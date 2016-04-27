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
#define MAX_NOMBRE 50  // definimos las longitudes máximas
#define MAX_NUMERO 10  // del nombre, número de telefono,
#define MAX_CORREO 30  // correo electronico,
#define MAX_NUMCASA 3  // y numero de casa
#define NOMBRE_ARCHIVO "misContactos.txt" // Se define el nombre del archivo como una cadena constante
#ifdef _WIN32
	#define CLEAR "cls"
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


/* void codificar(Contacto *, int ); // Prototipo de la función "codificar"
 * void escribirArchivo(FILE *, Contacto *); // Prototipo de la función "escribirArchivo"
 */
 

/*
 * Declaración: decodificar : Contactos, entero -> vacío
 * Propósito: Esta función toma como argumentos un apuntador a un arreglo de
 * Contactos, y para cada uno de los datos que contiene esta estructura, resta 3
 * al cada caracter
 */
void decodificar(Contacto *ap_lista_contactos, int num_contactos); // Prototipo de la función "decodificar"
/*int agregarContacto(Contacto *,int); // Prototipo de la función "agregarContacto"
int borrarContacto(Contacto *,int); // Prototipo de la función "borrarContacto"
void actualizarContacto(Contacto *, int); // Prototipo de la función "actualizarContacto" */


int main (int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	int num_contactos = 0, seleccion = 0; // Se crea un contador de "Contactos"
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
	numContactos = leerArchivo(aptdrArchivo,listaContactos);
	decodificar (ap_lista_contactos, num_contactos);

	do {
		seleccion = menu();
		switch (seleccion) {
		case 1:
			printf ("Seleccionaste la opción 1\n");
			break;
		case 2:
			printf ("Seleccionaste la opción 2\n");
			break;
		case 3:
			printf ("Seleccionaste la opción 3\n");
			break;
		case 4:
			printf ("Seleccionaste salir\n");
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
		printf ("\nNo se pudo leer, ni crear el archivo D:\n\t");
		printf ("Asegurate de tener permisos suficientes para leer o escribir aquí\n");
		exit(-1); // salimos indicando un error al sistema operativo
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
// void codificar(Contacto *listaContactos, int numContactos){

// }

/* Codigo de la función decodificar */
void decodificar(Contacto *ap_lista_contactos, int num_contactos){
	int i, j;
	unsigned char *apu;
	for (i = 0; i < num_contactos; i++) {
		apu = ap_lista_contactos->nombre;
		for (j = 0; j < strlen (ap_lista_contactos->nombre); j++) {
			*apu -= 3;
			apu++;
		}
		apu = ap_lista_contactos->numero;
		for (j = 0; j < strlen (ap_lista_contactos->numero); j++) {
			*apu -= 3;
			apu++;
		}
		apu = ap_lista_contactos->correo;
		for (j = 0; j < strlen (ap_lista_contactos->correo); j++) {
			*apu -= 3;
			apu++;
		}
		ap_lista_contactos ++;
	}
	apu = NULL;
}

/* Codigo de la función agregarContacto */
// int agregarContacto(Contacto *listaContactos,int numContactos){

// }

/* Codigo de la función borrarContacto */
// int borrarContacto(Contacto *listaContactos,int numContactos){

// }

/* Codigo de la función actualzarContacto */
// void actualizarContacto(Contacto *listaContactos,int numContactos){

// }
