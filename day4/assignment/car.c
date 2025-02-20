#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Car {
    int carID;
    char model[50];
    union {
        float rentPerDay;  
        float totalRent;   
    } rent;
    int isDailyRent;  
};

void saveCarsToFile(struct Car cars[], int n) {
    FILE *file = fopen("car_rentals.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for saving data.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (cars[i].isDailyRent) {
            fprintf(file, "%d, %s, ₹%.2f/day\n", cars[i].carID, cars[i].model, cars[i].rent.rentPerDay);
        } else {
            fprintf(file, "%d, %s, ₹%.2f total\n", cars[i].carID, cars[i].model, cars[i].rent.totalRent);
        }
    }

    fclose(file);
    printf("Data saved in \"car_rentals.txt\"\n");
}
void inputCarDetails(struct Car *car) {
    printf("Enter Car ID: ");
    scanf("%d", &car->carID);
    printf("Enter Model: ");
    scanf(" %[^\n]%*c", car->model);  // Read string with spaces

    printf("Enter 1 for Rent per Day, 0 for Total Rent: ");
    scanf("%d", &car->isDailyRent);

    if (car->isDailyRent) {
        printf("Enter Rent Per Day: ₹");
        scanf("%f", &car->rent.rentPerDay);
    } else {
        printf("Enter Total Rent: ₹");
        scanf("%f", &car->rent.totalRent);
    }
}

int main() {
    int n;
    printf("Enter number of cars: ");
    scanf("%d", &n);

    struct Car cars[n];
    for (int i = 0; i < n; i++) {
        printf("\nCar %d:\n", i + 1);
        inputCarDetails(&cars[i]);
    }    printf("\nCars Available:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - ", i + 1, cars[i].model);
        if (cars[i].isDailyRent) {
            printf("₹%.2f/day\n", cars[i].rent.rentPerDay);
        } else {
            printf("₹%.2f total\n", cars[i].rent.totalRent);
        }
    }    saveCarsToFile(cars, n);

    return 0;
