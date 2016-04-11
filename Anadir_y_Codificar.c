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
#define 	MAX_CONTACTOS 10 // Máximo número de contactos
#define   NOMBRE_ARCHIVO "misContactos.txt" // Se define el nombre del archivo como una cadena constante

// Declaración: presentacion : vacío -> vacío
// Próposito: Esta función imprime nuestra portada, no toma ni devuelve nada
// Ejemplo : presentacion(); debería imprimir
//           ##################################
//           #           Proyecto 3           #
//           ##################################
void presentacion(void);

// Declaración: menu : entero -> entero
// Próposito: Esta funcion recibe un entero (global) despliega el menú y asigna
//            al argumento la opción seleccionada por el usuario como un entero
// Ejemplo: Seleccione una opción:
//            1. Primer opción
//            2. Segunda opción
//            3. Tercer opción
// 					Elige una: 2
//   Debería devolver 2
void menu(int seleccion);


struct contacto // Definición de la estructura "contacto"
{
	//Datos de "contacto", todos alfanuméricos (cadenas) puesto que así son más faciles de manejar
};

typedef struct contacto Contacto; // Se define un alias para "struct contacto" que será "Contacto"

int leerArchivo(FILE *, Contacto *); // Prototipo de la función "leerArchivo"
void escribirArchivo(FILE *, Contacto *); // Prototipo de la función "escribirArchivo"
void codificar(Contacto *, int ); // Prototipo de la función "codificar"
void decodificar(Contacto *, int ); // Prototipo de la función "decodificar"
int agregarContacto(Contacto *,int); // Prototipo de la función "agregarContacto"
int borrarContacto(Contacto *,int); // Prototipo de la función "borrarContacto"
void actualizarContacto(Contacto *, int); // Prototipo de la función "actualizarContacto"

int main(int argc, char **argv){
	Contacto listaContactos[maxContactos]; // Se declara un arreglo de contactos con el tamaño definido en la variable maxContactos */
	int num_max_contactos, seleccion; // Se crea un contador de "Contactos"
	FILE * apuntador_ archivo; // apuntador a file para referenciar un archivo abierto

	// ### Parte 1: Mensajes iniciales ###

	presentacion();

	/*
	 * ### Parte 2: Leer los contactos existentes ###
	 * Como en esta sección solo se llama a la función, la persona a la que
	 * le toque esta parte solo tiene que construir el metodo de dicha función
	 * el cual se encuentra vacio actualmente
	 */
	numContactos = leerArchivo(aptdrArchivo,listaContactos);
	
	/* 
	* ### Parte 3: Decodificar los contactos ###
	* Como en esta sección solo se llama a la función, la persona a la que
	* le toque esta parte solo tiene que construir el metodo de dicha función
	* el cual se encuentra vacio actualmente
	*/
	decodificar(listaContactos,numContactos);
	
	/* 
	 * ### Parte 4: Menú ###
	 * Hay varias funciones que son llamadas en esta sección pero
	 * hacerlas no necesariamente es responsabilidad de la persona que crea
	 * el menú pues son acciones independientes
	 */

	do {
		menu(seleccion);
		switch (seleccion) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		default:
			printf ("Opción incorrecta, selecciona otra opción");
			seleccion = -1;
			break;
		}
	} while ( !seleccion );
	
	/* ### Parte 5: Mensaje de despedida ### */
	
	getchar();
	return 0;
}

// funcion de presentacion, para más informacion ir a la declaración
// imprime gatos, almohadillas o numerales, por los problemas con ascii en linux
// alguien usando windows deberia corregirlo
void presentacion () {
	printf ("###############################################");
	printf ("#   Universidad Nacional Aútonoma de México   #");
	printf ("#            Facultad de Ingeniería           #");
	printf ("#  Progamación avanzada y métodos numéricos   #");
	printf ("#                 Proyecto 1                  #");
	printf ("#          Cabrera López Oscar Emilio         #");
	printf ("#            Mendoza García Ulises            #");
	printf ("###############################################");
}

// funcion de presentacion, para más informacion ir a la declaración
void menu (int seleccion = 0) { // damos un valor inicial a seleccion
	printf ("\n\t\tBienvenido. \n\t Elige una opción:"); // peticion al usuario
	printf ("\n\t1. Añadir contacto: "); // primer opción
	printf ("\n\t2. Actualizar contactos"); // segunda opción
	printf ("\n\t3. Borrar contactos"); // tercer opción
	printf ("\n\t4. Salir\n"); // salida del programa
	scanf ("%d", seleccion); // asignamos una opcion a la sección
}



/* Codigo de la función leerArchivo */
int leerArchivo(FILE *archivo, Contacto *listaContactos){
	
}

/* Codigo de la función codificar */
void codificar(Contacto *listaContactos, int numContactos){
	
} 

/* Codigo de la función decodificar */
void decodificar(Contacto *listaContactos, int numContactos){
	
} 

/* Codigo de la función agregarContacto */
int agregarContacto(Contacto *listaContactos,int numContactos){
	
}

/* Codigo de la función borrarContacto */
int borrarContacto(Contacto *listaContactos,int numContactos){
	
}

/* Codigo de la función actualzarContacto */
void actualizarContacto(Contacto *listaContactos,int numContactos){
	
}

