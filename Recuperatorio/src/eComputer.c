#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eComputer.h"

eComputer* new_eComputer()
{
	return (eComputer*)malloc(sizeof(eComputer));
}

eComputer* new_eComputerConParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr)
{
	//agregar getter y setter
	eComputer* pEcomputer=NULL;
	int id = atoi(idStr); // viene en string por el parceo convierto a int
	int precio = atoi(precioStr);
	int idTipo = atoi(idTipoStr);

	pEcomputer = new_eComputer();

	pEcomputer->ID = id;
	strcpy(pEcomputer->Descripcion, descripcionStr);
	pEcomputer->precio = precio;
	pEcomputer->idTipo = idTipo;
//	strcpy(pEcomputer->oferta, ofertaStr);

	return pEcomputer;
}

int computer_order_idTipo(void* this, void* thisMasUno)
{
	int retorno = 0;
	eComputer* orderIdTipo;
	eComputer* orderIdTipoMasUno;
	orderIdTipo = (eComputer*) this;
	orderIdTipoMasUno = (eComputer*) thisMasUno;

	if(this != NULL && thisMasUno != NULL && (orderIdTipo->idTipo > orderIdTipoMasUno->idTipo))
	{
		retorno = 1;
	}

	return retorno;
}

int computer_oferta(void* this)
{
	int retorno = 0;
	eComputer* computadoraOferta;
	computadoraOferta = (eComputer*) this;

	if(this != NULL)
	{
		printf("COMPU OFERTA: %d", computadoraOferta->idTipo);
		if(computadoraOferta->idTipo == 2)
		{
			strcpy(computadoraOferta->oferta, "SIN DATOS");
			retorno = 1;
		}
		if(computadoraOferta->idTipo == 1 && computadoraOferta->precio > 20000)
		{
			strcpy(computadoraOferta->oferta, "50% DESCUENTO");
			retorno = 1;
		}
	}

	return retorno;
}

int computer_desktop(void* this)
{
	int retorno = 0;
	eComputer* desktop;
	desktop = (eComputer*) this;

	if(this != NULL && (desktop->idTipo == 1))
	{
		retorno = 1;
	}

	return retorno;
}
