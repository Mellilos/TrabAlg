//OBSERVAÇÃO: PODE ESCOLHER QUALQUER NOME. A SENHA É 'password' SEM AS ASPAS.
//Inclusão das bibliotecas necessárias
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<locale.h>
#include<string.h>
#include<math.h>
#include<time.h>
//Define constantes para navegação nos menus
#define cima 72
#define baixo 80
#define esquerda 75
#define direita 77
#define enter 13
#define esc 27
#define f1 59
//Estrutura do arquivo
typedef struct{
	int dia;
	int mes;
	int ano;
}data;
typedef struct{
	int excluido;
	int id;
	char nome[40];
	char marca[15];
	float frequenciaBase;
	float frequenciaMax;
	int litografia;
	int nucleos;
	int threads;
	int cache;
	float preco;
	data lancamento;
}processadores;
//Funções do programa
processadores cadastra()
{
	char numTexto[20];
	processadores processador;
	processador.excluido = 0;
	gotoxy(2,5); printf("ID do processador: ");
	gets(numTexto);
	processador.id = atoi(numTexto);
	gotoxy(2,6); printf("Nome do processador: ");
	gets(processador.nome);
	gotoxy(2,7); printf("Marca do processador: ");
	gets(processador.marca);
	gotoxy(2,8); printf("Frequência base: ");
	gets(numTexto);
	processador.frequenciaBase = atof(numTexto);
	gotoxy(2,9); printf("Frequência máxima: ");
	gets(numTexto);
	processador.frequenciaMax = atof(numTexto);
	gotoxy(2,10); printf("Litografia(nm): ");
	gets(numTexto);
	processador.litografia = atoi(numTexto);
	gotoxy(2,11); printf("Quantidade de núcleos: ");
	gets(numTexto);
	processador.nucleos = atoi(numTexto);
	gotoxy(2,12); printf("Quantidade de threads: ");
	gets(numTexto);
	processador.threads = atoi(numTexto);
	gotoxy(2,13); printf("Memória cachê: ");
	gets(numTexto);
	processador.cache = atoi(numTexto);
	gotoxy(2,14); printf("Preço: ");
	gets(numTexto);
	processador.preco = atof(numTexto);
	gotoxy(2,15); printf("Data de lançamento:   /  /  ");
	gotoxy(22,15); gets(numTexto);
	processador.lancamento.dia = atoi(numTexto);
	gotoxy(25,15); gets(numTexto);
	processador.lancamento.mes = atoi(numTexto);
	gotoxy(28,15); gets(numTexto);
	processador.lancamento.ano = atoi(numTexto);
}

processadores altera()
{
	char numTexto[20];
	processadores processador;
	gotoxy(2,5); printf("ID do processador: %d",processador.id);
	gotoxy(2,6); printf("Nome do processador: ");
	gets(processador.nome);
	gotoxy(2,7); printf("Marca do processador: ");
	gets(processador.marca);
	gotoxy(2,8); printf("Frequência base: ");
	gets(numTexto);
	processador.frequenciaBase = atof(numTexto);
	gotoxy(2,9); printf("Frequência máxima: ");
	gets(numTexto);
	processador.frequenciaMax = atof(numTexto);
	gotoxy(2,10); printf("Litografia(nm): ");
	gets(numTexto);
	processador.litografia = atoi(numTexto);
	gotoxy(2,11); printf("Quantidade de núcleos: ");
	gets(numTexto);
	processador.nucleos = atoi(numTexto);
	gotoxy(2,12); printf("Quantidade de threads: ");
	gets(numTexto);
	processador.threads = atoi(numTexto);
	gotoxy(2,13); printf("Memória cache: ");
	gets(numTexto);
	processador.cache = atoi(numTexto);
	gotoxy(2,14); printf("Preço: ");
	gets(numTexto);
	processador.preco = atof(numTexto);
	gotoxy(2,15); printf("Data de lançamento:   /  /  ");
	gotoxy(22,15); gets(numTexto);
	processador.lancamento.dia = atoi(numTexto);
	gotoxy(25,15); gets(numTexto);
	processador.lancamento.mes = atoi(numTexto);
	gotoxy(28,15); gets(numTexto);
	processador.lancamento.ano = atoi(numTexto);
}

processadores mostra(){
	processadores processador;
	gotoxy(2,5); printf("ID do processador: %d",processador.id);
	gotoxy(2,6); printf("Nome do processador: %s",processador.nome);
	gotoxy(2,7); printf("Marca do processador: %s",processador.marca);
	gotoxy(2,8); printf("Frequência base: %.2f",processador.frequenciaBase);
	gotoxy(2,9); printf("Frequência máxima: %.2f",processador.frequenciaMax);
	gotoxy(2,10); printf("Litografia(nm): %d",processador.litografia);
	gotoxy(2,11); printf("Quantidade de núcleos: %d",processador.nucleos);
	gotoxy(2,12); printf("Quantidade de threads: %d",processador.threads);
	gotoxy(2,13); printf("Memória cache: %d",processador.cache);
	gotoxy(2,14); printf("Preço: %.2f",processador.preco);
	gotoxy(2,15); printf("Data de lançamento: %2d/%2d/%2d",processador.lancamento.dia,processador.lancamento.mes,processador.lancamento.ano);
	getch();
}
//Função gotoxy
void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//Main
int main(){
	processadores processador;
    setlocale(LC_ALL,"Portuguese"); //Coloca a linguagem para Português
    //Declaração de variáveis
    FILE *arquivo;
    int tecla,a,b,linha,linhaAux,coluna,colunaAux,opcao,escolha,reprocessamento,tentativa=0,dif,i,achou,id;
    char nome[30],senha[11],pass[]="password",comando[100],pasta[50],nomeArq[50],numTexto[20],texto[150],resp;
    login: //Define o ponto de início do Login de usuário
    	system("cls");
    	system("color 8F");
    	gotoxy(50,1); printf("-----PROCESSADORES-----");
    	gotoxy(35,12); printf("Usuário: ");
    	gets(nome);
    	fflush(stdin);
    	gotoxy(35,13); printf("Senha: ");
    	do{
    		dif=0;
    		if(tentativa>0){
    			gotoxy(45,20); printf("Senha incorreta!");
			}
    		gotoxy(43,13); printf("                             ");
    		gotoxy(43,13); gets(senha);
    		//if(strlen(senha)==0)
    		//	dif=1;
    		for(i=0;i<strlen(senha);i++){
    			if(senha[i]!=pass[i]){
    				dif=1;
    				break;
				}
			}
    		tentativa++;
		}while(dif==1);
    do{
        inicio: //Define o ponto de início (Menu principal)
        linha=10;linhaAux=2;b=2;opcao=0;
        system("cls");
        system("color 9F");
        gotoxy(48,1); printf("-----PROCESSADORES-----");
        gotoxy(50,10); printf("Cadastrar processador");
		gotoxy(50,11); printf("Alterar processador");
		gotoxy(50,12); printf("Excluir processador");
		gotoxy(50,13); printf("Pesquisar processador por nome");
		gotoxy(50,14); printf("Pesquisar processador por ID");
		gotoxy(50,15); printf("Manipular pastas e arquivos");
		gotoxy(50,16); printf("Créditos");
		gotoxy(50,17); printf("Sair");
		gotoxy(1,28); printf("Conectado(a) como %s",nome);
		gotoxy(45,25); printf("Pressione F1 para obter ajuda!");
        do{
            gotoxy(46,linha); printf("->");
            if(kbhit){
				tecla=getch(); //Recebe as setas de navegação ou enter
			}
            //Seta para baixo
            if(tecla==baixo && b<=9){
            	if(b==9){
            		linha=10;linhaAux=17;b=2;
				}
				else{
					linhaAux=linha;
					linha++;
					b++;
				}
			}
			//Seta para cima
            if(tecla==cima && b>=2){
				if(b==2){
            		linha=17;linhaAux=10;b=9;
				}
				else{
					linhaAux=linha;
					linha--;
					b--;
				}
			}
            if(linha!=linhaAux){
				gotoxy(46,linhaAux); printf("  ");
				linhaAux=linha;
			}
            if(tecla==enter){
				opcao=b-1;
			}
			if(tecla==esc){
				opcao=8;
			}
			if(tecla==f1){
				opcao=9;
			}
        }while(opcao==0);
        switch (opcao){
            case 1: //Cadastrar processador
	            do{
	            	a=2;colunaAux=2;coluna=43;escolha=0;
	            	system("cls");
					system ("color 2F");
	            	gotoxy(51,1); printf("-----CADASTRAR-----");
	            	gotoxy(35,6); printf("Deseja utilizar uma pasta existente ou criar uma nova?");
					gotoxy(45,8); printf("Criar nova");
					gotoxy(65,8); printf("Usar existente");
					gotoxy(1,28); printf("Conectado(a) como %s",nome);
					do{
						gotoxy(coluna,8); printf("->");
						if(kbhit){
							tecla=getch();
						}
		            	// seta para direita
		            	if(tecla==direita && a<=3){
							if(a==3){
		            			coluna=43;colunaAux=63;a=2;
							}
							else{
								colunaAux=coluna;
								coluna+=20;
								a++;
							}
						}
						// seta para esquerda
				        if(tecla==esquerda && a>=2){
							if(a==2){
		            		coluna=63;colunaAux=43;a=3;
							}
							else{
								colunaAux=coluna;
								coluna-=20;
								a--;
							}
						}
				        if(coluna!=colunaAux){
							gotoxy(colunaAux,8); printf("  ");
							colunaAux=coluna;
						}
				        if(tecla==enter){
							escolha=a-1;
						}
					} while(escolha==0);
					if(escolha==1){
						gotoxy(35,10); printf("Digite o nome da nova pasta: ");
						gets(pasta);
						strcpy(comando,"mkdir ");
						strcat(comando,pasta);
						system(comando);
						chdir(pasta);
						gotoxy(35,16); printf("Digite o nome do novo arquivo(sem a extensão): ");
						gets(nomeArq);
						strcat(nomeArq,".dat");
						if ((arquivo = fopen(nomeArq, "wb")) == NULL) {
						    printf("\nFalha ao tentar abrir o arquivo %s!",nomeArq);
							goto inicio; 
						}
						do{
							system("cls");
							system("color 2F");
							gotoxy(51,1); printf("-----CADASTRAR-----");
							processador.excluido = 0;
							gotoxy(2,5); printf("ID do processador: ");
							gets(numTexto);
							processador.id = atoi(numTexto);
							gotoxy(2,6); printf("Nome do processador: ");
							gets(processador.nome);
							gotoxy(2,7); printf("Marca do processador: ");
							gets(processador.marca);
							gotoxy(2,8); printf("Frequência base: ");
							gets(numTexto);
							processador.frequenciaBase = atof(numTexto);
							gotoxy(2,9); printf("Frequência máxima: ");
							gets(numTexto);
							processador.frequenciaMax = atof(numTexto);
							gotoxy(2,10); printf("Litografia(nm): ");
							gets(numTexto);
							processador.litografia = atoi(numTexto);
							gotoxy(2,11); printf("Quantidade de núcleos: ");
							gets(numTexto);
							processador.nucleos = atoi(numTexto);
							gotoxy(2,12); printf("Quantidade de threads: ");
							gets(numTexto);
							processador.threads = atoi(numTexto);
							gotoxy(2,13); printf("Memória cache: ");
							gets(numTexto);
							processador.cache = atoi(numTexto);
							gotoxy(2,14); printf("Preço: ");
							gets(numTexto);
							processador.preco = atof(numTexto);
							gotoxy(2,15); printf("Data de lançamento:   /  /  ");
							gotoxy(22,15); gets(numTexto);
							processador.lancamento.dia = atoi(numTexto);
							gotoxy(25,15); gets(numTexto);
							processador.lancamento.mes = atoi(numTexto);
							gotoxy(28,15); gets(numTexto);
							processador.lancamento.ano = atoi(numTexto);
							
							fwrite(&processador, sizeof(processador), 1, arquivo);
						    printf("\nAdicionar outro registro(s/n)?: ");
						    do{
						        resp = toupper(getch());
						    }while (resp != 'S' && resp != 'N');
						}while (resp == 'S');
						fclose(arquivo);
						chdir("..");
					}
					else{
						do{
							gotoxy(35,10); printf("                                        ");
							gotoxy(0,12); printf("                                                    ");
							gotoxy(35,10); printf("Digite o nome da pasta: ");
							gets(pasta);
							strcpy(comando,"chdir ");
							strcat(comando,pasta);
							gotoxy(35,11); system(comando);
						}while(system(comando)==1);
						gotoxy(35,11); printf("                                                       ");
						chdir(pasta);
						
						a=2;colunaAux=2;coluna=43;escolha=0;
						gotoxy(35,12); printf("Deseja utilizar um arquivo existente ou criar um novo?");
						gotoxy(45,14); printf("Criar novo");
						gotoxy(65,14); printf("Usar existente");
						do{
							gotoxy(coluna,14); printf("->");
							if(kbhit){
								tecla=getch();
							}
			            	// seta para direita
			            	if(tecla==direita && a<=3){
								if(a==3){
			            			coluna=43;colunaAux=63;a=2;
								}
								else{
									colunaAux=coluna;
									coluna+=20;
									a++;
								}
							}
							// seta para esquerda
					        if(tecla==esquerda && a>=2){
								if(a==2){
			            		coluna=63;colunaAux=43;a=3;
								}
								else{
									colunaAux=coluna;
									coluna-=20;
									a--;
								}
							}
					        if(coluna!=colunaAux){
								gotoxy(colunaAux,14); printf("  ");
								colunaAux=coluna;
							}
					        if(tecla==enter){
								escolha=a-1;
							}
						}while(escolha==0);
						
						if(escolha==1){
							gotoxy(35,16); printf("Digite o nome do novo arquivo(sem a extensão): ");
							gets(nomeArq);
							strcat(nomeArq,".dat");
							if ((arquivo = fopen(nomeArq, "wb")) == NULL) {
							    printf("\nFalha ao tentar abrir o arquivo %s!",nomeArq);
								goto inicio; 
							}
							do{
								system("cls");
								system("color 2F");
								gotoxy(51,1); printf("-----CADASTRAR-----");
								processador.excluido = 0;
								gotoxy(2,5); printf("ID do processador: ");
								gets(numTexto);
								processador.id = atoi(numTexto);
								gotoxy(2,6); printf("Nome do processador: ");
								gets(processador.nome);
								gotoxy(2,7); printf("Marca do processador: ");
								gets(processador.marca);
								gotoxy(2,8); printf("Frequência base: ");
								gets(numTexto);
								processador.frequenciaBase = atof(numTexto);
								gotoxy(2,9); printf("Frequência máxima: ");
								gets(numTexto);
								processador.frequenciaMax = atof(numTexto);
								gotoxy(2,10); printf("Litografia(nm): ");
								gets(numTexto);
								processador.litografia = atoi(numTexto);
								gotoxy(2,11); printf("Quantidade de núcleos: ");
								gets(numTexto);
								processador.nucleos = atoi(numTexto);
								gotoxy(2,12); printf("Quantidade de threads: ");
								gets(numTexto);
								processador.threads = atoi(numTexto);
								gotoxy(2,13); printf("Memória cachê: ");
								gets(numTexto);
								processador.cache = atoi(numTexto);
								gotoxy(2,14); printf("Preço: ");
								gets(numTexto);
								processador.preco = atof(numTexto);
								gotoxy(2,15); printf("Data de lançamento:   /  /  ");
								gotoxy(22,15); gets(numTexto);
								processador.lancamento.dia = atoi(numTexto);
								gotoxy(25,15); gets(numTexto);
								processador.lancamento.mes = atoi(numTexto);
								gotoxy(28,15); gets(numTexto);
								processador.lancamento.ano = atoi(numTexto);
								
								fwrite(&processador, sizeof(processador), 1, arquivo);
							    printf("\nAdicionar outro registro(s/n)?: ");
							    do{
							        resp = toupper(getch());
							    }while (resp != 'S' && resp != 'N');
							}while (resp == 'S');
							fclose(arquivo);
							chdir("..");
						}
						else{
							do{
								gotoxy(35,16); printf("                                        ");
								gotoxy(0,18); printf("                                                    ");
								gotoxy(35,16); printf("Digite o nome do arquivo(sem a extensão): ");
								gets(nomeArq);
								strcat(nomeArq,".dat");
								if ((arquivo = fopen(nomeArq, "ab")) == NULL){
								    gotoxy(35,18); printf("\nFalha ao tentar abrir o arquivo %s!",nomeArq);
								}
							}while((arquivo = fopen(nomeArq, "ab")) == NULL);
							do{
								system("cls");
								system("color 2F");
								gotoxy(51,1); printf("-----CADASTRAR-----");
								processador.excluido = 0;
								gotoxy(2,5); printf("ID do processador: ");
								gets(numTexto);
								processador.id = atoi(numTexto);
								gotoxy(2,6); printf("Nome do processador: ");
								gets(processador.nome);
								gotoxy(2,7); printf("Marca do processador: ");
								gets(processador.marca);
								gotoxy(2,8); printf("Frequência base: ");
								gets(numTexto);
								processador.frequenciaBase = atof(numTexto);
								gotoxy(2,9); printf("Frequência máxima: ");
								gets(numTexto);
								processador.frequenciaMax = atof(numTexto);
								gotoxy(2,10); printf("Litografia(nm): ");
								gets(numTexto);
								processador.litografia = atoi(numTexto);
								gotoxy(2,11); printf("Quantidade de núcleos: ");
								gets(numTexto);
								processador.nucleos = atoi(numTexto);
								gotoxy(2,12); printf("Quantidade de threads: ");
								gets(numTexto);
								processador.threads = atoi(numTexto);
								gotoxy(2,13); printf("Memória cachê: ");
								gets(numTexto);
								processador.cache = atoi(numTexto);
								gotoxy(2,14); printf("Preço: ");
								gets(numTexto);
								processador.preco = atof(numTexto);
								gotoxy(2,15); printf("Data de lançamento:   /  /  ");
								gotoxy(22,15); gets(numTexto);
								processador.lancamento.dia = atoi(numTexto);
								gotoxy(25,15); gets(numTexto);
								processador.lancamento.mes = atoi(numTexto);
								gotoxy(28,15); gets(numTexto);
								processador.lancamento.ano = atoi(numTexto);
								
								fwrite(&processador, sizeof(processador), 1, arquivo);
							    printf("\nAdicionar outro registro(s/n)?: ");
							    do{
							        resp = toupper(getch());
							    }while (resp != 'S' && resp != 'N');
							}while (resp == 'S');
							fclose(arquivo);
							chdir("..");
						}
					}
					
					//Reprocessamento do Cadastro
					a=2;colunaAux=2;coluna=53;reprocessamento=0;
					system("cls");
					system ("color 2F");
					gotoxy(53,1); printf("-----CADASTRAR-----");
					gotoxy(44,12); printf("Deseja realizar um novo cadastro?");
					gotoxy(55,14); printf("Sim");
					gotoxy(64,14); printf("Não");
					gotoxy(1,28); printf("Conectado(a) como %s",nome);
					do{
						gotoxy(coluna,14); printf("->");
						if(kbhit){
							tecla=getch();
						}
		            	// seta para direita
		            	if(tecla==direita && a<=3){
							if(a==3){
		            			coluna=53;colunaAux=62;a=2;
							}
							else{
								colunaAux=coluna;
								coluna+=9;
								a++;
							}
						}
						// seta para esquerda
				        if(tecla==esquerda && a>=2){
							if(a==2){
		            		coluna=62;colunaAux=53;a=3;
							}
							else{
								colunaAux=coluna;
								coluna-=9;
								a--;
							}
						}
				        if(coluna!=colunaAux){
							gotoxy(colunaAux,14); printf("  ");
							colunaAux=coluna;
						}
				        if(tecla==enter){
							reprocessamento=a-1;
						}
					} while(reprocessamento==0);	
				}while(reprocessamento!=2);
	            break; //Fim Cadastrar
            case 2: //Alterar processador
            	do{
            		a=2;colunaAux=2;coluna=43;escolha=0;
	            	system("cls");
					system ("color 4E");
	            	gotoxy(48,1); printf("-----ALTERAR-----");
	            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
	            	do{
	            		gotoxy(0,10); printf("                                                    ");
	            		gotoxy(25,8); printf("                                     ");
	            		gotoxy(25,6); printf("Digite o nome da pasta que contém o arquivo que deseja alterar: ");
						gotoxy(25,8); gets(pasta);
						strcpy(comando,"cd ");
						strcat(comando,pasta);
						gotoxy(25,9); system(comando);
					}while(system(comando)==1);
					gotoxy(25,9); printf("                                                     ");
					chdir(pasta);
					gotoxy(25,10); printf("Digite o nome do arquivo que deseja alterar (sem extens?o):");
					gotoxy(25,12); gets(nomeArq);
					strcat(nomeArq,".dat");
					
					achou = 0;
				  	//Abertura do arquivo
				  	if((arquivo = fopen(nomeArq, "r+b")) == NULL) {
				    	gotoxy(35,14); printf ("Falha ao abrir o arquivo %s",nomeArq);
				    	getch();
				    	break;
				  	}
				  	gotoxy(25,14); printf ("Qual o número do ID do processador que deseja alterar?\n");
				  	gotoxy(25,16); scanf ("%d",&id);
				  	//Leitura dos registros  
				  	while (fread (&processador, sizeof(processadores), 1, arquivo) == 1 && !achou)
				    	if (!processador.excluido && processador.id == id) {
				      		fflush(stdin);
				      		system("cls");
							system("color 4E");
							gotoxy(53,1); printf("-----ALTERAR-----");
							gotoxy(1,28); printf("Conectado(a) como %s",nome);
							
							gotoxy(2,5); printf("ID do processador: %d",processador.id);
							gotoxy(2,6); printf("Nome do processador: %s",processador.nome);
							gotoxy(2,7); printf("Marca do processador: %s",processador.marca);
							gotoxy(2,8); printf("Frequência base: %.2f",processador.frequenciaBase);
							gotoxy(2,9); printf("Frequência máxima: %.2f",processador.frequenciaMax);
							gotoxy(2,10); printf("Litografia(nm): %d",processador.litografia);
							gotoxy(2,11); printf("Quantidade de núcleos: %d",processador.nucleos);
							gotoxy(2,12); printf("Quantidade de threads: %d",processador.threads);
							gotoxy(2,13); printf("Memória cache: %d",processador.cache);
							gotoxy(2,14); printf("Preço: %.2f",processador.preco);
							gotoxy(2,15); printf("Data de lançamento: %2d/%2d/%2d",processador.lancamento.dia,processador.lancamento.mes,processador.lancamento.ano);
							getch();
							
							system("cls");
							system("color 4E");
							gotoxy(53,1); printf("-----ALTERAR-----");
							gotoxy(2,5); printf("ID do processador: %d",processador.id);
							gotoxy(2,6); printf("Nome do processador: ");
							gets(processador.nome);
							gotoxy(2,7); printf("Marca do processador: ");
							gets(processador.marca);
							gotoxy(2,8); printf("Frequência base: ");
							gets(numTexto);
							processador.frequenciaBase = atof(numTexto);
							gotoxy(2,9); printf("Frequência máxima: ");
							gets(numTexto);
							processador.frequenciaMax = atof(numTexto);
							gotoxy(2,10); printf("Litografia(nm): ");
							gets(numTexto);
							processador.litografia = atoi(numTexto);
							gotoxy(2,11); printf("Quantidade de núcleos: ");
							gets(numTexto);
							processador.nucleos = atoi(numTexto);
							gotoxy(2,12); printf("Quantidade de threads: ");
							gets(numTexto);
							processador.threads = atoi(numTexto);
							gotoxy(2,13); printf("Memória cache: ");
							gets(numTexto);
							processador.cache = atoi(numTexto);
							gotoxy(2,14); printf("Preço: ");
							gets(numTexto);
							processador.preco = atof(numTexto);
							gotoxy(2,15); printf("Data de lançamento:   /  /  ");
							gotoxy(22,15); gets(numTexto);
							processador.lancamento.dia = atoi(numTexto);
							gotoxy(25,15); gets(numTexto);
							processador.lancamento.mes = atoi(numTexto);
							gotoxy(28,15); gets(numTexto);
							processador.lancamento.ano = atoi(numTexto);
							
				      		//Volta o ponteiro
				      		fseek(arquivo,-sizeof(processadores),SEEK_CUR);
				      		//Grava os dados lidos - alterados
				      		fwrite(&processador,sizeof(processadores),1,arquivo);
				      		fflush(arquivo);
				      		achou = 1;
				   	 	}
				  	if(!achou){
				    	gotoxy(35,15); printf("Não há processador cadastrado com ID %d!",id);
				    }
				  	fclose(arquivo);
				  	chdir("..");
				  	gotoxy(2,16); printf("Alteração realizada com sucesso!");
				  	getch();
					
					//Reprocessamento do alterar
					a=2;colunaAux=2;coluna=53;reprocessamento=0;
					system("cls");
					system ("color 4E");
					gotoxy(53,1); printf("-----ALTERAR-----");
					gotoxy(45,12); printf("Deseja realizar outra alteração?");
					gotoxy(55,14); printf("Sim");
					gotoxy(64,14); printf("Não");
					gotoxy(1,28); printf("Conectado(a) como %s",nome);
					do{
						gotoxy(coluna,14); printf("->");
						if(kbhit){
							tecla=getch();
						}
		            	// seta para direita
		            	if(tecla==direita && a<=3){
							if(a==3){
		            			coluna=53;colunaAux=62;a=2;
							}
							else{
								colunaAux=coluna;
								coluna+=9;
								a++;
							}
						}
						// seta para esquerda
				        if(tecla==esquerda && a>=2){
							if(a==2){
		            		coluna=62;colunaAux=53;a=3;
							}
							else{
								colunaAux=coluna;
								coluna-=9;
								a--;
							}
						}
				        if(coluna!=colunaAux){
							gotoxy(colunaAux,14); printf("  ");
							colunaAux=coluna;
						}
				        if(tecla==enter){
							reprocessamento=a-1;
						}
					} while(reprocessamento==0);	
				}while(reprocessamento!=2);
                break; //Fim alterar
            case 3: //Exclusão
            	do{
            		a=2;colunaAux=31;coluna=6;escolha=0;
	            	system("cls");
					system ("color 57");
	            	gotoxy(48,1); printf("-----EXCLUIR-----");
	            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
	            	do{
	            		gotoxy(0,10); printf("                                                    ");
	            		gotoxy(25,8); printf("                                     ");
	            		gotoxy(25,6); printf("Digite o nome da pasta que contém o arquivo que deseja alterar:");
						gotoxy(25,8); gets(pasta);
						strcpy(comando,"cd ");
						strcat(comando,pasta);
						gotoxy(25,9); system(comando);
					}while(system(comando)==1);
					gotoxy(25,9); printf("                                                     ");
					chdir(pasta);
					gotoxy(25,10); printf("Digite o nome do arquivo que deseja alterar (sem extens?o):");
					gotoxy(25,12); gets(nomeArq);
					strcat(nomeArq,".dat");
					
					achou = 0;
				  	//Abertura do arquivo
				  	if((arquivo = fopen(nomeArq, "r+b")) == NULL) {
				    	gotoxy(35,14); printf("Falha ao abrir o arquivo %s",nomeArq);
				    	getch();
				    	break;
				  	}
				  	gotoxy(25,14); printf ("Qual o número do ID do processador que deseja excluir?\n");
				  	gotoxy(25,16); scanf ("%d",&id);
				  	//Leitura dos registros  
				  	while (fread (&processador, sizeof(processadores), 1, arquivo) == 1 && !achou)
				    	if (!processador.excluido && processador.id == id) {
				      		fflush(stdin);
				      		system("cls");
							system("color 57");
							gotoxy(53,1); printf("-----EXCLUIR-----");
							gotoxy(2,5); printf("ID do processador: %d",processador.id);
							gotoxy(2,6); printf("Nome do processador: %s",processador.nome);
							gotoxy(2,7); printf("Marca do processador: %s",processador.marca);
							gotoxy(2,8); printf("Frequência base: %.2f",processador.frequenciaBase);
							gotoxy(2,9); printf("Frequência máxima: %.2f",processador.frequenciaMax);
							gotoxy(2,10); printf("Litografia(nm): %d",processador.litografia);
							gotoxy(2,11); printf("Quantidade de núcleos: %d",processador.nucleos);
							gotoxy(2,12); printf("Quantidade de threads: %d",processador.threads);
							gotoxy(2,13); printf("Memória cache: %d",processador.cache);
							gotoxy(2,14); printf("Preço: %.2f",processador.preco);
							gotoxy(2,15); printf("Data de lançamento: %2d/%2d/%2d",processador.lancamento.dia,processador.lancamento.mes,processador.lancamento.ano);
							
							gotoxy(2,17); printf("Deseja mesmo excluir o processador acima?");
							gotoxy(8,19); printf("Sim");
							gotoxy(33,19); printf("Não");
							gotoxy(1,28); printf("Conectado(a) como %s",nome);
							do{
								gotoxy(coluna,19); printf("->");
								if(kbhit){
									tecla=getch();
								}
				            	// seta para direita
				            	if(tecla==direita && a<=3){
									if(a==3){
				            			coluna=6;colunaAux=31;a=2;
									}
									else{
										colunaAux=coluna;
										coluna+=25;
										a++;
									}
								}
								// seta para esquerda
						        if(tecla==esquerda && a>=2){
									if(a==2){
				            		coluna=31;colunaAux=6;a=3;
									}
									else{
										colunaAux=coluna;
										coluna-=25;
										a--;
									}
								}
						        if(coluna!=colunaAux){
									gotoxy(colunaAux,19); printf("  ");
									colunaAux=coluna;
								}
						        if(tecla==enter){
									escolha=a-1;
								}
							}while(escolha==0);
							if(escolha==1){
								processador.excluido = 1;
								//Volta o ponteiro
					      		fseek(arquivo,-sizeof(processadores),SEEK_CUR);
					      		//Grava os dados lidos - alterados
					      		fwrite(&processador,sizeof(processadores),1,arquivo);
					      		fflush(arquivo);
							}
							else{
								fclose(arquivo);
				  				chdir("..");
				  				goto inicio;
							}
				      		achou = 1;
				   	 	}
				   	system("cls");
				   	system("color 57");
					gotoxy(53,1); printf("-----EXCLUIR-----");
				  	if(!achou){
				    	gotoxy(40,12); printf("Não há processador cadastrado com ID %d!",id);
				    }
				    else{
				    	gotoxy(50,12); printf("Exclusão realizada com sucesso!");
					}
				  	fclose(arquivo);
				  	chdir("..");
				  	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				  	getch();
					
					//Reprocessamento do excluir
					a=2;colunaAux=2;coluna=53;reprocessamento=0;
					system("cls");
					system ("color 57");
					gotoxy(53,1); printf("-----EXCLUIR-----");
					gotoxy(1,28); printf("Conectado(a) como %s",nome);
					gotoxy(45,12); printf("Deseja realizar outra alteração?");
					gotoxy(55,14); printf("Sim");
					gotoxy(64,14); printf("Não");
					do{
						gotoxy(coluna,14); printf("->");
						if(kbhit){
							tecla=getch();
						}
		            	// seta para direita
		            	if(tecla==direita && a<=3){
							if(a==3){
		            			coluna=53;colunaAux=62;a=2;
							}
							else{
								colunaAux=coluna;
								coluna+=9;
								a++;
							}
						}
						// seta para esquerda
				        if(tecla==esquerda && a>=2){
							if(a==2){
		            		coluna=62;colunaAux=53;a=3;
							}
							else{
								colunaAux=coluna;
								coluna-=9;
								a--;
							}
						}
				        if(coluna!=colunaAux){
							gotoxy(colunaAux,14); printf("  ");
							colunaAux=coluna;
						}
				        if(tecla==enter){
							reprocessamento=a-1;
						}
					} while(reprocessamento==0);	
				}while(reprocessamento!=2);
                break; //Fim exclusão
            case 4: //Pesquisa por nome
            	do{
            		a=2;colunaAux=31;coluna=6;escolha=0;
	            	system("cls");
					system ("color F0");
	            	gotoxy(50,1); printf("-----PESQUISAR-----");
	            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
	            	do{
	            		gotoxy(0,10); printf("                                                    ");
	            		gotoxy(25,8); printf("                                     ");
	            		gotoxy(25,6); printf("Digite o nome da pasta que contém o arquivo no qual fará a pesquisa (sem extensão):");
						gotoxy(25,8); gets(pasta);
						strcpy(comando,"cd ");
						strcat(comando,pasta);
						gotoxy(25,9); system(comando);
					}while(system(comando)==1);
					gotoxy(25,9); printf("                                                     ");
					chdir(pasta);
					gotoxy(25,10); printf("Digite o nome do arquivo para fazer a pesquisa:");
					gotoxy(25,12); gets(nomeArq);
					strcat(nomeArq,".dat");
					
					achou = 0;
				  	//Abertura do arquivo
				  	if((arquivo = fopen(nomeArq, "rb")) == NULL) {
				    	gotoxy(35,14); printf("Falha ao abrir o arquivo %s",nomeArq);
				    	getch();
				    	break;
				  	}
				  	gotoxy(25,14); printf("Qual o nome do processador que deseja pesquisar?\n");
				  	gotoxy(25,16); gets(texto);
				  	//Leitura dos registros  
				  	while(fread (&processador, sizeof(processadores), 1, arquivo) == 1 && !achou)
				    	if (!processador.excluido && strcmp(processador.nome,texto)==0) {
				      		fflush(stdin);
				      		system("cls");
							system("color F0");
							gotoxy(53,1); printf("-----PESQUISAR-----");
							gotoxy(2,5); printf("ID do processador: %d",processador.id);
							gotoxy(2,6); printf("Nome do processador: %s",processador.nome);
							gotoxy(2,7); printf("Marca do processador: %s",processador.marca);
							gotoxy(2,8); printf("Frequência base: %.2f",processador.frequenciaBase);
							gotoxy(2,9); printf("Frequência máxima: %.2f",processador.frequenciaMax);
							gotoxy(2,10); printf("Litografia(nm): %d",processador.litografia);
							gotoxy(2,11); printf("Quantidade de núcleos: %d",processador.nucleos);
							gotoxy(2,12); printf("Quantidade de threads: %d",processador.threads);
							gotoxy(2,13); printf("Memória cache: %d",processador.cache);
							gotoxy(2,14); printf("Preço: %.2f",processador.preco);
							gotoxy(2,15); printf("Data de lançamento: %2d/%2d/%2d",processador.lancamento.dia,processador.lancamento.mes,processador.lancamento.ano);
							getch();
							
							fclose(arquivo);
				  			chdir("..");
				      		achou = 1;
				   	 	}
				   	system("cls");
				   	system("color F0");
				   	gotoxy(53,1); printf("-----PESQUISAR-----");
				  	if(!achou){
				    	gotoxy(40,12); printf("Não há processador cadastrado com nome %s!",texto);
				    	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				  		getch();
					}
					
					//Reprocessamento do pesquisar nome
					a=2;colunaAux=2;coluna=53;reprocessamento=0;
					system("cls");
					system ("color F0");
					gotoxy(52,1); printf("-----PESQUISAR-----");
					gotoxy(1,28); printf("Conectado(a) como %s",nome);
					gotoxy(45,12); printf("Deseja realizar outra pesquisa?");
					gotoxy(55,14); printf("Sim");
					gotoxy(64,14); printf("Não");
					do{
						gotoxy(coluna,14); printf("->");
						if(kbhit){
							tecla=getch();
						}
		            	// seta para direita
		            	if(tecla==direita && a<=3){
							if(a==3){
		            			coluna=53;colunaAux=62;a=2;
							}
							else{
								colunaAux=coluna;
								coluna+=9;
								a++;
							}
						}
						// seta para esquerda
				        if(tecla==esquerda && a>=2){
							if(a==2){
		            		coluna=62;colunaAux=53;a=3;
							}
							else{
								colunaAux=coluna;
								coluna-=9;
								a--;
							}
						}
				        if(coluna!=colunaAux){
							gotoxy(colunaAux,14); printf("  ");
							colunaAux=coluna;
						}
				        if(tecla==enter){
							reprocessamento=a-1;
						}
					} while(reprocessamento==0);	
				}while(reprocessamento!=2);
            	break; //Fim pesquisa por nome
            case 5: //Pesquisa por ID
            	do{
            		a=2;colunaAux=31;coluna=6;escolha=0;
	            	system("cls");
					system ("color F4");
	            	gotoxy(50,1); printf("-----PESQUISAR-----");
	            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
	            	do{
	            		gotoxy(0,10); printf("                                                    ");
	            		gotoxy(25,8); printf("                                     ");
	            		gotoxy(25,6); printf("Digite o nome da pasta que contém o arquivo no qual fará a pesquisa (sem extensçao):");
						gotoxy(25,8); gets(pasta);
						strcpy(comando,"cd ");
						strcat(comando,pasta);
						gotoxy(25,9); system(comando);
					}while(system(comando)==1);
					gotoxy(25,9); printf("                                                     ");
					chdir(pasta);
					gotoxy(25,10); printf("Digite o nome do arquivo para fazer a pesquisa:");
					gotoxy(25,12); gets(nomeArq);
					strcat(nomeArq,".dat");
					
					achou = 0;
				  	//Abertura do arquivo
				  	if((arquivo = fopen(nomeArq, "rb")) == NULL) {
				    	gotoxy(35,14); printf("Falha ao abrir o arquivo %s",nomeArq);
				    	getch();
				    	break;
				  	}
				  	gotoxy(25,14); printf("Qual o ID do processador que deseja pesquisar?\n");
				  	gotoxy(25,16); scanf("%d",&id);
				  	//Leitura dos registros  
				  	while(fread (&processador, sizeof(processadores), 1, arquivo) == 1 && !achou)
				    	if(!processador.excluido && processador.id==id) {
				      		fflush(stdin);
				      		system("cls");
							system("color F4");
							gotoxy(53,1); printf("-----PESQUISAR-----");
							gotoxy(2,5); printf("ID do processador: %d",processador.id);
							gotoxy(2,6); printf("Nome do processador: %s",processador.nome);
							gotoxy(2,7); printf("Marca do processador: %s",processador.marca);
							gotoxy(2,8); printf("Frequência base: %.2f",processador.frequenciaBase);
							gotoxy(2,9); printf("Frequência máxima: %.2f",processador.frequenciaMax);
							gotoxy(2,10); printf("Litografia(nm): %d",processador.litografia);
							gotoxy(2,11); printf("Quantidade de núcleos: %d",processador.nucleos);
							gotoxy(2,12); printf("Quantidade de threads: %d",processador.threads);
							gotoxy(2,13); printf("Memória cache: %d",processador.cache);
							gotoxy(2,14); printf("Preço: %.2f",processador.preco);
							gotoxy(2,15); printf("Data de lançamento: %2d/%2d/%2d",processador.lancamento.dia,processador.lancamento.mes,processador.lancamento.ano);
							getch();
							
							fclose(arquivo);
				  			chdir("..");
				      		achou = 1;
				   	 	}
				   	system("cls");
				   	system("color F4");
				   	gotoxy(53,1); printf("-----PESQUISAR-----");
				  	if(!achou){
				    	gotoxy(40,12); printf("Não há processador cadastrado com ID %d!",id);
				    	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				  		getch();
					}
					
					//Reprocessamento do pesquisar ID
					a=2;colunaAux=2;coluna=53;reprocessamento=0;
					system("cls");
					system ("color F4");
					gotoxy(52,1); printf("-----PESQUISAR-----");
					gotoxy(1,28); printf("Conectado(a) como %s",nome);
					gotoxy(45,12); printf("Deseja realizar outra pesquisa?");
					gotoxy(55,14); printf("Sim");
					gotoxy(64,14); printf("Não");
					do{
						gotoxy(coluna,14); printf("->");
						if(kbhit){
							tecla=getch();
						}
		            	// seta para direita
		            	if(tecla==direita && a<=3){
							if(a==3){
		            			coluna=53;colunaAux=62;a=2;
							}
							else{
								colunaAux=coluna;
								coluna+=9;
								a++;
							}
						}
						// seta para esquerda
				        if(tecla==esquerda && a>=2){
							if(a==2){
		            		coluna=62;colunaAux=53;a=3;
							}
							else{
								colunaAux=coluna;
								coluna-=9;
								a--;
							}
						}
				        if(coluna!=colunaAux){
							gotoxy(colunaAux,14); printf("  ");
							colunaAux=coluna;
						}
				        if(tecla==enter){
							reprocessamento=a-1;
						}
					} while(reprocessamento==0);	
				}while(reprocessamento!=2);
            	break; //Fim pesquisa por ID
            case 6: //Alterar pastas
            	do{
			        pastas: //Define o ponto de início (alteração de pastas)
			        linha=10;linhaAux=2;b=2;opcao=0;
			        system("cls");
			        system("color B0");
			        gotoxy(50,1); printf("-----PASTAS E ARQUIVOS-----");
			        gotoxy(50,10); printf("Consultar arquivos de uma pasta");
					gotoxy(50,11); printf("Renomear pasta/arquivo");
					gotoxy(50,12); printf("Excluir pasta/arquivo");
					gotoxy(50,13); printf("Mover/copiar arquivo para outra pasta");
					gotoxy(50,14); printf("Alterar data e hora do sistema");
					gotoxy(50,15); printf("Voltar");
					gotoxy(1,28); printf("Conectado(a) como %s",nome);
					gotoxy(45,25); printf("Pressione ESC para voltar ao menu principal!");
			        do{
			            gotoxy(46,linha); printf("->");
			            if(kbhit){
							tecla=getch(); //Recebe as setas de navegação ou enter
						}
			            //Seta para baixo
			            if(tecla==baixo && b<=7){
			            	if(b==7){
			            		linha=10;linhaAux=15;b=2;
							}
							else{
								linhaAux=linha;
								linha++;
								b++;
							}
						}
						//Seta para cima
			            if(tecla==cima && b>=2){
							if(b==2){
			            		linha=15;linhaAux=10;b=7;
							}
							else{
								linhaAux=linha;
								linha--;
								b--;
							}
						}
			            if(linha!=linhaAux){
							gotoxy(46,linhaAux); printf("  ");
							linhaAux=linha;
						}
			            if(tecla==enter){
							opcao=b-1;
						}
						if(tecla==esc){
							opcao=5;
						}
						if(tecla==f1){
							opcao=6;
						}
			        }while(opcao==0);
			        switch (opcao){
			        	case 1: //Consultar arquivos
			        	
			        		do{
			            		a=2;colunaAux=31;coluna=6;escolha=0;
				            	system("cls");
								system ("color B0");
				            	gotoxy(50,1); printf("-----CONSULTAR-----");
				            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				            	do{
				            		gotoxy(0,10); printf("                                                    ");
				            		gotoxy(25,8); printf("                                     ");
				            		gotoxy(25,6); printf("Digite o nome da pasta na qual fará a pesquisa:");
									gotoxy(25,8); gets(pasta);
									strcpy(comando,"cd ");
									strcat(comando,pasta);
									gotoxy(25,9); system(comando);
								}while(system(comando)==1);
								gotoxy(25,9); printf("                                                     ");
								chdir(pasta);
								gotoxy(0,11);
								system("dir");
								getch();
				
								//Reprocessamento do pesquisar pasta
								a=2;colunaAux=2;coluna=53;reprocessamento=0;
								system("cls");
								system ("color B0");
								chdir("..");
								gotoxy(52,1); printf("-----CONSULTAR-----");
								gotoxy(1,28); printf("Conectado(a) como %s",nome);
								gotoxy(45,12); printf("Deseja realizar outra pesquisa?");
								gotoxy(55,14); printf("Sim");
								gotoxy(64,14); printf("Não");
								do{
									gotoxy(coluna,14); printf("->");
									if(kbhit){
										tecla=getch();
									}
					            	// seta para direita
					            	if(tecla==direita && a<=3){
										if(a==3){
					            			coluna=53;colunaAux=62;a=2;
										}
										else{
											colunaAux=coluna;
											coluna+=9;
											a++;
										}
									}
									// seta para esquerda
							        if(tecla==esquerda && a>=2){
										if(a==2){
					            		coluna=62;colunaAux=53;a=3;
										}
										else{
											colunaAux=coluna;
											coluna-=9;
											a--;
										}
									}
							        if(coluna!=colunaAux){
										gotoxy(colunaAux,14); printf("  ");
										colunaAux=coluna;
									}
							        if(tecla==enter){
										reprocessamento=a-1;
									}
								} while(reprocessamento==0);	
							}while(reprocessamento!=2);
			        	
			        		break; //Fim consultar arquivos
			        	case 2: //Renomear
			        	
			        		do{
			            		a=2;colunaAux=31;coluna=6;escolha=0;
				            	system("cls");
								system ("color B0");
				            	gotoxy(50,1); printf("-----RENOMEAR-----");
				            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				            	do{
				            		gotoxy(0,10); printf("                                                    ");
				            		gotoxy(25,8); printf("                                     ");
				            		gotoxy(25,6); printf("Digite o nome da pasta a qual renomeará");
									gotoxy(25,8); gets(pasta);
									strcpy(comando,"cd ");
									strcat(comando,pasta);
									gotoxy(25,9); system(comando);
								}while(system(comando)==1);
								strcpy(comando,"ren ");
								strcat(comando,pasta);
								gotoxy(0,10); printf("                                                    ");
				            	gotoxy(25,8); printf("                                     ");
				            	gotoxy(25,9); printf("                                                                                 ");
				            	gotoxy(25,6); printf("                                              ");
				            	gotoxy(25,6); printf("Digite o novo nome da pasta:");
								gotoxy(25,8); gets(pasta);
								strcat(comando," ");
								strcat(comando,pasta);
								gotoxy(25,9); printf("                                                     ");
								gotoxy(0,11);
								if (system(comando))
									getch();
				
								//Reprocessamento do renomear pasta
								a=2;colunaAux=2;coluna=53;reprocessamento=0;
								system("cls");
								system ("color B0");
								gotoxy(52,1); printf("-----RENOMEAR-----");
								gotoxy(1,28); printf("Conectado(a) como %s",nome);
								gotoxy(45,12); printf("Deseja renomear outra pasta?");
								gotoxy(55,14); printf("Sim");
								gotoxy(64,14); printf("Não");
								do{
									gotoxy(coluna,14); printf("->");
									if(kbhit){
										tecla=getch();
									}
					            	// seta para direita
					            	if(tecla==direita && a<=3){
										if(a==3){
					            			coluna=53;colunaAux=62;a=2;
										}
										else{
											colunaAux=coluna;
											coluna+=9;
											a++;
										}
									}
									// seta para esquerda
							        if(tecla==esquerda && a>=2){
										if(a==2){
					            		coluna=62;colunaAux=53;a=3;
										}
										else{
											colunaAux=coluna;
											coluna-=9;
											a--;
										}
									}
							        if(coluna!=colunaAux){
										gotoxy(colunaAux,14); printf("  ");
										colunaAux=coluna;
									}
							        if(tecla==enter){
										reprocessamento=a-1;
									}
								} while(reprocessamento==0);	
							}while(reprocessamento!=2);
			        	
			        		break; //Fim renomear
			        	case 3: //Excluir pasta/arqivos
			        		
				            system("cls");
							system ("color B0");
				            gotoxy(50,1); printf("-----EXCLUIR-----");
				            gotoxy(1,28); printf("Conectado(a) como %s",nome);
				            
							a=2;colunaAux=2;coluna=43;escolha=0;
							gotoxy(35,12); printf("Deseja excluir uma pasta ou arquivo?");
							gotoxy(45,14); printf("Pasta");
							gotoxy(65,14); printf("Arquivo");
							
							do{
								gotoxy(coluna,14); printf("->");
								if(kbhit){
									tecla=getch();
								}
				            	// seta para direita
				            	if(tecla==direita && a<=3){
									if(a==3){
				            			coluna=43;colunaAux=63;a=2;
									}
									else{
										colunaAux=coluna;
										coluna+=20;
										a++;
									}
								}
								// seta para esquerda
						        if(tecla==esquerda && a>=2){
									if(a==2){
				            		coluna=63;colunaAux=43;a=3;
									}
									else{
										colunaAux=coluna;
										coluna-=20;
										a--;
									}
								}
						        if(coluna!=colunaAux){
									gotoxy(colunaAux,14); printf("  ");
									colunaAux=coluna;
								}
						        if(tecla==enter){
									escolha=a-1;
								}
							}while(escolha==0);
								
							if (escolha==1)	
							{
								do{
			            		a=2;colunaAux=31;coluna=6;escolha=0;
				            	system("cls");
								system ("color B0");
				            	gotoxy(50,1); printf("-----EXCUIR-----");
				            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				            	
				            	do{
				            		gotoxy(0,10); printf("                                                    ");
				            		gotoxy(25,8); printf("                                     ");
				            		gotoxy(25,6); printf("Digite o nome da pasta que quer excluir");
									gotoxy(25,8); gets(pasta);
									strcpy(comando,"cd ");
									strcat(comando,pasta);
									gotoxy(25,9); system(comando);
								}while(system(comando)==1);
								gotoxy(25,9); printf("                                                    ");
								strcpy(comando,"rd /s ");
								strcat(comando,pasta);
								gotoxy(25,9);
								if(system(comando)){
									gotoxy(25,9);
									printf("Pasta não excluída. Pressione qualquer tecla para continuar.");getch();
								}
								//Reprocessamento do excluir pasta
								a=2;colunaAux=2;coluna=53;reprocessamento=0;
								system("cls");
								system ("color B0");
								gotoxy(52,1); printf("-----EXCLUIR-----");
								gotoxy(1,28); printf("Conectado(a) como %s",nome);
								gotoxy(45,12); printf("Deseja excluir outra pasta?");
								gotoxy(55,14); printf("Sim");
								gotoxy(64,14); printf("Não");
								do{
									gotoxy(coluna,14); printf("->");
									if(kbhit){
										tecla=getch();
									}
					            	// seta para direita
					            	if(tecla==direita && a<=3){
										if(a==3){
					            			coluna=53;colunaAux=62;a=2;
										}
										else{
											colunaAux=coluna;
											coluna+=9;
											a++;
										}
									}
									// seta para esquerda
							        if(tecla==esquerda && a>=2){
										if(a==2){
					            		coluna=62;colunaAux=53;a=3;
										}
										else{
											colunaAux=coluna;
											coluna-=9;
											a--;
										}
									}
							        if(coluna!=colunaAux){
										gotoxy(colunaAux,14); printf("  ");
										colunaAux=coluna;
									}
							        if(tecla==enter){
										reprocessamento=a-1;
									}
								 }while(reprocessamento==0);	
								}while(reprocessamento!=2);
							}else{
								
								do{
			            		a=2;colunaAux=31;coluna=6;escolha=0;
				            	system("cls");
								system ("color B0");
				            	gotoxy(50,1); printf("-----EXCLUIR-----");
				            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				            	
				            	do{
				            		gotoxy(0,10); printf("                                                    ");
				            		gotoxy(25,8); printf("                                     ");
				            		gotoxy(25,6); printf("Digite o nome da pasta que contém o arquivo que quer excluir");
									gotoxy(25,8); gets(pasta);
									strcpy(comando,"cd ");
									strcat(comando,pasta);
									gotoxy(25,9); system(comando);
								}while(system(comando)==1);
								chdir(pasta);
								gotoxy(25,9); printf("                                                    ");
								gotoxy(25,6); printf("                                                              "); 
								gotoxy(25,6); printf("Digite o nome do arquivo que quer excluir (Sem a extensão)");   
								gotoxy(25,8); printf("                                                              "); 
								gotoxy(25,8); gets(pasta);
								strcat(pasta, ".dat");  
								strcpy(comando,"del ");
								strcat(comando,pasta);
								gotoxy(25,9);
								if(system(comando)){
									gotoxy(25,9);
									printf("Arquivo não excluído. Pressione qualquer tecla para continuar.");getch();
								}
								//Reprocessamento do excluir arquivo
								a=2;colunaAux=2;coluna=53;reprocessamento=0;
								system("cls");
								system ("color B0");
								chdir("..");
								gotoxy(52,1); printf("-----EXCLUIR-----");
								gotoxy(1,28); printf("Conectado(a) como %s",nome);
								gotoxy(45,12); printf("Deseja excluir outro arquivo?");
								gotoxy(55,14); printf("Sim");
								gotoxy(64,14); printf("Não");
								do{
									gotoxy(coluna,14); printf("->");
									if(kbhit){
										tecla=getch();
									}
					            	// seta para direita
					            	if(tecla==direita && a<=3){
										if(a==3){
					            			coluna=53;colunaAux=62;a=2;
										}
										else{
											colunaAux=coluna;
											coluna+=9;
											a++;
										}
									}
									// seta para esquerda
							        if(tecla==esquerda && a>=2){
										if(a==2){
					            		coluna=62;colunaAux=53;a=3;
										}
										else{
											colunaAux=coluna;
											coluna-=9;
											a--;
										}
									}
							        if(coluna!=colunaAux){
										gotoxy(colunaAux,14); printf("  ");
										colunaAux=coluna;
									}
							        if(tecla==enter){
										reprocessamento=a-1;
									}
								 }while(reprocessamento==0);	
								}while(reprocessamento!=2);							
							}
			        		break; //Fim excluir pasta/arquivos
			        	case 4: //Mover arquivos		
					        system("cls");
							system ("color B0");
				            gotoxy(50,1); printf("-----MOVER/COPIAR-----");
				            gotoxy(1,28); printf("Conectado(a) como %s",nome);
		
							a=2;colunaAux=2;coluna=43;escolha=0;
							gotoxy(35,12); printf("Deseja mover ou copiar um arquivo?");
							gotoxy(45,14); printf("Mover");
							gotoxy(65,14); printf("Copiar");
							
							do{
								gotoxy(coluna,14); printf("->");
								if(kbhit){
									tecla=getch();
								}
				            	// seta para direita
				            	if(tecla==direita && a<=3){
									if(a==3){
				            			coluna=43;colunaAux=63;a=2;
									}
									else{
										colunaAux=coluna;
										coluna+=20;
										a++;
									}
								}
								// seta para esquerda
						        if(tecla==esquerda && a>=2){
									if(a==2){
				            		coluna=63;colunaAux=43;a=3;
									}
									else{
										colunaAux=coluna;
										coluna-=20;
										a--;
									}
								}
						        if(coluna!=colunaAux){
									gotoxy(colunaAux,14); printf("  ");
									colunaAux=coluna;
								}
						        if(tecla==enter){
									escolha=a-1;
								}
							}while(escolha==0);
										
					        if(escolha==1)
							{
								do{
									a=2;colunaAux=31;coluna=6;escolha=0;
					            	system("cls");
									system ("color B0");
					            	gotoxy(50,1); printf("-----MOVER-----");
					            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
					            	
					            	do{
					            		gotoxy(0,10); printf("                                                    ");
					            		gotoxy(25,8); printf("                                     ");
					            		gotoxy(25,6); printf("Digite o nome da pasta que contém o arquivo que quer mover");
										gotoxy(25,8); gets(pasta);
										strcpy(comando,"cd ");
										strcat(comando,pasta);
										gotoxy(25,9); system(comando);
									}while(system(comando)==1);
									chdir(pasta);
									gotoxy(25,9); printf("                                                    ");
									gotoxy(25,6); printf("                                                              "); 
									gotoxy(25,6); printf("Digite o nome do arquivo que quer mover (Sem a extensão)");   
									gotoxy(25,8); printf("                                                              "); 
									gotoxy(25,8); gets(pasta);
									strcat(pasta, ".dat");
									strcpy(comando, "move ");
									strcat(comando, pasta);
									strcat(comando, " ");
									gotoxy(25,6); printf("                                                              "); 
									gotoxy(25,6); printf("Digite o nome da pasta para qual que quer mover");   
									gotoxy(25,8); printf("                                                              "); 
									gotoxy(25,8); gets(pasta);  
									strcat(comando, " ..\\");
									strcat(comando,pasta);
									gotoxy(25,9);
									system(comando);
									getch();
										
									//Reprocessamento do mover arquivo
									a=2;colunaAux=2;coluna=53;reprocessamento=0;
									system("cls");
									system ("color B0");
									chdir("..");
									gotoxy(52,1); printf("-----MOVER-----");
									gotoxy(1,28); printf("Conectado(a) como %s",nome);
									gotoxy(45,12); printf("Deseja mover outro arquivo?");
									gotoxy(55,14); printf("Sim");
									gotoxy(64,14); printf("Não");
									do{
										gotoxy(coluna,14); printf("->");
										if(kbhit){
											tecla=getch();
										}
						            	// seta para direita
						            	if(tecla==direita && a<=3){
											if(a==3){
						            			coluna=53;colunaAux=62;a=2;
											}
											else{
												colunaAux=coluna;
												coluna+=9;
												a++;
											}
										}
										// seta para esquerda
								        if(tecla==esquerda && a>=2){
											if(a==2){
						            		coluna=62;colunaAux=53;a=3;
											}
											else{
												colunaAux=coluna;
												coluna-=9;
												a--;
											}
										}
								        if(coluna!=colunaAux){
											gotoxy(colunaAux,14); printf("  ");
											colunaAux=coluna;
										}
								        if(tecla==enter){
											reprocessamento=a-1;
										}
									}while(reprocessamento==0);	
								}while(reprocessamento!=2);		
							}else{
								do{
									a=2;colunaAux=31;coluna=6;escolha=0;
					            	system("cls");
									system ("color B0");
					            	gotoxy(50,1); printf("-----COPIAR-----");
					            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
					            	
					            	do{
					            		gotoxy(0,10); printf("                                                    ");
					            		gotoxy(25,8); printf("                                     ");
					            		gotoxy(25,6); printf("Digite o nome da pasta que contém o arquivo que quer copiar");
										gotoxy(25,8); gets(pasta);
										strcpy(comando,"cd ");
										strcat(comando,pasta);
										gotoxy(25,9); system(comando);
									}while(system(comando)==1);
									chdir(pasta);
									gotoxy(25,9); printf("                                                    ");
									gotoxy(25,6); printf("                                                              "); 
									gotoxy(25,6); printf("Digite o nome do arquivo que quer copiar (Sem a extensão)");   
									gotoxy(25,8); printf("                                                              "); 
									gotoxy(25,8); gets(pasta);
									strcat(pasta, ".dat");
									strcpy(comando, "copy ");
									strcat(comando, pasta);
									strcat(comando, " ");
									gotoxy(25,6); printf("                                                              "); 
									gotoxy(25,6); printf("Digite o nome da pasta para qual que quer copiar");   
									gotoxy(25,8); printf("                                                              "); 
									gotoxy(25,8); gets(pasta);  
									strcat(comando, " ..\\");
									strcat(comando,pasta);
									gotoxy(25,9);
									system(comando);
									getch();
										
									//Reprocessamento do copiar arquivo
									a=2;colunaAux=2;coluna=53;reprocessamento=0;
									system("cls");
									system ("color B0");
									chdir("..");
									gotoxy(52,1); printf("-----COPIAR-----");
									gotoxy(1,28); printf("Conectado(a) como %s",nome);
									gotoxy(45,12); printf("Deseja copiar outro arquivo?");
									gotoxy(55,14); printf("Sim");
									gotoxy(64,14); printf("Não");
									do{
										gotoxy(coluna,14); printf("->");
										if(kbhit){
											tecla=getch();
										}
						            	// seta para direita
						            	if(tecla==direita && a<=3){
											if(a==3){
						            			coluna=53;colunaAux=62;a=2;
											}
											else{
												colunaAux=coluna;
												coluna+=9;
												a++;
											}
										}
										// seta para esquerda
								        if(tecla==esquerda && a>=2){
											if(a==2){
						            		coluna=62;colunaAux=53;a=3;
											}
											else{
												colunaAux=coluna;
												coluna-=9;
												a--;
											}
										}
								        if(coluna!=colunaAux){
											gotoxy(colunaAux,14); printf("  ");
											colunaAux=coluna;
										}
								        if(tecla==enter){
											reprocessamento=a-1;
										}
									}while(reprocessamento==0);	
								}while(reprocessamento!=2);
							}
					        	
			        		break; //Fim mover arquivos
			        	case 5: //Alterar data e hora
			        	
			        		do{
								a=2;colunaAux=31;coluna=6;escolha=0;
				            	system("cls");
								system ("color B0");
				            	gotoxy(50,1); printf("-----DATA E HORA-----");
				            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
				            	gotoxy(0,10);
				            	strcpy(comando, "date");
				            	system(comando);
								printf("\n\n");
				            	strcpy(comando, "time");
				            	system(comando);
								printf("\n\nData e hora alterados com sucesso!");  
								getch();
									
								//Reprocessamento do mover arquivo
								a=2;colunaAux=2;coluna=53;reprocessamento=0;
								system("cls");
								system ("color B0");
								chdir("..");
								gotoxy(52,1); printf("-----MOVER-----");
								gotoxy(1,28); printf("Conectado(a) como %s",nome);
								gotoxy(45,12); printf("Deseja mudar data e hora de novo?");
								gotoxy(55,14); printf("Sim");
								gotoxy(64,14); printf("Não");
								do{
									gotoxy(coluna,14); printf("->");
									if(kbhit){
										tecla=getch();
									}
					            	// seta para direita
					            	if(tecla==direita && a<=3){
										if(a==3){
					            			coluna=53;colunaAux=62;a=2;
										}
										else{
											colunaAux=coluna;
											coluna+=9;
											a++;
										}
									}
									// seta para esquerda
							        if(tecla==esquerda && a>=2){
										if(a==2){
					            		coluna=62;colunaAux=53;a=3;
										}
										else{
											colunaAux=coluna;
											coluna-=9;
											a--;
										}
									}
							        if(coluna!=colunaAux){
										gotoxy(colunaAux,14); printf("  ");
										colunaAux=coluna;
									}
							        if(tecla==enter){
										reprocessamento=a-1;
									}
								}while(reprocessamento==0);	
							}while(reprocessamento!=2);		
			        	
			        	
			        		break; //Fim alterar data e hora
			        	case 6: //voltar
			        		break;
					}
				}while(opcao!=6);
            	break; //Fim alterar pastas
            case 7: //Créditos
            	system("cls");
            	system("color B0");
            	printf("Programa desenvolvido por: \nKaio Henrique A. D. de Paulo.\n");
            	printf("\nDisiciplina: \nAlgoritmos II.\n");
            	printf("\nProfessora: \nAndrea Vianna.\n");
            	printf("\nDescrição: \nO programa foi desenvolvido como o primeiro trabalho da disciplina em questão ");
            	printf("\ne tem o objetivo de sacar dinheiro e preencher cheques.\n");
            	printf("\nData de início: \n15 de novembro de 2021.\n");
            	printf("\nData de término: \n21 de novembro de 2021.\n");
            	printf("\nÚltima atualização: \n21 de novembro de 2021.\n\n");
            	gotoxy(1,27); printf("Conectado(a) como %s",nome);
            	gotoxy(1,28); system("pause");
            	break; //Fim créditos
            case 8: //Sair
           	 	system("cls");
                system ("color 0F");
                gotoxy(45,12.5); printf("Obrigado por utilizar o programa!");
                gotoxy(40,25); printf(" ");
                break; //Fim do programa
            case 9: //Iníco ajuda
            	system("cls");
            	system("color 9f");
            	FILE *criptografia;
				char texto[81];
				int i,tam;
				if((criptografia = fopen("Ajuda.txt","r")) == NULL){
					printf("\nFalha ao tentar abrir Ajuda.txt!");
					exit(1);
				}
				printf("\n\n\n\n");
				while(fgets(texto,80,criptografia) != NULL){
					tam=strlen(texto);
					for(i=0;i<tam-1;i++)
						texto[i]+=13;	
					printf("\t\t\t%s",texto);
				}
				fclose(criptografia);
            	gotoxy(1,28); printf("Conectado(a) como %s",nome);
            	gotoxy(37,20); system("pause");
            	break; //Fim ajuda
            default:
            	system("cls");
                printf("Você deve escolher uma opção válida\n");
                printf("Pressione qualquer tecla para voltar ao menu\n");
                system("pause");
                goto inicio;
        }
    }while(opcao!=8);
    return 0; //Fim da main
}