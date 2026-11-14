#include <iostream>
#include <fstream>

using namespace std;

    struct alumno {
        string nombre;
        string matricula;
        float cal[3];
        float prom;
    };
int main() {
    alumno lista_recuperada[5];    
    ifstream archenter("maestros.txt");

    if (archenter.fail()) {
        cout<<"El archivo no se encontro";
    } else {
        for (int i=0; i<5; i++) {
            archenter >> lista_recuperada[i].nombre >> lista_recuperada[i].matricula >> lista_recuperada[i].cal[0] >> lista_recuperada[i].cal[1] >> lista_recuperada[i].cal[2] >> lista_recuperada[i].prom;
        }
        archenter.close();

        for (int i=0; i<5; i++) {
            cout << lista_recuperada[i].nombre << " " << lista_recuperada[i].matricula << " " << lista_recuperada[i].cal[0] << " " << lista_recuperada[i].cal[1] << " " << lista_recuperada[i].cal[2] << " " << lista_recuperada[i].prom << endl;
        }
    }
    return 0;
}
