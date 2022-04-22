#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vetor[6],i,qtd,naop,x1,c,j1,j2,vez,fim=0,soma,qtd=6;
char pos;

int verifica();
void jogador1 ();
void jogador2 ();
int fimdojogo();

int main() {
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("Feito por Tommy \n");
	printf("Como jogar.\n Existem 6 numeros aleatorios de 0 a 10. O objetivo é encontrar eles e falar em que posição está \n");
	
	
	for(c=0;c<6;c++){
		vetor[c]=rand() % 10;
	}
	
	printf("\n");
    c=0;
	while(1){
		if(vez%2==0){
			jogador1();
			for(c=0;c<3;c++){
                if(x1>-1 && x1<11){
                    verifica();
                    j1=j1+1;
                    vez = vez+1;
                    }
            	if(naop>3){
                	printf("Não encontrado. \n");
                	break;
                }
                if(x1>10 || x1<-1){
            		printf("Numero maior/menor do valor . \n");
            		break;
				}
            }
        	fimdojogo();
        	if(fim>0){
        		break;
			}
    }
        if(vez%2!=0){
			jogador2();
			for(c=3;c<6;c++){
				if(x1>-1 && x1<11){
					verifica(pos);
					j2=j2+1;
					vez = vez+1;
					}
				if(naop>3){
            		printf("Não encontrado. \n");
            		break;
            		
            }
            	if(x1>10 || x1<-1){
            		printf("Numero maior/menor do valor . \n");
            		break;
				}
			
			}
			fimdojogo();
			if(fim>0){
        		break;
			}
			}
	}
	return 0;
    }
void jogador1 () {

	printf("\n (Jogador 1) Digite o numero de 0 a 10 : ");
	scanf("%d", &x1);
	printf(" (Jogador 1) Digite o sentido: D - Direita e E - Esquerda: ");
	scanf("%s", &pos);
}

void jogador2 (){

	printf("\n (Jogador 2) Digite o numero de 0 a 10 : ");
	scanf("%d", &x1);
	printf(" (Jogador 2) Digite o sentido: D - Direita e E - Esquerda: ");
	scanf("%s", &pos);
}

int verifica(){
	naop=0;
	if(pos=='E'){
		for(i=0;i<3;i++){
			if(vetor[i]==x1){
				vetor[i]=-1;
				qtd = qtd-1;
				printf(" Acertou. Faltam %d numeros. \n", qtd);
				naop=naop-1;
			}
			else{
				naop=naop+1;
			}
        }
	}

	else if(pos=='D'){
		for(i=3;i<6;i++){
			if(vetor[i]==x1){
				vetor[i]=-1;
				qtd = qtd-1;
				printf("Acertou. Faltam %d numeros. \n", qtd);
				naop=naop-1;
			}
			else{
				naop=naop+1;
			}
        }
	}

}
int fimdojogo(){
	soma=0;
	for(i=0;i<6;i++){
		if(vetor[i]==-1){
			soma=soma+1;
		}
	}
	if(soma==6){
        if(j1>j2){
			printf("Jogador 1 é o vencedor! \n");
			fim=1;
			}
		else if(j1==j2){
			printf("Empate! \n");
			fim=2;
			}
		else{
			printf("Jogador 2 é o vencedor! \n");
			fim=3;
        }
    }
}




