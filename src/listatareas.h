//DNI 48623053H BAUDÍ CANALES, PABLO

#ifndef _listatareas_
#define _listatareas_

#include "tarea.h"

class ListaTareas {
	private:
		bool mostrarcompletadas;
		Tarea t[KTAREAS];
		int ntareas;
		int extraerNumeroComPen(string orden);
		void ordenarTareas();
	public:
		ListaTareas();
		~ListaTareas();
		void mostrar() const;
		void cambiarVista() { mostrarcompletadas=!mostrarcompletadas; };
		void modificarTarea(string orden);
		bool tareaDeCadena(string orden);
		bool insertarTarea(Tarea t);
		bool borrarTarea(int pos_tat);
		bool completarTarea (int pos_tat);
		bool leerFicheroBinario(string nombreFichero, bool importar);
		bool leerFicheroTexto(string nombreFichero, bool importar);
		bool escribirFicheroTexto(string nombreFichero) const;
		bool escribirFicheroBinario(string nombreFichero) const;
		void procesarFichero(string nombreFichero, string op_par);
		int getNTareas(){ return ntareas; };
		Tarea getTarea(int ntarea);
};

#endif
