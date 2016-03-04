#include<iostream>
#include"tvectorporo.h"
using namespace std;

void TVectorPoro::Copia(TVectorPoro &origen)
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
TVectorPoro::TVectorPoro(TVectorPoro cons &origen):error(origen.error) //Preguntar Mutiple markers
{
	Copia(origen);
}
TVectorPoro::~TVectorPoro()
{
	this->datos=NULL;
	this->dimension=0;
	this->error;
}