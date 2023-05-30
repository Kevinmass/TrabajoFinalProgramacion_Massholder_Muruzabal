#include <string>
#include <vector>
#include "Banco.h"
class Transacciones : public Banco
{
private:
    int NumeroTransaccion;

public:
    Transacciones(std::string _clase, int _caja, int _dia, int _mes, int _anio, int _NumeroTransaccion)
    {
        clase = _clase;
        caja = _caja;
        dia = _dia;
        mes = _mes;
        anio = _anio;
        NumeroTransaccion = _NumeroTransaccion;
    }
    Transacciones()
    {
        clase = "";
        caja = 0;
        dia = 0;
        mes = 0;
        anio = 0;
        NumeroTransaccion = 0;
    }
    int getNumeroTransaccion();
    void setNumeroTransaccion(int _NumeroTransaccion);
    void operator+(int x);
    void operator-(int x);
    std::string getClase();
    int getCaja();
    int getDia();
    int getMes();
    int getAnio();
    void setClase(std::string _clase);
    void setCaja(int _caja);
    void setFecha(int _dia, int _mes, int _anio);
};
