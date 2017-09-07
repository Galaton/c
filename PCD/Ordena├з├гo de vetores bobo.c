#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

void gerador(int a);
void leitor(int a);
void bubble(int tam);
void selection_sort(int tam) ;
void insertionSortC(int tam);

int main(){

int quant,saida,a1;


    printf("Quantos numeros gerar?");
    scanf("%d",&quant);
    gerador(quant);


    printf("\n Deseja ver os valores?\n 1-sim 0-nao :");
    scanf("%d",&a1);
    if(a1==1){
    leitor(quant);
    }

 do{
    printf("\n \nQual algoritimo deseja utilizar para ordenar?\n 1-Bubble Sort\n 2-Selection Sort\n 3-Insertion Sort\n");
    scanf("%d",&a1);

    switch(a1){

case 1:
        bubble(quant);
    break;

case 2:
     selection_sort(quant);
    break;

case 3:
    insertionSortC(quant);
    break;


    }
    printf("\n Deseja utilizar outro aulgoritimo de ordenacao?\n 1-sim 0-nao");
    scanf("%d",&saida);
}while(saida!=0);


return 0;
}

void gerador(int a){
 FILE *arq;
arq=fopen("banc.txt","w+");
int i,j;

for(i=0;i<a;i++){

    j=rand()%a;
    fprintf(arq,"%d ",j);


}


fclose(arq);
}
void leitor(int a){
 FILE *arq;
arq=fopen("banc.txt","r+");
int i,k=0,vet[a];



for(i=0;i<a;i++){


    fscanf(arq,"%d ",&vet[i]);


}
printf("\n");
for(i=0;i<a;i++){


    printf("%d ",vet[i]);

    k++;
   if(k==20){
        printf("\n ");
        k=0;
    }


}
fclose(arq);
}
void bubble(int tam){


   FILE *arq;
   FILE *bb;
    bb=fopen("bu.txt","w+");
    arq=fopen("banc.txt","r+");

int i,j,vet[tam],aux;

int inicio,finall,tempo;


/// le o vetor
for(i=0;i<tam;i++){


    fscanf(arq,"%d ",&vet[i]);

}


  inicio = GetTickCount();
  ///algoritimo do bubble
  for(i=tam-1; i >= 1; i--) {

    for(j=0; j < i ; j++) {

      if(vet[j]>vet[j+1]) {

        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;

        }
      }
    }
    finall = GetTickCount();

///grava o vetor
for(i=0;i<tam;i++){


    fprintf(bb,"%d ",vet[i]);


}
fclose(arq);
fclose(bb);

tempo=finall-inicio;

printf("\n \n Tempo em ms foi : %d \n",tempo);
}
void selection_sort(int tam) {
  FILE *arq;
  arq=fopen("banc.txt","r+");
  FILE *ss;
  ss=fopen("ss.txt","w+");

  int i, j, min, aux,num[tam];
    int inicio,finall,tempo;

  ///le o vetor
  for(i=0;i<tam;i++){


    fscanf(arq," %d ",&num[i]);

}
  inicio = GetTickCount();
  ///algoritimo do ssort
  for (i = 0; i < (tam-1); i++)
   {
    min = i;
    for (j = (i+1); j < tam; j++) {
      if(num[j] < num[min])
        min = j;
    }
    if (i != min) {
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
   finall = GetTickCount();

        ///salva
  for(i=0;i<tam;i++){

    fprintf(ss," %d ",num[i]);

}
fclose(arq);
fclose(ss);

tempo=finall-inicio;

printf("\n \n Tempo em ms foi : %d \n",tempo);

}
void insertionSortC(int tam) {

  FILE *arq;
  arq=fopen("banc.txt","r+");
  FILE *is;
  is=fopen("is.txt","w+");

      int i, j, tmp,array[tam];
    int inicio,finall,tempo;

      ///le o vetor
  for(i=0;i<tam;i++){


    fscanf(arq," %d ",&array[i]);

}

  inicio = GetTickCount();
      ///algoritimo isort
      for (i = 1; i < tam; i++) {
            j = i;
            while (j > 0 && array[j - 1] > array[j]) {
                  tmp = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = tmp;
                  j--;
            }
      }
 finall = GetTickCount();

///salvando
for(i=0;i<tam;i++){


    fprintf(is," %d ", array[i]);


}

fclose(arq);
fclose(is);

tempo=finall-inicio;

printf("\n \n Tempo em ms foi : %d \n",tempo);

}
