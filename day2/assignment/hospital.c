#include <stdio.h>
float calculateBill(char wardType, int days) {
    float dailyCharge, totalBill, discount = 0;
    switch (wardType) {
        case 'G': case 'g': dailyCharge = 1000; break;
        case 'S': case 's': dailyCharge = 2000; break;
        case 'P': case 'p': dailyCharge = 5000; break;
        default:
            printf("Invalid ward type entered!\n");
            return -1;
    }
    totalBill = dailyCharge * days;
    if (days > 7) {
        discount = totalBill * 0.05;
        totalBill -= discount;
    }
 printf("\nTotal Bill Before Discount: ₹%.2f\n", dailyCharge * days);
    printf("Discount Applied: ₹%.2f\n", discount);
    printf("Final Bill Amount: ₹%.2f\n", totalBill);

    return totalBill;
}

int main() {
    char patientName[50], wardType;
       int days;
    printf("Enter Patient Name: ");
    scanf("%[^\n]", patientName);
    getchar(); 

    printf("Enter Ward Type (G/S/P): ");
    scanf("%c", &wardType);

    printf("Enter Number of Days: ");
    scanf("%d", &days);
    printf("\nPatient Name: %s\n", patientName);
    if (calculateBill(wardType, days) == -1) {
        printf("Please restart the program and enter a valid ward type.\n");
    }
      return 0;
}
