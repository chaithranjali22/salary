#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rollNumber;
    char name[50];
    int marks1;
    int marks2;
    int marks3;
} Student;

void appendStudentRecord() {
    FILE *fp = fopen("students.txt", "a"); // Open in append mode
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    Student student;
    printf("Appending student:\n");
    scanf("%d, %s, %d, %d, %d", &student.rollNumber, student.name, &student.marks1, &student.marks2, &student.marks3);

    fprintf(fp, "%d %s %d %d %d\n", student.rollNumber, student.name, student.marks1, student.marks2, student.marks3);

    fclose(fp);
    printf("Student record appended successfully.\n");
}

void displayStudentRecords() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    Student student;
    printf("Student Records:\n");
    while (fscanf(fp, "%d %s %d %d %d", &student.rollNumber, student.name, &student.marks1, &student.marks2, &student.marks3) == 5) {
        printf("%d %s %d %d %d\n", student.rollNumber, student.name, student.marks1, student.marks2, student.marks3);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Append Student Record\n2. Display Student Records\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                appendStudentRecord();
                break;
            case 2:
                displayStudentRecords();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
