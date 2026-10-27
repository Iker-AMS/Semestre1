#include <iostream>
using namespace std;

int main() {
    float cal [6];
    cal[5]=0;

    for (int i=0; i<5; i++) {
    cout << "Ingrese la calificacion " << i+1 << ": ";
    cin >> cal [i];
    cal [5] += cal [i];
    }
    cal[5] = cal[5] / 5.0;

    cout << "Estas fueron sus calificaciones: \n" << endl;
    for (int i=0; i<5; i++){
    cout << "Calificacion " << i+1 << " :" << cal [i] << endl;
    }

    cout << "\nSu promedio es de: " << cal [5] << endl;
    return 0;
}
