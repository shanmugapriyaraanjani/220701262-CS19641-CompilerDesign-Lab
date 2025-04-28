#include <stdio.h>
#include <string.h>

int checkSubstring(const char *str, const char *substr) {
    if (strstr(str, substr) != NULL) {
        return 1;  // Substring found
    }
    return 0;  // Substring not found
}

int main() {
    char str[100], substr[50];

    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Enter the substring: ");
    fgets(substr, sizeof(substr), stdin);

    substr[strcspn(substr, "\n")] = '\0';

    if (checkSubstring(str, substr)) {
        printf("The substring exists in the string.\n");
    } else {
        printf("The substring does not exist in the string.\n");
    }

    return 0;
}

