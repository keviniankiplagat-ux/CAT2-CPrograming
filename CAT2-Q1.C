/*
Name:kevin ian kiplagat
Reg no:PA106/G/28724/25
Description:program that intialise a 2D array
*/
#include <stdio.h>

int main() {
    int scores[2][2] = {
        {65, 92},
        {84, 72}
    };
    
    printf("Elements of the array:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}