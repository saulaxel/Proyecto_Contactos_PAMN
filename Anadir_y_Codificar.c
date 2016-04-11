/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * 			"Sistema de seguridad para contactos"
 * Parte 1: Añadir contactos codificados a documento de texto
 * Integrantes del equipo:
 * SIERRA GONZÁLEZ HÉCTOR ALEJANDRO
 * CABRERA LÓPEZ OSCAR EMILIO
 * MENDOZA GARCÍA ULISES
 *
 *
 */

#include <stdio.h> // Biblioteca estándar para la entrada y salida
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTOS 10 // Máximo número de contactos
#define	NOMBRE_ARCHIVO "misContactos.txt" // Se define el nombre del archivo como una cadena constante
#ifdef _WIN32
	#define CLEAR "cls"
	#ifdef _WIN64
		#define CLEAR "cls"
	#endif
#else
	#define CLEAR "clear"
#endif


struct contacto // Definición de la estructura "contacto"
{
	char nombre[50];
	char numero[10];
	char correo[30];
};


typedef struct contacto Contacto; // Se define un alias para "struct contacto" que será "Contacto"
/* Declaración: presentacion : vacío -> vacío
 * Próposito: Esta función imprime nuestra portada, no toma ni devuelve nada
 * Ejemplo : presentacion();
 * 	debería imprimir
 *           ##################################
 *           #           Proyecto 3           #
 *           ##################################
 */
void presentacion (void);

/*
 * Declaración: menu : vacío -> entero
 * Próposito: Esta funcion despliega el menú y devuelve la opción seleccionada
 * por el usuario como un entero.
 * Ejemplo: Seleccione una opción:
 *            1. Primer opción
 *            2. Segunda opción
 *            3. Tercer opción
 * 					Elige una: 2
 *   Debería devolver 2
 */
int menu (void);


/* Declaración: leerArchivo : Archivo Contacto -> numero de contactos leídos
 * Próposito: Esta función toma como parámetros un apuntador a un archivo y un
 * apuntador a un arreglo estructuras de contacto., Lee los contactos almacenados
 * en el archivo y almacena cada uno en una estructura Contacto, al terminar
 * devuelve el número de contactosque leyo exitosamente-
 * Ejemplo: Con un archivo almacenando 10 contactos
 * 	leerArchivo(ap_archivo, Contactos)
 * deberia devolver 10 y rellenar 10 elementos del arreglo
 */
int leerArchivo (FILE *ap_archivo, Contacto *ap_lista_contactos);

/*void escribirArchivo(FILE *, Contacto *); // Prototipo de la función "escribirArchivo"
void codificar(Contacto *, int ); // Prototipo de la función "codificar"
void decodificar(Contacto *, int ); // Prototipo de la función "decodificar"
int agregarContacto(Contacto *,int); // Prototipo de la función "agregarContacto"
int borrarContacto(Contacto *,int); // Prototipo de la función "borrarContacto"
void actualizarContacto(Contacto *, int); // Prototipo de la función "actualizarContacto" */

int main (int argc, char *argv[]) {
	Contacto arr_lista_contactos[MAX_CONTACTOS]; // Se declara un arreglo de
																							 // contactos con el tamaño
																							 // definido en la constante
																							 // MAX_CONTACTOS
	int num_contactos = 0, seleccion = 0; // Se crea un contador de "Contactos"
	Contacto *ap_lista_contactos = arr_lista_contactos; // apuntador a la lista de contactos
	FILE *ap_archivo = NULL; // apuntador a file para referenciar un archivo
													 // abierto, lo iniciamos en NULL por seguridad

	// ### Parte 1: Mensajes iniciales ###

	presentacion();

  /* Parte 2: Leer los contactos existentes ###
	 * Como en esta sección solo se llama a la función, la persona a la que
	 * le toque esta parte solo tiene que construir el metodo de dicha función
	 * el cual se encuentra vacio actualmente
	 */
	//num_contactos = leerArchivo(ap_archivo, ap_lista_contactos);
	
	/* 
	* ### Parte 3: Decodificar los contactos ###
	* Como en esta sección solo se llama a la función, la persona a la que
	* le toque esta parte solo tiene que construir el metodo de dicha función
	* el cual se encuentra vacio actualmente
	*/
	//decodificar(listaContactos,numContactos);
	
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
			printf ("Seleccionaste la opción 1");
			break;
		case 2:
			printf ("Seleccionaste la opción 2");
			break;
		case 3:
			printf ("Seleccionaste la opción 3");
			break;
		case 4:
			printf ("Seleccionaste salir");
			seleccion = 0;
			break;
		default:
			printf ("Opción incorrecta, selecciona otra opción\n");
			printf ("\nPresiona ENTER para continuar\n");
			getchar ();getchar ();
			seleccion = -1;
		}
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
	printf ("#  Progamación avanzada y métodos numéricos   #\n");
	printf ("#                 Proyecto 1                  #\n");
	printf ("#          Cabrera López Oscar Emilio         #\n");
	printf ("#            Mendoza García Ulises            #\n");
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
int leerArchivo(FILE *ap_archivo, Contacto *ap_lista_contactos){
	int i = 1;
	ap_archivo = fopen (NOMBRE_ARCHIVO, "r+"); // abrimos el archivo en
		// modo lectura o creación, para asegurarnos que exista, nombre provisional
	if (ap_archivo = NULL) {
		printf ("\nNo se pudo leer, ni crear el archivo D:\n\t");
		printf ("Aegurate de tener permisos suficientes para leer o escribir aquí");
		exit(-1);
	}
	while ( i ) {
		fscanf (ap_archivo, "" , &(*(ap_lista_contactos + i)->nombre));
		i++;
	}
	return (i - 1);
}


/* Codigo de la función codificar */
// void codificar(Contacto *listaContactos, int numContactos){

// }

/* Codigo de la función decodificar */
// void decodificar(Contacto *listaContactos, int numContactos){

// }

/* Codigo de la función agregarContacto */
// int agregarContacto(Contacto *listaContactos,int numContactos){
	
// }

/* Codigo de la función borrarContacto */
// int borrarContacto(Contacto *listaContactos,int numContactos){
	
// }

/* Codigo de la función actualzarContacto */
// void actualizarContacto(Contacto *listaContactos,int numContactos){
	
// }
