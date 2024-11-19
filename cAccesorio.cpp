#include "cAccesorio.hpp"
#include "cPrenda.hpp"
#include <iostream>

cAccesorio::cAccesorio() : cPrenda()
{
	cPrenda::fecha.actualizarFecha();
	llenado_nullptr();
	size_base = -1;
	precio_base = -1.0;
	precio_final = -1.0;
}

cAccesorio::cAccesorio(char * name, char *code, char * measure, int tam_cod, int tam_name,
                    int tam_measure,float money, char *base_material, int tam_base, 
					float money_base, float money_final) 
			: cPrenda(name, code, measure, tam_cod,tam_name, tam_measure, money)
{
	cPrenda::fecha.actualizarFecha();
	llenado_nullptr();
	
	if(llenado_material_base(base_material, tam_base))
	{
		std::cout<<""<<std::endl;
	}
	else
	{
		std::cout<<""<<std::endl;
	}
	if(llenado_precio_base(money_base))
	{
		std::cout<<""<<std::endl;
	}
	else
	{
		std::cout<<""<<std::endl;
	}
	
	
}

void cAccesorio::llenado_nullptr()
{
	material_base = nullptr;
	
}

bool cAccesorio::llenado_material_base(char *cadena, int size)
{
	cPrenda::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(unidad_relleno != nullptr)
        {   cPrenda::liberar(&unidad_relleno);  }

        if(llenado_size_base(size,cadena))
        {
            cPrenda::crear_memoria(size_base, &material_base);
            cPrenda::copiar(cadena, material_base, size_base);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cAccesorio::llenado_size_base(int size, char *cadena)
{
	cPrenda::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cPrenda::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_base = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_base = size;
    return true;
}

bool cAccesorio::llenado_precio_base(float numero)
{
	cPrenda::fecha.actualizarFecha();
    if(numero<=0.0)
	{
		precio_base = -1.0;
		return false;
	}
	precio_base = numero;
	return true;
}

bool cAccesorio::llenado_precio_final()
{
	cPrenda::fecha.actualizarFecha();
    float valor = cPrenda::getPrecio_unitario();

    if(valor<=0.0)
	{
		std::cout<<"Peso unitario cprenda invalido"<<std::endl;
        return false;
	}
	precio_final +=valor;
	return true;
	
}
		
const char *cAccesorio::getMaterial_base()
{
	
}

int cAccesorio::getSize_base()
{
	
}

float cAccesorio::getPrecio_base()
{
	
}

float cAccesorio::getPrecio_final()
{
	
}

cAccesorio::~cAccesorio()
{
	cPrenda::liberar(&material_base);
}