#include "cListaAccesorio.hpp"

cListaAccesorio::cListaAccesorio()
{
    num_capas = -1;
}

cListaAccesorio::cListaAccesorio(cPrenda * nuevo, int tam, char *code, char * source,
                     int tam_code,int tam_source, int tam_capas)
                : cListaPrenda(nuevo, tam, code, source, tam_code, tam_source)
{
    num_capas = -1;
    if(llenado_capas(tam_capas))
    {
        std::cout<<"LOGRADO LLENAR n CAPAS"<<std::endl;
    }
    else
    {
        std::cout<<"NO LOGRADO LLENAR n CAPAS"<<std::endl;
    }
}

bool cListaAccesorio::llenado_capas(int numero)
{
    if(numero<=0)
	{
		num_capas = -1;
		return false;
	}
	num_capas = numero;
	return true;
}

int cListaAccesorio::getNum_capas()
{
    return num_capas;
}

bool cListaAccesorio::llenado_precio_total()
{
    bool flag = true;
    for(int i=0;i<size_storage; i++)
    {
        cAccesorio *valor = dynamic_cast<cAccesorio*>(manyClothes+i);
        if(valor == nullptr)
        {
            flag = false;
            std::cout<<"error en acceder a metodo de lista accesorio"<<std::endl;
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

bool cListaAccesorio::llenado_peso_total()
{
    bool flag = true;
    for(int i=0;i<size_storage; i++)
    {
        cAccesorio *valor = dynamic_cast<cAccesorio*>(manyClothes+i);
        if(valor == nullptr)
        {
            flag = false;
            std::cout<<"error en acceder a metodo de lista accesorio"<<std::endl;
            break;
        }
        else
        {
            precio_total += (*valor).getPeso();
        }
    }
    if(peso_total<1.0)
    {
        peso_total = -1.0;
        flag = false;
    }
    return true;
}


void cListaAccesorio::crear_memoria()
{
    if( manyClothes!= nullptr)
    {   cListaPrenda::liberar_memoria();    }

    if(size_storage>=1)
    {
        manyClothes= new cAccesorio[size_storage];
    }
    else
    {
        manyClothes = nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }
}

void cListaAccesorio::crear_memoria_np(int tam, cPrenda ** destino)
{
    if(*destino != nullptr)
    {
        cListaPrenda::liberar_memoria_np(destino);
    }

    if (tam > 0) 	//nombre
	{	*destino =new cAccesorio[tam];
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

cListaAccesorio::~cListaAccesorio()
{
    liberar_memoria();
}
