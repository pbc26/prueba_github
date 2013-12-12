//DNI 48623053H BAUDÍ CANALES, PABLO

#ifndef _tarea_
#define _tarea_

#include "fecha.h"

typedef struct //Estructura para ficheros binario
{
	char descripcion[KTMAX];
	bool completada;
	Fecha fe;
	char et[KTAG][KLONG];
	int numetiquetas;
} TareaBin;

class Tarea {
	private:
		string desc;
		bool completada;
		Fecha f;
		string et[KTAG];
		int numetiquetas;
	public:
		Tarea();
		Tarea(string descripcion);
		Tarea(TareaBin tb);
		Tarea(const Tarea& t);
		~Tarea();
		void mostrar() const;
		string imprimirFormatoFichero() const;
		void setEtiquetas(string orden);
		void setFecha(Fecha f) { this->f=f; };
		void setDesc(string descripcion) { desc=descripcion; };
		TareaBin getTareaBin() const;
		bool isMenor(Tarea t) const;
		bool isCompletada() const;
		void completar() { completada=!completada; };
		void vaciarEtiquetas();
};

#endif
