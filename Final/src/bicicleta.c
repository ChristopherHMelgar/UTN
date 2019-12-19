#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "bicicleta.h"

bicicleta* new_bicicleta()
{
	return (bicicleta*)malloc(sizeof(bicicleta));
}

bicicleta* new_bicicletaConParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
	//agregar getter y setter
	bicicleta* pBicicleta=NULL;
	int id = atoi(idStr);
	int tiempo = atoi(tiempoStr); // viene en string por el parceo convierto a int

	pBicicleta = new_bicicleta();

	pBicicleta->ID_BIKE = id;
	strcpy(pBicicleta->NOMBRE, nombreStr);
	strcpy(pBicicleta->TIPO, tipoStr);
	pBicicleta->TIEMPO = tiempo;


	return pBicicleta;
}
