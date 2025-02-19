#include <stdio.h>

int mostFrequentElement(int arr[], int n) {
    int maxCount = 0;
    int mostFrequent = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxCount || (count == maxCount && arr[i] < mostFrequent)) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = mostFrequentElement(arr, n);
    printf("Most Frequent Element: %d\n", result);

    return 0;
}
