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

    alumno nuevo_alumno;

    cout << "Alumno nuevo, ingrese su nombre: " << endl;
    getline(cin, nuevo_alumno.nombre);
    cout << "Ingrese su matricula: ";
    cin >> nuevo_alumno.matricula;
    cout << "Ingrese sus 3 calificaciones parciales: " << endl;
    cin >> nuevo_alumno.cal[0];
    cin >> nuevo_alumno.cal[1];
    cin >> nuevo_alumno.cal[2];
    cin.ignore();
    nuevo_alumno.prom = (nuevo_alumno.cal[0] + nuevo_alumno.cal[1] + nuevo_alumno.cal[2]) / 3.0;

    ofstream newarch("alumnos.txt", ios::app);
    newarch<<nuevo_alumno.nombre<<" "<<nuevo_alumno.matricula<<" "<<nuevo_alumno.cal[0]<<" "<<nuevo_alumno.cal[1]<<" "<<nuevo_alumno.cal[2]<<" "<<nuevo_alumno.prom<<endl;
    newarch.close();

    return 0;
}
