#include<stdio.h>

int main() {
    int id;
    char name[255];
    int units;

    printf("Enter customer name: ");
    fgets(name, sizeof(name), stdin);  // Taking customer name input

    printf("Enter customer ID: ");
    scanf("%d", &id);

    printf("Enter the total units consumed: ");
    scanf("%d", &units);

    float base_amount = 100.0f;
    float surcharge = 0.0f;
    float total_amount = 0.0f;

    // Calculate base amount based on units consumed
    if (units > 300) {
        base_amount += (100.0f * 5.0f);
        base_amount += (200.0f * 7.0f);
        base_amount += ((units - 300) * 10.0f);
    } else if (units > 100) {
        base_amount += (100.0f * 5.0f);
        base_amount += ((units - 200) * 7.0f);
    } else {
        base_amount += (units * 5.0f);
    }

    // Apply surcharge if applicable
    if (base_amount > 1000.0f) {
        surcharge = (base_amount / 100.0f) * 5.0f;
    }

    // Calculate total amount
    total_amount = base_amount + surcharge;

    // Print the final bill details
    printf("EB Bill details:\n");
    printf("\tCustomer name: %s\n", name);
    printf("\tCustomer ID: %d\n", id);
    printf("\tUnits consumed: %d\n", units);
    printf("\tBase Bill: ₹%.2f\n", base_amount);

    if (surcharge > 0.0f) {
        printf("\tSurcharge: ₹%.2f\n", surcharge);
    }

    printf("\tTotal bill: ₹%.2f\n", total_amount);
    
    return 0;
}
