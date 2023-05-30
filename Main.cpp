#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "Transacciones.h"
using namespace std;

void PrimerIngreso(vector<Cliente> &C)
{
    int n, p, q, x;
    string m;
    cout << "**No hay clientes registrados en el sistema...\n**Ingrese un cliente para continuar...\n\nCuantos clientes desea ingresar?\n\n";
    cin >> x;
    
    try
    {
        for (int i = 0; i < x; i++)
    {
        C.push_back(Cliente());
        Cliente *y = &C[i];
        cout << "Cliente nro: " << i + 1 << ":\n";
        cout << "Ingrese Nombre del cliente: \n";
        cin >> m;
        y->setNombre(m);
        cout << "\nIngrese Apellido del cliente: \n";
        cin >> m;
        y->setApellido(m);
        cout << "\nIngrese el ID del cliente: \n";
        cin >> n;
        y->setID(n);
        cout << "\nIngrese el estado de la cuenta: \n";
        cin >> m;
        y->setEstado(m);
        cout << "\nIngrese la fecha en la que la cuenta fue creada: \n";
        cout << "Dia: \n";
        cin >> n;
        cout << "Mes: \n";
        cin >> p;
        cout << "Anio: \n";
        cin >> q;
        y->setFecha(n, p, q);
        cout << "\nIngrese la clase de cuenta: \n\n**CUENTAS CON 3 O MAS ANIOS DE ANTIGUEDAD PUEDEN SER CLASE BLACK**\n**CUENTAS QUE NO CUMPLAN EL REQUERIMIENTO SERAN CONVERTIDAS CLASE GOLD**\n";
        cin >> m;
        y->setClase(m);
        cout << "\nIngrese la cantidad de dinero que tiene actualmente el cliente: \n";
        cin >> n;
        y->setCaja(n);
        delete y;
        cout << "------------------------------------------------------------------------------------\n\n";
    }
    }
    catch(std::bad_alloc& e)
    {
        cout<<"Memoria Insuficiente\n";
    }
    
    
} // Funciona

void Estado(vector<Cliente> &C)
{
    int a = size(C);
    for (int i = 0; i < a; i++)
    {
        Cliente *x = &C[i];
        cout << "\n\nCliente ID: " << x->getID() << "\n";
        cout << "Nombre: " << x->getNombre() << "\n";
        cout << "Apellido: " << x->getApellido() << "\n";
        cout << "Estado: " << x->getEstado() << "\n";
        cout << "------------------------------------------------------------------------------------\n\n";
        delete x;
    }
} // Funciona

void MenuMantenimiento(vector<Cliente> &C)
{
    int n, p, q, x;
    string m;
    bool llave = false;
    cout << "\n\n--MENU MANTENIMIENTO--\n";
    do
    {
        cout << "\n\nQue desea hacer?\n1-Modificar datos de un cliente\n2-Modificar estado de una cuenta\n3-Modificar clase de una cuenta\n4-Regresar al menu principal\n";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\n\nIngrese el ID del cliente que desea modificar: \n\n";
            cin >> n;
            q=0;
            for (int i = 0; i < size(C); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    q=1;
                    cout<<"\n\nCliente encontrado...\n\n";
                    cout << "Ingrese el nuevo nombre: \n";
                    cin >> m;
                    y->setNombre(m);
                    cout << "Ingrese el nuevo apellido: ";
                    cin >> m;
                    y->setApellido(m);
                }
                delete y;
            }
            break;
            if (q == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 2:
            cout << "\n\nIngrese el ID del cliente que desea modificar: \n\n";
            cin >> n;
            q=0;
            for (int i = 0; i < size(C); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    q=1;
                    cout<<"\n\nCliente encontrado...\n\n";
                    cout << "Ingrese el nuevo estado: ";
                    cin >> m;
                    y->setEstado(m);
                }
                delete y;
            }
            break;
            if (q == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 3:
            cout << "\n\nIngrese el ID del cliente que desea modificar: \n";
            cin >> n;
            q=0;
            for (int i = 0; i < size(C); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    q=1;
                    cout << "Ingrese la nueva clase: \n";
                    cin >> m;
                    y->setClase(m);
                }
                delete y;
            }
            break;
            if (q == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 4:
            cout << "\n\nSaliendo del menu de mantenimiento...\n";
            llave = true;
            break;

        default:
            cout << "Opcion no valida...\n";
            break;
        }
    } while (llave == false);
} // Funciona

void MenuTransacciones(vector<Cliente> &C, int &nro)
{
    int n, p, q, x;
    string m;
    bool llave = false;
    cout << "\n\n--MENU TRANSACCIONES--\n";
    do
    {
        cout << "\n\nQue desea hacer?\n1-Depositar en un cliente\n2-Retirar de un cliente\n3-Ver transacciones realizadas\n4-Regresar al menu principal\n";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\n\nIngrese el ID del cliente al que desea depositarle: \n";
            cin >> n;
            q=0;
            for (int i = 0; i < size(C); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    
                    try
                    {
                    y->transaccion.push_back(Transacciones());
                    q=1;
                    y->transaccion.back() + (n);
                    nro++;
                    y->transaccion.back().setNumeroTransaccion(nro);
                    cout << "\nTransaccion nro: " << nro << "\n";
                    cout << "Ingrese la fecha de deposito: \n";
                    cout << "Dia: \n";
                    cin >> n;
                    cout << "Mes: \n";
                    cin >> p;
                    cout << "Anio: \n";
                    cin >> q;
                    y->transaccion.back().setFecha(n, p, q);
                    cout << "Ingrese el tipo de transaccion: \n";
                    cin >> m;
                    y->transaccion.back().setClase(m);
                    cout << "Ingrese la cantidad a depositar: \n";
                    cin >> n;
                    y->transaccion.back() + (n);
                    }
                    catch(std::bad_alloc& e)
                    {
                        cout<<"Memoria Insuficiente\n";
                    }
                    
                }
                delete y;
            }
            break;
            if (q==0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
            
        case 2:
            cout << "\n\nIngrese el ID del cliente al que desea retirarle: \n";
            cin >> n;
            q=0;
            for (int i = 0; i < size(C); i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    
                    try
                    {
                    y->transaccion.push_back(Transacciones());
                    q=1;
                    y->transaccion.back() + (n);
                    nro++;
                    y->transaccion.back().setNumeroTransaccion(nro);
                    cout << "Transaccion nro: " << nro << "\n";
                    cout << "Ingrese la fecha del retiro: \n";
                    cout << "Dia: \n";
                    cin >> n;
                    cout << "Mes: \n";
                    cin >> p;
                    cout << "Anio: \n";
                    cin >> q;
                    y->transaccion.back().setFecha(n, p, q);
                    cout << "Ingrese el tipo de transaccion: \n";
                    cin >> m;
                    y->transaccion.back().setClase(m);
                    cout << "Ingrese la cantidad a retirar: \n";
                    cin >> n;
                    y->transaccion.back() - (n);
                    }
                    catch(std::bad_alloc& e)
                    {
                        cout<<"Memoria Insuficiente\n";
                    }
                    
                }
                delete y;
            }
            break;
            if (q==0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }
        case 3:
            p = 1;
            for (int i = 0; i < size(C); i++)
                {
                    Cliente *y = &C[i];
                    if (size(y->transaccion) == 0)
                    {
                        p=0;
                    }
                    delete y;
                } 
                if (p==1)
                {
                    cout << "\n\nQue periodo desea ver?\n1-Por periodo de 6 meses\n2-Por periodo de un anio\n3-Todas las transacciones\n";
            cin >> x;
            switch (x)
            {
            case 1:
                for (int i = 0; i < size(C); i++)
                {
                    Cliente *y = &C[i];
                    for (int j = 0; j < size(y->transaccion); j++)
                    {
                        if (y->FechaActual.mes - 6 < y->transaccion[j].getMes() && y->FechaActual.anio == y->transaccion[i].getAnio())
                        {
                            cout << "Transaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                            cout << "     Cantidad: " << y->transaccion[j].getCaja();
                            cout << "     Tipo: " << y->transaccion[j].getClase();
                            cout << "     Dia: " << y->transaccion[j].getDia();
                            cout << "     Mes: " << y->transaccion[j].getMes();
                            cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                            cout << "      Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                            cout << "------------------------------------------------------------------------------------------\n\n";
                        }
                    }
                    delete y;
                } // No funciona

                break;
            case 2:
                for (int i = 0; i < size(C); i++)
                {
                    Cliente *y = &C[i];
                    for (int j = 0; j < size(y->transaccion); j++)
                    {
                        if (y->FechaActual.anio - 1 < y->transaccion[j].getAnio())
                        {
                            cout << "Transaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                            cout << "     Cantidad: " << y->transaccion[j].getCaja();
                            cout << "     Tipo: " << y->transaccion[j].getClase();
                            cout << "     Dia: " << y->transaccion[j].getDia();
                            cout << "     Mes: " << y->transaccion[j].getMes();
                            cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                            cout << "      Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                            cout << "------------------------------------------------------------------------------------------\n\n";
                        }
                    }
                    delete y;
                } // No funciona
                break;
            case 3:
                for (int i = 0; i < size(C); i++)
                {
                    Cliente *y = &C[i];
                    for (int j = 0; j < size(y->transaccion); j++)
                    {
                        cout << "Transaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                        cout << "     Cantidad: " << y->transaccion[j].getCaja();
                        cout << "     Tipo: " << y->transaccion[j].getClase();
                        cout << "     Dia: " << y->transaccion[j].getDia();
                        cout << "     Mes: " << y->transaccion[j].getMes();
                        cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                        cout << "      Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                        cout << "------------------------------------------------------------------------------------------\n\n";
                    }
                    delete y;
                } // Probablemente funciona

                break;

            default:
                cout << "Opcion no valida...\n";
                break;
            }
            break;
                }else cout<<"\n\n**Aun no se han realizado transacciones**\n\n";      
        case 4:
            cout << "\n\nSaliendo del menu de transacciones...\n";
            llave = true;
            break;

        default:
            cout << "Opcion no valida...\n";
            break;
        }
    } while (llave == false);
} // Funciona parcialmente, revisar, no modifica la caja del cliente

void MenuConsultas(vector<Cliente> &C, int &nro)
{
    int n, p = size(C), q, x;
    string m;
    bool llave = false;

    cout << "\n\n--CONSULTAS VARIAS--\n";
    do
    {
        cout << "\n\nQue desea hacer?\n1-Consultar cliente por ID\n2-Listado de todos los clientes\n3-Transacciones realizadas por cada cliente\n4-Salir\n\n";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Ingrese el ID del cliente al que busca: \n";
            cin >> n;
            q = 0;
            for (int i = 0; i < p; i++)
            {
                Cliente *y = &C[i];
                if (y->getID() == n)
                {
                    q = 1;
                    cout << "\n\nCliente encontrado...\n\n";
                    cout << "Nombre: " << y->getNombre() << " \n Apellido:" << y->getApellido() << "\n";
                    cout << "Estado de cuenta: " << y->getEstado() << "\n";
                    cout << "Clase: " << y->getClase() << "\n";
                    cout << "Saldo actual: $" << y->getCaja() << "\n";
                    cout << "Fecha de creacion de la cuenta: " << y->getDia() << " / " << y->getMes() << " / " << y->getAnio() << "\n";
                }
                delete y;
            }
            if (q == 0)
            {
                cout << "Cliente no encontrado...\n Verifique el ID ingresado...\n";
            }

            break;
        case 2:
            for (int i = 0; i < p; i++)
            {
                Cliente *y = &C[i];
                cout << "\nID: " << y->getID() << "\n";
                cout << "Nombre: " << y->getNombre() << " \n Apellido:" << y->getApellido() << "\n";
                cout << "Estado de cuenta: " << y->getEstado() << "\n";
                cout << "Clase: " << y->getClase() << "\n";
                cout << "Saldo actual: $" << y->getCaja() << "\n";
                cout << "Fecha de creacion de la cuenta: " << y->getDia() << "/" << y->getMes() << "/" << y->getAnio() << "\n";
                cout << "------------------------------------------------------------------------------------------\n\n";
                delete y;
            }

            break;
        case 3:
        p = 1;
            for (int i = 0; i < size(C); i++)
                {
                    Cliente *y = &C[i];
                    if (size(y->transaccion) == 0)
                    {
                        p=0;
                    }
                    delete y;
                } 
                if (p==1)
                {
            for (int i = 0; i < p; i++)
            {

                Cliente *y = &C[i];
                q = size(y->transaccion);
                for (int j = 0; j < q; j++)
                {
                    cout << "Transaccion nro: " << y->transaccion[j].getNumeroTransaccion();
                    cout << "     Cantidad: " << y->transaccion[j].getCaja();
                    cout << "     Tipo: " << y->transaccion[j].getClase();
                    cout << "     Dia: " << y->transaccion[j].getDia();
                    cout << "     Mes: " << y->transaccion[j].getMes();
                    cout << "     Anio: " << y->transaccion[j].getAnio() << "\n";
                    cout << "     Cliente: " << y->getNombre() << " " << y->getApellido() << "\n";
                    cout << "------------------------------------------------------------------------------------------\n\n";
                }
                delete y;
            } // No funciona, revisar

            break;
            }else cout<<"\n\n**Aun no se han realizado transacciones**\n\n";
        case 4:
            cout << "Saliendo del menu de consultas...\n";
            llave = true;
            break;

        default:
            cout << "Opcion no valida...\n";
            break;
        }

    } while (llave == false);
} // Funciona parcialmente, revisar caso 3
int main()
{
    int n, p, q, x, nro = 0;
    string m;
    Banco b;
    vector<Cliente> C;
    bool llave = false;
    cout << "INICIANDO SISTEMA BANCARIO...\n\n\n";
    cout << "----BIENVENIDO AL SISTEMA BANCARIO DE UCC----\n\n";
    do
    {
        if (size(C) == 0)
        {
            PrimerIngreso(C);
        }
        cout << "\n\n--MENU PRINCIPAL--\n";
        cout << "Que desea hacer?\n1-Mantenimiento de cuentas\n2-Menu TRANSACCIONES\n3-Menu Consultas varias\n4-Salir\n";
        cin >> x;
        switch (x)
        {
        case 1:
            Estado(C);
            MenuMantenimiento(C);
            break;
        case 2:
            MenuTransacciones(C, nro);
            break;
        case 3:
            MenuConsultas(C, nro);
            break;
        case 4:
            llave = true;
            cout << "\n\nGracias por utilizar nuestro sistema...\n";
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion no valida...\n";
            break;
        }
    } while (llave == false);

    return 0;
}