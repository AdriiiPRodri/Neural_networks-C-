#include <iostream>

using namespace std;

int main() {
    int datos[4][3] = {
        { 1, 1, 1},
        { 1, 0, 0},
        { 0, 1, 0},
        { 0, 0, 0}
    }; // Tabla de verdad AND
    int pesos[] = {rand(), rand(), rand()}; // Inicia los pesos al azar
    bool aprendiendo = true;
    int salidaEntera;

    while (aprendiendo) { // Hasta que aprenda la tabla AND
        aprendiendo = false;

        for (int cont = 0; cont <= 3; cont++) {
            // Funcion fitness
            double salidaReal = datos[cont][0] * pesos[0] + datos[cont][1] * pesos[1] + pesos[2]; // Calcula la salida real

            if (salidaReal > 0)
                salidaEntera = 1;
            else
                salidaEntera = 0; // Transforma a valores 0 o 1

            if (salidaEntera != datos[cont][2]) { // Si la salida no coincide con lo esperado, cambia los pesos al azar
                pesos[0] = rand() - rand();
                pesos[1] = rand() - rand();
                pesos[2] = rand() - rand();
                aprendiendo = true; // Y sigue buscando
            }
        }
    }

    for (int cont = 0; cont <= 3; cont++) { // Muestra el perceptron con la tabla AND aprendida
        double salidaReal = datos[cont][0] * pesos[0] + datos[cont][1] * pesos[1] + pesos[2];

        if (salidaReal > 0)
            salidaEntera = 1;
        else
            salidaEntera = 0;

        cout << "Entradas: " << datos[cont][0] << " y " << datos[cont][1] << " perceptron: " << salidaEntera << endl;
    }

    return 0;
}
