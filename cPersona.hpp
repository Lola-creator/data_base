// cPersona.hpp
#ifndef CPERSONA_HPP
#define CPERSONA_HPP
#include <iostream>
class cPersona {

protected: //atributos
    char* nombre;
    char* telefono;
    char* correo;
    char* direccion;
    int edad;
    int size_nombre;
    int size_telefono;
    int size_correo;
    int size_direccion;

public:
    virtual ~cPersona();
    explicit cPersona();
    explicit cPersona(char* name, char *adress, char *mail, char *phone, int tam_nom,
             int tam_adress, int tam_mail,int tam_phone, int age);
    explicit cPersona(const cPersona& obj);
    cPersona& operator=(const cPersona& obj);

    virtual void print();
    bool llenado_nombre(char* name, int size = 0);
    bool llenado_telefono(char* telefono, int size = 0);
    bool llenado_correo(char* email, int size = 0);
    bool llenado_direccion(char* direccion, int size = 0);
    bool llenado_size_nombre(int size, char* cadena = nullptr);
    bool llenado_size_telefono(int size, char* cadena = nullptr);
    bool llenado_size_correo(int size, char* cadena = nullptr);
    bool llenado_size_direccion(int size, char* cadena = nullptr);
    bool llenado_edad(int num);

    const char* getNombre();
    const char* getTelefono();
    const char* getCorreo();
    const char* getDireccion();
    int getEdad();
    int getSize_telef();
    int getSize_correo();
    int getSize_direcc();
    int getSize_nom();

protected:
    void asignar_nullptr();
    bool asignarValores(const cPersona* obj);
    void copiar(char* root, char* destino, int tam);
    int contador(const char* cadena);
    void crear_memoria(int tam, char** destino);
    void liberar(char** target);
};
#endif
