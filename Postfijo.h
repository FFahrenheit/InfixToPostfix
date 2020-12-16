//
// Created by ivan_ on 01/12/2020.
//

#ifndef PROYECTO_POSTFIJO_H
#define PROYECTO_POSTFIJO_H

#include <iostream>
#include "Pila.h"

using namespace std;

class Postfijo {
    private:
        static bool isOperator(char);
        static int precedence(char);
    public:
        Postfijo() = default;
        static string infijoAPostfijo(const string&);
};

string Postfijo::infijoAPostfijo(const string &cadena)
{
    /***
     * Crear una pila vacía para los operadores y una cadena de salida.
     */
    string postfijo;
    Pila<char> operadores;
    char operador;
    /***
     * Recorrer la expresión infija de izquierda a derecha.
     */
    for(char c : cadena)
    {
        try
        {
            if(isOperator(c))
            {
                /***
                 * Si el símbolo es un operador, primero remover cada operador de la pila con mayor o
                    igual precedencia que no sea un ‘(’ y agregarlo a la cadena de salida, después
                    insertar el operador encontrado.
                 */
                 while( !operadores.empty() &&
                        (operador = operadores.top()) != '(' &&
                        precedence(c) <= precedence(operador))
                 {
                     postfijo += operador;
                     operadores.pop();
                 }
                operadores.push(c);
            }
            else if(c == '(')
            {
                /***
                 * Si el símbolo es ‘(‘, agregarlo a la pila de operadores.
                 */
                operadores.push(c);
            }
            else if(c == ')')
            {
                /***
                 * Si el símbolo es ‘)’, vaciar de la pila hasta encontrar el ‘(’ correspondiente, agregar
                 * cada operador a la cadena de salida.
                 */
                while((operador = operadores.top()) != '(')
                {
                    postfijo+=operador;
                    operadores.pop();
                }
                operadores.pop();

            }
            else
            {
                /***
                 * Si el símbolo es un operando, agregarlo a la cadena de salida.
                 */
                postfijo += c;
            }
        }
        catch(...)
        {
            cout << "La cadena no esta en el formato adecuado infijo" << endl;
            return "";
        }
    }
    /***
     * Vaciar cada operador aún presente en la pila y agregarlo a la cadena de salida.
     */
    while(!operadores.empty())
    {
        postfijo += operadores.top();
        operadores.pop();
    }
    return postfijo;
}

bool Postfijo::isOperator(char c)
{
    string symbols = "+-*/^";
    return symbols.find(c) != string::npos;
}

int Postfijo::precedence(char c)
{
    return (c == '+' || c == '-') ? 1 :
    (c == '*' || c == '/') ? 2 :
    (c == '^')? 3 : 0;
}


#endif //PROYECTO_POSTFIJO_H
