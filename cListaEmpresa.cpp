#include "cListaEmpresa.hpp"
#include "cIntermedio.hpp"
#include <iostream>

cListaEmpresa::cListaEmpresa(): cListaCliente()
{

}

cListaEmpresa::cListaEmpresa(cCliente * nuevo, char*place, int tam_clients, int tam_place)
                :cListaCliente(nuevo, place, tam_clients, tam_place)
{

}

void cListaEmpresa::buscarId_fiscal(char * codigo, int* temp)//nombre real
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cEmpresa* direccion = (manyClients + i);   //manyStorages+i)->codigo;

        const char *cadena = (*direccion).getId_fiscal();
        int tope = (*direccion).getSize_id_fidcal();

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

void cListaEmpresa::buscarRazon_social(char * codigo, int* temp)//nombre real
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cEmpresa* direccion = (manyClients + i);   //manyStorages+i)->codigo;

        const char *cadena = (*direccion).getRazon_social();
        int tope = (*direccion).getSize_razon_social();

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

void cListaEmpresa::buscarNombre(char * codigo, int* temp)//nombre real
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;

        cEmpresa *empresa= dynamic_cast<cEmpresa *>(direccion);
        if (tercero == nullptr) {
            std::cout<<"DYNAMIC CAST FAILED"<<std::endl;
            break;
        }

        const char *cadena = (*empresa).getContacto();
        int tope = (*empresa).getSize_contacto();

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

void cListaEmpresa::buscarRegistro(char * codigo, int* temp)//nombre real
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;

        cEmpresa *empresa= dynamic_cast<cEmpresa *>(direccion);
        if (tercero == nullptr) {
            std::cout<<"DYNAMIC CAST FAILED"<<std::endl;
            break;
        }

        const char *cadena = (*empresa).getContrato();
        int tope = (*empresa).getSize_contrato();

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


void cListaEmpresa::crear_memoria()
{
    if( manyClients != nullptr)
    {   liberar_memoria();    }

    if(size_client>=1)
    {
        manyClients= new cEmpresa[size_client];
    }
    else
    {
        manyClients= nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }

}

void cListaEmpresa::crear_memoria_np(int tam, cCliente **destino)
{
    if(*destino != nullptr)
    {
        liberar_memoria_np(destino);
    }

    if (tam > 0) 	//nombre
	{	*destino = new cEmpresa[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

cListaEmpresa::~cListaEmpresa()
{

}
