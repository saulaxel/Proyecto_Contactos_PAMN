/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * "Sistema de seguridad para contactos"
 * Parte 1: Añadir contactos codificados a documento de texto
 * Integrantes del equipo:
 * SIERRA GONZÁLEZ HÉCTOR ALEJANDRO
 * CABRERA LÓPEZ OSCAR EMILIO
 * MENDOZA GARCÍA ULISES
 * MARTÍNEZ ORTIZ SAÚL AXEL
 */

#include <stdio.h> // Biblioteca estándar para la entrada y salida
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_CONTACTOS 10000 // El profe se va a aburrir antes de ingresar el maximo de contactos
#define MAX_NOMBRE 50  // definimos las longitudes máximas
#define MAX_NUMERO 10  // del nombre, número de telefono,
#define MAX_CORREO 30  // correo electronico,
#define MAX_NUMCASA 3  // y numero de casa
#define NOMBRE_ARCHIVO "misContactos.txt" // Se define el nombre del archivo como una cadena constante
#ifdef _WIN32
	#define CLEAR "cls"
	#include "contrasena.h"
	#ifdef _WIN64
		#define CLEAR "cls"
	#endif
#else
	#define CLEAR "clear"
#endif

struct contacto { // Definición de la estructura "contacto"
	unsigned char nombre[MAX_NOMBRE + 1]; //Declaramos nombre como cadena ascii
	unsigned char numero[MAX_NUMERO + 1]; //extendido y sumamos uno para considerar
	unsigned char correo[MAX_CORREO + 1]; //el caracter fin de linea '\0'
	unsigned char numcasa[MAX_NUMCASA + 1];
};
typedef struct contacto Contacto; /* Se define un alias para "struct contacto" que será "Contacto" */

/*
 * Declaración: contarFilas: Archivo -> entero
 * Proposito: Función que abre el archivo de los contactos codificados 
 * y lo recorre completamente contando el número de filas que este 
 * contiene
 */
int contarFilas(FILE* );

/* Declaración: leerArchivo : Archivo, Contactos -> numero
 * Próposito: Esta función toma como parámetros un apuntador a un archivo y un
 * apuntador a un arreglo estructuras de contacto, lee los contactos almacenados
 * en el archivo y almacena cada uno en una estructura Contacto, al terminar
 * devuelve el número de contactosque leyo exitosamente-
 * Ejemplo: Con un archivo almacenando 10 contactos
 *	leerArchivo(ap_archivo, Contactos)
 * deberia devolver 10 y rellenar 10 elementos del arreglo
 */
int leerArchivo(FILE *, Contacto *);

/*
 * Declaración: decodificar : Contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * Contactos, y para cada uno de los datos que contiene esta estructura, resta 3
 * al cada caracter
 */
void decodificar(Contacto *, int );

/*
 * Declaración: imprimirContactos: Contacto , int -> vacio
 * Proposito: Función que toma por argumentos un arreglo de contactos 
 * y el tamaño del mismo para imprimir a pantalla todos los "contactos"
 */
void imprimirContactos(Contacto * , int);

int main(int argc, char * argv[]){
	setlocale (LC_ALL, "");
	Contacto *ap_lista_contactos;
	int num_contactos; // Contador de "Contactos"
	FILE *ap_archivo = NULL; /* apuntador a file para referenciar un archivo abierto */
	
	ap_lista_contactos = (Contacto *) calloc( contarFilas(ap_archivo) , sizeof(Contacto) );
	/* ### Parte 1: Mensajes iniciales ### */
	
	/* ### Parte 2: Leer y decodificar ### */
	num_contactos = leerArchivo(ap_archivo,ap_lista_contactos);
	decodificar(ap_lusta_contactos,num_contactos);
	
	/* ### Parte 3: Impresión con formato ### */
	imprimirContactos(ap_lista_contactos,num_contactos);
	
	/* ### Parte 4: Mensaje de despedida ### */
	  /* Aquí va el mismo mensaje de despedida que en el primer programa*/
	getchar();
	return 0;
}

// Codigo de la función contar filas
int contarFilas( FILE* ap_archivo ){
	int contador = 0;
	unsigned char *ap_cadena;
	
	ap_archivo = fopen(NOMBRE_ARCHIVO, "r");
	
	if( ap_archivo != NULL ){
		while( !feof(ap_archivo) ){
			fscanf(ap_archivo,"%[^\n]\n",ap_cadena);
			++contador;
		}
	}
	fclose(ap_archivo);
	return contador;
}

/* Codigo de la función leerArchivo */
int leerArchivo(FILE *archivo, Contacto *listaContactos){
	
}

/* Codigo de la función decodificar */
void decodificar(Contacto *listaContactos, int numContactos){
	
} 
