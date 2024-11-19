#ifndef CACCESORIO_HPP
#define CACCESORIO_HPP

#include "cPrenda.hpp"

class cAccesorio:public cPrenda
{
	public:
		cAccesorio();
		cAccesorio(char * name, char *code, char * measure, int tam_cod, int tam_name,
						 int tam_measure,float money, char *base_material, int tam_base, 
						 float money_base, float money_final);
		cAccesorio();
		bool llenado_material_base(char * base_material, int tam_base = 0);
		bool llenado_size_base(int size, char *base_material = nullptr);
		bool llenado_precio_base(float money_base);
		bool llenado_precio_final();
		
		const char *getMaterial_base();
		int getSize_base();
		float getPrecio_base();
		float getPrecio_final();

		
	private:
		void llenado_nullptr();
		
		char *material_base;
		int size_base;
		float precio_base;
		float precio_final;
};

#endif