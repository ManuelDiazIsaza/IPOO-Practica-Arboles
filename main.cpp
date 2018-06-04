/*
  Archivo: Main.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/
#include <stdio.h>
#include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main()
{
    ArbolBinario *arbol = new ArbolBinario();
    arbol->insertar(400);
    arbol->insertar(100);
    arbol->insertar(50);
    arbol->insertar(60);
    arbol->insertar(75);
    arbol->insertar(200);
    arbol->insertar(700);
    arbol->insertar(900);
    arbol->insertar(600);
    arbol->insertar(180);
    arbol->insertar(220);
    arbol->insertar(55);
    arbol->insertar(80);
    arbol->insertar(1000);
//    arbol->insertar(45);
    cout<<"Impresion Pre - Orden: ";
    arbol->imprimirPre();
    cout<<"Impresion Entre - Orden: ";
    arbol->imprimirEntre();
    cout<<"Impresion Post - Orden: ";
    arbol->imprimirPost();
//    arbol->cantidadNodos();
    cout << endl;
//    arbol->cantidadNodosHojas();
    cout << endl;
    cout << arbol->alturaArbol() << endl;
    cout << arbol->imprimirMayor()<< endl;
    arbol->borrarMenor();
    cout<<"Impresion Pre - Orden: ";
    arbol->imprimirPre();


    delete arbol;
    arbol = 0;
    return 0;
}