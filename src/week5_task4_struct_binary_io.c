
/*
 * week5_task4_struct_binary_io.c (BONUS)
 * Name: Emirhan
 * Surname: Kucukyilmaz
 * Student ID: 251ADB105
 *
 * Task 4: Binary file I/O using fwrite and fread
 * Week 5 - Files & Modular Programming
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
int save_student_binary(const Student *s, const char *filename);
int load_student_binary(const char *filename, Student *out);
long file_size(const char *filename);

int main(void) {
    Student s1 = {0};
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    Student loaded = {0};
    const char *bin_file = "student.bin";
    const char *txt_file = "student.txt";

    printf("Saving student in binary format...\n");

    if (save_student_binary(&s1, bin_file) != 0) {
        fprintf(stderr, "Failed to save binary student.\n");
        return EXIT_FAILURE;
    }

    // Save the same student as text for file size comparison.
    FILE *text_fp = fopen(txt_file, "w");

    if (text_fp == NULL) {
        perror(txt_file);
        return EXIT_FAILURE;
    }

    if (fprintf(text_fp, "%s %d %.2f\n",
                s1.name, s1.age, s1.gpa) < 0) {
        fclose(text_fp);
        fprintf(stderr, "Failed to write text student.\n");
        return EXIT_FAILURE;
    }

    if (fclose(text_fp) != 0) {
        fprintf(stderr, "Failed to close text student file.\n");
        return EXIT_FAILURE;
    }

    printf("Loading student from binary file...\n");

    if (load_student_binary(bin_file, &loaded) != 0) {
        fprintf(stderr, "Failed to load binary student.\n");
        return EXIT_FAILURE;
    }

    printf("Loaded student: %s, %d, GPA %.2f\n",
           loaded.name, loaded.age, loaded.gpa);

    long text_bytes = file_size(txt_file);
    long binary_bytes = file_size(bin_file);

    if (text_bytes < 0 || binary_bytes < 0) {
        fprintf(stderr, "Failed to get file sizes.\n");
        return EXIT_FAILURE;
    }

    printf("Text file size: %ld bytes\n", text_bytes);
    printf("Binary file size: %ld bytes\n", binary_bytes);

    return EXIT_SUCCESS;
}

// Save a Student struct in binary format.
int save_student_binary(const Student *s, const char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        return -1;
    }

    if (fwrite(s, sizeof(Student), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }

    if (fclose(fp) != 0) {
        return -1;
    }

    return 0;
}

// Load a Student struct from a binary file.
int load_student_binary(const char *filename, Student *out) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        return -1;
    }

    if (fread(out, sizeof(Student), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }

    if (fclose(fp) != 0) {
        return -1;
    }

    return 0;
}

// Return the file size in bytes.
long file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        return -1;
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return -1;
    }

    long bytes = ftell(fp);

    if (fclose(fp) != 0) {
        return -1;
    }

    return bytes;
}
