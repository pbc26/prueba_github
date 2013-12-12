//DNI 48623053H BAUDÍ CANALES, PABLO

#include <locale.h>
#include <libintl.h>
#include <iostream>
#include <cstdlib>

#include "listatareas.h"
#include "utilidades.h"

#define _(String) gettext(String)

int main(int argc, char *argv[]) {

	ListaTareas tareas;
	string localedir;
	string opcion = "", op_par_argv="", nombreFichero_argv="";
	string op_par="", nombreFichero="";
/*

	if (Config.DEVELOPMENT_MODE == "ON") { // App not installed,
                                               // catalogs are here
                localedir = "src/po";
        } else {
                localedir = Config.PACKAGE_LOCALE_DIR;
        }
        */
        
        setlocale (LC_ALL, "");

        bindtextdomain ("ltareas", "./po");
        //bind_textdomain_codeset ("ltareas", "UTF-8");
        textdomain("ltareas");


	if(Utilidades::ComprobarParametros(argc, argv)) { //Si los parametros han sido correctos o no ha metido entramos al programa sin ningun problema

		if(Utilidades::ParametrosApropiados(argc, argv)) {

				op_par_argv=argv[1];
				nombreFichero_argv=argv[2];
				tareas.procesarFichero(nombreFichero_argv, op_par_argv);
		}
		do { //Lista para gestionar las tareas

			tareas.mostrar();
			
			cout << "a" << gettext("Anyadir tarea") << endl;
			
			cout << "c" << gettext("Cambiamos la vista de tareas pendientes o completadas") << endl;
			
			cout << "d" << gettext("Completamos la tarea indicada por el usuario") << endl;
			
			cout << "b" << gettext("Borramos la tarea indicada por el usuario") << endl;
			
			cout << "w" << gettext("Escribimos un fichero de texto o de binario") << endl;
			
			cout << "b" << gettext("Borramos la tarea indicada por el usuario") << endl;
			
			cout << "i" << gettext("Importamos fichero de texto o binario") << endl;
			
			cout << "r" << gettext("Lectura de un fichero de texto o de binario") << endl;
			
			cout << "s" << gettext("Salir") << endl;


			cout << KORDEN;
			getline(cin, opcion);

			if (opcion[0] == 'a') { //Añadir tarea

				tareas.tareaDeCadena(opcion);
			} else if (opcion[0] == 'c') { //Cambiamos la vista de tareas pendientes o completadas

				tareas.cambiarVista();
			} else if (opcion[0] == 'd') { //Completamos la tarea indicada por el usuario

				tareas.modificarTarea(opcion);
			} else if (opcion[0] == 'b') { //Borramos la tarea indicada por el usuario

				tareas.modificarTarea(opcion);
			} else if(opcion[0] == 'w') { //Escribimos un fichero de texto o de binario

				Utilidades::RecogerParametros(opcion, nombreFichero, op_par);
				tareas.procesarFichero(nombreFichero, op_par);
			} else if (opcion[0] == 'i') { //Importamos fichero de texto o binario

				Utilidades::RecogerParametros(opcion, nombreFichero, op_par);
				tareas.procesarFichero(nombreFichero, op_par);
			} else if (opcion[0] == 'r') { //Lectura de un fichero de texto o de binario

				Utilidades::RecogerParametros(opcion, nombreFichero, op_par);
				tareas.procesarFichero(nombreFichero, op_par);
			} else if (opcion[0] == 's') { //Opcion para salir

				return 0;
			} else { //Si el usuario no ha indicado una opcion correcta sacamos un mensaje de error

				cout << KMSG5 << endl;
			}

		} while (opcion[0] != 's');
	}
}

