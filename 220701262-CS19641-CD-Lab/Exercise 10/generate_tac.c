#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char temp_vars[10][10];
int temp_count = 0;

char* new_temp() {
    sprintf(temp_vars[temp_count], "t%d", temp_count);
    return temp_vars[temp_count++];
}

void generate_TAC(char *lhs, char *rhs) {
    char *tokens[MAX];
    int i = 0;

    // Tokenize the RHS by space
    tokens[i] = strtok(rhs, " ");
    while (tokens[i] != NULL) {
        i++;
        tokens[i] = strtok(NULL, " ");
    }

    int num_tokens = i;
    char temp1[10], temp2[10], result[10];
    char *op1, *op2, *op;

    // Support only binary operations and correct order of precedence
    // Step 1: Handle *, /
    for (i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "*") == 0 || strcmp(tokens[i], "/") == 0) {
            op1 = tokens[i - 1];
            op2 = tokens[i + 1];
            op = tokens[i];

            strcpy(result, new_temp());
            printf("%s = %s %s %s\n", result, op1, op, op2);

            tokens[i - 1] = result;  // replace left operand with temp
            // shift the rest
            int j;
            for (j = i; j < num_tokens - 2; j++) {
                tokens[j] = tokens[j + 2];
            }
            num_tokens -= 2;
            i = -1;  // restart
        }
    }

    // Step 2: Handle +, -
    for (i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "+") == 0 || strcmp(tokens[i], "-") == 0) {
            op1 = tokens[i - 1];
            op2 = tokens[i + 1];
            op = tokens[i];

            strcpy(result, new_temp());
            printf("%s = %s %s %s\n", result, op1, op, op2);

            tokens[i - 1] = result;
            int j;
            for (j = i; j < num_tokens - 2; j++) {
                tokens[j] = tokens[j + 2];
            }
            num_tokens -= 2;
            i = -1;
        }
    }

    // Final assignment
    printf("%s = %s\n", lhs, tokens[0]);
}

int main() {
    FILE *fp;
    char line[256], lhs[50], rhs[200];

    fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Error opening input file!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strlen(line) < 3) continue;

        // remove newline
        line[strcspn(line, "\n")] = 0;

        // Split into lhs and rhs at '='
        char *eq = strchr(line, '=');
        if (eq) {
            *eq = '\0';
            strcpy(lhs, line);
            strcpy(rhs, eq + 1);

            // Trim spaces
            char *lhs_trim = strtok(lhs, " ");
            char *rhs_trim = strtok(rhs, "\n");

            generate_TAC(lhs_trim, rhs_trim);
        }
    }

    fclose(fp);
    return 0;
}
