#include"criar.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){


            int largura_de_endereco = 32;
        float capacidade_de_dados_cache = 128, capacidade_de_dados_ram = 256;
    int numero_de_palavras = 8, numero_conjuntos = 2048, numero_vias = 8;

capacidade_de_dados_cache=capacidade_de_dados_cache*1024;//quantidade em bytes
capacidade_de_dados_ram=capacidade_de_dados_ram*1024;

 cindex( numero_conjuntos,capacidade_de_dados_ram, numero_de_palavras);

 criar_ram( numero_de_palavras);

 visualizacao_completa_ram();

 criar_cache( numero_de_palavras, numero_vias);

 visualizacao_completa_cache( numero_vias);

 visualizacao_faixa_de_endereco_cache( numero_vias);

 criar_tld();

 criar_memoria_virtual();
}
