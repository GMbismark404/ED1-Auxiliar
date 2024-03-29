﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
CSMemoria::CSMemoria() {
	mem = new NodoM[max_memoria];
	for (int i = 0; i < max_memoria; i++) {
		mem[i].link = i + 1;
	}
	mem[max_memoria - 1].link = nulo;
	libre = 0;
}
//-------------------------------------------------------------------------
int CSMemoria::getLibre(){
	return libre;
}
string CSMemoria::getId(direccion_mem dir){
	return mem[dir].id;
}
int CSMemoria::getDato(direccion_mem dir){
	return mem[dir].dato;
}
int CSMemoria::getLink(direccion_mem dir){
	return mem[dir].link;
}
//------------------------------------------------------------------------
direccion_mem CSMemoria::new_espacio(string cad) {
	int x = 0;
	int cant = cantidad_ids(cad); // id = "dia,mes,año" -> 3
	if (cant <= espacios_disponibles()) {
		int dir = libre;
		int d = libre;
		string *ides = vector_ids(cad);
		for (int i = 0; i < cant - 1; i++) {
			mem[d].id = ides[i];
			d = mem[d].link;
		}
		libre = mem[d].link;
		mem[d].link = nulo;
		mem[d].id = ides[cant - 1];
		return dir;
	}
	else
		cout << "MEMORIA INSUFICIENTE\n";
}

void CSMemoria::delete_espacio(direccion_mem dir) {
	int x = dir;
	while (mem[x].link != nulo) {
		x = mem[x].link;
	}
	mem[x].link = libre;
	libre = dir;
}

void CSMemoria::poner_dato(direccion_mem dir, string id, int valor) {
	if (id.substr(0, 2) == "->") // string id = "->dato" ---> "dato"
			id.erase(0, 2);
	int z = dir;
	while (z != nulo) {
		if (mem[z].id == id) { // "->dato == dato"
			mem[z].dato = valor;
			z = nulo;
		}
		else
			z = mem[z].link;
	}
}

int CSMemoria::obtener_dato(direccion_mem dir, string id) {
	if (id.substr(0, 2) == "->")
		id.erase(0, 2);
	int z = dir;
	while (z != nulo) {
		if (mem[z].id == id)
			return mem[z].dato;
		else
			z = mem[z].link;
	}
	return 0;
}

int CSMemoria::espacios_disponibles() {
	int x = libre;
	int c = 0;
	while (x != nulo) {
		c++;
		x = mem[x].link;
	}
	return c;
}

int CSMemoria::espacios_ocupados() {
	return max_memoria - espacios_disponibles();
}

bool CSMemoria::ocupado(direccion_mem dir) {
	int x = libre;
	bool c = false;
	while (x != nulo && c == false) {
		if (x == dir)
			c = true;
		x = mem[x].link;
	}
	if (c == false)
		return true;
	else
		return false;
}
//---------------------Mostrar en consola----------------------------------
void CSMemoria::mostrar_libres() {
	cout << "Dir | id | dato | link" << endl;
	cout << "----------------------" << endl;
	for (int i = 0; i < max_memoria; i++) {
		if (!ocupado(i)) {
			cout << i << "   " << mem[i].id << "   " << mem[i]
				.dato << "   " << mem[i].link << endl;
		}
	}
	cout << "----------------------" << endl;

}

void CSMemoria::mostrar_ocupados() {
	cout << "Dir | id | dato | link" << endl;
	cout << "----------------------" << endl;
	for (int i = 0; i < max_memoria; i++) {
		if (ocupado(i)) {
			cout << i << "   " << mem[i].id << "   " << mem[i]
				.dato << "   " << mem[i].link << endl;
		}
	}
	cout << "----------------------" << endl;
}
//------------------------------------------------------------------------
void CSMemoria::mostrar_memoria() {
	int espacios = 10;
	string dir1 = rellenar("DIR", 3);
	string id1 = rellenar("ID", espacios);
	string dato1 = rellenar("DATO", espacios);
	string link1 = rellenar("LINK", 4);
	string espacios7 = "       ";
	string cabecera = espacios7 + "|" + dir1 + "|" + dato1 + "|" + id1 + "|" +
		link1 + "|";

	string linea = espacios7 + "+" +
		repetir(cabecera.length() - espacios7.length() - 2, '-') + "+";
	cout << cabecera << endl;
	cout << linea << endl;
	for (int i = 0; i < max_memoria; i++) {
		string ocup;
		ocupado(i) ? ocup = "ocupado" : ocup = espacios7;
		string dir = rellenar(to_string(i), 3);
		string id = rellenar(mem[i].id, espacios);
		string dato = rellenar(to_string(mem[i].dato), espacios);
		string link = rellenar(to_string(mem[i].link), 4);
		cout << ocup << "|" << dir << "|" << dato << "|" << id << "|" << link <<
			"|" << endl;
	}
	cout << linea << endl;
	cout << espacios7 << "Libre = " << to_string(libre) << endl;
}
string CSMemoria::mostrar_memoria_str(){
	int espacios = 10;
	string dir1 = rellenar("DIR",3);
	string id1 = rellenar("ID", espacios);
	string dato1 = rellenar("DATO", espacios);
	string link1 = rellenar("LINK",4);
	string espacios7 = "       ";
	string cabecera = espacios7 + "|" + dir1 + "|" + dato1 + "|" + id1 + "|" + link1 + "|";
	string simulacion;
	string linea = espacios7 + "+" + repetir(cabecera.length() - espacios7.length() -2, '-') + "+";
	simulacion+= cabecera + "\n";
	simulacion+= linea + "\n";
	for(int i = 0; i < max_memoria; i++){
		string ocup;
		ocupado(i) ? ocup = "ocupado" : ocup = espacios7;
		string dir = rellenar(to_string(i), 3);
		string id = rellenar(mem[i].id, espacios);
		string dato = rellenar(to_string(mem[i].dato), espacios);
		string link = rellenar(to_string(mem[i].link), 4);
		simulacion+= ocup + "|" + dir + "|" + dato + "|" + id + "|" + link + "|" + "\n";
	}
	simulacion+= linea + "\n";
	simulacion+= espacios7 + "Libre = " + to_string(libre) + "\n";


	return simulacion;
}
string CSMemoria::mostrar_memoria_str_1(int a, int b){
	/*int espacios = 10;
	string dir1 = rellenar("DIR",3);
	string id1 = rellenar("ID",espacios);
	string dato1 = rellenar("DATO",espacios);
	string link1 = rellenar("LINK",4);
	string espacios7 = "	";
	string cabecera = espacios7 + "|"+dir1+"|"+dato1+"|"+id1+"|"+link1+"|";
	string simulacion;
	simulacion+=cabecera + "\n";
	simulacion += espacios7 + "+";
	simulacion += repetir(cabecera.length() - espacios7.length() - 2, '-')+"+\n";
	for(int i = 0; i< max_memoria; i++){
		string ocup;
		ocupado(i) ? ocup = "ocupado" : ocup = espacios7;
		string dir = rellenar(to_string(i),3);
		string id = rellenar(mem[i].id, espacios);
		string dato = rellenar(to_string(mem[i].dato),espacios);
		string link = rellenar(to_string(mem[i].link),4);
		simulacion+= ocup + "|" + dir + "|" + dato + "|" + id + "|" + link + "|\n";
	}
	simulacion+=espacios7 + repetir(cabecera.length() - espacios7.length() - 2, '-') + "+\n";
	simulacion+=espacios7 + "Libre = " + to_string(libre) + "\n";
	*/
	int espacios = 10;
	string dir1 = rellenar("DIR",3);
	string id1 = rellenar("ID", espacios);
	string dato1 = rellenar("DATO", espacios);
	string link1 = rellenar("LINK",4);
	string espacios7 = "       ";
	string cabecera = espacios7 + "|" + dir1 + "|" + dato1 + "|" + id1 + "|" + link1 + "|";
	string simulacion;
	string linea = espacios7 + "+" + repetir(cabecera.length() - espacios7.length() -2, '-') + "+";
	simulacion+= cabecera + "\n";
	simulacion+= linea + "\n";
	for(int i = a; i <= b; i++){
		string ocup;
		ocupado(i) ? ocup = "ocupado" : ocup = espacios7;
		string dir = rellenar(to_string(i), 3);
		string id = rellenar(mem[i].id, espacios);
		string dato = rellenar(to_string(mem[i].dato), espacios);
		string link = rellenar(to_string(mem[i].link), 4);
		simulacion+= ocup + "|" + dir + "|" + dato + "|" + id + "|" + link + "|" + "\n";
	}
	simulacion+= linea + "\n";
	simulacion+= espacios7 + "Libre = " + to_string(libre) + "\n";


	return simulacion;
}
