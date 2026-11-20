#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>

using namespace std;

// Structs
struct alumno {
    string nombre;
    string matricula;
    float cal[3];
    int grupo;
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

// Funciones
float calProm(float c1, float c2, float c3);
int freeBuffer(int v1, int v2);
float leerFloatRango(float minVal, float maxVal);
void mostrarGrupos(const vector<grupo>& lista_grupos);
void guardarDatos(const vector<alumno>& lista_alumnos, const vector<grupo>& lista_grupos, const vector<maestro>& lista_maestros, const string& archivo_nombre);
void cargarDatos(vector<alumno>& lista_alumnos, vector<grupo>& lista_grupos, vector<maestro>& lista_maestros, const string& archivo_nombre);
void generarReportePromedio(const vector<alumno>& lista_alumnos, const vector<grupo>& lista_grupos, const string& reporte_nombre);

int main() {
    vector<alumno> lista_alumnos;
    vector<maestro> lista_maestros;
    vector<grupo> lista_grupos;

    const string ARCHIVO_DATOS = "datos_v3.txt";
    const string ARCHIVO_REPORTE = "reporte_alumnos.txt";

    float promedio_actual;
    int opcion;
    int nalumnos;
    int ngrupos = 0;
    int nmaestros;
    float mejor_promedio_grupo = 0;
    string nombre_mejor_alumno = "";
    int total_alumnos_carrera = 0;

    alumno temp_a;
    grupo temp_g;
    maestro temp_m;

    temp_a.grupo = 0;

    cargarDatos(lista_alumnos, lista_grupos, lista_maestros, ARCHIVO_DATOS);

    do {
        cout << "====================================================" << endl;
        cout << "Bienvenido, seleccione una opcion según el número: " << endl;
        cout << "1. Capturar N alumnos" << endl;
        cout << "2. Capturar grupos y carreras" << endl;
        cout << "3. Capturar maestros" << endl;
        cout << "4. Mostrar reportes" << endl;
        cout << "5. Guardar datos en archivo" << endl;
        cout << "6. Cargar datos desde archivo" << endl;
        cout << "7. Generar reporte ordenado por promedio" << endl;
        cout << "8. Salir" << endl;
        cout << "====================================================" << endl;
        opcion = freeBuffer(1, 8);

        switch (opcion) {
            case 1:
                if (lista_grupos.empty()) {
                    cout << "Primero captura grupos en la opcion 2 antes de registrar alumnos." << endl;
                    break;
                }
                cout << "Ingrese el numero de alumnos: ";
                nalumnos = freeBuffer(1, 100);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                for (int i = 0; i < nalumnos; i++) {
                    cout << "Alumno " << i + 1 << " ingrese su nombre: " << endl;
                    getline(cin, temp_a.nombre);
                    mostrarGrupos(lista_grupos);
                    cout << "Seleccione el numero del grupo al que pertenece: " << endl;
                    temp_a.grupo = freeBuffer(1, static_cast<int>(lista_grupos.size())) - 1;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ingrese su matricula: ";
                    cin >> temp_a.matricula;
                    cout << "Ingrese sus 3 calificaciones parciales (0 a 100): " << endl;
                    temp_a.cal[0] = leerFloatRango(0.0f, 100.0f);
                    temp_a.cal[1] = leerFloatRango(0.0f, 100.0f);
                    temp_a.cal[2] = leerFloatRango(0.0f, 100.0f);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    lista_alumnos.push_back(temp_a);
                }
                break;

            case 2:
                cout << "Ingrese la cantidad de grupos a capturar: ";
                ngrupos = freeBuffer(1, 100);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                for (int i = 0; i < ngrupos; i++) {
                    cout << "Ingrese el nombre del grupo " << i + 1 << " : ";
                    getline(cin, temp_g.nombre);
                    cout << "Ingrese la carrera asociada: ";
                    getline(cin, temp_g.carrera);
                    lista_grupos.push_back(temp_g);
                }
                break;

            case 3:
                cout << "Ingrese el numero de maestros a capturar: ";
                nmaestros = freeBuffer(1, 100);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                for (int i = 0; i < nmaestros; i++) {
                    cout << "Ingrese el nombre del maestro " << i + 1 << " : ";
                    getline(cin, temp_m.nombre);
                    cout << "Ingrese la materia que imparte: ";
                    getline(cin, temp_m.materia);
                    cout << "Ingrese la carrera en la que imparte clases: ";
                    getline(cin, temp_m.carrera);
                    lista_maestros.push_back(temp_m);
                }
                break;

            case 4:
                if (lista_alumnos.empty()) {
                    cout << "No hay alumnos capturados, ingrese los datos primero" << endl;
                    break;
                }
                cout << "Lista de alumnos: " << endl;
                for (size_t i = 0; i < lista_alumnos.size(); i++) {
                    cout << "Alumno " << i + 1 << ": " << endl;
                    cout << "Nombre: " << lista_alumnos[i].nombre << endl;
                    cout << "Matricula: " << lista_alumnos[i].matricula << endl;
                    promedio_actual = calProm(lista_alumnos[i].cal[0], lista_alumnos[i].cal[1], lista_alumnos[i].cal[2]);
                    cout << "Promedio de 3 parciales: " << promedio_actual << endl;
                }

                for (size_t i = 0; i < lista_grupos.size(); i++) {
                    mejor_promedio_grupo = 0;
                    nombre_mejor_alumno = "";
                    for (size_t j = 0; j < lista_alumnos.size(); j++) {
                        if (lista_alumnos[j].grupo == static_cast<int>(i)) {
                            promedio_actual = calProm(lista_alumnos[j].cal[0], lista_alumnos[j].cal[1], lista_alumnos[j].cal[2]);
                            if (promedio_actual > mejor_promedio_grupo) {
                                mejor_promedio_grupo = promedio_actual;
                                nombre_mejor_alumno = lista_alumnos[j].nombre;
                            }
                        }
                    }
                    cout << "Grupo " << lista_grupos[i].nombre << endl;
                    cout << "Promedio mas alto del grupo: " << mejor_promedio_grupo << " del alumno: " << nombre_mejor_alumno << endl;
                }

                {
                    vector<string> carreras_vistas;
                    for (size_t i = 0; i < lista_grupos.size(); i++) {
                        string carrera_actual = lista_grupos[i].carrera;
                        bool ya_mostrada = false;
                        for (size_t v = 0; v < carreras_vistas.size(); v++) {
                            if (carreras_vistas[v] == carrera_actual) {
                                ya_mostrada = true;
                                break;
                            }
                        }
                        if (ya_mostrada) {
                            continue;
                        }
                        carreras_vistas.push_back(carrera_actual);
                        total_alumnos_carrera = 0;
                        for (size_t j = 0; j < lista_alumnos.size(); j++) {
                            int idx_grupo = lista_alumnos[j].grupo;
                            if (idx_grupo >= 0 && idx_grupo < static_cast<int>(lista_grupos.size())) {
                                if (lista_grupos[idx_grupo].carrera == carrera_actual) {
                                    total_alumnos_carrera++;
                                }
                            }
                        }
                        cout << "La carrera de " << carrera_actual << " cuenta con un total de: " << total_alumnos_carrera << " alumnos." << endl;
                    }
                }

                for (size_t i = 0; i < lista_maestros.size(); i++) {
                    cout << "Maestro: " << lista_maestros[i].nombre << endl;
                    cout << "Materia: " << lista_maestros[i].materia << endl;
                    cout << "Carrera: " << lista_maestros[i].carrera << endl;
                }
                break;

            case 5:
                guardarDatos(lista_alumnos, lista_grupos, lista_maestros, ARCHIVO_DATOS);
                break;

            case 6:
                cargarDatos(lista_alumnos, lista_grupos, lista_maestros, ARCHIVO_DATOS);
                break;

            case 7:
                generarReportePromedio(lista_alumnos, lista_grupos, ARCHIVO_REPORTE);
                break;

            case 8:
                cout << "Saliendo del programa." << endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}

float calProm(float c1, float c2, float c3) {
    float prom;
    prom = (c1 + c2 + c3) / 3.0;
    return prom;
}

int freeBuffer(int v1, int v2) {
    int free;
    bool repetir = false;

    do {
        repetir = false;
        cout << "Elige una opción: " << endl;
        cin >> free;

        if (cin.fail()) {
            cout << "Entrada invalida, ingresa un número." << endl;
            repetir = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (free < v1 || free > v2) {
            cout << "El numero debe estar dentro del rango" << endl;
            repetir = true;
        }
    } while (repetir);

    return free;
}

float leerFloatRango(float minVal, float maxVal) {
    float valor;
    bool repetir = false;

    do {
        repetir = false;
        cin >> valor;

        if (cin.fail()) {
            cout << "Entrada invalida, ingresa un numero: ";
            repetir = true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (valor < minVal || valor > maxVal) {
            cout << "El numero debe estar entre " << minVal << " y " << maxVal << ": ";
            repetir = true;
        }
    } while (repetir);

    return valor;
}

void mostrarGrupos(const vector<grupo>& lista_grupos) {
    if (lista_grupos.empty()) {
        cout << "No hay grupos registrados." << endl;
    } else {
        cout << "Grupos disponibles:" << endl;
        for (size_t i = 0; i < lista_grupos.size(); i++) {
            cout << i + 1 << ". " << lista_grupos[i].nombre << " (" << lista_grupos[i].carrera << ")" << endl;
        }
    }
}

void guardarDatos(const vector<alumno>& lista_alumnos, const vector<grupo>& lista_grupos, const vector<maestro>& lista_maestros, const string& archivo_nombre) {
    ofstream archivo(archivo_nombre);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para guardar los datos." << endl;
        return;
    }

    archivo << lista_grupos.size() << endl;
    for (size_t i = 0; i < lista_grupos.size(); i++) {
        archivo << lista_grupos[i].nombre << endl;
        archivo << lista_grupos[i].carrera << endl;
    }

    archivo << lista_maestros.size() << endl;
    for (size_t i = 0; i < lista_maestros.size(); i++) {
        archivo << lista_maestros[i].nombre << endl;
        archivo << lista_maestros[i].materia << endl;
        archivo << lista_maestros[i].carrera << endl;
    }

    archivo << lista_alumnos.size() << endl;
    for (size_t i = 0; i < lista_alumnos.size(); i++) {
        archivo << lista_alumnos[i].nombre << endl;
        archivo << lista_alumnos[i].matricula << endl;
        archivo << lista_alumnos[i].grupo << endl;
        archivo << lista_alumnos[i].cal[0] << " " << lista_alumnos[i].cal[1] << " " << lista_alumnos[i].cal[2] << endl;
    }
    cout << "Datos guardados correctamente en " << archivo_nombre << endl;
}

void cargarDatos(vector<alumno>& lista_alumnos, vector<grupo>& lista_grupos, vector<maestro>& lista_maestros, const string& archivo_nombre) {
    ifstream archivo(archivo_nombre);
    if (!archivo.is_open()) {
        lista_alumnos.clear();
        lista_grupos.clear();
        lista_maestros.clear();
        cout << "No se encontro archivo previo (" << archivo_nombre << "). Iniciando con datos vacios." << endl;
        return;
    }

    lista_alumnos.clear();
    lista_grupos.clear();
    lista_maestros.clear();

    size_t cant_grupos = 0;
    if (archivo >> cant_grupos) {
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        for (size_t i = 0; i < cant_grupos; i++) {
            grupo temp_g;
            getline(archivo, temp_g.nombre);
            getline(archivo, temp_g.carrera);
            lista_grupos.push_back(temp_g);
        }
    }

    size_t cant_maestros = 0;
    if (archivo >> cant_maestros) {
        archivo.ignore(numeric_limits<streamsize>::max(), '\n');
        for (size_t i = 0; i < cant_maestros; i++) {
            maestro temp_m;
            getline(archivo, temp_m.nombre);
            getline(archivo, temp_m.materia);
            getline(archivo, temp_m.carrera);
            lista_maestros.push_back(temp_m);
        }
    }

    size_t cant_alumnos = 0;
    if (archivo >> cant_alumnos) {
        for (size_t i = 0; i < cant_alumnos; i++) {
            alumno temp_a;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(archivo, temp_a.nombre);
            getline(archivo, temp_a.matricula);
            archivo >> temp_a.grupo;
            archivo >> temp_a.cal[0] >> temp_a.cal[1] >> temp_a.cal[2];
            lista_alumnos.push_back(temp_a);
        }
    }
    cout << "Datos cargados desde " << archivo_nombre << endl;
}

void generarReportePromedio(const vector<alumno>& lista_alumnos, const vector<grupo>& lista_grupos, const string& reporte_nombre) {
    if (lista_alumnos.empty()) {
        cout << "No hay alumnos registrados para generar el reporte." << endl;
        return;
    }

    vector<alumno> ordenados = lista_alumnos;
    sort(ordenados.begin(), ordenados.end(), [](const alumno& a, const alumno& b) {
        float prom_a = calProm(a.cal[0], a.cal[1], a.cal[2]);
        float prom_b = calProm(b.cal[0], b.cal[1], b.cal[2]);
        return prom_a > prom_b;
    });

    ofstream reporte(reporte_nombre);
    if (!reporte.is_open()) {
        cout << "No se pudo crear el archivo de reporte: " << reporte_nombre << endl;
        return;
    }

    reporte << "Reporte de alumnos ordenados por promedio" << endl << endl;
    for (size_t i = 0; i < ordenados.size(); i++) {
        float prom = calProm(ordenados[i].cal[0], ordenados[i].cal[1], ordenados[i].cal[2]);
        string nombre_grupo = "Sin grupo";
        if (ordenados[i].grupo >= 0 && ordenados[i].grupo < static_cast<int>(lista_grupos.size())) {
            nombre_grupo = lista_grupos[ordenados[i].grupo].nombre;
        }

        reporte << i + 1 << ". " << ordenados[i].nombre << " | Matricula: " << ordenados[i].matricula << " | Grupo: " << nombre_grupo << " | Promedio: " << prom << endl;
    }

    cout << "Reporte generado correctamente en " << reporte_nombre << endl;
}