#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define qtyEmployees 1000

int main()
{
    int opcionMenu;
    int buscarId;
    int indiceEncontrado;
    int opcionBajas;
    Employee empleadoModificado;
    Employee auxEmployee[qtyEmployees];

    limpiarArray(auxEmployee, qtyEmployees);


    do{
        printf("--ABM EMPLEADOS--\n");
        printf("\n1. ALTAS");
        printf("\n2. BAJAS");
        printf("\n3. MODIFICAR");
        printf("\n4. INFORMAR");
        printf("\n5. SALIR");
        printf("\n\nINGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA : ");
        fflush(stdin);
        scanf("%d", &opcionMenu);

        switch(opcionMenu){

            case 1:
                cargarArrayEmpleados(auxEmployee, qtyEmployees);
                generarID(auxEmployee, qtyEmployees);
                break;

            case 2:
               system("cls");
                printf("\n--INGRESO LA OPCION BAJAS--");
                printf("\n\nINGRESE EL NUMERO DE ID DEL EMPLEADO A DAR DE BAJA : ");
                scanf("%d", &buscarId);

                printf("\n\nEL EMPLEADO A DAR DE BAJA ES EL SIGUIENTE : \n");

                indiceEncontrado = buscarEmpleadoPorId(auxEmployee, buscarId, qtyEmployees);

                imprimirUnEmpleado(auxEmployee[indiceEncontrado]);

                printf("\n\n1. CONFIRMAR");
                printf("\n2. VOLVER AL MENU");
                printf("\n\nINGRESE OPCION DESEADA : ");
                scanf("%d", &opcionBajas);

                if(opcionBajas == 1){
                    eliminarEmpleadoPorId(auxEmployee, buscarId, qtyEmployees);
                    printf("\nEMPLEADO DADO DE BAJA EXITOSAMENTE!\n\n");
                    system("pause");
                    system("cls");
                }else{
                    system("cls");
                    break;
                }

                break;

            case 3:
                printf("\nIngreso la opcion modificar");
                printf("\nIngrese el numero de ID del empleado a modificar : ");
                scanf("%d", &buscarId);

                indiceEncontrado = buscarEmpleadoPorId(auxEmployee, buscarId, qtyEmployees);

                empleadoModificado = modificarEmpleado(auxEmployee[indiceEncontrado], qtyEmployees);

                auxEmployee[indiceEncontrado] = empleadoModificado;
                break;

            case 4:
                OrdenarEmpleadosPorNombre(auxEmployee, qtyEmployees);
                listarEmpleados(auxEmployee, qtyEmployees);
                break;
            case 5:
                printf("\nHasta luego!!");
                break;
        }

    }while(opcionMenu != 5);


    return 0;
}
