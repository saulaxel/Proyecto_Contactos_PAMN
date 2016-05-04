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
 * DÍAZ ALFÉREZ MELISA
 * MENDOZA GARCÍA ULISES
 * MARTÍNEZ ORTIZ SAÚL AXEL
 * SÁNCHEZ DÍAZ OMAR DIEGO
 */

#include <stdio.h> // Biblioteca estándar para la entrada y salida
#include <stdlib.h>
#include <locale.h>
#include "contacto.h"

#define MAX_CONTACTOS 100
#define MAX_NOMBRE 50  // definimos las longitudes máximas
#define MAX_NUMERO 10  // del nombre, número de telefono,
#define MAX_CORREO 30  // correo electronico,
#define MAX_NUMCASA 8  // y numero de casa
#define NOMBRE_ARCHIVO "misContactos.txt" // Se define el nombre del archivo como una cadena constante

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int main (int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	int num_contactos = 0; // Se crea un contador de "Contactos"
	Contacto *ap_lista_contactos; // apuntador a la lista de contactos
	FILE *ap_archivo = NULL; // apuntador a file para referenciar un archivo
	// abierto, lo iniciamos en NULL por seguridad
	int i;
	// ### Parte 1: Mensajes iniciales ###
	presentacion ();
	getchar ();
#ifdef _WIN32
	validarUsuario ();
#endif //_WIN32

	/*
	 * ### Parte 2: Pedir contactos al usuario ###
	 * Se pregunta al usuario cuantos contactos desea guardar y se le pide dicha
	 * cantidad de veces datos para los contactos
	 */
	printf ("¿Cuántos contactos desea guardar?\n");
	scanf ("%d", &num_contactos);
	ap_lista_contactos = crearArreglo(num_contactos);
	for (i = 0; i < num_contactos; ++i) {
		printf ("Para el contacto %d\n", i + 1);
		agregarContacto (ap_lista_contactos, i);
		putchar ('\n');
	}

	/* ### Parte3: Guardar contactos en archivo ### */
	codificar (ap_lista_contactos, num_contactos);
	escribirArchivo (ap_archivo, ap_lista_contactos, num_contactos);

	/* ### Parte 4: Mensaje de despedida ### */
	printf ("\n\t¡¡Muchas gracias por usar nuestro servicio!!\n");
	printf ("\tRegresa pronto :)");

	return 0;
}
