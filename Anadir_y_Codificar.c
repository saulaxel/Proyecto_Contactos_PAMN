/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * 			"Sistema de seguridad para contactos"
 * Parte 1: Añadir contactos codificados a documento de texto
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
	/*Datos de "contacto", todos alfanuméricos (cadenas) puesto que así son más faciles de manejar */
};

typedef struct contacto Contacto; /* Se define un alias para "struct contacto" que será "Contacto" */

int leerArchivo(FILE *, Contacto *); /* Prototipo de la función "leerArchivo" */ 
void escribirArchivo(FILE *, Contacto *); /* Prototipo de la función "escribirArchivo" */
void codificar(Contacto *, int ); /* Prototipo de la función "codificar" */
void decodificar(Contacto *, int ); /* Prototipo de la función "decodificar" */
int agregarContacto(Contacto *,int); /* Prototipo de la función "agregarContacto" */
int borrarContacto(Contacto *,int); /* Prototipo de la función "borrarContacto" */
void actualizarContacto(Contacto *, int); /* Prototipo de la función "actualizarContacto" */

int main(int argc, char * argv[]){
	Contacto listaContactos[maxContactos]; /* Se declara un arreglo de contactos con el tamaño definido en la variable maxContactos */
	int numContactos; /* Se crea un contador de "Contactos" */
	FILE *aptdrArchivo; /* apuntador a file para referenciar un archivo abierto */
	
	/* ### Parte 1: Mensajes iniciales ### */
	
	
	/* 
	 * ### Parte 2: Leer los contactos existentes ### 
	 * Como en esta sección solo se llama a la función, la persona a la que
	 * le toque esta parte solo tiene que construir el metodo de dicha función
	 * el cual se encuentra vacio actualmente
	 */
	numContactos = leerArchivo(aptdrArchivo,listaContactos);
	
	/* 
	* ### Parte 3: Decodificar los contactos ### 
	* Como en esta sección solo se llama a la función, la persona a la que
	* le toque esta parte solo tiene que construir el metodo de dicha función
	* el cual se encuentra vacio actualmente
	*/
	decodificar(listaContactos,numContactos);
	
	/* 
	 * ### Parte 4: Menú ###
	 * Hay varias funciones que son llamadas en esta sección pero
	 * hacerlas no necesariamente es responsabilidad de la persona que crea
	 * el menú pues son acciones independientes
	 */
	
	/* ### Parte 5: Mensaje de despedida ### */
	
	getchar();
	return 0;
}

/* Codigo de la función leerArchivo */
int leerArchivo(FILE *archivo, Contacto *listaContactos){
	
}

/* Codigo de la función codificar */
void codificar(Contacto *listaContactos, int numContactos){
	
} 

/* Codigo de la función decodificar */
void decodificar(Contacto *listaContactos, int numContactos){
	
} 

/* Codigo de la función agregarContacto */
int agregarContacto(Contacto *listaContactos,int numContactos){
	
}

/* Codigo de la función borrarContacto */
int borrarContacto(Contacto *listaContactos,int numContactos){
	
}

/* Codigo de la función actualzarContacto */
void actualizarContacto(Contacto *listaContactos,int numContactos){
	
}

