#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char str[]) {
    int start = 0, end = strlen(str) - 1;

    while (start < end) {
        if (str[start] == ' ') {
            start++;
        } else if (str[end] == ' ') {
            end--;
        } else {
            if (tolower(str[start]) != tolower(str[end])) {
                return 0;  
            }
            start++;
            end--;
        }
    }
    return 1;  
}

int main() {
    char str[100];
    
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
 
    str[strcspn(str, "\n")] = '\0';
    if (isPalindrome(str)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}
