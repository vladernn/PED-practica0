#ifndef TVECTORPORO_H
#define TVECTORPORO_H
#include"tporo.h"
#include<stdlib.h>

class TVectorPoro{
	// Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, const TVectorPoro &);
// Dimension del vector
private:
	bool esVacio()
	{
		if(this->dimension==0 and this->datos==NULL)
		{
			return true;
		}else
		{
			return false;
		}
	}
	//copiara todo el objeto excepto el error que hay que hacer lo manualmente
	void Copia( const TVectorPoro & );
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
	TVectorPoro(const int);

	// Constructor de copia
	TVectorPoro(const TVectorPoro  &);

	// Destructor
	~TVectorPoro();

	// Sobrecarga del operador asignación
	TVectorPoro & operator=(const TVectorPoro &);

	// Sobrecarga del operador igualdad
	bool operator==(const TVectorPoro &);

	// Sobrecarga del operador desigualdad
	bool operator!=(const TVectorPoro &);

	// Sobrecarga del operador corchete (parte IZQUIERDA)
	TPoro & operator[](const int);

	// Sobrecarga del operador corchete (parte DERECHA)
	TPoro operator[](const int) const;

	// Devuelve la longitud (dimensión) del vector
	int Longitud()const {return dimension;}

	// Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
	int Cantidad()const;

	// REDIMENSIONAR el vector de TPoro
	bool Redimensionar(const int n);

	};
#endif
