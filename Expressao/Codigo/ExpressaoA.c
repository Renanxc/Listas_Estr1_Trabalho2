/**************************************
* Trabalho 2 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Analise de expressão aritmetica
***************************************/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include "Pilha-lista.h"

int calcula(char* exp);
int executa(Pilha* num,Pilha* op);

char* expressao(){                             //função pega o que é escrito e manda para uma string
   char* exp;
   int n, ch;
   
   n = 0;
   while ((ch = getc( stdin)) != '\n') {      //ch recebe um valor enquanto o que for digitado for diferente de uma quebra de linha (enter)
      exp[n++] = ch;
   }
   exp[n] = '\0';                             //finaliza a string
   return exp;
}

int main(){
	int result;
	char ch, verif;
	char* exp;
	
	setlocale(LC_ALL, "Portuguese");
	printf("\n**************************************\n* Trabalho 2 de Estrutura de Dados I\n* Curso de Sistemas da informacão");
	printf("\n* Aluno: Renan Xavier Calmon - matricula: 0050010824\n* Analise de expressão aritmetica\n***************************************");
	printf("\nOlá, meu nome eh Renan,\n");
	do{
		printf("Entre com a expressão para que eu resolva:");
		fflush(stdin);
		exp = expressao();             //função para obter uma expressão
		//printf("\n%s\n",exp);
		result = calcula(exp);
		printf("Obrigado, o resultado da sua expressão é: %d\n",result);
		do{
			printf("Deseja continuar (s/n)?");
			fflush(stdin);
			scanf("%c",&verif);
			verif= toupper(verif);
		}while(verif!='S' && verif!='N');
	}while(verif=='S');
	printf("Fim !!!");
	system("pause");
	return 0;
}

int calcula(char* exp){
	int n=0,valor, result;
	Pilha *num,*op;                             //É criada uma pilha para obter os números e a outra para operadores
	num = pilha_cria();
	op = pilha_cria();
	while(exp[n]!='\0'){                        //Enquanto cada caracter for diferente do final da string será verificado se é um número ou não
		if(exp[n]==')')
			result = executa(num, op);
		else
			if(isdigit(exp[n]))
				pilha_push(num,exp[n]-48);      //Char de 1~9 na tabela ASCII equivalem à +48 de seu valor int
			else
				pilha_pushOP(op,exp[n]);
		n++;
	}
	pilha_libera(num);
	pilha_libera(op);
	return result;
}
int executa(Pilha* num, Pilha* op){
	int v1,v2,result;
	char operador;
	
	/*pilha_imprime(num);
	printf("\n");
	pilha_imprimeOP(op);
	printf("\n");
	*/	
	v2=pilha_pop(num);                    //Valores da expressão são desempilhados para que seja feita a conta
	v1=pilha_pop(num);
	operador=pilha_popOP(op);
	pilha_popOP(op);
		
	switch(operador){                     //Dependendo do operador uma aperação diferente e feita
		case '+':result = v1+v2; break;
		case '-':result = v1-v2; break;
		case '*':result = v1*v2; break;
		case '/':result = v1/v2; break;
		default:;
	}
		
	pilha_push(num,result);              //Novo valor adicionado a Pilha
	return result;
}
