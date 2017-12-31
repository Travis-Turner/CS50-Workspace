#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (int argc, string argv[]){

    printf("plaintext: ");
    string s = get_string();
    int count = 0;

    if (argc == 2){
      string key = argv[1];
      printf("ciphertext: ");
       for (int i = 0; i < strlen(s); i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            int temp = key[count];
            int value = s[i] + temp;
            if (value > 'Z'){
                value = value - 90;
                value = (value % 26) + 64;
            }
            printf("%c", value);
        }
        else if (s[i] >= 'a' && s[i] <= 'z'){
            int temp = key[count];
            int value = s[i] + temp;
            if (value > 'z'){
                value = value - 122;
                value = (value % 26) + 96;
            }
            printf("%c", value);

        }
        else {
            printf("%c", s[i]);
        }
       }
       count++;

       printf("\n");
       printf("%s", key);
    } else {
        printf("Not a valid number of arguments\n");

        return 1;
    }
    return 0;
}