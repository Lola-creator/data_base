#ifndef CLISTAEMPRESA_HPP
#define CLISTAEMPRESA_HPP
#include "cEmpresa.hpp"
#include "cIntermedio.hpp"
#include "cListaCliente.hpp"

class cListaEmpresa : public cListaCliente
{
    public:
        cListaEmpresa();
        cListaEmpresa(cCliente * nuevo, char*place, int tam_clients, int tam_place);
        virtual ~cListaEmpresa();

        void buscarId_fiscal(char * codigo, int* temp);
        void buscarRazon_social(char * codigo, int* temp);
        void buscarNombre(char * codigo, int* temp) override;
        void buscarRegistro(char * codigo, int* temp) override;

    private:
        void crear_memoria_np(int, cCliente **) override;
        void crear_memoria() override;
};

#endif
