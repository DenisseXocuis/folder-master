#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define Usuario struct usuario
#define Elem_Usuario struct elem_usuario
#define Lista_Usuario struct lista_usuario
#define Vehiculo struct vehiculo
#define Elem_Vehiculo struct elem_Vehiculo
#define Elem_Lote struct elem_lote
#define Lista_Lote struct lista_lote
#define Elem_Piso struct elem_piso
#define Transaccion struct transaccion
#define Elem_Transaccion struct elem_transaccion
#define Cola_Transaccion struct cola_transaccion

struct vehiculo
{
    char tipo[20];
    char marca[20];
    char modelo[25];
    char color[15];
    char placas[15];
    int year;
    char descripcion[100];
};

struct elem_Vehiculo
{
    int identificador_usuario;
    int estacionado;
    Vehiculo coche;
    Elem_Vehiculo *siguiente;
};

struct usuario
{
    int id;
    char nombre[25];
    char apellido[25];
    char direccion[50]; // etc, etc
    Elem_Vehiculo *Veh_Inicio;
};

struct elem_usuario
{
    Usuario persona;
    Elem_Usuario *siguiente;
};

struct lista_usuario
{
    Elem_Usuario *inicio;
    Elem_Usuario *final;
};

struct elem_piso
{
    int numero_piso;
    int limite_dias;
    Elem_Lote *lista;
    Elem_Piso *siguiente;
};

struct elem_lote
{
    int numero_lote;
    int ocupacion;
    Elem_Vehiculo *inicio;
    Elem_Lote *siguiente;
};

struct transaccion
{
    int id;
    int estatus;
    Usuario persona;
    Vehiculo vehiculo;
    int num_piso;
    int num_lote;
    int F_Ingreso; // obtiene la fecha de ingreso;
    int F_Egreso;  // marca la fecha limite o si es una recogida la fecha actual
};

struct elem_transaccion
{
    Transaccion ticket;
    Elem_Transaccion *siguiente;
};

struct cola_transaccion
{
    Elem_Transaccion *inicio;
    Elem_Transaccion *final;
};


int menu();
int Registrar_Persona(Lista_Usuario *lista);
int Rellenar_Persona(Elem_Usuario *temp);
Elem_Usuario *Buscar_Persona(Lista_Usuario *lista, int identificador);
void Listar_Personas(Elem_Usuario *lista);
int Agregar_Vehiculos(Elem_Vehiculo **inicio);
int Rellenar_Vehiculo(Elem_Vehiculo *temp);
int Eliminar_Vehiculo(Elem_Vehiculo **inicio, char *placas);
int Colocar_Vehiculo(Elem_Vehiculo *vehiculo, Elem_Vehiculo **lote_inicio);
int generar_Piso(Elem_Piso **inicio);
int generar_Lotes(Elem_Lote **lotes, int num_lotes);
Elem_Piso *Buscar_Piso(Elem_Piso **inicio, int dias);
Elem_Lote *Buscar_Lote(Elem_Lote **inicio);
Elem_Lote *Entregar_Vehiculo(Elem_Piso *inicio, int num_piso, int num_lote);
Elem_Vehiculo *Comparar_Placas(Elem_Vehiculo **inicio, char *placas);
Elem_Lote *Localizar_Lote(Elem_Lote **inicio, char *placas);
Elem_Lote *Localizar_Vehiculo(Elem_Piso **inicio, char *placas);
Transaccion *Resguardar_Vehiculo(Elem_Usuario *usuario, char *placas, int dias, Elem_Piso **inicio, Cola_Transaccion *Lista);
Transaccion *Recoger_Vehiculo(Elem_Usuario *activo, Elem_Piso **inicio, Transaccion *transa, Cola_Transaccion *Lista);
void Listar_Garaje(Elem_Piso *inicio);
void Listar_Lote(Elem_Lote *inicio);
void Listar_Vehiculos(Elem_Vehiculo *lista);
void Listar_Transferencias(Elem_Transaccion *inicio);
int encolar(Cola_Transaccion *Lista, Transaccion *transa);

int main()
{
    Cola_Transaccion *Lista = (Cola_Transaccion *) calloc(1, sizeof(*Lista));
    Transaccion *temp = NULL;
    Lista_Usuario *temp_usuario = (Lista_Usuario *)calloc(1, sizeof(Lista_Usuario));
    Elem_Usuario *activo = NULL;
    Elem_Piso *Garaje = NULL;
    char placas[15];
    int choice = 0, subchoice = 0, identificador = 0, dias;
    if (!Lista || !temp_usuario)
        return 0;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            printf("Ingrese 1 para registrar un nuevo usuario:\n");
            printf("Ingrese 2 para iniciar sesion con un usuario registrado:\n");
            scanf("%d", &subchoice);
            if (subchoice == 1)
                Registrar_Persona(temp_usuario);
            else if (subchoice == 2)
            {
                printf("Ingrese el id del usuario que va a iniciar sesion:\n");
                scanf("%d", &identificador);
                activo = Buscar_Persona(temp_usuario, identificador);
                if (!activo)
                    printf("Error al iniciar sesion:\n");
                else
                    printf("Sesion iniciada:\n");
            }
            break;
        case 2:
            if (!activo)
            {
                printf("No hay usuario con sesion activa:\n");
                break;
            }
            printf("Ingrese 1 para registrar un nuevo vehiculo:\n");
            printf("Ingrese 2 para eliminar un vehiculo registrado:\n");
            printf("Ingrese 3 para listar todos los vehiculos registrados:\n");
            scanf("%d", &subchoice);
            if (subchoice == 1)
            {
                if (Agregar_Vehiculos(&activo->persona.Veh_Inicio))
                {
                    printf("Vehiculo agregado con exito:\n");
                    break;
                }
                else
                {
                    printf("No se pudo registrar el vehiculo, intentelo mas tarde:\n");
                    break;
                }
            }
            else if (subchoice == 2)
            {
                printf("Por favor ingrese las placas del vehiculo que desea remover:\n");
                fflush(stdin);
                scanf("%14[^\n]", placas);
                fflush(stdin);
                if (Eliminar_Vehiculo(&activo->persona.Veh_Inicio, placas))
                    printf("Vehiculo Removido con Exito\n");
                else
                    printf("No se pudo remover el vehiculo indicado:\n");
                break;
            }
            else if (subchoice == 3)
            {
                Listar_Vehiculos(activo->persona.Veh_Inicio);
                break;
            }
        case 3:
            printf("Ingrese 1 para resguardar un vehiculo registrado:\n");
            printf("Ingrese 2 para recoger un vehiculo resguardado:\n");
            scanf("%d", &subchoice);
            if (subchoice == 1)
            {
                if (!activo || !Garaje)
                {
                    printf("Error de inicio, por favor inicie sesion y escoja su garaje:\n");
                    break;
                }
                printf("Por favor ingrese las placas del vehiculo que desea resguardar:\n");
                fflush(stdin);
                scanf("%14[^\n]", placas);
                fflush(stdin);
                printf("Ingrese el numero maximo de dias que tendra resguardado el vehiculo:\n");
                scanf("%d", &dias);
                temp = Resguardar_Vehiculo(activo, placas, dias, &Garaje, Lista);
                if (!temp)
                {
                    printf("Operacion Fallida:\n");
                }
                else
                {
                    printf("Operacion Exitosa:\n");
                }
                break;
            }
            else if (subchoice == 2)
            {
                temp = Recoger_Vehiculo(activo, &Garaje, NULL, Lista);
                if (!temp)
                {
                    printf("Operacion Fallida:\n");
                }
                else
                {
                    printf("Operacion Exitosa:\n");
                }
                break;
            }
        case 4:
            printf("Ingrese 1 para Generar un piso nuevo:\n");
            printf("Ingrese 2 para listar a todo los usuarios registrados:\n");
            printf("Ingrese 3 para ver la cola de transacciones:\n");
            printf("Ingrese 4 para ver todos los coches estacionados:\n");
            scanf("%d", &subchoice);
            if (subchoice == 1)
            {
                generar_Piso(&Garaje);
                break;
            }
            else if (subchoice == 2)
            {
                Listar_Personas(temp_usuario->inicio);
                break;
            }
            else if (subchoice == 3)
            {
                Listar_Transferencias(Lista->inicio);
                break;
            }
            else if (subchoice == 4)
            {
                Listar_Garaje(Garaje);
            }
        default:
            break;
        }
    } while (choice);
    return 0;
}

int Rellenar_Persona(Elem_Usuario *temp)
{
    printf("Ingrese la clave unica del usuario:\n");
    fflush(stdin);
    scanf("%d", &temp->persona.id);
    fflush(stdin);
    printf("Ingrese el nombre del usuario:\n");
    scanf("%24[^\n]", temp->persona.nombre);
    fflush(stdin);
    printf("Ingrese el apellido del usuario:\n");
    scanf("%24[^\n]", temp->persona.apellido);
    fflush(stdin);
    printf("Ingrese el domicilio del usuario:\n");
    scanf("%49[^\n]", temp->persona.direccion);
    fflush(stdin);
    temp->persona.Veh_Inicio = NULL;
    return 1;
}
// Muestra las opciones en el menu principal
int menu()
{
    int c = 0;
    printf("Ingrese 1 para ver opciones relacionadas al usuario:\n");
    printf("Ingrese 2 para ver opciones relacionadas acerca de los vehiculos;\n");
    printf("Ingrese 3 para ver opciones relacionadas con el resguardo/recogida de vehiculos:\n");
    printf("Ingrese 4 para ver opcones relacionadas con el estacionamiento:\n");
    printf("Ingrese 0 para terminar la ejecucion del programa:\n");
    scanf("%d", &c);
    return c;
}
// agrega a un usuarion a la lista en memoria
int Registrar_Persona(Lista_Usuario *lista)
{
    Elem_Usuario *temp = (Elem_Usuario *)calloc(1, sizeof(Elem_Usuario));
    if (!temp)
        return 0;
    if (!lista)
    {
        printf("Error en la lista ingresada:\n");
        free(temp);
        return 0;
    }
    Rellenar_Persona(temp);
    temp->siguiente = NULL;
    if (!lista->final && !lista->inicio)
    {
        lista->inicio = lista->final = temp;
        return 1;
    }
    else
    {
        lista->final->siguiente = temp;
        lista->final = temp;
        return 1;
    }
}
// busca a un usuario en la lista en memoria
Elem_Usuario *Buscar_Persona(Lista_Usuario *lista, int identificador)
{
    Elem_Usuario *temp = lista->inicio;
    while (temp)
    {
        if (temp->persona.id == identificador)
            return temp;
        else
            temp = temp->siguiente;
        if (!temp)
            return NULL;
    }
    return NULL;
}
// muestra a todos los usuarios en la lista en memoria
void Listar_Personas(Elem_Usuario *inicio)
{
    if (!inicio)
        return;
    printf("ID registrado: %d\n", inicio->persona.id);
    printf("Nombre del usuario: %s\n", inicio->persona.nombre);
    printf("Apellido del usuario: %s\n", inicio->persona.apellido);
    printf("Direccion registrada: %s\n", inicio->persona.direccion);

    return Listar_Personas(inicio->siguiente);
}
//agrega un vehiculo nuevo a una lista, creo que seria mas eficiente refactorizar y ya pasarle el vehiculo lleno para evitar dupli de funciones :/
int Agregar_Vehiculos(Elem_Vehiculo **inicio)
{
    if (!(*inicio))
    {
        *inicio = (Elem_Vehiculo *)calloc(1, sizeof(**inicio));
        if (!(*inicio))
        {
            return 0;
        }
        Rellenar_Vehiculo(*inicio);
        return 1;
    }
    else if (!(*inicio)->siguiente)
    {
        (*inicio)->siguiente = (Elem_Vehiculo *)calloc(1, sizeof(**inicio));
        if (!(*inicio)->siguiente)
            return 0;
        Rellenar_Vehiculo((*inicio)->siguiente);
        return 1;
    }
    else
    {
        return Agregar_Vehiculos(&(*inicio)->siguiente);
    }
}
// fucion auxiliar de agrega_vehiculo, se encarga del actual llenado de los campos de la struct vehiculo
int Rellenar_Vehiculo(Elem_Vehiculo *temp)
{
    fflush(stdin);
    printf("Ingrese el tipo de vehiculo a guardar:\n");
    scanf("%19[^\n]", temp->coche.tipo);
    fflush(stdin);
    printf("Ingrese la marca del vehiculo a guardar:\n");
    scanf("%19[^\n]", temp->coche.marca);
    fflush(stdin);
    printf("Ingrese la edicion del vehiculo a guardar:\n");
    scanf("%24[^\n]", temp->coche.modelo);
    fflush(stdin);
    printf("Ingrese el color de vehiculo a guardar:\n");
    scanf("%14[^\n]", temp->coche.color);
    fflush(stdin);
    printf("Ingrese las placas registradas del vehiculo a guardar:\n");
    scanf("%14[^\n]", temp->coche.placas);
    fflush(stdin);
    printf("Ingrese el modelo de lanzamiento del vehiculo a guardar:\n");
    scanf("%d", &temp->coche.year);
    fflush(stdin);
    printf("Ingrese una breve descripcion del vehiculo (detalles, informacion identificadora, etc) a guardar:\n");
    scanf("%99[^\n]", temp->coche.descripcion);
    fflush(stdin);
    return 1;
}
// funcion para generar pisos en el estacionamiento, relacionada con generar_Lotes
int generar_Piso(Elem_Piso **inicio)
{
    if (!(*inicio))
    {
        *inicio = (Elem_Piso *)calloc(1, sizeof(**inicio));
        (*inicio)->limite_dias = 1;
        (*inicio)->numero_piso = 0;
        if (generar_Lotes(&(*inicio)->lista, 0))
            return 1;
        else
            return 0;
    }
    else if (!(*inicio)->siguiente)
    {
        (*inicio)->siguiente = (Elem_Piso *)calloc(1, sizeof(**inicio));
        if (!(*inicio)->siguiente)
            return 0;
        (*inicio)->siguiente->limite_dias = (*inicio)->limite_dias * 3;
        (*inicio)->siguiente->numero_piso = (*inicio)->numero_piso + 1;
        if (generar_Lotes(&(*inicio)->siguiente->lista, 0))
        {
            return 1;
        }
        else
            return 0;
    }
    return generar_Piso(&(*inicio)->siguiente);
}
// funcion auxiliar para generar los lotes en los pisos, por el momento genera 4 lotes por piso, posiblemente deba rediseñarla
int generar_Lotes(Elem_Lote **lotes, int num_lotes)// para en un momento dado ampliar lotes, agregandole un campo de el numero de lotes a crear y el num del lote anterior
{
    if (num_lotes >= 4)
    {
        return 1;
    }
    else if (!(*lotes))
    {
        *lotes = (Elem_Lote *)calloc(1, sizeof(**lotes));
        if (!lotes)
            return 0;
        (*lotes)->numero_lote = num_lotes;
    }
    return generar_Lotes(&(*lotes)->siguiente, num_lotes + 1);
}
// funcion para eliminar un vehiculo de una determinada lista, compara las placas
int Eliminar_Vehiculo(Elem_Vehiculo **inicio, char *placas)// a lo mejor rediseñando la funcion de buscar_Vehiculo puedo reducir codigo aqui
{// pk en un determinado caso, necesito modificar la ligadura anterior, cosa que no me es posible en la forma actual de buscar_vehiculo
    Elem_Vehiculo *temp = NULL;
    if (!(*inicio))
    {
        return 0;
    }
    else if (!strcmp((*inicio)->coche.placas, placas))
    {
        temp = (*inicio);
        (*inicio) = (*inicio)->siguiente;
        free(temp);
        return 1;
    }
    else if ((*inicio)->siguiente)
    {
        if (!strcmp((*inicio)->siguiente->coche.placas, placas))
        {
            temp = (*inicio)->siguiente;
            (*inicio)->siguiente = temp->siguiente;
            free(temp);
            return 1;
        }
        else
        {
            return Eliminar_Vehiculo(&(*inicio)->siguiente, placas);
        }
    }
    else
    {
        return 0;
    }
}
// funcion auxiliar de resguardar_vehiculo, se encarga de la actual colocacion del vehiculo en la pila asignada
int Colocar_Vehiculo(Elem_Vehiculo *vehiculo, Elem_Vehiculo **lote_inicio)
{
    Elem_Vehiculo *aux = (Elem_Vehiculo *)malloc(sizeof(*aux));
    if (!aux)
    {
        return 0;
    } else if (vehiculo->estacionado){
        free(aux);
        return 0;
    }
    *aux = *vehiculo;
    if (!(*lote_inicio))
    {
        aux->siguiente = NULL;
        *lote_inicio = aux;
    }
    else
    {
        aux->siguiente = (*lote_inicio);
        (*lote_inicio) = aux;
    }
    vehiculo->estacionado = 1;
    return 1;
}
//funcion auxiliar de resguardar_vehiculo, busca un piso disponible que pueda resguardar el coche por el numero de dias indicado
Elem_Piso *Buscar_Piso(Elem_Piso **inicio, int dias)
{
    if (!(*inicio))
        return NULL;
    else if ((*inicio)->limite_dias < dias)
        return NULL;
    else if (((*inicio)->limite_dias >= dias) && (Buscar_Lote(&(*inicio)->lista))) //Para que incluso si no hay lugar en en piso poder seguir buscando en otros mientras no se pase del limite
        return (*inicio);
    else
        return Buscar_Piso(&(*inicio)->siguiente, dias);
}
// funcion auxiliar de resguardar_vehiculo y buscar_piso, examina el nivel de ocupacion de los lotes, y regresa el primer lote disponible que encuentra
Elem_Lote *Buscar_Lote(Elem_Lote **inicio)
{
    if (!(*inicio))
        return NULL;
    else if ((*inicio)->ocupacion < 3)
        return (*inicio);
    else
        return Buscar_Lote(&(*inicio)->siguiente);
}
//funcion administrativa encargada del resguardo de un coche en el estacinamiento, regresa un ticket con los detalles de la transaccion
Transaccion *Resguardar_Vehiculo(Elem_Usuario *usuario, char *placas, int dias, Elem_Piso **inicio, Cola_Transaccion *Lista)
{
    Transaccion *temp_transaccion = (Transaccion *)calloc(1, sizeof(*temp_transaccion));
    Elem_Piso *temp_piso;
    Elem_Lote *temp_lote;
    Elem_Vehiculo *temp;
    if (!temp_transaccion)
    {
        printf("Problema en el sistema de pedido, por favor intente mas tarde:\n");
        return NULL;
    }
    srand(time(NULL));
    temp = Comparar_Placas(&usuario->persona.Veh_Inicio, placas);
    if (!temp)
    {
        printf("El usuario no cuenta con un vehiculo disponible con el numero de placa indicado:\n");
        return NULL;
    }
    temp_piso = Buscar_Piso(inicio, dias);
    if (!temp_piso)
    {
        printf("No hay un piso disponible que se adecue a las necesidades:\n");
        return NULL;
    }
    temp_lote = Buscar_Lote(&temp_piso->lista);
    if (!temp_lote)
    {
        printf("Error en la asignacion de lugares:\n"); // No deberia pasar pk ya se busco en Buscar_Piso, pero pues siempre puede haber algo extraño en la ejecucion
        return NULL;
    }
    if (!Colocar_Vehiculo(temp, &temp_lote->inicio))
    {
        printf("Error en el resguardo del vehiculo, contacte a un administrador:\n");
        return NULL;
    }
    temp_lote->ocupacion = (temp_lote->ocupacion + 1);
    printf("Vehiculo estacionado:\n");
    temp_transaccion->id = rand() % 101;
    temp_transaccion->estatus = 1;
    temp_transaccion->persona = usuario->persona;
    temp_transaccion->vehiculo = temp->coche;
    temp_transaccion->num_piso = temp_piso->numero_piso;
    temp_transaccion->num_lote = temp_lote->numero_lote;
    temp_transaccion->F_Ingreso = 1;
    temp_transaccion->F_Egreso = 2;
    if (!encolar(Lista, temp_transaccion)){
        printf("Error al encolar la transferencia, contacte a un administrador:\n");
    }
    return temp_transaccion;
}
// funcion auxiliar para la recogida de vehiculos, encargada regresa el la direccion del lote en el que esta el vehiculo, teniendo el num del piso, y del lote
Elem_Lote *Entregar_Vehiculo(Elem_Piso *inicio, int num_piso, int num_lote)// Revisitandola, creo que es sintoma de mal diseño y puede prescindirse de esta :/
{
    Elem_Lote *aux = NULL;
    if (inicio->numero_piso != num_piso)
        return Entregar_Vehiculo(inicio->siguiente, num_piso, num_lote);
    aux = inicio->lista;
    while (num_lote != aux->numero_lote)
    {
        aux = aux->siguiente;
    }
    return aux;
}
// funcion para encontrar un vehiculo determinado en una lista, 
Elem_Vehiculo *Comparar_Placas(Elem_Vehiculo **inicio, char *placas)// originalmente llamada buscar_vehiculo, pero me confundi y escribi 2 funciones
// con el mismo porposito y esta era la que tenia mas referencias , por lo que me dio flojera cambiarla,
{
    if (!(*inicio))
    {
        return NULL;
    }
    else if (!strcmp((*inicio)->coche.placas, placas))
    {
        return (*inicio);
    }
    else
    {
        return Comparar_Placas(&(*inicio)->siguiente, placas);
    }
}
// funcion auxiliar para encontrar un vehiculo, cuando no se conoce donde esta resguardado, va comparando lote por lote
Elem_Lote *Localizar_Lote(Elem_Lote **inicio, char *placas)
{
    if (!(*inicio))
    {
        return NULL;
    }
    else if (!Comparar_Placas(&(*inicio)->inicio, placas))
    {
        return Localizar_Lote(&(*inicio)->siguiente, placas);
    }
    else
    {
        return (*inicio);
    }
}
//funcion padre para localzar un vehiculo perdido en el estacionamiento, va comparando piso por piso
Elem_Lote *Localizar_Vehiculo(Elem_Piso **inicio, char *placas)
{
    Elem_Lote *temp = NULL;
    if (!(*inicio))
    {
        return NULL;
    }
    temp = Localizar_Lote(&(*inicio)->lista, placas);
    if (temp)
    {
        return temp;
    }
    else
    {
        return Localizar_Vehiculo(&(*inicio)->siguiente, placas);
    }
}
// funcion para recoger un vehiculo estacionado en el estacionamiento, regresa un ticket con detalles de las transacciones
Transaccion *Recoger_Vehiculo(Elem_Usuario *activo, Elem_Piso **inicio, Transaccion *transa, Cola_Transaccion *Lista)
{
    Transaccion *aux = NULL;
    Elem_Lote *temp = NULL;
    Elem_Vehiculo *vehiculo = NULL;
    char placas[15];
    if (!transa)
    {
        printf("Por favor ingrese las placas del coche que desea estacionar:\n");
        fflush(stdin);
        scanf("%14[^\n]", placas);
        fflush(stdin);
        temp = Localizar_Vehiculo(inicio, placas);
        if (!temp)
        {
            printf("No se pudo localizar el vehiculo en el garaje. Contacte a un administrador:\n");
            return NULL;
        }
        printf("Se procedera a la extraccion del vehiculo. Por favor espere:\n");
        if (!Eliminar_Vehiculo(&temp->inicio, placas))
        {
            printf("Problemas al extraer el vehiculo. Por favor contacte a un administrador:\n");
            return NULL;
        }
    }
    else
    {
        temp = Entregar_Vehiculo((*inicio), transa->num_piso, transa->num_lote);
        if (!temp)
        {
            printf("No se pudo localizar el vehiculo en el garaje. Contacte a un administrador:\n");
            return NULL;
        }
        strcpy(placas, transa->vehiculo.placas);
    }
    vehiculo = Comparar_Placas(&activo->persona.Veh_Inicio, placas);
    vehiculo->estacionado = 0;
    aux = (Transaccion *)calloc(1, sizeof(*aux));
    if (!aux)
    {
        printf("Error de registro:\n");
        return NULL;
    }
    temp->ocupacion = (temp->ocupacion - 1);
    printf("Vehiculo Entregado:\n");
    aux->id = rand() % 101;
    aux->estatus = 0;
    aux->persona = activo->persona;
    aux->vehiculo = vehiculo->coche;
    aux->num_piso = 0;
    aux->num_lote = 0;
    aux->F_Ingreso = 2;
    aux->F_Egreso = 1;
    if (!encolar(Lista, aux)){
        printf("Error al encolar la transferencia, contacte a un administrador:\n");
    }
    return aux;
}

void Listar_Garaje(Elem_Piso *inicio)
{// funcion padre para mostrar el estado del estacionamiento entero, va piso por piso
    if (!inicio)
    {
        return;
    }
    else
    {
        printf("Piso [%d]\n", inicio->numero_piso);
        Listar_Lote(inicio->lista);
        return Listar_Garaje(inicio->siguiente);
    }
}
// funcion auxiliar para mostrar el estado del estacionamiento, va lote por lote
void Listar_Lote(Elem_Lote *inicio)
{
    if (!inicio)
    {
        return;
    }
    else
    {
        printf("Lote [%d]\n", inicio->numero_lote);
        Listar_Vehiculos(inicio->inicio);
        return Listar_Lote(inicio->siguiente);
    }
}
// funcion auxiliar para mostrar el estado del estacionamiento, se encarga de mostrar los datos de los vehiculos
void Listar_Vehiculos(Elem_Vehiculo *lista)
{
    if (!lista)
        return;
    printf("Tipo de vehiculo: %s\n", lista->coche.tipo);
    printf("Marca del vehiculo: %s\n", lista->coche.marca);
    printf("Edicion del vehiculo: %s\n", lista->coche.modelo);
    printf("Ingrese el color primario del vehiculo: %s\n", lista->coche.color);
    printf("Placas Registradas: %s\n", lista->coche.placas);
    printf("Fecha de lanzamiento del vehiculo: %d\n", lista->coche.year);
    printf("Descripcion introducida: %s\n", lista->coche.descripcion);
    printf("\n");
    return Listar_Vehiculos(lista->siguiente);
}
// funcion para mostrar la cola de transferencias
void Listar_Transferencias(Elem_Transaccion *inicio){
    if (!inicio)
        return;
    printf("ID de la transferencia: %d\n", inicio->ticket.id);
    printf("Estatus de la operacion: %d\n", inicio->ticket.estatus);
    printf("Nombre del usuario: %s %s\n", inicio->ticket.persona.nombre, inicio->ticket.persona.apellido);
    printf("Vehiculo: %s\n", inicio->ticket.vehiculo.placas);
    printf("Piso [%d]: Lote [%d]\n", inicio->ticket.num_piso, inicio->ticket.num_lote);

    return Listar_Transferencias(inicio->siguiente);
}
//funcion auxiliar para agregar un ticket a la cola de transferencias
int encolar(Cola_Transaccion *Lista, Transaccion *transa){
    Elem_Transaccion *temp= (Elem_Transaccion *) calloc(1, sizeof(*temp));
    if (!temp)
        return 0;
    temp->ticket = *transa;
    if (!Lista->inicio){
        Lista->inicio=Lista->final=temp;
    } else 
    {
        Lista->final->siguiente = temp;
        Lista->final = temp;
    }
    return 1;
}

