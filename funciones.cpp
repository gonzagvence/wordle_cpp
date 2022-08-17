#include "funciones.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    
    ifstream archivo(nombre_archivo); 
    string texto;
    vector<string>listado;
    if (archivo.good()==false) // Verificamos que el txt sea valido, en caso de no serlo se muestra por pantalla que no es válido
    {
        cout<< "No se pudo abrir el archivo "<< endl;
        exit (1);

    }
    else{ // Si es válido, agrega cada linea que tiene el txt (usando getline) al vector listado con la funcion push_back
        while (!archivo.eof())
        {
            getline(archivo,texto);
            if(texto!=""){
                listado.push_back(texto);
            }
                 
            
        }
        
    }
    
    return vector<string>(listado);
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    if (intento.length() != palabra_secreta.length()) // Verifica que el largo del intento sea de 5 letras
    {
        return false;
    }

    else if (*find(listado.begin(), listado.end(), intento) == intento) // Verifica que el intento esté en el diccionario de palabras
    {
        return true;
    }
    
    

    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    vector<EstadoLetra>(vr);
    int n = 0;
    while (n<5) // Verifica las 5 letras del intento, y va sumando al vector con los elementos de estado
    {
        if(intento[n]==palabra_secreta[n]){ //Caso Correcto
            vr.push_back(EstadoLetra::LugarCorrecto);
        }
        else if (palabra_secreta.find(intento[n]) != std::string::npos) //Caso Lugar Incorrecto
        {
            vr.push_back(EstadoLetra::LugarIncorrecto);
        }
        
        else{ //Caso No Presente
            vr.push_back(EstadoLetra::NoPresente);
        }
       n++; 
    }
    
    

    return vector<EstadoLetra>(vr);
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string vr=""; //Creamos string vacio para ir sumando los caracteres + - X
    for (auto e: respuesta) // Recorremos el vector
    {
      if (e == (EstadoLetra::LugarCorrecto)) // Caso +
      {
        vr.append("+");
      }
      else if (e == (EstadoLetra::LugarIncorrecto)) // Caso -
      {
        vr.append("-");
      }
      else{ //Caso X
        vr.append("X");
      }
        
    }
    

    return vr;
}