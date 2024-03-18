//---------------------------------------------------------------------------

#ifndef CSMemoriaH
#define CSMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
					//20
typedef int direccion_mem;

const int max_memoria = 15,
				 nulo = -1;

struct NodoM {
	int dato;
	string id;
	direccion_mem link;
};

class CSMemoria {
private:
	// NodoM mem[max_memoria]; vector estatico con memoria ya creada
	NodoM *mem; // vector dinamico con memoria no creada
	direccion_mem libre;

public:
	CSMemoria();
	direccion_mem new_espacio(string cad);
	void delete_espacio(direccion_mem dir);
	void poner_dato(direccion_mem dir, string id, int valor);
	int obtener_dato(direccion_mem dir, string id);
	int espacios_disponibles();
	int espacios_ocupados();
	bool ocupado(direccion_mem dir);
	void mostrar_memoria();
	void mostrar_libres();
	void mostrar_ocupados();
	string mostrar_memoria_str();
	string mostrar_memoria_str_1(int a, int b);


	string getId(direccion_mem dir);
	int getDato(direccion_mem dir);
	int getLink(direccion_mem dir);
	int getLibre();

};

// cad = "dia,mes,a�o" -> 3
// "dia,,,,,mes,a�o" -> 6 No acepta
// "dia,mes,a�o,"
int cantidad_ids(string id) {
	int ce = 0;
	int le = id.length();
	for (int i = 0; i < le; i++) {
		char c = id[i];
		if (c == ',')
			ce++;
	}
	if (id[le - 1] != ',')
		ce++;
	return ce;
}

string *vector_ids(string ids) {
	int cantidad = cantidad_ids(ids);
	string *vect = new string[cantidad];
	int c = 0;
	string copia = ids;
	while (copia.length() > 0) {
		int pos = copia.find_first_of(",");
		pos = pos == -1 ? copia.length() : pos;
		string id = copia.substr(0, pos);
		if (c + 1 < cantidad)
			copia = copia.substr(pos + 1, copia.length() - pos - 1);
		else
			copia = "";
		vect[c] = id;
		c++;
	}
	return vect;
}

string repetir(unsigned int cantidad, char c) {
	return std::string(cantidad, c);
}

string rellenar(string s, int espacios) {
	if (espacios <= s.length()) {
		return s;
	}
	int relleno = espacios - s.length();
	return s + repetir(relleno, ' ');
}

#endif
