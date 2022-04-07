#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CLIENTESMAX 5
#define PRODUCTOSMAX 10
#define BUFFSIZE 50

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
} typedef Producto;

struct Cliente {
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *productos;
} typedef Cliente;

void cargarClientes(Cliente* arregloClientes, short cantidadClientes);
// Función para cargar la información de cada uno de los clientes.

int main(){

    srand(time(NULL));

    short cantClientes;
    // Cantidad de clientes, máximo 5 clientes por preventista

    Cliente* arregloClientes;
    // Puntero con el cual crearé el arreglo de clientes.

    printf("|==== SERVICIO DISTRIBUIDORA ====|\n");

    do
    {
        printf("==> Ingrese la cantidad de clientes: ");
        scanf("%hd",&cantClientes);
    } while (cantClientes < 1 || cantClientes > CLIENTESMAX);
    // Control para el ingreso de la cantidad de clientes.

    fflush(stdin);

    arregloClientes = (Cliente*) malloc(sizeof(Cliente)*cantClientes);
    // Reservo dinámicamente memoria para el arreglo de clientes según la cantidad de clientes.

    printf("\n==> Ingrese la informacion de cada uno de los clientes \n");

    cargarClientes(arregloClientes,cantClientes);


    // RECORDAR LIBERAR MEMORIA PARA CADA CLIENTE

    return 0;

}

void cargarClientes(Cliente* arregloClientes, short cantidadClientes){

    char* buffer = (char*) malloc(BUFFSIZE*sizeof(char));

    for (short i = 0; i < cantidadClientes; i++)
    {
        printf("  ==> Cliente %d: \n",i+1);
        
        arregloClientes[i].clienteID = i+1;
        // Guardo el ID del cliente segun el numero en el ciclo iterativo

        printf("    - Nombre del cliente: ");
        gets(buffer);

        arregloClientes[i].nombreCliente = (char*) malloc((strlen(buffer)+1)*sizeof(char));

        strcpy(arregloClientes[i].nombreCliente,buffer);
        // Guardo el nombre del cliente

        arregloClientes[i].cantidadProductosAPedir = rand()%5 + 1;

        arregloClientes[i].productos = (Producto*) malloc(arregloClientes[i].cantidadProductosAPedir*sizeof(Producto));

    }

    free(buffer);
    // Libero la memoria reservada para el buffer
}

