#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Name[50];
    int Price;
} Product;

int compareProducts(const void *a, const void *b) {
    return ((Product *)a)->Price - ((Product *)b)->Price;
}

Product *binarySearch(Product *products, int left, int right, const char *searchName) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(products[mid].Name, searchName);
        if (cmp == 0) {
            return &products[mid];
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}

void onlineShopping(Product *products, int numProducts, const char *searchName) {
    if (numProducts == 0) {
        printf("No products available.\n");
        return;
    }
    qsort(products, numProducts, sizeof(Product), compareProducts);

    printf("Sorted by Price: ");
    for (int i = 0; i < numProducts; i++) {
        printf("%s (%d)", products[i].Name, products[i].Price);
        if (i < numProducts - 1) {
            printf(", ");
        }
    }
    printf("\n");
    if (searchName != NULL) {
        Product *foundProduct = binarySearch(products, 0, numProducts - 1, searchName);
        if (foundProduct != NULL) {
            printf("Search '%s': Found (Price: %d)\n", searchName, foundProduct->Price);
        } else {
            printf("Search '%s': Not Found\n", searchName);
        }
    }

    
    printf("Cheapest Product: %s (%d)\n", products[0].Name, products[0].Price);
    printf("Most Expensive Product: %s (%d)\n", products[numProducts - 1].Name, products[numProducts - 1].Price);
}

int main() {
    Product products[] = {
        {"Laptop", 50000},
        {"Mobile", 20000},
        {"Headphones", 5000},
        {"Tablet", 30000}
    };
    int numProducts = sizeof(products) / sizeof(products[0]);

    onlineShopping(products, numProducts, "Mobile");
    printf("\n");
    onlineShopping(products, numProducts, NULL);
    printf("\n");
    Product emptyProducts[1];
    onlineShopping(emptyProducts,0,"Mobile");
    printf("\n");
    onlineShopping(products, numProducts, "Camera");

    return 0;
}
