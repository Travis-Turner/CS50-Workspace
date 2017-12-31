#include <stdio.h>
#include <cs50.h>

int main (void){
    int x;
    bool valid = false;
    while (valid == false){
        printf("How big should the pyramid be?");
        x = get_int();
        if (x <= 23 && x >= 0){
            valid = true;
            break;
        }
    }
    int k = x - 1;
    int q = 1;
        for (int i = 0; i < x; i++){
            for (int j = 0; j < k; j++){
            printf(" ");
        }
        k--;
        printf("#");
        for (int t = 0; t < q; t++){
            printf("#");
        }
        q++;
        printf("\n");

}







}