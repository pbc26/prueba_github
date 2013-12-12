//DNI 48623053H BAUDÍ CANALES, PABLO

#ifndef _utilidades_
#define _utilidades_

#include <iostream>
#include <string.h>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <fstream>

//CONSTANTES
int const KTAREAS = 50; //Maximo de tareas que podemos añadir
int const KTAG = 10; //Maximo de etiquetas por tarea;
int const KLONG = 20; //Longitud maxima de las etiquetas;
int const KTMAX = 40; //Longitud maxima de la descripcion de las tareas;

int const KSEMANA=7; //días de semana

//****Mensajes de errores****//
char const KMSG1[] = "E1- NUMERO MAXIMO DE TAREAS ALCANZADO";
char const KMSG2[] = "E2- NUMERO DE TAREA INCORRECTO";
char const KMSG3[] = "E3- DEMASIADAS ETIQUETAS";
char const KMSG4[] = "E4- ERROR DE APERTURA DEL FICHERO";
char const KMSG5[] = "E5- SINTAXIS INCORRECTA";

char const KMENUP[] = "------- TAREAS PENDIENTES -------";
char const KMENUC[] = "------- TAREAS COMPLETADAS -------";
char const KRAYA[] = "---------------------------------";
char const KSEPARADOR[] = " | ";
char const KORDEN[] = "M1- ORDEN: ";

using namespace std;

class Utilidades {

public:
	Utilidades();
	~Utilidades();
	static bool ComprobarParametros(int argc, char *argv[]);
	static bool ParametrosApropiados(int argc, char *argv[]);
	static void RecogerParametros(string orden, string &nombreFichero, string &op_par);
};

#endif
