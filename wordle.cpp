#include "funciones.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    /*
    -Cargamos el archivo .txt en la variable listado, para luego usar la función cargar_listado y guardar el retorno en lista_vector
    -Luego, seteamos un número aleatorio para tomar un elemento aleatorio de nuestro vector, el cual funcionará como palabra secreta a encontrar
    -Seteamos variable num_intentos para ir sumando la cantidad de intentos que vamos usando
    -Creamos un while, que va a funcionar hasta que num_intentos sea 6 (representando los 6 intentos del juego)
    -Dentro del while, se nos va a pedir que ingresemos una palabra como intento, luego analiza si es valida
    -En el caso de no serlo, no se suma un intento utilizado y se reinicia el while
    -En el caso de serlo, se analiza si el intento es correcto con evaluar_intento
    -Si el intento es correcto, termina el juego e imprime en pantalla que ganaste
    -Si el intento es incorrecto, suma 1 al número de intentos, mos muestra que letras estan correctas y cuales no, y nos pide que ingresemos otra palabra
    -Si se da el caso de que no adivinemos la palabra, se nos mostrará por pantalla que perdimos el juego
    */
    string listado = "../listado.txt";
    vector<string>lista_vector = cargar_listado(listado);
    srand(time(NULL));
    int num_rand = rand()% (lista_vector.size());
    string palabra_secreta = lista_vector[num_rand];
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------¡Bienvenido a Wordle!---------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------REGLAS-----------------------------------------------------"<<endl;
    cout<<"Tienes 6 oportunidades para adivinar una palabra de 5 letras. Todas las palabras están en minúscula."<<endl<<"En Caso de que la palabra no esté en nuestro diccionario, no se te quitará un intento."<<endl<<"Ahora, ¡A jugar!"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"---------------------------------INGRESÁ UNA PALABRA PARA EMPEZAR-----------------------------------"<<endl;
    string intento_usuario;
    int num_intentos=0;
    while(num_intentos<6){
        cin>>intento_usuario;
        if(!(intento_valido(intento_usuario,palabra_secreta,lista_vector))){
            num_intentos = num_intentos;
            cout<<"Esta palabra no es valida (no esta en nuestro diccionario o no cumple los requisitos)"<<endl;
        }
        else{
            string resultado_usuario = respuesta_en_string(evaluar_intento(intento_usuario, palabra_secreta));
            cout<<resultado_usuario<<endl;
            if (resultado_usuario=="+++++")
            {
                cout<<"¡Felicitaciones! Ganaste la partida."<<endl;
                num_intentos = 6;
            }
            else{
                if (num_intentos == 5)
                {
                    cout<<"Game Over"<<endl;
                    exit(1);
                }
                
                cout<<"Incorrecto. Te quedan "<< 5 - num_intentos <<" intentos. Ingresa una nueva palabra."<<endl;
                num_intentos++;
            }

            
        }

    }

}