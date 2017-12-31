#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void){
    string s = get_string();

    for (int i = 0; i < strlen(s); i++){
        if (i == 0){
            if (s[0] >= 'a' && s[0] <= 'z'){
                printf("%c", s[0] - 32);
            } else {
                printf("%c", s[0]);
            }
        } else if (s[i] == ' '){
            if (s[i + 1] >= 'a' && s[i + 1] <= 'z'){
                printf("%c", s[i + 1] - 32);
            } else {
                printf("%c", s[i + 1]);
            }
        }
    }

    printf("\n");
}