/*
Name: kevin ian kiplagat
Reg no:PA106/28724/25
Description:function that prompt the user to input 10 integers and store them
*/
#include <stdio.h>

void write_integers_to_file() {
    FILE *file_ptr;
    int numbers[10];
    int i;

    file_ptr = fopen("input.txt", "w");
    if (file_ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        fprintf(file_ptr, "%d\n", numbers[i]);
    }

    fclose(file_ptr);
}