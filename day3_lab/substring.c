#include <stdio.h>
#include <string.h>

int findSubstring(char str[], char sub[]) {
    int i, j;
    int strLen = strlen(str);
    int subLen = strlen(sub);
    for (i = 0; i <= strLen - subLen; i++) {
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }
        if (j == subLen) {
            return i;
        }
    }
    return -1;
}

int main() {
    char str[100], sub[50];
    printf("Enter main string: ");
    gets(str);

    printf("Enter substring: ");
    gets(sub);

   
    int result = findSubstring(str, sub);
    if (result != -1) {
        printf("Substring found at index: %d\n", result);
    } else {
        printf("Substring not found\n");
    }

    return 0;
}
