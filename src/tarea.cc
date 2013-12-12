//DNI 48623053H BAUDÍ CANALES, PABLO

#include "fecha.h"
#include "tarea.h"

using namespace std;

Tarea::Tarea() {
	desc="";
	completada=false;
	vaciarEtiquetas();
}

Tarea::Tarea(string descripcion) {
	desc=descripcion;
	completada=false;
	vaciarEtiquetas();
}

Tarea::Tarea(TareaBin tb) { //Conversion de binario a texto/programa

	completada=tb.completada;
	numetiquetas=tb.numetiquetas;
	f=tb.fe;
	desc=tb.descripcion;

	for(int i=0;i < numetiquetas; i++)
	{
		et[i]=tb.et[i];
	}
}

Tarea::Tarea(const Tarea& t) {

	f=t.f;
	numetiquetas=t.numetiquetas;
	desc=t.desc;
	completada=t.completada;

	for(int i=0; i < numetiquetas; i++) {
		et[i]=t.et[i];
	}
}

Tarea::~Tarea() {

}

void Tarea::mostrar() const {

	cout << desc << KSEPARADOR << f.imprimir() << KSEPARADOR;
	for(int i=0; i < numetiquetas; i++) cout << et[i] << " ";
}

string Tarea::imprimirFormatoFichero() const {

	string aux;

	aux='\"' + desc + '\"';

	if(!f.isVacia()) {
		aux=aux + ' ' + f.imprimir();
	}

	if(numetiquetas > 0) {
		aux=aux + ' ' + 'q';

		for(int i=0; i < numetiquetas; i++) {
			aux=aux + ' ' + et[i];
		}
	}

	return aux;
}

void Tarea::setEtiquetas(string orden) {

	int cant = orden.length();
	int cont_pos_tag=0;
	string op_aux_tag[KLONG] = "";
	bool entra_tag_con=true;

	if(orden[0]!=' ') numetiquetas++;

	for(int i = 0; i < cant; i++) {

		if(entra_tag_con==true) {

			if(numetiquetas-1 < KTAG) {

				if(orden[i]==' ') {

					numetiquetas++;
					cont_pos_tag=0;
				}
				else if(orden[i]!=' ') {

					if(cont_pos_tag < KLONG) { //La longitud de la etiqueta que no pase de KLONG

						op_aux_tag[numetiquetas-1]=op_aux_tag[numetiquetas-1] + orden[i];
						cont_pos_tag++;
					}
				}
			  }
			  else {

				  if(numetiquetas > KTAG) numetiquetas=KTAG; //Si la cantidad de etiquetas supero el maximo permitido restauramos el total de etiquetas al maximo
				  entra_tag_con=false;
				  cout << KMSG3 << endl;
			  }
		}
	}

	for(int i=0;i < numetiquetas; i++) {
		et[i]=op_aux_tag[i];
	}
}

TareaBin Tarea::getTareaBin() const { //conversion de texto a binario

	TareaBin tb;

	tb.fe=f;
	tb.completada=completada;
	tb.numetiquetas=numetiquetas;
	strncpy(tb.descripcion,desc.c_str(),KTMAX);
	tb.descripcion[KTMAX-1]='\0';

	for(int i=0; i < numetiquetas; i++)
	{
		strncpy(tb.et[i],et[i].c_str(),KLONG);
		tb.et[i][KLONG]='\0';
	}

	return tb;
}

bool Tarea::isMenor(Tarea t) const {

	bool entra=false;

	if(!f.isVacia() && !t.f.isVacia()) { //Si no son vacias, ordenamos si fecha es menor
		if(f.isMenor(t.f)) { // Si fecha es menor ordenamos
			entra=true;
		}
	}

	if (f.isIgual(t.f)) { //Si la fecha es igual analizamos las descripciones
		if(desc < t.desc) {
			entra=true;
		}
	}

	if (f.isVacia() && t.f.isVacia()) { //Si las fechas estan vacias analizamos las descripciones
		if(desc < t.desc) {
			entra=true;
		}
	}

	if(!f.isVacia() && t.f.isVacia()) {
		entra=true;
	}

	return entra;
}

bool Tarea::isCompletada() const {

	bool entra=false;
	if(completada==true) entra=true;
	return entra;
}

void Tarea::vaciarEtiquetas() {
	numetiquetas=0;
	for(int i=0;i<KTAG;i++) et[i]="";
}
