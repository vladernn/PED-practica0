#include<iostream>
#include"tlistaporo.h"
using namespace std;

void TListaNodo::Copiar(const TListaNodo & miNodo)
{
	this->e=miNodo.e;
	this->anterior=NULL;
	this->siguiente=NULL;
}

TListaNodo::TListaNodo()
{
		this->e=NULL;
		this->anterior=NULL;
		this->siguiente=NULL;
}
TListaNodo::TListaNodo(const TListaNodo & miNodo)
{
	Copiar(miNodo);
}
TListaNodo& TListaNodo::operator = (const TListaNodo & miNodo)
{
	Copiar(miNodo);
	return *this;
}
TListaNodo::~TListaNodo()
{
	this->anterior=NULL;
	this->siguiente=NULL;
}

TListaPosicion::TListaPosicion()
{
	this->pos=NULL;
}
TListaPosicion::TListaPosicion(const TListaPosicion & posicion)
{
	this->pos=posicion;
}
TListaPosicion& TListaPosicion::operator =(TListaPosicion & pos)
{
	return pos;
}
bool TListaPosicion::operator ==(TListaPosicion & pos)
{
	if(pos.pos==this->pos)
	{
		return true;
	}else
	{
		return false;
	}
}
bool TListaPosicion::EsVacia()
{
	if(this->pos==NULL)
	{
		return true;
	}else
	{
		return false;
	}
}
TListaPosicion TListaPosicion::Anterior()
{
	TListaPosicion aux;
	if(pos!=NULL)
	{
		aux.pos=pos->anterior;
	}
	return aux;
}
TListaPosicion TListaPosicion::Siguiente()
{
	TListaPosicion aux;
	if(pos!=NULL)
	{
		aux.pos=pos->siguiente;
	}
	return aux;
}

TListaPoro::TListaPoro()
{
	this->primero=NULL;
	this->ultimo=NULL;
}
TListaPoro::TListaPoro(TListaPoro & miLista)
{
	if(miLista!=NULL)
	{
		this->primero=miLista.primero;
		this->ultimo=miLista.ultimo;
	}
}
TListaPoro::~TListaPoro()
{
	if(this!=NULL)
	{
		TListaNodo *aux0;
		TListaNodo *aux1;
		aux0=this->primero;
		while(aux0!=NULL)
		{
			aux1=aux0;
			aux0=aux0->siguiente;
			delete [] aux1;
		}
		this->primero=NULL;
		this->ultimo=NULL;
	}
}

TListaPoro& TListaPoro::operator=(TListaPoro & lista)
{
	return TListaPoro();
}
bool TListaPoro::operator ==(TListaPoro & lista)
{
	TListaNodo *aux0;
	TListaNodo *aux1;
	aux0=this->primero;
	aux1=lista.primero;
	int a=this->Longitud(),b=lista.Longitud();
	bool devuelvo;
	if(a!=b)
	{
		devuelvo=false;
	}else
	{
		devuelvo=true;
		while(aux0!=NULL and devuelvo==true)
		{
			if(aux0->e==aux1->e)
			{
				aux0=aux0->siguiente;
				aux1=aux1->siguiente;
			}else
			{
				devuelvo=false;
			}
		}
	}
	return devuelvo;
}
TListaPoro TListaPoro::operator +(TListaPoro & lista)
{
	return TListaPoro();
}
TListaPoro TListaPoro::operator-(TListaPoro &)
{

	return TListaPoro();
}
bool TListaPoro::EsVacia()
{
	return true;
}
bool TListaPoro::Insertar(TPoro &poro)
{
	return true;
}
bool TListaPoro::Borrar(TPoro &poro)
{
		return true;
}
bool TListaPoro::Borrar(TListaPosicion &poro)
{
		return true;
}
TPoro TListaPoro::Obtener(TListaPosicion &posicion)
{
	return TPoro();
}
bool TListaPoro::Buscar(TPoro &)
{
	return true;
}
int TListaPoro::Longitud()const
{
	TListaNodo *aux0;
	aux0=this->primero;
	int cont=0;
	while(aux0!=NULL)
	{
		aux0=aux0->siguiente;
		cont++;
	}
	return cont;
}
TListaPosicion TListaPoro::Primera()
{
	return TListaPosicion();
}
TListaPosicion TListaPoro::Ultima()
{
	return TListaPosicion();
}
TListaPoro TListaPoro::ExtraerRango (int n1, int n2)
{
	return TListaPoro();
}
