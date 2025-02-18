#include <stdio.h>
#include <stdlib.h>
struct Student {
    char name[50];
    int marks;
};

int main() {
    int numStudents;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);
struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student))
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }
 printf("\nStudent Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }
    free(students);

    return 0;
}
