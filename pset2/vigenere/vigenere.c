#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){


    int count = 0;
    int temp = 0;
    if (argc == 2){
    for (int j = 0; j < strlen(argv[1]); j++){
          if (argv[1][j] < 'A' || argv[1][j] > 'z'){
              printf("Invalid input\n");
              return 1;
          }
      }
      printf("plaintext: ");
      string s = get_string();
      string key = argv[1];
      printf("ciphertext: ");
       for (int i = 0; i < strlen(s); i++){
        if (count >= strlen(key)){
            count = 0;
        }
        if (key[count] >= 'A' && key[count] <= 'Z'){
            temp = key[count] - 65;
        } else if (key[count] >= 'a' && key[count] <= 'z'){
            temp = key[count] - 97;
        }

        if (s[i] >= 'A' && s[i] <= 'Z'){

            int value = s[i] + temp;
            if (value > 'Z'){
                value = value - 90;
                value = (value % 26) + 64;
            }
            printf("%c", value);
            count++;
        }
        else if (s[i] >= 'a' && s[i] <= 'z'){

            int value = s[i] + temp;
            if (value > 'z'){
                value = value - 122;
                value = (value % 26) + 96;
            }
            printf("%c", value);
            count++;

        }
        else {
            printf("%c", s[i]);
        }
       }

       printf("\n");

    } else {
        printf("Not a valid number of arguments\n");

        return 1;
    }
    return 0;
}