/*
Implemente una función que reciba un arreglo de cadenas y su tamaño y ordene lexicográficamente dicho arreglo.
Tamaño del arreglo 1000000.
*/

#include <iostream>
#include <string>

using namespace std;

void crear(string * &lista, long long tam){
	for(int i=0;i<tam;i++){
		cout<<"Ingrese palabra "<<i<<": "; 
		cin>>lista[i];
	}
}

void Quicksort(string *lista, long long inicio,long long final){
    int centro, i = inicio, j = final;
	string pivot;
	centro = (inicio+final)/2;
	pivot = lista[centro];
	do{
		while (lista[i]<pivot) i++;
		while (lista[j]>pivot) j--;
		if(i<=j){
			string aux;
			aux = lista[i];
			lista[i] = lista[j];
			lista[j] = aux;
			i++;
			j--; 
		}
	}
	while(i<=j);
	if(inicio<j) Quicksort(lista, inicio, j);
	if(i<final) Quicksort(lista,i,final);
}
void mostrar(string *lista, long long tam){
	for(long long i=0;i<tam;i++){
		cout<<lista[i]<<" , ";
	}
}

int main(){
	long long  tam=10;
    string *lista = new string[tam];
	crear(lista,tam);
	mostrar(lista,tam);
	Quicksort(lista,0,tam-1);
	cout<<"\nLista ordenada: "<<endl;
	mostrar(lista,tam);
	delete[]lista;
    return 0;
}
