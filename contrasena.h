#ifndef CONTRASENA_H_INCLUDED
#define CONTRASENA_H_INCLUDED
/* Biblioteca exclusiva para su uso en el proyecto de Programaci�n
* avanzada y metodos num�ricos, la cual esta sujeta a las especificaciones
* de este
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define WINDOWS 1

#if WINDOWS
#include <conio.h>
#endif /* WINDOWS */

#define DEBUG 0
#define ESTANDAR 0
#define tamDatos 17
#define archivo_CuentaUsuario "superSecreto.secret"
#define limpiar(x) for(i=0;i<tamDatos;++i) { x[i]=0; }

enum booleano{falso,verdadero};
typedef enum booleano Booleano;

void validarUsuario(void);
void establecerLocale(void); /* Prototipo de la funci�n establecerIdioma */
void contrasenaDeSeguridad( FILE* , unsigned char* , unsigned char* ); /* Prototipo de la funci�n contrasenaDeSeguridad */
Booleano comprobarContrasena( FILE* , unsigned char* , unsigned char* ); /* Prototipo de la funci�n comprobarContrasena */
void pedirContrasena( FILE* , unsigned char* , unsigned char* ); /* Prototipo de la funci�n pedirContrasena */
void reparar( unsigned char *cadena );

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

void validarUsuario(){
    contrasenaDeSeguridad( datosUsuario, usuario, contrasena );
}

void establecerLocale(){
    #if ESTANDAR
	setlocale(LC_ALL,"");
    #else
	setlocale(LC_ALL,"Spanish_Mexico");
    #endif
}

void contrasenaDeSeguridad(FILE *archivo, unsigned char *user, unsigned char *pswrd ){
	archivo = fopen(archivo_CuentaUsuario,"r");

	if (archivo == NULL){
		printf("%s%s%s%s%s%s",
			   "Parace que usted es un nuevo usuario \n",
			   "Este sistema de seguridad para contactos \n",
			   "lo identificar� a usted con una cuenta y una \n",
			   "contrase�a estandares\n",
               "(16 caracteres cada una)\n\n\n",
			   "A continuaci�n deber� ingresar una cuenta y contrase�a nuevas"
			   );
		getchar();

		pedirContrasena(archivo,user, pswrd);

		archivo = fopen(archivo_CuentaUsuario,"w");
		fprintf(archivo,"%s\t%s",user,pswrd);
		fclose(archivo);

		printf("\n%s%s\n",
			   "���Felicidades!!!",
			   "tus contactos estar�n seguros a partir de ahora"
			   );
		printf("Esperamos que tu experiencia con la aplicaci�n sea grata\n\n");
		getchar();
	}else{

		if( comprobarContrasena( archivo, user, pswrd ) == verdadero ){
			fclose(archivo);
			printf("\nBienvenido de vuelta %s\n\n",user);
			getchar();
		}else{
            #if WINDOWS
			system("cls");
            #else
			system("clear");
            #endif
			printf("\n%s\n\n\n",
				   "���Cuenta de usuario o contrase�a incorrecta!!!");
			printf("\t\tEl programa se cerrar�\n");
			getchar();
			exit(0);
		}
	}
}

Booleano comprobarContrasena( FILE *archivo , unsigned char *user, unsigned char *pswrd ){
	unsigned char usuarioReal[tamDatos], contrasenaReal[tamDatos];
	int i; /* Variable contadora */
	limpiar(usuarioReal)
    limpiar(contrasenaReal)

    fscanf(archivo," %s",usuarioReal);
	fscanf(archivo," %s",contrasenaReal);
    #if DEBUG /* DEBUG 2*/
	printf("\nLos datos de usuario son: %s %s\n",usuarioReal,contrasenaReal);
	getchar();
    #endif /* Fin DEBUG 2*/
	pedirContrasena( archivo , user, pswrd );

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

	for( i = 0 ; i < tamDatos-1 ; ++i){
		if ( (usuarioReal[i]!=user[i]) || (contrasenaReal[i]!=pswrd[i]) ){
			return falso;
		}
	}

	return verdadero;
}

void pedirContrasena( FILE *archivo , unsigned char *user , unsigned char *pswrd ){
	unsigned char c = 100;
	short m = 0, n; /* Dos variables contadoras que se usan para pedir datos */

	limpiar(usuario)
	limpiar(contrasena)

    #if WINDOWS
	system("cls");
    #else
	system("clear");
    #endif

	printf("Por favor ingrese su cuenta de usuario:\n");
	scanf(" %s",usuario);

    #if WINDOWS
	system("cls");
    #else
	system("clear");
    #endif

	printf("Por favor ingrese su contrase�a");
    #if  WINDOWS
    printf(":\n");
    #else
    printf(" letra por letra:\n");
    #endif

	getchar();

    #if  WINDOWS
	c = getch();
    #else
	c = getchar();
	getchar();
    #endif

	while( c != '\n' && c != '\t' && c != ' ' && c != '\r' && m < tamDatos-1 ){
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

    #if  WINDOWS
	system("cls");
    #else
	system("clear");
    #endif

    if( c != 127 && c != 8 ){
        contrasena[m] = c;
		++m;
    }else{
		--m;
    }

    printf("Por favor ingrese su contrase�a");
    #if  WINDOWS
    printf(":\n");
    #else
    printf(" letra por letra:\n");
    #endif
    for( n = 1 ; n <= m ; ++n ){
        putchar('*');
    }

    #if WINDOWS
    c = getch();
    #else
    c = getchar();
    getchar();
    #endif

	}
	contrasena[m] = '\0';

    reparar( usuario );
    reparar( contrasena );

    #if DEBUG
	printf("\n%s %s\n",usuario,contrasena);
	getchar();
    #endif /* DEBUG */
}


void reparar( unsigned char *cadena ){
    short n;
	unsigned char a[128];
	a[0] = '�';
	a[1] = '�';
	a[2] = '�';
	a[3] = '�';
	a[4] = '�';
	a[5] = '�';
	a[6] = '�';
	a[7] = '�';
	a[8] = '�';
	a[9] = '�';
	a[10] = '�';
	a[11] = '�';
	a[12] = '�';
	a[13] = '�';
	a[14] = '�';
	a[15] = '�';
	a[16] = '�';
	a[17] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[18] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[19] = '�';
	a[20] = '�';
	a[21] = '�';
	a[22] = '�';
	a[23] = '�';
	a[24] = '�';
	a[25] = '�';
	a[26] = '�';
	a[27] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[28] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[29] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[30] = '�';
	a[31] = '�';
	a[32] = '�';
	a[33] = '�';
	a[34] = '�';
	a[35] = '�';
	a[36] = '�';
	a[37] = '�';
	a[38] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[39] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[40] = '�';
	a[41] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[42] = '�';
	a[43] = '�';
	a[44] = '�';
	a[45] = '�';
	a[46] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[47] = '�';
	a[48] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[49] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[50] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[51] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[52] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[53] = '�';
	a[54] = '�';
	a[55] = '�';
	a[56] = '�';
	a[57] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[58] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[59] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[60] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[61] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[62] = '�';
	a[63] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[64] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[65] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[66] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[67] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[68] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[69] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[70] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[71] = '�';
	a[72] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[73] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[74] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[75] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[76] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[77] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[78] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[79] = '�';
	a[80] = '�';
	a[81] = '�';
	a[82] = '�';
	a[83] = '�';
	a[84] = '�';
	a[85] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[86] = '�';
	a[87] = '�';
	a[88] = '�';
	a[89] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[90] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[91] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[92] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[93] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[94] = '�';
	a[95] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[96] = '�';
	a[97] = '�';
	a[98] = '�';
	a[99] = '�';
	a[100] = '�';
	a[101] = '�';
	a[102] = '�';
	a[103] = '�';
	a[104] = '�';
	a[105] = '�';
	a[106] = '�';
	a[107] = '�';
	a[108] = '�';
	a[109] = '�';
	a[110] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[111] = '�';
	a[112] = '�';
	a[113] = '�';
	a[114] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[115] = '�';
	a[116] = '�';
	a[117] = '�';
	a[118] = '�';
	a[119] = '�';
	a[120] = '�';
	a[121] = '�';
	a[122] = '�';
	a[123] = '�';
	a[124] = '�';
	a[125] = '�';
	a[126] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */
	a[127] = 'a'; /* Caracter no valido para contrase�as en este proyecto, se remplaza por a */

	for( n=0 ; (cadena[n] || n < tamDatos -1) ; ++n ){
		if (cadena[n]>=128){
			cadena[n] = a[cadena[n]-128];
		}
	}
}



#endif // CONTRASENA_H_INCLUDED
