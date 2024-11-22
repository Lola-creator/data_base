#ifndef CPEDIDO_HPP
#define CPEDIDO_HPP

#include "cFecha.hpp"
#include "cListaPrenda"
#include "cListaPeluche"
#include "cListaAccesorio"

class cPedido
{
    public:
        cPedido();
        const char *getEntrega();
        int getSize_prendas();
        int getSize_peluches();
        int getSize_accesorios();

        const cListaPrenda getPrenda();
        const cListaPeluche getPeluche();
        const cListaAccesorio getAccesorio();
        ~cPedido();

    private:
        cFecha entrega;
        cListaPrenda * prendas;
        cListaPeluche * peluches;
        cListaAccesorio * accesorios;

        int size_pedido_prendas;
        int size_pedido_peluches;
        int size_pedido_accesorios;

        void llenado_nullptr();
};

#endif
