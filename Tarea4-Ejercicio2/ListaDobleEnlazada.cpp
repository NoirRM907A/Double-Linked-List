#include"ListaDobleEnlazada.h"

ListaDobleEnlazada::ListaDobleEnlazada() { primero = nullptr; ultimo = nullptr; }

ListaDobleEnlazada::~ListaDobleEnlazada() { borrar(); }


void ListaDobleEnlazada::insertar(int valor) {
	Nodo* nodo = new Nodo;
	nodo->dato = valor;

	if (primero == nullptr) {
		primero = nodo;
		ultimo = primero;
		return;
	}

	if (nodo->dato < primero->dato) {
		nodo->siguiente = primero;
		primero = nodo;
		return;
	}

	if (nodo->dato >= ultimo->dato) {
		nodo->anterior = ultimo;
		ultimo->siguiente = nodo;
		ultimo = nodo;
		return;
	}

	Nodo* nodo2 = primero;
	while (nodo2 && (nodo->dato >= nodo2->dato)) {
		nodo2 = nodo2->siguiente;
	}
	if (nodo2) {
		nodo->siguiente = nodo2;
		nodo->anterior = nodo2->anterior;
		nodo2->anterior->siguiente = nodo;
		nodo2->anterior = nodo;
		return;
	}
	return;
}



void ListaDobleEnlazada::eliminar(int posicion) {
	struct Nodo* actual = primero;
	for (int i = 1; i < posicion && actual != nullptr; i++) {
		actual = actual->siguiente;
		if (posicion == 1) {
			eliminarNodoPrimero();
		}else
			if (actual == ultimo) {
				eliminarNodoUltimo();
			}else
				if (actual != nullptr) {
					actual->anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = actual->anterior;
					free(actual);
				}
				else {
					std::cout << "La posicion es invalida\n";
				}
	
	}
}

void ListaDobleEnlazada::borrar() {
	Nodo* eliminar = primero;
	while (primero != nullptr) {
		primero = primero->siguiente;
		eliminar->siguiente = nullptr;
	}
	delete eliminar;
}

void ListaDobleEnlazada::mostrar() {
	struct Nodo* temp;
	temp = primero;
	while (temp != nullptr) {
		std::cout << temp->dato << " ";
		temp = temp->siguiente;
	}

}

void ListaDobleEnlazada::eliminarNodoPrimero() {
	struct Nodo* eliminar;
	if (primero != nullptr) {
		eliminar = primero;
		primero = primero->siguiente;
		primero->anterior = nullptr;
		free(eliminar);
	}
	else {
		std::cout << "No Hay Elementos en la Lista que Eliminar\n";
	}
}

void ListaDobleEnlazada::eliminarNodoUltimo() {
	struct Nodo* eliminar;
	if (ultimo != nullptr) {
		eliminar = ultimo;
		ultimo = ultimo->anterior;
		ultimo->siguiente = nullptr;
		free(eliminar);
	}
	else {
		std::cout << "No Hay Elementos en la Lista que Eliminar\n";
	}
}