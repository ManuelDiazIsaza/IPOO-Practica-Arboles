/*
  Archivo: ArbolBInario.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/

#include "ArbolBinario.h"
#include "Nodo.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

ArbolBinario::ArbolBinario()
{
    raiz = NULL;
}

ArbolBinario::~ArbolBinario()
{
    borrar(raiz);
}

void ArbolBinario::borrar(Nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->getIzq());
        borrar(reco->getDer());
        delete reco;
        reco = 0;
    }
}

void ArbolBinario::insertar(int info)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->setInfo(info);
    nuevo->setIzq(NULL);
    nuevo->setDer(NULL);
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        Nodo *anterior, *reco;
        anterior = NULL;
        reco = raiz;
        while (reco != NULL)
        {
            anterior = reco;
            if (info < reco->getInfo())
                reco = reco->getIzq();
            else
                reco = reco->getDer();
        }
        if (info < anterior->getInfo())
            anterior->setIzq(nuevo);
        else
            anterior->setDer(nuevo);
    }
}

void ArbolBinario::imprimirPre()
{
    imprimirPre(raiz);
    cout << endl;
}

void ArbolBinario::imprimirEntre()
{
    imprimirEntre(raiz);
    cout << endl;
}

void ArbolBinario::imprimirPost()
{
    imprimirPost(raiz);
    cout << endl;
}



void ArbolBinario::imprimirEntre(Nodo *reco)
{
    if (reco != NULL)
    {
        imprimirEntre(reco->getIzq());
        cout << reco->getInfo() << "-";
        imprimirEntre(reco->getDer());
    }
}

void ArbolBinario::imprimirPre(Nodo *reco)
{
    if (reco != NULL)
    {
        cout << reco->getInfo() << "-";
        imprimirPre(reco->getIzq());
        imprimirPre(reco->getDer());
    }
}

void ArbolBinario::imprimirPost(Nodo *reco)
{
    if (reco != NULL)
    {
        imprimirPost(reco->getIzq());
        imprimirPost(reco->getDer());
        cout << reco->getInfo() << "-";
    }
}

void ArbolBinario::cantidadNodos()
{
    cout << cantidadNodos(raiz);
}

int ArbolBinario::cantidadNodos(Nodo *reco)
{
    int contador=0;
    if (reco != NULL)
    {
        contador++;
        contador += cantidadNodos(reco->getIzq());
        contador += cantidadNodos(reco->getDer());
    }
    return contador;
}

void ArbolBinario::cantidadNodosHojas()
{
    cout << cantidadNodosHojas(raiz);
}

int ArbolBinario::cantidadNodosHojas(Nodo *reco)
{
    int contador=0;
    if (reco != NULL)
    {
        if(reco->getDer()== nullptr && reco->getIzq()== nullptr)
        {
            contador++;
            contador += cantidadNodosHojas(reco->getIzq());
            contador += cantidadNodosHojas(reco->getDer());
        }
        else
        {
            contador += cantidadNodosHojas(reco->getIzq());
            contador += cantidadNodosHojas(reco->getDer());
        }
    }
    return contador;
}

int ArbolBinario::alturaArbol()
{
    return alturaArbol(raiz);
}

int ArbolBinario::alturaArbol(Nodo *reco)
{

        int alturaDerecha = 0;
        int alturaIzquierda = 0;

        if(reco->getDer()== nullptr && reco->getIzq()== nullptr)
        {
            return 1;
        }

        if(reco->getDer()!= nullptr)
        {
            alturaDerecha = alturaArbol(reco->getDer());
        }
        if(reco->getIzq()!= nullptr)
        {
            alturaIzquierda = alturaArbol(reco->getIzq());
        }

        int alturaHijos = max(alturaDerecha, alturaIzquierda);
        return alturaHijos + 1;
}

int ArbolBinario::imprimirMayor(Nodo *reco)
{
        int mayorVal=0;

        if(reco->getDer()== nullptr && reco->getIzq()== nullptr)
        {
            mayorVal = reco->getInfo();
        }
        else
        {
            mayorVal = imprimirMayor(reco->getDer());
        }
    return mayorVal;
}

int ArbolBinario::imprimirMayor()
{
    return imprimirMayor(raiz);
}

void ArbolBinario::borrarMenor(Nodo *reco)
{
    Nodo *anterior = nullptr;

    while(reco->getIzq()!= nullptr)
    {
        if(reco->getIzq()== nullptr)
        {
        }
        if(reco->getIzq()->getIzq()== nullptr)
        {
            anterior = reco;
            reco = reco->getIzq();
        }
        else
        {
            reco = reco->getIzq();
        }
    }
    //cout << reco->getInfo() << endl;
    //cout << anterior->getInfo() << endl;
    if(reco->getDer()== nullptr && reco->getIzq()== nullptr)
    {
        delete reco;
        anterior->setIzq(nullptr);
    }
    else
    {
        anterior->setIzq(reco->getDer());
        delete reco;
    }
}

void ArbolBinario::borrarMenor()
{
    borrarMenor(raiz);
}