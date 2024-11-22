#ifndef CCLIENTE_HPP
#define CCLIENTE_HPP

#include "cFecha.hpp"

class cCliente
{
    public:

		~cCliente();//chau todo

		cCliente();
		explicit cCliente(char *name , char *code , char *direccion, int tam_nom, int tam_cod, int tam_direccion) ;//
		cCliente(const cCliente &obj);
		cCliente& operator=(const cCliente &obj);


		void print();

		bool llenado_nombre(char *name, int size = 0);
		bool llenado_codigo(char *code, int size = 0);
		bool llenado_direccion(char *code, int size = 0);
		bool llenado_size_nom(int size, char * cadena = nullptr);
		bool llenado_size_cod(int size, char * cadena = nullptr);
		bool llenado_size_direccion(int size, char * cadena = nullptr);
		void llenado_fecha();

		const char * getFecha();
		const char * getNombre();
		const char * getDireccion();
		const char * getCodigo();
		int getSize_nom();
		int getSize_cod();
		int getSize_direccion();

	protected:
		cFecha fecha;
		char *nombre;
		char *codigo;
		char *cadena_fecha;
		char *direccion_envio;

		int size_nom;
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
