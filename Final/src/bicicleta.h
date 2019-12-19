#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct{
	int ID_BIKE;
	char NOMBRE[20];
	char TIPO[20];
	int TIEMPO;
}bicicleta;

bicicleta* new_bicicleta();
bicicleta* new_bicicletaConParametros(char* id, char* nombre, char* tipo, char* tiempo);

#endif /* BICICLETA_H_ */
