#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "bicicleta.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	//char nombreDeArchivo[20];

//	("Ingrese el nombre del archivo: ");


    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
  //  printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_bicicletaFromText(pArchivo,pArrayList)==0)
    {
    	//printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_listBicicleta(LinkedList* pArrayList)
{
	//	printf("\nCONTROLLER LISTA DE CACHORROS") esta asi pq no tiene getter y setter, cambiar
		Node* nAux = pArrayList->pFirstNode;
		bicicleta* bicicleta = nAux->pElement;

//		controller_MAP(pArrayList);

		for(int i=0; i<ll_len(pArrayList); i++){
//			char idTipoAux[20];
//			if(bicicleta->idTipo == 1)
//			{
//				strcpy(idTipoAux, "DESKTOP");
//			}
//			if(bicicleta->idTipo == 2)
//			{
//				strcpy(idTipoAux, "LAPTOP");
//			}
			printf("ID_BIKE: %d\n1.NOMBRE: %s\n2.TIPO: %s\n3.TIEMPO: %d\n\n", bicicleta->ID_BIKE, bicicleta->NOMBRE, bicicleta->TIPO, bicicleta->TIEMPO);

			if(nAux->pNextNode != NULL){
				nAux = nAux->pNextNode;
				bicicleta = nAux->pElement;
			}
		}
		return 1;
}
