#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char *Buff; //variable auxiliar
    char *Nombre;
    char *Apellido;
    Buff= (char *) malloc(100*sizeof(char));

    printf("Ingrese sus nombres: ");
    gets(Buff);

    Nombre= (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(Nombre,Buff);

    printf("Ingrese sus Apellidos: ");
    gets(Buff);
    
    Apellido= (char *) malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(Apellido,Buff);

    printf("escribiendo usando printf\n");
    printf ("%s\n", Buff) ;
    printf ("%s\n", Nombre) ;
    printf ("%s\n", Apellido) ;

    printf("escribiendo usando puts\n");
    puts (Buff);
    puts (Nombre);
    puts (Apellido);

    //libero la memoria reservada en todos los punteros
    free(Buff);
    free(Nombre);
    free(Apellido);

    return 0;

}