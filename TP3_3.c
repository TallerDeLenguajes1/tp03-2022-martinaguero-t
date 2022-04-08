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

void cargarCliente(Cliente* cliente, short numCliente);
// Función para cargar un cliente.

void cargarProductos(Producto* puntProductos, int cantidadProductos);
// Función que genera aleatoriamente los productos

void mostrarClientes(Cliente* arregloClientes, short cantidadClientes);
// Función para mostrar los clientes.

void mostrarCliente(Cliente* cliente, short numCliente);
// Funcion para mostrar un cliente.

float mostrar_calculartotal_productos(Producto* puntProductos, int numProductos);
// Funcion que muestra los productos de un cliente y calcula la suma de los costos totales de todos ellos.

float calcularCostoProducto(Producto producto);
// Función que calcula el costo de un tipo de producto.

void liberarMemoria(Cliente* arregloClientes, short cantClientes);

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

    printf("\n|================================|\n");

    mostrarClientes(arregloClientes,cantClientes);

    liberarMemoria(arregloClientes,cantClientes);

    return 0;

}

void cargarClientes(Cliente* arregloClientes, short cantidadClientes){

    for (short i = 0; i < cantidadClientes; i++)
    {
        printf("  ==> Cliente %d: \n",i+1);
        
        cargarCliente(arregloClientes, i+1);

        arregloClientes++;
        // Notar que esto no moverá el puntero en main, solamente su copia dentro de esta función.
    }

}

void cargarCliente(Cliente* cliente, short numCliente){

    cliente->clienteID = numCliente;
    // Guardo el ID del cliente segun el numero en el ciclo iterativo

    char* buffer = (char*) malloc(BUFFSIZE*sizeof(char));
    printf("    - Nombre del cliente: ");
    gets(buffer);

    cliente->nombreCliente = (char*) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(cliente->nombreCliente,buffer);
    // Guardo el nombre del cliente

    cliente->cantidadProductosAPedir = rand()%5 + 1;
    // Genero aleatoriamente la cantidad de productos que cada cliente pedirá, entre 1 y 5.

    cliente->productos = (Producto*) malloc(cliente->cantidadProductosAPedir*sizeof(Producto));
    // Segun la cantidad de productos, uso el puntero cliente->productos para crear un arreglo dinámico de estructuras
    
    cargarProductos(cliente->productos,cliente->cantidadProductosAPedir);
    // Invoco a la función que se encarga de cargar el arreglo de estructuras de productos

    free(buffer);
    // Libero la memoria reservada para el buffer
}

void cargarProductos(Producto* puntProductos, int cantidadProductos){

    short randTipo;

    for (int i = 0; i < cantidadProductos; i++)
    {
        puntProductos[i].productoID = i+1;
        // Asigno el ID del producto

        puntProductos[i].cantidad = rand()%10 + 1;
        // Genero aleatoriamente la cantidad de productos correspondiente a cada tipo.

        randTipo = rand()%5;

        puntProductos[i].tipoProducto = (char*) malloc((strlen(TiposProductos[randTipo])+1)*sizeof(char));

        strcpy(puntProductos[i].tipoProducto,TiposProductos[randTipo]);
        // Cargo aleatoriamente algún valor del arreglo TiposProductos

        puntProductos[i].precioUnitario = rand()%91 + 10;
        // Cargo aleatoriamente un precio.

    }

}

void mostrarClientes(Cliente* arregloClientes, short cantidadClientes){

    for (int i = 0; i < cantidadClientes; i++)
    {
        mostrarCliente(arregloClientes,i+1);
        arregloClientes++;
    }
    
}

void mostrarCliente(Cliente* cliente, short numCliente){

    float total;

    printf("==> Informacion del cliente %d: \n",numCliente);

    printf("  -> Nombre e ID: %s, %d\n",cliente->nombreCliente,cliente->clienteID);
  
    printf("  -> Pidio %d producto(s), los cuales son: \n",cliente->cantidadProductosAPedir);

    total = mostrar_calculartotal_productos(cliente->productos,cliente->cantidadProductosAPedir);

    printf("  -> Total de su compra: $%.2f \n",total);

    printf("\n");

}

float mostrar_calculartotal_productos(Producto* puntProductos, int numProductos){

    float total = 0;

    for (int i = 0; i < numProductos; i++)
    {
        printf("    - ID: %d - Tipo: %s - Precio unitario: $%.2f - Cantidad: %d - Costo total: $%.2f \n",puntProductos[i].productoID,puntProductos[i].tipoProducto,puntProductos[i].precioUnitario,puntProductos[i].cantidad,calcularCostoProducto(puntProductos[i]));

        total = total + calcularCostoProducto(puntProductos[i]);

    }
    
}

float calcularCostoProducto(Producto producto){

    return producto.cantidad*producto.precioUnitario;

}

void liberarMemoria(Cliente* arregloClientes, short cantClientes){

    for (int i = 0; i < cantClientes; i++)
    {

        free(arregloClientes[i].nombreCliente);
        // Se libera la memoria alocada para guardar el nombre de cada cliente.

        for (int j = 0; j < arregloClientes->cantidadProductosAPedir; j++)
        {
            free(arregloClientes[i].productos[j].tipoProducto);
            // Se libera, en cada producto del cliente, la memoria reservada para guardar el tipo de producto.
        }
        
        free(arregloClientes[i].productos);
        // Se libera la memoria reservada para el arreglo de productos.

    }
    
    free(arregloClientes);

}
