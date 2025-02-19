#include <stdio.h>
#include <string.h>
void reverseWord(char word[]) 
{
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = word[i];
        word[i] = word[len - 1 - i];
        word[len - 1 - i] = temp;
    }
}

void reverseWords(char str[]) 
{
    int start = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
     
        if (str[i] == ' ' || str[i] == '\0') 
        {
            char word[100];
            int j = 0;
            
            
            for (int k = start; k < i; k++)
            {
                word[j++] = str[k];
            }
            word[j] = '\0';  
            reverseWord(word);
            for (int k = 0; word[k] != '\0'; k++)
            {
                str[start + k] = word[k];
            }

            start = i + 1;  
        }
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    reverseWords(sentence);
    printf("Reversed Sentence: %s\n", sentence);

    return 0;
}
