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

#include "contacto.h"
#define MAX_CONTACTOS 10000 // El profe se va a aburrir antes de ingresar el maximo de contactos
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
	printf("\n\t¡¡Muchas gracias por usar nuestro servicio!!\n");
	printf("\tRegresa pronto :)");

	getchar();
	return 0;
}
