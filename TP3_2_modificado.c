#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANO 5
#define BUFFSIZE 50

int main(){

    char** vectorNombres;
    // Puntero doble donde se guardarán los punteros con los cuales se recibira los nombres

    int cantidadNombres;

    char* buffer;
    buffer = (char *) malloc(sizeof(BUFFSIZE)*sizeof(char));
    // Puntero auxiliar buffer para recibir los nombres ingresados por el usuario.

    do
    {
        printf("Hola, indique cuantos nombres ingresara: \n");
        scanf("%d",&cantidadNombres);

    } while (cantidadNombres < 1);
    // Se controla el ingreso de la cantidad de nombres.
    
    fflush(stdin);

    vectorNombres = (char **) malloc(cantidadNombres*sizeof(char*));

    for (int i = 0; i < cantidadNombres; i++)
    {
        printf("Ingrese el nombre %d:",i+1);

        gets(buffer);
        // Uso gets para tomar el nombre ingresado por el usuario

        vectorNombres[i] = (char *) malloc((strlen(buffer)+1)*sizeof(char));
        // Reservo memoria dinámicamente según la longitud de la cadena ingresada

        strcpy(vectorNombres[i],buffer);
        // Copio la cadena ingresada en buffer a uno de los elementos del vector de nombres.

    }

    printf("\n");

    printf("Muestro los nombres: \n");

    for (int i = 0; i < cantidadNombres; i++)
    {
        puts(vectorNombres[i]);
    }

    for(int i = 0; i < cantidadNombres; i++){
        free(vectorNombres[i]);
        // Libero la memoria para cada puntero del arreglo
    }

    free(vectorNombres);
    free(buffer);
    // Libero la memoria para el puntero doble y para el buffer.

    return 0;

}