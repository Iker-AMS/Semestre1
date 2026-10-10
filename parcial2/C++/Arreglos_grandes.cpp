/*
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    float ventas[100];
    float suma = 0;
    
    for (int i=0; i<100; i++){
        ventas[i] = 1 + rand() % 10000;
        suma += ventas[i];
        cout << "Ventas del cliente " << i + 1 << ": " << ventas[i] << endl;
    }
    cout << "La suma total de las ventas es: " << suma;
    return 0;
}
*/

#include <iostream>

using namespace std;

int main()
{
    float ventas[100];
    float suma = 0;
    
    for (int i=0; i<100; i++){
        cout << "Ingrese el total de sus ventas: " << endl;
        cin >> ventas[i];
        suma += ventas[i];
    }
    cout << "La suma total de las ventas es: " << suma;
    return 0;
}
