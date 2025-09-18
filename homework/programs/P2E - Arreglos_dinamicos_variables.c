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

    /* arreglo de punteros a columnas (cada columna es char* o NULL) */
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
    /* construir columnas */
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (isupper((unsigned char)c)) {
            int h = (c - 'A') + 1; /* A->1, B->2, ... */
            cols[i] = (char *) malloc(sizeof(char) * h);
            if (cols[i] == NULL) {
                /* liberar lo ya reservado y salir con error */
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

    /* imprimir encabezado tipo ./prog CADENA */
    printf("./%s %s\n", argv[0], s);

    /* imprimir filas desde arriba (maxh) hacia 1 */
    for (int row = maxh; row >= 1; --row) {
        /* por cada columna */
        for (int col = 0; col < n; ++col) {
            putchar('|');
            putchar(' ');
            if (cols[col] != NULL && heights[col] >= row) {
                /* índices internos: la fila 1 corresponde a cols[..][0] (abajo).
                   como imprimimos de arriba hacia abajo, la posición a mostrar es row-1 */
                /* Para que la salida se asemeje a la imagen, imprimimos la letra */
                putchar(cols[col][row - 1]);
            } else {
                putchar(' ');
            }
            putchar(' ');
        }
        putchar('|');
        putchar('\n');
    }

    /* si quieres separar con una línea en blanco */
    printf("\n");

    /* finalmente, listar punteros (similar a ejemplo: mostrar NULL para las columnas nulas) */
    for (int i = 0; i < n; ++i) {
        if (cols[i] == NULL) {
            printf("NULL\n");
        } else {
            printf("col[%d] (h=%d)\n", i, heights[i]);
        }
    }

    /* liberar memoria */
    for (int i = 0; i < n; ++i) free(cols[i]);
    free(cols);
    free(heights);

    return 0;
}

