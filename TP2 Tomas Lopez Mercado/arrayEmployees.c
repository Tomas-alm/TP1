#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define qtyEmployees 1000

int limpiarArray(Employee arrayEmployees[], int limiteArray)
{
    int i;

        for(i=0; i < limiteArray ; i++){

            arrayEmployees[i].isEmpty = 0;
        }
    return 0;
}

int generarID(Employee arrayEmployees[], int limiteArray)
{
    int i;

        for(i=0; i < limiteArray ; i++){
            if(arrayEmployees[i].isEmpty == 1){
                arrayEmployees[i].id = i+1;
            }
        }
    return 0;
}

int imprimirUnEmpleado(Employee arrayEmployees){



        printf("\n%d\t%s\t\t%s\t\t%.2f\t%d", arrayEmployees.id, arrayEmployees.name, arrayEmployees.lastName, arrayEmployees.salary, arrayEmployees.sector );


        return 0;
}

Employee cargarUnEmpleado(){

    Employee empleadoCargado;

    printf("\n--COMPLETE CON LOS DATOS DEL EMPLEADO--\n\n");

    printf("Ingrese Nombre : ");
    fflush(stdin);
    scanf("%s", empleadoCargado.name);

    printf("Ingrese Apellido : ");
    fflush(stdin);
    scanf("%s", empleadoCargado.lastName);

    printf("Ingrese Salario : ");
    scanf("%f", &empleadoCargado.salary);

    printf("Ingrese Sector (1. Ventas - 2. Administracion - 3. Marketing - 4. Logistica - 5. Recursos Humanos) : ");
    scanf("%d", &empleadoCargado.sector);



    return empleadoCargado;
}

int buscarPosicionVacia(Employee arrayEmployees[], int limiteArray){

    int i;

    for(i=0 ; i < limiteArray ; i++){
        if(arrayEmployees[i].isEmpty == 0){
            break;
        }
    }

    return i;
}

int cargarArrayEmpleados(Employee arrayEmployees[], int limiteArray){

    system("cls");

    int continuar;

    for(int i = buscarPosicionVacia(arrayEmployees, qtyEmployees) ; i < limiteArray ; i++){
            arrayEmployees[i] = cargarUnEmpleado();
            arrayEmployees[i].isEmpty =1;


            printf("\n\n1. Para cargar otro empleado\n2. Para volver al menu");
            printf("\n\nINGRESE OPCION DESEADA : ");
            scanf("%d", &continuar);
            system("cls");
            fflush(stdin);

            if(continuar == 2){
                system("cls");
                break;
            }
        }

    return 0;
}

int listarEmpleados(Employee arrayEmployees[], int limiteArray){



    system("cls");
    float salarioPromedio;
    float salarioTotal;

    salarioTotal = calcularSalarioTotal(arrayEmployees, qtyEmployees);
    salarioPromedio = calcularSalarioPromedio(arrayEmployees, qtyEmployees);

    int i ;
    printf("--LISTADO DE EMPLEADOS--\n");
    printf("\nID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n");
    printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
    for(i = 0; i < limiteArray ; i++){
        if(arrayEmployees[i].isEmpty == 1){
            imprimirUnEmpleado(arrayEmployees[i]);
        }
    }
    printf("\n\n");
    printf("\nEL SALARIO PROMEDIO ES : %.2f", salarioPromedio);
    printf("\n");
    printf("\nEL SALARIO TOTAL ES : %.2f", salarioTotal);
    printf("\n");
    system("pause");
    system("cls");

    return 0;
}

int buscarEmpleadoPorId(Employee arrayEmployees[], int idBusqueda, int limiteArray){

    int i;

    for(i=0 ; i < limiteArray ; i++){
        if(arrayEmployees[i].id == idBusqueda){
            break;}
    }

    return i;
}

Employee modificarEmpleado(Employee arrayEmployees, int idAModificar){

    int opcion;
    char nombreNuevo[50];
    char apellidoNuevo[50];
    float salarioNuevo;
    int sectorNuevo;

    Employee empleadoModificado;
    empleadoModificado = arrayEmployees;

    printf("\n--LOS DATOS DEL EMPLEADO QUE QUIERE MODIFICAR SON LOS SIGUIENTES : ");
    imprimirUnEmpleado(arrayEmployees);
    printf("\n--OPCIONES PARA MODIFICAR--");
    printf("\n1.Nombre");
    printf("\n2. Apellido");
    printf("\n3. Salario");
    printf("\n4. Sector");
    printf("\n\nINGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA : ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("\n\nINGRESE NUEVO NOMBRE : ");
            fflush(stdin);
            scanf("%s", nombreNuevo);
            strcpy(empleadoModificado.name, nombreNuevo);
            break;
        case 2:
            printf("\nINGRESE NUEVO APELLIDO : ");
            fflush(stdin);
            scanf("%s", apellidoNuevo);
            strcpy(empleadoModificado.lastName, apellidoNuevo);
            break;
        case 3:
            printf("\nINGRESE NUEVO SALARIO : ");
            scanf("%f", &salarioNuevo);
            empleadoModificado.salary = salarioNuevo;
            break;
        case 4:
            printf("\nINGRESE NUEVO SECTOR : ");
            scanf("%d", &sectorNuevo);
            empleadoModificado.sector = sectorNuevo;
            break;
    }

    return empleadoModificado;
}

int eliminarEmpleadoPorId(Employee arrayEmployees[], int idBusqueda, int limiteArray){

    int i;

    for(i=0 ; i < limiteArray ; i++){
        if(arrayEmployees[i].id == idBusqueda){
          arrayEmployees[i].isEmpty = 0;
        }
    }

    return 0;


}

int OrdenarEmpleadosPorNombre (Employee arrayEmpleados[], int cantidad)
{
    int i;
    int j;
    Employee auxEmpleado;

   for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(strcmp(arrayEmpleados[i].lastName, arrayEmpleados[j].lastName)>0)
            {
                auxEmpleado = arrayEmpleados[i];
                arrayEmpleados[i] = arrayEmpleados[j];
                arrayEmpleados[j] = auxEmpleado;
            }
        }
    }
    return 0;
}


float calcularSalarioPromedio(Employee arrayEmployees[], int limiteArray){

    float salarioPromedio = 0;
    float salarioPromedioResultado;
    int contadorSalarios = 0;
    Employee auxEmployee;
    int i;

        for(i=0; i < limiteArray; i++){
            if (arrayEmployees[i].isEmpty == 1){
                salarioPromedio = salarioPromedio + arrayEmployees[i].salary;
                contadorSalarios++;
            }
        }
    salarioPromedioResultado = salarioPromedio / contadorSalarios;

return salarioPromedioResultado;
}

float calcularSalarioTotal(Employee arrayEmployees[], int limiteArray){

    float salarioTotal = 0;
    Employee auxEmployee;
    int i;
            for(i=0; i < limiteArray; i++){
                if (arrayEmployees[i].isEmpty == 1){
                    salarioTotal = salarioTotal + arrayEmployees[i].salary;
                }
            }

    return salarioTotal;
}

