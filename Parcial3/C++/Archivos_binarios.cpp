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
    int pesotxt;
    int pesobin;
    
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

    ofstream archivo_txt("alumnos.txt");
    for (int i = 0; i < 5; i++) {
        archivo_txt << lista_alumnos[i].nombre << " " << lista_alumnos[i].matricula << " " << lista_alumnos[i].cal[0] << " " << lista_alumnos[i].cal[1] << " " << lista_alumnos[i].cal[2] << " " << lista_alumnos[i].prom << endl;
    }

archivo_txt.close();

    ofstream archexit("alumnos.bin", ios::binary);

    archexit.write((char*)&lista_alumnos, sizeof(lista_alumnos));    
    archexit.close();

    ifstream archenter("alumnos.txt");
    archenter.seekg(0, ios::end);
    pesotxt = archenter.tellg();
    archenter.close();

    ifstream archenterb("alumnos.bin", ios::binary);
    archenterb.seekg(0, ios::end);
    pesobin = archenterb.tellg();
    archenterb.close();

    cout<<"El peso del archivo en texto es: "<<pesotxt<<endl;
    cout<<"El peso del archivo en binario es: "<<pesobin<<endl;

    return 0;
}
