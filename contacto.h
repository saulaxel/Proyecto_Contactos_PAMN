#ifndef CONTACTO_H_INCLUDED
	#define CONTACTO_H_INCLUDED
#endif
/* Biblioteca exclusiva para su uso en el proyecto de Programación
* avanzada y metodos numéricos, la cual esta sujeta a las especificaciones
* de este
*/

/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * "Sistema de seguridad para contactos"
 * Biblioteca contacto.h que incorpora funciones utilizadas en ambos programas
 * Integrantes del equipo:
 * SIERRA GONZÁLEZ HÉCTOR ALEJANDRO
 * CABRERA LÓPEZ OSCAR EMILIO
 * DÍAZ ALFÉREZ MELISA
 * MENDOZA GARCÍA ULISES
 * MARTÍNEZ ORTIZ SAÚL AXEL
 */

#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTOS 100
#define MAX_NOMBRE 50  // definimos las longitudes máximas
#define MAX_NUMERO 10  // del nombre, número de telefono,
#define MAX_CORREO 30  // correo electronico,
#define MAX_NUMCASA 8  // y numero de casa
#define NOMBRE_ARCHIVO "misContactos.txt" // Se define el nombre del archivo como una cadena constante
#ifdef _WIN32 // Si se trabaja en windows
	#define CLEAR "cls"
	#include "contrasena.h"
#else // En caso contrario ( provablemente unix/linux )
	#define CLEAR "clear"
#endif // Fin del #if _WIN32

// funcion de presentación
// imprime gatos, almohadillas o numerales, por los problemas con ascii en linux

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

/*
 * Declaración: codificar : Contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * Contactos y un entero que indica el número de los mismos, para despues recorrer
 * cada uno de los datos de los mismos sumandole 3 al codigo de sus caracteres
 */
void codificar (Contacto *ap_lista_contactos, int num_contactos) {
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

/*
 * Declaración: agregarContacto : Contactos, entero -> int
 * Propósito: Función que toma por argumentos el arreglo de contactos
 * y el número de contactos para añadir datos de un nuevo contacto al
 * final del arreglo y devuelve 1 en caso de realizar la tarea con éxito
 * o 0 en caso contrario
 */
int agregarContacto (Contacto *ap_lista_contactos, int num_contactos) {
	int i;
	unsigned short no_numero = 0, arroba = 0 , punto = 0, ascii_ext = 0;
	unsigned char *ap_c;
	if( num_contactos < MAX_CONTACTOS ){
		printf("Ingrese el nombre del nuevo contacto\n");
		scanf(" %50[^\n]\n", (ap_lista_contactos+num_contactos)->nombre);
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

/*
 * Declaración: escribirArchivo: Archivo, Contacto , int -> vacio
 * Proposito: Función que toma por argumentos un apuntador a archivo y
 * un arreglo de contactos que usará para abrir un archivo de texto
 * y guardar en el datos de un número entero de estructuras "Contacto"
 */void escribirArchivo(FILE *ap_archivo, Contacto *ap_lista_contactos, int num_contactos){
	int n;
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

/*
 * Declaración: contarFilas: Archivo -> entero
 * Proposito: Función que abre el archivo de los contactos codificados
 * y lo recorre completamente contando el número de filas que este
 * contiene
 */
int contarFilas( FILE* ap_archivo ){
	int contador = 0;
	unsigned char cadena[MAX_NOMBRE+MAX_CORREO+MAX_NUMERO+MAX_NUMCASA+5];
	unsigned char *ap_cadena = cadena;

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

/* Declaración: leerArchivo : Archivo, Contactos -> numero
 * Próposito: Esta función toma como parámetros un apuntador a un archivo y un
 * apuntador a un arreglo estructuras de contacto, lee los contactos almacenados
 * en el archivo y almacena cada uno en una estructura Contacto, al terminar
 * devuelve el número de contactosque leyo exitosamente-
 * Ejemplo: Con un archivo almacenando 10 contactos
 *	leerArchivo(ap_archivo, Contactos)
 * deberia devolver 10 y rellenar 10 elementos del arreglo
 */
int leerArchivo(FILE *ap_archivo, Contacto *ap_lista_contactos) {
	int num_contactos = 0, j = 0; // declaramos los contadores que usaremos
	ap_archivo = fopen (NOMBRE_ARCHIVO, "r+"); // abrimos el archivo en
	// modo lectura o creación, para asegurarnos que exista
	if (ap_archivo == NULL) { // manejamos el caso en que no se pueda crear el archivo
		return 0; // Si el archivo no está trabajaremos en blanco por lo que se
		// devuelve 0 y los contactos se irán creando conforme al usuario
		//printf ("\nNo se pudo leer, ni crear el archivo D:\n\t");
		//printf ("Asegurate de tener permisos suficientes para leer o escribir aquí\n");
		//exit(-1); // salimos indicando un error al sistema operativo
	}
	while (!feof(ap_archivo)) { // mientras no acabe el archivo
		fscanf(ap_archivo," %50[^\t]\t%10[^\t]\t%30[^\t]\t%3[^\n]\n", // este scanset toma
				// los valores separados con tabuladores, y solo permite espacios en la
				// cadena del nombre, explicado un poco más:
				// ' %50[^\t]' lee y guarda hasta 50 caracteres o hasta encontrar
				// un tabulador (sin almacenar el tabulador)
				// '\t' lee y descarta el tabulador
				// '%10[^\t]' lee y guarda hasta 10 caracteres o encontrar un tabulador,
				// espacio, o un salto de linea
				// '\t' lee y descarta el tabulador
				// '%30[^\t]' lee y guarda hasta 30 caracteres o encontrar un tabulador
				// '%3[^\n]' lee y guarda hasta 3 caracteres o un salto de linea
               ap_lista_contactos->nombre,// guarda la primer cadena aqui
               ap_lista_contactos->numero, // la segunda cadena aqui
               ap_lista_contactos->correo, // la tercer cadena aqui
               ap_lista_contactos->numcasa); // y la cuarta aquí
		num_contactos++; //aumentamos el contador de contactos
		ap_lista_contactos++; // y pasamos al siguiente elemento
	}
	for (j = 0; j < num_contactos; j++) {
		ap_lista_contactos--; // devolvemos el apuntador apuntando al primer elemento
	}
	fclose (ap_archivo); // limpiamos nuestra area de trabajo
	return num_contactos; // disminuimos y devolvemos el numero de contactos
}

/*
 * Declaración: decodificar : Contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * Contactos, y para cada uno de los datos que contiene esta estructura, resta 3
 * al cada caracter
 */
void decodificar(Contacto *ap_lista_contactos, int num_contactos){
	int i, j;
	unsigned char *apu;
	for (i = 0; i < num_contactos; i++) {
		apu = (ap_lista_contactos+i)->nombre;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->nombre); j++) {
			*apu -= 3;
			apu++;
		}
		apu = (ap_lista_contactos+i)->numero;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->numero); j++) {
			*apu -= 3;
			apu++;
		}
		apu = (ap_lista_contactos+i)->correo;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->correo); j++) {
			*apu -= 3;
			apu++;
		}
		apu = (ap_lista_contactos+i)->numcasa;
		for (j = 0; j < strlen ((ap_lista_contactos+i)->numcasa); j++) {
			*apu -= 3;
			apu++;
		}
	}
}

/*
 * Declaración: imprimirContactos: Contacto , int -> vacio
 * Proposito: Función que toma por argumentos un arreglo de contactos
 * y el tamaño del mismo para imprimir a pantalla todos los "contactos"
 */
void imprimirContactos(Contacto *ap_lista_contactos, int num_contactos){
	int n;

	printf("Los contactos guardados son:\n");
	for( n = 0; n < num_contactos; ++n ){
		printf("Nombre: %s\tNumero: %s\nCorreo: %s\t Número de casa: %s\n\n",
		       (ap_lista_contactos + n)->nombre,
		       (ap_lista_contactos + n)->numero,
		       (ap_lista_contactos + n)->correo,
		       (ap_lista_contactos + n)->numcasa
		);
	}
}