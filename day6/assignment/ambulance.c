#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void ambulanceDispatch(int distances[], int numAmbulances) {
    if (numAmbulances <= 0) {
        printf("No ambulances available.\n");
        return;
    }
    int sortedDistances[numAmbulances];
    for (int i = 0; i < numAmbulances; i++) {
        sortedDistances[i] = distances[i];
    }

    selectionSort(sortedDistances, numAmbulances);

    printf("Sorted: ");
    for (int i = 0; i < numAmbulances; i++) {
        printf("%d", sortedDistances[i]);
        if (i < numAmbulances - 1) {
            printf(", ");
        }
    }
    printf("\n");

    printf("Nearest Ambulance Assigned: Distance %d km\n", sortedDistances[0]);
}

int main() {
    int ambulanceDistances[] = {10, 3, 7, 1, 5};
    int numAmbulances = sizeof(ambulanceDistances) / sizeof(ambulanceDistances[0]);

    ambulanceDispatch(ambulanceDistances, numAmbulances);
    printf("\n");

    int ambulanceDistances2[] = {5,2,8,1,9,3};
    int numAmbulances2 = sizeof(ambulanceDistances2) / sizeof(ambulanceDistances2[0]);
    ambulanceDispatch(ambulanceDistances2, numAmbulances2);
    printf("\n");

    int ambulanceDistances3[] = {};
    int numAmbulances3 = sizeof(ambulanceDistances3) / sizeof(ambulanceDistances3[0]);
    ambulanceDispatch(ambulanceDistances3, numAmbulances3);

    return 0;
}
