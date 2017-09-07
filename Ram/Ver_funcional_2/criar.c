#include"criar.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long unsigned int index_cache,index_ram;

typedef struct memoria_virtual{

    int endereco_fisico;
    int tag;//tamb[em chamado de endereco virtual
    int bit_de_validade;
    int bit_de_referencia;// usado no lru

}mv;


typedef struct ram{

    int index;
    char *bloco;

}ram;



typedef struct via {

    int tag;
    char *bloco;
    int bit_de_validade; //quando criar a cache zerar todos

} via;


typedef struct cache {
    struct via *numero_de_vias;
    int index;
} cache;


cache *SRAM ;
ram *DRAM ;
mv *tlb;
mv *memo_virt;

void criar_ram(int numero_de_palavras){
 printf("\n..... Criando DRAM .....\n");
int i,j,aux0;
DRAM=malloc(sizeof(ram)*numero_de_palavras*index_ram*50);

char alf[11]={'0','1','2','3','4','5','6','7','8','9','/0'};
char aux;

for(i=0;i<index_ram;i++){

    DRAM[i].bloco=malloc(numero_de_palavras);

    DRAM[i].index=i;

    for(j=0;j<numero_de_palavras;j++){
    aux0=rand()%11;
    aux=alf[aux0];
    DRAM[i].bloco[j]=aux;

    }

}
    printf("\n ..... DRAM criada com sucesso .....\n");
}

void visualizacao_completa_ram(){


int i;

for(i=0;i<index_ram;i++){

    printf("\n \t Index:%d\n Palavra:",DRAM[i].index);
    puts(DRAM[i].bloco);


}


}

void criar_cache(int numero_de_palavras,int numero_vias) {
 printf("\n..... Criando SRAM .....\n");

        int i,j;

        SRAM=malloc(sizeof(via)*numero_vias*numero_de_palavras*index_cache);//aloca memoria para criar a cache

        for(i=0;i<index_cache;i++){

        SRAM[i].index=i;
        SRAM[i].numero_de_vias=malloc(numero_vias*numero_de_palavras*sizeof(via));// aloca memoria para as vias

        for(j=0;j<numero_vias;j++){

        SRAM[i].numero_de_vias[j].bit_de_validade=0;


        SRAM[i].numero_de_vias[j].bloco=malloc(numero_de_palavras);
        }


        }
printf("\n ..... SRAM criada com sucesso .....\n");

}


void visualizacao_completa_cache(int numero_vias){

int i,j;

        for(i=0;i<index_cache;i++){

        printf("\n \t Index:%d",SRAM[i].index);
        for(j=0;j<numero_vias;j++){

        printf("\n \t Bit de validade:%d \t TAG:%d",SRAM[i].numero_de_vias[j].bit_de_validade,SRAM[i].numero_de_vias[j].tag);


        }

        }


}
void visualizacao_faixa_de_endereco_cache(int numero_vias){



      int i,j,aux;

        printf("\n Digite o index desejado:");
        scanf("%d",&aux);

        for(i=0;i<index_cache;i++){

        if(SRAM[i].index==aux){
        for(j=0;j<numero_vias;j++){

              printf("\n \t Bit de validade:%d \t TAG:%d \t DADO:",SRAM[i].numero_de_vias[j].bit_de_validade,SRAM[i].numero_de_vias[j].tag);
                puts(SRAM[i].numero_de_vias[j].bloco);

        }
   }
}

}
void  cindex(int numero_conjuntos, float capacidade_de_dados_ram,int numero_de_palavras){

  index_cache= numero_conjuntos;
  index_ram= capacidade_de_dados_ram/(numero_de_palavras);


}

void criar_tld(){


        printf("\n..... Criando TLB.....\n");
    int i;

    tlb=malloc(sizeof(mv)*index_cache);

    for(i=0;i<index_cache;i++){

        tlb[i].bit_de_validade=0;
        tlb[i].tag=i;
        tlb[i].bit_de_referencia=0;

    }

        printf("\n..... TLB criada com sucesso.....\n");
}
void criar_memoria_virtual(){
        printf("\n .....Criando memoria virtual....\n ");
    int i;
    memo_virt=malloc(sizeof(mv)*index_ram);

    for(i=0;i<index_ram;i++){

    memo_virt[i].bit_de_referencia=1;
    memo_virt[i].bit_de_validade=1;
    memo_virt[i].tag=i;
    memo_virt[i].endereco_fisico=DRAM[i].index;


    }

        printf("\n .....Memoria virtual criada....\n ");
}
