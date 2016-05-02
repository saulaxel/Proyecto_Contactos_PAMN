#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED
/* Biblioteca exclusiva para su uso en el proyecto de Programaci�n
* avanzada y metodos num�ricos, la cual esta sujeta a las especificaciones
* de este
*/

/*
 * Primer Proyecto Programaci�n Avanzada y metodos num�ricos
 * "Sistema de seguridad para contactos"
 * Biblioteca contacto.h que incorpora funciones utilizadas en ambos programas
 * Integrantes del equipo:
 * SIERRA GONZ�LEZ H�CTOR ALEJANDRO
 * CABRERA L�PEZ OSCAR EMILIO
 * D�AZ ALF�REZ MELISA
 * MENDOZA GARC�A ULISES
 * MART�NEZ ORTIZ SA�L AXEL
 */

#include <stdio.h> // Biblioteca est�ndar para la entrada y salida
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_CONTACTOS 100
#define MAX_NOMBRE 50  // definimos las longitudes m�ximas
#define MAX_NUMERO 10  // del nombre, n�mero de telefono,
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

// funcion de presentacion, para m�s informacion ir a la declaraci�n
// imprime gatos, almohadillas o numerales, por los problemas con ascii en linux
// alguien usando windows deberia corregirlo
void presentacion () {
	printf ("\n###############################################\n"); //
	printf ("#   Universidad Nacional A�tonoma de M�xico   #\n");
	printf ("#            Facultad de Ingenier�a           #\n");
	printf ("#  Programaci�n avanzada y m�todos num�ricos  #\n");
	printf ("#                  Proyecto 1                 #\n");
	printf ("#          Cabrera L�pez Oscar Emilio         #\n");
	printf ("#             D�az ALf�rez Melisa             #\n");
	printf ("#             Mendoza Garc�a Ulises           #\n");
	printf ("#       Sierra Gonz�lez H�ctor Alejandro      #\n");
	printf ("#           Mart�nez Ortiz Sa�l Axel          #\n");
	printf ("###############################################\n\n");
}
// funcion de despedida al t�rmino de la ejecuci�n del programa
void despedida () {
	printf ("\n###############################################\n"); //
	printf ("# Muchas gracias por utilizar nuestro servicio  #\n");
	printf ("#                  Vuelva pronto                #\n");
	printf ("###############################################\n\n");

}

// funcion de presentacion, para m�s informacion ir a la declaraci�n
int menu (void) { // damos un valor inicial a seleccion
	int seleccion;
	printf ("\n\t\tBienvenido. \n\t Elige una opci�n:"); // peticion al usuario
	printf ("\n\t1. A�adir contacto "); // primer opci�n
	printf ("\n\t2. Actualizar contacto"); // segunda opci�n
	printf ("\n\t3. Borrar contactos"); // tercer opci�n
	printf ("\n\t4. Salir\n"); // salida del programa
	scanf ("%d", &seleccion); // asignamos una opcion a la secci�n
	return seleccion;
}


/* Codigo de la funci�n codificar */
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

/* Codigo de la funci�n decodificar */
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

/* Codigo de la funci�n agregarContacto */
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

		printf("Ingrese el n�mero del nuevo contacto\n");
		scanf(" %10s", (ap_lista_contactos+num_contactos)->numero);
		ap_c = (ap_lista_contactos+num_contactos)->numero;
		for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->numero); i++) {
			if( *( ap_c + i ) < 48 || *( ap_c + i ) > 57 ){
				no_numero = 1;
			}
		}
		while( no_numero ){
			no_numero = 0;
			printf("Caracteres invalidos para un n�mero de telefono. Vuelva a teclear el n�mero\n");
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

		printf("Ingrese el n�mero de casa del nuevo contacto\n");
		scanf(" %3s", (ap_lista_contactos+num_contactos)->numcasa);
		ap_c = (ap_lista_contactos+num_contactos)->numcasa;
		for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->numcasa); i++) {
			if( *( ap_c + i ) < 48 || *( ap_c + i ) > 57 ){
				no_numero = 1;
			}
		}
		while( no_numero ){
			no_numero = 0;
			printf("Caracteres invalidos para un n�mero de casa. Vuelva a teclear el n�mero\n");
			scanf(" %3s", (ap_lista_contactos+num_contactos)->numcasa);
			for (i = 0; i < strlen ((ap_lista_contactos+num_contactos)->numcasa); i++) {
				if( *( ap_c + i ) < 48 || *( ap_c + i ) > 57 ){
					no_numero = 1;
				}
			}
		}
		return 1;
	}else{
		printf("N�mero de contactos m�ximo excedido\n");
		return 0;
	}
}

/* Codigo de la funci�n borrarContacto */
int borrarContacto(Contacto *ap_lista_contactos, int num_contactos){
	unsigned char nombre[MAX_NOMBRE+1];
	unsigned char *ap_nombre;
	int posicion;

	if( num_contactos = 0 ){
		printf("No hay contactos a sacar\n");
		return 0;
	}else{
		printf("Ingrese el nombre del contacto que desea borrar\n");
		scanf(" %50[^\n]",ap_nombre);
		#ifdef _WIN32
		reparar(ap_nombre);
		#endif //_WIN32

		if( (posicion = buscar(ap_lista_contactos, ap_nombre) ) == -1 ){
			printf("Contacto no encontrado\n");
			return 0;
		}else{
			int i; // Contador para el ciclo
			for( i = posicion ; i < MAX_CONTACTOS - 2 ; ++i ){
				strcpy( (ap_lista_contactos + i)->nombre, (ap_lista_contactos + i + 1)->nombre );
				strcpy( (ap_lista_contactos + i)->numero, (ap_lista_contactos + i + 1)->numero );
				strcpy( (ap_lista_contactos + i)->correo, (ap_lista_contactos + i + 1)->correo );
				strcpy( (ap_lista_contactos + i)->numcasa, (ap_lista_contactos + i + 1)->numcasa );
			}

			memset( (ap_lista_contactos + i)->nombre, '\0', 50 );
			memset( (ap_lista_contactos + i)->numero, '\0', 10 );
			memset( (ap_lista_contactos + i)->correo, '\0', 30 );
			memset( (ap_lista_contactos + i)->numcasa, '\0', 3 );

			printf("Contacto borrado exitosamente\n");
			return 1;
		}
	}
}

/* Codigo de la funci�n actualzarContacto */
void actualizarContacto(Contacto *ap_lista_contactos, int num_contactos){
	unsigned char cadena[MAX_NOMBRE+1];
	unsigned char *ap_cadena;
	int posicion;

	printf("Ingrese el nombre del contacto que desea actualizar\n");
	scanf(" %50[^\n]", ap_cadena);
	#ifdef _WIN32
	reparar(ap_cadena);
	#endif //_WIN32

	if( (posicion = buscar(ap_lista_contactos, ap_cadena) ) == -1 ){
		printf("Contacto no encontrado\n");
	}else{
		unsigned short s; // Entero que guarda la selecci�n del usuario
		unsigned short i; // Entero contador
		unsigned short no_numero = 0, arroba = 0, punto = 0, ascii_ext = 0; // Enteros usados como banderas booleana
		printf("Indique el dato del contacto que desea actualizar:\n");
		printf("\t1. %s\n\t2. %s\n\t3. %s\n\t4. %s\n\t5. %s\n\n",
			"Nombre","Telefono","Correo","N�mero de casa","Todos"
		      );
		scanf(" %hd",&s);

		if( s==1 || s==5 ){
			printf("Ingrese el nuevo nombre\n");
			scanf(" %50[^\n]", ap_cadena);
			#ifdef _WIN32
			reparar( ap_cadena );
			#endif //_WIN32
			strcpy( (ap_lista_contactos+posicion)->nombre , ap_cadena );
		}

		if( s==2 || s==5 ){
			printf("Ingrese el nuevo n�mero del contacto\n");
			scanf(" %10s", ap_cadena);
			for (i = 0; i < strlen( ap_cadena ); ++i) {
				if( *( ap_cadena + i ) < 48 || *( ap_cadena + i ) > 57 ){
					no_numero = 1;
				}
			}
			while( no_numero ){
				no_numero = 0;
				printf("Caracteres invalidos para un n�mero de telefono. Vuelva a teclear el n�mero\n");
				scanf(" %10s", ap_cadena);
				for (i = 0; i < strlen( ap_cadena ); ++i) {
					if( *( ap_cadena + i ) < 48 || *( ap_cadena + i ) > 57 ){
						no_numero = 1;
					}
				}
			}

			strcpy( (ap_lista_contactos+posicion)->numero , ap_cadena );
		}

		if( s==3 || s== 5 ){
			printf("Ingrese el nuevo correo del contacto\n");
			scanf(" %30s", ap_cadena);
			for( i = 0; i < strlen( ap_cadena ); ++i){
				if( *(ap_cadena + i) == 64 ){
					arroba = 1;
				}else if( *(ap_cadena + i) == 46 ){
					punto = 1;
				}else if( *(ap_cadena + i) > 128 ){
					ascii_ext = 1;
				}
			}
			while( !(arroba && punto) || ascii_ext ){
				arroba = punto = ascii_ext = 0;
				printf("Formato invalido para correo, favor de volver a escribirlo\n");
				scanf(" %30s", ap_cadena);
				for( i = 0; i < strlen( ap_cadena ); ++i){
					if( *(ap_cadena + i) == 64 ){
						arroba = 1;
					}else if( *(ap_cadena + i) == 46 ){
						punto = 1;
					}else if( *(ap_cadena + i) > 128 ){
						ascii_ext = 1;
					}
				}
			}

			strcpy( (ap_lista_contactos+posicion)->correo , ap_cadena );
		}

		if( s==4 || s==5 ){
			printf("Ingrese el nuevo n�mero de casa del contacto\n");
			scanf(" %3s", ap_cadena);
			for( i = 0; i < strlen( ap_cadena ); ++i ){
				if( *(ap_cadena + i) < 48 || *(ap_cadena + i) > 57 ){
					no_numero = 1;
				}
			}
			while( no_numero ){
				printf("Caracteres invalidos para un n�mero de casa. Vuelva a teclear el n�mero\n");
				scanf(" %3s", ap_cadena);
				for( i = 0; i < strlen( ap_cadena ); ++i ){
					if( *(ap_cadena + i) < 48 || *(ap_cadena + i) > 57 ){
						no_numero = 1;
					}
				}
			}

			strcpy( (ap_lista_contactos+posicion)->numcasa , ap_cadena );
		}

		printf("Contacto actualizado correctamente\n");
	}
}

//Codigo de la funci�n para guardar todos los datos en un archivo de texto
void escribirArchivo(FILE *ap_archivo, Contacto *ap_lista_contactos, int num_contactos){
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

// Codigo de la funci�n buscar (contacto)
int buscar(Contacto *ap_lista_contactos, unsigned char* ap_nombre){
	int c = 0; // contador para el ciclo
	int pos = -1; // Variable para guardar la posici�n del contacto

	while( c < MAX_CONTACTOS && (pos == -1) ){
		if( strcmp( (ap_lista_contactos+c)->nombre, ap_nombre) == 0 ){
			pos = c;
		}
		++c;
	}
	return pos;
}



// Codigo de la funci�n contar filas
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

// funci�n para leer los contactos del archivo
// para una descripcion detallada, vaya a la definici�n
int leerArchivo(FILE *ap_archivo, Contacto *ap_lista_contactos) {
	int num_contactos = 0, j = 0; // declaramos los contadores que usaremos
	ap_archivo = fopen (NOMBRE_ARCHIVO, "r+"); // abrimos el archivo en
     // modo lectura o creaci�n, para asegurarnos que exista
	if (ap_archivo == NULL) { // manejamos el caso en que no se pueda crear el archivo
		return 0; // Si el archivo no est� trabajaremos en blanco por lo que se
			  // devuelve 0 y los contactos se ir�n creando conforme al usuario
		//printf ("\nNo se pudo leer, ni crear el archivo D:\n\t");
		//printf ("Asegurate de tener permisos suficientes para leer o escribir aqu�\n");
		//exit(-1); // salimos indicando un error al sistema operativo
	}
	while (!feof(ap_archivo)) { // mientras no acabe el archivo
		fscanf(ap_archivo," %50[^\t]\t%10[^\t]\t%30[^\t]\t%3[^\n]\n", // este scanset toma
		 // los valores separados con tabuladores, y solo permite espacios en la
		 // cadena del nombre, explicado un poco m�s:
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
			ap_lista_contactos->numcasa); // y la cuarta aqu�
		num_contactos++; //aumentamos el contador de contactos
		ap_lista_contactos++; // y pasamos al siguiente elemento
	}
	for (j = 0; j < num_contactos; j++) {
		ap_lista_contactos--; // devolvemos el apuntador apuntando al primer elemento
	}
	fclose (ap_archivo); // limpiamos nuestra area de trabajo
	return num_contactos; // disminuimos y devolvemos el numero de contactos
}


void imprimirContactos(Contacto *ap_lista_contactos, int num_contactos){
	int n;

	printf("Los contactos guardados son:\n");
	for( n = 0; n < num_contactos; ++n ){
		printf("Nombre: %s\tNumero: %s\nCorreo: %s\t N�mero de casa: %s\n\n",
			(ap_lista_contactos + n)->nombre,
			(ap_lista_contactos + n)->numero,
			(ap_lista_contactos + n)->correo,
			(ap_lista_contactos + n)->numcasa
		);
	}
}

