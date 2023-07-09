#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "juego.h"
#include "windows.h"


void menu(int Matriz_invisible[][Dimension_Matriz], int Matriz_visible[][Dimension_Matriz], char facil[], char normal[], char dificil[], char archivoUsuario[],Ranking ran[Dimension_Nombre]) /// FUNCION DE MENU DESTINADO AL USUARIO, AQUÍ SE ENCUENTRAN TODAS LAS FUNCIONALIDADES DEL PROGRAMA (JUEGO, INFO, PUNTUACIONES, SALIR).
{

    int opcion = 0;
    int dificultad = 0;
    char continuar;
    int pos = 0;

    Usuario x;
    Espacio Tablero;
    Ranking nuevo;

    char opc;
    CLEAR();
		printf("\n\t   ____       _   _    ____       ____      _      __   __              _   _       _      ____  ");
		printf("\n\tU | __\") u U |\"|u| |  / __\"| u U /\"___| U  /\"\\  u U|' \\/ '|u   ___     | \\ |\"|  U  /\"\\  u / __\"| u ");
		printf("\n\t \\|  _ \\ /  \\| |\\| |  \\___ \\/  \\| | u    \\/ _ \\/  \\| |\\/| |/  |_\"_|   <|  \\| |>  \\/ _ \\/ <\\___ \\/ ");
		printf("\n\t  | |_) |    | |_| |  u___) |   | |/__   / ___ \\   | |  | |    | |    U| |\\  |u  / ___ \\  u___) | ");
		printf("\n\t  |____/    <<\\___/   |____/>>   \\____| /_/   \\_\\  |_|  |_|  U/| |\\u   |_| \\_|  /_/   \\_\\ |____/>>  ");
		printf("\n\t _|| \\\\_   (__) )(     )(  (__) _// \\\\   \\\\    >> <<,-,,-..-,_|___|_,-.||   \\\\,-.\\\\    >>  )(  (__) ");
		printf("\n\t(__) (__)      (__)   (__)    (__) (__) (__)  (__) (./  \\.)\\_)-' '-(_/ (_\")  (_/(__)  (__)(__)    ");

    gotoxy(40, 20);
    printf("Presione cualquier tecla\n");
    getch();

    CLEAR();

    cargarUsuario(&x);

    opciones:

    do
    {

        getch();
        CLEAR();

    opcion = opcionesMenuUsuario();



    switch(opcion)
    {

    case 1:

        dificultades: ///Etiqueta.
        gotoxy(35,6);

        printf("SE ENCUENTRAN DISPONIBLES 3 DIFICULTADES\n\n");

        gotoxy(35,8);
        printf("1.FACIL\n");
        gotoxy(35,9);
        printf("2.NORMAL\n");
        gotoxy(35,10);
        printf("3.DIFICIL\n");
        gotoxy(35,11);
        printf("4. VOLVER AL MENU\n");

        gotoxy(35,14);
        printf("INGRESE NIVEL DESEADO: ");
        scanf("%i", &dificultad);

        if(dificultad == 1)
        {

            FILE *archi = fopen(facil, "ab");

            if(archi != NULL)
            {

                nuevo.puntos = funcion_juego(nuevo, Tablero, 1, Matriz_invisible, Matriz_visible, facil, normal,dificil);

                strcpy(nuevo.nombre, x.nombre);
                nuevo.ID_Usuario = x.ID;

                fwrite(&nuevo, sizeof(Ranking), 1, archi);

                fclose(archi);

            }

            getch();
            CLEAR();


        }
        else if(dificultad == 2)
        {

            FILE *archi = fopen(normal, "ab");

            if(archi != NULL)
            {

                nuevo.puntos = funcion_juego(nuevo, Tablero, 2, Matriz_invisible, Matriz_visible, facil, normal,dificil);

                strcpy(nuevo.nombre, x.nombre);
                nuevo.ID_Usuario = x.ID;

                fwrite(&nuevo, sizeof(Ranking), 1, archi);

                fclose(archi);

            }

            getch();
            CLEAR();

        }
        else if(dificultad == 3)
        {

            FILE *archi = fopen(dificil, "ab");

            if(archi != NULL)
            {

                nuevo.puntos = funcion_juego(nuevo, Tablero, 3, Matriz_invisible, Matriz_visible, facil, normal,dificil);

                strcpy(nuevo.nombre, x.nombre);
                nuevo.ID_Usuario = x.ID;

                fwrite(&nuevo, sizeof(Ranking), 1, archi);

                fclose(archi);

            }

            getch();
            CLEAR();


        }
        else if(dificultad == 4)
        {


            CLEAR();
            goto opciones;
        }

        else
        {

            CLEAR();
            gotoxy(40,13);
            printf("LA OPCION SELECCIONADA NO EXISTE\n");
            gotoxy(40,14);
            printf("Presione una tecla para continuar.");
            getch();
            CLEAR();
            goto dificultades; ///Vuelve a leer el código desde la etiqueta "dificultades" (LINEA 46).

        }
        break;

    case 2:

        puntuaciones(ran);

        break;

    case 3: /// Texto que indica el modo de uso del juego

        gotoxy(40, 1);
        printf("\t MANUAL DE USUARIO \t\n");

        puts("Tu objetivo es indicar la coordenada correpondiente a la fila y la columna del tablero y que la misma no contenga una mina.\n");
        puts ("Si la coordenada indicada contiene una mina se termina la partida y se revela el tablero que contiene todos los valores.\n");
        puts("Si se indica una coordenada que no contiene una mina, se revela una zona con números, que indican cuántas minas hay con respecto a cada hueco revelado.");
        puts("Si alrededor de una casilla ves un 1, significa que uno de los cuadros adyacentes es una mina.Si aparece un 2, está tocando dos minas en su radio.");

        getch();
        CLEAR();
        break;

    case 4:

        break;

    default:

        gotoxy(40,13);
        printf("LA OPCION SELECCIONADA NO EXISTE\n");
        gotoxy(40,14);
        printf("Presione una tecla para continuar.");
        getch();
        CLEAR();

        break;


    }

    }while(opcion != 4);

}

void cargarUsuario(Usuario* x) /// FUNCION PARA CARGAR LA ESTRUCTURA USUARIO Y GUARDARLA EN UN ARCHIVO.
{

    char nombreNuevo[Dimension_Nombre];
    int IDENTIFICADOR = 0;
    int IDNUEVO = 0;
    int validarDato = 0;
    int flag = 0;


    FILE *nombres = fopen("Nombres_Usuario", "ab");



    if(nombres != NULL)
    {

        IDENTIFICADOR = generarID();


        do
        {

        gotoxy(33, 7);
        printf("Ingrese su nombre de usuario (Sin numeros): ");
        gets(&nombreNuevo);
        flag = contiene_numero(nombreNuevo);

        if(flag == 1)
        {
            gotoxy(38,12);
            printf("El nombre ingresado contiene numeros");
            gotoxy(38,13);
            printf("PRESIONE UNA TECLA PARA CONTINUAR...");
            getch();
            CLEAR();

        }

        }while(flag == 1);

        strcpy(x->nombre, nombreNuevo);

        CLEAR();

        x->ID = IDENTIFICADOR;

        validarDato = validarID("Nombres_Usuario", IDENTIFICADOR);

        if(validarDato == 0)
        {

            do
            {

                IDNUEVO = generarID();
                validarDato = validarID("Nombres_Usuario", IDNUEVO);

            }
            while(IDNUEVO == IDENTIFICADOR && validarDato == 0);

            IDENTIFICADOR = IDNUEVO;

            x->ID = IDENTIFICADOR;

        }

        CLEAR();

        fwrite(&x, sizeof(Usuario), 1, nombres);

        fclose(nombres);

    }
    else
    {

        printf("Hubo un error al abrir el archivo. \n");

        fclose(nombres);

    }
}

int generarID ()  /// FUNCIÓN PARA GENERAR UN ID ALEATORIO DESDE 0 HASTA 30000.
{

    int id;

    srand(time(NULL));

    id = rand() % 30000;

    return id;
}

int validarID(char archivoUsuario[], int ID) /// FUNCION PARA COMPROBAR QUE UN ID NO SE REPITA DENTRO DE NINGUN USUARIO
{

    int IDVALIDA = 1;
    Usuario x;

    FILE *usuario = fopen("Nombres_Usuario", "rb");

    if(usuario != NULL)
    {

        while(fread(&x, sizeof(Usuario), 1, usuario) > 0)
        {

            if(x.ID == ID)
            {

                IDVALIDA = 0;

            }

        }


        fclose(usuario);
    }


    return IDVALIDA;
}

void mostrarRegistro(char archi[Dimension_Nombre]) /// FUNCION PARA MOSTRAR UN REGISTRO
{

    Usuario x;

    FILE *archivo = fopen(archi, "rb");

    if(archivo != NULL)
    {

        while(fread(&x, sizeof(Usuario), 1, archivo) > 0)
        {

            printf("Nombre: %s\n", x.nombre);
            printf("ID: %d\n", x.ID);

        }

        fclose(archivo);

    }


}

int opcionesMenuUsuario()  /// FUNCION PARA MOSTRAR POR PANTALLA LAS OPCIONES, ESTA RETORNA UN VALOR QUE ES ALMACENADO EN EL MENU PARA CONTINUAR CON EL FUNCIONAMIENTO DEL PROGRAMA.
{
    int opcion = 0;

    gotoxy(40,8);
    printf("1.JUGAR \n");
    gotoxy(40,9);
    printf("2.PUNTUACIONES\n");
    gotoxy(40,10);
    printf("3.INSTRUCCIONES DE USUARIO\n");
    gotoxy(40,11);
    printf("4.SALIR\n");

    gotoxy(40,14);
    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);

    CLEAR();


    return opcion;

}

void puntuaciones(Ranking ran[]) ///FUNCION PARA MOSTRAR LAS PUNTUACIONES DE LOS DISTINTOS USUARIOS QUE JUGARON AL JUEGO.
{

    Usuario x;
    Ranking nuevo;



    int opc;

    FILE *usuario = fopen("Nombres_Usuario", "rb");
    FILE *puntuacionesF = fopen("Facil", "rb");
    FILE *puntuacionesNm = fopen("Normal", "rb");
    FILE *puntuacionesD = fopen("Dificil", "rb");

    if(usuario != NULL || puntuacionesF != NULL || puntuacionesNm != NULL || puntuacionesD != NULL)
    {

        opc = OpcionesPuntuacion();
        int validos;
        switch(opc)
        {

        case 1:
            CLEAR();
            printf("TABLA DE PUNTUACION DE LA DIFICULTAD FACIL\n\n");

            validos = Archivo_A_Arreglo(1,ran);
            ordenamiento_seleccion(ran,validos);
            sobreescribir(1,ran,validos);

            mostrar_archivo_puntuacion(1);

            printf("\nPRESIONES UNA TECLA PARA CONTINUAR");
            getch();


            break;

        case 2:
            CLEAR();
            printf("TABLA DE PUNTUACION DE LA DIFICULTAD NORMAL \n\n");

            validos = Archivo_A_Arreglo(2,ran);
            ordenamiento_seleccion(ran,validos);
            sobreescribir(2,ran,validos);

            mostrar_archivo_puntuacion(2);

            printf("\nPRESIONES UNA TECLA PARA CONTINUAR");
            getch();

            break;

        case 3:
            CLEAR();
            printf("TABLA DE PUNTUACIONES DE LA DIFICULTAD DIFICIL\n\n");

            validos = Archivo_A_Arreglo(3,ran);
            ordenamiento_seleccion(ran,validos);
            sobreescribir(3,ran,validos);

            mostrar_archivo_puntuacion(3);


            printf("\nPRESIONES UNA TECLA PARA CONTINUAR");
            getch();
        }
        fclose(usuario);
        fclose(puntuacionesF);
        fclose(puntuacionesNm);
        fclose(puntuacionesD);

   }
}

int OpcionesPuntuacion() /// FUNCION QUE MUESTRA LAS OPCIONES PARA MOSTRAR LOS PUNTAJES.
{

    int opcion = 0;

opciones:

    gotoxy(25, 6);
    printf("De que nivel de dificultad desea ver la tabla de puntuaciones?\n");
    gotoxy(48, 8);
    printf("1. Facil\n");
    gotoxy(48, 9);
    printf("2. Normal\n");
    gotoxy(48, 10);
    printf("3. Dificil\n\n");

    gotoxy(48, 12);
    printf("Opcion: ");
    scanf("%d", &opcion);


    if(opcion <= 0 || opcion >3)
    {

        CLEAR();
        gotoxy(40,12);
        printf("La opcion seleccionada no existe.\n\n\n");

        gotoxy(40,13);
        printf("PRESIONE UNA TECLA PARA CONTINUAR");
        getch();
        CLEAR();

        goto opciones;

    }


    return opcion;
}

void gotoxy(int x, int y) /// FUNCION UTILIZADA PARA UBICAR EL CURSOR (NOSOTROS LA UTILIZAMOS PARA CENTRAR EL TEXTO).
{

    HANDLE manipulador;
    COORD coordenadas;
    manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    coordenadas.X = x;
    coordenadas.Y = y;

    SetConsoleCursorPosition(manipulador, coordenadas);

}

void mostrarEstructuraUsuario(Usuario x) /// MUESTRA ESTRUCTURA USUARIO
{

    printf("Nombre: %s\n\n", x.nombre);
    printf("ID: %i\n\n", x.ID);

}

void mostrarEstructuraRanking(Ranking nuevo) /// MUESTRA ESTRUCTURA RANKING
{

    printf("Nombre: %s\n\n", nuevo.nombre);
    printf("Puntaje: %i\n\n", nuevo.puntos);
    printf("ID: %i\n\n", nuevo.ID_Usuario);

}

int contiene_numero(char cadena[]) /// VALIDAR QUE EL NOMBRE INGRESADO POR EL USUARIO NO TENGA NÚMEROS
{

    int flag=0;

    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (isdigit(cadena[i])!=0)
        {

            flag=1; // La cadena contiene al menos un número
        }
     }
        return flag; // La cadena no contiene ningún número

}
int Archivo_A_Arreglo(int nivel,Ranking ran[Dimension_Nombre]) /// PASAR DE UN ARCHIVO TODOS LOS DATOS A UN ARREGLO DE LA ESTRUCTURA RANKING
{
    Ranking aux;
    int i=0;
    if(nivel == 1)
    {
        FILE* archi_facil = fopen("Facil","rb");
        if(archi_facil != NULL)
        {
            while(fread(&aux,sizeof(Ranking),1,archi_facil)>0)
            {
                ran[i] = aux;
                i++;
            }
            fclose(archi_facil);
        }
    }
    else if(nivel == 2)
    {
        FILE* archi_normal = fopen("Normal","rb");
        if(archi_normal != NULL)
        {
            while(fread(&aux,sizeof(Ranking),1,archi_normal)>0)
            {
                ran[i] = aux;
                i++;
            }
            fclose(archi_normal);
        }
    }
    else if(nivel == 3)
    {
        FILE* archi_dificil = fopen("Dificil","rb");
        if(archi_dificil != NULL)
        {
            while(fread(&aux,sizeof(Ranking),1,archi_dificil)>0)
            {
                ran[i] = aux;
                mostrarEstructuraRanking(aux);
                i++;
            }
            fclose(archi_dificil);
        }
    }


    return i;
}

int Mayor (Ranking ran[], int validos, int posicionI) /// DEVUELVE LA POS DEL MAYOR PUNTAJE
{
int mayor_ma = ran[posicionI].puntos;
int posicion_mayor = posicionI;
for(int i = posicionI ; i<validos ; i++)
{
    if(ran[i].puntos>mayor_ma)
    {
        mayor_ma = ran[i].puntos;
        posicion_mayor = i;
    }
}
return posicion_mayor;
}
///Busca la posicion menor
void ordenamiento_seleccion(Ranking ran[], int validos)
{
    int i=0, pos_mayor;
    Ranking nuevo;
    while(i<validos)
    {
        pos_mayor = Mayor(ran,validos,i);

        nuevo = ran[pos_mayor];
        ran[pos_mayor] = ran[i];
        ran[i] = nuevo;

        i++;
    }
}
void sobreescribir(int nivel,Ranking ran[], int validos)/// SOBREESCRIBE EN EL ARCHIVO LOS DATOS ORDENADOS
{
    Ranking aux;

    if(nivel == 1)
    {
        FILE* archi_facil = fopen("Facil","wb");
        if(archi_facil != NULL)
        {
            for(int i=0; i<validos; i++)
            {
                aux = ran[i];
                fwrite(&aux,sizeof(Ranking),1,archi_facil);
            }
            fclose(archi_facil);
        }
    }
    else if(nivel == 2)
    {
        FILE* archi_normal = fopen("Normal","wb");
        if(archi_normal != NULL)
        {
            for(int i=0; i<validos; i++)
            {
                aux = ran[i];
                fwrite(&aux,sizeof(Ranking),1,archi_normal);
            }
            fclose(archi_normal);
        }
    }
    else if(nivel == 3)
    {
        FILE* archi_dificil = fopen("Dificil","wb");
        if(archi_dificil != NULL)
        {
            for(int i=0; i<validos; i++)
            {
                aux = ran[i];
                fwrite(&aux,sizeof(Ranking),1,archi_dificil);
            }
            fclose(archi_dificil);
        }
    }
}
void mostrar_archivo_puntuacion(int nivel) /// MUESTRA UN ARCHIVO
{
    Ranking aux;
    if(nivel == 1)
      {
        FILE* archi_facil = fopen("Facil","rb");
        if(archi_facil != NULL)
        {
            while(fread(&aux,sizeof(Ranking),1,archi_facil)>0)
            {
               printf("Nombre: %s\n\n", aux.nombre);
               printf("Puntaje: %i\n\n", aux.puntos);
               printf("ID: %i\n\n", aux.ID_Usuario);
            }
            fclose(archi_facil);
        }
    }
    else if(nivel == 2)
    {
        FILE* archi_normal = fopen("Normal","rb");
        if(archi_normal != NULL)
        {
            while(fread(&aux,sizeof(Ranking),1,archi_normal)>0)
            {
               printf("Nombre: %s\n\n", aux.nombre);
               printf("Puntaje: %i\n\n", aux.puntos);
               printf("ID: %i\n\n", aux.ID_Usuario);
            }
            fclose(archi_normal);
        }
    }
    else if(nivel == 3)
    {
        FILE* archi_dificil = fopen("Dificil","rb");
        if(archi_dificil != NULL)
        {
            while(fread(&aux,sizeof(Ranking),1,archi_dificil)>0)
            {
               printf("Nombre: %s\n\n", aux.nombre);
               printf("Puntaje: %i\n\n", aux.puntos);
               printf("ID: %i\n\n", aux.ID_Usuario);
            }
            fclose(archi_dificil);
        }
    }

}

