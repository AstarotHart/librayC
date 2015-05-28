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
     printf ("   M E N U     P R I N C I P A L   \n\n\n");
     printf ("	1.  Buscar recurso.					\n");
     printf ("	2.  Administrar Recursos.				\n");
     printf ("	3.  Configuracion Biblioteca.			\n");
     printf ("	0.  Salir   \n");
}


// Menu Busqueda
void menu_busqueda (void)
{
     printf ("		       BUSQUEDA  		   \n\n\n");
     printf ("	1.  Buscar recurso.					\n");
     printf ("	2.  Administrar Recursos.				\n");
     printf ("	3.  Configuracion Biblioteca.			\n");
     printf ("	0.  Salir   \n");
}

// Menu Administrar Recursos
void menu_admon_recursos(void)
{
     printf ("		ADMINISTRAR RECURSOS		\n\n\n");
     printf ("	1.  Buscar recurso.					\n");
     printf ("	2.  Administrar Recursos.				\n");
     printf ("	3.  Configuracion Biblioteca.			\n");
     printf ("	0.  Salir   \n");
}

// Menu Configuracion Biblioteca
void menu_config (void)
{
     printf ("		      CONFIGURACION 		\n\n\n");
     printf ("	1.  Buscar recurso.					\n");
     printf ("	2.  Administrar Recursos.				\n");
     printf ("	3.  Configuracion Biblioteca.			\n");
     printf ("	0.  Salir   \n");
}





/* MAIN */
int main (void)
{
	int opc=-1, opc_busq=-1, opc_admin=-1, opc_config=-1;
	
	do {
        system ("cls"); 
        
        opciones();                                    // se utiliza la librería stdlib.h, sirve para limpiar la pantalla
        printf ("Ingrese la opción seleccionada:  "); // usa la libreria stdio.h 
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
						default:
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
						
						default:
					}*/
					
					break;
					
			case 3:
				
					system ("cls"); 
        
        			menu_config();
					printf ("Ingrese la opción seleccionada:  "); 
        			scanf ("%d",&opc_config);
				
					//Menu Configuracion Biblioteca
					/*switch(opc_config) 
					{
						default:
					}*/
					
					break;
									

		}
	} while (opc != 0);
	
	getch();
}

