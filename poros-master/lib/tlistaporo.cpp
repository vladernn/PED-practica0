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
	if(!this->e.EsVacio())
	{
		delete[] e;
	}
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
		this->primero=NULL;
		this->ultimo=NULL;
	}
}

TListaPoro& TListaPoro::operator =(TListaPoro & lista)
{

}
bool TListaPoro::operator ==(TListaPoro & lista)
{

}
TListaPoro TListaPoro::operator +(TListaPoro & lista)
{

}
TListaPoro TListaPoro::operator -(TlistaPoro & lista)
{

}

