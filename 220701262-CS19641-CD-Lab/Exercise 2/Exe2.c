#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while", "_Alignas", "_Alignof", "_Atomic", "_Bool",
    "_Complex", "_Generic", "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local"
};

// Operators and special symbols
const char *operators[] = {"+", "-", "*", "/", "%", "=", "==", "!=", "<", "<=", ">", ">=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>"};
const char *specialSymbols[] = {";", "{", "}", "(", ")", "[", "]", ",", ".", ":", "?"};

// Check if token is a keyword
bool isKeyword(const char *token) {
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0)
            return true;
    }
    return false;
}

// Check if token is an operator
bool isOperator(const char *token) {
    for (int i = 0; i < sizeof(operators)/sizeof(operators[0]); i++) {
        if (strcmp(token, operators[i]) == 0)
            return true;
    }
    return false;
}

// Check if token is a special symbol
bool isSpecialSymbol(const char *token) {
    for (int i = 0; i < sizeof(specialSymbols)/sizeof(specialSymbols[0]); i++) {
        if (strcmp(token, specialSymbols[i]) == 0)
            return true;
    }
    return false;
}

// Check if a token is a valid identifier
bool isIdentifier(const char *token) {
    if (!isalpha(token[0]) && token[0] != '_')
        return false;
    for (int i = 1; token[i]; i++) {
        if (!isalnum(token[i]) && token[i] != '_')
            return false;
    }
    return !isKeyword(token);
}

int main() {
    char code[1000];
    printf("Enter C code snippet (end with # on a new line):\n");

    // Read multiple lines of code until '#' is entered
    char line[200];
    code[0] = '\0';
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (line[0] == '#' && line[1] == '\n') break;
        strcat(code, line);
    }

    const char *delimiters = " \t\n;(){}[],.+-*/%<>=!&|^~?:";
    char *token = strtok(code, delimiters);

    printf("\n--- Token Classification ---\n");
    while (token != NULL) {
        if (isKeyword(token))
            printf("Keyword: %s\n", token);
        else if (isOperator(token))
            printf("Operator: %s\n", token);
        else if (isSpecialSymbol(token))
            printf("Special Symbol: %s\n", token);
        else if (isIdentifier(token))
            printf("Identifier: %s\n", token);
        else
            printf("Unknown: %s\n", token);

        token = strtok(NULL, delimiters);
    }

    return 0;
}
