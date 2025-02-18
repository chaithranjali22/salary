#include <stdio.h>
float convertTemperature(float temp, int choice);

int main() {
    float temp, result;
    int choice;
    printf("Enter Temperature: ");
    scanf("%f", &temp);
    printf("Choose Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    result = convertTemperature(temp, choice);
    switch (choice) {
        case 1:
            printf("Temperature in Fahrenheit: %.2f\n", result);
            break;
        case 2:
            printf("Temperature in Celsius: %.2f\n", result);
            break;
        case 3:
            printf("Temperature in Kelvin: %.2f\n", result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

float convertTemperature(float temp, int choice) {
    switch (choice) {
        case 1:
            return (temp * 9 / 5) + 32;
        case 2: 
            return (temp - 32) * 5 / 9;
        case 3: 
            return temp + 273.15;
        default:
            return 0; 
    }
}
