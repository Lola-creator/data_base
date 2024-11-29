#ifndef CLISTAACCESORIO_HPP
#define CLISTAACCESORIO_HPP

#include "cAccesorio.hpp"
#include "cListaPrenda.hpp"
#include <iostream>

class cListaAccesorio : public cListaPrenda
{
    public:
        cListaAccesorio();
        cListaAccesorio(cPrenda * nuevo, int tam, char *code, char * source,
                     int tam_code,int tam_source, int tam_capas);
        ~cListaAccesorio() override;

        bool llenado_capas(int num);
        int getNum_capas();

        bool llenado_precio_total() override;
        bool llenado_peso_total() override;

    private:
        int num_capas; //numero de capas que debe tener la base
        void crear_memoria() override;
        void crear_memoria_np(int, cPrenda **) override;
};

#endif
