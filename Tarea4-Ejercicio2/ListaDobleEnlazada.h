#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include<iostream>
class ListaDobleEnlazada {
private:
	struct Nodo{
		int dato;
		struct Nodo* siguiente;
		struct Nodo* anterior;
	    Nodo(int valor = 0, Nodo* next = nullptr, Nodo* prev = nullptr):	
			dato{ valor }, siguiente{ next }, anterior{ prev } {}
	};
	struct Nodo* primero = nullptr;
	struct Nodo* ultimo = nullptr;
public:
	ListaDobleEnlazada();
	~ListaDobleEnlazada();
	void insertar(int);
	void eliminar(int);
	void borrar();
	void mostrar();

	void eliminarNodoPrimero();
	void eliminarNodoUltimo();
};


#endif // !LISTADOBLEENLAZADA_H
