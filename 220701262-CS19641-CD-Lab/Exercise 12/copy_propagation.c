#include <stdio.h>
#include <string.h>

struct instruction {
    char lhs[10];
    char rhs1[10];
    char op[3];
    char rhs2[10];
};

int main() {
    int n;
    printf("Enter number of instructions: ");
    scanf("%d", &n);

    struct instruction tac[100];

    printf("Enter TAC (Format: lhs = rhs1 [op rhs2]):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", tac[i].lhs);   // lhs
        scanf("%*s");              // skip '='
        scanf("%s", tac[i].rhs1);  // rhs1

        char next[5];
        fgets(next, sizeof(next), stdin); // read remaining part (op and rhs2 if present)

        // Check if operator and rhs2 are provided
        if (sscanf(next, "%s %s", tac[i].op, tac[i].rhs2) < 2) {
            tac[i].op[0] = '\0';
            tac[i].rhs2[0] = '\0';
        }
    }

    // Copy Propagation
    for (int i = 0; i < n; i++) {
        if (strlen(tac[i].op) == 0) { // it's a copy statement: x = y
            char *from = tac[i].rhs1;
            char *to = tac[i].lhs;

            for (int j = i + 1; j < n; j++) {
                if (strcmp(tac[j].rhs1, to) == 0)
                    strcpy(tac[j].rhs1, from);
                if (strcmp(tac[j].rhs2, to) == 0)
                    strcpy(tac[j].rhs2, from);
                if (strcmp(tac[j].lhs, to) == 0)
                    break;
            }
        }
    }

    // Print optimized TAC
    printf("\nOptimized TAC:\n");
    for (int i = 0; i < n; i++) {
        printf("%s = %s", tac[i].lhs, tac[i].rhs1);
        if (strlen(tac[i].op) > 0)
            printf(" %s %s", tac[i].op, tac[i].rhs2);
        printf("\n");
    }

    return 0;
}
