#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void jugarRuleta() {
    int numeros[6] = {2, 4, 6, 8, 10, 3}; // 5 pares, 1 impar
    int paresSeguidos = 0;
    int jugadas = 0;
    
    cout << "\n🎯 Nueva partida de la ruleta!" << endl;
    cout << "Reglas:\n- Si sale un IMPAR -> Ganás la ronda y el contador se reinicia." << endl;
    cout << "- Si salen los 5 PARES antes del impar -> Perdés.\n" << endl;

    while (true) {
        cout << "Presioná ENTER para girar la ruleta...";
        cin.ignore(); // Espera ENTER
        jugadas++;

        int numero = numeros[rand() % 6]; // Número aleatorio del arreglo
        cout << "Giro " << jugadas << ": salió el " << numero << endl;

        if (numero % 2 == 0) {
            paresSeguidos++;
            cout << "🔥 Llevás " << paresSeguidos << " pares seguidos.\n" << endl;
        } else {
            paresSeguidos = 0;
            cout << "🎉 ¡GANASTE ESTA RONDA! Tocó un impar, el contador se reinicia.\n" << endl;
        }

        if (paresSeguidos == 5) {
            cout << "💀 ¡PERDISTE! Salieron TODOS los números pares antes del impar." << endl;
            break;
        }
    }
}

int main() {
    srand(time(0)); // Inicializa aleatorios

    while (true) {
        jugarRuleta();
        char opcion;
        cout << "\n¿Querés jugar otra vez? (s/n): ";
        cin >> opcion;
        cin.ignore(); // Limpia el buffer

        if (tolower(opcion) != 's') {
            cout << "\n👋 Gracias por jugar, ¡hasta la próxima!" << endl;
            break;
        }
    }

    return 0;
}