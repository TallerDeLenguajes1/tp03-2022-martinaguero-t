#include <stdio.h>
#include <stdlib.h>

int main() {

    char frase [100];
    char texto[] = "Ud escribio:";
    printf ("Escriba una frase: ") ;
    gets (frase);
    printf ("%s\n", texto) ;
    printf ("%s\n", frase) ;//forma 1 de escribir
    puts (frase);//forma 2 de escribir
    return 0;

}
