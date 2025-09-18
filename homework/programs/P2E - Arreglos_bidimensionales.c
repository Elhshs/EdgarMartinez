#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 25

int main() {
    int n, i;
    char **nombres;
    int **datos; 

    printf("Cuantos alumnos vas a capturar: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Cantidad invalida.\n");
        return 0;
    }

    nombres = (char **) malloc(n *sizeof(char *));
    for (i = 0; i < n; i++) {
        nombres[i] = (char *) malloc(MAX_NOMBRE * sizeof(char));
    }

    // Reservar memoria para datos numéricos
    datos = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        datos[i] = (int *) malloc(2 * sizeof(int)); 
    }

    // Captura de datos
    for (i = 0; i < n; i++) {
        printf("\nAlumno %d\n", i + 1);

        printf("Nombre: ");
        getchar(); 
        fgets(nombres[i], MAX_NOMBRE, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0;

        printf("Edad: ");
        if (scanf("%d", &datos[i][0]) != 1) {
            printf("Edad invalida. Se asigna 0.\n");
            datos[i][0] = 0;
            while (getchar() != '\n');
        }

        printf("Calificacion: ");
        if (scanf("%d", &datos[i][1]) != 1) {
            printf("Calificacion invalida. Se asigna 0.\n");
            datos[i][1] = 0;
            while (getchar() != '\n');
        }
    }

    printf("\n--- LISTA DE ALUMNOS ---\n");
    printf("%-25s %-5s %-12s\n", "Nombre", "Edad", "Calificacion");
    for (i = 0; i < n; i++) {
        printf("%-25s %-5d %-12d\n", nombres[i], datos[i][0], datos[i][1]);
    }

    for (i = 0; i < n; i++) {
        free(nombres[i]);
        free(datos[i]);
    }
    free(nombres);
    free(datos);

    return 0;
}
