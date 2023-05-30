#include <string>
#include <vector>
#include "Banco.h"

std::string Banco::getClase()
{
    return clase;
}

int Banco::getCaja()
{
    return caja;
}

int Banco::getDia()
{
    return dia;
}

int Banco::getMes()
{
    return mes;
}

int Banco::getAnio()
{
    return anio;
}

void Banco::setClase(std::string _clase)
{
    clase = _clase;
}
void Banco::setCaja(int _caja)
{
    caja = _caja;
}
void Banco::setFecha(int _dia, int _mes, int _anio)
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