#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


/* ----------------------- ESTRUCTURAS ----------------------- */

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
	char	uri[300];
	char	idioma[120];
};

/* PROTOTIPOS */


/* VARIABLES GLOBALES */
libro libro1;
monografia monografia1;
articulo articulo1;

FILE* archivo= NULL;
char* nombrearchivo = "Library.txt";

/* ========================= FUNCIONES ======================= */


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

// Ingresar LIBRO
void crear_recurso_libro (void)
{	
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
    
    //imprimo los valores
    //printf("ISBN: %d\nTITULO: %s \nAUTOR: %s \nTEMA: %s \nA. PUBLIC: %d",libro1.ISBN, libro1.titulo, libro1.autors, libro1.tema, libro1.anio_publicacion);
    
    // Escribir datos en el archivo
    fprintf(archivo,"libro|");
    fprintf(archivo,"%d|",libro1.ISBN);
    fprintf(archivo,"%s|",libro1.titulo);
    fprintf(archivo,"%s|",libro1.autors);
    fprintf(archivo,"%s|",libro1.tema);
    fprintf(archivo,"%d.\n",libro1.anio_publicacion);
    
    fclose(archivo);
}

// Ingresar MONOGRAFIA
void crear_recurso_monografia (void)
{	

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
    fprintf(archivo,"monografia|");
    fprintf(archivo,"%s|",monografia1.titulo);
    fprintf(archivo,"%s|",monografia1.autors);
    fprintf(archivo,"%s.\n",monografia1.tema);
    
    fclose(archivo);
}

// Ingresar ARTICULO
void crear_recurso_articulo (void)
{	

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

    printf("Ingrese rango de paginas articulo: ");
    fflush(stdin);
    gets(articulo1.paginas);

    // Escribir datos en el archivo
    fprintf(archivo,"monografia|");
    fprintf(archivo,"%s|",articulo1.titulo);
    fprintf(archivo,"%s|",articulo1.autors);
    fprintf(archivo,"%s|",articulo1.tema);
    fprintf(archivo,"%s|",articulo1.nombre_revista);
    fprintf(archivo,"%s.\n",articulo1.paginas);
    
    fclose(archivo);
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
					/*switch(opc_busq) 
					{
						
					}*/
					
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
									case 1:
											crear_recurso_libro ();
											getch();
											break;

									case 2:
											crear_recurso_monografia ();
											getch();
											break;

									case 3:
											crear_recurso_articulo ();
											getch();
											break;

									/*case 4:
											crear_recurso_libro ();
											getch();
											break;*/
												
									case 0: 
											goto menu_admin_agregar;
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

