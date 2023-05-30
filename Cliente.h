#include <string>
#include <vector>
#include "Banco.h"
#include "Transacciones.h"
#pragma once
class Cliente : public Banco
{
private:
    std::string nombre;
    std::string apellido;
    int ID;
    std::string estado;

public:
    Cliente(std::string _nombre, std::string _apellido, int _ID, std::string _estado, std::string _clase, int _caja, int _dia, int _mes, int _anio)
    {
        nombre = _nombre;
        apellido = _apellido;
        ID = _ID;
        estado = _estado;
        clase = _clase;
        caja = _caja;
        dia = _dia;
        mes = _mes;
        anio = _anio;
    }
    Cliente()
    {
        nombre = "";
        apellido = "";
        ID = 0;
        estado = "";
        clase = "";
        caja = 0;
        dia = 0;
        mes = 0;
        anio = 0;
    }
    Banco FechaActual;
    std::vector<Transacciones> transaccion;
    std::string getNombre();
    std::string getApellido();
    int getID();
    std::string getEstado();
    void setNombre(std::string _nombre);
    void setApellido(std::string _apellido);
    void setID(int _ID);
    void setEstado(std::string _estado);
    std::string getClase();
    int getCaja();
    int getDia();
    int getMes();
    int getAnio();
    void setClase(std::string _clase);
    void setCaja(int _caja);
    void setFecha(int _dia, int _mes, int _anio);
};
