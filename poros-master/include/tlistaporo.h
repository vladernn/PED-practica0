#ifndef TPORO_H_
#define TPORO_H_

class TlistaPoro{

// El elemento del nodo
private:
	TPoro e;

	// El nodo anterior

	TListaNodo *anterior;

	// El nodo siguiente

	TListaNodo *siguiente;

public:
	// Constructor por defecto

	TListaNodo ();

	// Constructor de copia

	TListaNodo (TListaNodo &);

	// Destructor

	~TListaNodo ();

	// Sobrecarga del operador asignación

	TListaNodo & operator=( TListaNodo &);
	// Para implementar la POSICIÓN a NODO de la LISTA de TPoro

	TListaNodo *pos;
	// Constructor por defecto

	TListaPosicion ();

	// Constructor de copia

	TListaPosicion (TListaPosicion &);

	// Destructor

	~TListaPosicion ();

	// Sobrecarga del operador asignación

	TListaPosicion& operator=( TListaPosicion &);
	// Sobrecarga del operador igualdad

	bool operator==( TListaPosicion &);

	// Devuelve la posición anterior

	TListaPosicion Anterior();
	// Devuelve la posición siguiente

	TListaPosicion Siguiente();

	// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario

	bool EsVacia();
};
#endif /* TPORO_H_ */
