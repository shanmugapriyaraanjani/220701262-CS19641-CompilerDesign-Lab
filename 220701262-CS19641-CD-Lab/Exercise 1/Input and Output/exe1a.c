#include<stdio.h>
#include <ctype.h>

void convertToUpper(char str[]) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    convertToUpper(str);

    printf("Uppercase String: %s", str);

    return 0;
}

