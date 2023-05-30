#include <string>
#include <vector>
#include "Cliente.h"

std::string Cliente::getNombre()
{
    return nombre;
}
std::string Cliente::getApellido()
{
    return apellido;
}
int Cliente::getID()
{
    return ID;
}
std::string Cliente::getEstado()
{
    return estado;
}
int Cliente::getDia()
{
    return dia;
}

int Cliente::getMes()
{
    return mes;
}

int Cliente::getAnio()
{
    return anio;
}
void Cliente::setNombre(std::string _nombre)
{
    nombre = _nombre;
}
void Cliente::setApellido(std::string _apellido)
{
    apellido = _apellido;
}
void Cliente::setID(int _ID)
{
    ID = _ID;
}
void Cliente::setEstado(std::string _estado)
{
    estado = _estado;
}

std::string Cliente::getClase()
{
    return clase;
}
int Cliente::getCaja()
{
    return caja;
}
void Cliente::setClase(std::string _clase)
{
    if (FechaActual.anio - 3 >= anio && (_clase == "Black" || _clase == "black" || _clase == "BLACK"))
    {
        clase = "Black";
    }
    else if (FechaActual.anio - 3 < anio && (_clase == "Black" || _clase == "black" || _clase == "BLACK"))
    {
        clase = "Gold";
    }
    else
    {
        clase = _clase;
    }
}
void Cliente::setCaja(int _caja)
{
    caja = _caja;
}
void Cliente::setFecha(int _dia, int _mes, int _anio)
{
    bool llave = false;
    do
    {
        if (_mes == 1 || _mes == 3 || _mes == 5 || _mes == 7 || _mes == 8 || _mes == 10 || _mes == 12)
        {
            if (_dia > 31)
            {
                _mes++;
                _dia = _dia - 31;
            }
            else
                llave = true;
                if (_mes > 12)
                {
                    _anio++;
                    _mes = _mes - 12;
                }
                
        }
        else if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11)
        {
            if (_dia > 30)
            {
                _mes++;
                _dia = _dia - 31;
            }
            else
                llave = true;
        }
        else if (_mes == 2)
        {
            if (_anio % 4 == 0 && _anio % 100 != 0 || _anio % 400 == 0)
            {
                if (_dia > 29)
                {
                    _mes++;
                    _dia = _dia - 29;
                }
                else
                    llave = true;
            }
            else
            {
                if (_dia > 28)
                {
                    _mes++;
                    _dia = _dia - 28;
                }
                else
                    llave = true;
            }
        }

        if (_mes == 1 || _mes == 3 || _mes == 5 || _mes == 7 || _mes == 8 || _mes == 10 || _mes == 12 || _mes > 12)
        {
            if (_dia > 31)
            {
                llave = false;
            } 
        }
        else if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11 || _mes > 12)
        {
            if (_dia > 30)
            {
             llave = false;
            }
        }
        else if (_mes == 2 || _mes > 12)
        {
            if (_anio % 4 == 0 && _anio % 100 != 0 || _anio % 400 == 0)
            {
                if (_dia > 29)
                {
                    llave = false;
                }
            }
            else
            {
                if (_dia > 28 || _mes > 12)
                {
                    llave = false;
                }
            }
        }
        if (_mes > 12)
                {
                    _anio++;
                    _mes = _mes - 12;
                }
    } while (llave == false);
    dia = _dia;
    mes = _mes;
    anio = _anio;
}