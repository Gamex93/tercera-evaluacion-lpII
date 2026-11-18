#include <iostream>
#include <iomanip>

//realice un conversor de divisas: lea el inicio la tasa del dolar y la del euro en bolivares (mayores que 0) y muestre un menu
//dolar a bs, bs a dolar, euro a bs, bs a euro, salir. cada conversion debe hacerse con una funcion que reciba el monto y la tasa y devuelva el resultado.
//muestre los montos con dos decimales: use al menos dos secuencias de escape y un operador ternario.

using namespace std;

float dolarAbolivar(float montoDolar, float tasaBcv) {
    return montoDolar * tasaBcv;
}

float bolivarAdolar(float montoBolivar, float tasaDolar) {
    return montoBolivar / tasaDolar;
}

float euroAbolivar(float montoEuro, float tasaBcv) {
    return montoEuro * tasaBcv;
}

float bolivarAeuro(float montoBolivar, float tasaEuro) {
    return montoBolivar / tasaEuro;
}

int main() {
    float tasaDolar = 916;
    float tasaEuro = 1000;
    int opcion = 0;
    float monto = 0;

    do {
        cout<<"\n==============================\n";
        cout<<"\tCONVERSOR DE DIVISAS\n";
        cout<<"==============================\n";
        cout<<"1. Dolar a Bolivares\n";
        cout<<"2. Bolivares a Dolar\n";
        cout<<"3. Euro a Bolivares\n";
        cout<<"4. Bolivares a Euro\n";
        cout<<"5. Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout<<"Ingrese el monto a convertir: ";
            cin>>monto;
        }

        switch (opcion) {
            case 1:
                cout<<"\nResultado: "<<monto<<" USD = "<<dolarAbolivar(monto, tasaDolar)<<" Bs\n";
                break;
            case 2:
                cout<<"\nResultado: "<<monto<<" Bs = "<<bolivarAdolar(monto, tasaDolar)<<" USD\n";
                break;
            case 3:
                cout<<"\nResultado: "<<monto<<" EUR = "<<euroAbolivar(monto, tasaEuro)<<" Bs\n";
                break;
            case 4:
                cout<<"\nResultado: "<<monto<<" Bs = "<<bolivarAeuro(monto, tasaEuro)<<" EUR\n";
                break;
            case 5:
                cout<<"\nSaliendo del programa...\n";
                break;
            default:
                cout<<"\n[Aviso] Opcion invalida.\n";
                break;
        }
        
        if (opcion == 5) {
            cout<<"\n Programa finalizado.\n";
        } else {
            cout<<"\n Operacion completada con exito.\n";
        }

    } while (opcion != 5);

    return 0;
}
