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

    while (aprendiendo) { // Mientras no la aprenda
        aprendiendo = false;

        for (int cont = 0; cont <= 3; cont++) {
            // Funcion fitness, esta funcion es la encargada del aprendizaje, pesos[2] no es relevante en este ejercicio,es el peso umbral
            double salidaReal = datos[cont][0] * pesos[0] + datos[cont][1] * pesos[1] + pesos[2]; // Calcula la salida real

            if (salidaReal > 0) // Si la salida es igual o mayor a 1 la ajusta a 1
                salidaEntera = 1;
            else // En otro caso la ajusta a 0
                salidaEntera = 0;

            if (salidaEntera != datos[cont][2]) { // Si la salida no coincide con lo esperado, cambia los pesos al azar
                pesos[0] = rand() - rand();
                pesos[1] = rand() - rand();
                pesos[2] = rand() - rand();
                aprendiendo = true; // Continua buscando los pesos adecuados hasta dar con los que nos sirven para
                                    // simular la tabla de verdad AND
            }
        }
    }

    for (int cont = 0; cont <= 3; cont++) { // Muestra el perceptron con la tabla AND aprendida
        double salidaReal = datos[cont][0] * pesos[0] + datos[cont][1] * pesos[1] + pesos[2];	// Fitness

        if (salidaReal > 0)
            salidaEntera = 1;
        else
            salidaEntera = 0;

        cout << "Entradas: " << datos[cont][0] << " y " << datos[cont][1] << " perceptron: " << salidaEntera << endl;
    }

    return 0;
}
