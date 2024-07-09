#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);
    return 0;
}