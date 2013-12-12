//DNI 48623053H BAUDÍ CANALES, PABLO

#include <iostream>
#include <string.h>

#include "fecha.h"

using namespace std;

Fecha::Fecha() {

	dia=0;
	mes=0;
	anyo=0;
}

Fecha::Fecha(string campo) {

	int cant=campo.length(), semaforo_fecha=0;
	string dia_i="", mes_i="", anyo_i="";

	if(campo!="") {

		if(isDia(campo)) {

			sumarDias(diferenciaDias(campo));
		}
		else {

			for(int i = 0; i < cant; i++) {

			  if(campo[i]!='/') {

				if(semaforo_fecha==0) {

				 dia_i=dia_i+campo[i];
				}
				else if(semaforo_fecha==1) {

				  mes_i=mes_i+campo[i];
				}
				else if(semaforo_fecha==2) {

				  anyo_i=anyo_i+campo[i];
				}
			  }
			  else {

				semaforo_fecha++;
			  }
			}
			  //Pasamos de string a entero
			   anyo=atoi(anyo_i.c_str());
			   mes=atoi(mes_i.c_str());
			   dia=atoi(dia_i.c_str());
		}
	}
	else {
		isVacia(); //Si la fecha no tiene valor la inicializamos dia, mes y anyo a 0
	}
}

Fecha::Fecha(int d, int m, int a) {

	dia=d;
	mes=m;
	anyo=a;
}

Fecha::~Fecha() {

}

string Fecha::imprimir() const {

	stringstream ss;
	string resultado="";

	if(dia!=0) {
		ss << dia << "/" << mes << "/" << anyo;
		resultado=ss.str();
	}
	return resultado;
}

void Fecha::setValor(string campo) {

	int cant=campo.length(), semaforo_fecha=0;
	string dia_i="", mes_i="", anyo_i="";

	if(campo!="") {

		if(isDia(campo)) {

			sumarDias(diferenciaDias(campo));
		}
		else {

			for(int i = 0; i < cant; i++) {

			  if(campo[i]!='/') {

				if(semaforo_fecha==0) {

				 dia_i=dia_i+campo[i];
				}
				else if(semaforo_fecha==1) {

				  mes_i=mes_i+campo[i];
				}
				else if(semaforo_fecha==2) {

				  anyo_i=anyo_i+campo[i];
				}
			  }
			  else {

				semaforo_fecha++;
			  }
			}
			  //Pasamos de string a entero
			   anyo=atoi(anyo_i.c_str());
			   mes=atoi(mes_i.c_str());
			   dia=atoi(dia_i.c_str());
		}
	}
	else {

		isVacia(); //Si la fecha no tiene valor la inicializamos dia, mes y anyo a 0
	}
}

void Fecha::sumarDias(int dias) {

	int dia_i= 0, mes_i = 0, anyo_i = 0;

	dia_i=dia+dias;
	mes_i=mes;
	anyo_i=anyo;

	if(KNUMDIASMES[mes_i-1] < dia_i) { //Si la fecha se pasa de rango, la arreglamos

		dia_i=dia_i-KNUMDIASMES[mes_i-1];
		mes_i=mes_i+1;
		if(mes_i  > 12) {

			mes_i=1;
			anyo_i=anyo_i+1;
		}
	}
	dia=dia_i;
	mes=mes_i;
	anyo=anyo_i;
}

bool Fecha::isMenor(Fecha f) const {

	bool entra=false;
	if(anyo < f.anyo) entra=true;
	if(anyo == f.anyo) {
		if(mes < f.mes) entra=true;
		if(mes == f.mes) {
			if(dia < f.dia) entra=true;
		}
	}
	return entra;
}

bool Fecha::isIgual(Fecha f) const {

	bool entra=false;
	if(dia==f.dia && mes==f.mes && anyo==f.anyo) entra=true;
	return entra;
}

void Fecha::setVacia() {
	dia=0;
	mes=0;
	anyo=0;
}

bool Fecha::isVacia() const {

	bool entra=false;
	if(dia==0 && mes==0 && anyo==0) entra=true;
	return entra;
}

bool Fecha::isDia(string s) {

	bool entra=false;

	if(s=="hoy" || s=="manana") {
		entra=true;
	}

	for(int i=0;i < KSEMANA; i++) {
		if(KDIAS[i]==s) entra=true;

	}

	return entra;
}

int Fecha::diferenciaDias(string campo) {

		int diadsemana = 0, incremento = 0, k = 1;

		time_t t;
		time(&t);
		tm* lt = localtime(&t);

		dia = lt->tm_mday; // dia del mes
		mes = lt->tm_mon + 1; //mes
		anyo = lt->tm_year + 1900; //años transcurridos

		diadsemana = lt->tm_wday; // dia de la semana 0 domingo a 6 sabado

		while(k <= 7) {

			if(campo=="hoy") {

				incremento=0;
			}
			else if(campo=="manana") {

				incremento=1;
			}

			else if(KDIAS[diadsemana+k]==campo) {

				incremento=k;
			}
			k++;
		}
	return incremento;
}
