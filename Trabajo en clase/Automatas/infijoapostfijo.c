#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilacadena.c"
char * agregar_caracter (char * cad,char c, int posicion, int tam);
char * concatenacion (char* cad);	
void infijoaposfijo( char * cad);
int finparentesis (char* cad);
char * agregarnulo (char * cad);
int ncerraduras( char * cad);

pila s;	
	
void main()
{
	int i,n;
	char * ER;
	elemento e;
	
	//Ingreso del dato
		printf("Ingresa tu expresion regular:\t");
		//pide la cadena a evaluar
		//crea el espacio y pone el contador en 1
		ER=(char *)malloc(sizeof(char));
		n=1;
		//mientras no se agregue un espacio (En la condición se obtiene el dato)
		while((ER[n-1]=getchar())!='\n')
		{
			//se amplia en un caracter el arreglo
			ER=(char *)realloc(ER,(n+1)*sizeof(char));
			//se agrega uno al contador
			n++;
		}
		//se agrega el caracternulo para que se vuelva cadena
		ER[n-1]='\0';
	//fin del ingreso del dato
	
	
	//Se le agregan las concatenacones
	ER=concatenacion(ER);
	ER=agregarnulo (ER);
	puts(ER);
	//Se inicializan las pilas
	Initialize(&s);
	//se convierte de infijo a postfijo
	infijoaposfijo(ER);
	
	e=Pop(&s);
	ER=e.c;
	
	puts(ER);
	printf("%d\n",strlen(ER));


}
//Esta funcion pasa una expresion regular de infijo a posfijo
void  infijoaposfijo ( char * cad )
{
	pila pcaux,poaux;
	elemento e, eaux;
	int i,j,taux,naux;
	
	Initialize(&pcaux);
	Initialize(&poaux);
	
	for(i=0;cad[i]!='\0';i++)
	{
		if (cad[i]<='z'&& cad[i]>='a')
		{
			if (Empty(&pcaux)==1 )//no hay concatenaciones pendientes
			{
				naux=ncerraduras(&cad[i]);
				e.c=(char *)malloc((2+naux)*sizeof(char));
				e.c[0]=cad[i];
				for(j=0;j<naux;j++)
				{
					i++;
					e.c[j+1]=cad[i];
				}
				e.c[1+naux]='\0';
				Push(&s,e);
			}
			else //Si hay concatenaciones pendientes
			{
				naux=ncerraduras(&cad[i]);
				e.c=(char *)malloc((2+naux)*sizeof(char));
				e.c[0]=cad[i];
				for(j=0;j<naux;j++)
				{
					i++;
					e.c[j+1]=cad[i];
				}
				e.c[1+naux]='\0';
				
				e=Pop(&s);
				e.c=(char *)realloc(e.c,(strlen(e.c)+2+strlen(eaux.c))*sizeof(char));
				e.c=strcat(e.c,eaux.c);
				e.c=strcat(e.c,".");
				Pop(&pcaux);
				Push(&s,e);
			}
		}	
		else if (cad[i]=='(')
			{
				infijoaposfijo(&cad[i+1]);
				i+=finparentesis(&cad[i]);
				
				eaux=Pop(&s);
				naux=ncerraduras(&cad[i]);
				taux=strlen(eaux.c);
				eaux.c=(char *)realloc(eaux.c,(taux+1+naux)*sizeof(char));
				for(j=0;j<naux;j++)
				{
					i++;
					eaux.c[taux+j]=cad[i];
				}
				eaux.c[taux+naux];
				Push(&s,eaux);
				
				if (Empty(&pcaux)==0 )//si hay concatenaciones pendientes
				{
					eaux=Pop(&s);
					e=Pop(&s);
					e.c=(char *)realloc(e.c,(strlen(e.c)+2+strlen(eaux.c))*sizeof(char));
					e.c=strcat(e.c,eaux.c);
					e.c=strcat(e.c,".");
					Pop(&pcaux);
					Push(&s,e);
				}
				
			}
/*
			else if (cad[i]=='+')
				{
					e=Pop(&s);
					e.c=(char *)realloc(e.c,(strlen(e.c)+2)*sizeof(char));
					strcat(e.c,"+");
					Push(&s,e);
				}
				else if (cad[i]=='*')
					{
						e=Pop(&s);
						e.c=(char *)realloc(e.c,(strlen(e.c)+2)*sizeof(char));
						strcat(e.c,"*");
						Push(&s,e);
					}
					*/
					else if (cad[i]=='.')
						{
							e.c=".";
							Push(&pcaux,e);
						}
						else // if (cad[i]=='|')
						{
							if(Empty(&poaux)==1)//si esta vacia
							{
								e.c="|";
								Push(&poaux,e);
							}
							else
							{
								eaux=Pop(&s);
								e=Pop(&s);
								e.c=(char *)realloc(e.c,(strlen(e.c)+2+strlen(eaux.c))*sizeof(char));
								e.c=strcat(e.c,eaux.c);
								e.c=strcat(e.c,"|");
								Push(&s,e);
							}
						}
	}
	if(Empty(&poaux)==0)//si no esta vacia y queda un signo de |
	{
		eaux=Pop(&s);
		e=Pop(&s);
		e.c=(char *)realloc(e.c,(strlen(e.c)+2+strlen(eaux.c))*sizeof(char));
		e.c=strcat(e.c,eaux.c);
		e.c=strcat(e.c,"|");
		Push(&s,e);
	}
	Destroy(&pcaux);
	Destroy(&poaux);
	return;
}
//Esta funcion agrega las concatenaciones como operacion
char * concatenacion (char * cad)
{
    int i;
    for (i=0;cad[i]!='\0';i++)
    {
    	if (((cad[i]<='z'&& cad[i]>='a') || cad[i]==')' || cad[i]=='+' || cad[i]=='*' ) &&
		((cad[i+1]<='z'&& cad[i+1]>='a') || cad[i+1]=='('))
    	{
    		agregar_caracter(cad,'.',i+1,strlen(cad));
		}
	}
	return cad;
}
//Esta funcion agrega un caracter en la localizacion cad[i] y recorre el resto de la cadena
char * agregar_caracter (char * cad,char c, int posicion, int tam)
{
	char anterior,nuevo;
	int i;
	//genera el espacio
	cad=(char *)realloc(cad,(strlen(cad)+2)*sizeof(char));
	
	nuevo=c;
	
	for (i=posicion;i<tam;i++)
	{
		anterior=cad[i];//guardamos la letra	
		cad[i]=nuevo;//agregamos la nueva letra
		nuevo=anterior;//Se prepara para introducir la siguiente		
	}
	cad[i]=nuevo;
	cad[i+1]='\0';
	return cad;
}
//Esta funcion nos dice cuanto tenemos que saltar para llegar a l fin del parentesis
int finparentesis (char* cad)
{
	int i,n;
	for (i=1,n=1;n!=0;i++)
	{
		if (cad[i]=='(')
		{
			n++;
		}else if (cad[i]==')')
		{
			n--;
		}
	}
	return i-1;
}
//Esta funcion agrega caracateres nulo antes de ')' EJ ab)--->ab'\0')
char * agregarnulo (char * cad)
{
	int i;
	for(i=0;cad[i]!='\0';i++)
	{
		if (cad[i]==')')
		{
			agregar_caracter (cad,'\0',i,strlen(cad));
		}
	}
	return cad;
}
//Esta funcion devuelve el numero de cerraduras
int ncerraduras( char * cad)
{
	int n,i;
	for(i=1,n=0;cad[i]=='+' || cad[i]=='*';i++)
	{
		n++;
	}
	return n;
}
