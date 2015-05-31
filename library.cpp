#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


/* ============================== ESTRUCTURAS =============================== */

// Estructura LIBRO
typedef struct libro
{
	char 	tipo[100];
	char	ISBN[60];
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	anio_publicacion[60];
};

// Estructura MONOGRAFIA
typedef struct monografia
{
	char 	tipo[100];
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
};

// Estructura ARTICULO
typedef struct articulo
{
	char 	tipo[100];
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	nombre_revista[120];
	char	paginas[120];
};

// Estructura AUDIO
typedef struct audio
{
	char 	tipo[100];
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	formato[20];
	char	duracion[60];
};

// Estructura VIDEO
typedef struct video
{
	char 	tipo[100];
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	formato[20];
	char	duracion[60];
};

// Estructura RECURSO WEB
typedef struct uri
{
	char tipo[100];
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	uri[800];
	char	idioma[120];
};

/* VARIABLES GLOBALES */
libro libro1;
monografia monografia1;
articulo articulo1;
audio audio1;
video video1;
uri uri1;

// para ingresar
FILE* archivo= NULL;
char* nombrearchivo = "Library.txt";

// para buscar
FILE* archivo_buscar= NULL;
char* nombrearchivo_buscar = "Library.txt";


/* ============================== PROTOTIPOS ================================ */
// Menu Opciones
void opciones (void);

// Menu Busqueda
void menu_busqueda (void);

// Menu Administrar Recursos
void menu_admon_recursos(void);

// Menu Administrar Recursos Agregar
void menu_admon_recursos_agregar(void);

// Menu Configuracion Biblioteca
void menu_config (void);

// Menu Configuracion Biblioteca - Administrar tipos
void menu_config_tipos (void);

// Menu Configuracion Biblioteca - Administrar Metadatos
void menu_config_metadatos (void);

//Crear RECURSO 
void crear_recurso (int opcion);


/* =============================== FUNCIONES ================================ */


/* -------------------------- MENUS -------------------------- */

// Menu Principal
void opciones (void)
{
     printf ("		    MENU PRINCIPAL         	\n\n\n");
     printf (" 1.  Buscar recurso.					\n");
     printf (" 2.  Administrar Recursos.			\n");
     printf (" 3.  Configuracion Biblioteca.		\n");
     printf (" 0.  Salir   						  \n\n");
}


// Menu Busqueda
void menu_busqueda (void)
{
     printf ("		       BUSQUEDA  		   	\n\n\n");
     printf (" 1.  Buscar por Autor.				\n");
     printf (" 2.  Buscar por Titulo.				\n");
     printf (" 3.  Buscar por tema.					\n");
     printf (" 0.  Volver   					  \n\n");
}

// Menu Administrar Recursos
void menu_admon_recursos(void)
{
     printf ("		 ADMINISTRAR RECURSOS		\n\n\n");
     printf (" 1.  Agregar recursos.				\n");
     printf (" 2.  Modificar datos recursos.		\n");
     printf (" 3.  Borrar un recurso.				\n");
     printf (" 0.  Volver   					  \n\n");
}

// Menu Administrar Recursos Agregar
void menu_admon_recursos_agregar(void)
{
     printf ("		   INGRESAR RECURSOS		\n\n\n");
     printf (" 1.  Ingresar Libro.					\n");
     printf (" 2.  Ingresar Monografia.				\n");
     printf (" 3.  Ingresar Articulo.				\n");
     printf (" 4.  Ingresar Audio.					\n");
     printf (" 5.  Ingresar Video.					\n");
     printf (" 6.  Ingresar URI.					\n");
     printf (" 0.  Volver   					  \n\n");
}

// Menu Configuracion Biblioteca
void menu_config (void)
{
     printf ("		     CONFIGURACION  		\n\n\n");
     printf (" 1.  Administrar tipos.				\n");
     printf (" 2.  Administrar Metadatos.			\n");
     printf (" 0.  Volver   					  \n\n");
}

// Menu Configuracion Biblioteca - Administrar tipos
void menu_config_tipos (void)
{
     printf ("	    CONFIGURACION RECURSOS 		\n\n\n");
     printf (" 1.  Crear recurso.					\n");
     printf (" 2.  Modificar recurso.				\n");
     printf (" 3.  Borrar recurso.					\n");
     printf (" 0.  Volver   					  \n\n");
}

// Menu Configuracion Biblioteca - Administrar Metadatos
void menu_config_metadatos (void)
{
     printf ("	    CONFIGURACION METADATOS 	\n\n\n");
     printf (" 1.  Crear metadatos.					\n");
     printf (" 2.  Modificar metadatos.				\n");
     printf (" 3.  Borrar metadatos.				\n");
     printf (" 0.  Volver   					  \n\n");
}


/* ----------------------- FUNCIONES RECURSOS ----------------------- */

//Funcion con la cual se ingresarn los recuros, cualquiera de ellos.
void crear_recurso (int opcion)
{	
	
	switch(opcion)
	{	
		case 1:	/*RECURSO LIBRO*/

				//se abre el archivo
				archivo= fopen(nombrearchivo, "a"); //abro el archivo
	
			    //Ingresar datos
			    printf("Ingrese ISBN: ");
			    fflush(stdin);
			    scanf("%d",&libro1.ISBN);
			    
			    printf("\ningrese el Titulo: ");
			    fflush(stdin);
			    gets(libro1.titulo);
			    
			    printf("\nIngrese el Autor(es): ");
			    fflush(stdin);
			    gets(libro1.autors);
			    
			    printf("\nIngrese Tema: ");
			    fflush(stdin);
			    gets(libro1.tema);
			    
			    printf("\nIngrese el Anio de Pulicacion: ");
			    fflush(stdin);
			    scanf("%d",&libro1.anio_publicacion);

			    
			    // Escribir datos en el archivo
			    fprintf(archivo,"libro|",libro1.tipo);
			    fprintf(archivo,"%d|",libro1.ISBN);
			    fprintf(archivo,"%s|",libro1.titulo);
			    fprintf(archivo,"%s|",libro1.autors);
			    fprintf(archivo,"%s|",libro1.tema);
			    fprintf(archivo,"%d.\n",libro1.anio_publicacion);
			    
			    fclose(archivo);
			    
			    break;
			    
		case 2:	/*RECURSO MONOGRAFIA*/

				archivo= fopen(nombrearchivo, "a"); //abro el archivo
	
			    //Ingresar datos 
			    printf("\ningrese el Titulo: ");
			    fflush(stdin);
			    gets(monografia1.titulo);
			    
			    printf("\nIngrese el Autor(es): ");
			    fflush(stdin);
			    gets(monografia1.autors);
			    
			    printf("\nIngrese Tema: ");
			    fflush(stdin);
			    gets(monografia1.tema);

			    // Escribir datos en el archivo
			    fprintf(archivo,"monografia|",monografia1.tipo);
			    fprintf(archivo,"%s|",monografia1.titulo);
			    fprintf(archivo,"%s|",monografia1.autors);
			    fprintf(archivo,"%s.\n",monografia1.tema);
			    
			    fclose(archivo);
			    
			    break;

		case 3:	/*RECURSO ARTICULO*/

				archivo= fopen(nombrearchivo, "a"); //abro el archivo
	
			    //Ingresar datos 
			    printf("\ningrese el Titulo: ");
			    fflush(stdin);
			    gets(articulo1.titulo);
			    
			    printf("\nIngrese el Autor(es): ");
			    fflush(stdin);
			    gets(articulo1.autors);
			    
			    printf("\nIngrese Tema: ");
			    fflush(stdin);
			    gets(articulo1.tema);

			    printf("\nIngrese Nombre de la revista: ");
			    fflush(stdin);
			    gets(articulo1.nombre_revista);

			    printf("\nIngrese rango de paginas articulo: ");
			    fflush(stdin);
			    gets(articulo1.paginas);

			    // Escribir datos en el archivo
			    fprintf(archivo,"articulo|",articulo1.tipo);
			    fprintf(archivo,"%s|",articulo1.titulo);
			    fprintf(archivo,"%s|",articulo1.autors);
			    fprintf(archivo,"%s|",articulo1.tema);
			    fprintf(archivo,"%s|",articulo1.nombre_revista);
			    fprintf(archivo,"%s.\n",articulo1.paginas);
			    
			    fclose(archivo);
			    
			    break;

		case 4:	/*RECURSO AUDIO*/

				archivo= fopen(nombrearchivo, "a"); //abro el archivo
	
			    //Ingresar datos 
			    printf("\ningrese el Titulo: ");
			    fflush(stdin);
			    gets(audio1.titulo);
			    
			    printf("\nIngrese el Autor(es): ");
			    fflush(stdin);
			    gets(audio1.autors);
			    
			    printf("\nIngrese Tema: ");
			    fflush(stdin);
			    gets(audio1.tema);

			    printf("\nIngrese formato de del audio: ");
			    fflush(stdin);
			    gets(audio1.formato);

			    printf("Ingrese duracion del audio (hh:mm:ss): ");
			    fflush(stdin);
			    gets(audio1.duracion);

			    // Escribir datos en el archivo
			    fprintf(archivo,"audio|",audio1.tipo);
			    fprintf(archivo,"%s|",audio1.titulo);
			    fprintf(archivo,"%s|",audio1.autors);
			    fprintf(archivo,"%s|",audio1.tema);
			    fprintf(archivo,"%s|",audio1.formato);
			    fprintf(archivo,"%s.\n",audio1.duracion);
			    
			    fclose(archivo);
			    
			    break;

		case 5:	/*RECURSO VIDEO*/

				archivo= fopen(nombrearchivo, "a"); //abro el archivo
	
			    //Ingresar datos 
			    printf("\ningrese el Titulo: ");
			    fflush(stdin);
			    gets(video1.titulo);
			    
			    printf("\nIngrese el Autor(es): ");
			    fflush(stdin);
			    gets(video1.autors);
			    
			    printf("\nIngrese Tema: ");
			    fflush(stdin);
			    gets(video1.tema);

			    printf("\nIngrese formato de video: ");
			    fflush(stdin);
			    gets(video1.formato);

			    printf("Ingrese duracion del video (hh:mm:ss): ");
			    fflush(stdin);
			    gets(video1.duracion);

			    // Escribir datos en el archivo
			    fprintf(archivo,"video|",video1.tipo);
			    fprintf(archivo,"%s|",video1.titulo);
			    fprintf(archivo,"%s|",video1.autors);
			    fprintf(archivo,"%s|",video1.tema);
			    fprintf(archivo,"%s|",video1.formato);
			    fprintf(archivo,"%s.\n",video1.duracion);
			    
			    fclose(archivo);
			    
			    break;

		case 6:	/*RECURSO URI*/
			    
				archivo= fopen(nombrearchivo, "a"); //abro el archivo
	
			    //Ingresar datos 
			    printf("\ningrese el Titulo: ");
			    fflush(stdin);
			    gets(uri1.titulo);
			    
			    printf("\nIngrese el Autor(es): ");
			    fflush(stdin);
			    gets(uri1.autors);
			    
			    printf("\nIngrese Tema: ");
			    fflush(stdin);
			    gets(uri1.tema);

			    printf("\nIngrese URI: ");
			    fflush(stdin);
			    gets(uri1.uri);

			    printf("Ingrese idioma del recurso: ");
			    fflush(stdin);
			    gets(uri1.idioma);

			    // Escribir datos en el archivo
			    fprintf(archivo,"uri|",uri1.tipo);
			    fprintf(archivo,"%s|",uri1.titulo);
			    fprintf(archivo,"%s|",uri1.autors);
			    fprintf(archivo,"%s|",uri1.tema);
			    fprintf(archivo,"%s|",uri1.uri);
			    fprintf(archivo,"%s.\n",uri1.idioma);
			    
			    fclose(archivo);
			    
			    break;
	}   
}

// Funcion para buscar en el archivo
void buscar (void)
{
	
}




/* MAIN */
int main (void)
{
	int opc=-1, opc_busq=-1, opc_admin=-1, opc_config=-1, opc_config_tipos=-1, opc_config_metadatos=-1, opc_admin_agrear=-1;
	
	do {
        system ("cls"); 
        
        opciones();
        printf ("Ingrese la opcion seleccionada:  ");
        scanf ("%d",&opc); 
	
		switch(opc)
		{
			case 1:
				
					system ("cls"); 
        
        			menu_busqueda(); 
					printf ("Ingrese la opción seleccionada:  "); 
        			scanf ("%d",&opc_busq);
				
					//Menu Busqueda
					switch(opc_busqueda) 
					{
							/*
								1.  Buscar por Autor.				\n");
 								2.  Buscar por Titulo.				\n");
								3.  Buscar por tema.
							*/
							
							case 1:	// Crear recurso LIBRO
									crear_recurso(opc_admin_agrear);
									getch();
									goto menu_admin_agregar;
									break;

							case 2:	// Crear recurso MONOGRAFIA
									crear_recurso(opc_admin_agrear);
									getch();
									goto menu_admin_agregar;
									break;

							case 3:	// Crear recurso ARTICULO
									crear_recurso(opc_admin_agrear);
									getch();
									goto menu_admin_agregar;
									break;

							case 4:	// Crear recurso AUDIO
									crear_recurso(opc_admin_agrear);
									getch();
									goto menu_admin_agregar;
									break;
											
							case 5:	// Crear recurso VIDEO
									crear_recurso(opc_admin_agrear);
									getch();
									goto menu_admin_agregar;
									break;
											
							case 6:	// Crear recurso URI
									crear_recurso(opc_admin_agrear);
									getch();
									goto menu_admin_agregar;
									break;
												
							case 0: 
									goto menu_admin;
									break;
								
					}

					break;
					
					break;
		
			case 2:
					
					menu_admin:
					system ("cls"); 
        
        			menu_admon_recursos();
					printf ("Ingrese la opción seleccionada:  "); 
        			scanf ("%d",&opc_admin);
					
					//Menu Administracion Recursos
					switch(opc_admin) 
					{
						case 1:
								menu_admin_agregar:
								system ("cls"); 
        
			        			menu_admon_recursos_agregar();
								printf ("Ingrese la opción seleccionada:  "); 
			        			scanf ("%d",&opc_admin_agrear);

			        			switch(opc_admin_agrear)
								{
									case 1:	// Crear recurso LIBRO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_agregar;
											break;

									case 2:	// Crear recurso MONOGRAFIA
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_agregar;
											break;

									case 3:	// Crear recurso ARTICULO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_agregar;
											break;

									case 4:	// Crear recurso AUDIO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_agregar;
											break;
											
									case 5:	// Crear recurso VIDEO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_agregar;
											break;
											
									case 6:	// Crear recurso URI
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_agregar;
											break;
												
									case 0: 
											goto menu_admin;
											break;
								}
			        						
								break;
						
					}
					
					break;
					
			case 3:
					
					menu_config:
					system ("cls"); 
        
        			menu_config();
					printf ("Ingrese la opción seleccionada:  "); 
        			scanf ("%d",&opc_config);
				
					//Menu Configuracion Biblioteca
					switch(opc_config) 
					{
						case 1:
								system ("cls");
								
								menu_config_tipos();
								
								printf ("Ingrese la opción seleccionada:  "); 
        						scanf ("%d",&opc_config_tipos);
        						
        						switch(opc_config_tipos)
								{
									case 0: 
											goto menu_config;
											break;
								}
        						
								break;
								
						case 2:
								system ("cls");
								
								menu_config_metadatos();
								
								printf ("Ingrese la opción seleccionada:  "); 
        						scanf ("%d",&opc_config_metadatos);
        						
        						switch(opc_config_metadatos)
								{
									case 0: 
											goto menu_config;
								}
        						
								break;
								
					}

					break;
						
			defalut:
			printf("Ha ingresado un numero no valido\n");
			break;			

		}
	} while (opc != 0);
	
	getch();
}

