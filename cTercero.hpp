#ifndef CTERCERO_HPP
#define CTERCERO_HPP

#include "cFecha.hpp"
#include "cCliente.hpp"
#include "cPersona.hpp"
#include "cFecha.hpp"

class cTercero : public cCliente, public cPersona
{

    public:
        explicit cTercero();
        explicit cTercero(char* comer, char *code, char *direccion,int tam_comer,int tam_cod, int tam_direccion,
                          char* name, char *adress, char *mail, char *phone, int tam_nom, int tam_adress,
                          int tam_mail,int tam_phone, int age, char *relative, char *money, int tam_relative, int tam_money,
                          char *regis, int tam_regis);
        cTercero(const cTercero &obj);
		cTercero& operator=(const cTercero &obj);
        virtual ~cTercero();

        bool llenado_factura(char *cadena, int size = 0);
        bool llenado_afiliado(char *cadena, int size = 0);
        bool llenado_size_factura(int size,char *cadena = nullptr);
        bool llenado_size_afiliado(int size,char *cadena = nullptr);

        const char * getAfiliado();
        const char * getFactura();
        int getSize_factura();
        int getSize_afiliado();

    private:
        char *factura;
        char *afiliado;

        int size_factura;
        int size_afiliado;

        bool asignar_valores(const cTercero &obj);
        void llenar_nullptr();
};

#endif
