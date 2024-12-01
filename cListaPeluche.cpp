#include "cListaPeluche.hpp"

cListaPeluche::cListaPeluche() : cListaPrenda()
{
    llenado_default();
    precio_total = -1.0;
    size_material_fill = -1;
}

cListaPeluche::cListaPeluche(cPrenda * nuevo, int tam, char *code, char * source,
                             char * fill, int tam_code, int tam_source, int tam_fill)
            : cListaPrenda(nuevo, tam, code, source, tam_code, tam_source)
{
    llenado_default();

    if(llenado_maFill(fill, tam_fill))
    {
        std::cout<<"LOGRADO LLENAR RELLENO"<<std::endl;
    }
    else
    {
        std::cout<<"NO LOGRADO LLENAR RELLENO"<<std::endl;
    }
}

void cListaPeluche:: llenado_default()
{
    material_fill = nullptr;
}

bool cListaPeluche::llenado_maFill(char *code, int size)
{
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(material_fill != nullptr) //liberar memoria de nombre
			{  cIntermedio::liberar_arrays(&material_fill); }

		if(llenado_size_maFill(size, code))
		{
			cIntermedio::crear_memoria_arrays(size_code, &codigo);
			cIntermedio::copiar(code, codigo, size_code);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
	return false;
}

bool cListaPeluche::llenado_size_maFill(int size, char * cadena)
{
    if(size <= 1)//o por deafult o no lo lleno
	{
		size = cIntermedio::contador(cadena);
		if(size<=1) // still 0, no se crea nada
		{
			size_material_fill = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_material_fill = size;
	return true;
}

const char* cListaPeluche::getRelleno()
{
    return material_fill;
}

int cListaPeluche::getRelleno_size()
{
    return size_material_fill;
}

bool cListaPeluche::llenado_precio_total()
{
    bool flag = true;
    for(int i=0;i<size_storage; i++)
    {
        cPeluche *valor = dynamic_cast<cPeluche *>(manyClothes+i);
        if(valor == nullptr)
        {
            flag = false;
            std::cout<<"error en acceder a metodo de lista peluche"<<std::endl;
            break;
        }
        else
        {
            precio_total += (*valor).getPrecio_final();
        }
    }
    if(precio_total<1.0)
    {
        precio_total = -1.0;
        flag = false;
    }
    return true;
}

bool cListaPeluche::llenado_peso_total()
{
    bool flag = true;
    for(int i=0;i<size_storage; i++)
    {
        cPeluche *valor = dynamic_cast<cPeluche *>(manyClothes+i);
        if(valor == nullptr)
        {
            flag = false;
            std::cout<<"error en acceder a metodo de lista peluche"<<std::endl;
            break;
        }
        else
        {
            peso_total += (*valor).getPeso_final();
        }
    }

    if(peso_total<1.0)
    {
        peso_total = -1.0;
        flag = false;
    }
    return true;
}

void cListaPeluche::crear_memoria()
{
    if( manyClothes!= nullptr)
    {   cListaPrenda::liberar_memoria();    }

    if(size_storage>=1)
    {
        manyClothes= new cPeluche[size_storage];
    }
    else
    {
        manyClothes = nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }
}

void cListaPeluche::crear_memoria_np(int tam, cPrenda ** destino)
{
    if(*destino != nullptr)
    {
        cListaPrenda::liberar_memoria_np(destino);
    }

    if (tam > 0) 	//nombre
	{	*destino = new cPeluche[tam];
        if(*destino ==nullptr)
        {
            std::cout<<"cannot cast"<<std::endl;
        }
    }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}


cListaPeluche::~cListaPeluche()
{
    cListaPrenda::liberar_memoria();
    cListaPrenda::liberar_arrays(&material_fill);
}















