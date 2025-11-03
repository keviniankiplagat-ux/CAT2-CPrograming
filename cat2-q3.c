/*
Name: kevin ian kiplagat
Reg no:PA106/G/28724/25
Description:program that print the gross pay taxes and net pay
*/
#include <stdio.h>

void write_integers_to_file() {
    FILE *file_ptr;
    int numbers[10];
    int i;

    file_ptr = fopen("input.txt", "w");
    if (file_ptr == NULL) {
        printf("Error opening input.txt for writing.\n");
        return;
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
        fprintf(file_ptr, "%d ", numbers[i]);
    }

    fclose(file_ptr);
    printf("Data successfully written to input.txt\n\n");
}

void process_integers() {
    FILE *input_ptr, *output_ptr;
    int num, count = 0, sum = 0;
    float average;

    input_ptr = fopen("input.txt", "r");
    if (input_ptr == NULL) {
        printf("Error opening input.txt for reading.\n");
        return;
    }

    output_ptr = fopen("output.txt", "w");
    if (output_ptr == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(input_ptr);
        return;
    }

    while (fscanf(input_ptr, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count == 0) {
        printf("No numbers found in input.txt.\n");
        fclose(input_ptr);
        fclose(output_ptr);
        return;
    }

    average = (float)sum / count;
    fprintf(output_ptr, "Sum = %d\nAverage = %.2f\n", sum, average);

    fclose(input_ptr);
    fclose(output_ptr);
    printf("Sum and average written to output.txt\n\n");
}

void display_files() {
    FILE *file_ptr;
    char ch;

    printf("Contents of input.txt:\n");
    file_ptr = fopen("input.txt", "r");
    if (file_ptr == NULL) {
        printf("Error opening input.txt for reading.\n");
        return;
    }
    while ((ch = fgetc(file_ptr)) != EOF)
        putchar(ch);
    fclose(file_ptr);

    printf("\n\nContents of output.txt:\n");
    file_ptr = fopen("output.txt", "r");
    if (file_ptr == NULL) {
        printf("Error opening output.txt for reading.\n");
        return;
    }
    while ((ch = fgetc(file_ptr)) != EOF)
        putchar(ch);
    fclose(file_ptr);

    printf("\n");
}

int main() {
    write_integers_to_file();
    process_integers();
    display_files();
    return 0;
}
