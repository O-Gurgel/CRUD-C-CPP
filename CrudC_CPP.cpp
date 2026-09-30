#include <stdio.h>
#include <conio2.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

#define TF 100

//structs
struct _alunos{
	char RA[13];      
	char nome[30];
};

struct _disciplinas{
	int cod;       
	char nome[50];
};

struct _notas{
	_alunos alunos;            
	_disciplinas disciplinas;
	float nota;          
};

//prototipo funcoes

void exec (void);
char menu (void);
char menuAlunos (void);
char menuDisciplinas (void);
char menuNotas (void);
char menuRelatorio (void);
void ImprimiMenuPrincipal (void);
void ImprimiMenuSub (void);
void ImprimiMenuRelatorio (void);


//buscas
int buscaAluno (_alunos alunos[], int TL, char RA[], int &pos);
int buscaDisciplina (_disciplinas disciplina[], int TL, int cod, int &pos);
int buscaNota (_notas notas[], int TL, char RA[], int cod, int &pos);

//alunos
void cadastroAluno (_alunos alunos[], int &TL);
void exibeAlunos (_alunos alunos[], int TL);
void exclusaoAlunos (_alunos alunos[], int &TL, _notas notas[], int &TLN);
void alteracaoAlunos (_alunos alunos[], int TL, _notas notas[], int TLN);
void consultaAlunos (_alunos alunos[], int TL);

//disciplinas
void cadastroDisciplina (_disciplinas disciplina[], int &TL);
void exibeDisciplina (_disciplinas disciplina[], int TL);
void exclusaoDisciplina (_disciplinas disciplina[], int &TL, _notas notas[], int &TLN);
void alteracaoDisciplina (_disciplinas disciplina[], int TL, _notas notas[], int TLN);
void consultaDisciplina (_disciplinas disciplina[], int TL);

//notas
void cadastroNota (_notas notas[], int &TLN, _alunos alunos[], int TLA, _disciplinas disciplina[], int TLD);
void exibeNotas (_notas notas[], int TL);
void exclusaoNota (_notas notas[], int &TL);
void alteracaoNota (_notas notas[], int TL);
void consultaNota (_notas notas[], int TL);

//dados teste
void InserirDadosTeste(_alunos TABalunos[], int &TLA, _disciplinas TABdisciplinas[], int &TLD, _notas TABnotas[], int &TLN);

//relatorios
void ExibeRelatorioGeral(_notas TABnotas[], int TLN, _alunos TABalunos[], int TLA, _disciplinas TABdisciplinas[], int TLD);
void MediasAbaixo(_disciplinas TABdisciplinas[], int TLD, _notas TABnotas[], int TLN);
void AlunosInicial(_alunos TABalunos[], int TLA, char L_ini);
int ContemTermo(char nome[], char termo[]);
void DisciplinasTermo(_disciplinas TABdisciplinas[], int TLD, char termo[]);
void AlunosReprovados(_alunos TABalunos[], int TLA, _notas TABnotas[], int TLN);

//ordernar
void ordenarAlunos(_alunos TABalunos[], int TLA);
void ordenarDisciplinas(_disciplinas TABdisciplinas[], int TLD);
void ordenarNotas(_notas TABnotas[TF], int TLN);

int main (){
	
	exec();
	
	return 0;
}

void exec(){  
	_alunos TABalunos[TF];
	_disciplinas TABdisciplinas[TF];
	_notas TABnotas[TF];
	
	int TLA = 0;
	int TLD = 0;
	int TLN = 0;
	int flag = 0;
	
	char letra;
	char termo[20];
	char opcao, sub;
	
	do{
		opcao = menu();
		switch (opcao){
			case 'A':	do{
							sub = menuAlunos();
							clrscr();
							switch (sub){
								case 'A':	cadastroAluno (TABalunos, TLA);
											break;
											
								case 'B':	exclusaoAlunos(TABalunos, TLA, TABnotas, TLN);
											break;
											
								case 'C':	ordenarAlunos(TABalunos, TLA);
											alteracaoAlunos(TABalunos, TLA, TABnotas, TLN);
											break;
											
								case 'D':   ordenarAlunos(TABalunos,TLA);
											consultaAlunos (TABalunos, TLA);
											break;
							}
						}while(sub != 13);
						break;
						
			case 'B':	do{
							sub = menuDisciplinas();
							clrscr();
							switch (sub){
								case 'A':	cadastroDisciplina(TABdisciplinas, TLD);
											break;
											
								case 'B':	exclusaoDisciplina(TABdisciplinas, TLD, TABnotas, TLN);
											break;
											
								case 'C':	ordenarDisciplinas(TABdisciplinas, TLD);
											alteracaoDisciplina(TABdisciplinas, TLD, TABnotas, TLN);
											break;
											
								case 'D':   ordenarDisciplinas(TABdisciplinas, TLD);
											consultaDisciplina(TABdisciplinas, TLD);
											break;
							}
						}while(sub != 13);
						break;
						
			case 'C':	do{
							sub = menuNotas();
							clrscr();
							switch (sub){
								case 'A':	cadastroNota(TABnotas, TLN, TABalunos, TLA, TABdisciplinas, TLD);
											break;
											
								case 'B':	exclusaoNota(TABnotas, TLN);
											break;
											
								case 'C':	ordenarNotas(TABnotas, TLN);
											alteracaoNota(TABnotas, TLN);
											break;
											
								case 'D':   ordenarNotas(TABnotas, TLN);
											consultaNota(TABnotas, TLN);
											break;
							}
						}while(sub != 13);
						break;
			
			case 'D': do{
						sub = menuRelatorio();
						clrscr();
						switch(sub){
							case 'A' : 	clrscr();
										ordenarNotas(TABnotas, TLN);
										AlunosReprovados(TABalunos, TLA, TABnotas, TLN);
										break;	
										
							case 'B' : 	clrscr();
										printf("Aluno(s) desejado começa com a letra:\n-->");
										letra = getch();
										clrscr();
										AlunosInicial(TABalunos, TLA, letra);
										break;	
										
							case 'C' : 	clrscr();
										printf("Digite o termo a ser buscado nas disciplinas:\n-->");
										gets(termo);
										clrscr();
										DisciplinasTermo(TABdisciplinas, TLD, termo);
										break;
									
										break;	
										
							case 'D' : 	clrscr();
										MediasAbaixo(TABdisciplinas, TLD, TABnotas, TLN);
										break;	
										
							case 'E' : 	clrscr();
										ordenarNotas(TABnotas, TLN);
										ExibeRelatorioGeral(TABnotas,TLN,TABalunos,TLA,TABdisciplinas,TLD);
										getch();
										break;									
						}
					}while(sub != 13);
					break;
			
			
			case 'E':	clrscr();
						if (flag == 0){
							InserirDadosTeste(TABalunos, TLA, TABdisciplinas, TLD, TABnotas, TLN);
							printf("Dados Teste Inseridos com sucesso.\n");
							flag = 1;
						}
						else
							printf("Dados tetes ja foram inseridos!!");
						getch();	
						break;
			
			default : 	clrscr();
						break;
				
		}
	}while(opcao != 27);
}

char menu (void){
	ImprimiMenuPrincipal();
	return toupper(getche());
}

char menuAlunos (void){
	ImprimiMenuSub();
	return toupper(getche());
}

char menuDisciplinas (void){
	ImprimiMenuSub();
	return toupper(getche());
}

char menuNotas (void){
	ImprimiMenuSub();
	return toupper(getche());
}

char menuRelatorio (void){
	ImprimiMenuRelatorio();
	return toupper(getche());
}

//buscas
int buscaAluno (_alunos alunos[], int TL, char RA[], int &pos){
	int i = 0;
	while(i < TL && strcmp(RA, alunos[i].RA) != 0)
		i++;
	
	if (i < TL){
		pos = i;
		return 1;
	}
	return 0;
}

int buscaDisciplina (_disciplinas disciplina[], int TL, int cod, int &pos){
	int i = 0;
	while(i < TL && cod != disciplina[i].cod)
		i++;
	
	if (i < TL){
		pos = i;
		return 1;
	}
	return 0;
}

int buscaNota (_notas notas[], int TL, char RA[], int cod, int &pos){
	int i = 0;
	while(i < TL && !(strcmp(RA, notas[i].alunos.RA) == 0 && cod == notas[i].disciplinas.cod))
		i++;
	
	if (i < TL){
		pos = i;
		return 1;
	}
	return 0;
}

//alunos

void cadastroAluno (_alunos alunos[], int &TL){
	char RAaux[100], nomeaux[30];
	int pos;
	
	printf("Digite o RA do aluno a ser cadastrado (ENTER para sair) : \n");
	gets(RAaux);
	while(strlen(RAaux) > 0 && TL < TF){
		if (strlen(RAaux) > 12)
			printf("RA invalido! Use no maximo 12 caracteres (ex: 26.09.1045-1)\n");
		else{
			if (buscaAluno(alunos, TL, RAaux, pos))
				printf("Ja existe aluno com o RA [%s]!\n", RAaux);
			else{
				printf("Digite o nome do aluno : ");
				gets(nomeaux);
				
				strcpy(alunos[TL].RA, RAaux);
				strcpy(alunos[TL].nome, nomeaux);
				
				TL++;
				printf("Aluno cadastrado com sucesso!\n");
			}
		}
		
		if (TL < TF){
			printf("\nDigite o RA do aluno a ser cadastrado (ENTER para sair) : \n");
			gets(RAaux);
		}
	}
	
	if (TL >= TF){
		printf("Nao ha mais espaco para cadastrar alunos!!");
		printf("\nPressione qualquer tecla para continuar...");
		getch();
	}
}

void exibeAlunos (_alunos alunos[], int TL){
	int i;
	
	if (TL == 0){
		printf("Nenhum aluno cadastrado!\n");
	}
	else{
		for (i = 0; i < TL; i++){
			printf("%s --- %s\n", alunos[i].RA, alunos[i].nome);
		}
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void exclusaoAlunos (_alunos alunos[], int &TL, _notas notas[], int &TLN){
	int i, j, k;
	char RAaux[100];
	
	printf("Digite o RA do aluno a ser excluido : \n");
	gets(RAaux);
	
	if (!buscaAluno(alunos, TL, RAaux, i))
		printf("Aluno com RA [%s] nao encontrado!!\n", RAaux);
	else{
		for(j = i; j < TL - 1; j++)
			alunos[j] = alunos[j + 1];
		
		TL--;
		

		k = 0;
		while(k < TLN){
			if (strcmp(RAaux, notas[k].alunos.RA) == 0){
				for(j = k; j < TLN - 1; j++)
					notas[j] = notas[j + 1];
				
				TLN--;
			}
			else
				k++;
		}
		
		printf("Aluno e suas notas excluidos com sucesso!\n");
	}
		
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void alteracaoAlunos (_alunos alunos[], int TL, _notas notas[], int TLN){
	int pos, k;
	char RAaux[100], nomeaux[30];
	
	printf("Digite o RA do aluno a ser alterado : \n");
	gets(RAaux);
	
	if (!buscaAluno(alunos, TL, RAaux, pos))
		printf("Aluno com RA [%s] nao encontrado!!\n", RAaux);
	else{
		printf("RA: %s\nNome atual: %s\n", alunos[pos].RA, alunos[pos].nome);
		printf("\nDigite o novo nome (ENTER para manter) : ");
		gets(nomeaux);
		
		if (strlen(nomeaux) > 0){
			strcpy(alunos[pos].nome, nomeaux);
			

			for(k = 0; k < TLN; k++){
				if (strcmp(RAaux, notas[k].alunos.RA) == 0)
					notas[k].alunos = alunos[pos];
			}
			
			printf("Aluno alterado com sucesso!\n");
		}
		else
			printf("Nenhuma alteracao feita.\n");
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void consultaAlunos (_alunos alunos[], int TL){
	int pos;
	char RAaux[100];
	
	printf("Digite o RA a consultar (ENTER para listar todos) : \n");
	gets(RAaux);
	
	if (strlen(RAaux) == 0)
		exibeAlunos(alunos, TL);
	else{
		if (!buscaAluno(alunos, TL, RAaux, pos))
			printf("Aluno com RA [%s] nao encontrado!!\n", RAaux);
		else
			printf("\nRA: %s\nNome: %s\n", alunos[pos].RA, alunos[pos].nome);
		
		printf("\nPressione qualquer tecla para continuar...");
		getch();
	}
}

//disciplinas

void cadastroDisciplina (_disciplinas disciplina[], int &TL){
	char nomeaux[50];
	int CodAux, pos;
	
	printf("Digite o codigo da disciplina a ser cadastrada (0 para sair) : \n");
	scanf("%d", &CodAux);
	fflush(stdin);
	while(CodAux > 0 && TL < TF){
		if (buscaDisciplina(disciplina, TL, CodAux, pos))
			printf("Ja existe disciplina com o codigo [%d]!\n", CodAux);
		else{
			printf("Digite o nome da disciplina : ");
			gets(nomeaux);
			
			disciplina[TL].cod = CodAux;
			strcpy(disciplina[TL].nome, nomeaux);
			
			TL++;
			printf("Disciplina cadastrada com sucesso!\n");
		}
		
		if (TL < TF){
			printf("\nDigite o codigo da disciplina a ser cadastrada (0 para sair) : \n");
			scanf("%d", &CodAux);
			fflush(stdin);
		}
	}
	
	if (TL >= TF){
		printf("Nao ha mais espaco para cadastrar disciplinas!!");
		printf("\nPressione qualquer tecla para continuar...");
		getch();
	}
}

void exibeDisciplina (_disciplinas disciplina[], int TL){
	int i;
	
	if (TL == 0){
		printf("Nenhuma disciplina cadastrada!\n");
	}
	else{
		for (i = 0; i < TL; i++){
			printf("%d --- %s\n", disciplina[i].cod, disciplina[i].nome);
		}
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void exclusaoDisciplina (_disciplinas disciplina[], int &TL, _notas notas[], int &TLN){
	int i, j, k, CodAux;
	
	printf("Digite o codigo da disciplina a ser excluida : \n");
	scanf("%d", &CodAux);
	fflush(stdin);
	
	if (!buscaDisciplina(disciplina, TL, CodAux, i))
		printf("Disciplina com codigo [%d] nao encontrada!!\n", CodAux);
	else{
		for(j = i; j < TL - 1; j++)
			disciplina[j] = disciplina[j + 1];
		
		TL--;
		
		k = 0;
		while(k < TLN){
			if (CodAux == notas[k].disciplinas.cod){
				for(j = k; j < TLN - 1; j++)
					notas[j] = notas[j + 1];
				
				TLN--;
			}
			else
				k++;
		}
		
		printf("Disciplina e suas notas excluidas com sucesso!\n");
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void alteracaoDisciplina (_disciplinas disciplina[], int TL, _notas notas[], int TLN){
	int pos, k, CodAux;
	char nomeaux[50];
	
	printf("Digite o codigo da disciplina a ser alterada : \n");
	scanf("%d", &CodAux);
	fflush(stdin);
	
	if (!buscaDisciplina(disciplina, TL, CodAux, pos))
		printf("Disciplina com codigo [%d] nao encontrada!!\n", CodAux);
	else{
		printf("Codigo: %d\nNome atual: %s\n", disciplina[pos].cod, disciplina[pos].nome);
		printf("\nDigite o novo nome (ENTER para manter) : ");
		gets(nomeaux);
		
		if (strlen(nomeaux) > 0){
			strcpy(disciplina[pos].nome, nomeaux);
			
			for(k = 0; k < TLN; k++){
				if (CodAux == notas[k].disciplinas.cod)
					notas[k].disciplinas = disciplina[pos];
			}
			
			printf("Disciplina alterada com sucesso!\n");
		}
		else
			printf("Nenhuma alteracao feita.\n");
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void consultaDisciplina (_disciplinas disciplina[], int TL){
	int pos, CodAux;
	
	printf("Digite o codigo a consultar (0 para listar todas) : \n");
	scanf("%d", &CodAux);
	fflush(stdin);
	
	if (CodAux == 0)
		exibeDisciplina(disciplina, TL);
	else{
		if (!buscaDisciplina(disciplina, TL, CodAux, pos))
			printf("Disciplina com codigo [%d] nao encontrada!!\n", CodAux);
		else
			printf("\nCodigo: %d\nNome: %s\n", disciplina[pos].cod, disciplina[pos].nome);
		
		printf("\nPressione qualquer tecla para continuar...");
		getch();
	}
}

//notas

void cadastroNota (_notas notas[], int &TLN, _alunos alunos[], int TLA, _disciplinas disciplina[], int TLD){
	char RAaux[100];
	int CodAux, pos, posA, posD;
	float notaAux;
	
	printf("Digite o RA do aluno (ENTER para sair) : \n");
	gets(RAaux);
	while(strlen(RAaux) > 0 && TLN < TF){
		if (!buscaAluno(alunos, TLA, RAaux, posA))
			printf("Aluno com RA [%s] nao encontrado! Cadastre o aluno primeiro.\n", RAaux);
		else{
			printf("Digite o codigo da disciplina : ");
			scanf("%d", &CodAux);
			fflush(stdin);
			
			if (!buscaDisciplina(disciplina, TLD, CodAux, posD))
				printf("Disciplina com codigo [%d] nao encontrada! Cadastre a disciplina primeiro.\n", CodAux);
			else{
				if (buscaNota(notas, TLN, RAaux, CodAux, pos))
					printf("Este aluno ja possui nota nesta disciplina!\n");
				else{
					printf("Digite a nota (0 a 10) : ");
					scanf("%f", &notaAux);
					fflush(stdin);
					
					if (notaAux < 0 || notaAux > 10)
						printf("Nota invalida! Deve estar entre 0 e 10.\n");
					else{
						notas[TLN].alunos = alunos[posA];
						notas[TLN].disciplinas = disciplina[posD];
						notas[TLN].nota = notaAux;
						
						TLN++;
						printf("Nota cadastrada com sucesso!\n");
					}
				}
			}
		}
		
		if (TLN < TF){
			printf("\nDigite o RA do aluno (ENTER para sair) : \n");
			gets(RAaux);
		}
	}
	
	if (TLN >= TF){
		printf("Nao ha mais espaco para cadastrar notas!!");
		printf("\nPressione qualquer tecla para continuar...");
		getch();
	}
}

void exibeNotas (_notas notas[], int TL){
	int i;
	
	if (TL == 0){
		printf("Nenhuma nota cadastrada!\n");
	}
	else{
		printf("RA            Disc.  Nota  Aluno / Disciplina\n");
		for (i = 0; i < TL; i++){
			printf("%-12s  %-5d  %.1f   %s / %s\n", notas[i].alunos.RA, notas[i].disciplinas.cod, notas[i].nota, notas[i].alunos.nome, notas[i].disciplinas.nome);
		}
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void exclusaoNota (_notas notas[], int &TL){
	int i, j, CodAux;
	char RAaux[100];
	
	printf("Digite o RA do aluno : \n");
	gets(RAaux);
	printf("Digite o codigo da disciplina : \n");
	scanf("%d", &CodAux);
	fflush(stdin);
	
	if (!buscaNota(notas, TL, RAaux, CodAux, i))
		printf("Nota do aluno [%s] na disciplina [%d] nao encontrada!!\n", RAaux, CodAux);
	else{
		for(j = i; j < TL - 1; j++)
			notas[j] = notas[j + 1];
		
		TL--;
		printf("Nota excluida com sucesso!\n");
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void alteracaoNota (_notas notas[], int TL){
	int pos, CodAux;
	char RAaux[100];
	float notaAux;
	
	printf("Digite o RA do aluno : \n");
	gets(RAaux);
	printf("Digite o codigo da disciplina : \n");
	scanf("%d", &CodAux);
	fflush(stdin);
	
	if (!buscaNota(notas, TL, RAaux, CodAux, pos))
		printf("Nota do aluno [%s] na disciplina [%d] nao encontrada!!\n", RAaux, CodAux);
	else{
		printf("Nota atual: %.1f\n", notas[pos].nota);
		printf("Digite a nova nota (0 a 10) : ");
		scanf("%f", &notaAux);
		fflush(stdin);
		
		if (notaAux < 0 || notaAux > 10)
			printf("Nota invalida! Nenhuma alteracao feita.\n");
		else{
			notas[pos].nota = notaAux;
			printf("Nota alterada com sucesso!\n");
		}
	}
	
	printf("\nPressione qualquer tecla para continuar...");
	getch();
}

void consultaNota (_notas notas[], int TL){
	int pos, CodAux;
	char RAaux[100];
	
	printf("Digite o RA a consultar (ENTER para listar todas) : \n");
	gets(RAaux);
	
	if (strlen(RAaux) == 0)
		exibeNotas(notas, TL);
	else{
		printf("Digite o codigo da disciplina : \n");
		scanf("%d", &CodAux);
		fflush(stdin);
		
		if (!buscaNota(notas, TL, RAaux, CodAux, pos))
			printf("Nota do aluno [%s] na disciplina [%d] nao encontrada!!\n", RAaux, CodAux);
		else
			printf("\nRA: %s\nAluno: %s\nDisciplina: %d - %s\nNota: %.1f\n", notas[pos].alunos.RA, notas[pos].alunos.nome, notas[pos].disciplinas.cod, notas[pos].disciplinas.nome, notas[pos].nota);
		
		printf("\nPressione qualquer tecla para continuar...");
		getch();
	}
}

// DADOS TESTE // 
void InserirDadosTeste (_alunos TABalunos[], int &TLA, _disciplinas TABdisciplinas[], int &TLD, _notas TABnotas[], int &TLN) {
	
	strcpy(TABalunos[TLA].RA, "26.09.1045-1"); 
	strcpy(TABalunos[TLA].nome, "Carolina");
	TLA++;
	
	
	strcpy(TABalunos[TLA].RA, "10.09.1055-3"); 
	strcpy(TABalunos[TLA].nome, "Enzo");
	TLA++;
	
	strcpy(TABalunos[TLA].RA, "26.09.2012-1"); 
	strcpy(TABalunos[TLA].nome, "Francisco");
	TLA++;
	
	strcpy(TABalunos[TLA].RA, "10.09.3052-6"); 
	strcpy(TABalunos[TLA].nome, "Leandro");
	TLA++;
	
	strcpy(TABalunos[TLA].RA, "26.09.3444-8"); 
	strcpy(TABalunos[TLA].nome, "Petronio");
	TLA++;
	
	TABdisciplinas[TLD].cod = 100;
	strcpy(TABdisciplinas[TLD].nome, "ATP I");
	TLD++;
	
	TABdisciplinas[TLD].cod = 105;
	strcpy(TABdisciplinas[TLD].nome, "ATP II");
	TLD++;
	
	TABdisciplinas[TLD].cod = 120;
	strcpy(TABdisciplinas[TLD].nome, "Estruturas de Dados I");
	TLD++;
	
	TABdisciplinas[TLD].cod = 150;
	strcpy(TABdisciplinas[TLD].nome, "Pesquisa e Ordenacao");
	TLD++;
	
	TABdisciplinas[TLD].cod = 210;
	strcpy(TABdisciplinas[TLD].nome, "Ferramentas I");
	TLD++;
	
	TABdisciplinas[TLD].cod = 230;
	strcpy(TABdisciplinas[TLD].nome, "Estatistica");
	TLD++;
	
	TABdisciplinas[TLD].cod = 240;
	strcpy(TABdisciplinas[TLD].nome, "Matematica Discreta");
	TLD++;
	
	strcpy(TABnotas[TLN].alunos.RA, "26.09.1045-1");
	TABnotas[TLN].disciplinas.cod = 120;
	TABnotas[TLN].nota = 8.0;
	strcpy(TABnotas[TLN].alunos.nome, "Carolina");
	strcpy(TABnotas[TLN].disciplinas.nome, "Estruturas de Dados I");
	TLN++;
	
	strcpy(TABnotas[TLN].alunos.RA, "26.09.1045-1");
	TABnotas[TLN].disciplinas.cod = 210;
	TABnotas[TLN].nota = 4.5;
	strcpy(TABnotas[TLN].alunos.nome, "Carolina");
	strcpy(TABnotas[TLN].disciplinas.nome, "Ferramentas I");
	TLN++;
	
	strcpy(TABnotas[TLN].alunos.RA, "26.09.1045-1");
	TABnotas[TLN].disciplinas.cod = 230;
	TABnotas[TLN].nota = 6.5;
	strcpy(TABnotas[TLN].alunos.nome, "Carolina");
	strcpy(TABnotas[TLN].disciplinas.nome, "Estatistica");
	TLN++;
	
	strcpy(TABnotas[TLN].alunos.RA, "10.09.1055-3");
	TABnotas[TLN].disciplinas.cod = 150;
	TABnotas[TLN].nota = 5.0;
	strcpy(TABnotas[TLN].alunos.nome, "Enzo");
	strcpy(TABnotas[TLN].disciplinas.nome, "Pesquisa e Ordenacao");
	TLN++;
	
	strcpy(TABnotas[TLN].alunos.RA, "10.09.1055-3");
	TABnotas[TLN].disciplinas.cod = 240;
	TABnotas[TLN].nota = 4.5;
	strcpy(TABnotas[TLN].alunos.nome, "Enzo");
	strcpy(TABnotas[TLN].disciplinas.nome, "Matematica Discreta");
	TLN++;
	
	strcpy(TABnotas[TLN].alunos.RA, "26.09.2012-1");
	TABnotas[TLN].disciplinas.cod = 100;
	TABnotas[TLN].nota = 7.0;
	strcpy(TABnotas[TLN].alunos.nome, "Francisco");
	strcpy(TABnotas[TLN].disciplinas.nome, "ATP I");
	TLN++;
	
	strcpy(TABnotas[TLN].alunos.RA, "26.09.2012-1");
	TABnotas[TLN].disciplinas.cod = 210;
	TABnotas[TLN].nota = 6.0;
	strcpy(TABnotas[TLN].alunos.nome, "Francisco");
	strcpy(TABnotas[TLN].disciplinas.nome, "Ferramentas I");
	TLN++;
	
	strcpy(TABnotas[TLN].alunos.RA, "26.09.2012-1");
	TABnotas[TLN].disciplinas.cod = 230;
	TABnotas[TLN].nota = 9.0;
	strcpy(TABnotas[TLN].alunos.nome, "Francisco");
	strcpy(TABnotas[TLN].disciplinas.nome, "Estatistica");
	TLN++;
}

//MENUS

void ImprimiMenuPrincipal (void){
	int i;
	clrscr();
	printf("%c", 201);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 187);


    printf("%c   MENU DE SELECAO   %c\n", 186, 186);
    textcolor(WHITE);


    printf("%c", 204);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 185);

    printf("%c                     %c\n", 186, 186);
    printf("%c     [A] Alunos      %c\n", 186, 186);
    printf("%c     [B] Disciplinas %c\n", 186, 186);
    printf("%c     [C] Notas       %c\n", 186, 186);
    printf("%c     [D] Relatorios  %c\n", 186, 186);
	printf("%c     [E] Dados       %c\n", 186, 186);
    
    printf("%c    [ESC] SAIR       %c\n", 186, 186);
    printf("%c                     %c\n", 186, 186);


    printf("%c", 200);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 188);
    printf("\t--> ");
}

void ImprimiMenuSub (void) {
	int i;
	clrscr();
	printf("%c", 201);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 187);


    printf("%c   MENU DE SELECAO   %c\n", 186, 186);
    textcolor(WHITE);


    printf("%c", 204);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 185);

    printf("%c                     %c\n", 186, 186);
    printf("%c    [A] Cadastro     %c\n", 186, 186);
    printf("%c    [B] Exclusao     %c\n", 186, 186);
    printf("%c    [C] Alteracao    %c\n", 186, 186);
    printf("%c    [D] Consultas    %c\n", 186, 186);
    printf("%c    [ENTER] SAIR     %c\n", 186, 186);
    printf("%c                     %c\n", 186, 186);


    printf("%c", 200);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 188);
    printf("\t--> ");
}

void ImprimiMenuRelatorio (void){
	int i;
	clrscr();
	printf("%c", 201);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 187);


    printf("%c   MENU DE SELECAO   %c\n", 186, 186);
    textcolor(WHITE);


    printf("%c", 204);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 185);

    printf("%c                     %c\n", 186, 186);
    printf("%c[A] Al. reprovado 2+ %c\n", 186, 186);
    printf("%c[B] Al. letra inicial%c\n", 186, 186);
    printf("%c[C] Disc por termo   %c\n", 186, 186);
    printf("%c[D] Disc media < 6.0 %c\n", 186, 186);
    printf("%c[E] Ficha compl Als. %c\n", 186, 186);
    printf("%c    [ENTER] SAIR     %c\n", 186, 186);
    printf("%c                     %c\n", 186, 186);


    printf("%c", 200);
    for (i = 0; i < 21; i++)
        printf("%c", 205);
    printf("%c\n", 188);
    printf("\t--> ");
}

//relatorios

void ExibeRelatorioGeral(_notas TABnotas[], int TLN, _alunos TABalunos[], int TLA, _disciplinas TABdisciplinas[], int TLD){
	int i, j, pos, achou;
	
	for (i = 0; i < TLA; i++){
		textcolor(15);
		printf("   RA: %s      nome: %s\n", TABalunos[i].RA, TABalunos[i].nome);
		achou = 0;
		
		for (j = 0; j < TLD; j++){
			if (buscaNota(TABnotas, TLN, TABalunos[i].RA, TABdisciplinas[j].cod, pos)){
				if (TABnotas[pos].nota >= 6){
					textcolor(2);
					printf("\t\tDisciplina: %d  -  %-20s\tNota: %.1f  Situacao: Aprovado\n", TABdisciplinas[j].cod, TABdisciplinas[j].nome, TABnotas[pos].nota);
						
				}
				else{
					textcolor(4);
					printf("\t\tDisciplina: %d  -  %-20s\tNota: %.1f  Situacao: Reprovado\n", TABdisciplinas[j].cod, TABdisciplinas[j].nome, TABnotas[pos].nota);
				}
					
				achou = 1;
			}
		}
		
		if (achou == 0){
			textcolor(14);
			printf("\t\tNenhuma nota cadastrada.\n");
		}
			
		
		printf("\n\n");
	}
	
	textcolor(15);
}

void MediasAbaixo(_disciplinas TABdisciplinas[], int TLD, _notas TABnotas[], int TLN){
	
	if(TLD > 0 && TLN > 0) {
		printf("Disciplina 	/ Nome\t\t\tMedia\n");
		for (int i = 0; i < TLD; i++){
		
		    float soma = 0;
		    int quantidade = 0;
		
		    for (int j = 0; j < TLN; j++){
		    
		        if (TABdisciplinas[i].cod == TABnotas[j].disciplinas.cod) {
		       
		        	soma += TABnotas[j].nota;
		            quantidade++;
		        }
		    }
		
		    if (quantidade > 0){
		    
		        float media = soma / quantidade;
		
		        if (media < 6.0){
		            printf("%-5d --- %-20s\t\t%.1f\n", TABdisciplinas[i].cod, TABdisciplinas[i].nome, media);
		        }
		    }
		}
	}
	else
		printf("Não há disciplinas, ou não há notas cadastradas.\n");
	
	getch();
}

void AlunosInicial(_alunos TABalunos[], int TLA, char L_ini){
	if(TLA > 0) {
		printf("Alunos com a letra %c.\n\n", L_ini);
		
		for(int i = 0; i < TLA; i++){
			if(toupper(TABalunos[i].nome[0]) == toupper(L_ini))
				printf("%-14s --- %s\n", TABalunos[i].RA, TABalunos[i].nome);
		}
	}
	else
		printf("Não há alunos cadastrados.\n");
	
	getch();
}

int ContemTermo(char nome[], char termo[]){
	int i, j;
	
	i = 0;
	while (nome[i] != '\0'){
		j = 0;
		while (termo[j] != '\0' && nome[i + j] != '\0' && toupper(nome[i + j]) == toupper(termo[j]))
			j++;
		
		if (termo[j] == '\0')
			return 1;
		
		i++;
	}
	return 0;
}

void DisciplinasTermo(_disciplinas TABdisciplinas[], int TLD, char termo[]){
	int i, achou = 0;
	
	if (TLD > 0){
		printf("Disciplinas contendo o termo \"%s\":\n\n", termo);
		
		for (i = 0; i < TLD; i++){
			if (ContemTermo(TABdisciplinas[i].nome, termo)){
				printf("%-5d --- %s\n", TABdisciplinas[i].cod, TABdisciplinas[i].nome);
				achou = 1;
			}
		}
		
		if (achou == 0)
			printf("Nenhuma disciplina contem o termo \"%s\".\n", termo);
	}
	else
		printf("Não há disciplinas cadastradas.\n");
	
	getch();
}

void AlunosReprovados(_alunos TABalunos[], int TLA, _notas TABnotas[], int TLN){
	int i, j, reprovacoes, achou = 0;
	
	if (TLA > 0 && TLN > 0){
		printf("Alunos reprovados em 2 ou mais disciplinas:\n\n");
		
		for (i = 0; i < TLA; i++){
			reprovacoes = 0;
			
			for (j = 0; j < TLN; j++){
				if (strcmp(TABalunos[i].RA, TABnotas[j].alunos.RA) == 0 && TABnotas[j].nota < 6)
					reprovacoes++;
			}
			
			if (reprovacoes >= 2){
				printf("%-14s --- %s\n", TABalunos[i].RA, TABalunos[i].nome);
				achou = 1;
			}
		}
		
		if (achou == 0)
			printf("Nenhum aluno reprovado em 2 ou mais disciplinas.\n");
	}
	else
		printf("Não há alunos, ou não há notas cadastradas.\n");
	
	getch();
}

void ordenarAlunos(_alunos TABalunos[], int TLA) {
	int flag = 1;
	
	while(TLA > 1 && flag == 1) {
		flag = 0;
		for(int i = 0; i < TLA - 1; i++)
			if(stricmp(TABalunos[i].RA, TABalunos[i+1].RA) == 1) {
				
				struct _alunos aux;

				aux = TABalunos[i];
				TABalunos[i] = TABalunos[i+1];
				TABalunos[i+1] = aux;
				
				flag = 1;
			}
		TLA--;
	}
}

void ordenarDisciplinas(_disciplinas TABdisciplinas[], int TLD) {
	int flag = 1;
	
	while(TLD > 1 && flag == 1) {
		flag = 0;
		for(int i = 0; i < TLD - 1; i++)
			if(TABdisciplinas[i].cod > TABdisciplinas[i + 1].cod) {
				
				struct _disciplinas aux;

				aux = TABdisciplinas[i];
				TABdisciplinas[i] = TABdisciplinas[i+1];
				TABdisciplinas[i+1] = aux;
				
				flag = 1;
			}
		TLD--;
	}
}

void ordenarNotas(_notas TABnotas[TF], int TLN) {
	int flag = 1;
	
	while(TLN > 1 && flag == 1) {
		flag = 0;
		for(int i = 0; i < TLN - 1; i++)
			if(stricmp(TABnotas[i].alunos.RA, TABnotas[i+1].alunos.RA) == 1 || stricmp(TABnotas[i].alunos.RA, TABnotas[i+1].alunos.RA) == 0 && TABnotas[i].disciplinas.cod > TABnotas[i+1].disciplinas.cod) {
				
				struct _notas aux;

				aux = TABnotas[i];
				TABnotas[i] = TABnotas[i+1];
				TABnotas[i+1] = aux;
				
				flag = 1;
			}
		TLN--;
	}
}



