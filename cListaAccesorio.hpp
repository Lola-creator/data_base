#include "cAccesorio.hpp"
#include "cListaPrenda.hpp"
#include <iostream>

class cListaAccesorio : public cListaPrenda
{
    public:
        cListaAccesorio();
        cListaAccesorio(cPrenda * nuevo, int tam, char *code, char * source,
                     int tam_code,int tam_source, int tam_capas);
        ~cListaAccesorio();

        int getNum_capas();

    private:
        int num_capas; //numero de capas que debe tener la base
        void crear_memoria() override;
};

#endif
