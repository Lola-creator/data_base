#include "cCliente.hpp"
#include "cFecha.hpp"
#include <iostream>
#include <ctime>

cCliente::cCliente()
{
	asignar_nullptr();
	size_cod =-1;
	size_envio = -1;
	size_comercial = -1;
	llenado_generalFecha();
}

cCliente::cCliente(char*comer, char *code, char *direccion,int tam_comer,int tam_cod, int tam_direccion, char *regis, int tam_regis)
{
	asignar_nullptr();
	llenado_generalFecha();

	if(llenado_comercial(comer, tam_comer))
	{
		std::cout<<"NOMBRE COMERCIAL LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"NOMBRE COMERCIAL no LLENADO CON EXITO"<<std::endl;
	}

	if(llenado_codigo(code, tam_cod))
	{
		std::cout<<"CODIGO LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"CODIGO no LLENADO CON EXITO"<<std::endl;
	}

	if(llenado_envio(direccion, tam_direccion))
	{
		std::cout<<"DIRECCION LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"DIRECCION no LLENADO CON EXITO"<<std::endl;
	}
	if(llenado_registro(regis, tam_regis))
	{
		std::cout<<"NOMBRE COMERCIAL LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"NOMBRE COMERCIAL no LLENADO CON EXITO"<<std::endl;
	}

}

cCliente::cCliente(const cCliente &obj) // Constructor de copia
{
	asignar_nullptr();

	if(asignarValores(&obj)) {
		std::cout << "SE LOGRO" << std::endl;
	} else {
		std::cout << "NO SE LOGRO" << std::endl;
	}

	std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cCliente& cCliente::operator=(const cCliente &obj) // Operador de asignación
{
	if(&obj != this) {
		if(asignarValores(&obj)) {  // Pasamos la dirección de `obj` para cumplir con el tipo
			std::cout << "SE LOGRO" << std::endl;
		} else {
			std::cout << "NO SE LOGRO" << std::endl;
		}
	} else {
		std::cout << "NO SE LOGRO - no copia de si mismo" << std::endl;
	}

	std::cout << "SOBRECARGA DE OPERADOR" << std::endl;
	return *this;//devolver la referencia
}

bool cCliente::asignarValores(const cCliente *obj)
{

	fecha.actualizarFecha();
	fecha = (*obj).fecha;

	if(llenado_codigo((*obj).codigo, (*obj).size_cod))
	{
		std::cout<<"CODIGO LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"CODIGO no LLENO"<<std::endl;
		return false;
	}

	if(llenado_envio((*obj).direccion_envio, (*obj).size_envio))
	{
		std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"NOMBRE no LLENO"<<std::endl;
		return false;
	}

	if(llenado_comercial((*obj).nombre_comercial, (*obj).size_comercial))
	{
		std::cout<<"NOMBRE COMERCIAL LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"NOMBRE COMERCIAL no LLENADO CON EXITO"<<std::endl;
	}

	if(llenado_registro((*obj).registro, (*obj).size_registro))
	{
		std::cout<<"NOMBRE COMERCIAL LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"NOMBRE COMERCIAL no LLENADO CON EXITO"<<std::endl;
	}

	return true;

}

void cCliente::print()
{
	char respuesta {'N'};
	bool valido = true;

	if (codigo!= nullptr)
	{
    std::cout<<"CODIGO: " <<codigo<<" tam:"<<size_cod<<std::endl;
	}
	else
	{
		std::cout << "Codigo no asignado (nullptr)" << std::endl;
		valido = false;
	}

	if (direccion_envio!= nullptr)
	{
    std::cout<<"CODIGO: " <<direccion_envio<<" tam:"<<size_envio<<std::endl;
	}
	else
	{
		std::cout << "Codigo no asignado (nullptr)" << std::endl;
		valido = false;
	}

	if (nombre_comercial!= nullptr)
	{
    std::cout<<"NOMBRE COMERCIAL: " <<nombre_comercial<<" tam:"<<size_comercial<<std::endl;
	}
	else
	{
		std::cout << "Codigo no asignado (nullptr)" << std::endl;
		valido = false;
	}

	if(!valido)
	{
		std::cout<<"NO SE ACCEDERA A SU ULTIMO ACCESO";
	}
	else
	{
		std::cout<<"¿Desea conocer el ultimo acceso? (Y/N) ";
		std::cin>>respuesta;

		if(respuesta == 'Y' || respuesta == 'y')
		{
			ultimoAcceso();
		}
	}
}

void cCliente::ultimoAcceso()
{

	char temp[40];
	bool flag = true;
	int i=0;

	fecha.actualizarFecha();

	std::cout<<"Ingrese codigo"<<std::endl;
	std::cin>>temp;

	while( *(codigo+i) !='\0')
	{
		if (*(temp+i) != *(codigo+i))
		{
			flag = false;
			break;
		}
		i++;

	}

	if(flag)
	{	std::cout<<"Ultimo acceso: ";
		fecha.print();
	}
	else
	{
		std::cout<<"INCORRECTO";
	}
}

void cCliente::asignar_nullptr()
{
	codigo = nullptr;
	direccion_envio = nullptr;
    cadena_fecha = nullptr;
	nombre_comercial = nullptr;
}

void cCliente::llenado_generalFecha()
{
	char respuesta;

	std::cout<<"Desea inicializar fecha o por defecto? (Y/N): ";
	std::cin>>respuesta;

	if(respuesta == 'Y' || respuesta == 'y')
	{
		llenado_fecha();
	}
	else
	{	fecha.actualizarFecha();	}

}

void cCliente::llenado_fecha()
{
	int valor =0;

	std::cout<<"dia: ";
	std::cin>> valor;
	fecha.setDia(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"mes: ";
	std::cin>> valor;
	fecha.setMes(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"year: ";
	std::cin>> valor;
	fecha.setYear(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"Segundo: ";
	std::cin>> valor;
	fecha.setSeg(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"Minuto: ";
	std::cin>> valor;
	fecha.setMin(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"Hora: ";
	std::cin>> valor;
	fecha.setHora(valor);
	std::cout<<" "<<std::endl;
}

bool cCliente::llenado_size_envio(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1)// still 0, no se crea nada
		{
			size_envio = -1;
			std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_envio = size;
	return true;
}

bool cCliente::llenado_size_comercial(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1)// still 0, no se crea nada
		{
			size_comercial = -1;
			std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_comercial = size;
	return true;
}

bool cCliente::llenado_size_registro(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1)// still 0, no se crea nada
		{
			size_registro= -1;
			std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_registro = size;
	return true;
}

bool cCliente::llenado_size_cod(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1) // still 0, no se crea nada
		{
			size_cod = -1;
			std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_cod = size;
	return true;
}
//code lo que te mandan
bool cCliente::llenado_codigo(char *code, int size)
{
	fecha.actualizarFecha();
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(codigo != nullptr) //liberar memoria de nombre
			{  liberar(&codigo); }

		if(llenado_size_cod(size, code))
		{
			crear_memoria(size_cod, &codigo);
			copiar(code, codigo, size_cod);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
	return false;

}

bool cCliente::llenado_comercial(char *code, int size)
{
	fecha.actualizarFecha();
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(codigo != nullptr) //liberar memoria de nombre
			{  liberar(&nombre_comercial); }

		if(llenado_size_comercial(size, code))
		{
			crear_memoria(size_comercial, &nombre_comercial);
			copiar(code, nombre_comercial, size_comercial);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
	return false;

}

bool cCliente::llenado_envio(char *name, int size)
{
	fecha.actualizarFecha();

	if(name != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(direccion_envio != nullptr) //liberar memoria de nombre
			{  liberar(&direccion_envio); }

		if(llenado_size_envio(size, name))
		{
			crear_memoria(size_envio, &direccion_envio);
			copiar(name, direccion_envio, size_envio);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR NOMBRE" <<std::endl;
	return false;
}

bool cCliente::llenado_registro(char *code, int size)
{
	fecha.actualizarFecha();
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(registro!= nullptr) //liberar memoria de nombre
			{  liberar(&registro); }

		if(llenado_size_registro(size, code))
		{
			crear_memoria(size_registro, &registro);
			copiar(code, registro, size_registro);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
	return false;

}

const char *cCliente::getEnvio()
{
	return direccion_envio;
}

const char * cCliente::getCodigo()
{
	return codigo;
}

const char * cCliente::getRegistro()
{
	return registro;
}

const char * cCliente::getComercial()
{
	return nombre_comercial;
}

const char * cCliente::getFecha()
{
    if(cadena_fecha != nullptr)
    {
       liberar(&cadena_fecha);
    }
    crear_memoria(8,&cadena_fecha);

    cadena_fecha[0] = fecha.getDia();
    cadena_fecha[1] = fecha.getMes();
    cadena_fecha[2] = fecha.getYear() / 100;
    cadena_fecha[3] = fecha.getYear() % 100;
    cadena_fecha[4] = fecha.getSeg();
    cadena_fecha[5] = fecha.getMin();
    cadena_fecha[6] = fecha.getHora();
    cadena_fecha[7] = '\0';

    return cadena_fecha;
}

int cCliente::getSize_cod()
{
	return size_cod;
}

int cCliente::getSize_registro()
{
	return size_registro;
}

int cCliente::getSize_envio()
{
	return size_envio;
}

int cCliente::getSize_comercial()
{
	return size_comercial;
}

int cCliente::contador(const char * cadena)
{
	int fin =0;
	while( *(cadena+fin) != '\0')
	{
		fin++;
	}
	return fin+1;
}

void cCliente::crear_memoria(int tam, char ** destino)
{
	if (tam > 0) 	//nombre
	{	*destino = new char[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

void cCliente::copiar( char *root, char *destino, int tam)
{
	for(int i=0;i<tam;i++)
	{
		*(destino+i) = *(root+i);
	}
	*(destino+(tam-1)) = '\0';//asegurar
}

void cCliente::liberar(char **target)
{
	if (*target != nullptr) {
        delete[] *target; // Libera la memoria asignada a nombre
        *target = nullptr; // Opcional: poner el puntero a nullptr para evitar accesos futuros
    }
}

cCliente::~cCliente()
{
    fecha.actualizarFecha();
	liberar(&codigo);
    liberar(&cadena_fecha);
	liberar(&direccion_envio);
}
