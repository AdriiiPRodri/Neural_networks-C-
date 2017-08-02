#include <iostream>

using namespace std;

int main() {
    int datos[4][3] = {
        { 1, 1, 1},
        { 1, 0, 0},
        { 0, 1, 0},
        { 0, 0, 0}
    }; // Tabla de verdad AND

    srand(time(NULL));      // Generamos una semilla para que nuestros aleatorios cambien en cada ejecucion de nuestro programa
    int limite = 10001;     // Este es el limite de generacion de los numeros aleatorios

    int pesos[] = {rand() % limite, rand() % limite, rand() % limite}; // Inicia los pesos al azar
    bool aprendiendo = true;
    int salidaEntera;
    int iteraciones = 0;

    while (aprendiendo) { // Mientras no la aprenda
        aprendiendo = false;
        iteraciones++;

        for (int cont = 0; cont <= 3; cont++) {
            // Funcion fitness, esta funcion es la encargada del aprendizaje, pesos[2] no es relevante en este ejercicio,es el peso umbral
            double salidaReal = datos[cont][0] * pesos[0] + datos[cont][1] * pesos[1] + pesos[2]; // Calcula la salida real

            if (salidaReal > 0) // Si la salida es igual o mayor a 1 la ajusta a 1
                salidaEntera = 1;
            else // En otro caso la ajusta a 0
                salidaEntera = 0;

            if (salidaEntera != datos[cont][2]) { // Si la salida no coincide con lo esperado, cambia los pesos al azar
                pesos[0] = rand() % limite - rand() % limite;
                pesos[1] = rand() % limite - rand() % limite;
                pesos[2] = rand() % limite - rand() % limite;
                aprendiendo = true; // Continua buscando los pesos adecuados hasta dar con los que nos sirven para
                                    // simular la tabla de verdad AND
            }
        }

        if(aprendiendo){
            cout << "*****************************************************************************************" << endl;
            cout << "\tIteracion no valida, sigue aprendiendo..." << endl;
            cout << "\t---> Peso 1 = " << pesos[0] << "\tPeso 2 = " << pesos[1] << "\tPeso 3 = " << pesos[2] << "\n" << endl;

            for(int cont = 0; cont <= 3; cont++){
                cout << "\t\tEntrada = " << datos[cont][0] << " && " << datos[cont][1] << endl;
                cout << "\t\tSalida esperada = " << datos[cont][2] << "\tObtenida = " << salidaEntera << "\n" << endl;
            }
        }
    }

    cout << "*****************************************************************************************" << endl;
    cout << "\tIteraciones hasta aprender = " << iteraciones << endl;
    cout << "\t---> Peso 1 = " << pesos[0] << "\tPeso 2 = " << pesos[1] << "\tPeso 3 = " << pesos[2] << endl;

    for (int cont = 0; cont <= 3; cont++) { // Muestra el perceptron con la tabla AND aprendida
        double salidaReal = datos[cont][0] * pesos[0] + datos[cont][1] * pesos[1] + pesos[2];	// Fitness

        if (salidaReal > 0)
            salidaEntera = 1;
        else
            salidaEntera = 0;

        cout << "\t\tEntrada = " << datos[cont][0] << " && " << datos[cont][1] << "\tObtenida = " << salidaEntera << endl;
    }

    return 0;
}
