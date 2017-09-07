
#include<stdio.h>
#include<stdlib.h>

    /// 0-Oradea      1- Zerind           2-Arad           3-Timisoara       4-Lugoj       5-Melhadia
    /// 6-Drobeta         7-Sibiu       8-Rimnicu Vilcea      9-Craiova    10- Fagaras         11-Pitesti   12-Giurgiu
    ///13-Bucharest        14-Neamt       15-Iasi        16-Vaslui      17-Urziceni        18-Hirsova     19-Eforie



int main(){
    int m[20][20];// distancia entre uma cidade e outra
    int i,j;
    int v[20];//distancia entre a cidade ea capital
    int aux,aux1,aux2,aux3,ultima;

    v[0]=380;
    v[1]=374;
    v[2]=366;
    v[3]=329;
    v[4]=244;
    v[5]=241;
    v[6]=242;
    v[7]=253;
    v[8]=193;
    v[9]=160;
    v[10]=176;
    v[11]=100;
    v[12]=77;
    v[13]=0;
    v[14]=234;
    v[15]=226;
    v[16]=199;
    v[17]=80;
    v[18]=151;
    v[19]=161;

    /// zera todas as posicoes
   for(i=0;i<20;i++){
        for(j=0;j<20;j++){

        m[i][j]=0;

        }

    }

    m[1][0]=71;
    m[0][1]=71;

    m[0][7]= 151 ;
    m[7][0]= 151 ;

    m[1][2]=  75  ;
    m[2][1]=  75  ;

    m[2][3]= 118 ;
    m[3][2]=  118;

    m[2][7]=140;
    m[7][2]=140;

    m[3][4]=111;
    m[4][3]=111;

    m[4][5]=70;
    m[5][4]=70;

    m[5][6]=75;
    m[6][5]=75;

    m[6][9]=120;
    m[9][6]=120;

    m[7][8]= 80;
    m[8][7]= 80;

    m[7][10]=99;
    m[10][7]=99;

    m[8][11]=97;
    m[11][8]=97;

    m[9][11]=138;
    m[11][9]=138;

    m[10][13]=211;
    m[13][10]=211;

    m[11][13]=101;
    m[13][11]=101;

    m[12][13]=90;
    m[13][12]=90;

    m[13][17]=85;
    m[17][13]=85;

    ///o resto e irrelevante para tal busca
// mostra a matriz
  /*  for(i=0;i<20;i++){
        for(j=0;j<20;j++){

        printf(" %d",m[j][i]);

        }
    printf("\n");
    }
*/
/// vizinho mais proximo
printf(" \n ////////Vizinho mais proximo\\\\\\\\\\\\\\\\\\\\\ \n");
    aux = 2;//arand
    ultima = 2;
for(;;){

    aux1 = 0;//o tamanho de aux ate a cidade
    for(i = 0;i<20;i++){
        if(m[aux][i]!=0 && i!= ultima){
                if(aux1==0){
                    aux1=m[aux][i];
                    aux2=aux;//guarda a cidade em que esta procurando o vizinho
                    aux3=i;//a cidade para onde vai ir

                }
                else
                if(m[aux][i]<aux1){

                aux1=m[aux][i];
                aux3=i;

                }
    }

}
printf("\n %d \n ",aux3);
aux=aux3;
ultima=aux2;//ultima cidade visitada

if(aux==13){
break;
}

}



/// Subida da encosta pela trilha mais íngreme
printf(" \n ///////  SEPTMI  \\\\\\\\\\ \n");
    aux = 2;//arand
    ultima = 2;
    aux2=0;


for(;;){

    aux3 = 0;
    for(i = 0;i<20;i++){
        if(m[aux][i]!=0 && i!= ultima){
                if(aux3==0){
                    aux2=aux;//guarda a cidade em que esta procurando o vizinho
                    aux3=i;//a cidade para onde vai ir

                }
                else
                if(v[aux3]>v[i]){
                aux3=i;

                }
    }

}
printf("\n %d \n ",aux3);
aux=aux3;
ultima=aux2;//ultima cidade visitada

if(aux==13){
break;
}

}

/// A*
printf(" \n ///////  A*  \\\\\\\\\\ \n");
    aux = 2;//arand
    ultima = 2;
    aux2=0;


for(;;){

    aux3 = 0;//o tamanho de aux ate a cidade
    for(i = 0;i<20;i++){
        if(m[aux][i]!=0 && i!= ultima){
                if(aux3==0){
                aux3=i;
                aux2=aux;
                aux1=m[aux][i]+v[i];//distancia da cidade i ate o objetivo, mais a distancia para chegar na cidade i

                }
                else
                if(aux1>(m[aux][i]+v[i])){
                aux3=i;

                }
    }

}
printf("\n %d \n ",aux3);
aux=aux3;
ultima=aux2;//ultima cidade visitada

if(aux==13){
break;
}

}



    return 0;
}
