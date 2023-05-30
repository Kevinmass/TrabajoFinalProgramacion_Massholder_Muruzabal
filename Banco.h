#include <string>
#include <vector>
#pragma once
class Banco
{
protected:
    std::string clase;

public:
    int caja;
    int dia;
    int mes;
    int anio;
    Banco(std::string _clase, int _caja, int _dia, int _mes, int _anio)
    {
        clase = _clase;
        caja = _caja;
        dia = _dia;
        mes = _mes;
        anio = _anio;
    }
    Banco()
    {
        clase = "Bronce";
        caja = 0;
        dia = 1;
        mes = 6;
        anio = 2023;
    }
    virtual std::string getClase();
    virtual int getCaja();
    virtual int getDia();
    virtual int getMes();
    virtual int getAnio();
    virtual void setClase(std::string _clase);
    virtual void setCaja(int _caja);
    virtual void setFecha(int _dia, int _mes, int _anio);
};
