#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    struct alumno {
        string nombre;
        string matricula;
        float cal[3];
        float prom;
    };
int main() {
    alumno lista_recuperada[5];    
    ifstream archenter("alumnos.txt");
    string nombre_mejor_alumno;

    for (int i=0; i<5; i++) {
        archenter >> lista_recuperada[i].nombre >> lista_recuperada[i].matricula >> lista_recuperada[i].cal[0] >> lista_recuperada[i].cal[1] >> lista_recuperada[i].cal[2] >> lista_recuperada[i].prom;
    }
    archenter.close();

    for (int i=0; i<5; i++) {
        cout << lista_recuperada[i].nombre << " " << lista_recuperada[i].matricula << " " << lista_recuperada[i].cal[0] << " " << lista_recuperada[i].cal[1] << " " << lista_recuperada[i].cal[2] << " " << lista_recuperada[i].prom << endl;
    }

    alumno temporal;
    for (int i=0; i<5; i++) {
        for (int j=0; j<4; j++) {
            if (lista_recuperada[j].prom < lista_recuperada[j+1].prom) {
                temporal = lista_recuperada[j];
                lista_recuperada[j] = lista_recuperada[j+1];
                lista_recuperada[j+1] = temporal;
            }
        }
    }

    ofstream archexit("top globales.txt");
    for (int i=0; i<5; i++) {
        archexit <<"Lugar "<<i+1<< ": " <<lista_recuperada[i].nombre<<" "<<"Promedio: "<<lista_recuperada[i].prom<<endl;
    }
    archexit.close();

    return 0;
}
