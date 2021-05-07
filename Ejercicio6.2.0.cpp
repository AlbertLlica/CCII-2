#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void crear(string * &lista, long long tam){
	ifstream archivo;
	archivo.open("C:\\Users\\Albert\\Desktop\\text3.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se encontro el texto";
		exit(1);
	}
	for(int i=0;i<tam;i++){
		archivo>>*(lista+i);
		//cout<<*(lista+i)<<" , ";;
	}
	archivo.close();

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
void G_mostrar(string *lista, long long tam){
	ofstream file;
	file.open("TXT ORDENADO QUICKSORT.txt",ios::out);
	for(long long i=0;i<tam;i++){
		file<<*(lista+i)<<" , ";
		//cout<<*(lista+i)<<" , ";;
	}
	file.close();
}
int main(){
	long long  tam=1000000;
    string *lista = new string[tam];
	crear(lista,tam);
	Quicksort(lista,0,tam-1);
	cout<<"\n\nLISTA ORDENADA: "<<endl;
	G_mostrar(lista,tam);
	delete[]lista;
    return 0;
}