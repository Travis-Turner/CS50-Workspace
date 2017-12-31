#include <stdio.h>
#include <cs50.h>

int main (void){
    printf("How long was your shower?");
    int n = get_int();
    printf("That's like using %i bottles of water.", (n * 192) / 16);
}