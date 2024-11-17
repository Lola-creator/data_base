#ifndef CPRENDA_HPP
#define CPRENDA_HPP

#include "cPrenda.hpp"

class cPeluche:public cPrenda()
{
    public:
        cPeluche();
        cPeluche(char * name, char *code, char * measure, int tam_cod, int tam_name,
				 int tam_measure,float money, char *relleno, char * relleno_unidad,
                 int tam_relleno, int tam_relleno_unidad, float money_relleno, float
                 money_final, float weight_relleno, float weight_final);
        cPeluche();

        bool llenado_tipo_relleno();
        bool llenado_unidad_relleno();
        bool llenado_size_tipo_relleno();
        bool llenado_size_unidad_relleno();

        bool llenado_peso_relleno(float numero);
        bool llenado_precio_relleno(float numero);
        bool llenado_precio_final();
        bool llenado_peso_final();

		char * getTipo_relleno();
		char * getUnidad_relleno();
		int getSize_relleno();
        int getSize_unidad_relleno();

        float getPrecio_relleno();
        float getPeso_relleno();
        float getPeso_final();
        float getPrecio_final();

        ~cPeluche();



    private:
        char * tipo_relleno;
        char *unidad_relleno;

        int size_tipo_relleno;
        int size_unidad_relleno;

        float peso_relleno;
        float precio_relleno;
        float precio_final;
        float peso_final;

        void llenado_nullptr();

		bool asignarValores(const cPeluche *obj);

        void crear_memoria(int tam, char ** destino);
		void liberar(char **target);

};

#endif
