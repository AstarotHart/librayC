#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


/* Variables Globales*/



/* Prototipos*/



/* FUNCIONES */

// Menu Principal
void opciones (void)
{
     printf ("		    MENU PRINCIPAL         \n\n\n");
     printf (" 1.  Buscar recurso.					\n");
     printf (" 2.  Administrar Recursos.				\n");
     printf (" 3.  Configuracion Biblioteca.			\n");
     printf (" 0.  Salir   \n\n");
}


// Menu Busqueda
void menu_busqueda (void)
{
     printf ("		       BUSQUEDA  		   \n\n\n");
     printf (" 1.  Buscar por Autor.				\n");
     printf (" 2.  Buscar por Titulo.				\n");
     printf (" 3.  Buscar por tema.				\n");
     printf (" 0.  Volver   \n\n");
}

// Menu Administrar Recursos
void menu_admon_recursos(void)
{
     printf ("		 ADMINISTRAR RECURSOS		\n\n\n");
     printf (" 1.  Agregar recursos.				\n");
     printf (" 2.  Modificar datos recursos.		\n");
     printf (" 3.  Borrar un recurso.				\n");
     printf (" 0.  Volver   \n\n");
}

// Menu Configuracion Biblioteca
void menu_config (void)
{
     printf ("		     CONFIGURACION  		\n\n\n");
     printf (" 1.  Administrar tipos.				\n");
     printf (" 2.  Administrar Metadatos.			\n");
     printf (" 0.  Volver   \n\n");
}

// Menu Configuracion Biblioteca - Administrar tipos
void menu_config_tipos (void)
{
     printf ("	    CONFIGURACION RECURSOS 		\n\n\n");
     printf (" 1.  Crear recurso.				\n");
     printf (" 2.  Modificar recurso.			\n");
     printf (" 3.  Borrar recurso.				\n");
     printf (" 0.  Volver   \n\n");
}

// Menu Configuracion Biblioteca - Administrar Metadatos
void menu_config_metadatos (void)
{
     printf ("	    CONFIGURACION METADATOS 	\n\n\n");
     printf (" 1.  Crear metadatos.				\n");
     printf (" 2.  Modificar metadatos.			\n");
     printf (" 3.  Borrar metadatos.			\n");
     printf (" 0.  Volver   \n\n");
}





/* MAIN */
int main (void)
{
	int opc=-1, opc_busq=-1, opc_admin=-1, opc_config=-1, opc_config_tipos=-1, opc_config_metadatos=-1;
	
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
				
					system ("cls"); 
        
        			menu_admon_recursos();
					printf ("Ingrese la opción seleccionada:  "); 
        			scanf ("%d",&opc_admin);
					
					//Menu Administracion Recursos
					/*switch(opc_admin) 
					{
						case 1:
						
					}*/
					
					break;
					
			case 3:
				
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
								break;
								
						case 2:
								system ("cls");
								
								menu_config_metadatos();
								
								printf ("Ingrese la opción seleccionada:  "); 
        						scanf ("%d",&opc_config_metadatos);
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

