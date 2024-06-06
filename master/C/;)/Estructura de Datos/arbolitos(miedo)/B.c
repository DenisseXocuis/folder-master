/*  information 'bout b-tree....
        K : grado del árbol
        K - 1: max keys
        K/2 : key del medio
*/
#include <stdio.h>
#include <stdlib.h>
#define K 5
enum hijo{FALSE, TRUE}HIJOS;

//estructura base para nodo-clave
    typedef struct node
    {   int clave;
        struct node *izquierda, *derecha;
        struct key *left, *right; //hijos
    }NODE;

//estructura base para key-list
    typedef struct key //<-lista de nodos
    {   int k;//¿cuántas llaves tendrá el nodo?
        struct node *head;
    }KEY_LIST;

void *insertar_bt(KEY_LIST **root, int clave);

    KEY_LIST *crear_lista()
    {   KEY_LIST *new_nodito = malloc(sizeof(KEY_LIST));
        if(!new_nodito) exit(1);
        new_nodito->head=NULL;
        new_nodito->k =0;
        return new_nodito;
    }

//crear nodo-clave
    void *insertar_clave(int clave)
    {   NODE *new_nodito = malloc(sizeof(NODE));
        if(!new_nodito) exit(1);
        new_nodito->clave = clave;
        new_nodito->derecha = new_nodito->izquierda = new_nodito->left = new_nodito->right= NULL;
    }

//busca si la clave ya existe
    int *buscar_clave(NODE *nodo, int clave)
    {   
        if(nodo == NULL) return 0;
        if(nodo->clave == clave) return 1; //la encontró
        if((nodo->clave < clave) && (clave < nodo->derecha))
        {   
            return buscar_clave(nodo->derecha, clave);
        }
        else return buscar_clave(nodo->derecha, clave);
    }

    //insertar de forma ordenada cada clave
    void *insertar_ordenado(NODE **lista, int clave)
    {   NODE *actuel = *lista, *suivant,*nodito = NULL;
        if(clave < actuel->clave)
        {
            if(actuel->izquierda == NULL)
            {
                if(actuel->left == NULL)
                { //inserta hasta el final
                    suivant = actuel;
                    actuel->izquierda= insertar_clave(clave);
                    actuel = actuel->izquierda;
                    actuel->derecha=suivant;
                    *lista = actuel;
                }
                else
                {
                    (*lista)->left->k++;
                    HIJOS = TRUE;
                    return insertar_ordenado(&actuel->left->head,clave);
                }
            }
            else  //insertar entre dos nodos
            {   actuel = actuel->izquierda;
                suivant = actuel->derecha;
                nodito = insertar_clave(clave);
                nodito->izquierda=actuel;
                nodito->derecha=suivant;
                actuel->derecha=nodito;
                suivant->izquierda=nodito;
            }
            return;
        }
        else if(actuel->derecha == NULL)
        {
            if(actuel->right == NULL)
            {
                //inserta hasta el final
                actuel->derecha = insertar_clave(clave);
                suivant = actuel->derecha;
                suivant->izquierda=actuel;
                return;
            }
            else
            {
                (*lista)->right->k++;
                HIJOS = TRUE;
                return insertar_ordenado(&actuel->right->head,clave);
            }
        }
        else return insertar_ordenado(&actuel->derecha, clave);
    }

    /* verifica si la parte decimal es mayor o igual a 0.5
        -si es así, redondea hacia arriba
        -si no, redondea hacia abajo
        
        ayuda para saber la posición de la clave del medio
        K/2
        */
    int redondear(float num)
    {
        int x = (int)num;
        return num-x >= 0.5 ? x+1 : x;
    }

    //dividir la lista
    void *dividir_bt(KEY_LIST **root)
    { //dividir el num de keys agregadas entre 2 y redondearlo
        //quitar 1 k

        NODE *actuel = (*root)->head, *nodito = NULL, *temp = NULL;
        KEY_LIST *left = NULL, *right = NULL, *copy = *root;
        float demi = (float)K/2; //para la clave mediana
        int clave = 0;
        int medio = redondear(demi);

        //nodo para clave mediana
        for(int i=1; i <= medio-1 ; i++) actuel = actuel->derecha;
        //desencola toda la lista restante de la izquierda  |1|2|    |3|    |4|5|
        clave = actuel->clave;
        if((*root)->head->right != NULL) //si ya tiene hijos
        {
            insertar_bt(&*root, clave);
        }
        else
        {
            *root = NULL;
            insertar_bt(&*root, clave);
        }

        

         // desencola toda la lista restante de la derecha
        nodito = actuel->derecha;
        actuel->derecha = NULL; //actuel es la lista restante de la izquierda
        nodito->izquierda=NULL;

        // crea una lista nueva con la lista restante de la derecha
        right = crear_lista();
        right->head = nodito;
        right->k++;
        //para contar todas las keys de la lista derecha y tener orden
        for(temp = right->head; temp->derecha != NULL; temp = temp->derecha) right->k++;

        //desencolar la lista restante de la izquierda
        nodito = actuel;
        actuel = actuel->izquierda;
        actuel->derecha = NULL;
        nodito->izquierda=NULL;
        free(nodito);
        //acomodar actual
        while(actuel->izquierda != NULL) actuel = actuel->izquierda;

        //crear la lista nueva con la lista restante de la derecha
        left = crear_lista();
        left->head= actuel;
        left->k++;

        //para contar todas las keys de la lista izquierda y tener orden
        for(temp = left->head; temp->derecha != NULL; temp = temp->derecha) left->k++;

        //asignar la lista izquierda y derecha a el nuevo root
        (*root)->head->left = left;
        (*root)->head->right = right;
        /* (*root)->head->izquierda = insertar_clave(-1); //representación de "NULL"
        (*root)->head->izquierda->next = left;
        (*root)->head->derecha=insertar_clave(-1);
        (*root)->head->derecha->next=right; */
    } 
    
    //insertar en B-tree
    void *insertar_bt(KEY_LIST **root, int clave)
    {   KEY_LIST *nodo;
        //si la1 lista no existe
        if(!*root)
        {   *root = crear_lista();
            (*root)->head = insertar_clave(clave);
            (*root)->k++;
            return;
        }
        else
        {
            //checa si el numero ya fue puesto, si no, inserta
            if(buscar_clave((*root)->head,clave))
            {
                puts("La clave ya ha sido insertada con anterioridad");
                puts("Pulse ENTER para continuar");
                getchar();
                return;
            }
            //si está llena, divide
            if((*root)->k == (K - 1))  
            {
                insertar_ordenado(&(*root)->head,clave);
                (*root)->k++;
                dividir_bt(&*root);
            }
            else if(((*root)->head->right != NULL) && ((*root)->head->right->k == (K-1)))
            {   
               //nodo = insertar_bt(&(*root)->head->right, clave);

                return;
            }
            else if(((*root)->head->left != NULL) && ((*root)->head->left->k == (K-1)))
            {
                return insertar_bt(&(*root)->head->left,clave);
            }
            else //si no está llena , insertar de forma ordenada
            {   insertar_ordenado(&(*root)->head, clave);
                if(!HIJOS) (*root)->k++;
                else HIJOS = FALSE;
            }
        }
    }

    void menu()
    {   system("cls || clear");
        puts("~*============={            }===============*~");
        puts("\t\t   B-Tree");
        puts("\t\t     by:");
        puts("    ©Lara Xocuis Martha Denisse. S22002213");
        puts("          Ingenieria en Informatica");
        puts("\t    \"Estructura de Datos\"");
        puts("~*==========================================*~");

    }
int main()
{   KEY_LIST *node_default = NULL;
    int op, num;
    HIJOS = FALSE;

   /*  do{
        menu();
        printf("Ingresa un numero ^^\n>");
        scanf("%d", &num);
        insertar_bt(&node_default,num);
        system("cls || clear");
        puts(" ¿Quieres agregar otro numero?");
        printf("[1] - Oui \n[0] - Non\n>");
        scanf("%d", &op);
    }while(op); */


        //4 debuggin' ;)

    //inserta, ordena y divide correctamente estos números; no se alcanza un nivel tan alto del árbol por ahora
    insertar_bt(&node_default,10);
    insertar_bt(&node_default,15);
    insertar_bt(&node_default,40);
    insertar_bt(&node_default,20);
    insertar_bt(&node_default,15); // para verificar si ya se ingresó con anterioridad
    insertar_bt(&node_default,50);
    insertar_bt(&node_default,5);
    insertar_bt(&node_default,60);
    insertar_bt(&node_default,70);
    insertar_bt(&node_default,80);

    puts("Au revoir!");
    return 0;
}