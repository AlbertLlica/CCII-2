/*
2. Implementar una función que invierta los elementos de un arreglo de enteros (Iterativa y recursiva). Tamaño del
arreglo 1000000.
*/

#include <iostream>
#include <time.h>
using namespace std;

void crear(long long * &lista, long long tam){
	srand(time(NULL));
	for(int i=0;i<tam;i++){
		lista[i]=1+rand()%10;
	}
}

void mostrar(long long *lista, long long tam){
	for(long long i=0;i<tam;i++){
		cout<<lista[i]<<", ";
	}
}


void Iteratividad(long long *lista, long long tam){
    int aux;
    for(long long j=0; j<tam/2; j++){
        aux = lista[j];
        lista[j]=lista[tam -1 -j];
        lista[tam -1 -j] = aux;
    }
}

void Recursividad(long long *lista, long long tam){
    if(tam>=1){
        cout<<lista[tam-1]<< ", ";
        Recursividad(lista,tam -1);
    }
}

int main(){
	long long  tam=1000000, *lista = new long long[tam];
	crear(lista,tam);
    cout<<"Lista inicial: ";
	mostrar(lista,tam);
    cout<<"\n Lista invertida ITERATIVIDAD: ";
	Iteratividad(lista,tam);
    mostrar(lista,tam);
    cout<<"\n Lista invertida RECURSIVIDAD: ";
    Recursividad(lista,tam);
	delete[]lista;
    return 0;
}