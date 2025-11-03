
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int numbers[10];
    int sum = 0;
    double average;
    char ch;

    
    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error opening input.txt for writing.\n");
        return 1;
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        fprintf(file, "%d\n", numbers[i]);
    }
    fclose(file);

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input.txt for reading.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fscanf(file, "%d", &numbers[i]);
        sum += numbers[i];
    }
    fclose(file);

    average = sum / 10.0;

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening output.txt for writing.\n");
        return 1;
    }

    fprintf(file, "Sum: %d\n", sum);
    fprintf(file, "Average: %.2lf\n", average);
    fclose(file);

    printf("\nContents of input.txt:\n");
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input.txt.\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    printf("\nContents of output.txt:\n");
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error opening output.txt.\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    return 0;
