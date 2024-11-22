#ifndef CTERCERO_HPP
#define CTERCERO_HPP

#include "cFecha.hpp"
#include "cCliente.cpp"

class cTercero : public cCliente
{

    public:
        cTercero();
        explicit cTercero(char *name , char *code , char *direccion, int tam_nom, int tam_cod, int tam_direccion);//

        ~cTercero();

        bool llenado_dni(char *cadena, int size = 0);
        bool llenado_factura(char *cadena, int size = 0);
        bool llenado_afiliado(char *cadena, int size = 0);
        bool llenado_size_dni(int size,char *cadena = nullptr);
        bool llenado_size_factura(int size,char *cadena = nullptr);
        bool llenado_size_afiliado(int size,char *cadena = nullptr);

        const char * getDni();
        const char * getFactura();
        int getSize_dni();
        int getSize_factura();
        int getSize_afiliado();

    private:
        char *dni;
        char *factura;
        char *afiliado;

        int size_dni;
        int size_factura;
        int size_afiliado;
};

#endif
