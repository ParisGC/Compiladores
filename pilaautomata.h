/*
LIBRERIA: Cabecera de el TAD PILA DINÁMICA

*/
//DEFINICIONES DE CONSTANTES
#define TRUE	1
#define FALSE	0

//DEFINICIONES DE TIPOS DE DATO

//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un aut (Se modela con una estructura "aut")
typedef struct aut
{
	//Variables de la estructura "aut" (El usuario puede modificar)
	char * estados;
	char * alfabeto;
	int  inicial;
	int final;
	char ** tran;
	//***
	//***
}aut;

//Definir un nodo que será utilizado para almacenar una posición de la pila (Nodo), lo que incluira a un aut y a un apuntador al siguiente nodo
typedef struct nodo
{
	//aut a almacenar en cada nodo de la pila	
	aut e;	
	//Apuntador al aut de debajo (Requerido por ser una implementación dinámica -Usuario: No modificar)
	struct nodo *abajo;
}nodo;

//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "aut")
typedef struct pilaa
{		
	nodo *tope;
}pilaa;

//DECLARACIÓN DE FUNCIONES
void Initialize(pilaa *s);			//Inicializar pilaa (Iniciar una pilaa para su uso)
void Push(pilaa *s, aut e);		//Empilaar (Introducir un aut a la pilaa)
aut Pop (pilaa *s);				//Desempilaar (Extraer un aut de la pilaa)
boolean Empty(pilaa *s);				//Vacia (Preguntar si la pilaa esta vacia)
aut Top(pilaa *s);				//Tope (Obtener el "aut" del tope de la pilaa si extraerlo de la pilaa)
int Size(pilaa *s);					//Tamaño de la pilaa (Obtener el número de auts en la pilaa)
void Destroy(pilaa *s);				//Elimina pila (Borra a todos los auts y a la pila de memoria)
