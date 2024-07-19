#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char *filename = "example.txt";
    char *mode = "w+";
    char write_data[] = "Hello, this is a file handling example in C!";
    char read_data[100];

    // Create and open a file for writing and reading
    file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write data to the file
    if (fputs(write_data, file) == EOF) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }
    printf("Data written to file: %s\n", write_data);

    // Rewind the file pointer to the beginning of the file
    rewind(file);

    // Read data from the file
    if (fgets(read_data, sizeof(read_data), file) == NULL) {
        perror("Error reading from file");
        fclose(file);
        return 1;
    }
    printf("Data read from file: %s\n", read_data);

    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        return 1;
    }

    printf("File closed successfully.\n");
    return 0;
}
