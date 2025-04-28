#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char lhs[20];
    char op1[20];
    char operator;
    char op2[20];
    int is_used;
    int is_deleted;
} TAC;

TAC code[MAX];
int n = 0;

void read_TAC(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[100];

    if (!fp) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strlen(line) < 5) continue;

        TAC *inst = &code[n];
        inst->is_used = 0;
        inst->is_deleted = 0;

        if (sscanf(line, "%s = %s %c %s", inst->lhs, inst->op1, &inst->operator, inst->op2) == 4) {
            n++;
        }
    }

    fclose(fp);
}

void perform_CSE() {
    for (int i = 0; i < n; i++) {
        if (code[i].is_deleted) continue;

        for (int j = i + 1; j < n; j++) {
            if (code[j].is_deleted) continue;

            if (strcmp(code[i].op1, code[j].op1) == 0 &&
                strcmp(code[i].op2, code[j].op2) == 0 &&
                code[i].operator == code[j].operator) {

                // CSE detected: replace later LHS with first LHS
                strcpy(code[j].op1, code[i].lhs);
                code[j].operator = '=';
                strcpy(code[j].op2, "");
                code[j].is_deleted = 0;  // still used
            }
        }
    }
}

void perform_DCE() {
    // First mark used operands
    for (int i = 0; i < n; i++) {
        if (code[i].operator != '=') {
            for (int j = 0; j < n; j++) {
                if (strcmp(code[j].lhs, code[i].op1) == 0)
                    code[j].is_used = 1;
                if (strcmp(code[j].lhs, code[i].op2) == 0)
                    code[j].is_used = 1;
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (strcmp(code[j].lhs, code[i].op1) == 0)
                    code[j].is_used = 1;
            }
        }
    }

    // Eliminate unused
    for (int i = 0; i < n; i++) {
        if (!code[i].is_used) {
            code[i].is_deleted = 1;
        }
    }
}

void print_TAC() {
    printf("\nOptimized Three Address Code:\n");
    for (int i = 0; i < n; i++) {
        if (code[i].is_deleted) continue;

        if (code[i].operator == '=') {
            printf("%s = %s\n", code[i].lhs, code[i].op1);
        } else {
            printf("%s = %s %c %s\n", code[i].lhs, code[i].op1, code[i].operator, code[i].op2);
        }
    }
}

int main() {
    read_TAC("input.txt");

    printf("Performing Common Subexpression Elimination...\n");
    perform_CSE();

    printf("Performing Dead Code Elimination...\n");
    perform_DCE();

    print_TAC();
    return 0;
}
