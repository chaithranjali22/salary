#include <stdio.h>

float calculate_bill(int units_consumed) {
    float bill = 0;
    
    if (units_consumed <= 100) {
        bill = units_consumed * 2;
    }
    else if (units_consumed <= 200) {
        bill = (100 * 2) + ((units_consumed - 100) * 3);
    }
    else {
        bill = (100 * 2) + (100 * 3) + ((units_consumed - 200) * 5);
    }

    return bill;
}

int main() {
    int N, units;
    
    printf("Enter the number of customers: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter units consumed by customer %d: ", i + 1);
        scanf("%d", &units);

        float total_bill = calculate_bill(units);
        printf("Total Bill for customer %d: ₹%.2f\n", i + 1, total_bill);
    }

    return 0;
}
