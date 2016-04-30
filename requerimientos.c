/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * "Sistema de seguridad para contactos"
 * Parte 0: Pedir contactos al usuario y guardarlos 
    * Este programa es parecido al llamado "Añadir_y_Codificar.c" pero con bastantes
    * menos caracteristicas, debido a que el programa antes mencionado fue el desarrollo
    * original de nuestro equipo pensado antes de disponer de la documentación con los 
    * requerimientos contcretos del proyecto. El programa original es bastante completo 
    * y cuenta con diversas caracteristicas extras con respecto a los requerimientos 
    * originales del proyecto.
    * Sin embargo el programa original no cumple con uno de los requerimientos originales: 
    * memoria dinámica al crear el arreglo decontactos.
    * A pesar de tratarse de un detalle simple, el añadirlo a estas alturas al
    * programa original resultaría problematico dado que este trabaja con un menú
    * que permite añadir contactos cuantas veces se quiera, detalle que de trabajarse 
    * junto con memoria dinámica, requeriría el uso de una estructura de datos para 
    * guardar los contactos que se van creando dinamicamente uno a uno (ya que no es 
    * posible garantizar la adyacencia en memoria de dichos contactos a menos que se 
    * crearan en una sola excibición) con lo que se tendrían que restructurar muchas 
    * cosas en el programa.
    * Por lo tanto, este programa es un añadido a los originalmente creados con el cual
    * se logran cumplir fielmente los requerimientos originales y nada más que dichos
    * requerimientos con el fin de no quedar faltos en la entrega.
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
#define MAX_CONTACTOS 100 
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
typedef struct contacto Contacto; // Se define un alias para
					// "struct contacto" que será "Contacto"

/* Declaración: presentacion : vacío -> vacío
 * Próposito: Esta función imprime nuestra portada, no toma ni devuelve nada
 * Ejemplo : presentacion();
 *	debería imprimir
 *	##################################
 *	#          Proyecto 3            #
 *	##################################
 */
void presentacion (void);

/*
 * Declaración: codificar : Contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * Contactos y un entero que indica el número de los mismos, para despues recorrer
 * cada uno de los datos de los mismos sumandole 3 al codigo de sus caracteres
 */
void codificar(Contacto *, int );

/*
 * Declaración: agregarContacto : Contactos, entero -> int
 * Propósito: Función que toma por argumentos el arreglo de contactos
 * y el número de contactos para añadir datos de un nuevo contacto al 
 * final del arreglo y devuelve 1 en caso de realizar la tarea con éxito
 * o 0 en caso contrario
 */
int agregarContacto(Contacto *,int);


/*
 * Declaración: escribirArchivo: Archivo, Contacto , int -> vacio
 * Proposito: Función que toma por argumentos un apuntador a archivo y 
 * un arreglo de contactos que usará para abrir un archivo de texto
 * y guardar en el datos de un número entero de estructuras "Contacto"
 */
void escribirArchivo(FILE *, Contacto *, int); // Prototipo de la función "escribirArchivo"

int main (int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	int num_contactos = 0; // Se crea un contador de "Contactos"
	Contacto *ap_lista_contactos; // apuntador a la lista de contactos
	FILE *ap_archivo = NULL; // apuntador a file para referenciar un archivo
	                         // abierto, lo iniciamos en NULL por seguridad
	int i;
	
	// ### Parte 1: Mensajes iniciales ###
	presentacion();
	#ifdef _WIN32
	validarUsuario();
	#endif //_WIN32
	
	/* 
	 * ### Parte 2: Pedir contactos al usuario ###
	 * Se pregunta al usuario cuantos contactos desea guardar y se le pide dicha 
	 * cantidad de veces datos para los contactos
	 */
	 printf("¿Cuántos contactos desea guardar?\n");
	 scanf("%d",&num_contactos);
	 ap_lista_contactos = calloc( num_contactos, sizeof(Contacto) );
	 for( i = 0; i < num_contactos; ++i ){
	    agregarContacto( ap_lista_contactos , i );
	 }
	 
	 /* ### Parte3: Guardar contactos en archivo ### */
	 codificar(ap_lista_contactos, num_contactos);
	 escribirArchivo( ap_archivo, ap_lista_contactos, num_contactos );

	/* ### Parte 4: Mensaje de despedida ### */
	return 0;
}

void presentacion () {
	printf ("\n###############################################\n"); //
	printf ("#   Universidad Nacional Aútonoma de México   #\n");
	printf ("#            Facultad de Ingeniería           #\n");
	printf ("#  Programación avanzada y métodos numéricos  #\n");
	printf ("#                  Proyecto 1                 #\n");
	printf ("#          Cabrera López Oscar Emilio         #\n");
	printf ("#             Mendoza García Ulises           #\n");
	printf ("#       Sierra González Héctor Alejandro      #\n");
	printf ("#           Martínez Ortiz Saúl Axel          #\n");
	printf ("###############################################\n\n");
}

/* Codigo de la función codificar */
void codificar(Contacto *ap_lista_contactos, int num_contactos){
	int i, j;
	unsigned char *apu;
	for (i = 0; i < num_contactos; i++) {
		apu = (ap_lista_contactos+i)->nombre;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->nombre); j++) {
			*apu += 3;
			apu++;
		}
		apu = (ap_lista_contactos+i)->numero;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->numero); j++) {
			*apu += 3;
			apu++;
		}
		apu = (ap_lista_contactos+i)->correo;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->correo); j++) {
			*apu += 3;
			apu++;
		}
		apu = (ap_lista_contactos+i)->numcasa;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->numcasa); j++) {
			*apu += 3;
			apu++;
		}
	}
}

/* Codigo de la función agregarContacto */
int agregarContacto(Contacto *ap_lista_contactos, int num_contactos){
	int i;
	unsigned short no_numero = 0, arroba = 0 , punto = 0, ascii_ext = 0;
	unsigned char *ap_c;
	if( num_contactos < MAX_CONTACTOS ){
		printf("Ingrese el nombre del nuevo contacto\n");
		scanf(" %50[^\n]", (ap_lista_contactos+num_contactos)->nombre);
		#ifdef _WIN32
		reparar((ap_lista_contactos+num_contactos)->nombre);
		#endif //_WIN32
		
		printf("Ingrese el número del nuevo contacto\n");
		scanf(" %10s", (ap_lista_contactos+num_contactos)->numero);
		ap_c = (ap_lista_contactos+num_contactos)->numero;
		for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->numero); i++) {
			if( *( ap_c + i ) < 48 || *( ap_c + i ) > 57 ){
				no_numero = 1;
			}
		}
		while( no_numero ){
			no_numero = 0;
			printf("Caracteres invalidos para un número de telefono. Vuelva a teclear el número\n");
			scanf(" %10s", (ap_lista_contactos+num_contactos)->numero);
			for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->numero); i++) {
				if( *( ap_c + i ) < 48 || *( ap_c + i ) > 57 ){
					no_numero = 1;
				}
			}
		}
		
		printf("Ingrese el correo del nuevo contacto\n");
		scanf(" %30s", (ap_lista_contactos+num_contactos)->correo);
		ap_c = (ap_lista_contactos+num_contactos)->correo;
		for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->correo); i++) {
			if( *( ap_c + i ) == 64 ){
				arroba = 1;
			}
			if( *( ap_c + i ) == 46){
				punto = 1;
			}
			if( *( ap_c + i ) > 128 ){
				ascii_ext = 1;
			}
		}
		while( !(arroba && punto) || ascii_ext ){
			arroba = 0; punto = 0; ascii_ext = 0;
			printf("Formato invalido para correo, favor de volver a escribirlo\n");
			scanf(" %30s", (ap_lista_contactos+num_contactos)->correo);
			for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->correo); i++) {
				if( *( ap_c + i ) == 64 ){
					arroba = 1;
				}
				if( *( ap_c + i ) == 46){
					punto = 1;
				}
				if( *( ap_c + i ) > 128 ){
					ascii_ext = 1;
				}
			}
		
		}
		
		printf("Ingrese el número de casa del nuevo contacto\n");
		scanf(" %3s", (ap_lista_contactos+num_contactos)->numcasa);
		ap_c = (ap_lista_contactos+num_contactos)->numcasa;
		for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->numcasa); i++) {
			if( *( ap_c + i ) < 48 || *( ap_c + i ) > 57 ){
				no_numero = 1;
			}
		}
		while( no_numero ){
			no_numero = 0;
			printf("Caracteres invalidos para un número de casa. Vuelva a teclear el número\n");
			scanf(" %3s", (ap_lista_contactos+num_contactos)->numcasa);
			for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->numcasa); i++) {
				if( *( ap_c + i ) < 48 || *( ap_c + i ) > 57 ){
					no_numero = 1;
				}
			}
		}
		return 1;
	}else{
		printf("Número de contactos máximo excedido\n");
		return 0;	
	}
}

//Codigo de la función para guardar todos los datos en un archivo de texto
void escribirArchivo(FILE *ap_archivo, Contacto *ap_lista_contactos, int num_contactos){
	int n;
	FILE *ap_archivo;
	ap_archivo = fopen(NOMBRE_ARCHIVO, "w");
	
	for( n = 0; n < num_contactos; ++n ){
		fprintf(ap_archivo ,"%s\t%s\t%s\t%s\n",
			(ap_lista_contactos + n)->nombre,
			(ap_lista_contactos + n)->numero,
			(ap_lista_contactos + n)->correo,
			(ap_lista_contactos + n)->numcasa
		);
	}	
}
