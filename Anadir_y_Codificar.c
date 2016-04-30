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
#define MAX_CONTACTOS 10 // Solo para pruebas volvi a declarar un arreglo estatico al inicio
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
 * Declaración: menu : vacío -> entero
 * Próposito: Esta funcion despliega el menú y devuelve la opción seleccionada
 * por el usuario como un entero.
 * Ejemplo: Seleccione una opción:
 *	1. Primer opción
 *	2. Segunda opción
 *	3. Tercer opción
 *	Elige una: 2
 *  Debería devolver 2
 */
int menu (void);

/* Declaración: leerArchivo : Archivo, Contactos -> numero
 * Próposito: Esta función toma como parámetros un apuntador a un archivo y un
 * apuntador a un arreglo estructuras de contacto, lee los contactos almacenados
 * en el archivo y almacena cada uno en una estructura Contacto, al terminar
 * devuelve el número de contactosque leyo exitosamente-
 * Ejemplo: Con un archivo almacenando 10 contactos
 *	leerArchivo(ap_archivo, Contactos)
 * deberia devolver 10 y rellenar 10 elementos del arreglo
 */
int leerArchivo (FILE *ap_archivo, Contacto *ap_lista_contactos);

/*
 * Declaración: codificar : Contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * Contactos y un entero que indica el número de los mismos, para despues recorrer
 * cada uno de los datos de los mismos sumandole 3 al codigo de sus caracteres
 */
void codificar(Contacto *, int );

/*
 * Declaración: decodificar : Contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * Contactos, y para cada uno de los datos que contiene esta estructura, resta 3
 * al cada caracter
 */
void decodificar(Contacto *ap_lista_contactos, int num_contactos); 

/*
 * Declaración: agregarContacto : Contactos, entero -> int
 * Propósito: Función que toma por argumentos el arreglo de contactos
 * y el número de contactos para añadir datos de un nuevo contacto al 
 * final del arreglo y devuelve 1 en caso de realizar la tarea con éxito
 * o 0 en caso contrario
 */
int agregarContacto(Contacto *,int);

/*
 * Declaración: borrarContacto : Contactos, entero -> int
 * Propósito: Función que toma por argumentos el arreglo de contactos
 * y el número de contactos para borrar los datos de un contacto 
 * del arreglo y devuelve 1 en caso de realizar la tarea con éxito
 * o 0 en caso contrario
 */
int borrarContacto(Contacto *,int); // Prototipo de la función "borrarContacto"

/*
 * Declaración: actualizarContacto : Contactos, entero -> vacio
 * Propósito: Función que toma por argumentos el arreglo de contactos
 * y el número de contactos para buscar un contacto elegido por el usuario 
 * y modificar sus datos
 */
void actualizarContacto(Contacto *, int); // Prototipo de la función "actualizarContacto" */

/*
 * Declaración: escribirArchivo: Archivo, Contacto , int -> vacio
 * Proposito: Función que toma por argumentos un apuntador a archivo y 
 * un arreglo de contactos que usará para abrir un archivo de texto
 * y guardar en el datos de un número entero de estructuras "Contacto"
 */
void escribirArchivo(FILE *, Contacto *, int); // Prototipo de la función "escribirArchivo"

/* 
 * Declaración: buscar : Contacto, cadena -> entero
 * Propósito: Función que toma por argumentos el arreglo de contactos
 * y una cadena que buscara entre los datos "nombre" del arreglo de 
 * contactos para devolver la posicón de dicho nombre en el arreglo 
 * (en caso de encontrarlo) o devolver -1 si no se encuentra.
 */
int buscar(Contacto * ,unsigned char *);

int main (int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	int num_contactos = 0, seleccion = 0; // Se crea un contador de "Contactos"
	Contacto arr_lista_contactos[MAX_CONTACTOS];
	Contacto *ap_lista_contactos = arr_lista_contactos; // apuntador a la lista de contactos
	FILE *ap_archivo = NULL; // apuntador a file para referenciar un archivo
	                         // abierto, lo iniciamos en NULL por seguridad

	// ### Parte 1: Mensajes iniciales ###
	presentacion();
	
	/* 
	 * ### Parte 2: Leer los contactos existentes ### 
	 * Como en esta sección solo se llama a la función, la persona a la que
	 * le toque esta parte solo tiene que construir el metodo de dicha función
	 * el cual se encuentra vacio actualmente
	 */
	num_contactos = leerArchivo(ap_archivo,ap_lista_contactos);
	
	/* 
	* ### Parte 3: Decodificar los contactos ### 
	* Como en esta sección solo se llama a la función, la persona a la que
	* le toque esta parte solo tiene que construir el metodo de dicha función
	* el cual se encuentra vacio actualmente
	*/
	decodificar (ap_lista_contactos, num_contactos);

	/* 
	 * ### Parte 4: Menú ###
	 * Hay varias funciones que son llamadas en esta sección pero
	 * hacerlas no necesariamente es responsabilidad de la persona que crea
	 * el menú pues son acciones independientes
	 */
	do {
		seleccion = menu();
		switch (seleccion) {
		case 1:
			printf ("Seleccionaste la opción 1\n");
			num_contactos += agregarContacto(ap_lista_contactos, num_contactos);
			break;
		case 2:
			printf ("Seleccionaste la opción 2\n");
			actualizarContacto(ap_lista_contactos, num_contactos);
			break;
		case 3:
			printf ("Seleccionaste la opción 3\n");
			num_contactos -= borrarContacto(ap_lista_contactos, num_contactos);
			break;
		case 4:
			printf ("Seleccionaste salir\n");
			codificar(ap_lista_contactos, num_contactos);
			escribirArchivo(ap_archivo, ap_lista_contactos, num_contactos);
			seleccion = 0;
			break;
		default:
			printf ("Opción incorrecta, selecciona otra opción\n");
			seleccion = -1;
		}
		printf ("\nPresiona ENTER para continuar\n");
		getchar ();getchar ();
		system (CLEAR);
	} while ( seleccion );

	/* ### Parte 5: Mensaje de despedida ### */
	return 0;
}

// funcion de presentacion, para más informacion ir a la declaración
// imprime gatos, almohadillas o numerales, por los problemas con ascii en linux
// alguien usando windows deberia corregirlo
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

// funcion de presentacion, para más informacion ir a la declaración
int menu (void) { // damos un valor inicial a seleccion
	int seleccion;
	printf ("\n\t\tBienvenido. \n\t Elige una opción:"); // peticion al usuario
	printf ("\n\t1. Añadir contacto: "); // primer opción
	printf ("\n\t2. Actualizar contactos"); // segunda opción
	printf ("\n\t3. Borrar contactos"); // tercer opción
	printf ("\n\t4. Salir\n"); // salida del programa
	scanf ("%d", &seleccion); // asignamos una opcion a la sección
	return seleccion;
}



// función para leer los contactos del archivo
// para una descripcion detallada, vaya a la definición
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
	return --num_contactos; // disminuimos y devolvemos el numero de contactos
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

/* Codigo de la función decodificar */
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
		printf("Número de contactos maximo excedido\n");
		return 0;	
	}
}

/* Codigo de la función borrarContacto */
int borrarContacto(Contacto *ap_lista_contactos, int num_contactos){
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

/* Codigo de la función actualzarContacto */
void actualizarContacto(Contacto *ap_lista_contactos, int num_contactos){
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
		unsigned short s; // Entero que guarda la selección del usuario
		unsigned short i; // Entero contador
		unsigned short no_numero = 0, arroba = 0, punto = 0, ascii_ext = 0; // Enteros usados como banderas booleana
		printf("Indique el dato del contacto que desea actualizar:\n");
		printf("\t1. %s\n\t2. %s\n\t3. %s\n\t4. %s\n\t5. %s\n\n",
			"Nombre","Telefono","Correo","Número de casa","Todos"
		      );
		scanf(" %hd",&s);
		
		if( s==1 || s==5 ){
			printf("Ingrese el nuevo nombre");
			scanf(" %50[^\n]", ap_cadena);
			#ifdef _WIN32
			reparar( ap_cadena );
			#endif //_WIN32
			strcpy( (ap_lista_contactos+posicion)->nombre , ap_cadena );
		}
		
		if( s==2 || s==5 ){
			printf("Ingrese el nuevo número del contacto");
			scanf(" %10s", ap_cadena);
			for (i = 0; i < strlen( ap_cadena ); ++i) {
				if( *( ap_cadena + i ) < 48 || *( ap_cadena + i ) > 57 ){
					no_numero = 1;
				}
			}
			while( no_numero ){
				no_numero = 0;
				printf("Caracteres invalidos para un número de telefono. Vuelva a teclear el número\n");
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
			printf("Ingrese el nuevo número de casa del contacto\n");
			scanf(" %3s", ap_cadena);
			for( i = 0; i < strlen( ap_cadena ); ++i ){
				if( *(ap_cadena + i) < 48 || *(ap_cadena + i) > 57 ){
					no_numero = 1;
				}
			}
			while( no_numero ){
				printf("Caracteres invalidos para un número de casa. Vuelva a teclear el número\n");
				scanf(" %3s", ap_cadena);
				for( i = 0; i < strlen( ap_cadena ); ++i ){
					if( *(ap_cadena + i) < 48 || *(ap_cadena + i) > 57 ){
						no_numero = 1;
					}
				}
			}
			
			strcpy( (ap_lista_contactos+posicion)->numcasa , ap_cadena );
		}
		
		printf("Contacto sacado correctamente\n");
	}
}

//Codigo de la función para guardar todos los datos en un archivo de texto
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

// Codigo de la función buscar (contacto)
int buscar(Contacto *ap_lista_contactos, unsigned char* ap_nombre){
	int c = 0; // contador para el ciclo
	int pos = -1; // Variable para guardar la posición del contacto
	
	while( c < MAX_CONTACTOS && (pos == -1) ){
		if( strcmp( (ap_lista_contactos+c)->nombre, ap_nombre) == 0 ){
			pos = c;
		}
		++c;
	}
	return pos;
}
