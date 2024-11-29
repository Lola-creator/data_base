#ifndef CCLIENTE_HPP
#define CCLIENTE_HPP

#include "cFecha.hpp"

class cCliente
{
    public:

		~cCliente();//chau todo

		cCliente();
		explicit cCliente(char *name , char *code , char *direccion, int tam_nom, int tam_cod, int tam_direccion);//
		cCliente(const cCliente &obj);
		cCliente& operator=(const cCliente &obj);


		void print();
		bool llenado_codigo(char *cadena, int num=0);
		bool llenado_direccion(char *cadena, int num=0);
		bool llenado_size_cod(int size, char * cadena = nullptr);
		bool llenado_size_direccion(int size, char * cadena = nullptr);
		void llenado_fecha();

		const char * getDireccion();
		const char * getCodigo();
		int getSize_direccion();
		int getSize_cod();
		const char * getFecha();

	protected:
		cFecha fecha;
		char *cadena_fecha;//revision ultima entrada
		char *direccion_envio;
		char *codigo;


		int size_envio;
		int size_cod;
		int size_direccion;

		void ultimoAcceso();
		void asignar_nullptr();
		void llenado_generalFecha();

		bool asignarValores(const cCliente *obj);
		void copiar(char *root, char *destino, int tam);
		int contador(const char *cadena);

		void crear_memoria(int tam, char ** destino);
		void liberar(char **target);

};

#endif
