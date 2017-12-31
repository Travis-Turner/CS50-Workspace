#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    if (argc == 2){
      string key = argv[1];
      string input = get_string();
      int count = 0;
      int temp;
       for (int i = 0; i < strlen(input); i++){
           if (count >= strlen(key)){
               count = 0;
           }
           temp = key[count] - 65;
           input[i] = input[i] + temp;

          printf("%i\n", count);
           count++;
       }

       printf("%s", input);
    } else {
        printf("Error!");
        return 1;
    }
}


