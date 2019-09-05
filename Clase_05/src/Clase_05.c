#include <stdio.h>
#include <stdlib.h>
#include "getInt.h"

#define CANTIDAD 5
int initArrayInt(int *pArray , int limite, int valor);
int printArrayInt(int *pArray , int limite);
int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);
int calcularSumaArrayInt(int *pArray , int limite, int *pResultadoSuma);
int calularPromedioArrayInt(int *pArray, int limite, int *pResultadoPromedio);
int calcularMaximoArrayInt(int *pArray, int limite, int *pResultadoMaximo);
int calcularMinimoArrayInt(int *pArray, int limite, int *pResultadoMinimo);
int printResultado(int resultado, char *pMensaje, char *pMensajeError);

int main(void) {
	int array[CANTIDAD] = {1,2,8,4,5};
	int resultadoSuma, resultadoPromedio, resultadoMaximo, resultadoMinimo;
	//initArrayInt(array, CANTIDAD, 23);
//	getArrayInt(array,
//				CANTIDAD,
//				"Ingrese un numero: \n",
//				"ERROR\n",
//				0,
//				200,
//				2);
	printArrayInt(array, CANTIDAD);
	calcularSumaArrayInt(array , CANTIDAD, &resultadoSuma);
	calularPromedioArrayInt(array, CANTIDAD, &resultadoPromedio);
	calcularMaximoArrayInt(array, CANTIDAD, &resultadoMaximo);
	calcularMinimoArrayInt(array, CANTIDAD, &resultadoMinimo);

	printResultado(resultadoSuma, "\nLa suma del Array es: ", "ERROR\n");
	printResultado(resultadoPromedio, "\nEl promedio del Array es: ", "ERROR\n");
	printResultado(resultadoMaximo, "\nEl numero maximo del array es: ", "ERROR\n");
	printResultado(resultadoMinimo, "\nEl numero minimo del array es: ", "ERROR\n");

	return EXIT_SUCCESS;
}

int initArrayInt(int *pArray , int limite, int valor)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i]=valor;
		}
		retorno = 0;
	}
	return retorno;
}

int printArrayInt(int *pArray , int limite)
{
	int retorno = -1;
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("\n\t%i",pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int retorno = -1;
	int buffer;
	int i=0;
	char respuesta;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		do
		{

			if(	getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limite)
				{
					break;
				}
			}

			printf("Continuar (s/n)? \n");
			__fpurge(stdin); // fflush(stdin)
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
		retorno = i;
	}
	return retorno;
}

int printResultado(int resultado, char *pMensaje, char *pMensajeError) {
	int retorno = 0;
	printf("%s %d", pMensaje, resultado);
	return retorno;
}

int calcularSumaArrayInt(int *pArray , int limite, int *pResultadoSuma)
{
	int retorno = -1;
	int i;
	int suma = 0;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			suma = suma + pArray[i];
		}
		retorno = 0;
	}
	*pResultadoSuma = suma;
	return retorno;
}

int calularPromedioArrayInt(int *pArray, int limite, int *pResultadoPromedio) {
	int retorno = -1;
	int suma;
	int promedio = 0;

	if(pArray != NULL && limite > 0) {
		calcularSumaArrayInt(pArray, limite, &suma);
		promedio = suma / limite;
		retorno = 0;
	}
	*pResultadoPromedio = promedio;
	return retorno;
}

int calcularMaximoArrayInt(int *pArray, int limite, int *pResultadoMaximo) {
	int retorno = -1;
	int maximo;
	if(pArray != NULL && limite > 0) {
		for(int i = 0; i < limite; i++) {
			if(i == 0 || pArray[i] > maximo) {
				maximo = pArray[i];
			}
			retorno = 0;
		}
	}
	*pResultadoMaximo = maximo;
	return retorno;
}

int calcularMinimoArrayInt(int *pArray, int limite, int *pResultadoMinimo) {
	int retorno = -1;
	int minimo;
	if(pArray != NULL && limite > 0) {
		for(int i = 0; i < limite; i++) {
			if(i == 0 || pArray[i] < minimo) {
				minimo = pArray[i];
			}
			retorno = 0;
		}
	}
	*pResultadoMinimo = minimo;
	return retorno;
}
