#ifndef CLISTAPRENDA_HPP
#define CLISTAPRENDA_HPP

#include "cPrenda.hpp"
#include "cPattern.hpp"
#include "cIntermedio.hpp"

class cListaPrenda : public cIntermedio
{
    public:
        cListaPrenda();
        cListaPrenda(cPrenda * nuevo, int tam, char *code, char * source,
                     int tam_code,int tam_source);

        bool llenado_codigo(char *code, int size = 0);
        bool llenado_prenda(cPrenda * nuevo, int value);
        bool llenado_material(char *code, int size = 0);
        bool llenado_size_cod(int size, char * cadena = nullptr);
        bool llenado_size_material(int size, char * cadena = nullptr);

        bool llenado_size(int valor);
        virtual bool llenado_precio_total();
        virtual bool llenado_peso_total();

        cPrenda * getStorage();
        const char* getCodigo();
        const char* getMaterial();
        int getSize();
        int getSize_code();
        int getSize_material();
        int getPrecio_total();

        void print();

        bool addContent(cPrenda *nuevo, int add);
        bool deleteContent(int begin, int end);

        void buscarTalla(char * codigo, int * temp);
        void buscarColor(char * codigo, int * temp);
        void buscarFecha(char * codigo,int fin, int inicio, int* temp);
        void buscarPeso(char *unidad, float numero, int *temp);

        virtual ~cListaPrenda();

    protected:
        cPrenda * manyClothes;
        char * codigo;//MODELO
        char * material;
        float precio_total;
        float peso_total;

        int size_storage;
        int size_code;
        int size_material;

        virtual void crear_memoria_np(int, cPrenda **);
        virtual void crear_memoria();
        void liberar_memoria_np(cPrenda ** target);
        void liberar_memoria();

    private:
        void llenado_nullptr();
};

#endif
