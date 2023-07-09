#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "juego.h"
#include "windows.h"

void colocar_minasAleatorio (int matrizInvisible[Dimension_Matriz][Dimension_Matriz], Espacio nuevo)///Lo que hace esta funcion es cargar la estructura matriz con 0 y dependiendo el nivel la cantidad de -1
{
    int i=0;
    int fila,columna;

    for (i; i<nuevo.cant_Minas; i++)
    {
        fila=rand()% (0,Dimension_Matriz-1);
        columna=rand()%(0,Dimension_Matriz-1);

        matrizInvisible[fila][columna] =(-1);

    }

    for (int i=0; i<Dimension_Matriz; i++)
    {
        for(int j=0; j<Dimension_Matriz; j++)
        {
            if (matrizInvisible[i][j]!=(-1))
            {
                matrizInvisible[i][j]=0;
            }
        }

    }
}
void tableroCol()///Imprime el Tablero
{
    int i=0, j=0;
    char linea='A';

    for (int j=0; j<Dimension_Matriz ; j++)
    {
        printf("   %c  ",linea);
        linea++;
    }

    printf("\n _ _ _ _ _ _ _ _ \n");

    for (i; i <Dimension_Matriz ; i++)
    {

        printf("\n");

        printf("|");
        for(j=0; j<Dimension_Matriz ; j++)
        {

            printf("_");
            printf("|");
        }
        printf("   %i  ",i);
        printf("\n");
    }
}
void cargar_X_Matriz_visible(int matrizVisible[Dimension_Matriz][Dimension_Matriz])///Carga con X la matriz visible
{
    for(int i=0; i<Dimension_Matriz; i++)
    {
        for(int j=0; j<Dimension_Matriz ; j++)
        {
            matrizVisible[i][j] = 7;
        }
    }
}
void mostrarMatrizInvisible(int matrizInvisible[Dimension_Matriz][Dimension_Matriz])///Muestra la matriz invisible
{
    int linea_sup=0;
    printf("\n");
    for (int j=0; j<Dimension_Matriz ; j++)
    {
        printf("   %i  ",linea_sup);
        linea_sup++;
    }
    printf("\n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");

    for (int i=0; i <Dimension_Matriz ; i++)
    {
        printf("\n");
        printf("|");
        for(int j=0; j<Dimension_Matriz ; j++)
        {
            if (matrizInvisible[i][j]==(-1))
            {
                printf("  %i ",matrizInvisible[i][j]);
            }
            else
            {
                printf("  %i  ", matrizInvisible[i][j]);
            }
            printf("|");
        }
        printf("   %i  ",i);
        printf("\n");
    }
}
void mostrarMatriz_visible(int matrizVisible[Dimension_Matriz][Dimension_Matriz])///Muestra la matriz visible
{
   int linea_sup=0;
    printf("\n");
    for (int j=0; j<Dimension_Matriz ; j++)
    {
        printf("   %i  ",linea_sup);
        linea_sup++;
    }
    printf("\n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");

    for (int i=0; i <Dimension_Matriz ; i++)
    {
        printf("\n");

        printf("|");
        for(int j=0; j<Dimension_Matriz ; j++)
        {
            if (matrizVisible[i][j]==(-1))
            {
                printf("  %i ",matrizVisible[i][j]);
            }
            else
            {
                printf("  %i  ", matrizVisible[i][j]);
            }
            printf("|");
        }
        printf("   %i  ",i);
        printf("\n");
    }
}
void agregar_unos_alrededor(int matrizInvisible[Dimension_Matriz][Dimension_Matriz])///Esta funcion lo que hace es va recorriendo cuando encuentra un -1 carga unos alrededor
{
    for (int i=0 ; i<Dimension_Matriz ; i++)
    {
        for(int j=0 ; j<Dimension_Matriz ; j++)
        {
            if(matrizInvisible[i][j] == (-1))
            {
                if(i<Dimension_Matriz-1 && matrizInvisible[i][j+1] != (-1))
                    matrizInvisible[i][j+1] =matrizInvisible[i][j+1] + 1;//arriba
                if(i>0 && matrizInvisible[i][j-1] != (-1))
                    matrizInvisible[i][j-1] = 1 + matrizInvisible[i][j-1];//abajo
                if(i>0 && matrizInvisible[i-1][j] != (-1))
                    matrizInvisible[i-1][j] = 1 + matrizInvisible[i-1][j]; //izquierda
                if(i<Dimension_Matriz && matrizInvisible[i+1][j] != (-1))
                    matrizInvisible[i+1][j] = 1 + matrizInvisible[i+1][j]; //derecha
                if(i<Dimension_Matriz && j<Dimension_Matriz && matrizInvisible[i+1][j+1] != (-1))
                    matrizInvisible[i+1][j+1] = 1 + matrizInvisible[i+1][j+1]; //derecha arriba
                if(i<Dimension_Matriz && j>0 && matrizInvisible[i+1][j-1] != (-1))
                    matrizInvisible[i+1][j-1] = 1 + matrizInvisible[i+1][j-1]; //derecha abajo
                if(i>0 && j<Dimension_Matriz && matrizInvisible[i-1][j+1] != (-1))
                    matrizInvisible[i-1][j+1] = 1 + matrizInvisible[i-1][j+1]; // izquierda arriba
                if(i>0 && j>0 && matrizInvisible[i-1][j-1] != (-1))
                    matrizInvisible[i-1][j-1] = 1 + matrizInvisible[i-1][j-1]; //izquierda abajo
            }
        }
    }
}
int validacionCoordenadasIngresada (int x, int y, int matrizVisible[Dimension_Matriz][Dimension_Matriz])/// VALIDA QUE LAS COORDENADAS NO SE SALGAN DE LOS LÍMITES DE LA MATRIZ
{
    int flag=0;

    if (x>=0 && x<Dimension_Matriz &&  y>=0 && y<Dimension_Matriz)
    {
        flag=1;
    }
    return flag;
}
int validarCantCasillasDesbloqueadas (Espacio nuevo) ///casillasAdesbloquear es cantCasillasTotales-cantMinas
{
    int bandera=0;

    if(nuevo.puntaje==nuevo.casillas_desbloquear)
    {
        bandera==1;
    }
    return bandera;
}
///EVALÚA LAS COORDENADAS INGRESADAS POR EL USUARIO Y EJECUTA LAS INSTRUCCIONES CORRESPONDIENTES
int descubrir_casilla (Ranking ran, int x, int y,Espacio nuevo, int matrizInvisible[Dimension_Matriz][Dimension_Matriz],int matrizVisible[Dimension_Matriz][Dimension_Matriz],char Facil[],char Normal[],char Dificil[])
{

    int ban;
    int puntos=0;
    switch(matrizInvisible[x][y])
    {
    case -1:

        gotoxy(27, 1);
        printf("PERDISTE\n");
        mostrarMatrizInvisible(matrizInvisible);

        break;
    case 0:

        cantCasillas(matrizInvisible,matrizVisible,x,y);
        mostrarMatriz_visible(matrizVisible);
        int bandera = recorrerMatriz2(matrizVisible, nuevo.casillas_desbloquear);

        if(bandera == 1)
        {
            printf("\n\t GANASTE\t\n");
        }
        break;
    case 1:

        matrizVisible[x][y] = matrizInvisible[x][y];
        mostrarMatriz_visible(matrizVisible);
        ban = recorrerMatriz2(matrizVisible, nuevo.casillas_desbloquear);
        if(ban==1)
        {
            printf("\n\t GANASTE \t\n");
        }
        break;
    case 2:
        matrizVisible[x][y] = matrizInvisible[x][y];
        mostrarMatriz_visible(matrizVisible);
        ban = recorrerMatriz2(matrizVisible, nuevo.casillas_desbloquear);
        if(ban==1)
        {
            printf("\n\t GANASTE \t\n");
        }
        break;
    case 3:
        matrizVisible[x][y] = matrizInvisible[x][y];
        mostrarMatriz_visible(matrizVisible);
        ban = recorrerMatriz2(matrizVisible, nuevo.casillas_desbloquear);
        if(ban==1)
        {
            printf("\n\t GANASTE \t\n");
        }
        break;
    }
    return puntos;
}
///Desbloquea las casillas
void cantCasillas(int matrizInvisible[Dimension_Matriz][Dimension_Matriz],int matrizVisible[Dimension_Matriz][Dimension_Matriz],int x, int y)
{
    int filaInicio, filaFin, columnaInicio, columnaFin;

    //Fila
    if (x-1 < 0)
    {
        filaInicio = 0;
    }
    else
    {
        filaInicio = x-1;
    }

    if (x+1 > Dimension_Matriz)
    {
        filaFin = Dimension_Matriz-1;
    }
    else
    {
        filaFin = x+1;
    }

    //Columna
    if (y-1<= 0)
    {
        columnaInicio = 0;
    }
    else
    {
        columnaInicio = y-1;
    }
    if (y + 1 > Dimension_Matriz)
    {
        columnaFin = Dimension_Matriz-1;
    }
    else
    {
        columnaFin = y + 1;
    }
    //Recorre un recuadro de 8 casillas alrededor de los que eligio la persona
    for (int m = filaInicio; m<=filaFin; m++)
    {
        for (int l = columnaInicio; l<=columnaFin; l++)
        {
            matrizVisible[m][l]=matrizInvisible[m][l];
        }
    }

}
int funcion_juego(Ranking nuevo, Espacio Tablero, int dificultad, int Matriz_invisible[][Dimension_Matriz], int Matriz_visible[][Dimension_Matriz], char facil[], char normal[], char dificil[])/// EN ESTA FUNCIÓN SE LLAMAN A EL RESTO DE FUNCIONES PARA EJECUTAR CORRECTAMENTE EL JUEGO.
{
    int fila, columna, flag;
    int puntaje = 0;
    Tablero.puntaje = 0;

    if(dificultad == 1)
    {

        CLEAR();
        Tablero.cant_Minas = minas_facil;
        Tablero.casillas_desbloquear = 100-Tablero.cant_Minas;
        Tablero.nivel = dificultad;
        colocar_minasAleatorio(Matriz_invisible,Tablero); // Cargar de 0 la matriz invisible y carga las minas con -1 dependiendo del nivel
        agregar_unos_alrededor(Matriz_invisible); // Agrega unos alrededor de la mina y si esta cerca dos minas se carga con 2
        cargar_X_Matriz_visible(Matriz_visible); //Carga la matriz visible con X
        mostrarMatriz_visible(Matriz_visible); //Muestra la matriz visible
        do
        {

            printf("Indique la cordenada X: ");
            scanf("%i",&fila);

            printf("Indique la cordenada Y:");
            scanf("%i",&columna);

            CLEAR();

            flag = validacionCoordenadasIngresada(columna,fila,Matriz_visible);
            while(flag==0)
            {
                mostrarMatriz_visible(Matriz_visible);
                printf("\nLa coordena ingresada no es valida o ya fue descubierta, ingrese nuevamente: \n");
                printf("Indique la cordenada X: ");
                scanf("%i",&fila);

                printf("Indique la cordenada Y:");
                scanf("%i",&columna);

                flag = validacionCoordenadasIngresada(columna,fila,Matriz_visible);
            }
            descubrir_casilla (nuevo,fila, columna,Tablero, Matriz_invisible,Matriz_visible,facil,normal,dificil);
            Tablero.puntaje = recorrerMatriz(Matriz_visible);
            printf("\nPUNTAJE: %i\n", Tablero.puntaje);
        }
        while(Tablero.puntaje!=Tablero.casillas_desbloquear && Matriz_invisible[fila][columna]!=-1);

    }
    else if(dificultad == 2)
    {
        CLEAR();
        Tablero.cant_Minas = 15;
        Tablero.casillas_desbloquear = 100-Tablero.cant_Minas;
        Tablero.nivel = dificultad;
        colocar_minasAleatorio(Matriz_invisible,Tablero); // Cargar de 0 la matriz invisible y carga las minas con -1 dependiendo del nivel
        agregar_unos_alrededor(Matriz_invisible); // Agrega unos alrededor de la mina y si esta cerca dos minas se carga con 2
        cargar_X_Matriz_visible(Matriz_visible); //Carga la matriz visible con X
        mostrarMatriz_visible(Matriz_visible); //Muestra la matriz visible
      do
        {

            printf("Indique la cordenada X: ");
            scanf("%i",&fila);

            printf("Indique la cordenada Y:");
            scanf("%i",&columna);
            CLEAR();
            flag = validacionCoordenadasIngresada(columna,fila,Matriz_visible);
            while(flag==0)
            {
                mostrarMatriz_visible(Matriz_visible);
                printf("\nLa coordena ingresada no es valida o ya fue descubierta, ingrese nuevamente: \n");
                printf("Indique la cordenada X: ");
                scanf("%i",&fila);

                printf("Indique la cordenada Y:");
                scanf("%i",&columna);

                flag = validacionCoordenadasIngresada(columna,fila,Matriz_visible);
            }
            descubrir_casilla (nuevo,fila, columna,Tablero, Matriz_invisible,Matriz_visible,facil,normal,dificil);
            Tablero.puntaje = recorrerMatriz(Matriz_visible);
            printf("\nPUNTAJE: %i\n", Tablero.puntaje);
        }
        while(Tablero.puntaje!=Tablero.casillas_desbloquear && Matriz_invisible[fila][columna]!=-1);


    }

    else if(dificultad == 3)
    {
        CLEAR();
        Tablero.cant_Minas = 20;
        Tablero.casillas_desbloquear = 100-Tablero.cant_Minas;
        Tablero.nivel = dificultad;
        colocar_minasAleatorio(Matriz_invisible,Tablero); // Cargar de 0 la matriz invisible y carga las minas con -1 dependiendo del nivel
        agregar_unos_alrededor(Matriz_invisible); // Agrega unos alrededor de la mina y si esta cerca dos minas se carga con 2
        cargar_X_Matriz_visible(Matriz_visible); //Carga la matriz visible con X
        mostrarMatriz_visible(Matriz_visible); //Muestra la matriz visible

        do
        {


            printf("Indique la cordenada X: ");
            scanf("%i",&fila);

            printf("Indique la cordenada Y:");
            scanf("%i",&columna);

            CLEAR();

            flag = validacionCoordenadasIngresada(columna,fila,Matriz_visible);
            while(flag==0)
            {
                mostrarMatriz_visible(Matriz_visible);
                printf("\nLa coordena ingresada no es valida o ya fue descubierta, ingrese nuevamente: \n");
                printf("Indique la cordenada X: ");
                scanf("%i",&fila);

                printf("Indique la cordenada Y:");
                scanf("%i",&columna);

                flag = validacionCoordenadasIngresada(columna,fila,Matriz_visible);
            }
            descubrir_casilla (nuevo,fila, columna,Tablero, Matriz_invisible,Matriz_visible,facil,normal,dificil);
            Tablero.puntaje = recorrerMatriz(Matriz_visible);
            printf("\nPUNTAJE: %i\n", Tablero.puntaje);
        }
        while(Tablero.puntaje!=Tablero.casillas_desbloquear && Matriz_invisible[fila][columna]!=-1);
    }
    return Tablero.puntaje;

}

int recorrerMatriz(int Matriz_Visible[][Dimension_Matriz]) /// SUMAR EL PUNTAJE
{

    int cant_casillas = 0;

    for(int i = 0; i < Dimension_Matriz; i++)
    {

        for(int j = 0; j < Dimension_Matriz; j++)
        {

            if(Matriz_Visible[i][j] != 7)
            {

                cant_casillas++;

            }

        }

    }

    return cant_casillas;

}

int recorrerMatriz2(int matriz_visible[][Dimension_Matriz], int casillas_total) /// FUNCION PARA SABER SI GANÓ EL USUARIO: SI LA CANTIDAD DE CASILLAS DESBLOQUEADAS ES == A LA CANTIDAD DE CASILLAS TOTALES - LA CANTIDAD DE MINAS, EL USUARIO GANÓ
{

    int flag = 0;
    int casillas = 0;

    for(int i = 0; i < Dimension_Matriz; i++)
    {

        for(int j = 0; j < Dimension_Matriz; j++)
        {

            if(matriz_visible[i][j] == 0 || matriz_visible[i][j] == 1 || matriz_visible[i][j] == 3 || matriz_visible[i][j] == 4 || matriz_visible[i][j] == 5)
            {

                casillas++;

            }

        }

    }

    if(casillas == casillas_total)
    {

        flag = 1;

    }


    return flag;

}




