#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "juego.h"
#include "windows.h"

//Prototipado
int generarID ();
int validarID(char archivoUsuario[], int ID);
int opcionesMenuUsuario();
int OpcionesPuntuacion();
int validacionCoordenadasIngresada (int x, int y, int matrizVisible[Dimension_Matriz][Dimension_Matriz]);
int validarCantCasillasDesbloqueadas (Espacio nuevo);
int descubrir_casilla (Ranking ran, int x, int y,Espacio nuevo, int matrizInvisible[Dimension_Matriz][Dimension_Matriz],int matrizVisible[Dimension_Matriz][Dimension_Matriz],char Facil[],char Normal[],char Dificil[]);
int funcion_juego(Ranking nuevo, Espacio Tablero, int dificultad, int Matriz_invisible[][Dimension_Matriz], int Matriz_visible[][Dimension_Matriz], char facil[], char normal[], char dificil[]);
int Mayor (Ranking ran[], int validos, int posicionI);
int Archivo_A_Arreglo(int nivel,Ranking ran[Dimension_Nombre]);
int recorrerMatriz(int Matriz_Visible[][Dimension_Matriz]);
int recorrerMatriz2(int matriz_visible[][Dimension_Matriz], int casillas_total);

int main()
{
    int Matriz_invisible[Dimension_Matriz][Dimension_Matriz];
    int Matriz_visible[Dimension_Matriz][Dimension_Matriz];
    int fila,columna;
    int flag=0;
    int puntaje=0;

    char archivoUsuario[Dimension_Nombre];
    strcpy(archivoUsuario, "Nombres_Usuario");

    char facil[Dimension_Nombre];
    char normal[Dimension_Nombre];
    char dificil[Dimension_Nombre];
    strcpy(facil,"Facil");
    strcpy(normal,"Normal");
    strcpy(dificil,"Dificil");


    Espacio Tablero;
    Ranking nuevo;
    Ranking ran[Dimension_Nombre];
    Usuario x;

    srand(time(NULL));

    // int Hoal = Archivo_A_Arreglo(3,ran);
    //ordenamiento_seleccion(ran,3);
    //sobreescribir(3,ran,3);

    menu(Matriz_invisible, Matriz_visible,facil,normal,dificil,archivoUsuario,ran);
 //mostrarRegistro(facil);


    return 0;
}
