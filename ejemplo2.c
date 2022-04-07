#include <stdio.h>
#include <stdlib.h>

int main() {

    char *Buff;
    Buff= (char *) malloc(100*sizeof(char));
    printf ("Ingrese una frase\n");
    gets(Buff);
    printf ("%s\n", Buff) ;//forma 1 de escribir
    puts (Buff);//forma 2 de escribir
    free(Buff);
    return 0;
    
}