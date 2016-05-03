#ifndef CONTRASENA_H_INCLUDED
#define CONTRASENA_H_INCLUDED
/* Biblioteca exclusiva para su uso en el proyecto de Programación
* avanzada y metodos numéricos, la cual esta sujeta a las especificaciones
* de este
*/

#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32

#include <conio.h>

#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define DEBUG 0
#define ESTANDAR 0
#define tamDatos 17
#define archivo_CuentaUsuario ".superSecreto.secret"
#define limpiar(x) for(i=0;i<tamDatos;++i) { x[i]=0; }

enum booleano {
	falso, verdadero
};
typedef enum booleano Booleano;

void validarUsuario (void);

void establecerLocale (void);

/* Prototipo de la función establecerIdioma */
void contrasenaDeSeguridad (FILE *, unsigned char *, unsigned char *);

/* Prototipo de la función contrasenaDeSeguridad */
Booleano comprobarContrasena (FILE *, unsigned char *, unsigned char *);

/* Prototipo de la función comprobarContrasena */
void pedirContrasena (FILE *, unsigned char *, unsigned char *);

/* Prototipo de la función pedirContrasena */
void reparar (unsigned char *cadena);

unsigned char usuario[tamDatos], contrasena[tamDatos];
FILE *datosUsuario;
int i;

#if DEBUG /* DEBUG 1*/
int main(int argc, char *argv[]) {

	establecerLocale();
	validarUsuario();

	return 0;
}
#endif /* fin DEBUG 1*/

void validarUsuario () {
	contrasenaDeSeguridad (datosUsuario, usuario, contrasena);
}

void establecerLocale () {
#if ESTANDAR
	setlocale(LC_ALL,"");
#else
	setlocale (LC_ALL, "Spanish_Mexico");
#endif
}

void contrasenaDeSeguridad (FILE *archivo, unsigned char *user, unsigned char *pswrd) {
	archivo = fopen (archivo_CuentaUsuario, "r");

	if (archivo == NULL) {
		printf ("%s%s%s%s%s%s",
		        "Parace que usted es un nuevo usuario \n",
		        "Este sistema de seguridad para contactos \n",
		        "lo identificará a usted con una cuenta y una \n",
		        "contraseña estandares\n",
		        "(hasta 16 caracteres cada una)\n\n",
		        "A continuación deberá ingresar una cuenta y contraseña nuevas\n"
		);
		getchar ();

		pedirContrasena (archivo, user, pswrd);

		archivo = fopen (archivo_CuentaUsuario, "w");
		fprintf (archivo, "%s\t%s", user, pswrd);
		fclose (archivo);

		printf ("\n%s%s\n",
		        "¡¡¡Felicidades!!!",
		        "tus contactos estarán seguros a partir de ahora"
		);
		printf ("Esperamos que tu experiencia con la aplicación sea grata\n\n");
		getchar ();
	} else {
		if (comprobarContrasena (archivo, user, pswrd) == verdadero) {
			fclose (archivo);
			printf ("\nBienvenido de vuelta %s\n\n", user);
			getchar ();
		} else {
			system (CLEAR);
			printf ("\n%s\n\n\n",
			        "¡¡¡Cuenta de usuario o contraseña incorrecta!!!");
			printf ("\t\tEl programa se cerrará\n");
			getchar ();
			exit (0);
		}
	}
}

Booleano comprobarContrasena (FILE *archivo, unsigned char *user, unsigned char *pswrd) {
	unsigned char usuarioReal[tamDatos], contrasenaReal[tamDatos];
	int i; /* Variable contadora */
	limpiar(usuarioReal)
	limpiar(contrasenaReal)

	fscanf (archivo, " %s", usuarioReal);
	fscanf (archivo, " %s", contrasenaReal);
#if DEBUG /* DEBUG 2*/
	printf("\nLos datos de usuario son: %s %s\n",usuarioReal,contrasenaReal);
	getchar();
#endif /* Fin DEBUG 2*/
	pedirContrasena (archivo, user, pswrd);

#if DEBUG /* DEBUG 3*/
	printf("%s=%s\n",user,usuarioReal);
	for(i=0;i<tamDatos;++i){
		printf("%d ",user[i]-usuarioReal[i]);
	}
	putchar('\n');
	printf("%s=%s\n",contrasenaReal,pswrd);
	for(i=0;i<tamDatos;++i){
		printf("%d ",pswrd[i]-contrasenaReal[i]);
	}
	putchar('\n');
	getchar();
#endif /* Fin del DEBUG 3*/

	for (i = 0; i < tamDatos - 1; ++i) {
		if ((usuarioReal[i] != user[i]) || (contrasenaReal[i] != pswrd[i])) {
			return falso;
		}
	}

	return verdadero;
}

void pedirContrasena (FILE *archivo, unsigned char *user, unsigned char *pswrd) {
	unsigned char c = 100;
	short m = 0, n; /* Dos variables contadoras que se usan para pedir datos */

	limpiar(usuario)
	limpiar(contrasena)

	system (CLEAR);

	printf ("Por favor ingrese su cuenta de usuario:\n");
	scanf (" %s", usuario);

	system (CLEAR);

	printf ("Por favor ingrese su contraseña");
#if  WINDOWS
	printf(":\n");
#else
	printf (" letra por letra:\n");
#endif

	getchar ();

#if  WINDOWS
	c = getch();
#else
	c = getchar ();
	getchar ();
#endif

	while (c != '\n' && c != '\t' && c != ' ' && c != '\r' && m < tamDatos - 1) {
#if ESTANDAR
		if ( c > 127 ){
			do{
				printf("\nCaracter invalido, remplacelo por otro:\n");
#if WINDOWS
				c = getch();
#else
				c = getchar();
				getchar();
#endif
			}while ( c > 127 );
		}
#endif /* Fin ESTANDAR */

		system (CLEAR);

		if (c != 127 && c != 8) {
			contrasena[m] = c;
			++m;
		} else {
			--m;
		}

		printf ("Por favor ingrese su contraseña");
#if  WINDOWS
		printf(":\n");
#else
		printf (" letra por letra:\n");
#endif
		for (n = 1; n <= m; ++n) {
			putchar ('*');
		}

#if WINDOWS
		c = getch();
#else
		c = getchar ();

#endif

	}
	contrasena[m] = '\0';

	reparar (usuario);
	reparar (contrasena);

#if DEBUG
	printf("\n%s %s\n",usuario,contrasena);
	getchar();
#endif /* DEBUG */
}


void reparar (unsigned char *cadena) {
	short n;
	unsigned char a[128];
	a[0] = 'Ç';
	a[1] = 'ü';
	a[2] = 'é';
	a[3] = 'â';
	a[4] = 'ä';
	a[5] = 'à';
	a[6] = 'å';
	a[7] = 'ç';
	a[8] = 'ê';
	a[9] = 'ë';
	a[10] = 'è';
	a[11] = 'ï';
	a[12] = 'î';
	a[13] = 'ì';
	a[14] = 'Ä';
	a[15] = 'Å';
	a[16] = 'É';
	a[17] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[18] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[19] = 'ô';
	a[20] = 'ö';
	a[21] = 'ò';
	a[22] = 'û';
	a[23] = 'ù';
	a[24] = 'ÿ';
	a[25] = 'Ö';
	a[26] = 'Ü';
	a[27] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[28] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[29] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[30] = '×';
	a[31] = 'ƒ';
	a[32] = 'á';
	a[33] = 'í';
	a[34] = 'ó';
	a[35] = 'ú';
	a[36] = 'ñ';
	a[37] = 'Ñ';
	a[38] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[39] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[40] = '¿';
	a[41] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[42] = '¬';
	a[43] = '½';
	a[44] = '¼';
	a[45] = '¡';
	a[46] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[47] = 'Á';
	a[48] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[49] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[50] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[51] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[52] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[53] = 'Á';
	a[54] = 'Â';
	a[55] = 'À';
	a[56] = '©';
	a[57] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[58] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[59] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[60] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[61] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[62] = '¥';
	a[63] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[64] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[65] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[66] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[67] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[68] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[69] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[70] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[71] = 'Ã';
	a[72] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[73] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[74] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[75] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[76] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[77] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[78] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[79] = '¤';
	a[80] = 'ð';
	a[81] = 'Ð';
	a[82] = 'Ê';
	a[83] = 'Ë';
	a[84] = 'È';
	a[85] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[86] = 'Í';
	a[87] = 'Î';
	a[88] = 'Ï';
	a[89] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[90] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[91] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[92] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[93] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[94] = 'Ì';
	a[95] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[96] = 'Ó';
	a[97] = 'ß';
	a[98] = 'Ô';
	a[99] = 'Ò';
	a[100] = 'õ';
	a[101] = 'Õ';
	a[102] = 'µ';
	a[103] = 'þ';
	a[104] = 'Þ';
	a[105] = 'Ú';
	a[106] = 'Û';
	a[107] = 'Ù';
	a[108] = 'ý';
	a[109] = 'Ý';
	a[110] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[111] = '´';
	a[112] = '­';
	a[113] = '±';
	a[114] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[115] = '¾';
	a[116] = '¶';
	a[117] = '§';
	a[118] = '÷';
	a[119] = '¸';
	a[120] = '°';
	a[121] = '¨';
	a[122] = '·';
	a[123] = '¹';
	a[124] = '³';
	a[125] = '²';
	a[126] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */
	a[127] = 'a'; /* Caracter no valido para contraseñas en este proyecto, se remplaza por a */

	for (n = 0; (cadena[n] || n < tamDatos - 1); ++n) {
		if (cadena[n] >= 128) {
			cadena[n] = a[cadena[n] - 128];
		}
	}
}


#endif // CONTRASENA_H_INCLUDED
