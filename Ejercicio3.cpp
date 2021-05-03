/*
3. Implementar una función que ordene los elementos de un arreglo: ascendente. Tamaño del arreglo 1000000.
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

void Quicksort(long long *lista, long long inicio,long long final){
    int pivot, centro, i = inicio, j = final;
	centro = (inicio+final)/2;
	pivot = lista[centro];
	do{
		while (lista[i]<pivot) i++;
		while (lista[j]>pivot) j--;
		if(i<=j){
			int aux;
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
void mostrar(long long *lista, long long tam){
	for(long long i=0;i<tam;i++){
		cout<<lista[i]<<" , ";
	}
}

int main(){
	long long  tam=1000000, *lista = new long long[tam];
	crear(lista,tam);
	mostrar(lista,tam);
	Quicksort(lista,0,tam-1);
	cout<<"\nLista ordenada: "<<endl;
	mostrar(lista,tam);
	delete[]lista;
    return 0;
}
