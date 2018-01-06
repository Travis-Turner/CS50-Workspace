#include <cs50.h>
#include <stdio.h>
#include <string.h>

// int duration(string fraction);

// int duration(string fraction)
// {
//     int denom = atoi(&fraction[strlen(fraction) - 1]);;
//     return 8 / denom;
// }

bool is_rest(string s)
{
    if (strlen(s) == 0){
        return true;
    } else {
        return false;
    }
}



int main (){
    if(is_rest("")){
        printf("TRUE!");
    };
    if(is_rest("")){
        printf("TRUE!");
    };
    if(is_rest("")){
        printf("TRUE!");
    };
    return 0;
}

