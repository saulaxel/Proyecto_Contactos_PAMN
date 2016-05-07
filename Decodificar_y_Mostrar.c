/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * "Sistema de seguridad para contactos"
 * Parte 2: Decodificar contactos y mostrarlos en consola
 * Integrantes del equipo:
 * SIERRA GONZÁLEZ HÉCTOR ALEJANDRO
 * CABRERA LÓPEZ OSCAR EMILIO
 * DÍAZ ALFÉREZ MELISA
 * MENDOZA GARCÍA ULISES
 * MARTÍNEZ ORTIZ SAÚL AXEL
 * SÁNCHEZ DÍAZ OMAR DIEGO
 */

#include "contacto.h"

#define MAX_CONTACTOS 100 // El profe se va a aburrir antes de ingresar el maximo de contactos
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

/*
 * Declaración: contarFilas: Archivo -> entero
 * Proposito: Función que abre el archivo de los contactos codificados
 * y lo recorre completamente contando el número de filas que este
 * contiene
 */
int contarFilas(FILE*);

int main (int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	Contacto *ap_lista_contactos;
	int num_contactos; // Contador de "Contactos"
	FILE *ap_archivo = NULL; /* apuntador a file para referenciar un archivo abierto */

	ap_lista_contactos = crearArreglo (contarFilas (ap_archivo));
	/* ### Parte 1: Mensajes iniciales ### */
	presentacion ();
	getchar ();
#ifdef _WIN32
	validarUsuario ();
#endif //_WIN32

	/* ### Parte 2: Leer y decodificar ### */
	num_contactos = leerArchivo (ap_archivo, ap_lista_contactos);
	decodificar (ap_lista_contactos, num_contactos);

	/* ### Parte 3: Impresión con formato ### */
	imprimirContactos (ap_lista_contactos, num_contactos);

	/* ### Parte 4: Mensaje de despedida ### */
	printf ("\n\t¡¡Muchas gracias por usar nuestro servicio!!\n");
	printf ("\tRegresa pronto :)");

	getchar ();
	return 0;
}

// Codigo de la función contar filas
int contarFilas (FILE *ap_archivo) {
	int contador = 0;
	unsigned char cadena[MAX_NOMBRE + MAX_CORREO + MAX_NUMERO + MAX_NUMCASA + 5];
	unsigned char *ap_cadena = cadena;

	ap_archivo = fopen (NOMBRE_ARCHIVO, "r");

	if (ap_archivo != NULL) {
		while (!feof (ap_archivo)) {
			fscanf (ap_archivo, "%[^\n]\n", ap_cadena);
			++contador;
		}
	}
	fclose (ap_archivo);
	return contador;
}
