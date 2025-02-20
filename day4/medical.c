#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Medicine {
    int id;
    char name[50];
    char expiryDate[11];  
    float price;
};
int compareExpiryDate(const void *a, const void *b) {
    return strcmp(((struct Medicine*)a)->expiryDate, ((struct Medicine*)b)->expiryDate);
}
void saveMedicinesToFile(struct Medicine medicines[], int n) {
    FILE *file = fopen("medicine_inventory.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for saving data.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %s, ₹%.2f\n", medicines[i].id, medicines[i].name, medicines[i].expiryDate, medicines[i].price);
    }
  fclose(file);
    printf("Records saved in \"medicine_inventory.txt\"\n");
}
int main() {
    int n;
    printf("Enter number of medicines: ");
    scanf("%d", &n);
    
    struct Medicine medicines[n];
    for (int i = 0; i < n; i++) {
        printf("Medicine %d: ", i + 1);
        printf("ID, Name, Expiry Date (YYYY-MM-DD), Price\n");
        printf("Enter ID: ");
        scanf("%d", &medicines[i].id);
        printf("Enter Name: ");
        scanf(" %[^\n]%*c", medicines[i].name);  // Read string with spaces
        printf("Enter Expiry Date (YYYY-MM-DD): ");
        scanf("%s", medicines[i].expiryDate);
        printf("Enter Price: ₹");
        scanf("%f", &medicines[i].price);
    }
    qsort(medicines, n, sizeof(struct Medicine), compareExpiryDate);
    printf("\nSorted Medicines (by Expiry Date):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, medicines[i].name, medicines[i].expiryDate);
    }
    saveMedicinesToFile(medicines, n);

    return 0;
}
