#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct alumno {
        string nombre;
        string matricula;
        float cal[3];
        string grupo;
    };

struct maestro {
        string nombre;
        string materia;
        string carrera;
    };

struct grupo {
        string nombre;
        string carrera;
    };

int main() {
    vector<alumno> lista_alumnos;
    vector<maestro> lista_maestros;
    vector<grupo> lista_grupos;

    float promedio_actual;
    float promedio_mayor;
    promedio_mayor = 0;
    int opcion;
    int nalumnos;
    int ngrupos;
    int nmaestros;
    float mejor_promedio_grupo;
    mejor_promedio_grupo = 0;
    string nombre_mejor_alumno = "";
    int total_alumnos_carrera = 0;

    alumno temp_a;
    grupo temp_g;
    maestro temp_m;

    do {
        cout << "Bienvenido, seleccione una opcion: " << endl;
        cout << "1. Capturar N alumnos" << endl;
        cout << "2. Capturar grupos y carreras" << endl;
        cout << "3. Capturar maestros" << endl;
        cout << "4. Mostrar reportes" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;
    
    switch (opcion) {
        case 1:
            cout << "Ingrese el numero de alumnos: ";
            cin >> nalumnos;
            cin.ignore();

            for (int i=0; i<nalumnos; i++) {
                cout << " Alumno " << i + 1 << " ingrese su nombre: " << endl;
                getline (cin, temp_a.nombre);
                cout << "Ingrese el nombre del grupo al que pertenece: ";
                getline (cin, temp_a.grupo);
                cout << "Ingrese su matricula: ";
                cin >> temp_a.matricula;
                cout << "Ingrese sus 3 calificaciones parciales: " << endl;
                cin >> temp_a.cal[0];
                cin >> temp_a.cal[1];
                cin >> temp_a.cal[2];
                cin.ignore();
                promedio_actual = (temp_a.cal[0] + temp_a.cal[1] + temp_a.cal[2]) / 3;
                lista_alumnos.push_back(temp_a);
            }

            break;
        case 2:

            cout << "Ingrese la cantidad de grupos a capturar: ";
            cin >> ngrupos;
            cin.ignore();
            
            for (int i=0; i<ngrupos; i++) {
                cout << "Ingrese el nombre del grupo" << i + 1 << " : ";
                getline (cin, temp_g.nombre);
                cout << "Ingrese la carrera asociada: ";
                getline (cin, temp_g.carrera);
                lista_grupos.push_back(temp_g);
            }
            break;
        
        case 3:
            cout << "Ingrese el numero de maestros a capturar: ";
            cin >> nmaestros;
            cin.ignore();

            for (int i=0; i<nmaestros; i++) {
                cout << "Ingrese el nombre del maestro" << i+ 1 << " : ";
                getline (cin, temp_m.nombre);
                cout << "Ingrese la materia que imparte: ";
                getline (cin, temp_m.materia);
                cout << "Ingrese la carrera en la que imparte clases: ";
                getline (cin, temp_m.carrera);
                lista_maestros.push_back(temp_m);
            }
            break;

        case 4:

        if (lista_alumnos.empty()) {
            cout << "No hay alumnos capturados, ingrese los datos primero" << endl;
            break;
        }
            cout << "Lista de alumnos: " << endl;
            for (int i=0; i<lista_alumnos.size(); i++) {
                cout << "Alumno " << i + 1 << ": " << endl;
                cout << "Nombre: " << lista_alumnos[i].nombre << endl;
                cout << "Matricula: " << lista_alumnos[i].matricula << endl;
                promedio_actual = (lista_alumnos[i].cal[0] + lista_alumnos[i].cal[1] + lista_alumnos[i].cal[2]) / 3.0;
                cout << "Promedio de 3 parciales: " << promedio_actual << endl;

                if (promedio_actual > promedio_mayor) {
                    promedio_mayor = promedio_actual;
                }
            }
            
            for (int i=0; i<lista_grupos.size(); i++) {
                mejor_promedio_grupo = 0;
                nombre_mejor_alumno = "";
                for (int j=0; j<lista_alumnos.size(); j++) {
                    if (lista_alumnos[j].grupo == lista_grupos[i].nombre) {
                        promedio_actual = (lista_alumnos[j].cal[0] + lista_alumnos[j].cal[1] + lista_alumnos[j].cal[2]) / 3.0;
                        if (promedio_actual > mejor_promedio_grupo) {
                            mejor_promedio_grupo = promedio_actual;
                            nombre_mejor_alumno = lista_alumnos[j].nombre;
                        }
                    }
                }
                cout << "Grupo " << lista_grupos[i].nombre << endl;
                cout << "Promedio mas alto del grupo: " << mejor_promedio_grupo << " del alumno: " << nombre_mejor_alumno << endl;

                total_alumnos_carrera = 0;
                    for (int j=0; j<lista_alumnos.size(); j++) {
                        if (lista_alumnos[j].grupo == lista_grupos[i].nombre) {
                            total_alumnos_carrera++;
                        }
                    }
                cout << "La carrera de " << lista_grupos[i].carrera << " cuenta con un total de: " << total_alumnos_carrera << " alumnos." << endl;
                
            }

            for (int i=0; i<lista_maestros.size(); i++) {
                cout << "Maestro: " << lista_maestros[i].nombre << endl;
                cout << "Materia: " << lista_maestros[i].materia << endl;
                cout << "Carrera: " << lista_maestros[i].carrera << endl;
            }

            break;

        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        }

    }
        while (opcion != 5);

    return 0;
}
