#include <stdio.h>
#include <string.h>
struct Passenger {
    char name[50];
    int age;
    char destination[50];
};
void addPassenger(struct Passenger passengers[], int *n) {
    printf("Enter name: ");
    scanf("%s", passengers[*n].name);
    printf("Enter age: ");
    scanf("%d", &passengers[*n].age);
    printf("Enter destination: ");
    scanf("%s", passengers[*n].destination);
    (*n)++;
}
void sortPassengers(struct Passenger passengers[], int n) {
    struct Passenger temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(passengers[i].destination, passengers[j].destination) > 0) {
                temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }
}

void searchPassengers(struct Passenger passengers[], int n, char destination[]) {
    int found = 0;
    printf("Passengers traveling to %s:\n", destination);
    for (int i = 0; i < n; i++) {
        if (strcmp(passengers[i].destination, destination) == 0) {
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found for this destination.\n");
    }
}
int main() {
    int n = 0, choice;
    struct Passenger passengers[100];
        while (1) {
        printf("\nFlight Ticket Booking System\n");
        printf("1. Add a new passenger\n");
        printf("2. Sort passengers by destination\n");
        printf("3. Search for passengers by destination\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
  switch(choice) {
 case 1:
        addPassenger(passengers, &n);
                break;
            case 2:
                sortPassengers(passengers, n);
                printf("Sorted List (by destination):\n");
                for (int i = 0; i < n; i++) {
                    printf("%s - %s\n", passengers[i].name, passengers[i].destination);
                }
                break;
            case 3:
                {
                    char destination[50];
                    printf("Enter destination to search: ");
                    scanf("%s", destination);
                    searchPassengers(passengers, n, destination);
                }
                break;
            case 4:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
   return 0;
}

