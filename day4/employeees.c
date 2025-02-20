#include<stdio.h>
#include<string.h>
struct Employee_t
{
    int id;
    char name[255];
    float salary;
    char department[50];
};
typedef struct Employee_t Employee;
void readEmployees(Employee emp[],int n);
void saveEmployees(Employee emp[],int n);
void loadEmployees(Employee emp[],int n);
void displayEmployees(Employee emp[],int n);
Employee findhighestSalary(Employee emp[],int n);

int main()
{
    int employeecount;
    printf("ENter number of employee:");
    scanf("%d",&employeecount);
    Employee employees[100];
    readEmployees(employees,employeecount);
    saveEmployees(employees,employeecount);
    loadEmployees(employees,employeecount);
    displayEmployees(employees,employeecount);
    Employee highestsalariedEmployee=findhighestSalary(employees,employeecount);
    printf("\nEmployee with highest salary:%s,%.2f(%s)\n",highestsalariedEmployee.name,highestsalariedEmployee.salary,highestsalariedEmployee.department);
    return 0;
   
}
void readEmployees(Employee emp[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s",emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        printf("Department: ");
        scanf("%s",emp[i].department);
    }
}
void saveEmployees(Employee emp[], int n)
{
    FILE *file = fopen("employees.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for(int i=0;i<n;i++)
    {
     fprintf(file,"%d %s %.2f %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
    fclose(file);
}

void loadEmployees(Employee emp[], int n) {
    FILE *file = fopen("employees.txt", "a");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    for(int i=0;i<n;i++)
    {
     fscanf(file,"%d %s %f %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
    fclose(file);
}

void displayEmployees(Employee emp[], int n) {
    printf("\nEmployee Details:\n");
    printf("ID\tName\tSalary\t\tDepartment\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\t%s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

Employee findhighestSalary(Employee emp[], int n) {
    Employee highest = emp[0];
    for (int i = 1; i < n; i++) {
        if (emp[i].salary > highest.salary) {
            highest = emp[i];
        }
    }
    return highest;
}
