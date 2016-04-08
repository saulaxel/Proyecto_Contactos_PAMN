/*
 * Primer Proyecto Programaci�n Avanzada y metodos num�ricos
 * 			"Sistema de seguridad para contactos"
 * Parte 1: A�adir contactos codificados a documento de texto
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
	/*Datos de "contacto", todos alfanum�ricos (cadenas) puesto que as� son m�s faciles de manejar */
};

typedef struct contacto Contacto; /* Se define un alias para "struct contacto" que ser� "Contacto" */

int leerArchivo(FILE *, Contacto *); /* Prototipo de la funci�n "leerArchivo" */ 
void escribirArchivo(FILE *, Contacto *); /* Prototipo de la funci�n "escribirArchivo" */
void codificar(Contacto *, int ); /* Prototipo de la funci�n "codificar" */
void decodificar(Contacto *, int ); /* Prototipo de la funci�n "decodificar" */
int agregarContacto(Contacto *,int); /* Prototipo de la funci�n "agregarContacto" */
int borrarContacto(Contacto *,int); /* Prototipo de la funci�n "borrarContacto" */
void actualizarContacto(Contacto *, int); /* Prototipo de la funci�n "actualizarContacto" */

int main(int argc, char * argv[]){
	Contacto listaContactos[maxContactos]; /* Se declara un arreglo de contactos con el tama�o definido en la variable maxContactos */
	int numContactos; /* Se crea un contador de "Contactos" */
	FILE *aptdrArchivo; /* apuntador a file para referenciar un archivo abierto */
	
	/* ### Parte 1: Mensajes iniciales ### */
	
	
	/* 
	 * ### Parte 2: Leer los contactos existentes ### 
	 * Como en esta secci�n solo se llama a la funci�n, la persona a la que
	 * le toque esta parte solo tiene que construir el metodo de dicha funci�n
	 * el cual se encuentra vacio actualmente
	 */
	numContactos = leerArchivo(aptdrArchivo,listaContactos);
	
	/* 
	* ### Parte 3: Decodificar los contactos ### 
	* Como en esta secci�n solo se llama a la funci�n, la persona a la que
	* le toque esta parte solo tiene que construir el metodo de dicha funci�n
	* el cual se encuentra vacio actualmente
	*/
	decodificar(listaContactos,numContactos);
	
	/* 
	 * ### Parte 4: Men� ###
	 * Hay varias funciones que son llamadas en esta secci�n pero
	 * hacerlas no necesariamente es responsabilidad de la persona que crea
	 * el men� pues son acciones independientes
	 */
	
	/* ### Parte 5: Mensaje de despedida ### */
	
	getchar();
	return 0;
}

/* Codigo de la funci�n leerArchivo */
int leerArchivo(FILE *archivo, Contacto *listaContactos){
	
}

/* Codigo de la funci�n codificar */
void codificar(Contacto *listaContactos, int numContactos){
	
} 

/* Codigo de la funci�n decodificar */
void decodificar(Contacto *listaContactos, int numContactos){
	
} 

/* Codigo de la funci�n agregarContacto */
int agregarContacto(Contacto *listaContactos,int numContactos){
	
}

/* Codigo de la funci�n borrarContacto */
int borrarContacto(Contacto *listaContactos,int numContactos){
	
}

/* Codigo de la funci�n actualzarContacto */
void actualizarContacto(Contacto *listaContactos,int numContactos){
	
}

