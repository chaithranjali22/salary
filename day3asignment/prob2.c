#include <stdio.h>
struct Patient {
    char name[50];
    int emergencyLevel;
};

int main() {
    int n;
    printf("Enter number of patients: ");
    scanf("%d", &n);
 struct Patient patients[n];    
    for (int i = 0; i < n; i++) {
        printf("Enter name for patient %d: ", i + 1);
        scanf("%s", patients[i].name);
        printf("Enter emergency level (1 to 5) for %s: ", patients[i].name);
        scanf("%d", &patients[i].emergencyLevel);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (patients[i].emergencyLevel < patients[j].emergencyLevel) {
                struct Patient temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }
    printf("\nSorted by Emergency Level (Descending):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - Level %d\n", i + 1, patients[i].name, patients[i].emergencyLevel);
    }
    printf("\nTop 3 Critical Patients:\n");
    for (int i = 0; i < (n < 3 ? n : 3); i++) {
        printf("%d. %s\n", i + 1, patients[i].name);
    }

    return 0;
}
