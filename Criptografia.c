// Gabriel Lopes Silva gabriel18.lopes@gmail.com trabalho de Decodificacao lab 2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char chave[] = "G89yk1";
void Criptografar();
void back();

int main(){

    char select;

for(;;){

    printf("\n 1-Criptografar\n 2-Descriptografar\n 3-Sair\n ");
        scanf("%c",&select);

    switch(select){

        case '1':

            Criptografar();

            break;
        case '2':

          back();
            break;
        case '3':
            return 0;

            break;

    }

}

}

void Criptografar(){


    FILE *arquivo_de_leitura,*arquivo_de_escrita;

    char nome_do_arquivo[80],aux;
    int valor_em_asc,codigo,i = 0;

    __fpurge(stdin);

    printf("\n Digite o nome do arquivo: ");
    gets(nome_do_arquivo);

    arquivo_de_escrita=fopen("codic.crp","w+");

    if((arquivo_de_leitura=fopen(nome_do_arquivo,"r"))==NULL){

        printf("\n Erro \n Seu arquivo pode estar em branco ou nao existir!\n");

    }

    else{

      while((aux=fgetc(arquivo_de_leitura))!=EOF){

            valor_em_asc=aux;//pega o valor do caracter em ascII

            if(i==6){
                i=0;//retorma o comeco da chave
            }

            codigo = chave[i]*valor_em_asc;
            fprintf(arquivo_de_escrita," %d ",codigo);

        }
    }

    fclose(arquivo_de_escrita);
    fclose(arquivo_de_leitura);

}
void back(){


    FILE *arquivo_de_leitura,*arquivo_de_decodificado;

    char aux;
    int valor_em_asc,codigo,i = 0;

    if((arquivo_de_leitura=fopen("codic.crp","r"))==NULL){

    printf("\n Erro \n");

    }
    else

    if((arquivo_de_decodificado=fopen("descodificado.txt","w+"))==NULL){

        printf("\n Erro \n");

    }


    else{

      for(;;){

            fscanf(arquivo_de_leitura," %d ",&codigo);

            if(codigo == NULL){

                break;

            }

            if(i==6){
                i=0;//retorma o comeco da chave
            }

            valor_em_asc=codigo/chave[i];
            aux=valor_em_asc;

            fprintf(arquivo_de_decodificado,"%c",aux);
            codigo = NULL;
        }
    }

    fclose(arquivo_de_decodificado);
    fclose(arquivo_de_leitura);
    __fpurge(stdin);
}

























