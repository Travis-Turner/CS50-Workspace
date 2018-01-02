/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    int n;
    int tileValue;
    n = d * d;
    tileValue = n - 1;
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
                board[i][j] = tileValue;
                tileValue--;
        }
    }
    //If there an ODD number of tiles (which means that 'n' is EVEN)
    //This will swap the positions of '1' and '2' so that the game is solveable
    if (n % 2 == 0){
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            //Print '-' instead of 0
            //Adjust spacing depending on if integer is 1 digit or 2 digits.
            if (board[i][j] == 0){
                printf(" - ");
            } else if (board[i][j] > 9){
                printf(" %i  ", board[i][j]);
            } else {
                printf("  %i  ", board[i][j]);
            }
        }
        // Print a new line after each row.
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    int tileX;
    int tileY;
    int spaceX;
    int spaceY;

    //find position of userSelectedTile
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (board[i][j] == tile){
                tileY = i;
                tileX = j;
                break;
            }
        }
    }
    //find position of space
    for (int k = 0; k < d; k++){
        for (int l = 0; l < d; l++){
            if(board[k][l] == 0){
                spaceY = k;
                spaceX = l;
                break;
            }
        }
    }

    //for me to keep track
    printf("Tile coordinates. X = %i, Y = %i.\n", tileX, tileY);
    printf("Blank coordinates. X = %i, Y = %i.\n", spaceX, spaceY);


    //TRIGGERS IF SPACE AND USER TILE ARE ALIGNED ON THE Y AXIS
    if (spaceX == tileX){
        //TRIGGERS IF SPACE CANNOT GO ANY FARTHER UP
        //IF THE Y LOCATION IS EQUAL TO THE LOCATION OF THE SPACE, MINUS 1
        //THIS MEANS THAT THE SELECTED TILE IS ABOVE THE SPACE LOCATION
        if (tileY == spaceY - 1){

            board[spaceY][spaceX] = board[tileY][tileX];
            board[tileY][tileX] = 0;
            return true;
        }
        else if (tileY == spaceY + 1){
            board[spaceY][spaceX] = board[tileY][tileX];
            board[tileY][tileX] = 0;
            return true;
        }
    }
    if (spaceY == tileY){
        //TRIGGERS IF SPACE CANNOT GO ANY FARTHER UP
        //IF THE Y LOCATION IS EQUAL TO THE LOCATION OF THE SPACE, MINUS 1
        //THIS MEANS THAT THE SELECTED TILE IS ABOVE THE SPACE LOCATION
        if (tileX == spaceX - 1){

            board[spaceY][spaceX] = board[tileY][tileX];
            board[tileY][tileX] = 0;
            return true;
        }
        else if (tileX == spaceX + 1){
            board[spaceY][spaceX] = board[tileY][tileX];
            board[tileY][tileX] = 0;
            return true;
        }
    }
    return false;
}



/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int count;
    count = 1;
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            if (board[i][j] == board[d - 1][d - 1]){
                if(board[i][j] == 0){
                    return true;
                }
            }
            if (board[i][j] != count){
                return false;
            }
            count++;
        }
    }
    return false;
}