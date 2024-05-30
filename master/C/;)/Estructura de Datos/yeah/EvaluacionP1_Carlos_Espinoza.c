/* No hay mucho que decir, no quise hacer extravagante debido a la evaluacion y aunque todavia siento que esta lejos de ser un programa
   funcional y escalable en un ambiente real, creo que funciona como prueba de concepto :D */
/* Carlos Eduardo Espinoza Chapa */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
typedef struct mueble
{
    char nombre[25]; //LLave primaria
    float pcompra;
    float pventa;
    int cantidad;
    char descripcion[100];
} Muebles;

typedef struct empleados
{
    char nombre[30]; //Llave primaria
    char puesto[15];
    float salario;
    int ventas;
    double ganancias;
} Empleados;

typedef struct ventas
{
    int ID_Venta;
    char nombre_Mueble[25];   //LLave foranea hacia mueble
    char nombre_Vendedor[30]; //llave foranea hacia vendedor
    int cantidad;             //cantidad del mueble especificado vendido
    double total;             // total de venta
    double margen;            //margen de ganancia
} Ventas;

int menu(FILE *fp_muebles, FILE *fp_empleados, FILE *fp_ventas);
int abrirArchivo(FILE **fp, char *nombre, char *modo);
int insertar(FILE *fp, int choice);
int cambiarActivo(Empleados *empleados, FILE *fp_empleado);
int generarVenta(FILE *fp_venta, FILE *fp_mueble, FILE *fp_empleado, Empleados *activo);
int rellenarMueble(Muebles *mueble);
int rellenarEmpleado(Empleados *empleado);
int modificarM(FILE *fp_mueble);
int validar(FILE **fp, char *cad, int choice);
void listar(FILE *fp, int choice);
void numVentas(FILE *fp_venta);
void ranking(FILE *fp_empleados);
void HeapSort(Empleados *empleado, int size);
void heapify(Empleados *empleado, int size, int index);
void swap(Empleados *empleado1, Empleados *empleado2);

int main()
{
    int choice;
    FILE *fp_muebles, *fp_empleados, *fp_ventas;
    abrirArchivo(&fp_muebles, "test.dat", "wb+");
    abrirArchivo(&fp_empleados, "testEm.dat", "wb+");
    abrirArchivo(&fp_ventas, "testVen.dat", "wb+");
    if (!(fp_muebles && fp_ventas && fp_empleados))
    {
        printf("Error de apertura de archivo:\n");
        return 0;
    }
    do
    {
        choice = menu(fp_muebles, fp_empleados, fp_ventas);
    } while (choice);
    fclose(fp_muebles);
    fclose(fp_empleados);
    fclose(fp_ventas);
    printf("%d\n", __STDC__); // muestra 1 si el compilador se apega al estandar iso C
    printf("%d\n", __STDC_VERSION__); //Muestra la version del estandar de C que uso :D
    return 0;
}
// menu del programa
int menu(FILE *fp_muebles, FILE *fp_empleados, FILE *fp_ventas)
{ //Estoy empezando a pensar en romperlo en varios submenus :/
    int choice, c, n, i;
    Empleados activo;
    printf("Menu de muebleria:\n");
    printf("Ingrese la opcion deseada:\n");
    printf("Ingrese 1 para agregar elementos al registro:\n");
    printf("Ingrese 2 para visualizar un registro:\n");
    printf("Ingrese 3 para generar una venta:\n");
    printf("Ingrese 4 para iniciar sesion:\n");
    printf("Ingrese 5 para visualizar estadisticas de la tienda:\n");
    printf("Ingrese 0 para salir:\n");
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        return 0;
    case 1:
        printf("Ingrese la opcion deseada:\n");
        printf("Ingrese 1 para agregar un mueble:\n");
        printf("Ingrese 2 para agregar empleados:\n");
        fflush(stdin);
        scanf("%d", &c);
        printf("Numero de elementos a agregar?\n");
        fflush(stdin);
        scanf("%d", &n);
        if (c == 1)
        {
            fseek(fp_muebles, 0, SEEK_END);
            for (i = 0; i < n; i++)
            {
                insertar(fp_muebles, 1);
            }
        }
        else if (c == 2)
        {
            fseek(fp_empleados, 0, SEEK_END);
            for (i = 0; i < n; i++)
            {
                insertar(fp_empleados, 2);
            }
        }
        return 1;
        break;
    case 2:
        printf("Ingrese la opcion deseada:\n");
        printf("Ingrese 1 para visualizar muebles registrados:\n");
        printf("Ingrese 2 para visualizar empleados registrados:\n");
        printf("Ingrese 3 para visualizar ventas registradas:\n");
        printf("Ingrese 4 para modificar un mueble registrado:\n");
        fflush(stdin);
        scanf("%d", &c);
        if (c == 1)
        {
            listar(fp_muebles, 1);
        }
        else if (c == 2)
        {
            listar(fp_empleados, 2);
        }
        else if (c == 3)
        {
            listar(fp_ventas, 3);
        }
        else if (c == 4)
        {
            modificarM(fp_muebles);
        }

        return 2;
        break;
    case 3:
        printf("Generando una venta:\n");
        generarVenta(fp_ventas, fp_muebles, fp_empleados, &activo);
        return 3;
        break;
    case 4:
        printf("Cambiando empleado activo:\n");
        printf("Ingrese la llave (En este caso el nombre) del empleado:\n");
        fflush(stdin);
        scanf("%29[^\n]", activo.nombre);
        cambiarActivo(&activo, fp_empleados);
        return 4;
        break;
    case 5:
        printf("Imprimiendo estadisticas:\n");
        numVentas(fp_ventas);
        ranking(fp_empleados);
        return 5;
        break;
    default:
        break;
    }
    return 0;
}
// regresa 0 si no se pudo, 1 apertura exitosa
int abrirArchivo(FILE **fp, char *nombre, char *modo)
{
    *fp = fopen(nombre, modo);
    if (!*fp)
    {
        printf("No se pudo abrir el archivo especificado:\n");
        return 0;
    }
    return 1;
}
// 1 para mueble, 2 para empleados
int insertar(FILE *fp, int choice)
{
    Muebles mueble;
    Empleados empleado;
    int i = 0;
    switch (choice)
    {
    case 1:
        printf("Insertando el mueble numero [%d]:\n", i + 1);
        rellenarMueble(&mueble);
        fwrite(&mueble, sizeof(mueble), 1, fp);
        break;
    case 2:
        printf("Insertando al empleado numero [%d]:\n", i + 1);
        rellenarEmpleado(&empleado);
        fwrite(&empleado, sizeof(empleado), 1, fp);
        break;
    default:
        break;
    }
    return 1;
}
// cambia el empleado logeado en el programa
int cambiarActivo(Empleados *activo, FILE *fp_empleado)
{
    rewind(fp_empleado);
    if (!validar(&fp_empleado, activo->nombre, 2))
    {
        return 0;
    }
    fread(activo, sizeof(*activo), 1, fp_empleado);
    return 1;
}
// genera y valida una venta
int generarVenta(FILE *fp_venta, FILE *fp_mueble, FILE *fp_empleado, Empleados *activo)
{ //Puede ser rota en mas funciones y rediseñada
    Muebles mueble;
    Ventas venta;
    char nombre[100];
    int cantidad;
    srand(time(NULL));
    printf("Ingrese el nombre del mueble que se va a adquirir:\n");
    fflush(stdin);
    scanf("%99[^\n]", nombre);
    if (!validar(&fp_mueble, nombre, 1))
    {
        return 0;
    }
    fread(&mueble, sizeof(mueble), 1, fp_mueble);
    fseek(fp_mueble, -sizeof(mueble), SEEK_CUR);
    if (!validar(&fp_empleado, activo->nombre, 2))
    {
        return 0;
    }
    printf("Ingrese la cantidad deseada a adquirir:\n");
    fflush(stdin);
    scanf("%d", &cantidad);
    if ((mueble.cantidad - cantidad) < 0)
    {
        printf("No hay suficiente cantidad en el inventario:\n");
        return 0;
    }
    venta.ID_Venta = rand();
    strcpy(venta.nombre_Mueble, nombre);
    strcpy(venta.nombre_Vendedor, activo->nombre);
    venta.cantidad = cantidad;
    venta.total = (mueble.pventa * cantidad);
    venta.margen = ((mueble.pventa - mueble.pcompra) / mueble.pventa) * 100;
    fseek(fp_venta, 0, SEEK_END);
    fwrite(&venta, sizeof(venta), 1, fp_venta);
    mueble.cantidad -= cantidad;
    activo->ventas += cantidad;
    activo->ganancias += venta.total;
    fwrite(&mueble, sizeof(mueble), 1, fp_mueble);
    fwrite(activo, sizeof(*activo), 1, fp_empleado);
    return 1;
}
//funcion auxiliar de insertar() para la insercion de mueble
int rellenarMueble(Muebles *mueble)
{
    printf("Ingrese el nombre del mueble:\n");
    fflush(stdin);
    scanf("%s", mueble->nombre);
    printf("Ingrese el costo de adquisicion del mueble para la tienda:\n");
    fflush(stdin);
    scanf("%f", &mueble->pcompra);
    printf("Ingrese el precio de venta del mueble:\n");
    fflush(stdin);
    scanf("%f", &mueble->pventa);
    printf("Ingrese la cantidad de muebles en existencia:\n");
    fflush(stdin);
    scanf("%d", &mueble->cantidad);
    printf("Ingrese una breve descripcion del mueble:\n");
    fflush(stdin);
    scanf("%99[^\n]", mueble->descripcion);
    fflush(stdin);
    return 1;
}
// funcion auxiliar de insertar() para la insercion de empleados
int rellenarEmpleado(Empleados *empleado)
{
    printf("Ingrese el nombre del empleado:\n");
    fflush(stdin);
    scanf("%29[^\n]", empleado->nombre);
    printf("Ingrese el puesto actual del empleado:\n");
    fflush(stdin);
    scanf("%14[^\n]", empleado->puesto);
    printf("Ingrese el salario del empleado\n");
    fflush(stdin);
    scanf("%f", &empleado->salario);
    printf("Ingrese las ventas completadas del empleado:\n");
    fflush(stdin);
    scanf("%d", &empleado->ventas);
    printf("Ingrese las ganancias generadas por el empleado:\n");
    fflush(stdin);
    scanf("%lf", &empleado->ganancias);
    return 1;
}
// funcion para modificar un registro (este caso mueble)
int modificarM(FILE *fp_mueble)
{ //Iba a hacerlo para poder tambien modificar empleados pero estoy empezando a dudar acerca de este tipo de combinacion de funciones :(
    Muebles mueble;
    rewind(fp_mueble);
    printf("Ingrese el nombre la llave del elemento a modificar(En este caso el nombre):\n");
    fflush(stdin);
    scanf("%s", mueble.nombre);
    if (!validar(&fp_mueble, mueble.nombre, 1))
    {
        return 0;
    }
    printf("Ingrese los nuevos parametros:\n");
    rellenarMueble(&mueble);
    fwrite(&mueble, sizeof(mueble), 1, fp_mueble);
    return 1;
}

// 1 para muebles, 2 empleados, mueve el puntero a la direccion del registro
int validar(FILE **fp, char *cad, int choice)
{ 
    Muebles mueble;
    Empleados empleado;
    fseek(*fp, 0, SEEK_SET);
    switch (choice)
    {
    case 1:
        while (!feof(*fp))
        {
            fread(&mueble, sizeof(mueble), 1, *fp);
            if (feof(*fp))
            {
                printf("No se encontro el mueble especificado en el archivo:\n");
                return 0;
            }
            if (strcmp(cad, mueble.nombre) != 0)
            {
                continue;
            }
            else
            {
                fseek(*fp, -sizeof(mueble), SEEK_CUR);
                return 1;
            }
        }
        break;
    case 2:
        while (!feof(*fp))
        {
            fread(&empleado, sizeof(empleado), 1, *fp);
            if (feof(*fp))
            {
                printf("No se encontro al empleado especificado en el archivo:\n");
                return 0;
            }
            if (strcmp(cad, empleado.nombre) != 0)
            {
                continue;
            }
            else
            {
                fseek(*fp, -sizeof(empleado), SEEK_CUR);
                return 1;
            }
        }
        break;
    default:
        break;
    }
    return 0;
}
// 1 para mueble, 2 para empleado, 3 para venta
void listar(FILE *fp, int choice) // deberia romper el cuerpo en 3 funciones mas chicas
{
    Muebles mueble;
    Empleados empleado;
    Ventas venta;
    int i = 0;
    rewind(fp);
    switch (choice)
    {
    case 1:
        while (!feof(fp))
        {
            fread(&mueble, sizeof(mueble), 1, fp);
            if (feof(fp))
            {
                break;
            }
            printf("Elemento [%d]\n", i + 1);
            printf("Nombre: %s\nCosto de compra: %f\nPrecio de Venta: %f\nExistencias: %d\nDescripcion: %s\n",
                   mueble.nombre, mueble.pcompra, mueble.pventa, mueble.cantidad, mueble.descripcion);
            i++;
        }
        break;
    case 2:
        while (!feof(fp))
        {
            fread(&empleado, sizeof(empleado), 1, fp);
            if (feof(fp))
            {
                break;
            }
            printf("Elemento [%d]\n", i + 1);
            printf("Nombre: %s\nPuesto: %s\nSalario: %f\nVentas: %d\nGanancias: %lf\n",
                   empleado.nombre, empleado.puesto, empleado.salario, empleado.ventas, empleado.ganancias);
        }
        break;
    case 3:
        while (!feof(fp))
        {
            fread(&venta, sizeof(venta), 1, fp);
            if (feof(fp))
            {
                break;
            }
            printf("Elemento [%d]\n", i + 1);
            printf("ID: %d\nNombre de producto: %s\nCantidad: %d\nTotal: %lf\nVendedor: %s\n",
                   venta.ID_Venta, venta.nombre_Mueble, venta.cantidad, venta.total, venta.nombre_Vendedor);
        }
        break;
    default:
        break;
    }
}
// funcion de conteo de las ventas en el archivo
void numVentas(FILE *fp_venta)
{
    int i = 0, cantidad = 0;
    double margen = 0;
    Ventas venta;
    rewind(fp_venta);
    while (!feof(fp_venta))
    {
        fread(&venta, sizeof(venta), 1, fp_venta);
        if (feof(fp_venta))
        {
            break;
        }
        i++;
        cantidad += venta.cantidad;
        margen += venta.margen;
    }
    printf("Total de ventas registradas: %d\nProductos vendidos: %d\nMargen promedio: %.2lf%%\n",
           i, cantidad, margen / i);
}
// funcion de rankeo de empleados mediante metodo de ordenamiento heapsort
void ranking(FILE *fp_empleados)
{
    int size = 0, mem = 100, i = 0;
    Empleados *arr;
    rewind(fp_empleados);
    arr = (Empleados *)calloc(mem, sizeof(*arr));
    if (!arr)
    {
        printf("Error al intentar asignar memoria:\n");
        return;
    }
    while (!feof(fp_empleados))
    {
        if (size >= (mem - 1))
        {
            arr = realloc(arr, sizeof(*arr) * (mem *= 2));
            if (!arr)
            {
                printf("Error en la realocacion de memoria:\n");
                return;
            }
        }
        fread(&arr[size], sizeof(*arr), 1, fp_empleados);
        if (feof(fp_empleados))
        {
            break;
        }
        size++;
    }
    HeapSort(arr, size);
    printf("Imprimiendo el ranking de vendedores:\n");
    for (i = 0; i < size; i++)
    {
        printf("[%d]: %s : [%.2lf]\n", i + 1, arr[i].nombre, arr[i].ganancias);
    }
}
// funcion principal de heapsort 
void HeapSort(Empleados *empleado, int size)
{
    int i;
    for (i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(empleado, size, i);
    }

    for (i = (size - 1); i >= 0; i--)
    {
        swap(&empleado[0], &empleado[i]);
        heapify(empleado, i, 0);
    }
}
// funcion encargada de mantener la propiedad de heaps (Este caso minHeaps)
void heapify(Empleados *empleado, int size, int index)
{
    int root = index;
    int left = (2 * index + 1);
    int right = (2 * index + 2);

    if ((left < size) && (empleado[left].ganancias < empleado[root].ganancias))
    {
        root = left;
    }
    if ((right < size) && (empleado[right].ganancias < empleado[root].ganancias))
    {
        root = right;
    }

    if (root != index)
    {
        swap(&empleado[root], &empleado[index]);
        heapify(empleado, size, root);
    }
}
// funcion auxiliar para el intercambio de 2 elementos
void swap(Empleados *empleado1, Empleados *empleado2)
{
    Empleados temp = *empleado1;
    *empleado1 = *empleado2;
    *empleado2 = temp;
}

//