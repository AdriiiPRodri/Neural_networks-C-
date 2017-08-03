#include <iostream>
#include <cmath>

// IMPORTANTE: CON ESTE METODO ES POSIBLE EXPLORAR UN MINIMO LOCAL Y QUEDARSE EN ESTE, POR LO QUE NO SE ASEGURA ENCONTRAR EL MINIMO GLOBAL

using namespace std;

double Ecuacion(const double& x){
    return 5 * x * x - 7 * x - 13;
}

int main(){
    double valorInicial = rand() % 10;
    double Yini = Ecuacion(valorInicial);
    double variacion = 1;
    double Ysigue;

    while(abs(variacion) > 0.00001){
        Ysigue = Ecuacion(valorInicial + variacion);

        if(Ysigue > Yini){      // No disminuye, seguimos hacia un paso menor
            variacion *= -1;    // Cambiamos el signo de la variacion
            variacion /= 10;    // Reducimos la variacion
        }
        else{
            Yini = Ysigue;      // Hallamos un valor menor que el anterior y disminuimos a este nuevo valor
            valorInicial += variacion;
            cout << "x: " << valorInicial << " + Yini: " << Yini << endl;
        }
    }

    cout << "Respuesta: " << valorInicial << endl;

    return 0;
}