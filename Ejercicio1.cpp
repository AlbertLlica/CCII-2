/*
1. Implementar una función reciba un arreglo de enteros y su tamaño y retorne la suma de los elementos de un arreglo.
Tamaño del arreglo 1000000. (Iterativa y recursiva).
*/

#include<iostream>
#include <time.h>

using namespace std;

void crear(long long * &lista, long long tam){
	srand(time(NULL));
	for(int i=0;i<tam;i++){
		lista[i]=1+rand()%10;
	}
}
long long Iteratividad(long long *lista,long long tam){
	long long sum=0;
	for(long long j=0;j<tam;j++){
		sum+=lista[j];
	}
	return sum;
}

long long Recursividad(long long *lista, long long inicio,long long final){

	if(inicio>final) return 0;
	if(inicio==final) return lista[final];
	long long Sublista1 = Recursividad(lista,inicio+1,((inicio+1)+final)/2);
	long long Sublista2= Recursividad(lista,(((inicio+1)+final)/2)+1,final);
	return lista[inicio]+Sublista1+Sublista2;
	
}
void mostrar(long long *lista, long long tam){
	for(long long i=0;i<tam;i++){
		cout<<lista[i]<<" + ";
	}
}

int main(){
	long long  tam=1000000, *lista = new long long[tam];
	crear(lista,tam);
	//mostrar(lista,tam);
	cout<<"ITERATIVIDAD: "<<Iteratividad(lista,tam)<<endl;
	cout<<"RECURSIVIDAD: "<<Recursividad(lista,0,tam-1)<<endl;
	delete[]lista;
    return 0;
}