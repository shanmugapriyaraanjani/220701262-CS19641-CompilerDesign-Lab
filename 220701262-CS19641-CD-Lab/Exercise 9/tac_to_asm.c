#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateAssembly(char *line) {
    char lhs[10], op1[10], op2[10], temp[10], op;
    
    // Pattern: t = a op b
    if (sscanf(line, "%s = %s %c %s", lhs, op1, &op, op2) == 4) {
        printf("MOV AX, [%s]\n", op1);
        switch (op) {
            case '+': printf("ADD AX, [%s]\n", op2); break;
            case '-': printf("SUB AX, [%s]\n", op2); break;
            case '*': printf("MUL [%s]\n", op2); break;
            case '/': printf("DIV [%s]\n", op2); break;
        }
        printf("MOV [%s], AX\n\n", lhs);
    }
    // Pattern: a = b
    else if (sscanf(line, "%s = %s", lhs, op1) == 2) {
        printf("MOV AX, [%s]\n", op1);
        printf("MOV [%s], AX\n\n", lhs);
    }
}

int main() {
    char line[100];

    printf("Enter TAC lines (Ctrl+D to finish):\n");
    while (fgets(line, sizeof(line), stdin)) {
        if (strlen(line) > 1) {
            generateAssembly(line);
        }
    }

    return 0;
}
