#include <iostream>
using namespace std;

int main() {
    float grupo1 [5];
    float grupo2 [5];
    float m [5];

    for (int i = 0; i < 5; i++) {
    cout << "Ingresa la nota del alumno " << i + 1 << " del grupo A: " << endl;
    cin >> grupo1 [i];
    cout << "Ingresa la nota del alumno " << i + 1 << " del grupo B: " << endl;
    cin >> grupo2 [i];

    if (grupo1 [i] > grupo2 [i]) {
        m [i] = grupo1 [i];
        cout << "El promedio mayor es " << m [i] << " del alumno del grupo A" << endl;
    } else if (grupo1 [i] < grupo2 [i]) {
        m [i] = grupo2 [i];
        cout << "El promedio mayor es " << m [i] << " del alumno del grupo B" << endl;
    }
        else {
            m [i] = grupo1 [i];
            cout << "Ambos alumnos empataron" << endl;
        }
    }
    return 0;
}
