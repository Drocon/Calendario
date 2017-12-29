#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <Windows.h>

//---------Constantes-----------

const int ENERO = 1;
const int FEBRERO = 2;
const int MARZO = 3;
const int ABRIL = 4;
const int MAYO = 5;
const int JUNIO = 6;
const int JULIO = 7;
const int AGOSTO = 8;
const int SEPTIEMBRE = 9;
const int OCTUBRE = 10;
const int NOVIEMBRE = 11;
const int DICIEMBRE = 12;

const int LUNES = 0;
const int MARTES = 1;
const int MIERCOLES = 2;
const int JUEVES = 3;
const int VIERNES = 4;
const int SABADO = 5;
const int DOMINGO = 6;

//	Las constantes X_BASE pueden ser modificables para hacerlo apartir de un dia. Teniendo en cuenta
//	que el DIABASE tiene que ser LUNES. Aunque para ello habría que cambiar partes de la práctica,
//	como restricciones de bucles para que cumplan su nueva definición.
const int DIABASE = 1;
const int MESBASE = ENERO;
const int ANYOBASE = 1900;

//---------------------FUNCIONES------------------------

//-------------Version 1.0-----------------

int solicitarAnyo();
/*
	Solicita un año valido para el programa.
	Entrada: dato por consola.
	Salida: año valido, dentro de los parametros.
*/

int solicitarMes();
/*
	Solicita un mes valido para el programa.
	Entrada: dato por consola.
	Salida: mes valido, dentro de los parametros.
*/

int solicitarDia(int mes, int anyo);
/*
	Solicita un día valido para el programa.
	Entrada: dato por consola.
	Salida: día valido, dentro de los parametros.
*/

long int diasTranscurridos(int dia, int mes, int anyo);
/*
	Calcula el numero total de dias que hay desde nuestra fecha base hasta la fecha introducida.
	Entrada: dia, mes y año validados anteriormente.
	Salida: total de dias en el intervalo de fechas.
*/

long int diasAnyosCompletos(int anyo);
/*
	Realiza el calculo de los dias que hay entre dos años.
	Entrada: un año validado anteriormente.
	Salida: Dias entre dos años.
*/

int diasEsteAnyo(int dia, int mes, int anyo);
/*
	Calcula los dias que han transcurrido en un año del 1/enero a la fecha dada.
	Entrada: dia, mes y año validados anteriormente.
	Salida: dias transcurridos durante ese año.
*/

int contarBisiestos(int anyoInicio, int anyoFinal);
/*
	Contar la cantidad de años bisiestos que hay en un intervalo de años.
	Entrada: año de inicio y final de un intervalo de años.
	Salida: número de años bisiestos que hay entre un intervalo de años.
*/

int diasMes(int mes, int anyo);
/*
	Busca la cantidad de días de un mes, en un año especifico.
	Entrada: mes y año validados anteriormente.
	Salida: dias del mes.
*/

bool esBisiesto(int anyo);
/*	
	Calcula si un año es bisiesto.
	Entrada: año valido.
	Salida: booleano diciendo si es bisiesto o no.
*/

int diaSemana(long int numDias);
/*
	Representación del numero del dia correspondiente.
	Entrada: numero total de dias de diferecia en las fechas.
	Salida: numero que pertenece al día.
*/

string nombreDia(int representacionDia);
/*
	Muestra el nombre del día.
	Entrada: numero que pertenece al dia.
	Salida: nombre del día de la semana.
*/

//-------------Version 2.0-----------------

int menu();
/*
	Menu de la aplicación.
	Entrada: opcion del case.
	Salida: case seleccionado.
*/

string diaDeLaSemana(int dia, int mes, int anyo);
/*
	Muestra el dia de la semana. Aparte, es una funcion para liberar codigo del main()
	Entrada: dia, mes, año validados anteriormente.
	Salida: una cadena con el nombre del día.
*/

int primerDomingoMes(int mes, int anyo);
/*
	Busca el primer domingo de un año.
	Entrada: Año y mes validados anteriormente.
	Salida: dia que fue el primer domingo del año.
*/

int domingosAnyo(int anyo);
/*
	Saca por pantalla la totalidad de los meses que hay en un año dado.
	Entrada: año validado anteriormente.
	Salida:	totalidad de los domingos de un año.
*/

bool puentes();
/*
	Abre el archivo puentes.txt y a los dias MARTES y JUEVES los pasa al archivo puentes.txt
	Entrada: abrir un archivo valido, junto con un año valido.
	Salida: boolean de si hay puente o no, mas la impresion de esos dias en un archivo.
*/

string nombreMes (int representacionMes);
/*
	Da el nombre del mes.
	Entrada: dato del mes en que estmaos.
	Salida: un string con el nombre del mes con caracteres.
*/

//-------------Version 3.0-----------------

bool puentesMejorado();
/*

	Entrada:
	Salida:
*/





//---------------------------------PROGRAMA-----------------------------

int main() {
	int mes, anyo, dia, dSemana;
	int numeroDomingos = 0;
	int diaAnyo = 0;
	int opcion = -1;
	string nDia, nMes;

	while (opcion != 0) {
		opcion = menu();
		switch (opcion) {
			case 1: 
				

				anyo = solicitarAnyo();
				mes = solicitarMes();
				dia = solicitarDia(mes, anyo);

				nDia = diaDeLaSemana(dia, mes, anyo);

				/*
				numDias = diasTranscurridos(dia, mes, anyo);
				dSemana = diaSemana(numDias);
				nDia = nombreDia(dSemana);
				*/

				cout << endl;
				cout << "-- " << nDia << " - " << dia << "/" << mes << "/" << anyo << " --" << endl;

				system("pause");
				system("cls");
				break; 
			case 2: 
				mes = 1;
				anyo = solicitarAnyo();
				//mes = solicitarMes();
										//Se puede hacer o pidiendo el mes o simplemente sacando el primer domingo del año.
				dSemana = primerDomingoMes(mes, anyo);
				nMes = nombreMes(mes);

				cout << endl;
				cout << " -El primer domingo del anyo " << anyo << " es el dia: " << dSemana << " de " << nMes << ".-" << endl;

				system("pause");
				system("cls");
				break;
			case 3: 
				anyo = solicitarAnyo();
				cout << endl;
				cout << "	Domingos de " << anyo << endl;
				cout << endl;
				numeroDomingos = domingosAnyo(anyo);

				cout << " El numero total de domingos en el anyo " << anyo << " es " << numeroDomingos << endl;
				
				system("pause");
				system("cls");
				break;
			case 4:
				puentes();

				system("pause");
				system("cls");
				break;
			case 5:
				puentesMejorado();

				system("pause");
				system("cls");
				break;
		}
	}

	return 0;
}

//---Sub.Funciones v 1.0---

int solicitarAnyo() {
	int anyo=1899;

	while (anyo < ANYOBASE) {
		cout << "Introduce anyo: ";
		cin >> anyo;
	}

	return anyo;
}

int solicitarMes() {
	int mes=0;

	while (mes<ENERO || mes>DICIEMBRE) {
		cout << "Introduce mes (numero de mes): ";
		cin >> mes;
	}
	
	return mes;
}

int solicitarDia(int mes, int anyo){
	int dia = 0, dMes=-1;

	while (dia < 1 || dia>dMes) {
		cout << "Introduce dia: ";
		cin >> dia;
		dMes = diasMes(mes, anyo);		
	}

	return dia;
}

long int diasTranscurridos(int dia, int mes, int anyo) {
	int dTranscurridos;
	int dACompl, dEAnyo;

	dACompl = diasAnyosCompletos(anyo);
	dEAnyo = diasEsteAnyo(dia, mes, anyo);
	dTranscurridos = dACompl + dEAnyo;

	return dTranscurridos;
}

long int diasAnyosCompletos(int anyo) {
	int dACompletos = 0;
	int i, dAnyo;
	bool bisiesto;

	for (i = ANYOBASE; i < anyo; i++) {
		bisiesto = esBisiesto(i);
		if (bisiesto == false) {
			dAnyo = 365;
		}
		else {
			dAnyo = 366;
		}
		dACompletos += dAnyo;
	}

	return dACompletos;
}

int diasEsteAnyo(int dia, int mes, int anyo) {
	int numDias = 0;
	int i, dMes;

	for (i = 1; i < mes; i++) {
		dMes = diasMes(i, anyo);
		numDias += dMes;
	}
	numDias += dia;

	return numDias;
}

int contarBisiesto(int anyoInicio, int anyoFinal) {
	int anyosBisiestos;
	bool aux;

	for (anyosBisiestos = 0; anyoInicio <= anyoFinal; anyoInicio++) {
		aux = esBisiesto(anyoInicio);

		if (aux = true) {
			anyosBisiestos++;
		}
	}

	return anyosBisiestos;
}

int diasMes(int mes, int anyo) {
	int diasMes;
	
	if (anyo >= ANYOBASE) {
		if (mes == ENERO || mes == MARZO || mes == MAYO || mes == JULIO || mes == AGOSTO || mes == OCTUBRE || mes == DICIEMBRE) {
			diasMes = 31;
		}
		else {
			if (mes == ABRIL || mes == JUNIO || mes == SEPTIEMBRE || mes == NOVIEMBRE) {
				diasMes = 30;
			}
			else {
				if (mes == FEBRERO && esBisiesto(anyo) == true) {
					diasMes = 29;
				}
				else {
					diasMes = 28;
				}
			}
		}
	}

	return diasMes;
}

bool esBisiesto(int anyo) {
	bool bisiesto;

	if (((anyo % 4) == 0 && (anyo % 100) != 0) || (anyo % 400) == 0) {
		bisiesto = true;
	}
	else {
		bisiesto = false;
	}

	return bisiesto;
}

int diaSemana(long int numDias) {
	int dSemana, aux;
	numDias -= 1;

	aux = numDias % 7;
	switch (aux) {
		case 0:
			dSemana = LUNES;
			break;
		case 1:
			dSemana = MARTES;
			break;
		case 2:
			dSemana = MIERCOLES;
			break;
		case 3:
			dSemana = JUEVES;
			break;
		case 4:
			dSemana = VIERNES;
			break;
		case 5:
			dSemana = SABADO;
			break;
		case 6:
			dSemana = DOMINGO;
			break;
	}

	return dSemana;
}

string nombreDia(int representacionDia) {
	string nDia;

	switch (representacionDia) {
		case 0:
			nDia = "Lunes";
			break;
		case 1: 
			nDia = "Martes";
			break;
		case 2: 
			nDia = "Miercoles";
			break;
		case 3: 
			nDia = "Jueves";
			break;
		
		case 4: 
			nDia = "Viernes";
			break;
		case 5: 
			nDia = "Sabado";
			break;
		case 6: 
			nDia = "Domingo";
			break;
	}

	return nDia;
}

//---Sub.Funciones v 2.0---

int menu() {
	int op = -1;
	int tiempo = 1000;


	while ((op < 0) || (op > 5)) {
		cout << " --- Practica 1 FP --- " << endl;
		cout << "  1 - Calcular el dia de la semana para una fecha dada." << endl;
		cout << "  2 - Obtener la fecha correspondiente al primer domingo de un anyo." << endl;
		cout << "  3 - Obtener los domingos de un anyo. " << endl;
		cout << "  4 - Obtener los posibles puentes de un anyo.	 " << endl;
		cout << "  5 - Obtener los posibles puentes de un anyo 'mejorado' ( En proceso )" << endl;
		cout << "  0 - Salir." << endl;
		cout << "  Opcion: ";
		cin >> op;

		if ((op < 0) || (op > 5)) {
			cout << "¡Opcion no valida!" << endl;
			Sleep(tiempo);
		}
		system("cls");
	}
	
	return op;
}

string diaDeLaSemana(int dia, int mes, int anyo) {
	string diaDeSemana;
	int diasTrans;
	int diaSem;

	diasTrans = diasTranscurridos(dia, mes, anyo);
	diaSem = diaSemana(diasTrans);
	diaDeSemana = nombreDia(diaSem);

	return diaDeSemana;
}

int primerDomingoMes(int mes, int anyo) {
	int numDias, dSemana, i, dMes;
	int diaAnyo = 0;
	int nDias = 0;
	
	numDias = diasAnyosCompletos(anyo);
	for (i = 1; i < mes; i++) {
		dMes = diasMes(i, anyo);
		nDias += dMes;
	}

	numDias += nDias;
	numDias += 1;
	dSemana = diaSemana(numDias);

	while (dSemana <= DOMINGO) {
		dSemana++;
		diaAnyo++;
	}

	return diaAnyo;
}

int domingosAnyo(int anyo) {
	int diaDomingo = 0;
	int numeroDomingos = 0;
	int tiempo = 1000;
	int dSemana, mes, dMes;
	int nDias = 0;
	string nMes;

	for (mes = 1; mes <= DICIEMBRE; mes++) {
		dSemana = primerDomingoMes(mes, anyo);
		nMes = nombreMes(mes);
		dMes = diasMes(mes, anyo);
		cout << "-----------------" << endl;
		while (dSemana <= dMes ) {
			cout << dSemana << " de " << nMes<< endl;
			cout << "   ---   " << endl;
			dSemana += 7;
			numeroDomingos++;
		}

		Sleep(tiempo);			//El tiempo que tarda en pasar es modificable en la propia subfuncion.
	}

	return numeroDomingos;
}

bool puentes() {
	bool haberPuente;
	ifstream archivoFiestas;
	ofstream archivoPuentes;
	int contador = 1;
	int anyo, mes=1, dia=1, numeroDias, dSemana;
	string nomDia, nomMes;

	archivoFiestas.open("fiestas.txt");
	archivoPuentes.open("puentes.txt");
	if (archivoFiestas.is_open()) {
		archivoFiestas >> anyo;
		archivoPuentes << anyo << endl;
		cout << "-----Puentes de " << anyo << "-----" << endl;
		cout << endl;

		while (dia != 0 && mes != 0) {
			archivoFiestas >> dia;
			archivoFiestas >> mes;

			if (dia != 0 && mes != 0) {
				numeroDias = diasTranscurridos(dia, mes, anyo);
				dSemana = diaSemana(numeroDias);

				if (dSemana == MARTES || dSemana == JUEVES) {
					nomDia = nombreDia(dSemana);
					nomMes = nombreMes(mes);
					cout << " " <<  contador << ".- " << nomDia << " " << dia << " de " << nomMes << endl;
					archivoPuentes << dia << " " << mes << " " << nomDia << endl;
					contador++;
					haberPuente = true;
				}
				else{
					haberPuente = false;
				}
			}
		}

	archivoPuentes << "0 0 XXX" << endl;

	archivoFiestas.close();
	archivoPuentes.close();
	}
	else {
		cout << "No exite el archivo 'fiestas.txt' o 'puentes.txt'" << endl;
	}	
	
	return haberPuente;
}

string nombreMes(int representacionMes) {
	string nDia;

	switch (representacionMes) {
	case 1:
		nDia = "Enero";
		break;
	case 2:
		nDia = "Febrero";
		break;
	case 3:
		nDia = "Marzo";
		break;
	case 4:
		nDia = "Abril";
		break;
	case 5:
		nDia = "Mayo";
		break;
	case 6:
		nDia = "Junio";
		break;
	case 7:
		nDia = "Julio";
		break;
	case 8:
		nDia = "Agosto";
		break;
	case 9:
		nDia = "Septiembre";
		break;
	case 10:
		nDia = "Octubre";
		break;
	case 11:
		nDia = "Noviembre";
		break;
	case 12:
		nDia = "Diciembre";
		break;

	}

	return nDia;
}

//---Sub.Funciones v 3.0---

bool puentesMejorado() {
	bool haberPuente;
	ifstream archivoFiestas;
	ofstream archivoPuentesMejorado;
	int contador = 1;
	int anyo, numeroDias, dSemana, aux;
	int numerDias, diaDeSemana;
	int mes = 1;
	int dia = 1;
	int auxFiestasDia, auxFiestasMes;
	string nomDia, nomMes;

	archivoFiestas.open("fiestas.txt");
	archivoPuentesMejorado.open("puentesMejorado.txt");
	if (archivoFiestas.is_open()) {
		archivoFiestas >> anyo;
		archivoPuentesMejorado << anyo << endl;
		cout << "-----Puentes de " << anyo << "-----" << endl;
		cout << endl;

		while (dia != 0 && mes != 0) {
			archivoFiestas >> dia;
			archivoFiestas >> mes;
			auxFiestasDia = dia;
			aux = auxFiestasDia + 1;
			auxFiestasMes = mes;

			if (dia != 0 && mes != 0) {
				numeroDias = diasTranscurridos(dia, mes, anyo);
				dSemana = diaSemana(numeroDias);

				if (dSemana == LUNES || dSemana == JUEVES) {			
					archivoFiestas >> dia;
					archivoFiestas >> mes;

					if (aux == dia && auxFiestasMes == mes ) {
						haberPuente = false;
					}
					else {
						if (dSemana == JUEVES) {
							nomDia = nombreDia(dSemana);
							nomMes = nombreMes(auxFiestasMes);
							cout << " " << contador << ".- " << nomDia << " " << auxFiestasDia << " de " << nomMes << endl;
							archivoPuentesMejorado << auxFiestasDia << " " << auxFiestasMes << " " << nomDia << endl;
							contador++;
							haberPuente = true;
						}
					}
				}
				else {
					if (dSemana == MARTES || dSemana == JUEVES) {
						nomDia = nombreDia(dSemana);
						nomMes = nombreMes(mes);
						cout << " " << contador << ".- " << nomDia << " " << dia << " de " << nomMes << endl;
						archivoPuentesMejorado << dia << " " << mes << " " << nomDia << endl;
						contador++;
						haberPuente = true;
					}
					haberPuente = false;
				}
			}
		}

		archivoPuentesMejorado << "0 0 XXX" << endl;

		archivoFiestas.close();
		archivoPuentesMejorado.close();
	}
	else {
		cout << "No exite el archivo 'fiestas.txt' o 'puentes.txt'" << endl;
	}

	return haberPuente;
}
