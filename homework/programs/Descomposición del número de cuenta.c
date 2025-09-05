#include <stdio.h>
#define n 10

int main() {
    int arrayPares[n], arrayInverso[n];
    int i;
	int nCuenta = 318236050;   
    int uDigito = nCuenta % 10;
    
    for (i = 0; i < n; i++) {
        arrayPares[i] = (i + 1) * 2;
    }
    
    for (i = 0; i < n; i++){
    	arrayInverso[i] = arrayPares[9-i]; 
	}

    printf("Primero 10 numeros pares en orden inverso:\n");
    for (i = 9; i >= 0; i--) {
        printf("|%d| ", arrayPares[i]);
    }
    printf("\n");

	//Modificar el valor almacenado en el indice 
	//correspondiente al ultimo digito de su numero de cuenta
    
	if (uDigito < n) {
        arrayInverso[uDigito] = -1;
    }
    
    printf("Numero de cuenta: '318236050'\n");
    printf("Digito sustituido: \n");
    for (i = 0; i < n; i++) {
        printf("|%d| ", arrayInverso[i]);
    }
    printf("\n");

    return 0;
}

