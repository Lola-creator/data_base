// cPersona.hpp
#ifndef CPERSONA_HPP
#define CPERSONA_HPP
#include "cFecha.hpp"

class cPersona {
protected: //atributos
    cFecha fecha;
    char* nombre;
    char* telefono;
    char* correo;
    int edad;
    int size_nombre;
    int size_telefono;
    int size_correo;
    int size_direccion;

public:
    virtual ~cPersona();
    cPersona();
    cPersona(char* name, char* code, int tam_nom, int tam_cod);
    cPersona(const cPersona& obj);
    cPersona& operator=(const cPersona& obj);

    virtual void print();
    bool llenado_nombre(char* name, int size = 0);
    bool llenado_telefono(char* telefono, int size = 0);
    bool llenado_correo(char* email, int size = 0);
    bool llenado_direccion(char* direccion, int size = 0);
    bool llenado_size_nombre(int size, char* cadena = nullptr);
    void llenado_fecha();
    void setEdad(int _edad);

    const char* getFecha();
    const char* getNombre();
    const char* getTelefono();
    const char* getCorreo();
    const char* getDireccion();
    int getEdad();
    int getSize_nom();

protected:
    virtual void ultimoAcceso();
    void asignar_nullptr();
    void llenado_generalFecha();
    bool asignarValores(const cPersona* obj);
    void copiar(char* root, char* destino, int tam);
    int contador(const char* cadena);
    void crear_memoria(int tam, char** destino);
    void liberar(char** target);
};
#endif
