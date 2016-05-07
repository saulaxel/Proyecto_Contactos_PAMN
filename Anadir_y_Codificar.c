/*
 * Primer Proyecto Programación Avanzada y metodos numéricos
 * "Sistema de seguridad para contactos"
 * Parte 1: Añadir contactos codificados a documento de texto
 * Integrantes del equipo:
 * SIERRA GONZÁLEZ HÉCTOR ALEJANDRO
 * CABRERA LÓPEZ OSCAR EMILIO
 * DÍAZ ALFÉREZ MELISA
 * MENDOZA GARCÍA ULISES
 * MARTÍNEZ ORTIZ SAÚL AXEL
 * SÁNCHEZ DÍAZ OMAR DIEGO
 */

#include "contacto.h" // Biblioteca con todas las declaraciones necesarias para que funcione el proyecto 

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
	getchar();
	#ifdef _WIN32
	validarUsuario();
	#endif //_WIN32

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
	despedida();

	return 0;
}


// funcion de presentacion, para más informacion ir a la declaración
int menu (void) { // damos un valor inicial a seleccion
	int seleccion;
	printf ("\n\t\tBienvenido. \n\t Elige una opción:"); // peticion al usuario
	printf ("\n\t1. Añadir contacto "); // primer opción
	printf ("\n\t2. Actualizar contacto"); // segunda opción
	printf ("\n\t3. Borrar contactos"); // tercer opción
	printf ("\n\t4. Salir\n"); // salida del programa
	scanf ("%d", &seleccion); // asignamos una opcion a la sección
	return seleccion;
}

/* Codigo de la función borrarContacto */
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

/* Codigo de la función actualzarContacto */
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
		unsigned short s; // Entero que guarda la selección del usuario
		unsigned short i; // Entero contador
		unsigned short no_numero = 0, arroba = 0, punto = 0, ascii_ext = 0; // Enteros usados como banderas booleana
		printf("Indique el dato del contacto que desea actualizar:\n");
		printf("\t1. %s\n\t2. %s\n\t3. %s\n\t4. %s\n\t5. %s\n\n",
			"Nombre","Telefono","Correo","Número de casa","Todos"
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
			printf("Ingrese el nuevo número del contacto\n");
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

		printf("Contacto actualizado correctamente\n");
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
