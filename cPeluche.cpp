#include "cPeluche.hpp"
#include "cPrenda.hpp"
#include <iostream>

cPeluche::cPeluche():cPrenda()
{
    llenado_nullptr();
    size_relleno = -1;
    precio_relleno = -1.0;
    precio_final = -1.0;
    peso_relleno = -1.0;
    peso_final = -1.0;
}

cPeluche:cPeluche(char * name, char *code, char * measure, int tam_cod, int tam_name,
				  int tam_measure,float money,/**/ char *relleno, char * relleno_unidad,
                  int tam_relleno, int tam_relleno_unidad, float money_relleno, float
                  money_final, float weight_relleno, float weight_final)
                :cPrenda(name, code, measure, tam_cod, tam_name, tam_measure, money)
{
    llenado_nullptr();

    if(llenado_peso_relleno(weight_relleno))
	{
		std::cout<<"PESO RELLENO LLENADO CON EXITO"<<std::endl;
        if(llenado_peso_final())
        {
           std::cout<<"PESO FINAL LLENADO CON EXITO"<<std::endl;
        }
        else
        {
            std::cout<<"PESO FINAL NO LLENADO CON EXITO"<<std::endl;
        }
	}
	else
	{
		std::cout<<"PESO RELLENO no LLENO"<<std::endl;
	}
	if(llenado_precio_relleno(money_relleno))
	{
		std::cout<<"PRECIO RELLENO LLENADO CON EXITO"<<std::endl;
        if(llenado_precio_final())
        {
           std::cout<<"PRECIO FINAL LLENADO CON EXITO"<<std::endl;
        }
        else
        {
            std::cout<<"PRECIO FINAL NO LLENADO CON EXITO"<<std::endl;
        }
	}
	else
	{
		std::cout<<"PRECIO RELLENO no LLENO"<<std::endl;
	}

}


void cPeluche::llenado_nullptr()
{
    tipo_relleno = nullptr;
    unidad_relleno = nullptr;
}


bool cPeluche::llenado_peso_relleno(float numero)
{
	if(numero<=0.0)
	{
		peso_relleno = -1.0;
		return false;
	}
	peso_relleno = numero;
	return true;
}

bool cPeluche::llenado_precio_relleno(float numero)
{
	if(numero<=0.0)
	{
		precio_relleno = -1.0;
		return false;
	}
	precio_relleno = numero;
	return true;
}

bool cPrenda::llenado_peso_final()
{
    float valor = cPrenda::getPeso();

    if(valor<=0.0)
	{
		std::cout<<"Peso unitario cprenda invalido"<<std::endl;
        return false;
	}
	peso_final +=valor;
	return true;
}


bool cPeluche::llenado_precio_final()
{
    float valor = cPrenda::getPrecio_unitario();

    if(valor<=0.0)
	{
		std::cout<<"Precio unitario cprenda invalido"<<std::endl;
        return false;
	}
	precio_final +=valor;
	return true;
}

char * cPeluche::getTipo_relleno()
{
    return tipo_relleno;
}

char * cPeluche::getUnidad_relleno()
{
    return unidad_relleno;
}

int cPeluche::getSize_relleno()
{
    return size_relleno;
}

float cPeluche::getPrecio_relleno()
{
    return precio_relleno;
}

float cPeluche::getPeso_relleno()
{
    return peso_relleno;
}

float cPeluche::getPeso_final()
{
    return peso_final;
}

float cPeluche::getPrecio_final()
{
    return precio_final;
}

cPeluche::~cPeluche()
{

}