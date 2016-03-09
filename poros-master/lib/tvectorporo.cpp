#include<iostream>
#include"tvectorporo.h"
using namespace std;

void TVectorPoro::Copia(const TVectorPoro &origen)
{
	this->dimension=origen.dimension;
	for(int i=0;i<origen.dimension;i++)
	{
		this->datos[i]=origen.datos[i];
	}
	//this->error=origen.error;
}
TVectorPoro::TVectorPoro():error()
{
	this->dimension=0;
	this->datos=NULL;
}

TVectorPoro::TVectorPoro(int x):error()
{
	if(x<=0)
	{
		this->dimension=0;
		this->datos=NULL;
	}else
	{
		this->dimension=x;
		this->datos=NULL;
	}
}
TVectorPoro::TVectorPoro(TVectorPoro const &origen)
{
	Copia(origen);
}
TVectorPoro::~TVectorPoro()
{
	this->dimension=0;
	delete[] this->datos;
}
TVectorPoro& TVectorPoro::operator=(TVectorPoro &suVector)
{
	if(this != &suVector)
	{
		(*this).~TVectorPoro();
		Copia(suVector);
		this->error=suVector.error;
	}
	return *this;
}
bool TVectorPoro::operator ==(TVectorPoro &suVector)
{
	if(this->dimension==suVector.dimension and this->error==suVector.error)
	{
		for(int i=0;i<suVector.dimension;i++)
		{
			if(this->error!=suVector.error)
			{
				return false;
			}
		}
		return true;
	}else
	{
		return false;
	}
}

bool TVectorPoro::operator !=(TVectorPoro &suVector)
{
	if(this==&suVector)
	{
		return false;
	}else
	{
		return true;
	}
}
// Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro& TVectorPoro::operator [](int pos)
{
	if(this->dimension >=pos and pos>0)
	{
		return datos[pos-1];
	}else
	{
		return error;
	}
}
// Sobrecarga del operador corchete (parte DERECHA)
TPoro TVectorPoro::operator [](int pos)const
{
	if(this->dimension >=pos and pos > 0)
	{
		return datos[pos-1];
	}else
	{
		return error;
	}

}

int TVectorPoro::Cantidad()
{
	int cant=0;
	for(int i=0;i<this->dimension;i++)
	{
		if(!this->datos[i].EsVacio())
		{
			cant++;
		}
	}
	return cant;
}

bool TVectorPoro::Redimensionar(int n)
{
	bool devolver =false;
	TPoro *auxiliar;

	if(n>0 and n!=this->dimension)
	{
		auxiliar= new TPoro[n];
		this->dimension=n;
		for(int i=0;i<n;i++)
		{
			//this->datos[i].Copiar(auxiliar.datos[i]);
			auxiliar[i]=this->datos[i];
		}
		delete[] this->datos;
		this->datos=auxiliar;
		devolver=true;
	}
	return devolver;
}

ostream & operator<<(ostream &os,TVectorPoro &vector)
{
	if(vector.esVacio())
	{
		os<<"[]";
	}else
	{
		os<<"[";
		for(int i=0;i<vector.dimension;i++)
		{
			os<<vector.datos[i];
		}
		os<<"]";
	}
	return os;
}
