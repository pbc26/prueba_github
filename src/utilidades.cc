//DNI 48623053H BAUDÍ CANALES, PABLO

#include "utilidades.h"

Utilidades::Utilidades() {

}

Utilidades::~Utilidades() {

}

bool Utilidades::ComprobarParametros(int argc, char *argv[]) {

	bool entra=true;

	if(argc > 1) { //Comprobamos los parametros si ha añadido mas de 2

		if((strcmp(argv[1],"rt") !=0) && (strcmp(argv[1],"rb") !=0)) { //Comparamos si los parametros son correctos

			entra=false;
		} else if (argc!=3) { //Si ha metido un numero distinto de parametros sacamos el error

			entra=false;
		}
	}

	if (entra == false) cout << KMSG5 << endl;

	return entra;
}

bool Utilidades::ParametrosApropiados(int argc, char *argv[]) {

	bool entra=false;

	if(argc == 3) { //Si encuentra los parametros apropiados comparamos si las opciones son las correctas

		if((strcmp(argv[1],"rt") == 0) || (strcmp(argv[1],"rb") == 0)) {

			entra=true;
		}
	}

	return entra;
}

void Utilidades::RecogerParametros(string orden, string &nombreFichero, string &op_par)
{
	int cant = orden.length();
	bool entra=false;
	nombreFichero="", op_par="";

	for(int i=0; i < cant; i++) {

		if(orden[i]!=' ' && entra==false) {

			op_par=op_par + orden[i]; //Recogemos opcion
		}
		else {

			entra=true;
		}

		if(entra==true && orden[i]!=' ') {

			nombreFichero=nombreFichero + orden[i]; //Recogemos nombre del fichero
		}
	}
}
