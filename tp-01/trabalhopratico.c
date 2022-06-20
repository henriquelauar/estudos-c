// Samuel Gonçalves Reis 21.2.4092 turma 32
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>


//tabela
#define TAB_HOR "\u2501"
#define TAB_VER "\u2503" 
#define TAB_TL  "\u250F" 
#define TAB_ML  "\u2523" 
#define TAB_BL  "\u2517" 
#define TAB_TJ  "\u2533" 
#define TAB_MJ  "\u254B" 
#define TAB_BJ  "\u253B" 
#define TAB_TR  "\u2513" 
#define TAB_MR  "\u252B" 
#define TAB_BR  "\u251B" 
//cores
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"

#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET

int menu(){//mostra o menu e retorna a opção escolhida pelo usuário
	char *retornomenu;
	retornomenu=malloc(20*sizeof(char));
	printf(BOLD(BLUE("\n---------------------Bem vindo ao Quebra-Cabeças---------------------\n\n")));
    	printf("0.Sair do jogo\n");
    	printf("1.Começar um novo jogo\n");
    	printf("2.Continuar o jogo atual\n");
    	printf("3.Continuar um jogo salvo\n");
    	printf("4.Instruções do jogo\n\n\n");
    	printf("\nEscolha a opção (digite 'sair' em qualquer lugar para sair do jogo): ");
    	fgets(retornomenu,20,stdin);
    	retornomenu[strlen(retornomenu)-1]='\0';
    	int opcao=(int)retornomenu[0]-48;
    	while(strlen(retornomenu)>1 || opcao<0 || opcao>4){
    			if(strcmp(retornomenu,"sair")==0)
	    			return 0;
			printf(RED("Comando invalido!"));
			printf("Escolha a opção (digite 'sair' em qualquer lugar para sair do jogo): ");
			fgets(retornomenu,20,stdin);	
			retornomenu[strlen(retornomenu)-1]='\0';
			opcao=(int)retornomenu[0]-48;
		    	}
	free(retornomenu);
    	return opcao;
 }   
    
void instrucoes(){
	printf("\n-------Digite o numero da peça para movimenta-la\n ");
    	printf("\n-------Para salvar digite 'salvar nome.txt' \n");
    	printf("\n-------Para mostrar o menu digite voltar \n");
    	printf("\n-------Digite sair em qualquer lugar para fechar o jogo \n\n");
 } 	  
   
void tabuleiroNovo(int **A){//cria um tabuleiro com o jogo correto
	int k=1;
	for(int i=0; i<3;i++){
		for(int j=0;j<3;j++){
		    A[i][j]=k;
		    k++;	
	}      
    }
    A[2][2]=0;
}

int verificaJogo(int **A){//função cria um tabuleiro com o jogo correto e o compara com o jogo atual para verificar se são iguais 
	int k=1,**B;
	B=malloc(3*sizeof(int*));
	for(int i=0; i<3;i++)
		B[i]=malloc(3*sizeof(int));
	for(int i=0; i<3;i++){
		for(int j=0;j<3;j++){
		    B[i][j]=k;
		    k++;	
		}      
    }
    	B[2][2]=0;
    	for(int i=0; i<3;i++){
		for(int j=0;j<3;j++)
		    if(B[i][j] != A[i][j]){
		    	for(int i=0;i<3;i++)
    				free(B[i]);
    			free(B);
		    	return 0;//caso o usuario ainda nao ganhou o jogo	
		    	}	     
    }
    	for(int i=0;i<3;i++)
    		free(B[i]);
    	free(B);
    	return 1;//caso o usuario ganhou o jogo
}

void imprimir(int **A){
    	for (int i=0;i<3;i++){    		
    		if(i==0)
    			printf("                                "TAB_TL TAB_HOR TAB_TJ TAB_HOR TAB_TJ TAB_HOR TAB_TR"\n");
    		else if(i==1)
    			printf("                                "TAB_ML TAB_HOR TAB_MJ TAB_HOR TAB_MJ TAB_HOR TAB_MR "\n");
		else
			printf("                                "TAB_ML TAB_HOR TAB_MJ TAB_HOR TAB_MJ TAB_HOR TAB_MR "\n");
		printf("                                ");
    		for (int j=0;j<3;j++){    			
    			if(A[i][j]==0)
    				printf(TAB_VER " ");
    			else 
    				printf(TAB_VER "%d",A[i][j]);		    				
    			}
    		printf(TAB_VER"\n");   		
    		}
    	printf("                                "TAB_BL TAB_HOR TAB_BJ TAB_HOR TAB_BJ TAB_HOR TAB_BR "\n");
}
 		
void embaralhar(int **A, int dificuldade){
//função é baseada na posiçao vazia(zero), considera o zero em todas posições e de acordo com quantos valores pode trocar sorteia um numero para decidir com qual irá trocar,por exemplo se o zero estiver na linha zero e coluna zero ele so pode trocar com o elemento de baixo e da sua direita, então é sorteado um numero entre 0 e 1, onde a representação do numero é feita usando o sentido horário(o primeiro elemento é o no "horario mais cedo"). A variavel que auxilia a troca é criada fora do looping pois ela sera importante na proxima embaralhada, pois para não trocar duas peças em uma embaralhada e na proxima embaralhada trocar as mesmas peças é necessário comparar a peça que está sendo trocada com a ultima peça trocada, caso iguais o while faz a geração de um novo numero aleatorio, até sortear um numero que represente uma peça que não foi trocada na iteraão anterior.
	srand(time(NULL));
	int vezes,colunazero,linhazero,aux=-1,random;
	if(dificuldade == 1)
		vezes=20;		
	else if(dificuldade == 2)
		vezes=40;	
	else
		vezes=80;
	for(int k=0; k<vezes;k++){
		for(int i=0; i< 3;i++)
			for(int j=0;j<3;j++)
				if(A[i][j] == 0){
					linhazero=i;
					colunazero=j;
				}
		if(linhazero==0 && colunazero==0){
			random= rand() % 2;
			int troca=0;
			while(troca == 0){
				if(random == 0 && aux != A[0][1]){
					aux=A[0][1];
					A[0][1]=A[0][0];
					A[0][0]=aux;
					troca=1;
					
					
				}
				else if(random == 1 && aux != A[1][0]){
					aux=A[1][0];
					A[1][0]=A[0][0];
					A[0][0]=aux;
					troca=1;
					
				}
				else
					random=rand()%2;	
				}			
		}
		else if(linhazero==0 && colunazero==1){
			random= rand() % 3;
			int troca=0;
			while(troca == 0){
				if(random == 0 && aux != A[0][2]){
					aux=A[0][2];
					A[0][2]=A[0][1];
					A[0][1]=aux;
					troca=1;
					
				}
				else if(random == 1 && aux != A[1][1]){
					aux=A[1][1];
					A[1][1]=A[0][1];
					A[0][1]=aux;
					troca=1;
				}
				else if(random == 2 && aux != A[0][0]){	
					aux=A[0][0];
					A[0][0]=A[0][1];
					A[0][1]=aux;
					troca=1;
				}
				else
					random= rand()%3;	
				}	
		}
		else if(linhazero==0 && colunazero==2){
			random= rand() % 2;
			int troca=0;
			while(troca == 0){
				if(random == 0 && aux != A[1][2]){
					aux=A[1][2];
					A[1][2]=A[0][2];
					A[0][2]=aux;
					troca=1;
				}
				else if(random == 1 && aux != A[0][1]){	
					aux=A[0][1];
					A[0][1]=A[0][2];
					A[0][2]=aux;
					troca=1;
				}
				else
					random=rand()%2;	
				}	
		}
		//elementos linha 2
		else if(linhazero==1 && colunazero==0){
			random= rand() % 3;
			int troca=0;
			while(troca == 0){
				if(random == 0 && aux != A[0][0]){
					aux=A[0][0];
					A[0][0]=A[1][0];
					A[1][0]=aux;
					troca=1;
				}
				else if(random == 1 && aux != A[1][1]){
					aux=A[1][1];
					A[1][1]=A[1][0];
					A[1][0]=aux;
					troca=1;
				}
				else if(random == 2 && aux != A[2][0]){	
					aux=A[2][0];
					A[2][0]=A[1][0];
					A[1][0]=aux;
					troca=1;
				}
				else 
					random= rand()%3;	
				}	
		}
		else if(linhazero==1 && colunazero==1){
			random= rand() % 4;
			int troca=0;
			while(troca == 0){
				if(random == 0 && aux != A[0][1]){
					aux=A[0][1];
					A[0][1]=A[1][1];
					A[1][1]=aux;
					troca=1;
				}
				else if(random == 1 && aux != A[1][2]){
					aux=A[1][2];
					A[1][2]=A[1][1];
					A[1][1]=aux;
					troca=1;
				}
				else if(random == 2 && aux != A[2][1]){	
					aux=A[2][1];
					A[2][1]=A[1][1];
					A[1][1]=aux;
					troca=1;
				}
				else if(random == 3 && aux != A[1][0]){
					aux=A[1][0];
					A[1][0]=A[1][1];
					A[1][1]=aux;
					troca=1;
				}
				else 
					random=rand()%4;
				}		
		}
		else if(linhazero==1 && colunazero==2){
			random= rand() % 3;
			int troca=0;
			while(troca == 0){
				if(random == 0 && aux != A[0][2]){
					aux=A[0][2];
					A[0][2]=A[1][2];
					A[1][2]=aux;
					troca=1;
					
				}
				else if(random == 1 && aux != A[2][2]){
					aux=A[2][2];
					A[2][2]=A[1][2];
					A[1][2]=aux;
					troca=1;
					
				}
				else if(random == 2 && aux != A[1][1]){	
					aux=A[1][1];
					A[1][1]=A[1][2];
					A[1][2]=aux;
					troca=1;
				}
				else
					random= rand()%3;
		}		
		}
	//elementos linha 3
		else if(linhazero==2 && colunazero==0){
			random= rand() % 2;
			int troca=0;
			while(troca == 0){
				if(random == 0 && aux != A[1][0]){
					aux=A[1][0];
					A[1][0]=A[2][0];
					A[2][0]=aux;
					troca=1;
					
				}
				else if(random == 1 && aux != A[2][1]){	
					aux=A[2][1];
					A[2][1]=A[2][0];
					A[2][0]=aux;
					troca=1;
					
				}
				else
					random=rand() % 2;	
				}	
		}
		else if(linhazero==2 && colunazero==1){
			random= rand() % 3;
			int troca=0;
			while(troca==0){
				if(random == 0 && aux != A[1][1]){
					aux=A[1][1];
					A[1][1]=A[2][1];
					A[2][1]=aux;
					troca=1;
					
				}
				else if(random == 1 && aux != A[2][2]){
					aux=A[2][2];
					A[2][2]=A[2][1];
					A[2][1]=aux;
					troca=1;
				}
				else if(random == 2 && aux != A[2][0]){
					aux=A[2][0];
					A[2][0]=A[2][1];
					A[2][1]=aux;
					troca=1;
				}
				else
					random = rand() % 3;		
			}
	}
		else if(linhazero==2 && colunazero==2){
			random= rand() % 2;
			int troca=0;
			while(troca==0){
				if(random == 0 && aux != A[1][2]){
					aux=A[1][2];
					A[1][2]=A[2][2];
					A[2][2]=aux;
					troca=1;
			
				}
				else if(random == 1 && aux != A[2][1]){	
					aux=A[2][1];
					A[2][1]=A[2][2];
					A[2][2]=aux;
					troca=1;
				}
				else
					random = rand() % 2;	
			}	
		}
	}   
}

int movimenta(int **A, int peca){
//essa função encontra o espaço vazio(zero), verifica se as peças na vertical ou na horizontal são iguais a peça que o usuario deseja trocar e sendo assim realiza a troca e retorna 1, indicando que houve a troca ou retorna zero quando a troca não é possível. 
	int colunazero,linhazero;
	for(int i=0; i< 3;i++)
		for(int j=0;j<3;j++)
			if(A[i][j] == 0){
				linhazero=i;
				colunazero=j;
			}
			
	if(linhazero == 0 && colunazero == 0){
		if(A[0][1] == peca){
			int aux=A[0][0];
			A[0][0]=A[0][1];
			A[0][1]=aux;
			return 1;
		}
		else if(A[1][0] == peca){
			int aux=A[0][0];
			A[0][0]=A[1][0];
			A[1][0]=aux;
			return 1;
		}			
	}
	else if(linhazero==0 && colunazero==1){
		if(A[0][2] == peca){
			int aux=A[0][1];
			A[0][1]=A[0][2];
			A[0][2]=aux;
			return 1;
		}
		else if(A[1][1] == peca){
			int aux=A[0][1];
			A[0][1]=A[1][1];
			A[1][1]=aux;
			return 1;
		}
		else if(A[0][0]== peca){	
			int aux=A[0][1];
			A[0][1]=A[0][0];
			A[0][0]=aux;
			return 1;
		}		
	}
	else if(linhazero==0 && colunazero==2){
			if(A[1][2] == peca){
			int aux=A[0][2];
			A[0][2]=A[1][2];
			A[1][2]=aux;
			return 1;
		}
			else if(A[0][1] == peca){	
			int aux=A[0][2];
			A[0][2]=A[0][1];
			A[0][1]=aux;
			return 1;
		}		
	}
	else if(linhazero==1 && colunazero==0){
		if(A[0][0]== peca){
			int aux=A[1][0];
			A[1][0]=A[0][0];
			A[0][0]=aux;
			return 1;
		}
		else if(A[1][1]== peca){
			int aux=A[1][0];
			A[1][0]=A[1][1];
			A[1][1]=aux;
			return 1;
		}
		else if(A[2][0]== peca){	
			int aux=A[1][0];
			A[1][0]=A[2][0];
			A[2][0]=aux;
			return 1;
		}		
	}
	else if(linhazero==1 && colunazero==1){
		if(A[0][1]== peca){
			int aux=A[1][1];
			A[1][1]=A[0][1];
			A[0][1]=aux;
			return 1;
		}
		else if(A[1][2]== peca){
			int aux=A[1][1];
			A[1][1]=A[1][2];
			A[1][2]=aux;
			return 1;
		}
		else if(A[2][1]== peca){	
			int aux=A[1][1];
			A[1][1]=A[2][1];
			A[2][1]=aux;
			return 1;
		}
		else if(A[1][0]== peca){
			int aux=A[1][1];
			A[1][1]=A[1][0];
			A[1][0]=aux;
			return 1;
		}		
	}
	else if(linhazero==1 && colunazero==2){
		if(A[0][2]== peca){
			int aux=A[1][2];
			A[1][2]=A[0][2];
			A[0][2]=aux;
			return 1;
		}
		else if(A[2][2]== peca){
			int aux=A[1][2];
			A[1][2]=A[2][2];
			A[2][2]=aux;
			return 1;
		}
		else if(A[1][1]== peca){	
			int aux=A[1][2];
			A[1][2]=A[1][1];
			A[1][1]=aux;
			return 1;
		}		
	}
	//elementos linha 3
	else if(linhazero==2 && colunazero==0){
		if(A[1][0]== peca){
			int aux=A[2][0];
			A[2][0]=A[1][0];
			A[1][0]=aux;
			return 1;
		}
		else if(A[2][1]== peca){	
			int aux=A[2][0];
			A[2][0]=A[2][1];
			A[2][1]=aux;
			return 1;
		}		
	}
	else if(linhazero==2 && colunazero==1){
		if(A[1][1]== peca){
			int aux=A[2][1];
			A[2][1]=A[1][1];
			A[1][1]=aux;
			return 1;
		}
		else if(A[2][2]== peca){
			int aux=A[2][1];
			A[2][1]=A[2][2];
			A[2][2]=aux;
			return 1;
		}
		else if(A[2][0]== peca){
			int aux=A[2][1];
			A[2][1]=A[2][0];
			A[2][0]=aux;
			return 1;
		}		
	}
	else if(linhazero==2 && colunazero==2){
		if(A[1][2]== peca){
			int aux=A[2][2];
			A[2][2]=A[1][2];
			A[1][2]=aux;
			return 1;
		}
		else if(A[2][1]== peca){	
			int aux=A[2][2];
			A[2][2]=A[2][1];
			A[2][1]=aux;
			return 1;
		}		
	}
	return 0;
}   

int jogoNovo(int **A){
		printf("\n");
    		tabuleiroNovo(A);//cria um tabuleiro com os valores iniciais
    		imprimir(A);//imprime o tabuleiro
    		printf(BOLD(BLUE("\n                         Tabuleiro ordenado!\n")));    		
    		char *dificuldade;
    		dificuldade=malloc(20*sizeof(char));
    		printf("\nDigite o nivel de dificuldade para embaralhar ");
    		printf(BOLD(GREEN("facil (1),")));
    		printf(BOLD(YELLOW("medio (2) "))"ou ");
    		printf(BOLD(RED("dificil (3)"))":");
    		fgets(dificuldade,20,stdin);
    		dificuldade[strlen(dificuldade)-1]='\0';
	    	int nivel=(int)dificuldade[0]-48;	
		while(strlen(dificuldade)>1 || nivel<1 || nivel>3 ){//fica solicitando o comando se digitar um comando maior que 1 caracter ou se o numero for invalido 
			if(strcmp(dificuldade,"sair")==0)
				return -1;//retorna -1 e ja para a funçao
			printf(RED("Comando invalido!"));
			printf("\nDigite o nivel de dificuldade para embaralhar ");
    			printf(BOLD(GREEN("facil (1),")));
    			printf(BOLD(YELLOW("medio (2) "))"ou ");
    			printf(BOLD(RED("dificil (3)"))": ");
			fgets(dificuldade,20,stdin);	
			dificuldade[strlen(dificuldade)-1]='\0';
			nivel=(int)dificuldade[0]-48;
		    	}
		free(dificuldade);
    		return nivel;
    		
 }	
 
 int carregarJogo(int **A){//verifica se o arquivo existe, se sim ele é aberto
	 	char *nome;
	 	nome=malloc(30*sizeof(char));
	 	int movimentos;
	    	printf("Digite o nome do arquivo: ");
	    	fgets(nome,30,stdin);
	    	nome[strlen(nome)-1]='\0';
		FILE *carregararquivo = fopen(nome, "r");
		if(carregararquivo == NULL){//quando nao existe retorna -1 
			printf(RED("Arquivo nao existe\n"));
			movimentos=-1;
			return movimentos;
			}
		else{//se carregado o arquivo
			printf(GREEN("\n\nArquivo %s Carregado. Vamos continuar o jogo! \n"),nome);
			fscanf(carregararquivo,"%d ",&movimentos);//primeiro inteiro do arquivo sao os movimentos do jogo
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++)
			    		fscanf(carregararquivo,"%d ",&A[i][j]);//preenche a matriz com os valores do carregamento
			   }
			fclose(carregararquivo);
		}
		free(nome);
		return movimentos;
	}
 
void comandosDoJogo(int **A,int cont){	
 		printf("\n\n\nDigite um comando ou um numero da peça que quer mover: ");
    		char *comando;
    		comando=malloc(30*sizeof(char));
    		fgets(comando,30,stdin);    
    		comando[strlen(comando)-1]='\0';//eliminando '/n'		
    		int resultado,movimentos=cont,mover;//movimentos recebe o contador de movimentos, pode ser zero ou os movimentos do carregamento
    		while(strcmp(comando,"sair") != 0 ){//um while principal que funciona enquanto o usuario nao digita sair
    			//printf("\n%s\n",comando);
	    		if(strlen(comando) == 1){//o comando de mover so pode ter um caracter    		
	    			mover=(int)comando[0]-48;//transforma a string de uma posição em um inteiro
	    			resultado=movimenta(A,mover); //chama a funçao movimentar que retorna 1 se movimentar ou 0 quando não é possivel movimentar  			
	    			if(resultado == 1){//se houver movimentação tem que verificar algumas coisas
	    				imprimir(A);//imprime a matriz apos a movimentação
	    				movimentos++;//acrescenta um no contador de movimentos
	    				int verificajogo=verificaJogo(A);//chama uma função que possui uma matriz correta e as comparam
	    				if(verificajogo == 1){//se retornar 1 é pelo fato do jogo atual ser igual ao jogo correto 
	    					printf(GREEN("\nParabens! Você completou o quebra-cabeças com %d movimentos.\n"),movimentos);
	    					break;//finaliza o jogo
	    				}
	    				
	    				printf("\n                 Quantidade de jogadas ate agora: %d\n\n",movimentos);//se o jogo nao acabou mostra a quantidade de movimentos apos a movimentaçao
	  
	    				}
	    			else if(resultado==0 && mover>0 && mover<9)//se a funçao de movimentar retornar zero e o numero da peça fizer parte do jogo
	    				printf(RED("\n                 Não e possível mover a peça %d\n\n"),mover);
	    			else //caso o usuario digitou uma letra ou um numero maior que 8 ou menor que 1
	    				printf(RED("Peça inexistente!\n"));
	    			
	    			}
	    		
	    		else if(strlen(comando) > 5){// voltar ou salvar tem mais de 5 caracteres
	    			
	    			char comandoarquivo[7];//separa o salvar do nome do arquivo 
	    			for(int i=0; i < 7; i++)
		    			comandoarquivo[i]=comando[i]; //salva o caracter que deve ser um espaço	
		    		comandoarquivo[7]='\0';
		    		
		    		if(strcmp(comandoarquivo,"salvar ") == 0){//se o comando salvar foi usado certo começa a manipular o nome do arquivo	
		    			
		    			char nomearquivo[20];
		    			int h=0;
		    			for (int i=7;i<strlen(comando);i++){//começa a preencher o nome do arquivo depois do espaço do comando
		    				nomearquivo[h]=comando[i];
		    				h++;
		    			}
		    			nomearquivo[h]='\0';
		    			
		    			char extensao[4];
		    			int k=4;
		    			
		    			for(int i=strlen(comando); i >= strlen(comando)-4; i--){//para verificar a extensão é preenchido um vetor de quatro posições de tras para frente
		    				extensao[k]=comando[i];
		    				k--;
		    				}
		    			extensao[4]='\0';
		    			
		    			if(strcmp(extensao,".txt") == 0){//se for uma extensão aceita ele salva o arquivo
		    				FILE *arquivo = fopen(nomearquivo,"w");
		    				fprintf(arquivo,"%d ",movimentos);//salva primeiro a quantidade de movimentos e um espaço	
		    				for (int i=0;i<3;i++){
		    					for(int j=0;j<3;j++)
		    						fprintf(arquivo,"%d ",A[i][j]);//salva a matriz com seus numeros separados por um espaço
		    				}
		    				printf(GREEN("Arquivo '%s' salvo com sucesso!\n"), nomearquivo);
		    				fclose(arquivo);
		    				}
		    			else//quando a extensão é diferente de .txt
		    				printf(RED("Extensão não aceita, deve ser .txt\n"));
		    		
	    			}
	    			else if(strcmp(comando,"voltar") == 0){// se o comando é maior que 5 verifica se é voltar	
		    			int retornomenu=menu();	//funçao mostra o menu e manipula a entrada, retornando a opçao do usuario, se digitar sair na seleção é retornado zero	    			
			    		if(retornomenu==1){//procedimento de jogo novo
				    		int dific=jogoNovo(A);
				    		if(dific == -1)
				    			break;
				    		else{
				  			movimentos=0;//zera os movimentos, pois é um novo jogo	
				  			embaralhar(A,dific);
				  			imprimir(A);	
				  			}
				    	}
			    		else if(retornomenu==2)//apenas imprime o jogo atual e pula para o pedido de comando
			    			imprimir(A);			    							    			
			    		else if(retornomenu==3){//chama função de carregar jogo que retorna os movimentos do jogo carregado
			    			int carregarmovimentos=carregarJogo(A);
			    			while(carregarmovimentos == -1){
			    			//enquanto o usuario nao digita um arquivo existente ele chama a função novamente 
				   			carregarmovimentos=carregarJogo(A);	
					   		}
			    			movimentos=carregarmovimentos;
			    			imprimir(A);
			    				}	
					else if(retornomenu==4){//apenas imprime as instruçoes e o jogo atual
			    			instrucoes(A);
			    			imprimir(A);
			    				}
			    		else if(retornomenu==0) 
			    			break;	
					}
				
				
					
				else{//caso digitar algum comando maior de 5 letras e invalido
					printf(RED("\nComando desconhecido! \n"));
					printf("\nPara salvar deve-se escrever da seguinte maneira: 'salvar nome.txt'\nPara voltar ao menu apenas digite voltar\n");
					}	
				
				}
		    	else
		    		printf(RED("Comando invalido!"));
		    	//proximas linhas pedem o comando novamente para o while principal, que vai verificar tudo novamente
		    	printf("Digite um comando ou um número da peça que quer mover: ");		    	
	    		fgets(comando,30,stdin);
	   		comando[strlen(comando)-1]='\0';				
		    	}
	free(comando);		
	}	    	

int main() {
    
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int **A;
    A=malloc(3*sizeof(int*));
    for(int i=0;i<3;i++)
    	A[i]=malloc(3*sizeof(int));
    int opcnumero=menu();//menu retorna a opçao, se for digitado sair retorna zero
    int sairnadificuldade;
	int movimentoscarregamento;
    switch(opcnumero){
    	case 0:
		break;
    	case 1:
    		sairnadificuldade=jogoNovo(A);//jogo novo preenche e mostra a matriz inicial(correta) e retorna a dificuldade, ou -1 se for digitado sair na seleção da dificuldade
    		if(sairnadificuldade == -1)
    			break;
    		else{
    			embaralhar(A,sairnadificuldade);//funçao recebe a matriz inicial e a embaralha de acordo com a dificuldade selecionada
    			imprimir(A);//mostra a matriz embaralhada
    			comandosDoJogo(A,0);//funçao responsavel pelos comandos do jogo, que recebe a matriz embaralhada e a quantidade de movimentos feitos, que nesse caso, como é um jogo novo não foram feitos movimentos
    			}
		break;
    
   	case 2:
   		printf(RED("\n\n                         Não existe jogo atual\n\n"));
   		printf(GREEN("                            Jogo novo gerado!\n"));//não tem como continuar um jogo atual se é a primeira vez que joga
   		
   		sairnadificuldade=jogoNovo(A);//sera feito o mesmo procedimento de um jogo novo
    		if(sairnadificuldade == -1)
    			break;
    		else{
    			embaralhar(A,sairnadificuldade);
    			imprimir(A);		
    			comandosDoJogo(A,0);
    			}
		break;
   	case 3:
   		movimentoscarregamento=carregarJogo(A); //função pede o nome do arquivo, e se existente retorna quantos movimentos foram feitos no jogo ou -1 caso não exista a arquivo
   		while(movimentoscarregamento == -1){//enquanto o usuario nao digita um arquivo existente ele chama a função 
   			movimentoscarregamento=carregarJogo(A);	
	   		}
	   	
	   	imprimir(A);//imprime o jogo carregado
	   	comandosDoJogo(A,movimentoscarregamento);//chama a função dos comandos do jogo, porém enviando os movimentos do carregamento
   		break;
   	case 4://mostra as instruções e faz o procedimento de um novo jogo
   		instrucoes();
   		sairnadificuldade=jogoNovo(A);
    		if(sairnadificuldade == -1)
    			break;
    		else{
    			embaralhar(A,sairnadificuldade);
    			imprimir(A);
    			comandosDoJogo(A,0);
    			}
		break; 
}
    for(int i=0;i<3;i++)
    	free(A[i]);
    free(A);
    return 0;
}
