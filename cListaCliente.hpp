#ifndef CLISTACLIENTE_HPP
#define CLISTACLIENTE_HPP
#include "cCliente.hpp"
#include "cIntermedio.hpp"

class cListaCliente : public cIntermedio
{
    public:
        cListaCliente();
        cListaCliente(cCliente * nuevo, char*place, int tam_clients, int tam_place);

        bool llenado_clientes(cCliente * nuevo, int num);
        bool llenado_sede(char *cadena, int size = 0);
        bool llenado_size(int num);
        bool llenado_size_sede(int size,char *cadena = nullptr);

        const cCliente * getClients();
        const char * getSede();
        int getSize_sede();
        int getSize_clients();

        bool addContent(cCliente *nuevo, int add);
        bool deleteContent(int begin, int end);

        void buscarCodigo(char * codigo, int* temp);
        void buscarEnvio(char * codigo, int* temp);
        void buscarFecha(char * codigo,int fin, int inicio, int* temp);
        virtual void buscarNombre(char * codigo, int* temp);
        virtual void buscarRegistro(char * codigo, int* temp);
        //int buscar

        virtual ~cListaCliente();

    protected:
        cCliente * manyClients;
        char * sede;
        int size_sede;
        int size_client;

        virtual void crear_memoria_np(int, cCliente **);
        virtual void crear_memoria();

        void liberar_memoria_np(cCliente ** target);
        void liberar_memoria();

    private:
        void llenado_nullptr();

};

#endif
