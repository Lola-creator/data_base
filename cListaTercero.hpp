#ifndef CLISTATERCERO_HPP
#define CLISTATERCERO_HPP
#include "cListaCliente.hpp"
#include "cTercero.hpp"
#include "cCliente.hpp"
#include "cPersona.hpp"

class cListaTercero : public cListaCliente
{
    public:
        cListaTercero();
        cListaTercero(cCliente * nuevo, char*place, int tam_clients, int tam_place);

        void buscarTelefono(char * codigo, int* temp);
        void buscarCorreo(char * codigo, int* temp);
        void buscarDireccion(char * codigo, int* temp);
        void buscarNombre(char * codigo, int* temp) override;
        void buscarRegistro(char * codigo, int* temp) override;

        virtual ~cListaTercero();

    private:
        void crear_memoria_np(int, cCliente **) override;
        void crear_memoria() override;

};

#endif
