#ifndef CEMPRESA_HPP
#define CEMPRESA_HPP

#include "cFecha.hpp"
#include "cCliente.hpp"


class cEmpresa : public cCliente
{
    public:
        cEmpresa();
		cEmpresa(char*razon, char*contact, char*id, char*paper, int tam_razon, int tam_contact,
                int tam_id, int tam_paper, float less_money, char*comer, char *code,
                char *direccion,int tam_comer,int tam_cod, int tam_direccion, char *regis, int tam_regis);
		cEmpresa(const cEmpresa &obj);
		cEmpresa& operator=(const cEmpresa &obj);
        ~cEmpresa();

        bool llenado_razon_social(char *cadena, int size = 0);
        bool llenado_contacto(char *cadena, int size = 0);
        bool llenado_id_fiscal(char *cadena, int size = 0);
        bool llenado_contrato(char *cadena, int size = 0);
        bool llenado_descuento(float num);
        bool llenado_size_razon_social(int size,char *cadena = nullptr);
        bool llenado_size_contacto(int size,char *cadena = nullptr);
        bool llenado_size_id_fiscal(int size,char *cadena = nullptr);
        bool llenado_size_contrato(int size,char *cadena = nullptr);

        float getDescuento();
        const char *getRazon_social();
        const char *getContacto();
        const char *getId_fiscal();
        const char *getContrato();

        int getSize_contacto();
        int getSize_razon_social();
        int getSize_id_fiscal();
        int getSize_contrato();

    private:
        float descuento;
        char *razon_social;
        char *contacto;
        char *id_fiscal;
        char *contrato;

        int size_contacto;
        int size_razon_social;
        int size_id_fiscal;
        int size_contrato;

        void llenado_nullptr();
        bool asignar_valores(const cEmpresa &obj);
        bool llenado_precio();
        bool llenado_precio_total();
};

#endif
