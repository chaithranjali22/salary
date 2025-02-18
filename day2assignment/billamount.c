#include <stdio.h>
float calculateFinalAmount(float billAmount) {
    float discount = 0;
if (billAmount >= 500 && billAmount <= 1000) {
        discount = 10;
    } else if (billAmount > 1000) {
        discount = 20;  
    }
     float finalAmount = billAmount - (billAmount * discount / 100);
    return finalAmount;
}
int main() {
    float billAmount;
printf("Enter total bill amount: ");
    scanf("%f", &billAmount);
float finalAmount = calculateFinalAmount(billAmount);
 printf("Final Payable Amount: %.2f\n", finalAmount);
  return 0;
}
