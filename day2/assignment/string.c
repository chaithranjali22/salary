#include <stdio.h>
void reverseString(char *str) 
{
    char *end = str;
    char temp;
  
    while (*end) 
    {
        end++;
    }
    end--; 
   
    while (str < end) 
    {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed String: %s\n", str);

    return 0;
}
