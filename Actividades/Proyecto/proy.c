#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
// LEXICO
#define Max 150

typedef struct
{
    int dia;
    int mes;
    int anio;
} Tfecha;
typedef struct
{
    int DNI;
    char nombre[20];
    char apellido[20];
    Tfecha nacimiento; // Campo de tipo Tfecha para la fecha de nacimiento
    int edad;
    char ciudad[20];      // Ciudad de residencia actual
    char ciudadAntes[20]; // Ciudad de residencia en el momento de la guerra
    char DP[30];          // Dirección Postal
    char CE[20];          // Correo Electrónico
    char tel[15];         // Teléfono
    int VF;               // Vive/falleció: Verdadero si está vivo, Falso si ha fallecido
    Tfecha fallecimiento; // Campo de tipo Tfecha para la fecha de fallecimiento
    char beneficio[20];   // Número beneficio nacional
    char CP[10];          // Código postal
    char provincia[50];   // Provincia de nacimiento
    int fuerza;           // Fuerza a la que perteneció: 1-Marina, 2-Gendarmeria, 3-Ejército, 4-Aeronáutica
    char destino[50];     // Destino en Malvinas
    char funcion[100];    // Función en Malvinas
    char grado[20];       // Grado
    char secuelas[200];   // Secuelas de la guerra

} TPersona;
typedef struct
{
    TPersona a[Max];
    int cant;
} TData;
TData persona;
int num, doc;
TPersona new;
char localidad[20];
struct Telem
{
    TPersona info;
    struct Telem *next;
} Telem;
struct TDoblete
{
    TPersona info;
    struct TDoblete *next;
    struct TDoblete *back;
} TDoblete;
struct Telem *list;
struct Telem *aux1;
struct TDoblete *puntIni;
struct TDoblete *puntFin;
struct TDoblete *aux2;
char ciudad[20];
FILE *f = NULL;
char apellidoBuscar[20];
int fuerzaBuscada;
int mesBuscado;
Tfecha fechaActual;

// DECLARACION DE FUNCIONES Y ACCIONES
int Vacia(TData p);
int Llena(TData s);
int CalcularEdad(Tfecha fechaNacimiento, Tfecha fechaActual);
void CargarFecha(Tfecha *fecha);
void Insertar(TPersona nuevo, TData *q);
void Suprimir(int d, TData *q);
void Mostrar(TData q);
void Modificar(int d, TData *q);
void Fallecidos(TData q, struct Telem **lis);
void Locales(TData q, char loc[20], struct TDoblete *ini, struct TDoblete *fin);
void MostrarListaDoble(struct TDoblete *ini, struct TDoblete *fin);
void FuerzaPertenenciente(TData q, int fuerza, struct TDoblete **ini, struct TDoblete **fin);
void Buble(TData *x, int opc);
void Intercambiar(TPersona *x, TPersona *y);
void PasarDeArchivoAArray(TData *x);
void GuardarEnArchivo(TData x);
void CumpleañosDelMismoMes(TData q, int mes);
void BusquedaApellido(TData q, char a[20]);
void ListarPorAPellido(TData x);
void ListarPorDNI(TData x);
void InicializarLSE(struct Telem **punts, struct Telem **aux);
void InicializarLDE(struct TDoblete **ini, struct TDoblete **fin, struct TDoblete **aux);

// INICIO
int main()
{
    PasarDeArchivoAArray(&persona);
    do
    {

        printf("\n\t\t\t==> MENU DE OPCIONES <==\n");
        printf("\n\t\t1: Dar de alta a una persona \n\t\t2: Para dar de baja a una persona por DNI \n\t\t3: Modifcar un campo por DNI \n\t\t4: Lista completa ordenada por DNI \n\t\t5: Lista completa ordenada por apellido\n\t\t6: Listar personas fallecidas\n\t\t7: Listar personas de una misma fuerza \n\t\t8: Listas personas nacidas en un mismo mes \n\t\t9: Listar personas con un mismo apellido \n\t\t10: Guardar cambios\n\t\t 0:Salir \n\t\t");
        printf("\nIngrese su opcion: [ ]\b\b");
        scanf("%d", &num);
        getchar();
        if (num == 1)
        {
            persona.cant = persona.cant + 1;
            printf("Nombre: ");
            fgets(new.nombre, sizeof(new.nombre), stdin);
            new.nombre[strcspn(new.nombre, "\n")] = '\0';
            printf("Apellido: ");
            fgets(new.apellido, sizeof(new.apellido), stdin);
            new.apellido[strcspn(new.apellido, "\n")] = '\0';

            printf("DNI: ");
            scanf("%d", &new.DNI);
            for (int i = 0; i < persona.cant; i++)
            {
                if (new.DNI == persona.a[i].DNI)
                {
                    printf("Ese DNI ya existe, ingrese otro: ");
                    scanf("%d", &new.DNI);
                }
            }

            printf("Nacimiento: ");
            CargarFecha(&new.nacimiento);
            // Obtener la fecha actual del sistema
            time_t tiempoActual = time(NULL);
            struct tm *tmActual = localtime(&tiempoActual);

            // Asignar la fecha actual
            fechaActual.dia = tmActual->tm_mday;         // dia
            fechaActual.mes = tmActual->tm_mon + 1;      // mes
            fechaActual.anio = tmActual->tm_year + 1900; // año

            new.edad = CalcularEdad(new.nacimiento, fechaActual);
            printf("Edad: %d\n", new.edad);

            /*while (1)
            {
                if (scanf("%d", &new.edad) != 1 || new.edad <= 0 || new.edad > 120)
                {
                    printf("La edad no puede ser negativa o mayor a 120, ingrese nuevamente: ");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF)
                        ; // Limpia el buffer de entrada
                }
                else
                {
                    break; // Sale del bucle si la entrada es válida
                }
            }*/
            getchar();
            printf("Ciudad de residencia actual: ");
            fgets(new.ciudad, sizeof(new.ciudad), stdin);
            printf("Ciudad de residencia en el momento de la guerra: ");
            fgets(new.ciudadAntes, sizeof(new.ciudadAntes), stdin);
            printf("Direccion postal: ");
            fgets(new.DP, sizeof(new.DP), stdin);
            printf("Correo electronico: ");
            fgets(new.CE, sizeof(new.CE), stdin);
            printf("Telefono: ");
            fgets(new.tel, sizeof(new.tel), stdin);
            printf("Provincia de nacimiento: ");
            fgets(new.provincia, sizeof(new.provincia), stdin);
            printf("Si vive presione 1, si esta fallecido 0: ");
            scanf("%d", &new.VF);
            getchar();
            if (new.VF == 0)
            {
                printf("Fallecimiento: ");
                scanf("%d/%d/%d", &new.fallecimiento.dia, &new.fallecimiento.mes, &new.fallecimiento.anio);
            }
            printf("Ingrese a qué fuerza perteneció en Malvinas:\n 1: Marina\n 2: Gendarmería\n 3: Ejército\n 4: Aeronáutica\n ");

            while (1)
            {
                if (scanf("%d", &new.fuerza) == 1)
                {
                    // Se ingresó un número correctamente
                    if (new.fuerza >= 1 && new.fuerza <= 4)
                    {
                        getchar();
                        break;
                    }
                    else
                    {
                        printf("Por favor, ingrese un número válido entre 1 y 4.\n");
                    }
                }
                else
                {
                    // No se ingresó un número, limpiar el búfer de entrada y volver a intentar
                    printf("Por favor, ingrese un número válido entre 1 y 4.\n");
                    while (getchar() != '\n')
                        ; // Limpiar el búfer de entrada
                }
            }
            printf("Ingrese que destino tuvo en malvinas: ");
            fgets(new.destino, sizeof(new.destino), stdin);
            printf("Ingrese que funcion cumplio en malvinas: ");
            fgets(new.funcion, sizeof(new.funcion), stdin);
            printf("Ingrese que grado tuvo en malvinas: ");
            fgets(new.grado, sizeof(new.grado), stdin);
            printf("Ingrese que secuelas tuvo despues de malvinas: ");
            fgets(new.secuelas, sizeof(new.secuelas), stdin);

            printf("Datos ingresados correctamente. \n");

            Insertar(new, &persona);
        }
        else if (num == 2)
        {
            printf("Ingrese el DNI: ");
            scanf("%d", &doc);
            Suprimir(doc, &persona);
        }
        else if (num == 3)
        {
            printf("Ingrese el DNI: ");
            scanf("%d", &doc);
            Modificar(doc, &persona);
        }
        else if (num == 4)
        {
            ListarPorDNI(persona);
        }
        else if (num == 5)
        {
            ListarPorAPellido(persona);
        }
        else if (num == 6)
        {
            /*aux1 = (struct Telem *)malloc(sizeof(struct Telem));
            aux1->next = NULL;
            list = aux1;*/
            struct Telem *list = NULL;
            struct Telem *aux1 = NULL;
            InicializarLSE(&list, &aux1);
            Fallecidos(persona, &list);
        }
        else if (num == 7)
        {

            printf("Ingrese a qué fuerza de Malvinas quiere listar:\n 1: Marina\n 2: Gendarmería\n 3: Ejército\n 4: Aeronáutica\n ");
            while (1)
            {
                if (scanf("%d", &fuerzaBuscada) == 1)
                {
                    if (fuerzaBuscada >= 1 && fuerzaBuscada <= 4)
                    {
                        break;
                    }
                    else
                    {
                        printf("Por favor, ingrese un número válido entre 1 y 4.\n");
                    }
                }
                else
                {
                    // No se ingresó un número, limpiar el búfer de entrada y volver a intentar
                    printf("Por favor, ingrese un número válido entre 1 y 4.\n");
                    while (getchar() != '\n')
                        ; // Limpiar el búfer de entrada
                }
            }
            /*aux2 = (struct TDoblete *)malloc(sizeof(struct TDoblete));
            aux2->next = NULL;
            aux2->back = NULL;
            puntIni = aux2;
            puntFin = aux2;
            aux2 = (struct TDoblete *)malloc(sizeof(struct TDoblete));
            aux2->next = NULL;
            aux2->back = puntIni;
            puntIni->next = aux2;
            puntFin = aux2;*/
            struct TDoblete *puntIni = NULL;
            struct TDoblete *puntFin = NULL;
            struct TDoblete *aux2 = NULL;
            InicializarLDE(&puntIni, &puntFin, &aux2);
            FuerzaPertenenciente(persona, fuerzaBuscada, &puntIni, &puntFin);
            MostrarListaDoble(puntIni, puntFin);
        }
        else if (num == 8)
        {
            printf("Ingrese el numero del mes que quiera buscar: ");
            scanf("%d", &mesBuscado);
            CumpleañosDelMismoMes(persona, mesBuscado);
        }
        else if (num == 9)
        {

            printf("Ingrese el apellido que quiera buscar: ");
            fgets(apellidoBuscar, sizeof(apellidoBuscar), stdin);
            BusquedaApellido(persona, apellidoBuscar);
        }
        else if (num == 10)
        {
            GuardarEnArchivo(persona);
        }
    } while (num != 0);

    return 0;
}

// ARCHIVOS
void PasarDeArchivoAArray(TData *x)
{

    int i = 0;
    FILE *f;
    TPersona pers;

    f = fopen("malvinas.dat", "rb");
    if (f != NULL)
    {

        fread(&(x->cant), sizeof(int), 1, f);
        printf("CANT leída: %d\n", x->cant);

        while (fread(&pers, sizeof(TPersona), 1, f) == 1)
        {
            x->a[i + 1] = pers; // Comienza desde el índice 1
            printf("Read data for person %d\n", i);
            printf("Name: %s\n", x->a[i + 1].nombre);
            i++;
        }
        fclose(f);
    }
    else
    {
        printf("El archivo era inexistente, se creó para su primer uso\n");
        f = fopen("malvinas.dat", "ab");
        fclose(f);
        x->cant = 0;
    }
}
void GuardarEnArchivo(TData x)
{
    FILE *f;
    int i;

    f = fopen("malvinas.dat", "wb");
    if (f == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // Guarda la cantidad de elementos primero
    fwrite(&x.cant, sizeof(int), 1, f);

    // Luego guarda los elementos individuales
    for (i = 1; i < x.cant + 1; i++)
    {

        fwrite(&x.a[i], sizeof(TPersona), 1, f);
    }

    fclose(f);
    printf("Se guardó con éxito el archivo!\n");
}
// ARRAYS

void BusquedaApellido(TData q, char a[20])
{
    int i;
    bool hay;
    hay = false;
    printf("%s", a);
    for (i = 1; i <= q.cant; i++)
    {
        if (strcmp(a, q.a[i].apellido) == 0)
        {
            printf("\n------------------------------------------\n");
            printf("\n---------INFORMACION DE LA PERSONA---------\n");
            printf("Nombre: %s\n", q.a[i].nombre);
            printf("Apellido: %s\n", q.a[i].apellido);
            printf("DNI: %d\n", q.a[i].DNI);
            printf("Nacimiento: %d/%d/%d \n", q.a[i].nacimiento.dia, q.a[i].nacimiento.mes, q.a[i].nacimiento.anio);
            printf("Telefono: %s\n", q.a[i].tel);
            printf("Edad: %d\n", q.a[i].edad);
            printf("Ciudad de residencia actual: %s\n", q.a[i].ciudad);
            printf("Ciudad de residencia en el momento de la guerra: %s\n", q.a[i].ciudadAntes);
            printf("Dirección Postal: %s\n", q.a[i].DP);
            printf("Correo Electronico: %s\n", q.a[i].CE);
            printf("Provincia de nacimiento: %s\n", q.a[i].provincia);

            if (q.a[i].VF == 0)
            {
                printf("Vive: No\n");
                printf("Fecha de fallecimiento: %d/%d/%d \n", q.a[i].fallecimiento.dia, q.a[i].fallecimiento.mes, q.a[i].fallecimiento.anio);
            }
            else
            {
                printf("Vive: Si\n");
            }
            printf("\n---------INFORMACION DE MALVINAS---------\n");
            if (q.a[i].fuerza == 1)
            {
                printf("Fuerza que pertenecio: Marina\n");
            }
            else if (q.a[i].fuerza == 2)
            {
                printf("Fuerza que pertenecio: Gendarmeria\n");
            }
            else if (q.a[i].fuerza == 3)
            {
                printf("Fuerza que pertenecio: Ejercito\n");
            }
            else if (q.a[i].fuerza == 4)
            {
                printf("Fuerza que pertenecio: Aeronautica\n");
            }
            printf("Destino en malvinas: %s\n", q.a[i].destino);
            printf("Funcion en Malvinas: %s\n", q.a[i].funcion);
            printf("Grado: %s\n", q.a[i].grado);
            printf("Secuelas: %s\n", q.a[i].secuelas);
            printf("\n------------------------------------------\n");
            hay = true;
        }
    }
    if (hay == false)
    {
        printf("No hay personas con ese apellido.");
    }
}

void CumpleañosDelMismoMes(TData q, int mes)
{
    int i, j;
    TData h;
    h.cant = 0;
    for (i = 1; i <= q.cant; i++)
    {
        if (q.a[i].nacimiento.mes == mes)
        {
            h.cant++;
            h.a[h.cant] = q.a[i];
        }
    }
    Buble(&h, 1);
}
int Vacia(TData p)
{
    if (p.cant == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Llena(TData s)
{
    if (s.cant == 250)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Insertar(TPersona nuevo, TData *q)
{
    int i;
    if (Llena(*q) == 1)
    {
        printf("La lista esta llena, suprima un elemento.");
    }
    else
    {
        q->a[q->cant] = nuevo;
        printf("Nombre: %s\n", q->a[q->cant].nombre);
        Buble(q, 1);
    }
}
void Suprimir(int d, TData *q)
{
    int i, k, esta;
    if (Vacia(*q) == 1)
    {
        printf("La Lista esta vacia.");
    }
    else
    {
        esta = 0;
        for (i = 0; i <= q->cant; i++)
        {
            if (d == q->a[i].DNI)
            {
                for (k = i; k < q->cant; k++)
                {
                    q->a[k] = q->a[k + 1];
                }
                esta = 1;
                q->cant = q->cant - 1;
                printf("Persona eliminada con exito!");
            }
        }
        if (esta == 0)
        {
            printf("La persona con ese DNi no está en la lista.");
        }
    }
}

void Mostrar(TData q)
{
    int i;
    if (q.cant == 0)
    {
        printf("Lista Vacia!");
    }
    for (i = 1; i <= q.cant; i++)
    {
        printf("\n------------------------------------------\n");
        printf("\n---------INFORMACION DE LA PERSONA---------\n");
        printf("Nombre: %s\n", q.a[i].nombre);
        printf("Apellido: %s\n", q.a[i].apellido);
        printf("DNI: %d\n", q.a[i].DNI);
        printf("Nacimiento: %d/%d/%d \n", q.a[i].nacimiento.dia, q.a[i].nacimiento.mes, q.a[i].nacimiento.anio);
        printf("Telefono: %s\n", q.a[i].tel);
        printf("Edad: %d\n", q.a[i].edad);
        printf("Ciudad de residencia actual: %s\n", q.a[i].ciudad);
        printf("Ciudad de residencia en el momento de la guerra: %s\n", q.a[i].ciudadAntes);
        printf("Dirección Postal: %s\n", q.a[i].DP);
        printf("Correo Electronico: %s\n", q.a[i].CE);
        printf("Provincia de nacimiento: %s\n", q.a[i].provincia);
        if (q.a[i].VF == 0)
        {
            printf("Vive: No\n");
            printf("Fecha de fallecimiento: %d/%d/%d \n", q.a[i].fallecimiento.dia, q.a[i].fallecimiento.mes, q.a[i].fallecimiento.anio);
        }
        else
        {
            printf("Vive: Si\n");
        }
        printf("\n---------INFORMACION DE MALVINAS---------\n");
        if (q.a[i].fuerza == 1)
        {
            printf("Fuerza que pertenecio: Marina\n");
        }
        else if (q.a[i].fuerza == 2)
        {
            printf("Fuerza que pertenecio: Gendarmeria\n");
        }
        else if (q.a[i].fuerza == 3)
        {
            printf("Fuerza que pertenecio: Ejercito\n");
        }
        else if (q.a[i].fuerza == 4)
        {
            printf("Fuerza que pertenecio: Aeronautica\n");
        }
        printf("Funcion en Malvinas: %s\n", q.a[i].funcion);
        printf("Destino en Malvinas: %s\n", q.a[i].destino);
        printf("Grado: %s\n", q.a[i].grado);
        printf("Secuelas: %s\n", q.a[i].secuelas);

        printf("\n------------------------------------------\n");
    }
}

void Modificar(int d, TData *q)
{
    int DNI;
    char nombre[20];
    char apellido[20];
    Tfecha nacimiento; // Campo de tipo Tfecha para la fecha de nacimiento
    int edad;
    char ciudad[20];      // Ciudad de residencia actual
    char ciudadAntes[20]; // Ciudad de residencia en el momento de la guerra
    char DP[30];          // Dirección Postal
    char CE[20];          // Correo Electrónico
    char tel[15];         // Teléfono
    int VF;               // Vive/falleció: Verdadero si está vivo, Falso si ha fallecido
    Tfecha fallecimiento; // Campo de tipo Tfecha para la fecha de fallecimiento
    char beneficio[20];   // Número beneficio nacional
    char CP[10];          // Código postal
    char provincia[50];   // Provincia de nacimiento
    int fuerza;           // Fuerza a la que perteneció: 1-Marina, 2-Gendarmeria, 3-Ejército, 4-Aeronáutica
    char destino[50];     // Destino en Malvinas
    char funcion[100];    // Función en Malvinas
    char grado[20];       // Grado
    char secuelas[200];
    int i, selec, esta, n;
    Tfecha fechaActual;

    if (Vacia(*q) == 1)
    {
        printf("La lista está vacía.");
    }
    else
    {
        esta = 0;

        for (i = 1; i <= q->cant; i++)
        {
            if (d == q->a[i].DNI)
            {
                printf("Persona encontrada!");
                printf("DNI: %d\n", q->a[i].DNI);
                printf("\n------------------------------------------\n");
                printf("\n---------INFORMACION DE LA PERSONA---------\n");
                printf("Nombre: %s\n", q->a[i].nombre);
                printf("Apellido: %s\n", q->a[i].apellido);
                printf("Nacimiento: %d/%d/%d \n", q->a[i].nacimiento.dia, q->a[i].nacimiento.mes, q->a[i].nacimiento.anio);
                printf("Telefono: %s\n", q->a[i].tel);
                printf("Edad: %d\n", q->a[i].edad);
                printf("Ciudad de residencia actual: %s\n", q->a[i].ciudad);
                printf("Ciudad de residencia en el momento de la guerra: %s\n", q->a[i].ciudadAntes);
                printf("Dirección Postal: %s\n", q->a[i].DP);
                printf("Correo Electronico: %s\n", q->a[i].CE);
                printf("Provincia de nacimiento: %s\n", q->a[i].provincia);
                if (q->a[i].VF == 0)
                {
                    printf("Vive: No\n");
                    printf("Fecha de fallecimiento: %d/%d/%d \n", q->a[i].fallecimiento.dia, q->a[i].fallecimiento.mes, q->a[i].fallecimiento.anio);
                }
                else
                {
                    printf("Vive: Si\n");
                }
                printf("\n---------INFORMACION DE MALVINAS---------\n");
                if (q->a[i].fuerza == 1)
                {
                    printf("Fuerza que pertenecio: Marina\n");
                }
                else if (q->a[i].fuerza == 2)
                {
                    printf("Fuerza que pertenecio: Gendarmeria\n");
                }
                else if (q->a[i].fuerza == 3)
                {
                    printf("Fuerza que pertenecio: Ejercito\n");
                }
                else if (q->a[i].fuerza == 4)
                {
                    printf("Fuerza que pertenecio: Aeronautica\n");
                }
                printf("Funcion en Malvinas: %s\n", q->a[i].funcion);
                printf("Destino en Malvinas: %s\n", q->a[i].destino);
                printf("Grado: %s\n", q->a[i].grado);
                printf("Secuelas: %s\n", q->a[i].secuelas);

                printf("\n------------------------------------------\n");
                do
                {
                    printf("\n1: Modifar campos de la persona\n2: Modicar campos de malvinas\n3: Salir\n");
                    scanf("%d", &selec);
                    if (selec == 3)
                    {
                        return;
                    }
                    if (selec == 1)

                    {
                        printf("Que dato quiere modificar?\n");
                        printf("1: Nombre\n2: Apellido\n3: Fecha Nacimiento\n4: Ciudad de residencia actual\n5: Ciudad de residencia en el momento de la guerra\n6: Direccion Postal\n7: Correo Electronico\n8: Telefono\n9: Provincia de nacimiento\n10: Vive o No?\n11: Fecha de Fallecimiento\n0: Salir. \n");
                        printf("\nIngrese su opcion: [ ]\b\b");
                        scanf("%d", &n);

                        switch (n)
                        {
                        case 1:
                            printf("Ingrese el nombre: ");
                            scanf("%s", nombre);
                            strcpy(q->a[i].nombre, nombre);
                            break;
                        case 2:
                            printf("Ingrese el apellido: ");
                            scanf("%s", apellido);
                            strcpy(q->a[i].apellido, apellido);
                            break;
                        case 3:
                            printf("Ingrese el Dia(DD): ");
                            scanf("%d", &nacimiento.dia);
                            q->a[i].nacimiento.dia = nacimiento.dia;
                            printf("Ingrese el mes(MM): ");
                            scanf("%d", &nacimiento.mes);
                            q->a[i].nacimiento.mes = nacimiento.mes;
                            printf("Ingrese el año(AAAA): ");
                            scanf("%d", &nacimiento.anio);
                            q->a[i].nacimiento.anio = nacimiento.anio;
                            // Obtener la fecha actual del sistema
                            time_t tiempoActual = time(NULL);
                            struct tm *tmActual = localtime(&tiempoActual);

                            // Asignar la fecha actual
                            fechaActual.dia = tmActual->tm_mday;         // dia
                            fechaActual.mes = tmActual->tm_mon + 1;      // mes
                            fechaActual.anio = tmActual->tm_year + 1900; // año

                            q->a[i].edad = CalcularEdad(q->a[i].nacimiento, fechaActual);
                            printf("Edad: %d\n", q->a[i].edad);
                            break;
                        case 4:
                            printf("Ingrese la ciudad de residencia actual: ");
                            scanf("%s", ciudad);
                            strcpy(q->a[i].ciudad, ciudad);
                            break;
                        case 5:
                            printf("Ingrese la la ciudad de residencia en el momento de la guerra: ");
                            scanf("%s", ciudadAntes);
                            strcpy(q->a[i].ciudadAntes, ciudadAntes);
                            break;
                        case 6:
                            printf("Ingrese la dirección postal: ");
                            scanf("%s", DP);
                            strcpy(q->a[i].DP, DP);
                            break;
                        case 7:
                            printf("Ingrese el correo electronico: ");
                            scanf("%s", CE);
                            strcpy(q->a[i].CE, CE);
                            break;
                        case 8:
                            printf("Ingrese el telefono: ");
                            scanf("%s", tel);
                            strcpy(q->a[i].tel, tel);
                            break;
                        case 9:
                            printf("Ingrese la provincia de nacimiento: ");
                            scanf("%s", provincia);
                            strcpy(q->a[i].provincia, provincia);
                            break;
                        case 10:
                            printf("Si es fallecido precione 0, sino 1: ");
                            scanf("%d", &VF);
                            q->a[i].VF = VF;
                            break;
                        case 11:
                            printf("Ingrese el Dia: ");
                            scanf("%d", &fallecimiento.dia);
                            q->a[i].fallecimiento.dia = fallecimiento.dia;
                            printf("Ingrese el mes: ");
                            scanf("%d", &fallecimiento.mes);
                            q->a[i].fallecimiento.mes = fallecimiento.mes;
                            printf("Ingrese el año: ");
                            scanf("%d", &fallecimiento.anio);
                            q->a[i].fallecimiento.anio = fallecimiento.anio;
                            break;
                        case 0:

                            break;
                        default:
                            printf("Opción no válida. Intente de nuevo.\n");
                        }
                    }
                    else
                    {
                        printf("Que dato quiere modificar?\n");
                        printf("1: Fuerza que pertenecio\n2: Destino en Malvinas\n3: Funcion en Malvinas\n4: Grado\n5: Secuelas\n0: Salir. \n");
                        printf("\nIngrese su opcion: [ ]\b\b");
                        scanf("%d", &n);
                        switch (n)
                        {
                        case 1:
                            printf("Ingrese a qué fuerza perteneció en Malvinas:\n 1: Marina\n 2: Gendarmería\n 3: Ejército\n 4: Aeronáutica\n ");

                            while (1)
                            {
                                if (scanf("%d", &new.fuerza) == 1)
                                {
                                    // Se ingresó un número correctamente
                                    if (new.fuerza >= 1 && new.fuerza <= 4)
                                    {
                                        // Número válido, salir del bucle
                                        break;
                                    }
                                    else
                                    {
                                        printf("Por favor, ingrese un número válido entre 1 y 4.\n");
                                    }
                                }
                                else
                                {
                                    // No se ingresó un número, limpiar el búfer de entrada y volver a intentar
                                    printf("Por favor, ingrese un número válido entre 1 y 4.\n");
                                    while (getchar() != '\n')
                                        ; // Limpiar el búfer de entrada
                                }
                            }
                            break;
                        case 2:
                            printf("Ingrese el destino en Malvinas: ");
                            scanf("%s", destino);
                            strcpy(q->a[i].destino, destino);
                            break;
                        case 3:
                            printf("Ingrese la funcion en Malvinas: ");
                            scanf("%s", funcion);
                            strcpy(q->a[i].funcion, funcion);
                            break;
                        case 4:

                            printf("Ingrese el grado: ");
                            scanf("%s", grado);
                            strcpy(q->a[i].grado, grado);
                            break;
                        case 5:
                            printf("Ingrese las secuelas: ");
                            scanf("%s", secuelas);
                            strcpy(q->a[i].secuelas, secuelas);
                            break;

                        case 0:
                            // Salir del bucle
                            break;

                        default:
                            break;
                        }
                    }
                } while (n != 0);
                Buble(q, 1);
                esta = 1;
            }
        }

        if (esta == 0)
        {
            printf("La persona con ese DNI no está en la lista.\n");
        }
    }
}
void ListarPorAPellido(TData x)
{
    int i;
    TData aux;
    aux.cant = 0;
    if (x.cant == 0)
    {
        printf("Lista vacia.\n");
    }
    for (i = 1; i <= x.cant; i++)
    {
        aux.cant++;
        aux.a[aux.cant] = x.a[i];
    }

    Buble(&aux, 2);
}
void ListarPorDNI(TData x)
{
    int i;
    TData aux;
    aux.cant = x.cant;
    printf("Cantidad en de personas en lista: %d\n", x.cant);
    for (i = 1; i <= x.cant + 1; i++)
    {
        aux.a[i] = x.a[i];
    }

    Buble(&aux, 1);
}

// LISTAS
void InicializarLSE(struct Telem **punts, struct Telem **aux)
{
    *aux = (struct Telem *)malloc(sizeof(struct Telem));
    (*aux)->next = NULL;
    *punts = *aux;
}
void InicializarLDE(struct TDoblete **ini, struct TDoblete **fin, struct TDoblete **aux)
{
    *aux = (struct TDoblete *)malloc(sizeof(struct TDoblete));
    (*aux)->next = NULL;
    (*aux)->back = NULL;
    *ini = *aux;
    *fin = *aux;

    *aux = (struct TDoblete *)malloc(sizeof(struct TDoblete));
    (*aux)->next = NULL;
    (*aux)->back = *ini;
    (*ini)->next = *aux;
    *fin = *aux;
}

void Locales(TData q, char loc[20], struct TDoblete *ini, struct TDoblete *fin)
{
    struct TDoblete *aux, *n, *t;
    int i, k, menor;
    k = 0;
    for (i = 1; i <= q.cant; i++)
    {
        if (q.a[i].ciudad == loc)
        {
            aux = (struct TDoblete *)malloc(sizeof(struct TDoblete));
            aux->info = q.a[i];
            aux->back = ini;
            aux->next = ini->next;
            aux->next->back = aux;
            aux->back->next = aux;
            k++;
        }
    }
    i = 1;
    aux = ini->next;
    while ((i <= k) && (aux->next != NULL))
    {
        n = aux;
        t = n->next;
        while (t->next != NULL)
        {
            if (t->info.DNI < n->info.DNI)
            {
                n = t;
            }
            t = t->next;
        }
        menor = n->info.DNI;
        n->info.DNI = aux->info.DNI;
        aux->info.DNI = menor;
        aux = aux->next;
        k++;
    }
}

void FuerzaPertenenciente(TData q, int fuerza, struct TDoblete **ini, struct TDoblete **fin)
{
    struct TDoblete *aux, *n, *t;
    int i, k, menor;

    k = 0;

    for (i = 0; i < q.cant; i++)
    {
        if (q.a[i].fuerza == fuerza)
        {
            aux = (struct TDoblete *)malloc(sizeof(struct TDoblete));
            aux->info = q.a[i];
            aux->back = *ini;
            aux->next = (*ini)->next;
            aux->next->back = aux;
            aux->back->next = aux;
            printf("Data del nodo: %s\n", aux->info.nombre);
            k++;
        }
    }

    aux = (*ini)->next;
    while (i <= k && aux->next != NULL)
    {
        n = aux;
        t = n->next;
        while (t->next != NULL)
        {
            if (t->info.DNI < n->info.DNI)
            {
                n = t;
            }
            t = t->next;
        }
        menor = n->info.DNI;
        n->info.DNI = aux->info.DNI;
        aux->info.DNI = menor;
        aux = aux->next;
        i++;
    }

    // Free the unused aux variable
    free(aux);
}
void MostrarListaDoble(struct TDoblete *ini, struct TDoblete *fin)
{
    struct TDoblete *aux;
    int n;

    printf("Que modo desea ver la lista?\n1:Modo ascendente\n2:Modo descendente\n");
    scanf("%d", &n);
    getchar();
    if (n == 1)
    {
        aux = ini->next;
        while (aux->next != NULL)
        {
            printf("\n------------------------------------------\n");
            printf("\n---------INFORMACION DE LA PERSONA--------\n");
            printf("Nombre: %s\n", aux->info.nombre);
            printf("Apellido: %s\n", aux->info.apellido);
            printf("DNI: %d\n", aux->info.DNI);
            printf("Nacimiento: %d/%d/%d \n", aux->info.nacimiento.dia, aux->info.nacimiento.mes, aux->info.nacimiento.anio);
            printf("Telefono: %s\n", aux->info.tel);
            printf("Edad: %d\n", aux->info.edad);
            printf("Ciudad de residencia actual: %s\n", aux->info.ciudad);
            printf("Ciudad de residencia en el momento de la guerra: %s\n", aux->info.ciudadAntes);
            printf("Dirección Postal: %s\n", aux->info.DP);
            printf("Correo Electronico: %s\n", aux->info.CE);
            printf("Provincia de nacimiento: %s\n", aux->info.provincia);
            if (aux->info.VF == 0)
            {
                printf("Vive: No\n");
                printf("Fecha de fallecimiento: %d/%d/%d \n", aux->info.fallecimiento.dia, aux->info.fallecimiento.mes, aux->info.fallecimiento.anio);
            }
            else
            {
                printf("Vive: Si\n");
            }
            printf("\n---------INFORMACION DE MALVINAS---------\n");
            if (aux->info.fuerza == 1)
            {
                printf("Fuerza que pertenecio: Marina\n");
            }
            else if (aux->info.fuerza == 2)
            {
                printf("Fuerza que pertenecio: Gendarmeria\n");
            }
            else if (aux->info.fuerza == 3)
            {
                printf("Fuerza que pertenecio: Ejercito\n");
            }
            else if (aux->info.fuerza == 4)
            {
                printf("Fuerza que pertenecio: Aeronautica\n");
            }
            printf("Destino en malvinas: %s\n", aux->info.destino);
            printf("Funcion en Malvinas: %s\n", aux->info.funcion);
            printf("Grado: %s\n", aux->info.grado);
            printf("Secuelas: %s\n", aux->info.secuelas);
            printf("\n------------------------------------------\n");
            aux = aux->next;
        }
    }
    else
    {
        printf("No entras 2");
        aux = fin->back;
        while (aux->back != NULL)
        {
            printf("\n------------------------------------------\n");
            printf("\n---------INFORMACION DE LA PERSONA---------\n");
            printf("Nombre: %s\n", aux->info.nombre);
            printf("Apellido: %s\n", aux->info.apellido);
            printf("DNI: %d\n", aux->info.DNI);
            printf("Nacimiento: %d/%d/%d \n", aux->info.nacimiento.dia, aux->info.nacimiento.mes, aux->info.nacimiento.anio);
            printf("Telefono: %s\n", aux->info.tel);
            printf("Edad: %d\n", aux->info.edad);
            printf("Ciudad de residencia actual: %s\n", aux->info.ciudad);
            printf("Ciudad de residencia en el momento de la guerra: %s\n", aux->info.ciudadAntes);
            printf("Dirección Postal: %s\n", aux->info.DP);
            printf("Correo Electronico: %s\n", aux->info.CE);
            printf("Provincia de nacimiento: %s\n", aux->info.provincia);
            if (aux->info.VF == 0)
            {
                printf("Vive: No\n");
                printf("Fecha de fallecimiento: %d/%d/%d \n", aux->info.fallecimiento.dia, aux->info.fallecimiento.mes, aux->info.fallecimiento.anio);
            }
            else
            {
                printf("Vive: Si\n");
            }
            printf("\n---------INFORMACION DE MALVINAS---------\n");
            if (aux->info.fuerza == 1)
            {
                printf("Fuerza que pertenecio: Marina\n");
            }
            else if (aux->info.fuerza == 2)
            {
                printf("Fuerza que pertenecio: Gendarmeria\n");
            }
            else if (aux->info.fuerza == 3)
            {
                printf("Fuerza que pertenecio: Ejercito\n");
            }
            else if (aux->info.fuerza == 4)
            {
                printf("Fuerza que pertenecio: Aeronautica\n");
            }
            printf("Destino en malvinas: %s\n", aux->info.destino);
            printf("Funcion en Malvinas: %s\n", aux->info.funcion);
            printf("Grado: %s\n", aux->info.grado);
            printf("Secuelas: %s\n", aux->info.secuelas);
            printf("\n------------------------------------------\n");
            aux = aux->back;
        }
    }
}

void Fallecidos(TData q, struct Telem **lis)
{
    struct Telem *aux;
    int i;

    for (i = 1; i <= q.cant; i++)
    {
        if (q.a[i].VF == 0)
        {
            aux = (struct Telem *)malloc(sizeof(struct Telem));
            aux->info = q.a[i];
            aux->next = (*lis)->next;
            (*lis)->next = aux;
        }
    }

    aux = (*lis)->next;
    int id = 1;
    while (aux != NULL)
    {
        printf("\n------------------------------------------\n");
        printf("\n---------INFORMACION DE LA PERSONA---------\n");
        printf("Nombre: %s \n", aux->info.nombre);
        printf("Apellido: %s \n", aux->info.apellido);
        printf("Nacimiento: %d/%d/%d \n", aux->info.nacimiento.dia, aux->info.nacimiento.mes, aux->info.nacimiento.anio);
        printf("Edad: %d \n", aux->info.edad);
        printf("DNI: %d \n", aux->info.DNI);
        printf("Ciudad de residencia actual: %s \n", aux->info.ciudad);
        printf("Ciudad de residencia en el momento de la guerra: %s \n", aux->info.ciudadAntes);
        printf("Direccion postal: %s \n", aux->info.DP);
        printf("Correo Electronico: %s \n", aux->info.CE);
        printf("Provincia de nacimiento: %s \n", aux->info.provincia);
        if (aux->info.VF == 0)
        {
            printf("Vive: No\n");
            printf("Fecha de fallecimiento: %d/%d/%d \n", aux->info.fallecimiento.dia, aux->info.fallecimiento.mes, aux->info.fallecimiento.anio);
        }
        else
        {
            printf("Vive: Si\n");
        }
        printf("\n---------INFORMACION DE MALVINAS---------\n");
        if (aux->info.fuerza == 1)
        {
            printf("Fuerza que pertenecio: Marina\n");
        }
        else if (aux->info.fuerza == 2)
        {
            printf("Fuerza que pertenecio: Gendarmeria\n");
        }
        else if (aux->info.fuerza == 3)
        {
            printf("Fuerza que pertenecio: Ejercito\n");
        }
        else if (aux->info.fuerza == 4)
        {
            printf("Fuerza que pertenecio: Aeronautica\n");
        }
        printf("Destino en malvinas: %s\n", aux->info.destino);
        printf("Funcion en Malvinas: %s\n", aux->info.funcion);
        printf("Grado: %s\n", aux->info.grado);
        printf("Secuelas: %s\n", aux->info.secuelas);
        printf("\n------------------------------------------\n");

        aux = aux->next;
    }
}

// UTILS
void Intercambiar(TPersona *x, TPersona *y)
{

    TPersona aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void Buble(TData *x, int opc)
{
    int i, j;

    switch (opc)
    {
    case 1:
        for (i = 0; i < x->cant; i++)
        {
            for (j = 0; j < x->cant; j++)
            {
                if (x->a[j].DNI > x->a[j + 1].DNI)
                {
                    Intercambiar(&x->a[j], &x->a[j + 1]);
                }
            }
        }

        printf("Lista ordenada por DNI: \n");
        for (i = 1; i <= x->cant; i++)
        {
            printf("\n--------------------------------------\n");
            printf("\n------Informacion de la persona------\n");
            printf("DNI: %d\n", x->a[i].DNI);
            printf("Nombre: %s\n", x->a[i].nombre);
            printf("Apellido: %s\n", x->a[i].apellido);
            printf("Nacimiento: %d/%d/%d \n", x->a[i].nacimiento.dia, x->a[i].nacimiento.mes, x->a[i].nacimiento.anio);
            printf("Telefono: %s\n", x->a[i].tel);
            printf("Edad: %d\n", x->a[i].edad);
            printf("Ciudad de residencia actual: %s\n", x->a[i].ciudad);
            printf("Ciudad de residencia en el momento de la guerra: %s\n", x->a[i].ciudadAntes);
            printf("Dirección Postal: %s\n", x->a[i].DP);
            printf("Correo Electronico: %s\n", x->a[i].CE);
            printf("Provincia de nacimiento: %s\n", x->a[i].provincia);
            if (x->a[i].VF == 0)
            {
                printf("Vive: No\n");
                printf("Fecha de fallecimiento: %d/%d/%d \n", x->a[i].fallecimiento.dia, x->a[i].fallecimiento.mes, x->a[i].fallecimiento.anio);
            }
            else
            {
                printf("Vive: Si\n");
            }
            printf("\n---------INFORMACION DE MALVINAS---------\n");
            if (x->a[i].fuerza == 1)
            {
                printf("Fuerza que pertenecio: Marina\n");
            }
            else if (x->a[i].fuerza == 2)
            {
                printf("Fuerza que pertenecio: Gendarmeria\n");
            }
            else if (x->a[i].fuerza == 3)
            {
                printf("Fuerza que pertenecio: Ejercito\n");
            }
            else if (x->a[i].fuerza == 4)
            {
                printf("Fuerza que pertenecio: Aeronautica\n");
            }
            printf("Destino en malvinas: %s\n", x->a[i].destino);
            printf("Funcion en Malvinas: %s\n", x->a[i].funcion);
            printf("Grado: %s\n", x->a[i].grado);
            printf("Secuelas: %s\n", x->a[i].secuelas);
            printf("\n------------------------------------------\n");
        }

        break;
    case 2:
        for (i = 0; i < x->cant; i++)
        {
            for (j = 0; j < x->cant - 1; j++)
            {
                if (strcmp(x->a[j].apellido, x->a[j + 1].apellido) > 0)
                {
                    Intercambiar(&x->a[j], &x->a[j + 1]);
                }
            }
        }

        // Mostrar la lista ordenada por apellido
        printf("Lista ordenada por apellido: \n");
        for (i = 0; i < x->cant; i++)
        {
            printf("--------------------------------------\n");
            printf("\n------Informacion de la persona------\n");
            printf("DNI: %d\n", x->a[i].DNI);
            printf("Nombre: %s\n", x->a[i].nombre);
            printf("Apellido: %s\n", x->a[i].apellido);
            printf("Nacimiento: %d/%d/%d \n", x->a[i].nacimiento.dia, x->a[i].nacimiento.mes, x->a[i].nacimiento.anio);
            printf("Telefono: %s\n", x->a[i].tel);
            printf("Edad: %d\n", x->a[i].edad);
            printf("Ciudad de residencia actual: %s\n", x->a[i].ciudad);
            printf("Ciudad de residencia en el momento de la guerra: %s\n", x->a[i].ciudadAntes);
            printf("Dirección Postal: %s\n", x->a[i].DP);
            printf("Correo Electronico: %s\n", x->a[i].CE);
            printf("Provincia de nacimiento: %s\n", x->a[i].provincia);
            if (x->a[i].VF == 0)
            {
                printf("Vive: No\n");
                printf("Fecha de fallecimiento: %d/%d/%d \n", x->a[i].fallecimiento.dia, x->a[i].fallecimiento.mes, x->a[i].fallecimiento.anio);
            }
            else
            {
                printf("Vive: Si\n");
            }
            printf("\n---------INFORMACION DE MALVINAS---------\n");
            if (x->a[i].fuerza == 1)
            {
                printf("Fuerza que pertenecio: Marina\n");
            }
            else if (x->a[i].fuerza == 2)
            {
                printf("Fuerza que pertenecio: Gendarmeria\n");
            }
            else if (x->a[i].fuerza == 3)
            {
                printf("Fuerza que pertenecio: Ejercito\n");
            }
            else if (x->a[i].fuerza == 4)
            {
                printf("Fuerza que pertenecio: Aeronautica\n");
            }
            printf("Destino en malvinas: %s\n", x->a[i].destino);
            printf("Funcion en Malvinas: %s\n", x->a[i].funcion);
            printf("Grado: %s\n", x->a[i].grado);
            printf("Secuelas: %s\n", x->a[i].secuelas);
            printf("\n------------------------------------------\n");
        }
        break;
    default:
        // Opción no válida
        break;
    }
}
void CargarFecha(Tfecha *fecha)
{
    int logico;

    printf("\nIngresar el año(AAAA): \n");
    do
    {
        scanf("%d", &fecha->anio);
        if ((fecha->anio < 0) || (fecha->anio > 1982))
        {
            printf("El valor ingresado no es correcto\n");
        }
        // Se controla que el año sea mayor a 0 y sea igual a añoArch//
        // En caso que el archivo se encuentre vacio, añoArch = 1//
    } while ((fecha->anio < 0) || ((fecha->anio > 1982)));

    printf("\nIngresar el mes(MM): \n");
    do
    {
        scanf("%d", &fecha->mes);
        if ((fecha->mes < 1) || (fecha->mes > 12))
        {
            printf("El valor ingresado no es correcto\n");
        }
    } while ((fecha->mes < 1) || (fecha->mes > 12));

    printf("\nIngresar el dia(DD): \n");
    do
    {
        scanf("%d", &fecha->dia);
        if ((fecha->dia < 1) && (fecha->dia > 31))
        {
            logico = 0;
            printf("El valor ingresado no es correcto\n");
        }
        else
        {
            // La condicion debajo confirma si el año es o no bisiesto, si no lo es y el dia ingresado es 2 y el mes ingresado es febrero, le asigna a logico falso//
            if (((fecha->dia == 29) && (fecha->mes == 2)) && !((fecha->anio % 4 == 0) && (!(fecha->anio % 100 == 0) || (fecha->anio % 400 == 0))))
            {
                logico = 0;
                printf("El valor ingresado no es correcto\n");
            }
            else
            {
                if ((fecha->dia > 29) && (fecha->mes == 2))
                {
                    logico = 0;
                    printf("El valor ingresado no es correcto\n");
                }
                else
                {
                    if ((fecha->dia > 30) && ((fecha->mes == 1) || (fecha->mes == 6) || (fecha->mes == 9) || (fecha->mes == 11)))
                    {
                        logico = 0;
                        printf("El valor ingresado no es correcto\n");
                    }
                    else
                    {
                        if (fecha->dia > 31)
                        {
                            logico = 0;
                            printf("El valor ingresado no es correcto\n");
                        }
                        else
                        {
                            logico = 1;
                        }
                    }
                }
            }
        }

    } while (logico == 0);
}
int CalcularEdad(Tfecha fechaNacimiento, Tfecha fechaActual)
{
    int edad;
    edad = fechaActual.anio - fechaNacimiento.anio;
    if (fechaActual.mes < fechaNacimiento.mes || (fechaActual.mes == fechaNacimiento.mes && fechaActual.dia < fechaNacimiento.dia))
    {
        edad--;
    }

    return edad;
}