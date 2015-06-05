#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


/* ============================== ESTRUCTURAS =============================== */

// Estructura GENERAL
typedef struct general
{
	char	tipo[10];
	char	ISBN[10];
	char 	titulo[60];
	char 	autors[60];
	char 	tema[60];
	char	anio_publicacion[4];
	//para articulo
	char	nombre_revista[60];
	char	paginas[10];
	// para audio y video
	char	formato[5];
	char	duracion[12];
	//para uri
	char	uri[200];
	char	idioma[12];
};


/* VARIABLES GLOBALES */

// declaro una estructura general1 tipo GENERAL
general general1;


// para ingresar al archivo LIBRARY.DAT
FILE *archivo= NULL;
char nombrearchivo[]={"library.dat"};

// para ingresar al archivo LIBRARY.DAT
FILE *temp= NULL;
char nombretemp[]={"temp.dat"};


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

// Buscar RECURSO 
void buscar (int opcion);

// Modificar RECURSO
void modficar_recurso (int opcion);


/* =============================== FUNCIONES ================================ */
void EliminarRetornoLinea(char *cad)
{
   int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}

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

// Menu Administrar Recursos Modificar
void menu_admon_recursos_modificar(void)
{
     printf ("		  MODIFICAR RECURSOS		\n\n\n");
     printf (" 1.  Modificar Libro.					\n");
     printf (" 2.  Modificar Monografia.			\n");
     printf (" 3.  Modificar Articulo.				\n");
     printf (" 4.  Modificar Audio.					\n");
     printf (" 5.  Modificar Video.					\n");
     printf (" 6.  Modificar URI.					\n");
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
	// Este modo permite leer y escribir
	archivo = fopen(nombrearchivo, "r+b");
   	
   	// si el fichero no existe, lo crea.
	if(!archivo)
   	{
   		archivo = fopen(nombrearchivo, "w+b");
   	}
   	
   	// Cierra el archivo
   	fclose(archivo);
	
	switch(opcion)
	{	
		case 1:	/*RECURSO LIBRO*/
				
				/*
				char	ISBN[10];
				char 	titulo[60];
				char 	autors[60];
				char 	tema[60];
				char	anio_publicacion[4];
			//para articulo
				char	nombre_revista[60];
				char	paginas[10];
			// para audio y video
				char	formato[5];
				char	duracion[12];
			//para uri
				char	uri[200];
				char	idioma[12];
				*/
				
				//se abre el archivo
				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos
				    strcpy(general1.tipo,"libro");
				    
				    printf("\nIngrese ISBN: ");
				    fflush(stdin);
				    fgets(general1.ISBN, 10, stdin);
				    EliminarRetornoLinea(general1.ISBN);
				    
				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
				    
				    printf("\nIngrese el Anio de Pulicacion: ");
				    fflush(stdin);
				    fgets(general1.anio_publicacion, 5, stdin);
				    EliminarRetornoLinea(general1.anio_publicacion);

					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
					
				fclose(archivo);
			    
			    break;
			    
		case 2:	/*RECURSO MONOGRAFIA*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
					
					//Ingresar datos
				    strcpy(general1.tipo,"monografia");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
				
			    fclose(archivo);
			    
			    break;

		case 3:	/*RECURSO ARTICULO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos
					strcpy(general1.tipo,"articulo");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese Nombre de la revista: ");
				    fflush(stdin);
				    fgets(general1.nombre_revista, 60, stdin);
				    EliminarRetornoLinea(general1.nombre_revista);
	
				    printf("\nIngrese rango de paginas articulo: ");
				    fflush(stdin);
				    fgets(general1.paginas, 10, stdin);
				    EliminarRetornoLinea(general1.paginas);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);

			    fclose(archivo);
			    
			    break;

		case 4:	/*RECURSO AUDIO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos 
					strcpy(general1.tipo,"audio");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese formato de del audio: ");
				    fflush(stdin);
				    fgets(general1.formato, 5, stdin);
				    EliminarRetornoLinea(general1.formato);
	
				    printf("\nIngrese duracion del audio (hh:mm:ss): ");
				    fflush(stdin);
				    fgets(general1.duracion, 5, stdin);
				    EliminarRetornoLinea(general1.duracion);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
			    
			    fclose(archivo);
			    
			    break;

		case 5:	/*RECURSO VIDEO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos 
					strcpy(general1.tipo,"video");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese formato de del video: ");
				    fflush(stdin);
				    fgets(general1.formato, 5, stdin);
				    EliminarRetornoLinea(general1.formato);
	
				    printf("\nIngrese duracion del audio (hh:mm:ss): ");
				    fflush(stdin);
				    fgets(general1.duracion, 5, stdin);
				    EliminarRetornoLinea(general1.duracion);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
			    
			    fclose(archivo);
			    
			    break;

		case 6:	/*RECURSO URI*/
			    
				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos
					strcpy(general1.tipo,"uri");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese URI: ");
				    fflush(stdin);
				    fgets(general1.uri, 60, stdin);
				    EliminarRetornoLinea(general1.uri);
	
				    printf("\nIngrese idioma del recurso: ");
				    fflush(stdin);
				    fgets(general1.idioma, 60, stdin);
				    EliminarRetornoLinea(general1.idioma);
	
				    /*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
			    
			    fclose(archivo);
			    
			    break;
	}   
}

// Funcion para buscar en el archivo
void buscar (int opcion)
{
	char busq[60];
	
	int found=0;
	
	switch(opcion)
	{
		/*
			1.  Buscar por Autor.				\n");
 			2.  Buscar por Titulo.				\n");
			3.  Buscar por tema.
		*/
		
		case 1:	/*BUSCAR POR AUTOR*/
				
				int pos_puntero, pos_busqueda;
				char busq[20];
				
				
				//Ingresar termino a buscar
				printf("\n  Autor a Buscar: ");
				fflush(stdin);
				gets(busq);
				
				
				printf("\n =================================================");
				printf("\n\t\t\tLIBROS");
				printf("\n =================================================\n");
				printf("\n  (Autor, Isbn, Titulo, Tema, Anio Publicacion.)");
				printf("\n   --------------------------------------------\n\n");
				
				goto autor_libro;
			
			/*BUSCAR EN LIBROS POR AUTOR*/
			
				autor_libro:
					
					pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					archivo= fopen(nombrearchivo, "rb");
					//fseek(archivo, sizeof(general), SEEK_CUR);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "libro") == 0)
						{
							if(strcmp(general1.autors, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.autors);
								printf("%s, ",general1.ISBN);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.tema);
								printf("%s.\n",general1.anio_publicacion);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t      MONOGRAFIAS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema.)");
						printf("\n   ---------------------------------------------\n\n");
									
						//Cierro el archivo
						fclose(archivo);
									
						rewind(archivo);
									
					    goto autor_monografia;				
					}
					
					else
					{
						printf("   No hay registros en LIBROS para este autor.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto autor_monografia;
					}


			/*BUSCAR EN MONOGRAFIA POR AUTOR*/

		        autor_monografia:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "monografia") == 0)
						{
							if(strcmp(general1.autors, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.autors);
								printf("%s, ",general1.titulo);
								printf("%s.\n",general1.tema);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t       ARTICULOS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Nombre revista, Paginas.)");
						printf("\n   ---------------------------------------------\n\n");
						
						rewind(archivo);
						//Cierro el archivo
						fclose(archivo);
						
		        		goto autor_articulo;				
					}
					
					else
					{
						printf("   No hay registros en MONOGRAFIAS para este autor.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto autor_articulo;
					}
		        	
		        	

			/*BUSCAR EN ARTICULO POR AUTOR*/

		        autor_articulo:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "articulo") == 0)
						{
							if(strcmp(general1.autors, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.autors);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.nombre_revista);
								printf("%s\n",general1.paginas);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\tAUDIOS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto autor_audio;				
					}
					
					else
					{
						printf("   No hay registros en ARTICULOS para este autor.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto autor_audio;
					}
		        	


			/*BUSCAR EN AUDIO POR AUTOR*/

		        autor_audio:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "audio") == 0)
						{
							if(strcmp(general1.autors, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.autors);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.formato);
								printf("%s\n",general1.duracion);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\tVIDEOS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto autor_video;				
					}
					
					else
					{
					printf("   No hay registros en AUDIOS para este autor.\n");	
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto autor_video;
					}		        	


			/*BUSCAR EN VIDEO POR AUTOR*/

		        autor_video:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "video") == 0)
						{
							if(strcmp(general1.autors, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.autors);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.formato);
								printf("%s\n",general1.duracion);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\t URIS");
						printf("\n =================================================\n");
						printf("\n  (Autor, Titulo, Tema, Uri, Idioma.)");
						printf("\n   ---------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto autor_uri;				
					}
					
					else
					{
						printf("   No hay registros en VIDEOS para este autor.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto autor_uri;
					}
	
					

			/*BUSCAR EN URI POR AUTOR*/

		        autor_uri:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "uri") == 0)
						{
							if(strcmp(general1.autors, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.autors);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.uri);
								printf("%s\n",general1.idioma);
								
								found++;
						
							}
						}
					}
					
					if(found==0)
					{			
						printf("   No hay registros en URIS para este autor.\n");
						fclose(archivo);				
					}
					
					fclose(archivo);				
		        
		break;


		case 2:	/*BUSCAR POR TITULO*/

				//Ingresar termino a buscar
				printf("\n  Titulo a Buscar: ");
				fflush(stdin);
				gets(busq);
				
				
				printf("\n =================================================");
				printf("\n\t\t\tLIBROS");
				printf("\n =================================================\n");
				printf("\n  (Titulo, Isbn, Autor, Tema, Anio Publicacion.)");
				printf("\n   --------------------------------------------\n\n");
				
				goto titulo_libro;
			
			/*BUSCAR EN LIBROS POR TITULO*/
			
				titulo_libro:
					
					pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					archivo= fopen(nombrearchivo, "rb");
					//fseek(archivo, sizeof(general), SEEK_CUR);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "libro") == 0)
						{
							if(strcmp(general1.titulo, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.titulo);
								printf("%d, ",general1.ISBN);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.tema);
								printf("%d.\n",general1.anio_publicacion);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t      MONOGRAFIAS");
						printf("\n =================================================\n");
						printf("\n  (Titulo, Autor, Tema.)");
						printf("\n   ---------------------------------------------\n\n");
									
						//Cierro el archivo
						fclose(archivo);
									
						rewind(archivo);
									
					    goto titulo_monografia;				
					}
					
					else
					{
						printf("   No hay registros en LIBROS para este titulo.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto titulo_monografia;
					}


			/*BUSCAR EN MONOGRAFIA POR TITULO*/

		        titulo_monografia:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "monografia") == 0)
						{
							if(strcmp(general1.titulo, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s.\n",general1.tema);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t       ARTICULOS");
						printf("\n =================================================\n");
						printf("\n  (Titulo, Autor, Tema, Nombre revista, Paginas.)");
						printf("\n   ---------------------------------------------\n\n");
						
						rewind(archivo);
						//Cierro el archivo
						fclose(archivo);
						
		        		goto titulo_articulo;				
					}
					
					else
					{
						printf("   No hay registros en MONOGRAFIAS para este titulo.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto titulo_articulo;
					}
		        	
		        	

			/*BUSCAR EN ARTICULO POR TITULO*/

		        titulo_articulo:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "articulo") == 0)
						{
							if(strcmp(general1.titulo, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.nombre_revista);
								printf("%s\n",general1.paginas);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\tAUDIOS");
						printf("\n =================================================\n");
						printf("\n  (Titulo, Autor, Tema, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto titulo_audio;				
					}
					
					else
					{
						printf("   No hay registros en ARTICULOS para este titulo.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto titulo_audio;
					}
		        	


			/*BUSCAR EN AUDIO POR TITULO*/

		        titulo_audio:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "audio") == 0)
						{
							if(strcmp(general1.titulo, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.formato);
								printf("%s\n",general1.duracion);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\tVIDEOS");
						printf("\n =================================================\n");
						printf("\n  (Titulo, Autor, Tema, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto titulo_video;				
					}
					
					else
					{
					printf("   No hay registros en AUDIOS para este titulo.\n");	
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto titulo_video;
					}
		        	/*---------------------------------------------------------------------------------*/
		        	


			/*BUSCAR EN VIDEO POR TITULO*/

		        titulo_video:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "video") == 0)
						{
							if(strcmp(general1.titulo, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.formato);
								printf("%s\n",general1.duracion);
								
								found++;
						
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\t URIS");
						printf("\n =================================================\n");
						printf("\n  (Titulo, Autor, Tema, Uri, Idioma.)");
						printf("\n   ---------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto titulo_uri;				
					}
					
					else
					{
						printf("   No hay registros en VIDEOS para este titulo.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto titulo_uri;
					}
		        	
					

			/*BUSCAR EN URI POR TITULO*/

		        titulo_uri:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "uri") == 0)
						{
							if(strcmp(general1.titulo, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.tema);
								printf("%s, ",general1.uri);
								printf("%s\n",general1.idioma);
								
								found++;
						
							}
						}
					}
					
					if(found==0)
					{			
						printf("   No hay registros en URIS para este titulo.\n");
						fclose(archivo);				
					}
					
					fclose(archivo);				
		        
		break;

		case 3:	/*BUSCAR POR TEMA*/

		      //Ingresar termino a buscar
				printf("\n  Tema a Buscar: ");
				fflush(stdin);
				gets(busq);
				
				
				printf("\n =================================================");
				printf("\n\t\t\tLIBROS");
				printf("\n =================================================\n");
				printf("\n  (Tema, Isbn, Titulo, Autor, Anio Publicacion.)");
				printf("\n   --------------------------------------------\n\n");
				
				goto tema_libro;

			
			/*BUSCAR EN LIBROS POR TEMA*/
			
				tema_libro:
					
					pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					archivo= fopen(nombrearchivo, "rb");
					//fseek(archivo, sizeof(general), SEEK_CUR);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "libro") == 0)
						{
							if(strcmp(general1.tema, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.tema);
								printf("%d, ",general1.ISBN);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%d.\n",general1.anio_publicacion);
								
								found++;
							}
						
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t      MONOGRAFIAS");
						printf("\n =================================================\n");
						printf("\n  (Tema, Autor, Titulo.)");
						printf("\n   ---------------------------------------------\n\n");
									
						//Cierro el archivo
						fclose(archivo);
									
						rewind(archivo);
									
					    goto tema_monografia;				
					}
					
					else
					{
						printf("   No hay registros en LIBROS para este tema.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto tema_monografia;
					}


			/*BUSCAR EN MONOGRAFIA POR TEMA*/

		        tema_monografia:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "monografia") == 0)
						{
							if(strcmp(general1.tema, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.tema);
								printf("%s, ",general1.autors);
								printf("%s.\n",general1.titulo);
								
								found++;
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t       ARTICULOS");
						printf("\n =================================================\n");
						printf("\n  (Tema, Titulo, Autor, Nombre revista, Paginas.)");
						printf("\n   ---------------------------------------------\n\n");
						
						rewind(archivo);
						//Cierro el archivo
						fclose(archivo);
						
		        		goto tema_articulo;				
					}
					
					else
					{
						printf("   No hay registros en MONOGRAFIAS para este tema.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto tema_articulo;
					}
		        	
		        	

			/*BUSCAR EN ARTICULO POR TEMA*/

		        tema_articulo:

		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "articulo") == 0)
						{
							if(strcmp(general1.tema, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.tema);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.nombre_revista);
								printf("%s\n",general1.paginas);
								
								found++;
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\tAUDIOS");
						printf("\n =================================================\n");
						printf("\n  (Tema, Titulo, Autor, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto tema_audio;				
					}
					
					else
					{
						printf("   No hay registros en ARTICULOS para este tema.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto tema_audio;
					}
		        	


			/*BUSCAR EN AUDIO POR TEMA*/

		        tema_audio:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "audio") == 0)
						{
							if(strcmp(general1.tema, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.tema);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.formato);
								printf("%s\n",general1.duracion);
								
								found++;
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\tVIDEOS");
						printf("\n =================================================\n");
						printf("\n  (Tema, Titulo, Autor, Formato, Duracion.)");
						printf("\n   ---------------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto tema_video;				
					}
					
					else
					{
					printf("   No hay registros en AUDIOS para este tema.\n");	
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto tema_video;
					}
		        	

			/*BUSCAR EN VIDEO POR TEMA*/

		        tema_video:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "video") == 0)
						{
							if(strcmp(general1.tema, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.tema);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.formato);
								printf("%s\n",general1.duracion);
								
								found++;
							}
						}
					}
					
					if(found!=0)
					{			
						printf("\n =================================================");
						printf("\n\t\t\t URIS");
						printf("\n =================================================\n");
						printf("\n  (Tema, Titulo, Autor, Uri, Idioma.)");
						printf("\n   ---------------------------------\n\n");
						
						//Cierro el archivo
						fclose(archivo);
						
		        		goto tema_uri;				
					}
					
					else
					{
						printf("   No hay registros en VIDEOS para este tema.\n");
									
						//Cierro el archivo
						fclose(archivo);
									
					    goto tema_uri;
					}
		        	
					

			/*BUSCAR EN URI POR TEMA*/

		        tema_uri:
		        	
		        	pos_puntero=0;
					pos_busqueda=0;
					found=0;
					
					//abrimos el archivo
					archivo= fopen(nombrearchivo, "rb");
					
					// coloca el puntero en la primera posicion del archivo
					rewind(archivo);
					
					while (1)
					{
						fread(&general1,sizeof(general),1,archivo);
						
						if(feof(archivo))
						{
							break;
						}
						
						if(strcmp(general1.tipo, "uri") == 0)
						{
							if(strcmp(general1.tema, busq) == 0)
							{
								pos_puntero = ftell(archivo);
								pos_busqueda = pos_puntero - (sizeof(general1));
								
								fseek(archivo, pos_busqueda, SEEK_CUR);
								
								printf("   %s, ",general1.tema);
								printf("%s, ",general1.titulo);
								printf("%s, ",general1.autors);
								printf("%s, ",general1.uri);
								printf("%s\n",general1.idioma);
								
								found++;
							}
						}
					}
					
					if(found==0)
					{			
						printf("   No hay registros en URIS para este tema.\n");
						fclose(archivo);				
					}
					
					fclose(archivo);				
		        
		break; 

		
		defalut:
			printf("Ha ingresado un numero no valido\n");
			break;

  }

}


//Funcion con la cual se modfican los recuros, cualquiera de ellos.
void modificar_recurso (int opcion)
{	
	int pos_puntero, pos_busqueda;

	char busq[60];
	
	int found=0;
	
	switch(opcion)
	{	
		case 1:	/*RECURSO LIBRO*/
				
				pos_puntero=0;
				pos_busqueda=0;
				found=0;
				
				//Ingresar termino a buscar
				printf("\n  ISBN a Modificar: ");
				fflush(stdin);
				gets(busq);
				
				
				printf("\n =================================================");
				printf("\n\t\t\tLIBROS");
				printf("\n =================================================\n");
				printf("\n  (Autor, Isbn, Titulo, Tema, Anio Publicacion.)");
				printf("\n   --------------------------------------------\n\n");
					
				//abrimos el archivo a modificar
				archivo= fopen(nombrearchivo, "rb+");
				
				//abrimos el archivo temporal
				temp= fopen(nombretemp, "rb+");
				
				// si el fichero no existe, lo crea.
				if(!temp)
			   	{
			   		temp = fopen(nombretemp, "w+b");
			   	}
					
				// coloca el puntero en la primera posicion del archivo
				rewind(archivo);
					
				while (1)
				{
					fread(&general1,sizeof(general),1,archivo);
					
					if(feof(archivo))
					{
						break;
					}
					
					if(strcmp(general1.ISBN, busq) == 0)
					{
						pos_puntero = ftell(archivo);
						pos_busqueda = pos_puntero - (sizeof(general1));
						
						fseek(archivo, pos_busqueda, SEEK_CUR);
						
					// imprimir
						printf("   %s, ",general1.autors);
						printf("%s, ",general1.ISBN);
						printf("%s, ",general1.titulo);
						printf("%s, ",general1.tema);
						printf("%s.\n",general1.anio_publicacion);
						
					//Ingresar nuevos datos
					    strcpy(general1.tipo,"libro");
					    
					    printf("\nIngrese ISBN: ");
					    fflush(stdin);
					    fgets(general1.ISBN, 10, stdin);
					    EliminarRetornoLinea(general1.ISBN);
					    
					    printf("\ningrese el Titulo: ");
					    fflush(stdin);
					    fgets(general1.titulo, 60, stdin);
					    EliminarRetornoLinea(general1.titulo);
					    
					    printf("\nIngrese el Autor(es): ");
					    fflush(stdin);
					    fgets(general1.autors, 60, stdin);
					    EliminarRetornoLinea(general1.autors);
					    
					    printf("\nIngrese Tema: ");
					    fflush(stdin);
					    fgets(general1.tema, 60, stdin);
					    EliminarRetornoLinea(general1.tema);
					    
					    printf("\nIngrese el Anio de Pulicacion: ");
					    fflush(stdin);
					    fgets(general1.anio_publicacion, 5, stdin);
					    EliminarRetornoLinea(general1.anio_publicacion);
	
						
						/*FORMA CON FSEEK*/
						fseek(archivo, 0, SEEK_END);
	   					fwrite(&general1, sizeof(general), 1, temp);
						
						found++;
					}
				}
				
				fclose(archivo);
				fclose(temp);
					
				if(found==0)
				{			
					printf("   No hay registros en LIBROS para este ISBN.\n");
					fclose(archivo);				
				}
				else
				{
					//abrimos el archivo a modificar
					archivo= fopen(nombrearchivo, "wb+");
				
					//abrimos el archivo temporal
					temp= fopen(nombretemp, "rb+");
					
					while(1)
					{
						fread(&general1,sizeof(general),1,temp);
					
						if(feof(temp))
						{
							break;
						}
						fseek(archivo, 0, SEEK_END);
   						fwrite(&general1, sizeof(general), 1, archivo);
					}
				}
					
				fclose(archivo);
				fclose(temp);
			    
		break;
			    
		case 2:	/*RECURSO MONOGRAFIA*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
					
					//Ingresar datos
				    strcpy(general1.tipo,"monografia");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
				
			    fclose(archivo);
			    
			    break;

		case 3:	/*RECURSO ARTICULO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos
					strcpy(general1.tipo,"articulo");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese Nombre de la revista: ");
				    fflush(stdin);
				    fgets(general1.nombre_revista, 60, stdin);
				    EliminarRetornoLinea(general1.nombre_revista);
	
				    printf("\nIngrese rango de paginas articulo: ");
				    fflush(stdin);
				    fgets(general1.paginas, 10, stdin);
				    EliminarRetornoLinea(general1.paginas);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);

			    fclose(archivo);
			    
			    break;

		case 4:	/*RECURSO AUDIO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos 
					strcpy(general1.tipo,"audio");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese formato de del audio: ");
				    fflush(stdin);
				    fgets(general1.formato, 5, stdin);
				    EliminarRetornoLinea(general1.formato);
	
				    printf("\nIngrese duracion del audio (hh:mm:ss): ");
				    fflush(stdin);
				    fgets(general1.duracion, 5, stdin);
				    EliminarRetornoLinea(general1.duracion);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
			    
			    fclose(archivo);
			    
			    break;

		case 5:	/*RECURSO VIDEO*/

				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos 
					strcpy(general1.tipo,"video");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese formato de del video: ");
				    fflush(stdin);
				    fgets(general1.formato, 5, stdin);
				    EliminarRetornoLinea(general1.formato);
	
				    printf("\nIngrese duracion del audio (hh:mm:ss): ");
				    fflush(stdin);
				    fgets(general1.duracion, 5, stdin);
				    EliminarRetornoLinea(general1.duracion);
					
					/*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
			    
			    fclose(archivo);
			    
			    break;

		case 6:	/*RECURSO URI*/
			    
				archivo= fopen(nombrearchivo, "ab"); //abro el archivo
	
				    //Ingresar datos
					strcpy(general1.tipo,"uri");

				    printf("\ningrese el Titulo: ");
				    fflush(stdin);
				    fgets(general1.titulo, 60, stdin);
				    EliminarRetornoLinea(general1.titulo);
				    
				    printf("\nIngrese el Autor(es): ");
				    fflush(stdin);
				    fgets(general1.autors, 60, stdin);
				    EliminarRetornoLinea(general1.autors);
				    
				    printf("\nIngrese Tema: ");
				    fflush(stdin);
				    fgets(general1.tema, 60, stdin);
				    EliminarRetornoLinea(general1.tema);
	
				    printf("\nIngrese URI: ");
				    fflush(stdin);
				    fgets(general1.uri, 60, stdin);
				    EliminarRetornoLinea(general1.uri);
	
				    printf("\nIngrese idioma del recurso: ");
				    fflush(stdin);
				    fgets(general1.idioma, 60, stdin);
				    EliminarRetornoLinea(general1.idioma);
	
				    /*FORMA CON FSEEK*/
					fseek(archivo, 0, SEEK_END);
   					fwrite(&general1, sizeof(general), 1, archivo);
			    
			    fclose(archivo);
			    
			    break;
	}   
}



/* MAIN */
int main (void)
{
	int opc=-1, opc_busqueda=-1, opc_admin=-1, opc_config=-1, opc_config_tipos=-1, opc_config_metadatos=-1, opc_admin_agrear=-1, opc_admin_modificar=-1;
	
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
								menu_admin_modificar:
								system ("cls"); 
        
			        			menu_admon_recursos_agregar();
								printf ("Ingrese la opcion seleccionada:  "); 
			        			scanf ("%d",&opc_admin_agrear);

			        			switch(opc_admin_agrear)
								{
									case 1:	// Crear recurso LIBRO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_modificar;
											break;

									case 2:	// Crear recurso MONOGRAFIA
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_modificar;
											break;

									case 3:	// Crear recurso ARTICULO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_modificar;
											break;

									case 4:	// Crear recurso AUDIO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_modificar;
											break;
											
									case 5:	// Crear recurso VIDEO
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_modificar;
											break;
											
									case 6:	// Crear recurso URI
											crear_recurso(opc_admin_agrear);
											getch();
											goto menu_admin_modificar;
											break;
												
									case 0: 
											goto menu_admin;
											break;
								}
			        						
						break;
						
						case 2:
								menu_admin_modificarr:
								system ("cls"); 
        
			        			menu_admon_recursos_modificar();
								printf ("Ingrese la opcion seleccionada:  "); 
			        			scanf ("%d",&opc_admin_modificar);

			        			switch(opc_admin_modificar)
								{
									case 1:	// modificar recurso LIBRO
											modificar_recurso(opc_admin_modificar);
											getch();
											goto menu_admin_modificar;
											break;

									case 2:	// modificar recurso MONOGRAFIA
											modificar_recurso(opc_admin_modificar);
											getch();
											goto menu_admin_modificar;
											break;

									case 3:	// modificar recurso ARTICULO
											modificar_recurso(opc_admin_modificar);
											getch();
											goto menu_admin_modificar;
											break;

									case 4:	// modificar recurso AUDIO
											modificar_recurso(opc_admin_modificar);
											getch();
											goto menu_admin_modificar;
											break;
											
									case 5:	// modificar recurso VIDEO
											modificar_recurso(opc_admin_modificar);
											getch();
											goto menu_admin_modificar;
											break;
											
									case 6:	// modificar recurso URI
											modificar_recurso(opc_admin_modificar);
											getch();
											goto menu_admin_modificar;
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
