#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rollNo;
    char name[50];
    int maths, physics, chemistry, cs;
    int totalMarks;
    float percentage;
    char grade;
} Student;

void calculateStudentData(Student *student) {
    student->totalMarks = student->maths + student->physics + student->chemistry + student->cs;
    student->percentage = (float)student->totalMarks / 4.0;

    if (student->percentage >= 90) {
        student->grade = 'A';
    } else if (student->percentage >= 80) {
        student->grade = 'B';
    } else if (student->percentage >= 70) {
        student->grade = 'C';
    } else if (student->percentage >= 60) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

int main() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Student students[100]; // Assuming a maximum of 100 students
    int studentCount = 0;

    while (fscanf(file, "%d %s %d %d %d %d", &students[studentCount].rollNo,
                  students[studentCount].name, &students[studentCount].maths,
                  &students[studentCount].physics, &students[studentCount].chemistry,
                  &students[studentCount].cs) == 6) {
        calculateStudentData(&students[studentCount]);
        studentCount++;
    }

    fclose(file);

    printf("--------------------------------------------------------\n");
    printf("| Roll No | Name                | Maths | Physics | Chem  | CS    | Total | %%    | Grade |\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("| %-7d | %-17s | %-5d | %-7d | %-5d | %-5d | %-5d | %-5.2f | %-5c |\n",
               students[i].rollNo, students[i].name, students[i].maths, students[i].physics,
               students[i].chemistry, students[i].cs, students[i].totalMarks,
               students[i].percentage, students[i].grade);
    }

    printf("--------------------------------------------------------\n");

    return 0;
}
