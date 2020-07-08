#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Pilaautomata.c"
pilaa s2;
void automata (char * cad );
aut * transiscion ( char a);
aut * estrella (aut * a);
aut * kleen (aut * a);
aut * concatenacion (aut * a,aut * b);
aut * disyuncion (aut * a,aut * b);
void main()
{
	aut a;
	char cad[]="ab|c.d+.";//(a|b)cd+
	Initialize(&s2);
	automata (cad);
	a=Pop(&s2);
}
void  automata( char * cad )
{
	int i;
	for  (i=0;cad[i]!='\0';i++)
	{
		if (cad[i]>='a' | cad[i]<='z')
		{
			Push(&s2,transicion(cad[i]));
		}
		else if (cad[i]=='*')
			{
				
			}
			else if (cad[i]=='+')
				{
					
				}
				else if (cad[i]=='|')
					{
						
					}
					else// Cad[i]=='.'
					{
						
					}	
	}
}
aut transiscion ( char a)
{
	
}
aut estrella (aut * a)
{
	
}
aut kleen (aut * a)
{
	
}
aut concatenacion (aut * a,aut * b)
{
	
}
aut disyuncion (aut * a,aut * b)
{
	
}
