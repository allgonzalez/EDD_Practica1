#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstring>

using namespace::std;

struct nodo{
	int dato;
	nodo* siguiente;
    nodo* anterior;
} *primero, *ultimo;

void InsertarNodo();
void MostrarLista();
void ordenar(nodo* Entrada);
void buscarNodo();

int main(){
	
	int opcion = 0;
	
	do
	{
		cout << "\n|-------------------------------------|";
		cout << "\n|            LISTA SIMPLE             |";
		cout << "\n|------------------|------------------|";
		cout << "\n| 1. Insertar                         |";
		cout << "\n| 2. Buscar                           |";
		cout << "\n| 3. Mostrar Lista                    |";
		cout << "\n| 4. Salir                            |";
		cout << "\n|------------------|------------------|";
		cout << "\n\n Seleccione una opcion: ";
		cin >> opcion;
		switch(opcion){
		case 1:
			cout << "\n\n INSERTAR NODO EN LISTA \n\n";
			InsertarNodo();
			break;
		case 2:
			cout << "\n\n BUSCAR \n\n";
			buscarNodo();
			break;
		case 3:
			cout << "\n\n MOSTRAR LISTA \n\n";
			MostrarLista();
			break;
		case 4:
			cout << "\n\n Adios!! :) \n\n";
			break;
		default:
			cout << "\n\n Ingrese una opcion correcta \n\n";
		}
	} while (opcion != 4);
	
	
	return 0;
}
void InsertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el Dato: ";
	cin >> nuevo->dato;

	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ordenar(nuevo);
	}
	cout << "\n Nodo Agregado a la lista\n\n";
}
void ordenar(nodo* Entrada){
    nodo* aux = primero;
    while(aux != NULL){
        if(aux->dato < Entrada -> dato){
            aux = aux -> siguiente;
            
        }else{

            if(aux == primero){
                Entrada -> siguiente = aux;
                aux -> anterior = Entrada;
                primero = Entrada;

            }else{
                Entrada -> anterior = aux -> anterior;
                aux -> anterior -> siguiente = Entrada;
                Entrada -> siguiente = aux;
                aux -> anterior = Entrada;
                return;
            }
        }
    }

    ultimo -> siguiente = Entrada;
    Entrada -> anterior = ultimo;
    ultimo = Entrada;
}

void buscarNodo(){
    nodo* temporal = primero;
    int posicion = 0;
    int datoB;
    bool encontro = false;

    cout << " Ingrese el Dato: ";
    cin >> datoB;
    while(temporal != NULL){
        if(temporal->dato == datoB){
            cout << " Dato encontrado en la posicion  " << posicion << endl;
            encontro = true;
            break;
        }else{
            posicion += 1;
        }
        temporal = temporal -> siguiente;
    }
    if(encontro == false){
        cout  << "\n Dato no encontrado en la Lista \n\n";
    }
}

void MostrarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero != NULL){
		
		while(actual != NULL){
			cout << "------------------------------------------- " << endl;
			cout << " Dato: " << actual-> dato << endl;
           
			cout << "------------------------------------------- " << endl;
			actual = actual->siguiente;
		}
		
	}else{
		cout  << "\n La Lista esta vacia \n\n";
        
	}
}