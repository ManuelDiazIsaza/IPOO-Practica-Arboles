/*
  Archivo: ArbolBInario.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2018-02-09
  Fecha Cltima modificaciC3n: 2018-02-09
  VersiC3n: 0.1
  Licencia: GPL
*/

// Clase: ListaDoble
// Responsabilidad: elemento (nodo) de un arbol binario
// ColaboraciCB3n: ninguna


#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "Nodo.h"


using namespace std;


class ArbolBinario
{
private:
    Nodo *raiz;
    void borrar(Nodo *reco);
    void imprimirPre(Nodo *reco);
    void imprimirEntre(Nodo *reco);
    void imprimirPost(Nodo *reco);
    int cantidadNodos(Nodo *reco);
    int cantidadNodosHojas(Nodo *reco);
    int alturaArbol(Nodo *reco);
    int imprimirMayor(Nodo *reco);
    void borrarMenor(Nodo *reco);
public:
    ArbolBinario();
    ~ArbolBinario();
    void insertar(int x);
    void imprimirPre();
    void imprimirEntre();
    void imprimirPost();
    void cantidadNodos();
    void cantidadNodosHojas();
    int alturaArbol();
    int imprimirMayor();
    void borrarMenor();

};

#endif