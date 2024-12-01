#include "cListaCliente.hpp"
#include "cIntermedio.hpp"
#include <iostream>

cListaCliente::cListaCliente()
{
    llenado_nullptr();
    size_sede = -1;
    size_client = -1;
}

cListaCliente::cListaCliente(cCliente * nuevo, char*place, int tam_clients, int tam_place)
{
    llenado_nullptr();

    if(llenado_clientes(nuevo, tam_clients))
    {
        std::cout<<"LOGRADO LLENAR CLIENTE"<<std::endl;
    }
    else
    {
        std::cout<<"NO LOGRADO LLENAR CLIENTE"<<std::endl;
    }
    if(llenado_sede(place, tam_place))
    {
        std::cout<<"LLENADO SEDE"<<std::endl;
    }
    else
    {
        std::cout<<"NO LLENADO SEDE"<<std::endl;
    }
}

void cListaCliente::llenado_nullptr()
{
    sede = nullptr;
    manyClients = nullptr;
}

bool cListaCliente::llenado_clientes(cCliente * nuevo, int value)
{
    if(llenado_size(value))
    {
        crear_memoria();
        for(int i=0;i<size_client;i++)
        {
            *(manyClients+i) = *(nuevo+i);
        }

        return true;
    }
    return false;
}

bool cListaCliente::llenado_sede(char *code, int size)
{
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(sede != nullptr) //liberar memoria de nombre
			{  cIntermedio::liberar_arrays(&sede); }

		if(llenado_size_sede(size, code))
		{
			cIntermedio::crear_memoria_arrays(size_sede, &sede);
			cIntermedio::copiar(code, sede, size_sede);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR SEDE" <<std::endl;
	return false;
}

bool cListaCliente::llenado_size(int valor)
{
    if(valor<1)
    {
        size_client = -1;
        std::cout<<"invalido"<<std::endl;
        return false;
    }

    size_client = valor;
    return true;
}

bool cListaCliente::llenado_size_sede(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = cIntermedio::contador(cadena);
		if(size<=1) // still 0, no se crea nada
		{
			size_sede =-1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_sede = size;
	return true;
}

const cCliente * cListaCliente::getClients()
{
    return manyClients;
}

const char * cListaCliente::getSede()
{
    return sede;
}
int cListaCliente::getSize_sede()
{
    return size_sede;
}

int cListaCliente::getSize_clients()
{
    return size_client;
}

void cListaCliente::buscarFecha(char * codigo,int fin, int inicio, int* temp)
{
    int indexTemp = 0;
    int intervalo = (fin - inicio);
    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        const char *direccion = (*(manyClients + i)).getFecha();   //manyStorages+i)->codigo;

        for(int a =0;a<intervalo;a++, inicio++)
        {
            if(  *(codigo+a) != *(direccion+inicio))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            temp[indexTemp] = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}


void cListaCliente::buscarNombre(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;
        const char *cadena = (*direccion).getComercial();
        int tope = (*direccion).getSize_comercial();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaCliente::buscarEnvio(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;
        const char *cadena = (*direccion).getEnvio();
        int tope = (*direccion).getSize_envio();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaCliente::buscarCodigo(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;
        const char *cadena = (*direccion).getCodigo();
        int tope = (*direccion).getSize_cod();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaCliente::buscarRegistro(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;
        const char *cadena = (*direccion).getRegistro();
        int tope = (*direccion).getSize_registro();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

bool cListaCliente::addContent(cCliente *nuevo, int add)
{
    cCliente *temp = nullptr;
    int oldSize = size_client;

    if(nuevo == nullptr || add == 0)
    {
        return false;
    }

    size_client +=add;

    crear_memoria_np(size_client, &temp);

    for(int i=0;i<(oldSize);i++)
    {
        *(temp+i) = *(manyClients+i);
    }

    for(int i=0;i<add;i++)
    {
        *(temp+oldSize+i) = *(nuevo+i);
    }

    liberar_memoria();

    manyClients = temp;

    return true;

}

void cListaCliente::crear_memoria_np(int tam, cCliente ** destino)
{
    if(*destino != nullptr)
    {
        liberar_memoria_np(destino);
    }

    if (tam > 0) 	//nombre
	{	*destino = new cCliente[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

void cListaCliente::liberar_memoria_np(cCliente ** target)
{
    if (*target != nullptr) {
        delete[] *target; // Libera la memoria asignada a nombre
        *target = nullptr; // Opcional: poner el puntero a nullptr para evitar accesos futuros
    }
    else
    {
        std::cout<<"Already empty!"<<std::endl;
    }
}

bool cListaCliente::deleteContent(int begin, int end)//index, 3 a 4, entonce 2 a 3includio
{
    cCliente *temp = nullptr;
    int intervalo = (end-begin+1);
    int oldSize = size_client;
    int tempIndex =0;

    if(intervalo<=0 || end>size_client || begin<1 || begin>end)
    {   return false;   }

    size_client-=intervalo;
    crear_memoria_np(size_client, &temp);

    for(int i=0;i<oldSize;i++)
    {
        if(i<= (end-1) && i>=(begin-1))
        {
            continue;
        }
        *(temp+tempIndex) = *(manyClients+i);
        tempIndex++;
    }

    liberar_memoria();

    manyClients = temp;
    return true;
}

void cListaCliente::crear_memoria()
{
    if( manyClients != nullptr)
    {   liberar_memoria();    }

    if(size_client>=1)
    {
        manyClients= new cCliente[size_client];
    }
    else
    {
        manyClients= nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }

}

void cListaCliente::liberar_memoria()
{
    if(manyClients != nullptr)
    {
        delete[] manyClients;
        manyClients = nullptr;
    }
    else
    {
        std::cout<<"Already empty!"<<std::endl;
    }
}

cListaCliente::~cListaCliente()
{
    liberar_memoria();
    cIntermedio::liberar_arrays(&sede);
}






