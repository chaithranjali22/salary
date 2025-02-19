#include <stdio.h>
#include <string.h>
void reverseWord(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
void reverseWords(char str[]) {
    int len = strlen(str);
    int start = 0;
   for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverseWord(&str[start], &str[i - 1]);
            start = i + 1;
        }
    }
}

int main() {
    char str[100];  
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    reverseWords(str);

    printf("Reversed Sentence: %s\n", str);

    return 0;
}
