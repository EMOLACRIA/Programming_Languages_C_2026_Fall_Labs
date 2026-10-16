// week5_task1_file_io.c
// Name: Emirhan  Surname: Kucukyilmaz  Student ID: 251ADB105
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(void) {
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    printf("Writing lines to %s...\n", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    fprintf(fp, "Hi, is this working?\nAre you there?\n");
    fprintf(fp, "I need you help, the world is going to be a candy!\n");
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    printf("Reading contents:\n");
    while (fgets(line,sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    fclose(fp);
    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}
