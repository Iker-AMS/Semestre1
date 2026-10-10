#include <iostream>
using namespace std;

void intercambiePuntero (int*a, int*b){
        int temp= *a;
        *a = *b;
        *b = temp;
    }

int main() {
    int x=9, y=70;
    int *ptrx= &x;
    int *ptry= &y;
    cout << "Antes de intercambiar: x= " << x << ", y= " << y << endl;
    cout << '\n';
    intercambiePuntero(ptrx, ptry);
    cout << "Despues de intercambiar: x= " << x << ", y= " << y << endl;
    
    return 0;
}
