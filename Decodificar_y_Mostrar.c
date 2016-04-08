/*
 * Primer Proyecto Programaci�n Avanzada y metodos num�ricos
 * 			"Sistema de seguridad para contactos"
 * Parte 2: Decodificar contactos y mostrarlos en consola
 * Integrantes del equipo:
	*
	*
	*	
	*
	*
	*
 */

#include <stdio.h> /* Para las funciones printf, scanf, getch */
#define maxContactos 10 /* El m�ximo de contactos aun falta decidirlo pero por el momento ser� 10 */
#define nombreArchivo "misContactos.txt" /* Se define el nombre del archivo como una cadena constante */

struct contacto /* Definici�n de la estructura "contacto" */
{
	/*Datos de "contacto", todos alfanum�ricos */
};

typedef struct contacto Contacto; /* Se define un alias para "struct contacto" que ser� "Contacto" */

int leerArchivo(FILE *, Contacto *); /* Prototipo de la funci�n "leerArchivo" */ 
void decodificar(Contacto *, int ); /* Prototipo de la funci�n "decodificar" */

int main(int argc, char * argv[]){
	Contacto listaContactos[maxContactos]; /* Se declara un arreglo de contactos con el tama�o definido en la variable maxContactos */
	int numContactos; /* Se crea un contador de "Contactos" */
	FILE *aptdrArchivo; /* apuntador a file para referenciar un archivo abierto */
	
	/* ### Parte 1: Mensajes iniciales ### */
	
	/* ### Parte 2: Leer y decodificar ### */
	numContactos = leerArchivo(aptdrArchivo,listaContactos);
	decodificar(listaContactos,numContactos);
	
	/* ### Parte 3: Impresi�n con formato ### */
	
	/* ### Parte 4: Mensaje de despedida ### */
	  /* Aqu� va el mismo mensaje de despedida que en el primer programa*/
	getchar();
	return 0;
}

/* Codigo de la funci�n leerArchivo */
int leerArchivo(FILE *archivo, Contacto *listaContactos){
	
}

/* Codigo de la funci�n decodificar */
void decodificar(Contacto *listaContactos, int numContactos){
	
} 
