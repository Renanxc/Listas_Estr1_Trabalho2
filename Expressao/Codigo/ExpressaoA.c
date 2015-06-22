/**************************************
* Trabalho 2 de Estrutura de Dados I
* Curso de Sistemas da informac�o
* Aluno: Renan Xavier Calmon - matricula: 0050010824
* Analise de express�o aritmetica
***************************************/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include "Pilha-lista.h"

int calcula(char* exp);
int executa(Pilha* num,Pilha* op);

char* expressao(){                             //fun��o pega o que � escrito e manda para uma string
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
	printf("\n**************************************\n* Trabalho 2 de Estrutura de Dados I\n* Curso de Sistemas da informac�o");
	printf("\n* Aluno: Renan Xavier Calmon - matricula: 0050010824\n* Analise de express�o aritmetica\n***************************************");
	printf("\nOl�, meu nome eh Renan,\n");
	do{
		printf("Entre com a express�o para que eu resolva:");
		fflush(stdin);
		exp = expressao();             //fun��o para obter uma express�o
		//printf("\n%s\n",exp);
		result = calcula(exp);
		printf("Obrigado, o resultado da sua express�o �: %d\n",result);
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
	Pilha *num,*op;                             //� criada uma pilha para obter os n�meros e a outra para operadores
	num = pilha_cria();
	op = pilha_cria();
	while(exp[n]!='\0'){                        //Enquanto cada caracter for diferente do final da string ser� verificado se � um n�mero ou n�o
		if(exp[n]==')')
			result = executa(num, op);
		else
			if(isdigit(exp[n]))
				pilha_push(num,exp[n]-48);      //Char de 1~9 na tabela ASCII equivalem � +48 de seu valor int
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
	v2=pilha_pop(num);                    //Valores da express�o s�o desempilhados para que seja feita a conta
	v1=pilha_pop(num);
	operador=pilha_popOP(op);
	pilha_popOP(op);
		
	switch(operador){                     //Dependendo do operador uma apera��o diferente e feita
		case '+':result = v1+v2; break;
		case '-':result = v1-v2; break;
		case '*':result = v1*v2; break;
		case '/':result = v1/v2; break;
		default:;
	}
		
	pilha_push(num,result);              //Novo valor adicionado a Pilha
	return result;
}
