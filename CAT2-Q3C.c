/*
Name:kevin ian kiplagat
Reg no:PA106/G/28724/25
Description:program that intialise a 2D array
*/
#include <stdio.h>

void display_file_contents() {
    FILE *file_ptr;
    char ch;

    printf("--- Contents of input.txt ---\n");
    file_ptr = fopen("input.txt", "r");
    if (file_ptr == NULL) {
        printf("Error opening input file!\n");
        return;
    }
    while ((ch = fgetc(file_ptr)) != EOF) {
        putchar(ch);
    }
    fclose(file_ptr);

    printf("\n--- Contents of output.txt ---\n");
    file_ptr = fopen("output.txt", "r");
    if (file_ptr == NULL) {
        printf("Error opening output file!\n");
        return;
    }
    while ((ch = fgetc(file_ptr)) != EOF) {
        putchar(ch);
    }
    fclose(file_ptr);
}