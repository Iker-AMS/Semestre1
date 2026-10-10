#include <iostream>
using namespace std;

int main() {
    float cal [6];

    cout << "Ingrese 5 calificaciones: " << endl;
    cin >> cal [0] >> cal [1] >> cal [2] >> cal [3] >> cal [4];

    cal [5] = (cal [0] + cal [1] + cal [2] + cal [3] + cal [4]) / 5;

    cout << "Estas fueron sus calificaciones: " << endl;
    cout << cal [0] << endl;
    cout << cal [1] << endl;
    cout << cal [2] << endl;
    cout << cal [3] << endl;
    cout << cal [4] << endl;
    cout << "Su promedio es de: " << cal [5] << endl;

    return 0;
}
