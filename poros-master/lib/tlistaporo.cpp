#include<iostream>
#include"tlistaporo.h"
using namespace std;

void TListaNodo::Copiar(const TListaNodo & miNodo)
{
	this->e=miNodo.e;
	this->anterior=NULL;
	this->siguiente=NULL;
}

TListaNodo::TListaNodo():e()
{
		this->anterior=NULL;
		this->siguiente=NULL;
}
TListaNodo::TListaNodo(const TListaNodo & miNodo):e(miNodo.e)
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
	if(this!=NULL)
	{
		this->anterior=NULL;
		this->siguiente=NULL;
	}
}

TListaPosicion::TListaPosicion()
{
	this->pos=NULL;
}
TListaPosicion::TListaPosicion(TListaPosicion & posicion)
{
	if(posicion.pos!=NULL)
	{
		this->pos=posicion.pos;
	}

}
TListaPosicion::~TListaPosicion()
{
	if(this!=NULL)
	{
		this->pos=NULL;
	}
}
TListaPosicion& TListaPosicion::operator =(const TListaPosicion & pos)
{
	if(this!=&pos)
	{
		this->pos=pos.pos;
	}
	return *this;
}
bool TListaPosicion::operator ==(const TListaPosicion & pos)const
{
	if(pos.pos==this->pos)
	{
		return true;
	}else
	{
		return false;
	}
}
bool TListaPosicion::EsVacia()const
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
TListaPosicion TListaPosicion::Siguiente() const
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
	if(miLista.EsVacia()==false)
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
			delete aux1;
		}
		this->primero=NULL;
		this->ultimo=NULL;
	}
}

TListaPoro& TListaPoro::operator=(TListaPoro & lista)
{
	TListaNodo *nodo;
	if(this!=&lista)
	{
		this->~TListaPoro();
		nodo=lista.primero;
		while(nodo!=NULL)
		{
			this->Insertar(nodo->e);
			nodo=nodo->siguiente;
		}
	}
	return *this;
	//return TListaPoro();
}
bool TListaPoro::operator ==(TListaPoro & lista)const
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
	//return TListaPoro();
}
TListaPoro TListaPoro::operator-(TListaPoro &)
{

	//return TListaPoro();
}
bool TListaPoro::EsVacia()const
{
	if(this->primero==NULL)
	{
		return true;
	}else
	{
		return false;
	}
}
bool TListaPoro::Insertar(TPoro &poro)
{	TListaNodo *aux0; //creo un puntero a un nodo
	TListaNodo *nodo=new TListaNodo();  //creo un nodo
	nodo->e=poro; // meto el poro dentro del nodo
	bool encontrado=false;
	if(this->EsVacia()==false)
	{
		if(this->Buscar(poro)==false)
		{
			aux0=this->primero;
			while(aux0!=NULL and encontrado==false)
			{
				if(this->primero->e.Volumen() > poro.Volumen())
				{
					nodo->siguiente=aux0;
					aux0->anterior=nodo;
					this->primero=nodo;
					this->ultimo=aux0;
					//aux0->siguiente=nodo;
					//nodo->anterior=aux0;
					//nodo->siguiente->anterior=nodo;
					encontrado=true;
				}else if(this->ultimo->e.Volumen() <= poro.Volumen())
				{
					if(aux0==this->ultimo)
					{
						nodo->anterior=aux0;
						aux0->siguiente=nodo;
						this->ultimo=nodo;
						encontrado=true;
					}
				}else if(aux0->e.Volumen()<poro.Volumen()and aux0->siguiente->e.Volumen() > poro.Volumen())
				{
					nodo->anterior=this->ultimo;
					this->ultimo->siguiente=nodo;
					encontrado=true;
				}else if(aux0->e.Volumen()==poro.Volumen())
				{
					nodo->siguiente=aux0->siguiente;
					aux0->siguiente=nodo;
					nodo->anterior=aux0;
					nodo->siguiente->anterior=nodo;
					encontrado=true;
				}
				aux0=aux0->siguiente;
			}
		}else
		{
			encontrado=false;
		}
	}else
	{
		aux0=nodo;
		this->primero=aux0;
		this->ultimo=aux0;
		encontrado=true;
	}
	return encontrado;
}
bool TListaPoro::Borrar(TPoro &poro)
{
		return true;
}
bool TListaPoro::Borrar(TListaPosicion &poro)
{
		return true;
}
TPoro TListaPoro::Obtener(const TListaPosicion &posicion)const
{
	if(posicion.EsVacia()==false)
	{
		return posicion.pos->e;
	}

	return TPoro();
}
bool TListaPoro::Buscar(const TPoro &nodo)const
{
	TListaNodo *aux0;
	TListaNodo *aux1;
	if(this->EsVacia()==false)
	{
			aux0=this->primero;
			while(aux0!=NULL)
			{
				if(aux0->e==nodo)
				{
					return true;
				}
				aux0=aux0->siguiente;
			}
			return false;
	}else
	{
		return false;
	}
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
TListaPosicion TListaPoro::Primera()const
{
	TListaPosicion aux;
	if(this->EsVacia())
	{
		return aux;
	}else
	{
		aux.pos=this->primero;
		return aux;
	}
}
TListaPosicion TListaPoro::Ultima()const
{
	TListaPosicion aux;
	if(this->EsVacia())
	{
		return aux;
	}else
	{
		aux.pos=this->ultimo;
		return aux;
	}
}
TListaPoro TListaPoro::ExtraerRango (int n1, int n2)
{
	//return TListaPoro();
}

ostream& operator<<(ostream &os, const TListaPoro &p)
{
	TListaPosicion pos0;

	os<<"(";
	for(pos0 = p.Primera();
			pos0.EsVacia()==false;
				pos0=pos0.Siguiente())
	{
		if(!(pos0==p.Ultima()))
		{
			os<<p.Obtener(pos0);
			os<<" ";
		}else
		{
			os<<p.Obtener(pos0);
		}
	}
	os<<")";
	return os;

}
