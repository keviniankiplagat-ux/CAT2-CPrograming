/*
Name:kevin ian kiplagat
Reg no:PA106/G/28724/25
Description:function that reads the integers
*/

void calculate_and_write_results() {
    FILE *input_file, *output_file;
    int number, sum = 0, count = 0;
    double average;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        return;
    }

    while (fscanf(input_file, "%d", &number) == 1) {
        sum += number;
        count++;
    }
    fclose(input_file);

    if (count > 0) {
        average = (double)sum / count;

        output_file = fopen("output.txt", "w");
        if (output_file == NULL) {
            printf("Error opening output file!\n");
            return;
        }

        fprintf(output_file, "Sum: %d\n", sum);
        fprintf(output_file, "Average: %.2f\n", average);
        fclose(output_file);
    } else {
        printf("Input file is empty.\n");
    }
}
