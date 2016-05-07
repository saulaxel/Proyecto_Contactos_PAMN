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
	
	/* ### Parte 0: Se crea el arreglo dinámico para su uso posterior ###*/
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
	despedida();

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
