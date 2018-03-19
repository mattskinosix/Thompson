/*
 * operazioni_file.c
 *
 *  Created on: 08 dic 2016
 *      Author: Matteo
 */

#include<stdio.h>
typedef enum{FALSO,VERO}BOOL;
BOOL separatore_f(char carattere){
	BOOL bool=0;
	bool =((carattere==' ') || (carattere=='\t') || (carattere==',') || (carattere==';') || (carattere=='.') || (carattere==':'));
	return bool;
}



void lettura_parola()
{
int contatore_parole=0,contatore_caratteri=0,contatore_righe=0;
BOOL separatore,fine_parola;
char buffer;
FILE *matteo;
matteo=fopen("file.txt", "r");
if(matteo){
	buffer=fgetc(matteo);
	while(buffer!= EOF) {
		fine_parola=VERO;

			while(buffer!='\n'){
				contatore_caratteri++;
				separatore = separatore_f(buffer);
				printf("%c",buffer);
			if (separatore && !fine_parola){
				fine_parola=VERO;
				contatore_parole++;
			}
			else{
				if (!separatore){
					fine_parola=FALSO;
				}
				}
			buffer =fgetc(matteo);
			}
			separatore = separatore_f(buffer);
				if (separatore && !fine_parola) contatore_parole++;
				else if (!separatore)fine_parola=FALSO;
				buffer=fgetc(matteo);
				contatore_righe++;
}
}
else{
	printf("Errore nel file!!");
}
 printf("Le parole sono:  %d",contatore_parole);
 printf("\n");
 printf("i caratteri sono:  %d",contatore_caratteri);
 printf("\n");
 printf("le righe sono  %d",contatore_righe);
 printf("\n");
fclose(matteo);
}


