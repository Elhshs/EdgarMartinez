#include <stdio.h>

int matriz[10][10];
int n, m;

void llenarMatriz() {
    int valor = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = valor++;
        }
    }
}

void mostrarMatriz() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void recorridoFilas() {
    int i, j;
    printf("\nRecorrido por filas:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

void recorridoColumnasInverso() {
    int i, j;
    printf("\nRecorrido por columnas inverso:\n");
    for (j = m - 1; j >= 0; j--) {
        for (i = n - 1; i >= 0; i--) {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\n");
}

void recorridoDiagonal() {
    int i, limite;
    printf("\nRecorrido diagonal:\n");

    if (n < m) {
        limite = n;
    } else {
        limite = m;
    }

    for (i = 0; i < limite; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("\n");
}


int main() {
    int opcion;

    printf("Dame el valor de n (max 10): ");
    scanf("%d", &n);
    printf("Dame el valor de m (max 10): ");
    scanf("%d", &m);

    if (n <= 0 || n > 10 || m <= 0 || m > 10) {
        printf("Valores fuera de rango.\n");
        return 0;
    }

    llenarMatriz();
    mostrarMatriz();

    do {
        printf("\n--- MENU DE RECORRIDOS ---\n");
        printf("1. Recorrido por filas\n");
        printf("2. Recorrido por columnas inverso\n");
        printf("3. Recorrido diagonal\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: 
				recorridoFilas(); 
				break;
            case 2: 
				recorridoColumnasInverso(); 
				break;
            case 3: 
				recorridoDiagonal(); 
				break;
            case 4: 
				printf("Fin del programa.\n"); 
				break;
            default: 
				printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}
