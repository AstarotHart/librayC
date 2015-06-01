#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


/* ============================== ESTRUCTURAS =============================== */

// Estructura LIBRO
typedef struct libro
{
	int		ISBN;
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	int		anio_publicacion;
};

// Estructura MONOGRAFIA
typedef struct monografia
{

	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
};

// Estructura ARTICULO
typedef struct articulo
{

	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	nombre_revista[120];
	char	paginas[120];
};

// Estructura AUDIO
typedef struct audio
{
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	formato[20];
	char	duracion[60];
};

// Estructura VIDEO
typedef struct video
{
	char 	titulo[120];
	char 	autors[60];
	char 	tema[120];
	char	formato[20];
	char	duracion[60];
};

// Estructura RECURSO WEB
typedef struct uri
{
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
//char* nombrearchivo = "Library.txt";

char nombrearchivo[]={"library.dat"};

// para buscar
FILE* archivo_buscar= NULL;
//char* nombrearchivo_buscar = "Library.txt";
char nombrearchivo_buscar[]={"library.dat"};


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
				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
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
				
					/*OTRA FORMA*/
					fwrite(&libro1,sizeof(libro1),1,archivo);
					
				    fclose(archivo);
			    
			    break;
			    
		case 2:	/*RECURSO MONOGRAFIA*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
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
				fwrite(&monografia1,sizeof(monografia1),1,archivo);
				
			    fclose(archivo);
			    
			    break;

		case 3:	/*RECURSO ARTICULO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
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
				fwrite(&articulo1,sizeof(articulo1),1,archivo);

			    fclose(archivo);
			    
			    break;

		case 4:	/*RECURSO AUDIO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
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
				fwrite(&audio1,sizeof(audio1),1,archivo);
			    
			    fclose(archivo);
			    
			    break;

		case 5:	/*RECURSO VIDEO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
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
				fwrite(&video1,sizeof(video1),1,archivo);
			    
			    fclose(archivo);
			    
			    break;

		case 6:	/*RECURSO URI*/
			    
				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
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
				fwrite(&uri1,sizeof(uri1),1,archivo);
			    
			    fclose(archivo);
			    
			    break;
	}   
}

// Funcion para buscar en el archivo
void buscar (int opcion)
{
	char busq[60];
	
	int found=0, cont=0;
	
	switch(opcion)
	{
		/*
			1.  Buscar por Autor.				\n");
 			2.  Buscar por Titulo.				\n");
			3.  Buscar por tema.
		*/
		
		case 1:	/*BUSCAR POR AUTOR*/
				
				//Ingresar termino a buscar
				printf("\n  Autor a Buscar: ");
			    fflush(stdin);
			    gets(busq);
			    
			    //se abre el archivo
				archivo_buscar= fopen(nombrearchivo_buscar, "rb");
		        
	
		        //by_autor:
		        	printf("\n =================================================");
					printf("\n\t\t\tLIBROS");
					printf("\n =================================================\n");
			    	printf("\n  (Autor, Isbn, Titulo, Tema, Anio Publicacion.)");
			    	printf("\n   --------------------------------------------\n\n");
		        	goto autor_libro;

		    /*BUSCAR EN LIBROS POR AUTOR*/

		        autor_libro:
		        	
		        	found = 0;
		        	cont = 0;
		        	
			        while(1)
					{
						/*
							fread[editar]
							size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
							
							Esta función lee un bloque de una "stream" de datos. Efectúa la lectura de un arreglo 
							de elementos "count", cada uno de los cuales tiene un tamaño definido por "size". 
							Luego los guarda en el bloque de memoria especificado por "ptr". El indicador de posición 
							de la cadena de caracteres avanza hasta leer la totalidad de bytes. Si esto es exitoso la 
							cantidad de bytes leídos es (size*count).
							
							
							PARAMETROS:
							
							ptr  : Puntero a un bloque de memoria con un tamaño mínimo de (size*count) bytes.
							size  : Tamaño en bytes de cada elemento (de los que voy a leer).
							count : Número de elementos, los cuales tienen un tamaño "size".
							stream: Puntero a objetos FILE, que especifica la cadena de entrada.
						*/
						
						
						fread(&libro1,sizeof(libro1),1,archivo_buscar);
						
						// Fin archivo int feof(FILE *fichero);
						if(feof(archivo_buscar))
						{
							break;
						}
						
						// strcmp compara cadenas
						if(strcmp(busq,libro1.autors)==0)
						{
							printf("   %s, ",libro1.autors);
							printf("%d, ",libro1.ISBN);
							printf("%s, ",libro1.titulo);
							printf("%s, ",libro1.tema);
							printf("%d.\n",libro1.anio_publicacion);
							
							cont++;
						}
						
					}

					if(found==0)
					{
						if(cont==0)
						{
							printf("   No hay registros en LIBROS para este autor.\n");	
						}
						
						printf("\n =================================================");
						printf("\n\t\t      MONOGRAFIAS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema.)");
						printf("\n   ---------------------------------------------\n\n");
		        		goto autor_monografia;				
					}


			/*BUSCAR EN MONOGRAFIA POR AUTOR*/

		        autor_monografia:
		        	
		        	found = 0;
		        	cont = 0;
		        	
			        while(1)
					{
						
						fread(&monografia1,sizeof(monografia1),1,archivo_buscar);
						
						// Fin archivo int feof(FILE *fichero);
						if(feof(archivo_buscar))
						{
							break;
						}
						
						// strcmp compara cadenas
						if(strcmp(busq,monografia1.autors)==0)
						{
							printf("   %s, ",monografia1.autors);
							printf("%s, ",monografia1.titulo);
							printf("%d.\n",monografia1.tema);
						}
						
					}

					if(found==0)
					{
						if(cont==0)
						{
							printf("   No hay registros en MONOGRAFIAS para este autor.\n");	
						}
						
						printf("\n =================================================");
						printf("\n\t\t       ARTICULOS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Nombre revista, Paginas.)");
						printf("\n   ---------------------------------------------\n\n");
		        		goto autor_articulo;				
					}


			/*BUSCAR EN ARTICULO POR AUTOR*/

		        autor_articulo:
		        	
		        	found = 0;
		        	cont = 0;
		        	
			        while(1)
					{
						
						fread(&articulo1,sizeof(articulo1),1,archivo_buscar);
						
						// Fin archivo int feof(FILE *fichero);
						if(feof(archivo_buscar))
						{
							break;
						}
						
						// strcmp compara cadenas
						if(strcmp(busq,articulo1.autors)==0)
						{
							printf("   %s, ",articulo1.autors);
							printf("%s, ",articulo1.titulo);
							printf("%s, ",articulo1.tema);
							printf("%s, ",articulo1.nombre_revista);
							printf("%s\n",articulo1.paginas);
						}
						
					}

					if(found==0)
					{
						if(cont==0)
						{
							printf("   No hay registros en ARTICULOS para este autor.\n");	
						}
						
						printf("\n =================================================");
						printf("\n\t\t\tAUDIOS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
		        		goto autor_audio;				
					}


			/*BUSCAR EN AUDIO POR AUTOR*/

		        autor_audio:
		        	
		        	found = 0;
		        	cont = 0;
		        	
			        while(1)
					{
						
						fread(&audio1,sizeof(audio1),1,archivo_buscar);
						
						// Fin archivo int feof(FILE *fichero);
						if(feof(archivo_buscar))
						{
							break;
						}
						
						// strcmp compara cadenas
						if(strcmp(busq,audio1.autors)==0)
						{
							printf("   %s, ",audio1.autors);
							printf("%s, ",audio1.titulo);
							printf("%s, ",audio1.tema);
							printf("%s, ",audio1.formato);
							printf("%s\n",audio1.duracion);
						}
						
					}

					if(found==0)
					{
						if(cont==0)
						{
							printf("   No hay registros en AUDIOS para este autor.\n");	
						}
						
						printf("\n =================================================");
						printf("\n\t\t\tVIDEOS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
		        		goto autor_video;				
					}


			/*BUSCAR EN VIDEO POR AUTOR*/

		        autor_video:
		        	
		        	found = 0;
		        	cont = 0;
		        	
			        while(1)
					{
						
						fread(&video1,sizeof(video1),1,archivo_buscar);
						
						// Fin archivo int feof(FILE *fichero);
						if(feof(archivo_buscar))
						{
							break;
						}
						
						// strcmp compara cadenas
						if(strcmp(busq,video1.autors)==0)
						{
							printf("   %s, ",video1.autors);
							printf("%s, ",video1.titulo);
							printf("%s, ",video1.tema);
							printf("%s, ",video1.formato);
							printf("%s\n",video1.duracion);
						}
						
					}

					if(found==0)
					{
						if(cont==0)
						{
							printf("   No hay registros en VIDEOS para este autor.\n");	
						}
						
						printf("\n =================================================");
						printf("\n\t\t\t URIS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Uri, Idioma.)");
						printf("\n   ---------------------------------\n\n");
		        		goto autor_uri;				
					}
					

			/*BUSCAR EN URI POR AUTOR*/

		        autor_uri:
		        	
		        	found = 0;
		        	cont = 0;
		        	
			        while(1)
					{
						
						fread(&uri1,sizeof(uri1),1,archivo_buscar);
						
						// Fin archivo int feof(FILE *fichero);
						if(feof(archivo_buscar))
						{
							break;
						}
						
						// strcmp compara cadenas
						if(strcmp(busq,uri1.autors)==0)
						{
							printf("   %s, ",uri1.autors);
							printf("%s, ",uri1.titulo);
							printf("%s, ",uri1.tema);
							printf("%s, ",uri1.uri);
							printf("%s\n",uri1.idioma);
						}

					}

					if(found==0)
					{
						if(cont==0)
						{
							printf("   No hay registros en URIS para este autor.\n");	
						}				
					}


				//Cierro el archivo
				fclose(archivo_buscar);     
		        
		break;


		case 2:	/*BUSCAR POR TITULO*/

				//se abre el archivo
				archivo_buscar= fopen(nombrearchivo, "rb");
				
				//Ingresar termino a buscar
				printf("\n  Autor a Buscar: ");
			    fflush(stdin);
			    gets(busq);
		        
		        printf("\n  (Titulo, Isbn, Autor, Tema, Fecha Publicacion)\n\n");
		        
		        
		        while(1)
				{
					
					fread(&libro1,sizeof(libro1),1,archivo_buscar);
					
					// Fin archivo int feof(FILE *fichero);
					if(feof(archivo_buscar))
					{
						break;
					}
					
					// strcmp compara cadenas
					if(strcmp(busq,libro1.titulo)==0)
					{
						printf("   %s, ",libro1.titulo);
						printf("%d, ",libro1.ISBN);
						printf("%s, ",libro1.autors);
						printf("%s, ",libro1.tema);
						printf("%d.\n",libro1.anio_publicacion);
					}
					
				}
				if(found==0)
				{
					printf("\nNo hay mas regstros..");
				}
				fclose(archivo_buscar);
		        
		        
		break;

		case 3:	/*BUSCAR POR TEMA*/

				//se abre el archivo
				archivo_buscar= fopen(nombrearchivo, "rb");
				
				//Ingresar termino a buscar
				printf("\n  Autor a Buscar: ");
			    fflush(stdin);
			    gets(busq);
		        
		        printf("\n  (Tema, Isbn, Titulo, Autor, Fecha Publicacion)\n\n");
		        
		        
		        while(1)
				{
					
					fread(&libro1,sizeof(libro1),1,archivo_buscar);
					
					// Fin archivo int feof(FILE *fichero);
					if(feof(archivo_buscar))
					{
						break;
					}
					
					// strcmp compara cadenas
					if(strcmp(busq,libro1.titulo)==0)
					{
						printf("   %s, ",libro1.tema);
						printf("%d, ",libro1.ISBN);
						printf("%s, ",libro1.titulo);
						printf("%s, ",libro1.autors);
						printf("%d.\n",libro1.anio_publicacion);
					}
					
				}
				if(found==0)
				{
					printf("\nNo hay mas regstros..");
				}
				fclose(archivo_buscar);
		        
		        
		break;

  }

}




/* MAIN */
int main (void)
{
	int opc=-1, opc_busqueda=-1, opc_admin=-1, opc_config=-1, opc_config_tipos=-1, opc_config_metadatos=-1, opc_admin_agrear=-1;
	
	do {
        system ("cls"); 
        
        opciones();
        printf ("Ingrese la opcion seleccionada:  ");
        scanf ("%d",&opc); 
	
		switch(opc)
		{
			case 1:
				
					menu_busqueda:
					system ("cls"); 
        
        			menu_busqueda(); 
					printf ("Ingrese la opcion seleccionada:  "); 
        			scanf ("%d",&opc_busqueda);
				
					//Menu Busqueda
					switch(opc_busqueda) 
					{
							/*
								1.  Buscar por Autor.				\n");
 								2.  Buscar por Titulo.				\n");
								3.  Buscar por tema.
							*/
							
							case 1:	// buscar por AUTOR
									buscar(opc_busqueda);
									getch();
									goto menu_busqueda;
									break;
									
							case 2:	// buscar por TITULO
									buscar(opc_busqueda);
									getch();
									goto menu_busqueda;
									break;
									
							case 3:	// buscar por TEMA
									buscar(opc_busqueda);
									getch();
									goto menu_busqueda;
									break;
												
							case 0: 
									break;
								
					}
					
			break;
		
			case 2:
					
					menu_admin:
					system ("cls"); 
        
        			menu_admon_recursos();
					printf ("Ingrese la opcion seleccionada:  "); 
        			scanf ("%d",&opc_admin);
					
					//Menu Administracion Recursos
					switch(opc_admin) 
					{
						case 1:
								menu_admin_agregar:
								system ("cls"); 
        
			        			menu_admon_recursos_agregar();
								printf ("Ingrese la opcion seleccionada:  "); 
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
					printf ("Ingrese la opcion seleccionada:  "); 
        			scanf ("%d",&opc_config);
				
					//Menu Configuracion Biblioteca
					switch(opc_config) 
					{
						case 1:
								system ("cls");
								
								menu_config_tipos();
								
								printf ("Ingrese la opcion seleccionada:  "); 
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
								
								printf ("Ingrese la opcion seleccionada:  "); 
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

