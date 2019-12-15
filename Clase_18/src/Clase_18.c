#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct{
	int legajo;
	char nombre[20];
	char apellido[20];
	float sueldo;
}eEmpleado;

//typedef struct{
//	int id;
//	char nombre[20];
//	int horasTrabajadas;
//	float sueldo;
//}FILE;

void mostrarEmpleados(eEmpleado** lista, int len);
void menu();
void cargaDeEmpleadosCSV();
eEmpleado* new_EmpleadoParam(int leg, char* nombre, char* apellido, float sueldo);
eEmpleado* new_Empleado();
int empleado_setLegajo(eEmpleado* this, int legajo);
int empleado_getLegajo(eEmpleado* this, int* legajo);
int empleado_setNombre(eEmpleado* this, char* nombre);
int empleado_getNombre(eEmpleado* this, char* nombre);

int main(void) {
	menu();

	return 0;
}

void menu(){
	char resp = 's';
	int opcion;
	while(resp == 's'){
		printf("\nMENU\n");
		printf("\nElija una de las opciones: ");
		printf("\n1.- Cargar empleados desde CSV");
		printf("\n3.- Alta de empleados");
		printf("\n4.- Modificar datos de empleado");
		printf("\n10.- Salir");
		scanf("%d", &opcion);
		__fpurge(stdin);
		switch(opcion) {
			case 1:
				cargaDeEmpleadosCSV();
				break;
			case 2:

				break;

			case 10:
				resp = 'n';
				printf("\nADIOS PERRO!");
				break;
		}
	}
}

void cargaDeEmpleadosCSV(){
	printf("\nCARGA DE EMPLEADOS CSV\n");
	FILE *parch;
//	if((parch==fopen("/home/chris/tp3/eclipse_tp3/tp3_linux/data.csv", "r")) == NULL){
//		printf("\El archivo no pudo ser abierto");
//	}
//	fclose(parch);
	int c;

	parch = fopen("/home/chris/tp3/eclipse_tp3/tp3_linux/data.csv", "r");
	while(1) {
		c = fgetc(parch);
		if(feof(parch)){
			break;
		}
		printf("%c", c);
	}
	fclose(parch);
}

void cargaDeEmpleadosManual(){
	eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*));
	eEmpleado** pAuxEmpleado;
	int cont = 0;

	char resp = 's';
	int bufLegajo;
	char bufNombre[20];
	char bufApellido[20];
	float bufSueldo;

	eEmpleado* nuevoEmpleado = new_Empleado();

	if(nuevoEmpleado != NULL){

	}
// 	MUESTRA LA INICIALIZACION
//	printf("\nLegajo 		Nombre		Apellido		Sueldo\n");
//	printf(" %5d 		%10s		%10s		%8.2f\n", nuevoEmpleado->legajo, nuevoEmpleado->nombre, nuevoEmpleado->apellido, nuevoEmpleado->sueldo);
//	printf("\n\n");

	while(resp == 's'){
		printf("\nIngresar el legajo");
		scanf("%d", &bufLegajo);
//		fflush(stdin);
		__fpurge(stdin);

		printf("\nIngrese el nombre");
		gets(bufNombre);
		__fpurge(stdin);

		printf("\nInrese el apellido");
		gets(bufApellido);
		__fpurge(stdin);

		printf("\nIngrese el sueldo");
		scanf("%f", &bufSueldo);
//		fflush(stdin);

		__fpurge(stdin);
		nuevoEmpleado = new_EmpleadoParam(bufLegajo, bufNombre, bufApellido, bufSueldo);

		 *(lista + cont) = nuevoEmpleado; //version con aritmetica de punteros
//		 lista[cont] = nuevoEmpleado; //notacion vectorial

		 printf("\n Desea ingresar otro Empleado? s/n: ");
		 scanf("%c", &resp);
		 fflush(stdin);

		 if(resp == 's'){
			 cont++;
			 pAuxEmpleado = (eEmpleado**) realloc(lista, sizeof(eEmpleado*) * (cont + 1));
			 if(pAuxEmpleado == NULL){
				 exit(1);
			 }
			 lista = pAuxEmpleado;
		 }

	}

	printf("\nLegajo	Nombre		Apellido	Sueldo \n");
	mostrarEmpleados(lista, cont);

	free(lista);
//	free(pAuxEmpleado); //free() invalid pointer
	free(nuevoEmpleado);
}

eEmpleado* new_Empleado(){

	eEmpleado* emp = (eEmpleado*) malloc(sizeof(eEmpleado));

	if(emp != NULL){
		emp->legajo = 0;
		strcpy(emp->nombre, "");
		strcpy(emp->apellido, "");
		emp->sueldo = 0;
	}
	return emp;
}

void mostrarEmpleados(eEmpleado** lista, int len){
	int auxLeg;
	char auxNom[20];
	for(int i = 0; i <= len; i++){
		empleado_getLegajo(*(lista + i), &auxLeg);
		empleado_getNombre(*(lista + i), &auxNom);
		printf(" %5d 	%10s	%10s	%8.2f\n", auxLeg, auxNom, (*(lista + i))->apellido, (*(lista + i))->sueldo);
	}
	printf("\n\n");
}

eEmpleado* new_EmpleadoParam(int leg, char* nombre, char* apellido, float sueldo){
	eEmpleado* emp = (eEmpleado*) malloc(sizeof(eEmpleado));
	if(emp != NULL){

		empleado_setLegajo(emp, leg);
//		emp->legajo = leg;
		empleado_setNombre(emp, nombre);
//		strcpy(emp->nombre, nombre);
		strcpy(emp->apellido, apellido);
		emp->sueldo = sueldo;
	}
	return	emp;
}

int empleado_setLegajo(eEmpleado* this, int legajo){
	int todoOk = 0;
	if(this != NULL && legajo > 0){
		this->legajo = legajo;
		todoOk = 1;
	}

	return todoOk;
}

int empleado_getLegajo(eEmpleado* this, int* legajo){
	int todoOk = 0;
	if(this != NULL && legajo != NULL){
		*legajo = this->legajo;
		todoOk = 1;
	}

	return	todoOk;
}

int empleado_setNombre(eEmpleado* this, char* nombre){
	int todoOk = 0;
	if(this != NULL && !*nombre == 0){
		strcpy(this->nombre, nombre);
		todoOk = 1;
	}

	return todoOk;
}

int empleado_getNombre(eEmpleado* this, char* nombre){
	int todoOk = 0;
	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}

	return todoOk;
}
