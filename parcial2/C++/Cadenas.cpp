#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    
    string cad;
    
    cout << "Ingresa en un único texto un nombre y un apellido separados: " << endl;
    getline(cin,cad);
    
    size_t pos1 = cad.find(' ');
    size_t pos2 = cad.rfind(' ');
    char primero = cad.front();
    char ultimo = cad.back();
    
    //Aquí se agrega un if para verificar que nombre y apellido esten bien escritos
    if((primero != (' ')) && (ultimo != (' ')) && (pos1 != string::npos) && (pos1 == pos2)) {
        
        string nombre = cad.substr(0,pos1);
        string apellido = cad.substr(pos1 + 1);
        bool num = false;
        
        //Para verificar letra por letra que no haya un número
        for (int i=0; i<nombre.size(); i++) {
            
            //Este if es el que cambia el bool para avisar de un número
            if (isdigit(nombre[i]) == true) {
                num = true;
            }
        }
        //Para verificar letra por letra que no haya un número
        for (int i=0; i<apellido.size(); i++) {
            
            //Este if es el q cambia el bool para avisar sobre un número
            if (isdigit(apellido[i]) == true) {
                num = true;
            }
        }
        //Aqui, si hay numeros, manda error, sino, manda los datos
        if (num == true) {
            cout << "Error, el nombre o apellido contiene(n) un número";
        } else {
            cout << "Nombre: " << nombre << " Apellido: " << apellido;
        }
        
      //Forma parte del primer if para verificar que nombre y apellido sean correctos  
    } else {
            cout << "Error, verifique sus datos";
        }
    return 0;
}
