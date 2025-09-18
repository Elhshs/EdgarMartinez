#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s CADENA\n", argv[0]);
        return 1;
    }

    char *s = argv[1];
    int n = (int)strlen(s);
    if (n == 0) {
        printf("NULL\n");
        return 0;
    }

    char **cols = (char **) malloc(sizeof(char *) * n);
    if (cols == NULL) {
        return -1;
    }

    int *heights = (int *) malloc(sizeof(int) * n);
    if (heights == NULL) {
        free(cols);
        return -1;
    }

    int maxh = 0;

    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (isupper((unsigned char)c)) {
            int h = (c - 'A') + 1; 
            cols[i] = (char *) malloc(sizeof(char) * h);
            if (cols[i] == NULL) {
                for (int k = 0; k < i; ++k) {
                    free(cols[k]);
                }
                free(cols);
                free(heights);
                return -1;
            }
            for (int r = 0; r < h; ++r) cols[i][r] = c;
            heights[i] = h;
            if (h > maxh) maxh = h;
        } else {
            cols[i] = NULL;
            heights[i] = 0;
        }
    }

    printf("./%s %s\n", argv[0], s);

    for (int row = maxh; row >= 1; --row) {
        for (int col = 0; col < n; ++col) {
            putchar('|');
            putchar(' ');
            if (cols[col] != NULL && heights[col] >= row) {
                putchar(cols[col][row - 1]);
            } else {
                putchar(' ');
            }
            putchar(' ');
        }
        putchar('|');
        putchar('\n');
    }

    printf("\n");

    for (int i = 0; i < n; ++i) {
        if (cols[i] == NULL) {
            printf("NULL\n");
        } else {
            printf("col[%d] (h=%d)\n", i, heights[i]);
        }
    }

    for (int i = 0; i < n; ++i) free(cols[i]);
    free(cols);
    free(heights);

    return 0;
}

