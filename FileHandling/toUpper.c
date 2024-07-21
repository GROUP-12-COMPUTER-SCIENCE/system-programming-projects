#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: toUpper [filename]\n");
        exit(0);
    }

    FILE *fpt_read;
    if ((fpt_read = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open %s for reading\n", argv[1]);
        exit(0);
    }

    FILE *fpt_append;
    if ((fpt_append = fopen(argv[1], "a")) == NULL) {
        printf("Unable to open %s for appending\n", argv[1]);
        fclose(fpt_read);
        exit(0);
    }

    char c;
    while ((c = fgetc(fpt_read)) != EOF) {
        fputc(toupper(c), fpt_append);
    }

    fclose(fpt_read);
    fclose(fpt_append);
    return 0;
}