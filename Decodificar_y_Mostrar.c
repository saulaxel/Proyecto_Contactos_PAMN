/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
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
#define maxContactos 10 /* El máximo de contactos aun falta decidirlo pero por el momento será 10 */
#define nombreArchivo "misContactos.txt" /* Se define el nombre del archivo como una cadena constante */

struct contacto /* Definición de la estructura "contacto" */
{
	/*Datos de "contacto", todos alfanuméricos */
};

typedef struct contacto Contacto; /* Se define un alias para "struct contacto" que será "Contacto" */

int leerArchivo(FILE *, Contacto *); /* Prototipo de la función "leerArchivo" */
void decodificar(Contacto *, int ); /* Prototipo de la función "decodificar" */

int main(int argc, char * argv[]){
	Contacto listaContactos[maxContactos]; /* Se declara un arreglo de contactos con el tamaño definido en la variable maxContactos */
	int numContactos; /* Se crea un contador de "Contactos" */
	FILE *aptdrArchivo; /* apuntador a file para referenciar un archivo abierto */
	
	/* ### Parte 1: Mensajes iniciales ### */
	
	/* ### Parte 2: Leer y decodificar ### */
	numContactos = leerArchivo(aptdrArchivo,listaContactos);
	decodificar(listaContactos,numContactos);
	
	/* ### Parte 3: Impresión con formato ### */
	
	/* ### Parte 4: Mensaje de despedida ### */
	  /* Aquí va el mismo mensaje de despedida que en el primer programa*/
	getchar();
	return 0;
}

/* Codigo de la función leerArchivo */
int leerArchivo(FILE *archivo, Contacto *listaContactos){
	
}

/* Codigo de la función decodificar */
void decodificar(Contacto *listaContactos, int numContactos){
	
} 
