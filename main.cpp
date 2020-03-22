//
//  main.cpp
//  abstract_factory
//
//  Created by Alexander Arturo Baylon Ibanez on 7/04/16.
//  Copyright © 2016 aunesto17. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Pizza
{
public:
    string nombre;
    string masa;
    string salsa;
    vector<string> adicionales;
    
    virtual void preparar()
    {
        cout << "Preparando " << nombre << endl;
        cout << "Amazando..." << endl;
        cout << "Agregando la salsa... " << endl;
        cout << "Agregando adicionales... " << nombre << endl;
        for(int i=0;i<adicionales.size();i++ ){
            cout << adicionales[i] << " ";}
    }
    virtual void hornear()
    {cout << "Horneando por 25 minutos a 170 grados." << endl;}
    virtual void cortar()
    {cout << "Cortando la pizza en diagonales." << endl;}
    virtual void empaquetar()
    {cout << "Poniendo la pizza en la caja de la Pizzeria." << endl;}
    virtual string getNombre()
    {return nombre;}
};

class pizzaHawaianaAQP : public Pizza
{
public:
    pizzaHawaianaAQP()
    {
        nombre = "Pizza Hawaiana con ingredientes de Arequipa";
        masa   = "masa gruesa";
        salsa  = "salsa estilo Arequipa";
        
        adicionales.push_back("jamon serrano");
        adicionales.push_back("pina");
        adicionales.push_back("durazno");
    }
};

class pizzaQuesoAQP : public Pizza
{
public:
    pizzaQuesoAQP()
    {
        nombre = "Pizza de Queso con ingredientes de Arequipa";
        masa   = "masa gruesa";
        salsa  = "salsa estilo Arequipa";
        
        adicionales.push_back("queso serrano");
    }
};


class pizzaHawaianaLima : public Pizza
{
public:
    pizzaHawaianaLima()
    {
        nombre = "Pizza Hawaiana con ingredientes de Lima";
        masa   = "masa delgada";
        salsa  = "salsa basica de tomate";
        
        adicionales.push_back("jamon ingles");
        adicionales.push_back("pina");
        adicionales.push_back("durazno");
    }
};

class pizzaQuesoLima : public Pizza
{
public:
    pizzaQuesoLima()
    {
        nombre = "Pizza de Queso con ingredientes de Lima";
        masa   = "masa delgada";
        salsa  = "salsa basica de tomate";
        
        adicionales.push_back("queso generico");
    }
};






class pizzeria
{
public:
    Pizza * ordenarPizza(string tipo)
    {
        Pizza * pizza;
        pizza = crearPizza(tipo);
        
        pizza->preparar();
        pizza->hornear();
        pizza->cortar();
        pizza->empaquetar();
        
        return pizza;
    }
    
    virtual Pizza * crearPizza(string tipo);
};


class pizzeriaArequipa : public pizzeria
{
public:
    Pizza * crearPizza(string tipo)
    {
        if(tipo == "queso")
        {
            Pizza * temp = new pizzaQuesoAQP();
            return temp;
        }
        else if(tipo == "hawaiana")
        {
            Pizza * temp = new pizzaHawaianaAQP();
            return temp;
        }
        else
            return 0;
    }
};

class pizzeriaLima : public pizzeria
{
public:
    Pizza * crearPizza(string tipo)
    {
        if(tipo == "queso")
        {
            Pizza * temp = new pizzaQuesoLima();
            return temp;
        }
        else if(tipo == "hawaiana")
        {
            Pizza * temp = new pizzaHawaianaLima();
            return temp;
        }
        else
            return 0;
    }
};






int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
