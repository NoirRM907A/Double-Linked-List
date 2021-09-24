#include<iostream>
#include"ListaDobleEnlazada.h"
/*Implemente los métodos 
  Insertar y Eliminar de una lista
  doblemente enlazada. Una lista doblemente enlazada
  tiene dos punteros: uno al nodo siguiente y otro al nodo anterior.
*/
int main() {
	ListaDobleEnlazada lde;
	std::cout << "Agregando valores: \n";
    lde.insertar(2);
	lde.insertar(3);
	lde.insertar(5);
	lde.insertar(78);
	lde.mostrar();
	std::cout << "\n";
	std::cout << "Eliminando el ultimo valor de la lista: \n";
	lde.eliminarNodoUltimo();
	lde.mostrar();
	std::cout << "\n";
	std::cout << "Eliminando la posicion 2 de la lista\n";
	lde.eliminar(2);
	lde.mostrar();
	std::cout << "\n";
	std::cout << "Eliminando el primer valor de la lista: \n";
	lde.eliminarNodoPrimero();
	lde.mostrar();
	lde.~ListaDobleEnlazada();
	return 0;
}