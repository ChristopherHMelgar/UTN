#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define RETORNO_EXITOSO 0
#define ERROR -1
#define CANTIDAD_PERSONAS 2

struct direccion {
	char calle[20];
	int numero;
};
struct persona {
	char nombre[20];
	char apellido[20];
	struct direccion domicilio;
};

void menu(int *opcionMenu);
int alta(struct persona[], struct direccion[], int cantidadDePersonas);
int baja();
int modificacion();
int listar();
int ordenar();


int main(void) {
	int opcionMenu, salir = 0;
	struct persona empleado[CANTIDAD_PERSONAS];
	struct direccion domicilio[CANTIDAD_PERSONAS];
		do {
			menu(&opcionMenu);
			printf("OPCION ACTUAL DEL MENU: %d\n", opcionMenu);
			switch(opcionMenu) {
				case 1: alta(empleado, domicilio, CANTIDAD_PERSONAS);
					break;
				case 2: baja();
					break;
				case 3: modificacion();
					break;
				case 4: listar(empleado);
					break;
				case 5: ordenar();
					break;
				case 6: salir = 1;
					printf("\nADIOS");
					break;
			}
		} while(salir != 1);
		return RETORNO_EXITOSO;
}

void menu(int *opcionMenu) {
	int opcionUsuario;
	printf("\n");
	printf("1. ALTA\n");
	printf("2. BAJA\n");
	printf("3. MODIFICACION\n");
	printf("4. LISTAR\n");
	printf("5. ORDENAR\n");
	printf("6. SALIR\n");
	printf("**ELEGIR UNA OPCION PARA CONTINUAR**");
	scanf("%d", &opcionUsuario);
	*opcionMenu = opcionUsuario;
}

int alta(struct persona empleado[], struct direccion domiciolio[], int cantidadDePersonas) {
	int regresar = 0;
	int flag = 0;
	do {
		if(!getStringLetras("Ingrese el nombre: ", empleado[flag].nombre)){
			printf("\nEl nombre solo debe contener letras");
			continue;
		}
		if(!getStringLetras("Ingrese el apellido: ", empleado[flag].apellido)){
			printf("\El apellido solo debe contener letras");
			continue;
		}
		printf("\nDesea seguir cargando empleados?: ");
		scanf("%d", &regresar);
		flag++;
		if(flag >= cantidadDePersonas) {
			printf("Ya no puede cargar mas empleados");
			regresar = 1;
		}
	}while(regresar != 1);

	return 0;
}

int baja() {
	printf("BAJA");
	return 0;
}

int modificacion() {
	printf("MODIFICACION");
	return 0;
}

int listar(struct persona empleado[]) {
	printf("**LISTAR**");
	for(int i=0; i<2; i++){
		printf("\nNOMBRE: %s", empleado[i].nombre);
		printf("  APELLIDO: %s", empleado[i].apellido);
	}
	return 0;
}

int ordenar() {
	printf("ORDENAR");
	return 0;
}
