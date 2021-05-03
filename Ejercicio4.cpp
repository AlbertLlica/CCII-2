/*
4. Implemente una función que reciba una cadena y retorne su tamaño. (Iterativa y recursiva)
*/

#include <iostream>

using namespace std;

void crear(char * &lista, long long tam){
	lista = new char [tam];
    cout<<"Ingrese palabra: "; cin>>lista;
}


int Iterativo(char *lista){
    int idx=0;
    for(;*(lista+idx)!='\0';idx++);
    cout<<"La cantidad de elementos es: "<<idx;
    return 0;
}

void Recursivo(char *lista){
    int i=0,
    if(*(lista+i)!= '\0'){
        Recursivo(lista+i);
    }
    cout<<i;
}

int main(){
	long long  tam=1000000;
    char *lista = new char[tam];
	crear(lista,tam);
    cout<<"POR ITERATIVIDAD: "<<endl;
    Iterativo(lista);
    cout<<"\nPOR RECURSIVIDAD: "<<endl;
    Recursivo(lista);
	delete[]lista;
    return 0;
}