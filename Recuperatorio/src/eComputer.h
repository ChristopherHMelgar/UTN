#ifndef ECOMPUTER_H_
#define ECOMPUTER_H_

typedef struct{
	int ID;
	char Descripcion[20];
	int precio;
	int idTipo;
	char oferta[20];
}eComputer;

eComputer* new_eComputer();
eComputer* new_eComputerConParametros(char* id, char* descripcion, char* precio, char* idTipo);
//int Cachorros_setId(Cachorro* this,int id);
//int Cachorros_getId(Cachorro* this,int* id);
//int Cachorros_Nombre(Cachorro* this,char* Nombre);
//int Cachorros_setRaza(Cachorro* this,char* Raza);
//int Cachorros_setDias(Cachorro* this,int Dias);
//int Cachorros_setReservado(Cachorro* this,char* Reservado);
//int Cachorros_Genero(Cachorro* this,char* Genero);
//int Cachorros_getId(Cachorro* this,int* id);
//int Cachorros_getNombre(Cachorro* this,char* nombre);
//int Cachorros_getDias(Cachorro* this,int* dias);
//int Cachorros_getRaza(Cachorro* this,char* Raza);
//int Cachorros_getReservado(Cachorro* this,char* Reservado);
//int Cachorros_getGenero(Cachorro* this,char* Genero);
//
//
//int cachorros_callejeros(void* this);
//int cachorros_dias(void* this);
//int cachorros_machos(void* this);
int computer_order_idTipo(void* this, void* thisMasUno);
int computer_oferta(void* this);
int computer_desktop(void* this);

#endif /* ECOMPUTER_H_ */
