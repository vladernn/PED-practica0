#ifndef TVECTORPORO_H
#define TVECTORPORO_H
#include"tporo.h"

class TVectorPoro{
// Dimension del vector
private:
	void Copia(TVectorPoro &);
	// dimension del vector
	int dimension;

	// Datos del vector
	TPoro *datos;

	// Para cuando haya error en el operator[]
	TPoro error;
public:
	// Constructor por defecto
	TVectorPoro();

	// Constructor a partir de una dimensión
	TVectorPoro(int);

	// Constructor de copia
	TVectorPoro(TVectorPoro &);

	// Destructor
	~TVectorPoro();

	// Sobrecarga del operador asignación
	TVectorPoro & operator=(TVectorPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(TVectorPoro &);

	// Sobrecarga del operador desigualdad
	bool operator!=(TVectorPoro &);

	// Sobrecarga del operador corchete (parte IZQUIERDA)
	TPoro & operator[](int);

	// Sobrecarga del operador corchete (parte DERECHA)
	TPoro operator[](int) const;

	// Devuelve la longitud (dimensión) del vector
	int Longitud();

	// Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
	int Cantidad();

	// REDIMENSIONAR el vector de TPoro
	bool Redimensionar(int);

	// Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, TVectorPoro &);
	};
#endif