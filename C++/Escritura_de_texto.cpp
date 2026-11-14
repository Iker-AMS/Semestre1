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
    alumno lista_alumnos[5];
    
    for (int i=0; i<5; i++) {
        cout << "Alumno " << i + 1 << ", ingrese su nombre: " << endl;
        getline(cin, lista_alumnos[i].nombre);
        cout << "Ingrese su matricula: ";
        cin >> lista_alumnos[i].matricula;
        cout << "Ingrese sus 3 calificaciones parciales: " << endl;
        cin >> lista_alumnos[i].cal[0];
        cin >> lista_alumnos[i].cal[1];
        cin >> lista_alumnos[i].cal[2];
        cin.ignore();
        lista_alumnos[i].prom = (lista_alumnos[i].cal[0] + lista_alumnos[i].cal[1] + lista_alumnos[i].cal[2]) / 3.0;
    }

    ofstream archexit("alumnos.txt");
    for (int i=0; i<5; i++){
        archexit<<lista_alumnos[i].nombre<<" "<<lista_alumnos[i].matricula<<" "<<lista_alumnos[i].cal[0]<<" "<<lista_alumnos[i].cal[1]<<" "<<lista_alumnos[i].cal[2]<<" "<<lista_alumnos[i].prom<<endl;
    }
    archexit.close();
    return 0;
}
