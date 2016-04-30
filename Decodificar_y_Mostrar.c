/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * "Sistema de seguridad para contactos"
 * Parte 2: Decodificar contactos y mostrarlos en consola
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
	presentacion();
	getchar();
	#ifdef _WIN32
	validarUsuario();
	#endif //_WIN32
	
	/* ### Parte 2: Leer y decodificar ### */
	num_contactos = leerArchivo(ap_archivo,ap_lista_contactos);
	decodificar(ap_lista_contactos,num_contactos);
	
	/* ### Parte 3: Impresión con formato ### */
	imprimirContactos(ap_lista_contactos,num_contactos);
	
	/* ### Parte 4: Mensaje de despedida ### */
	  /* Aquí va el mismo mensaje de despedida que en el primer programa*/
	getchar();
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

// Codigo de la función contar filas
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
	return num_contactos; // disminuimos y devolvemos el numero de contactos
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
