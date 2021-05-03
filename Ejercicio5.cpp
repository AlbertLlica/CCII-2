/*
Implemente una función que reciba dos cadenas a y b; dicha función debe concatenar la cadena a a la cadena b.
(asuma que la cadena b tiene el tamaño suficiente para contener los elementos de a).
*/

#include <iostream>

using namespace std;

void concatenar(char *CA, char *CB){
    int cant = 0, idx =0;
    for(;*(CB+cant)!='\0'; cant++);
    while (*(CA+idx)!= '\0'){
        *(CB+cant+idx) = *(CA +idx);
        idx++;
    }
    *(CB+idx+cant) = '\0';
}

int main(){
    char * cadenaA = new char [1000]; 
    char * cadenaB = new char [1000];
    cout<<"Ingrese Cadena A: "; cin>>cadenaA;
    cout<<"Ingrese Cadena B: "; cin>>cadenaB;

    concatenar(cadenaA,cadenaB);
    cout<<"Cadena A: "<<cadenaA<<endl;
    cout<<"Cadena B: "<<cadenaB<<endl;
}