/*
Problema:
	Imagina que estás creando un simulador de una tienda de muebles. Tú código consiste en las clases que representan lo siguiente:
    1. Una familia de productos relacionados tal como: Chair + Sofa + CoffeTable.
    2. La colleción de objetos puede tener varias combinaciones, por ejemplo: 
    Chair + Sofa + CoffeTable que están disponibles en sus diferentes variaciones: Modern, Victorian, ArcDeco.
Solución:
    Necesitas una forma de crear los objetos muebles individuales de tal forma que sea posible agruparse con los otros objetos de su misma familia, 
    a razón es porque los clientes se enojan cuando no reciben una agrupación de muebles cuando lo requieren.
	Considerando que tu no quieres cambiar el código existente cada que se añaden nuevos productos o
     familia de productos al programa y por su puesto esto no es para nada una buena práctica. Los vendedores de la mueblería actualizan los catálogos con mucha frecuencia y 
     tu no debes hacer cambios al código cada vez que se esto sucede.
*/

#include <iostream>
#include <string>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FABRICA ABSTRACTA INICIO
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Creo Interfaz va a ser la fábrica abstracta
class FactoryMuebles
{   //Anteponiendo la palabra reservada virtual e igualando a 0, digo que no se pueden implementar
    //las funciones miembro en esta clase, que va a funcionar como ABTRACCIÓN
    public:
    virtual string createChair() = 0;
    virtual string createSofa() = 0;
    virtual string createCoffeTable() = 0;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FABRICA ABSTRACTA FIN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FÁBRICAS CONCRETAS QUE HEREDAN DE LA FÁBRICA ABSTRACTA FactoryMuebles INICIO
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Clase que fabrica productos concretos del estilo Modern
class ModernStyle : public FactoryMuebles
{
    public:
        string createChair() override;
        string createSofa() override;
        string createCoffeTable() override;
};

//Implemento las funciones que cree de la clase ModernStyle

string ModernStyle::createChair()
{
    return "Chair";
}

string ModernStyle::createSofa()
{
    return "Chair";
}

string ModernStyle::createCoffeTable()
{
    return "Chair";
}

//Clase que fabrica productos concretos del estilo Modern
class VictorianStyle : public FactoryMuebles
{
    public:
        string createChair() override;
        string createSofa() override;
        string createCoffeTable() override;
};

//Implemento las funciones miembro de la clase VictorianStyle
string VictorianStyle::createChair()
{
    return "Chair";
}

string VictorianStyle::createSofa()
{
    return "Sofa";
}

string VictorianStyle::createCoffeTable()
{
    return "CoffeTable";
}

//Clase que fabrica productos concretos del estilo Modern
class ArtDecoStyle : public FactoryMuebles
{
    public:
        string createChair() override;
        string createSofa() override;
        string createCoffeTable() override;
};

string ArtDecoStyle::createChair()
{
    return "Chair";
}

string ArtDecoStyle::createSofa()
{
    return "Sofa";
}

string ArtDecoStyle::createCoffeTable()
{
    return "CoffeTable";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FÁBRICAS CONCRETAS QUE HEREDAN DE LA FÁBRICA ABSTRACTA FactoryMuebles FIN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CLIENTE QUE CONSUME LA INTERFAZ, TIENE UNA RELACIÓN DE DEPENDENCIA CON FactoryMuebles
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    //Creo un objeto del tipo ArtDecoStyle que se llama artDecoStyle
    ArtDecoStyle* artDecoStyle = new ArtDecoStyle();//Asigno el objeto a la memoria dinámica

    cout << artDecoStyle->createChair() << endl;
    cout << artDecoStyle->createCoffeTable() << endl;
    cout << artDecoStyle->createSofa() << endl;
   
    
    
    
   //Borro el objeto que esta en la memoria dinámica
   delete artDecoStyle; 

  return 0;
}

