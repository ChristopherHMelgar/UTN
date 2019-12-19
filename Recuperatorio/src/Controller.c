#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "eComputer.h"

int controller_MAP(LinkedList* pArrayList);

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	//char nombreDeArchivo[20];

//	("Ingrese el nombre del archivo: ");


    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
  //  printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_eComputerFromText(pArchivo,pArrayList)==0)
    {
    	//printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_listComputer(LinkedList* pArrayList)
{
	//	printf("\nCONTROLLER LISTA DE CACHORROS") esta asi pq no tiene getter y setter, cambiar
		Node* nAux = pArrayList->pFirstNode;
		eComputer* computer = nAux->pElement;

		controller_MAP(pArrayList);

		for(int i=0; i<ll_len(pArrayList); i++){
			char idTipoAux[20];
			if(computer->idTipo == 1)
			{
				strcpy(idTipoAux, "DESKTOP");
			}
			if(computer->idTipo == 2)
			{
				strcpy(idTipoAux, "LAPTOP");
			}
			printf("ID: %d\n1.Descripcion: %s\n2.Precio: %d\n3.idTipo: %s\n4.Oferta: %s\n\n", computer->ID, computer->Descripcion, computer->precio, idTipoAux, computer->oferta);

			if(nAux->pNextNode != NULL){
				nAux = nAux->pNextNode;
				computer = nAux->pElement;
			}
		}
		return 1;
}

int controller_orderComputer(LinkedList* pArrayList)
{
	printf("\nLISTA DE COMPUTADORAS ORDENADAS POR ID TIPO: \n");
	if(pArrayList != NULL)
	{
		if(ll_sort(pArrayList, computer_order_idTipo, 1) == 0)
		{
			controller_listComputer(pArrayList);
		}
	}

	return	0;
}

int controller_MAP(LinkedList* pArrayList)
{
	int retorno = -1;
	printf("\nMAP DE COMPUTADORAS: \n");
	if(pArrayList != NULL)
	{
		if(ll_map(pArrayList, computer_oferta) == 0)
		{
//			controller_listComputer(pArrayList);
			retorno = 0;
		}
	}
	return retorno;
}

int controller_filterDesktop(LinkedList* pArrayList)
{
	printf("\nFILTRO DE COMPUTADORAS DESKTOP: \n");
	if(pArrayList != NULL)
	{
		controller_listComputer(ll_filter(pArrayList, computer_desktop));
	}
	return 0;
}
