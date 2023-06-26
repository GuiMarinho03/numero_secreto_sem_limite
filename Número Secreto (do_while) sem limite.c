#include <stdio.h>
#include <locale.h> //setlocale (colocar acento)
#include <stdlib.h> //system("cls") limpar tela
#include <time.h> 	// Biblioteca para Time(0).


int main() {
	setlocale(LC_ALL, "portuguese");
	
	printf  ("**************************************\n");
	printf  ("Bem vindo ao nosso jogo de adivinhação\n");
	printf  ("**************************************\n");
	
	int segundos = time(0);
	srand(segundos);
	
 	int num_grande = rand();
	
	int num_sec = num_grande % 100;
	int chute;
	int tentativas = 1;
	double pontos = 1000;
	
	while(1)
	{
		printf 	("\nTentativa %d\n", tentativas);
		printf  ("Qual o seu chute? ");
		scanf	("%d", &chute);
		printf  ("Seu chute foi: %d\n", chute);
		
		if	(chute < 0){
			printf ("Você não pode chutar números negativos!\n");
			printf ("***************************************\n");
			continue;
		}
				
		
		int acertou = (chute == num_sec);
		int maior = (chute > num_sec);
		
	   	if (acertou){
		   	printf  ("Parabéns! Você acertou!\n"); 
			printf  ("Jogue de novo, você é um bom jogador!\n");
			break;
		}
		else
		{
			if (maior){
				printf ("Seu chute foi maior que o número secreto\n");
				printf  ("*****************************************\n");
			} else {
				printf ("Seu chute foi menor que o número secreto\n");   	
				printf  ("*****************************************\n");
			}
			
			tentativas++;	
			
			double pontosperdidos = abs(chute - num_sec) / (double)2; // convertendo para DOUBLE.
			pontos = pontos - pontosperdidos;
		}
	}
	printf  ("********************************\n");
	printf 	("*Fim de Jogo!                  *\n");
	printf	("*Você acertou em %d tentativas! *\n", tentativas);
	printf  ("*Total de pontos: %.2f         *\n", pontos);	
	printf  ("********************************\n");
}
