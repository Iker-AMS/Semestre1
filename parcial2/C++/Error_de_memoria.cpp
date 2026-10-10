#include <iostream>
using namespace std;

void usarPuntero(int* ptr) {
    
    cout << "El valor en la memoria es: " << *ptr << endl;
}

int main() {
     // int* ptrSalvaje;          
     // usarPuntero(ptrSalvaje);

    int numero = 42;
    int* ptrCorrecto = &numero;

    usarPuntero(ptrCorrecto);

    return 0;
}
