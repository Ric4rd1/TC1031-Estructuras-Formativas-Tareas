/*
 * funciones.h
 *      Author: Ricard Catalá Garfias
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

class Funciones {
	public: 

	// funcion O(n), comportamiento lineal uso de ciclo for que 
	//depende directamente de n
	unsigned int sumaIterativa(int n) {
		unsigned int sum = 0;
		for (int i = 0; i <= n; i++) {
			sum += i;
		}
		return sum;
	}

	// funcion recursiva O(n), comportamiento lineal que 
	//depende directamente de n.
	unsigned int sumaRecursiva(int n) {
		if (n == 0) {
			return 0;
		} else {
			return n + sumaRecursiva(n - 1);
		}
	}

	// funcion O(1), comportamiento constante que no depende de n.
	//Consiste en operaciones de multiplicación y división constantes, 
	//independientes de n. Por lo tanto, su complejidad temporal es constante
	unsigned int sumaDirecta(int n) {
		return (n * (n + 1)) / 2;
	}

};
#endif /* FUNCTIONS_H_ */
