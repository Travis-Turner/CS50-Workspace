#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void){
    float x;
    bool valid = false;


    while (valid == false){
        printf("How much change is owed? ");
        x = get_float();
        if (x > 0){
            valid = true;
            break;
        }
    }



    int payment = round(x * 100.00);
    int coins = 0;
    while (payment > 0){
        if (payment >= 25){
            payment = payment - 25;
        } else if (payment >= 10){
            payment = payment - 10;
        } else if (payment >= 5){
            payment = payment - 5;
        } else {
            payment = payment - 1;
        }
        coins++;
    }

      printf("%i\n", coins);
}
