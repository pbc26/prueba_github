//DNI 48623053H BAUDÍ CANALES, PABLO

#include "listatareas.h"
#include "fecha.h"

using namespace std;

ListaTareas::ListaTareas() {

	mostrarcompletadas=false;
	ntareas=0;
}

ListaTareas::~ListaTareas() {

}

void ListaTareas::mostrar() const {

	int num_aux=1;

	if (mostrarcompletadas == false) cout << KMENUP << endl;
	else cout << KMENUC << endl;

	for (int i = 0; i < ntareas; i++) {

		if (mostrarcompletadas == t[i].isCompletada()) { //Si es false mostramos pendientes y si es true completadas

			cout << num_aux++ << KSEPARADOR;
			t[i].mostrar();
			cout << endl;
		}
	}
	cout << KRAYA << endl;
}

int ListaTareas::extraerNumeroComPen(string orden)
{
	int aux = 0;

	for(int i=0; i<ntareas; i++) {
		if(t[i].isCompletada()==mostrarcompletadas)
			aux++;
	}
	return aux;
}

void ListaTareas::modificarTarea(string orden) {

	int i = 0, aux = 0, cant = 0, comppen = 0;
	bool entra = true;
	string op_aux = "";
	comppen=extraerNumeroComPen(orden);

	cant=orden.length();

	for (i = 2; i <= cant; i++) { //Extraemos el numero para operar, empezamos en la posicion dos

		if(orden[i]!=' ' && entra==true) {

			op_aux += orden[i];
		} else {

			entra=false;
		}
	}
	aux = atoi(op_aux.c_str()) - 1;

	if (aux >= 0 && aux < comppen) {


		if(orden[0]=='b') { //Borramos tarea

			borrarTarea(aux);
		} else if(orden[0]=='d') { //Completamos tarea

			completarTarea(aux);
		}

	} else {

		cout << KMSG2 << endl;
	}
}

bool ListaTareas::tareaDeCadena(string orden) {

	bool entra = false, entra_tag = false, entra_fec = false, entra_tag_con=true, sin_errores=false, entra_desc=true;
	int i_aux= 0, cant = orden.length();
	int k = 0;
	string op_aux = "", op_aux_fecha = "", op_aux_tag = "";

	Tarea tarea_aux;
	Fecha fecha_aux;

	for (k = 0; k < cant; k++) {

		if(entra_desc) {
			if (orden[k] == '\"' && entra == false) { //Si encontramos comillas daremos paso a extraer la descripcion
				entra = true;
				k++;
			}
		}

		if (entra == true && orden[k] != '\"') { //Extraemos la descripcion

			op_aux = op_aux + orden[k];
			i_aux=k;
			entra_desc=false;
			sin_errores=true; //Si hay descripcion y se cerra la ultima comilla devolvemos true.
		}
		else {

		  entra=false;
		}
	}

	for(int i = i_aux+3; i < cant; i++) {

		  if(orden[i]=='q' && entra_tag==false) { //Comprobamos si eligió el argumento q

		   entra_tag=true;
		   i++; //Adelantamos una posición para recoger correctamente las etiquetas
		  }

		  if(entra_tag==true && entra_tag_con==true) { //Extraemos las etiquetas

			  op_aux_tag = op_aux_tag + orden[i];
	  }

	  if(entra_tag==false && orden[i]!=' ') { //Extraemos fecha

	   op_aux_fecha=op_aux_fecha+orden[i];
	   entra_fec=true;
	  }
	}

  if (sin_errores == true) {

	  tarea_aux.setDesc(op_aux);
	  if (op_aux_tag!="") tarea_aux.setEtiquetas(op_aux_tag);
	  fecha_aux.setValor(op_aux_fecha);
	  tarea_aux.setFecha(fecha_aux);

	  insertarTarea(tarea_aux);
  }

	return sin_errores;
}

bool ListaTareas::insertarTarea(Tarea t) {

	bool entra=false;

	if (ntareas < KTAREAS) {

		this->t[ntareas]=t;
		ntareas++;
		entra=true;

	} else {
		cout << KMSG1 << endl;
	}

	ordenarTareas(); //Ordenamos tareas

	return entra;

}

bool ListaTareas::borrarTarea(int pos_tat) {

	int aux_i=-1;
	bool repetir=false;

	for (int i = 0; i < ntareas; i++) {

		if(t[i].isCompletada() == mostrarcompletadas) aux_i++;

		if((aux_i == pos_tat && t[i].isCompletada() == mostrarcompletadas) || repetir) {

			repetir=true;

			if(i!=ntareas-1) {
				t[i] = t[i + 1];
			}
		}
	}

	ntareas--;
	return true;
}


bool ListaTareas::completarTarea (int pos_tat) {

	int aux_i=-1;

	for (int i = 0; i < ntareas; i++) {

		if (t[i].isCompletada() == mostrarcompletadas) {
			aux_i++;

			if(aux_i == pos_tat) t[i].completar();

			}
		}

	return true;
}

bool ListaTareas::leerFicheroBinario(string nombreFichero, bool importar) {

	fstream fich_texto;
	TareaBin tb;
	Tarea taux;
	bool entra=true;

	fich_texto.open(nombreFichero.c_str(),ios::in | ios::binary);

	if(fich_texto.is_open()==false) { //Si el fichero no se ha abierto correctamente sacamos el error

		cout << KMSG4 << endl;
		entra=false;
	}
	else {

		if(!importar) ntareas=0; //Si es la opcion de leer reseteamos el total de tareas por el contrario importamos las tareas del fichero indicado

		fich_texto.read((char*)&tb, sizeof(tb));

		while(!fich_texto.eof() && (ntareas < KTAREAS)) { //Si el fichero no ha llegado a fin de fichero y el total de tareas no ha superado el maximo seguimos leyendo el fichero

			taux=Tarea(tb); //Hacemos la conversion
			insertarTarea(taux);
			fich_texto.read((char*)&tb, sizeof(tb));
		}

		if(fich_texto.eof() == false) cout << KMSG1 << endl;
		fich_texto.close();
	}

	return entra;
}

bool ListaTareas::leerFicheroTexto(string nombreFichero, bool importar) {

	fstream fich_texto;
	string line="";
	bool entra=true;

	fich_texto.open(nombreFichero.c_str(),ios::in);

	if(fich_texto.is_open()==false) { //Si el fichero no se ha abierto correctamente sacamos el error

		cout << KMSG4 << endl;
		entra=false;
	}
	else {

		if(!importar) ntareas=0; //Si es la opcion de leer reseteamos el total de tareas por el contrario importamos las tareas del fichero indicado

		getline(fich_texto,line);
		while((!fich_texto.eof() || line.length()!=0) && ntareas < KTAREAS) { //Si el fichero no ha llegado a fin de fichero o alguna de las lineas no esta vacia y el total de tareas no ha superado el maximo seguimos leyendo el fichero

			tareaDeCadena(line);
			line="";
			getline(fich_texto,line);
		}
		if(fich_texto.eof() == false) cout << KMSG1 << endl;
		fich_texto.close();
	}


	return entra;
}

bool ListaTareas::escribirFicheroTexto(string nombreFichero) const {

	fstream fich_texto;

	bool entra=true;

	fich_texto.open(nombreFichero.c_str(),ios::out);

	if(fich_texto.is_open()==false) {

		cout << KMSG4 << endl;
		entra=false;
	}
	else
	{
		for(int i=0; i < ntareas; i++)
		{
			fich_texto << t[i].imprimirFormatoFichero() << endl;
		}

		fich_texto.close();
	}

	return entra;
}

bool ListaTareas::escribirFicheroBinario(string nombreFichero) const {

	fstream fich_texto;
	TareaBin tb;
	bool entra=true;

	fich_texto.open(nombreFichero.c_str(),ios::out | ios::binary);

	if(fich_texto.is_open()==false) {

		cout << KMSG4 << endl;
		entra=false;
	}
	else {

		for(int i = 0; i < ntareas; i++) {

			tb=t[i].getTareaBin(); //Hacemos la conversion
			fich_texto.write((const char*)&tb, sizeof(tb));
		}
		fich_texto.close();
	}

	return entra;
}

void ListaTareas::procesarFichero(string nombreFichero, string op_par) {

	bool importar=false;

	if(op_par == "rt") {

		leerFicheroTexto(nombreFichero, importar);

	} else if(op_par == "rb") { //leer fichero binario

		leerFicheroBinario(nombreFichero, importar);

	} else if(op_par == "wt") { //escribir fichero de texto

		escribirFicheroTexto(nombreFichero);

	} else if(op_par == "wb") { //escribir fichero binario

		escribirFicheroBinario(nombreFichero);

	} else if(op_par == "it") { //importar tareas de un fichero de texto

		importar=true;
		leerFicheroTexto(nombreFichero, importar);

	} else if(op_par == "ib") { //importar tareas de un fichero binario

		importar=true;
		leerFicheroBinario(nombreFichero, importar);

	} else {

		cout << KMSG5 << endl;
	}
}

void ListaTareas::ordenarTareas() {

	Tarea tarea_aux;
	int i, j;

	for (i = 0; i < ntareas; i++) {

		for (j = 0; j < ntareas; j++) {

			if(t[i].isMenor(t[j])) {

				tarea_aux = t[j];
				t[j] = t[i];
				t[i] = tarea_aux;
			}
		}
	}
}

Tarea ListaTareas::getTarea(int ntarea)
{
    Tarea tar;

    if (ntarea>=0 && ntarea<KTAREAS)
        tar=t[ntarea];

    return tar;
}

