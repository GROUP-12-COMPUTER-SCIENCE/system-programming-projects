#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char *buffer;
    size_t fileSize;

    // Open the file in binary mode
    file = fopen("sample.txt", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    // Allocate memory for the buffer to hold the entire file content
    buffer = (char*)malloc(sizeof(char) * fileSize);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read the file content into the buffer
    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Null-terminate the buffer
    buffer[fileSize] = '\0';

    // Print the content of the buffer
    printf("File content:\n%s\n", buffer);

    // Clean up
    free(buffer);
    fclose(file);

    return EXIT_SUCCESS;
}
