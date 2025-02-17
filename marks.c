#include <stdio.h>

char grade(float marks) {
    if (marks >= 90) {
        return 'A';
    } else if (marks >= 80) {
        return 'B';
    } else if (marks >= 70) {
        return 'C';
    } else if (marks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int num_students;
    
    // Input the number of students
    printf("Enter number of students: ");
    scanf("%d", &num_students);
    
    float marks[num_students];
    
    // Input the marks for each student
    printf("Enter marks: ");
    for (int i = 0; i < num_students; i++) {
        scanf("%f", &marks[i]);
    }
    
    // Display grades for each student
    for (int i = 0; i < num_students; i++) {
        char student_grade = grade(marks[i]);
        printf("Student %d: Grade %c\n", i + 1, student_grade);
    }

    return 0;
}
