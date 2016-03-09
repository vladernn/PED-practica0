/*
 * TPoro.cpp
 *
 *  Created on: 17 de feb. de 2016
 *      Author: vladernn
 */
#include "tporo.h"

void TPoro::Copiar(TPoro &poroX)
{
	x=poroX.x;
	y=poroX.y;
	volumen=poroX.volumen;
	if(poroX.EsVacio()==false)
	{
		this->color=new char[strlen( poroX.color)+1];
		this->Color1(poroX.color);

	}else
	{
		color=NULL;
	}
}

TPoro::TPoro() {
	color=NULL;
	x=0;
	y=0;
	volumen=0;
}
TPoro::TPoro(int x ,int y,double vol)
{
	this->x=x;
	this->y=y;
	this->volumen=vol;
	color=NULL;
}
TPoro::TPoro(int x,int y,double vol,char* col)
{
	this->x=x;
	this->y=y;
	volumen=vol;
	//color=col;
	if(col!=NULL)
	{
		this->color=new char[strlen(col)+1];
		Color(col);

	}else
	{
		this->color=NULL;
	}
}
TPoro::TPoro(TPoro  &poroX) //Preguntar// Multiple markers
{
	Copiar(poroX);
}
TPoro::~TPoro()
{
		x=y=0;
		volumen=0;
		if(this->color!=NULL)
			delete color;
}
TPoro& TPoro::operator=(TPoro & suPoro)
{
	if(this!=&suPoro)
	{
		(*this).~TPoro();
		Copiar(suPoro);
	}
	return *this;
}
bool TPoro:: operator==(TPoro & suPoro)
{
	bool sonIguales=false;
	if(suPoro.Color()!=NULL and this->Color()!=NULL)
	{

		if(strcmp(this->Color(),suPoro.Color())==0)
		{
			sonIguales=true;
		}
	}

	if(this->PosicionX()==suPoro.PosicionX() && this->PosicionY()==suPoro.PosicionY()
			&& this->Volumen()==suPoro.Volumen() && sonIguales==true)
	{
		return(true);
	}else
	{
		return(false);
	}
}
bool TPoro::operator!=(TPoro & suPoro)
{
	if(*this==suPoro)
	{
		return(false);
	}else
	{
		return(true);
	}
}
void TPoro::Color1(char* col)
{
	char aux[strlen(col)];
	char c;
	unsigned int i=0;
	if(this->color!=NULL)
	{
		delete this->color;
	}
	if(col!=NULL)
		{
		this->color=new char[strlen(col)+1];
				//strcpy(this->color,col);
				while(i<strlen(col))
				{
					c=col[i];
					aux[i]=tolower(c);
					i++;
				}
				strcpy(this->color,aux);
			}
			else
			{
				this->color = NULL;
			}	
}
bool TPoro::EsVacio() const
{
	if(this->color==NULL and this->volumen==0 and this->x==0 and this->y==0)
	{
		return true;
	}else
	{
		return false;
	}
}
ostream & operator<<(ostream &os,const TPoro &poro)
{
	if(!poro.EsVacio())
	{
		os.setf(ios::fixed);
		os.precision( 2 );
		os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";
		if(poro.color!=NULL)
			os<<poro.color;
		else
			os<<"-";
	}
	else
		os << "()";

	return os;
}
