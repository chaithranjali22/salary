#include <stdio.h>
struct Student {
    int roll_no;
    char name[50];
    int marks;
};

int main() {
    struct Student students[3] = {
        {101, "Alice", 85},
        {102, "Bob", 90},
        {103, "Charlie", 75}
    };

    int n = 3;
    struct Student temp;

    // Sorting the students by marks in descending order (simple bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].marks < students[j].marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Sorted by Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }
    int roll_no_to_search = 102;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].roll_no == roll_no_to_search) {
            printf("\nSearch Roll No %d: Found (%s, Marks: %d)\n", roll_no_to_search, students[i].name, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nSearch Roll No %d: Not Found\n", roll_no_to_search);
    }
    printf("\nTop 3 Students:\n");
    for (int i = 0; i < n && i < 3; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }

    return 0;
}
