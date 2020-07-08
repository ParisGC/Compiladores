/*
IMPLEMENTACIONES DE LA LIBRERIA DEL TAD PILA DINÁMICA (TADPilaDin.h)
VERSIÓN: 1.3

DESCRIPCIÓN: TAD pila o stack.
 gcc TADPilaDin.c -c
*/

//LIBRERAS
#include <stdio.h>
#include <stdlib.h>
#include "pilaautomata.h"

//DEFINICIÓN DE FUNCIONES

/*
void Initialize(pilaa *s);
Descripción: Inicializar pilaa (Iniciar una pilaa para su uso)
Recibe: int *s (Referencia a la pilaa "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pilaa y s tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pilaa *s)
{
	s->tope=NULL; //(*s).tope=NULL;
	return;
}

/*
void Push(pilaa *s, aut e);
Descripción: Empilaar (Introducir un aut a la pilaa)
Recibe: int *s (Referencia a la pilaa "s" a operar), aut e (aut a introducir en la pilaa)
Devuelve:
Observaciones: El usuario a creado una pilaa y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si el malloc() pudo o no apartar memoria, se idealiza que siempre funciona bien 
y no se acaba la memoria
*/
void Push(pilaa *s, aut e)
{
	nodo *aux;
	aux=malloc(sizeof(nodo));
	
	//Si no hay más memoria dinámica por alguna razón
	if(aux==NULL)
	{
		printf("\nERROR-Push(&s,e): Desbordamiento de la pilaa, no hay más memoria disponible");
		exit(1);
	}
	
	//Si se creo el nuevo nodo insertar al aut
	(*aux).e=e;  //aux->e=e;
	aux->abajo=s->tope;
	s->tope=aux;
	return;
}


/*
void Pop(pilaa *s);
Descripción: Desempilaar (Extraer un aut de la pilaa)
Recibe: int *s (Referencia a la pilaa "s" a operar)
Devuelve: aut (aut e extraido de la pilaa)
Observaciones: El usuario a creado una pilaa y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pilaa esta vacia antes de desempilaar (causa error desempilaar si esta esta vacía), 
tampoco se valida si free() pudo o no liberar la memoria, se idealiza que siempre funciona bien 
*/
aut Pop (pilaa *s)
{
	aut r;
	nodo *aux;
	
	//Si el tope es NULL, se intenta Pop de pilaa vacia 
	if(s->tope==NULL)
	{
		printf("\nERROR-e=Pop(&s): Subdesbordamiento de la pilaa, no hay auts en la pilaa");
		exit(1);
	}
	
	r=s->tope->e;
	aux=s->tope;
	s->tope=s->tope->abajo;
	free(aux);
	return r;	
}

/*
boolean Empty(pilaa *s);
Descripción: //Vacia (Preguntar si la pilaa esta vacia)
Recibe: int *s (Referencia a la pilaa "s" a operar)
Devuelve: boolean (TRUE o FALSE según sea el caso)
Observaciones: El usuario a creado una pilaa y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pilaa *s)
{
	boolean r;
	if(s->tope==NULL)
	{
		r=TRUE;
	}	
	else
	{
		r=FALSE;
	}
	return r;	
}

/*
aut Top(pilaa *s);
Descripción: Tope (Obtener el "aut" del tope de la pilaa si extraerlo de la pilaa)
Recibe: int *s (Referencia a la pilaa "s" a operar)
Devuelve: aut (aut del tope de la pilaa)
Observaciones: El usuario a creado una pilaa y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pilaa esta vacia antes de consultar al elemnto del tope (causa error si esta esta vacía).
*/
aut Top(pilaa *s)
{
	//Si el tope es NULL, se intenta Top de pla vacia 
	if(s->tope==NULL)
	{
		printf("\nERROR-e=Top(&s): Subdesbordamiento de la pilaa, no hay auts en la pilaa");
		exit(1);
	}
	
	return s->tope->e;
}

/*
int Size(pilaa *s);
Descripción: Tamaño de la pilaa (Obtener el número de auts en la pilaa)
Recibe: int *s (Referencia a la pilaa "s" a operar)
Devuelve: int (Tamaño de la pilaa 0->Vacia, 1->1 aut, 2->2 auts, ...)
Observaciones: El usuario a creado una pilaa y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pilaa *s)
{
	nodo *aux;
	int tam_pilaa=0;
	aux=s->tope;
	if(aux!=NULL)
	{
		tam_pilaa++;
		while(aux->abajo!=NULL)
		{
			tam_pilaa++;
			aux=aux->abajo;
		}
	}	
	return tam_pilaa;
}

/*
void Destroy(pilaa *s);
Descripción: Elimina pilaa (Borra a todos los auts en a la pilaa de memoria)
Recibe: int *s (Referencia a la pilaa "s" a operar)
Devuelve: 
Observaciones: El usuario a creado una pilaa y s tiene la referencia a ella, s ya ha sido inicializada.
*/
void Destroy(pilaa *s)
{
	nodo *aux;
	if(s->tope!=NULL)
	{
		while(s->tope!=NULL)
		{				
			aux=s->tope->abajo;
			free(s->tope);
			s->tope=aux;
		}		
	}
	return;
}
