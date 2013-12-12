//DNI 48623053H BAUDÍ CANALES, PABLO

#ifndef _fecha_
#define _fecha_

#include "utilidades.h"

const string KDIAS[]={"domingo","lunes","martes","miercoles","jueves","viernes","sabado","domingo","lunes","martes","miercoles","jueves","viernes","sabado"}; //Para sacar la diferencia de dias
const int KNUMDIASMES[]={31,28,31,30,31,30,31,31,30,31,30,31};

class Fecha {
	private:
		int dia;
		int mes;
		int anyo;
		int diferenciaDias(string campo);

	public:
		Fecha();
		Fecha(string campo);
		Fecha(int d, int m, int a);
		~Fecha();
		string imprimir() const;
		void setValor(string campo);
		void sumarDias(int dias);
		bool isMenor(Fecha f) const;
		bool isIgual(Fecha f) const;
		void setVacia();
		bool isVacia() const;
		static bool isDia(string s);
};

#endif
