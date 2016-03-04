#include<iostream>
#include"tvectorporo.h"
using namespace std;

/*friend ostream & operator<<(ostream &, TVectorPoro &)
{

}*/

void TVectorPoro::Copia(TVectorPoro const &origen)
{
	this->dimension=origen.dimension;
	this->datos=origen.datos;
	this->error=origen.error;
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
TVectorPoro::TVectorPoro(TVectorPoro const &origen):error(origen.error)
{
	Copia(origen);
}
TVectorPoro::~TVectorPoro()
{
	this->datos=NULL;
	this->dimension=0;
	this->error;
}
TVectorPoro& TVectorPoro::operator=(TVectorPoro &suVector)
{
	if(this!=suVector)
	{
		(*this).~TVectorPoro();
		Copia(suVector);
		this->error;
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
	if(this==suVector)
	{
		return false;
	}else
	{
		return true;
	}
}

TPoro& TVectorPoro::operator [](int pos)
{
	if(this->dimension >=pos and pos>0)
	{
		return this->datos[pos-1];
	}else
	{
		return error;
	}
}
TPoro TVectorPoro::operator [](int pos)const
{
	if(this->dimension >=pos and pos > 0)
	{
		return this->datos[pos-1];
	}else
	{
		return this->error;
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
	if(this->dimension==n or n<=0)
	{
		return false;
	}else if(n < this->dimension){
		for(int i=0;i<this->dimension;i++)
		{
			if(i<n)
			{
				//this->datos[i].Copiar();
			}
		}
	}else
	{
		this->dimension=n;return true;}
}
