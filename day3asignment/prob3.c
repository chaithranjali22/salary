#include <stdio.h>

int main() {
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    int salaries[n];
    int totalPayroll = 0;
    printf("Enter salaries of %d employees: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &salaries[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (salaries[i] > salaries[j]) {
                int temp = salaries[i];
                salaries[i] = salaries[j];
                salaries[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        totalPayroll += salaries[i];
    }

    int secondHighestSalary = salaries[n - 2];
    printf("\nSorted Salaries: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", salaries[i]);
    }
printf("\nSecond Highest Salary: %d\n", secondHighestSalary);
    printf("Total Payroll: ₹%d\n", totalPayroll);

    return 0;
}
