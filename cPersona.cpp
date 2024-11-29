#include "cPersona.hpp"
#include <iostream>
#include <ctime>

cPersona::cPersona()
{
    size_nombre = -1;
    size_telefono = -1;
    size_correo = -1;
    size_direccion = -1;
    edad = 0;
}

cPersona::cPersona(char* name, char *adress, char *mail, char *phone, int tam_nom,
                    int tam_adress, int tam_mail,int tam_phone, int age)
{
    if(llenado_nombre(name, tam_nom))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NOMBRE no LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_correo(mail, tam_mail))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"NOMBRE no LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_telefono(phone, tam_phone))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"NOMBRE no LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_direccion(adress, tam_adress))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"NOMBRE no LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_edad(age))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"NOMBRE no LLENADO CON EXITO"<<std::endl;
    }
}

cPersona::cPersona(const cPersona &obj) // Constructor de copia
{
    asignar_nullptr();

    if(asignarValores(&obj)) {
        std::cout << "SE LOGRO" << std::endl;
    } else {
        std::cout << "NO SE LOGRO" << std::endl;
    }

    std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cPersona& cPersona::operator=(const cPersona &obj) // Operador de asignación
{
    if(&obj != this) {
        if(asignarValores(&obj)) {
            std::cout << "SE LOGRO" << std::endl;
        } else {
            std::cout << "NO SE LOGRO" << std::endl;
        }
    } else {
        std::cout << "NO SE LOGRO - no copia de si mismo" << std::endl;
    }

    std::cout << "SOBRECARGA DE OPERADOR" << std::endl;
    return *this;
}

bool cPersona::asignarValores(const cPersona *obj)
{
    bool flag = true;
    if(llenado_nombre((*obj).nombre, (*obj).size_nombre))
    {
        std::cout<<"NOMBRE LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"NOMBRE no LLENO"<<std::endl;
        flag = false;
    }

    if(llenado_telefono((*obj).telefono, (*obj).size_telefono))
    {
        std::cout<<"TELEFONO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"TELEFONO no LLENO"<<std::endl;
        flag = false;
    }

    if(llenado_correo((*obj).correo, (*obj).size_correo))
    {
        std::cout<<"CORREO LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"CORREO no LLENO"<<std::endl;
        flag = false;
    }

    if(llenado_direccion((*obj).direccion, (*obj).size_direccion))
    {
        std::cout<<"DIRECCION LLENADO CON EXITO"<<std::endl;
    }
    else
    {   
        std::cout<<"DIRECCION no LLENO"<<std::endl;
        return false;
    }

    if(llenado_edad((*obj).edad) )
    {
        std::cout<<"EDAD LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"EDAD no LLENO"<<std::endl;
        flag = false;
    }

    return flag;
}

void cPersona::print()
{
    bool valido = true;

    if (nombre != nullptr)
    {
        std::cout<<"NOMBRE: " << nombre <<" tam:" << size_nombre <<std::endl;
    }
    else
    {
        std::cout << "Nombre no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (telefono != nullptr)
    {
        std::cout<<"TELEFONO: " << telefono << " tam:" << size_telefono <<std::endl;
    }
    else
    {
        std::cout << "Telefono no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (correo != nullptr)
    {
        std::cout<<"CORREO: " << correo << " tam:" << size_correo <<std::endl;
    }
    else
    {
        std::cout << "Correo no asignado (nullptr)" << std::endl;
        valido = false;
    }

    if (direccion != nullptr)
    {
        std::cout<<"DIRECCION: " << direccion << " tam:" << size_direccion <<std::endl;
    }
    else
    {
        std::cout << "Direccion no asignado (nullptr)" << std::endl;
        valido = false;
    }

    std::cout << "EDAD: " << edad << std::endl;
}

void cPersona::asignar_nullptr()
{
    nombre = nullptr;
    telefono = nullptr;
    correo = nullptr;
    direccion = nullptr;
}

bool cPersona::llenado_size_nombre(int size, char* cadena)
{
    if(size <= 1)
    {
        size = contador(cadena);
        if(size<=1)
        {
            size_nombre = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_nombre = size;
    return true;
}

bool cPersona::llenado_size_direccion(int size, char* cadena)
{
    if(size <= 1)
    {
        size = contador(cadena);
        if(size<=1)
        {
            size_direccion = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_direccion = size;
    return true;
}

bool cPersona::llenado_size_telefono(int size, char* cadena)
{
    if(size <= 1)
    {
        size = contador(cadena);
        if(size<=1)
        {
            size_telefono = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_telefono = size;
    return true;
}

bool cPersona::llenado_size_correo(int size, char* cadena)
{
    if(size <= 1)
    {
        size = contador(cadena);
        if(size<=1)
        {
            size_correo = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_correo = size;
    return true;
}

bool cPersona::llenado_nombre(char* name, int size)
{

    if(name != nullptr)
    {
        if(nombre != nullptr) 
            liberar(&nombre);

        if(llenado_size_nombre(size, name))
        {
            crear_memoria(size_nombre, &nombre);
            copiar(name, nombre, size_nombre);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR NOMBRE" <<std::endl;
    return false;
}

bool cPersona::llenado_telefono(char* tel, int size)
{

    if(tel != nullptr)
    {
        if(telefono != nullptr) 
            liberar(&telefono);

        if(llenado_size_telefono(size, tel))
        {
            crear_memoria(size_telefono, &telefono);
            copiar(tel, telefono, size_telefono);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR TELEFONO" <<std::endl;
    return false;
}

bool cPersona::llenado_correo(char* email, int size)
{
    if(email != nullptr)
    {
        if(correo != nullptr) 
            liberar(&correo);

        if(llenado_size_correo(size, email))
        {
            crear_memoria(size_correo, &correo);
            copiar(email, correo, size_correo);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR CORREO" <<std::endl;
    return false;
}

bool cPersona::llenado_direccion(char* dir, int size)
{
    if(dir != nullptr)
    {
        if(direccion != nullptr) 
            liberar(&direccion);

        if(llenado_size_direccion(size, dir))
        {
            crear_memoria(size_direccion, &direccion);
            copiar(dir, direccion, size_direccion);
            return true;
        }
    }
    std::cout<< "ERROR AL LLENAR DIRECCION" <<std::endl;
    return false;
}

bool cPersona::llenado_edad(int num)
{
    if(num<18)
    {
        edad =-1;
        std::cout<<"Edad de un menor o invalida"<<std::endl;
        return false;
    }
    edad = num;
    return true;
}

int cPersona::contador(const char* cadena)
{
    int fin = 0;
    while(*(cadena+fin) != '\0')
    {
        fin++;
    }
    return fin+1;
}

void cPersona::crear_memoria(int tam, char** destino)
{
    if (tam > 0)
    {   
        *destino = new char[tam]; 
    }
    else
    {
        *destino = nullptr;
        std::cout<<"array = 0 bytes?"<< std::endl;
    }
}

void cPersona::copiar(char* root, char* destino, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        *(destino+i) = *(root+i);
    }
    *(destino+(tam-1)) = '\0';
}

void cPersona::liberar(char** target)
{
    if (*target != nullptr) {
        delete[] *target;
        *target = nullptr;
    }
}
// Getter methods
const char* cPersona::getNombre()
{
    return nombre;
}

const char* cPersona::getTelefono()
{
    return telefono;
}

const char* cPersona::getCorreo()
{
    return correo;
}

const char* cPersona::getDireccion()
{
    return direccion;
}

int cPersona::getEdad()
{
    return edad;
}

int cPersona::getSize_nom()
{
    return size_nombre;
}

int cPersona::getSize_telef()
{
    return size_telefono;
}
int cPersona::getSize_correo()
{
    return size_correo;
}
int cPersona::getSize_direcc()
{
    return size_direccion;
}

cPersona::~cPersona()
{
    liberar(&nombre);
    liberar(&telefono);
    liberar(&correo);
    liberar(&direccion);
}
