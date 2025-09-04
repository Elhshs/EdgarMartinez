#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int esNumerico(char *str){
    int i;
	for(i = 0; str[i] != '\0'; i++){
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int factTail(int n, int a){
    if(n < 0){
        return 0;
    } else if(n == 0){
        return 1;
    } else if(n == 1){
        return a;
    } else {
        return factTail(n - 1, n * a);
    }
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Dar numero como argumento.\n");
        return 1;
    }

    char *num = argv[1];
    printf("arg[1] = %s\n", num);
	
	int i;
    for(i = 0; i < strlen(num); i++)
        printf("num[%d] = %c\n", i, num[i]);

    if(!esNumerico(num)){
        printf("Dar valor numerico.\n");
        return 1;
    }

    int n = atoi(num);
    int resultado = factTail(n, 1);
    printf("Factorial de %d es: %d\n", n, resultado);

    return 0;
}

