#ifndef CCLIENTE_HPP
#define CCLIENTE_HPP

#include "cFecha.hpp"

class cCliente
{
    public:

		virtual ~cCliente();//chau todo

		explicit cCliente();
		explicit cCliente(char*comercial, char *code, char *direccion,int tam_comer,int tam_cod,
						  int tam_direccion);//
		explicit cCliente(const cCliente &obj);
		cCliente& operator=(const cCliente &obj);


		void print();
		bool llenado_codigo(char *cadena, int num=0);
		bool llenado_direccion(char *cadena, int num=0);
		bool llenado_comercial(char *cadena, int num=0);
		bool llenado_size_cod(int size, char * cadena = nullptr);
		bool llenado_size_direccion(int size, char * cadena = nullptr);
		bool llenado_size_comercial(int size, char * cadena = nullptr);
		void llenado_fecha();

		const char * getComercial();
		const char * getDireccion();
		const char * getCodigo();
		const char * getFecha();

		int getSize_direccion();
		int getSize_cod();
		int getSize_comercial();

	protected:
		cFecha fecha;
		char *cadena_fecha;//revision ultima entrada
		char *direccion_envio;
		char *codigo;
		char *nombre_comercial;

		int size_envio;
		int size_cod;
		int size_direccion;
		int size_comercial;

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
