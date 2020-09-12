#include <stdio.h>
#include <stdlib.h>
#include "aritmeticas.h"

/*Trabajo practico nro 1
Lopez Mercado, Tomás
1f
*/

int main()
{
//Declaracion de variables

    float primerOperando;
    float segundoOperando;
    int opcionMenu;
    int flagPrimerOperando;
    int flagSegundoOperando;
    int flagOperacionesCalculadas;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    double factorialA;
    double factorialB;

//Inicializacion de banderas

    flagPrimerOperando = 0;
    flagSegundoOperando = 0;
    flagOperacionesCalculadas = 0;

//Utilizo la estructura do while para asi crear un bucle que me muestre un menu con 5 opciones

    do{

//Valido las banderas del primer y segundo operando, para asi mostrar los mismos en el menu e imprimo en pantalla las distintas opciones del menu

    if(flagPrimerOperando == 0 ){
            printf("1. Ingresar primer operando");
     }else{
            printf("1. Primer Operando : %.2f", primerOperando);
            printf(" (Modificar presione 1)");
     }
    if(flagSegundoOperando == 0 ){
            printf("\n2. Ingresar segundo operando");
    }else{
            printf("\n2. Segundo operando : %.2f", segundoOperando);
            printf(" (Modificar presione 2)");
    }

    printf("\n3. Calcular todas las operaciones");
    printf("\n      a)Suma A+B");
    printf("\n      b)Resta A-B");
    printf("\n      c)Division A/B");
    printf("\n      d)Multiplicacin A*B");
    printf("\n      e)Factorial A!");
    printf("\n      f)Factorial B!");
    printf("\n4. Informar resultados");
    printf("\n5. Salir");
    printf("\nIngrese un numero para elegir la opcion correspondiente: ");

//Una vez impreso el menu en pantalla pido un entero el cual me va a determinar la opcion a elegir mediante el uso de la estructura switch

    scanf("%d", &opcionMenu);

//Englobo toda la estructura switch con las funciones de cada opción dentro de una estructura if, para asi determinar si el número ingresado corresponde a una opción valida

    if(opcionMenu > 0 && opcionMenu < 6)
    {

//Desarrollo de la estructura switch con cada "case" representando una opción del menu.

    switch(opcionMenu){

            case 1:
                printf("\nIngrese primer operando : ");
                scanf("%f", &primerOperando);
                fflush(stdin);
                flagPrimerOperando = 1;
                system("cls");
            break;

            case 2:
                printf("\nIngrese segundo operando : ");
                scanf("%f", &segundoOperando);
                fflush(stdin);
                flagSegundoOperando = 1;
                system("cls");
            break;

            case 3:

                if(flagPrimerOperando == 1 && flagSegundoOperando == 1){
                    suma = sumarOperandos(primerOperando, segundoOperando);
                    resta = restarOperandos(primerOperando, segundoOperando);
                    multiplicacion = multiplicarOperandos (primerOperando, segundoOperando);
                    division = dividirOperandos(primerOperando, segundoOperando);
                    factorialA = factorialNum(primerOperando);
                    factorialB = factorialNum(segundoOperando);
                    flagOperacionesCalculadas = 1;

                    printf("\nCalculos realizados exitosamente!!!");
                    printf("\n\n");
                    system("pause");
                    system("cls");
                }else{
                    printf("\nERROR : Primero debe ingresar los operandos");
                    printf("\n\n");
                    system("pause");
                    system("cls");
                    }
            break;

            case 4:
                if(flagOperacionesCalculadas == 1){

                    printf("\na)El resultado de la suma A+B es : %.2f", suma);
                    printf("\nb)El resultado de la resta A-B es  : %.2f", resta);


                if(segundoOperando != 0){
                    printf("\nc)El resultado de la division A/B es : %.2f", division);
                }else{
                    printf("\nc)ERROR :Un numero no puede ser dividido por 0");
                }

                    printf("\nd)El resultado de la multiplicacion A*B es : %.2f", multiplicacion);

                if(primerOperando > 0){
                    printf("\ne)El resultado de factorial A! es : %.2f", factorialA);
                }else{
                    printf("\ne)ERROR : Solo se puede calcular factorial de numeros positivos mayores a 0");

                }

                if(segundoOperando > 0){
                    printf("\nf)El resultado de factorial B! es : %.2f", factorialB);
                }else{
                printf("\nf)ERROR : Solo se puede calcular factorial de numeros positivos mayores a 0");
                }
                printf("\n\n");
                system("pause");
                system("cls");
                }else{

                printf("\nERROR : Primero debe calcular las operaciones");
                printf("\n\n");
                system("pause");
                system("cls");
                }

            break;

    }
//Aca cierro la estructura IF la cual contiene al switch con las opciones y le declaro un else para el caso en el que el usuario no haya ingresado un número que se corresponda a una opcion del menu.
    }else{
        printf("\nERROR. Ingrese una opcion valida");
        printf("\n\n");
        system("pause");
        system("cls");

    }

//Cierro la estructura Do While mientras el usuario ingrese "5", siendo este número la opciún para salir del programa.
    }while(opcionMenu != 5);


    return 0;
}

