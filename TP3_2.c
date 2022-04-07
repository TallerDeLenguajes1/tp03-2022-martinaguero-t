#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO 5
#define BUFFSIZE 50

int main(){

    char* V[TAMANO];
    
    char* buffer;
    buffer = (char *) malloc(sizeof(BUFFSIZE)*sizeof(char));
    // Puntero auxiliar buffer para recibir los nombres ingresados por el usuario.

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d:",i+1);

        gets(buffer);
        // Uso gets para tomar el nombre ingresado por el usuario

        V[i] = (char *) malloc((strlen(buffer)+1)*sizeof(char));
        // Reservo memoria dinámicamente según la longitud de la cadena ingresada

        strcpy(V[i],buffer);
        // Copio la cadena ingresada en buffer a uno de los elementos del vector de nombres.

    }

    printf("\n");

    printf("Muestro los nombres: \n");

    for (int i = 0; i < 5; i++)
    {
        puts(V[i]);
    }
    
    return 0;

}