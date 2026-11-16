#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Contato{
   char nome [51];
   char cpf[12];
   int valor ;
   struct Contato *prox;
};
typedef struct Contato Pessoa;

void inserir(Pessoa *cabeca, int valor, char *cpf);
//void excluir();
//void editar();
void liberarEspaco(Pessoa *cabeca);
void imprime(Pessoa *cabeca);
 int contador = 0;

int main(){
Pessoa cabeca;
cabeca.prox = NULL;
char cpf_ref[] = "123456789-1";

inserir(&cabeca,15,cpf_ref);
//inserir(&cabeca,15);
//inserir(&cabeca,15);
//inserir(&cabeca,15);

imprime(&cabeca);

}

void inserir(Pessoa *cabeca, int valor, char *cpf){
   Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));

   novo -> prox = NULL;
   novo -> valor = valor;
   novo -> cpf = cpf;


   Pessoa *atual = cabeca;

   while(atual ->prox !=NULL){
      atual = atual -> prox ;
   }
   atual -> prox = novo;
         contador++;


}

void imprime(Pessoa *cabeca){
   Pessoa *atual = cabeca -> prox;

   while (atual != NULL){
      printf("Item %3d\n", atual -> valor);
      printf("cpf %s \n", atual -> cpf);
      atual = atual -> prox;
   }
}


void libera(Pessoa* cabeca){
   Pessoa *atual = cabeca -> prox;
   Pessoa *liberado;

while(atual !=NULL){
   liberado = atual;
   atual = atual -> prox;
free(liberado);
   }

}