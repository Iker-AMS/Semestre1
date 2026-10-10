#include <iostream>
using namespace std;

int main () {
    float numeros[10][3];

    for (int i=0; i<10; i++) {
        cout << "Ingrese un promedio del grupo A para el alumno " << i + 1 << ": " << endl;
            cin >> numeros[i][0];
        cout << "Ingrese un promedio del grupo B para el alumno " << i + 1 << ": " << endl;
            cin >> numeros[i][1];
            
        if (numeros[i][0] > numeros[i][1]) {
            numeros[i][2] = numeros[i][0];
            
        } else if (numeros[i][0] < numeros[i][1]) {
            numeros[i][2] = numeros[i][1];
            }else {
                numeros[i][2] = numeros[i][0];
            }
    }

    cout << "\nGrupo A\t\tGrupo B\t\tPromedio Mayor" << endl;
    for (int i=0; i<10; i++) {
        for (int j=0; j<3; j++) {
            cout << numeros[i][j] << "\t\t";
        }
        cout << endl;
    }
    return 0;
}
