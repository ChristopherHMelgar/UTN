#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void) {
	int opcionMenu;
		int salir = 0;
		LinkedList* listaComputer = ll_newLinkedList();
		LinkedList* listaPerrosFiltrados = ll_newLinkedList();
		do
		{
			menu(&opcionMenu);
			switch(opcionMenu)
			{
				case 1: controller_loadFromText("/home/chris/UTN/Recuperatorio/src/data.csv",listaComputer);
					break;
				case 2: controller_listComputer(listaComputer);
					break;
//				case 3:
//					listaPerrosFiltrados = ll_filter(listaComputer,cachorros_dias);
//					                    printf("Calculando\n");
//
//					                    if(listaPerrosFiltrados != NULL) {
//											if(controller_saveAsText("/home/chris/gitMarisa/Programacion1/Parcial2/src/menosDe45Dias.csv",listaPerrosFiltrados) == 0) {
//												printf("\nArchivo generado correctamente\n");
//											} else {
//												printf("Error generando archivo\n");
//											}
//					                    }
//
//					//controller_listCachorrosCallejeros(listaCachorros);
//					break;
				case 3: controller_orderComputer(listaComputer);
					break;
				case 4: controller_MAP(listaComputer);
					break;
				case 5: controller_filterDesktop(listaComputer);
					break;
//				case 7: controller_MAP(listaCachorros);
//					break;
				case 8: salir = 1;
					break;
			}
		} while(salir != 1);
}

void menu(int* opcionMenu)
{
	int opcionUsuario;
	printf("\n");
	printf("1. CARGARA ARCHIVO\n");
	printf("2. LISTAR COMPUTADORAS\n");
	printf("3. ORDENAR POR ID TIPO\n");
	printf("4. MAP\n");
	printf("5. SOLO DESKTOP\n");
	printf("8. SALIR\n");
	printf("**ELIGE UNA OPCION PARA CONTINUAR**");
	scanf("%d", &opcionUsuario);
	*opcionMenu = opcionUsuario;
}
