#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct direccion {
	char calle[20];
	int numero;

};

struct datosPersonales {
	char nombre[20];
	char apellido[20];
	struct direccion domicilio;
};


int main(void) {
	struct datosPersonales vecAgenda[3];
	struct direccion vecDir[3];

	for(int i=0; i<3; i++){
		printf("Ingrese el nombre: ");
		gets(vecAgenda[i].nombre);
		printf("Ingrese el apellido: ");
		gets(vecAgenda[i].apellido);

		printf("Ingrese la calle: ");
//		gets(vecAgenda[i].calle);
		gets(vecDir[i].calle);
		printf("Ingrese el numero: ");
//		scanf("%d", &vecAgenda[i].numero);
		scanf("%d", &vecDir[i].numero);
		__fpurge(stdin);

		vecAgenda[i].domicilio = vecDir[i];
	}

	for(int i=0; i<3; i++){
		printf("\nNombre y Apellido: %s %s", vecAgenda[i].nombre, vecAgenda[i].apellido);
		printf("\nDIRECCION: %s %d", vecAgenda[i].domicilio.calle, vecAgenda[i].domicilio.numero);
	}
}
