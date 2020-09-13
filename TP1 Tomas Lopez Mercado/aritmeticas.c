#include <stdio.h>
#include <stdlib.h>
#include "aritmeticas.h"


float sumarOperandos(float primerOperando, float segundoOperando)
{
    float suma;
    suma = primerOperando + segundoOperando;
    return suma;
}

float restarOperandos(float primerOperando, float segundoOperando)
{
    float resta;
    resta = primerOperando - segundoOperando;
    return resta;
}

float multiplicarOperandos(float primerOperando, float segundoOperando)
{
    float multiplicacion;
    multiplicacion = primerOperando * segundoOperando;
    return multiplicacion;
}

float dividirOperandos(float primerOperando, float segundoOperando)
{
    float division;
    division = primerOperando / segundoOperando;
    return division;
}

double factorialNum(double operando)
{
	long double returnFactorial = 1;

	for(float factorial = 1 ; factorial<=operando;factorial++)
	{
		returnFactorial = returnFactorial * factorial;
	}

	return returnFactorial;
}
