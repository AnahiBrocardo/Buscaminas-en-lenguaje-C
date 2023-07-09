#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#define Dimension_Nombre 20 //Si quieren modificar la dimension se cambia el numero
#define Dimension_Matriz 10 //Si quieren modificar la dimension se cambia el numero
#define Dimension_ID 50 //Si quieren modificar la dimension se cambia el numero
#define CLEAR() system("CLS") //WINDOWS
#define BAR_V 186
#define minas_facil 10
#define minas_medio 15
#define minas_dificil 20

typedef struct{

int cant_Minas;
int ID_Usuario;
int nivel;
int casillas_desbloquear;
int puntaje;
}Espacio;  //Espacio es la estructura de nuestras matrices

typedef struct{
char nombre[Dimension_Nombre];
int ID;
}Usuario; //Nombre del usuario

typedef struct{
int puntos;
char nombre[Dimension_Nombre];
int ID_Usuario;
}Ranking; //Puntos a lo largo del juego.


///FUNCIONES CORRESPONDIENTES AL JUEGO
void colocar_minasAleatorio (int matrizInvisible[Dimension_Matriz][Dimension_Matriz], Espacio nuevo);
void tableroCol();
void cargar_X_Matriz_visible(int matrizVisible[Dimension_Matriz][Dimension_Matriz]);
void mostrarMatrizInvisible(int matrizInvisible[Dimension_Matriz][Dimension_Matriz]);
void mostrarMatriz_visible(int matrizVisible[Dimension_Matriz][Dimension_Matriz]);
void agregar_unos_alrededor(int matrizInvisible[Dimension_Matriz][Dimension_Matriz]);
int validacionCoordenadasIngresada (int x, int y, int matrizVisible[Dimension_Matriz][Dimension_Matriz]);
int validarCantCasillasDesbloqueadas (Espacio nuevo);
int funcion_juego(Ranking nuevo, Espacio Tablero, int dificultad, int Matriz_invisible[][Dimension_Matriz], int Matriz_visible[][Dimension_Matriz], char facil[], char normal[], char dificil[]);
int funcion_juego(Ranking nuevo, Espacio Tablero, int dificultad, int Matriz_invisible[][Dimension_Matriz], int Matriz_visible[][Dimension_Matriz], char facil[], char normal[], char dificil[]);
int recorrerMatriz(int Matriz_Visible[][Dimension_Matriz]);
void cantCasillas(int matrizInvisible[Dimension_Matriz][Dimension_Matriz],int matrizVisible[Dimension_Matriz][Dimension_Matriz],int x, int y);
int recorrerMatriz2(int matriz_visible[][Dimension_Matriz], int casillas_total);
/// FUNCION DE MENU DESTINADO AL USUARIO, AQUÍ SE ENCUENTRAN TODAS LAS FUNCIONALIDADES DEL PROGRAMA (JUEGO, INFO, PUNTUACIONES, SALIR).
void cargarUsuario();
int generarID ();
int validarID(char archivoUsuario[], int ID);
void mostrarRegistro(char archivo[Dimension_Nombre]);
int opcionesMenuUsuario();
void puntuaciones(Ranking ran[]);
int OpcionesPuntuacion();
void gotoxy(int x, int y);
void mostrarEstructuraUsuario(Usuario x);
void mostrarEstructuraRanking(Ranking nuevo);
void menu(int Matriz_invisible[][Dimension_Matriz], int Matriz_visible[][Dimension_Matriz], char facil[], char normal[], char dificil[], char archivoUsuario[],Ranking ran[Dimension_Nombre]); /// FUNCION DE MENU DESTINADO AL USUARIO, AQUÍ SE ENCUENTRAN TODAS LAS FUNCIONALIDADES DEL PROGRAMA (JUEGO, INFO, PUNTUACIONES, SALIR).
int Archivo_A_Arreglo(int nivel,Ranking ran[Dimension_Nombre]);
int Mayor (Ranking ran[], int validos, int posicionI);
void ordenamiento_seleccion(Ranking ran[], int validos);
void sobreescribir(int nivel,Ranking ran[], int validos);
void mostrar_archivo_puntuacion(int nivel);


#endif // JUEGO_H_INCLUDED
