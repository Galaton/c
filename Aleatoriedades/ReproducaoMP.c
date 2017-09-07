	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int main(){

        int ep;

		char abrir[1050];
		char mp[10] = "mplayer ";
		char sub[6] = "-sub ";
        char aux[500],aux2[500],aux3[500];
        char pasta[500];

        //Pasta onde a lista se encontra
        printf("Pasta:");
        scanf(" %[^\n]s", pasta);

        //__fpurge(stdin);
        printf("Qual ep:");
        scanf("%i",&ep);

        while(ep<30){
            //convertendo o episodeo para string

            sprintf(aux, "%d", ep);
            //formando o nome do arquivo para abrir 'nome da pasta''nome do episodeo'
            strcat(aux2,pasta);
            strcat(aux2,"/'");
            strcat(aux2,aux);
            strcat(aux2,".mkv");
            strcat(aux2,"' ");

            //formando o nome da legenda
            strcat(aux3,pasta);
            strcat(aux3,"/'");
            strcat(aux3,aux);
            strcat(aux3,".str");
            strcat(aux3,"' ");

            //mplayer 'caminho ate o ep' -sub 'legenda'
            strcpy(abrir,"");
            strcat(abrir,mp);
            strcat(abrir,aux2);
            strcat(abrir,"-sub ");
            strcat(abrir,aux3);
            strcat(abrir,"-alang eng");

            system(abrir);
            ep++;
            strcpy(aux2,"");
            strcpy(aux3,"");
            strcpy(aux,"");

        }


		return 0;
	}
