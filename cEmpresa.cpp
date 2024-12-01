#include "cCliente.hpp"
#include "cEmpresa.hpp"
#include "cFecha.hpp"
#include <iostream>
#include <ctime>

cEmpresa::cEmpresa() : cCliente()
{
    llenado_nullptr();
    descuento = -1.0;
}

cEmpresa::cEmpresa(char*razon, char*contact, char*id, char*paper, int tam_razon, int tam_contact,
                int tam_id, int tam_paper, float less_money, char*comer, char *code, char *direccion,
                int tam_comer,int tam_cod, int tam_direccion, char *regis, int tam_regis)
        :cCliente( comer, code, direccion, tam_comer, tam_cod, tam_direccion, regis, tam_regis)
{
    cCliente::fecha.actualizarFecha();
    llenado_nullptr();

    if(llenado_razon_social(razon, tam_razon))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_contacto(contact, tam_contact))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_id_fiscal(id, tam_id))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_contrato(paper, tam_paper))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
}

cEmpresa::cEmpresa(const cEmpresa &obj)
{
	if(asignar_valores(obj)) {
		std::cout << "SE LOGRO" << std::endl;
	} else {
		std::cout << "NO SE LOGRO" << std::endl;
	}

	std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cEmpresa& cEmpresa::operator=(const cEmpresa &obj)
{
	if(&obj != this) {
        cCliente::operator=(obj);

		if(asignar_valores(obj)) {  // Pasamos la dirección de `obj` para cumplir con el tipo
			std::cout << "SE LOGRO" << std::endl;
		} else {
			std::cout << "NO SE LOGRO" << std::endl;
		}
	} else {
		std::cout << "NO SE LOGRO - no copia de si mismo" << std::endl;
	}

	std::cout << "SOBRECARGA DE OPERADOR" << std::endl;
	return *this;//devolver la referencia

}

bool cEmpresa::asignar_valores(const cEmpresa &obj)
{
    bool flag = true;
    cCliente::fecha.actualizarFecha();
    llenado_nullptr();
    if(llenado_razon_social(obj.razon_social, obj.size_razon_social))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
        flag  = false;
    }
    if(llenado_contacto(obj.contacto, obj.size_contacto))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
        flag  = false;
    }
    if(llenado_id_fiscal(obj.id_fiscal, obj.size_id_fiscal))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
        flag  = false;
    }
    if(llenado_contrato(obj.contrato, obj.size_contrato))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
        flag  = false;
    }
    return flag;
}

void cEmpresa::llenado_nullptr()
{
    razon_social = nullptr;
    contacto = nullptr;
    id_fiscal = nullptr;
    contrato = nullptr;
}

bool cEmpresa::llenado_razon_social(char *cadena, int size)
{
    cCliente::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(razon_social!= nullptr)
        {   cCliente::liberar(&razon_social);  }

        if(llenado_size_razon_social(size,cadena))
        {
             cCliente::crear_memoria(size_razon_social, &razon_social);
             cCliente::copiar(cadena, razon_social, size_razon_social);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cEmpresa::llenado_contacto(char *cadena, int size)
{
    cCliente::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(contacto!= nullptr)
        {   cCliente::liberar(&contacto);  }

        if(llenado_size_contacto(size,cadena))
        {
            cCliente::crear_memoria(size_contacto, &contacto);
            cCliente::copiar(cadena, contacto, size_contacto);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cEmpresa::llenado_id_fiscal(char *cadena, int size)
{
    cCliente::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(id_fiscal!= nullptr)
        {   cCliente::liberar(&id_fiscal);  }

        if(llenado_size_id_fiscal(size,cadena))
        {
            cCliente::crear_memoria(size_id_fiscal, &id_fiscal);
            cCliente::copiar(cadena, id_fiscal, size_id_fiscal);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cEmpresa::llenado_contrato(char *cadena, int size)
{
    cCliente::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(contrato!= nullptr)
        {   cCliente::liberar(&contrato);  }

        if(llenado_size_contrato(size,cadena))
        {
            cCliente::crear_memoria(size_contrato, &contrato);
            cCliente::copiar(cadena, contrato, size_contrato);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cEmpresa::llenado_descuento(float num)
{
    if(num<=1)
    {
        descuento = -1;
        return false;
    }
    descuento = num;
    return true;
}

bool cEmpresa::llenado_size_razon_social(int size,char *cadena)
{
    cCliente::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cCliente::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_razon_social = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_razon_social = size;
    return true;
}

bool cEmpresa::llenado_size_contacto(int size,char *cadena)
{
    cCliente::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cCliente::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_contacto = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_contacto = size;
    return true;

}

bool cEmpresa::llenado_size_id_fiscal(int size,char *cadena)
{
    cCliente::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cCliente::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_id_fiscal = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_id_fiscal = size;
    return true;
}

bool cEmpresa::llenado_size_contrato(int size,char *cadena)
{
    cCliente::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cCliente::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_contrato = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_contrato = size;
    return true;
}

float cEmpresa::getDescuento()
{
    return descuento;
}

const char *cEmpresa::getRazon_social()
{
    return razon_social;
}


const char *cEmpresa::getContacto()
{
    return contacto;
}

const char *cEmpresa::getId_fiscal()
{
    return id_fiscal;
}

const char *cEmpresa::getContrato()
{
    return contrato;
}

int cEmpresa::getSize_contacto()
{
    return size_contacto;
}

int cEmpresa::getSize_razon_social()
{
    return size_razon_social;
}

int cEmpresa::getSize_id_fiscal()
{
    return size_id_fiscal;
}

int cEmpresa::getSize_contrato()
{
    return size_contrato;
}

cEmpresa::~cEmpresa()
{
    cCliente::liberar(&razon_social);
    cCliente::liberar(&contacto);
    cCliente::liberar(&id_fiscal);
    cCliente::liberar(&contrato);
}



















