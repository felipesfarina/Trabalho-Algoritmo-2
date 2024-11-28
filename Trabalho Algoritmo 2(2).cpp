#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

struct TpLivro
{
	int idLivro, AnoPublicacao, Status;
	char Titulo[20];
};

struct TpAutor
{
	int idAutor, Status;
	char Nome[20], Nacionalidade[20];
};

struct TpData
{
	int d,m,a;
};

struct TpEmprestimo
{
	int idEmprestimo, idLivro, idPessoa, Status;
	TpData dataEmprestimo;
	TpData dataDevolucao;
};

struct TpPessoa
{
	int idPessoa, Telefone, Status; 
	char Nome[30], Endereco[20];
};

struct TpLivroAutor
{
	int idLivro, idAutor;	
};


// --------------> MOLDURAS <-------------- //

void Moldura ()
{
	//////////////////// MOLDURA PRINCIPAL ////////////////////
	int i, CE=6, CD=90, LE=2, LD=28;
	
	gotoxy(CE,LE);
	printf("%c", 201);
	gotoxy(CD,LE);
	printf("%c", 187);
	
	gotoxy(CE,LD);
	printf("%c", 200);
	gotoxy(CD,LD);
	printf("%c", 188);

	for (i = CE+1; i<CD; i++) {
		gotoxy(i,LE);
		printf("%c", 205);
		gotoxy(i,LD);
		printf("%c", 205);
		Sleep(10);
	}
	
	for (i = LE+1; i<LD; i++) {
		gotoxy(CE,i);
		printf("%c", 186);
		gotoxy(CD,i);
		printf("%c", 186);
		Sleep(10);
	}


	//////////////////// MOLDURA NOME ////////////////////
	CE=7, CD=89, LE=3, LD=5;
	
	gotoxy(CE,LE);
	printf("%c", 201);
	gotoxy(CD,LE);
	printf("%c", 187);
	
	gotoxy(CE,LD);
	printf("%c", 200);
	gotoxy(CD,LD);
	printf("%c", 188);
	
	for (i = CE+1; i<CD; i++) {
		gotoxy(i,LE);
		printf("%c", 205);
		gotoxy(i,LD);
		printf("%c", 205);
		Sleep(10);
	}
	
	for (i = LE+1; i<LD; i++) {
		gotoxy(CE,i);
		printf("%c", 186);
		gotoxy(CD,i);
		printf("%c", 186);
		Sleep(10);
	}
	gotoxy(42,4);
	textcolor(2);
	printf(".:: ACERVO ::."); textcolor(15);
	
	
	//////////////////// MOLDURA MENU ////////////////////
	CE=7, CD=30, LE=6, LD=27;
	
	gotoxy(CE,LE);
	printf("%c", 201);
	gotoxy(CD,LE);
	printf("%c", 187);
	
	gotoxy(CE,LD);
	printf("%c", 200);
	gotoxy(CD,LD);
	printf("%c", 188);

	for (i = CE+1; i<CD; i++) {
		gotoxy(i,LE);
		printf("%c", 205);
		gotoxy(i,LD);
		printf("%c", 205);
		Sleep(10);
	}
	
	for (i = LE+1; i<LD; i++) {
		gotoxy(CE,i);
		printf("%c", 186);
		gotoxy(CD,i);
		printf("%c", 186);
		Sleep(10);
	}
	gotoxy(11,7);
	textcolor(2);
	printf(".:: M E N U ::."); textcolor(15);
	
	gotoxy(CE, 8);
	printf("%c", 204);
	gotoxy(CD, 8);
	printf("%c", 185);
	for (i=CE+1; i<CD; i++) {
		gotoxy(i,8);
		printf("%c", 205);
	}
	
	
	//////////////////// MOLDURA AÇÃO ////////////////////
	CE=31, CD=89, LE=6, LD=27;
	
	gotoxy(CE,LE);
	printf("%c", 201);
	gotoxy(CD,LE);
	printf("%c", 187);
	
	gotoxy(CE,LD);
	printf("%c", 200);
	gotoxy(CD,LD);
	printf("%c", 188);
	
	for (i = CE+1; i<CD; i++) {
		gotoxy(i,LE);
		printf("%c", 205);
		gotoxy(i,LD);
		printf("%c", 205);
		Sleep(10);
	}
	
	for (i = LE+1; i<LD; i++) {
		gotoxy(CE,i);
		printf("%c", 186);
		gotoxy(CD,i);
		printf("%c", 186);
		Sleep(10);
	}
}

// --------------> LIMPAR <-------------- //

void LimparTela()
{
	int x, y, CE=32, CD=88, LE=7, LD=26;
	
	for (x=CE; x<CD; x++)
		for (y=LE; y<LD; y++) {
			gotoxy(x,y);
			textcolor(0);
			printf("-"); textcolor(15);
		}
}

void LimparTela2()
{
	int x, y, CE=32, CD=89, LE=11, LD=26;
	
	for (x=CE; x<CD; x++)
		for (y=LE; y<LD; y++) {
			gotoxy(x,y);
			textcolor(0);
			printf("-"); textcolor(15);
		}
}

void LimparMenu ()
{
    int x, y, CE=8, CD=30, LE=10, LD=27;
    
    for (x=CE; x<CD; x++)
        for (y=LE; y<LD; y++) {
            gotoxy(x,y);
            textcolor(0);
            printf("-"); textcolor(15);
        }
}

//void LimparBarra ()
//{
//	int x=11, y=7;
//	for(x=11; x<27; x++)
//	{
//		gotoxy(x,y);
//		textcolor(0);
//		printf("-"); textcolor(15);
//	}
//}

// --------------> MENUS <-------------- //
char Menu (void)
{	
	LimparTela();
	gotoxy(9,10);
	textcolor(2);
	printf("[A] "); textcolor(15);
	printf("Cadastrar");
	gotoxy(9,11);
	textcolor(2);
	printf("[B] "); textcolor(15);
	printf("Consultar");
	gotoxy(9,12);
	textcolor(2);
	printf("[C] "); textcolor(15);
	printf("Alterar ");
	gotoxy(9,13);
	textcolor(2);
	printf("[D] "); textcolor(15);
	printf("Excluir ");
	gotoxy(9,14);
	textcolor(2);
	printf("[E] "); textcolor(15);
	printf("Relatorio");
	gotoxy(9,15);
	textcolor(4);
	printf("[ESC] "); textcolor(15);
	printf("Sair");
	
	gotoxy(9,17);
	textcolor(8);
	printf("Opcao Desejada: ");

	return toupper(getche());
	textcolor(15);
}

char Menu2(void)
{

	gotoxy(9,10);
	textcolor(2);
	printf("[A] "); textcolor(15);
	printf("Livros");
	gotoxy(9,11);
	textcolor(2);
	printf("[B] "); textcolor(15);
	printf("Autores");
	gotoxy(9,12);
	textcolor(2);
	printf("[C] "); textcolor(15);
	printf("Emprestimos");
	gotoxy(9,13);
	textcolor(2);
	printf("[D] "); textcolor(15);
	printf("Pessoas");
	gotoxy(9,14);
	textcolor(4);
	printf("[X] "); textcolor(15);
	printf("Voltar");
	
	gotoxy(9,16);
	textcolor(8);
	printf("Opcao Desejada: ");

	return toupper(getche());
	textcolor(15);
}

char MenuEx2 (void)
{
	
	gotoxy(9,10);
	textcolor(2);
	printf("[A] "); textcolor(15);
	printf("Exclusao Logica");
	gotoxy(9,11);
	textcolor(2);
	printf("[B] "); textcolor(15);
	printf("Exclusao Fisica");
	gotoxy(9,12);
	textcolor(4);
	printf("[X] "); textcolor(15);
	printf("Voltar");
	
	gotoxy(9,14);
	textcolor(8);
	printf("Opcao Desejada: ");

	return toupper(getche());
	textcolor(15);
}

char MenuRelat (void)
{
	
	gotoxy(9,10);
	textcolor(2);
	printf("[A] "); textcolor(15);
	printf("Autores (Letra)");
	gotoxy(9,11);
	textcolor(2);
	printf("[B] "); textcolor(15);
	printf("Livros (Titulo)");
	gotoxy(9,12);
	textcolor(2);
	printf("[C] "); textcolor(15);
	printf("Emprestimo.Pessoa");
	gotoxy(9,13);
	textcolor(2);
	printf("[D] "); textcolor(15);
	printf("Livro.Autor");
	gotoxy(9,14);
	textcolor(2);
	printf("[E] "); textcolor(15);
	printf("Emprestimo.Pessoa");
	gotoxy(9,15);
	textcolor(4); 
	printf("[X] "); textcolor(15);
	printf("Voltar");
	
	gotoxy(9,17);
	textcolor(8);
	printf("Opcao Desejada: ");

	return toupper(getche());
	textcolor(15);
}


// --------------> BUSCAS <-------------- //

int BuscaIdLivro(FILE *PtrArq, int ChaveId)
{
    TpLivro R;
    rewind(PtrArq);
    
    fread(&R, sizeof(TpLivro),1,PtrArq);
    while(!feof(PtrArq) && R.idLivro != ChaveId || R.Status == 0)
    	fread(&R, sizeof(TpLivro),1,PtrArq);
    	
    if(R.idLivro == ChaveId && R.Status==1)
    	return ftell(PtrArq) - sizeof(TpLivro); //retorna posicao que achou
    else
    	return -1; //-1 se não achou
}

int BuscaIdAutor(FILE *PtrArq, int ChaveId)
{
    TpAutor R;
    rewind(PtrArq);
    
    fread(&R, sizeof(TpAutor),1,PtrArq);
    
    while(!feof(PtrArq) && R.idAutor != ChaveId || R.Status == 0)
    	fread(&R, sizeof(TpAutor),1,PtrArq);
    	
    if(R.idAutor == ChaveId && R.Status==1)
    	return ftell(PtrArq) - sizeof(TpAutor); //retorna posicao que achou
    else
    	return -1; //-1 se não achou
}

int BuscaIdPessoa(FILE *PtrArq, int ChaveId)
{
	TpPessoa R;
	rewind(PtrArq);
	
	fread(&R, sizeof(TpPessoa),1,PtrArq);
	
	while(!feof(PtrArq) && R.idPessoa != ChaveId || R.Status == 0)
		fread(&R, sizeof(TpPessoa),1,PtrArq);
		
	if(R.idPessoa == ChaveId && R.Status==1)
		return ftell(PtrArq) -sizeof(TpPessoa);
	else
		return -1;
}

int BuscaIdEmprestimo(FILE *PtrArq, int ChaveId)
{
	TpEmprestimo R;
	rewind(PtrArq);
	
	fread(&R, sizeof(TpEmprestimo),1,PtrArq);
	while(!feof(PtrArq) && (R.idEmprestimo != ChaveId || R.Status == 0))
		fread(&R, sizeof(TpEmprestimo),1,PtrArq);
		
	if(R.idEmprestimo == ChaveId && R.Status==1) // retorna emprestimo ativo
		return ftell(PtrArq) - sizeof(TpEmprestimo);
	else
		return -1;
}

int BuscaLivroAutor(FILE *PtrLivroAutor, int idLivro, int idAutor)
{
	TpLivroAutor Relac;
	int pos = 0;
	
	rewind(PtrLivroAutor);
	fread(&Relac, sizeof(TpLivroAutor),1,PtrLivroAutor);
	
	while(fread(&Relac, sizeof(TpLivroAutor), 1, PtrLivroAutor))
	{
		if (Relac.idLivro == idLivro && Relac.idAutor == idAutor)
            pos = ftell(PtrLivroAutor) - sizeof(TpLivroAutor);  
	}
	
	return pos;
	
}

// --------------> CADASTROS <-------------- //

void CadastrarLivro(void)
{
    LimparTela();
    TpLivro R;
    TpLivroAutor Relac;
    int idAutor;
    char controle;

    FILE *PtrArq = fopen("Livros.dat", "ab+");
    FILE *PtrAutores = fopen("Autores.dat", "rb+");
    FILE *PtrLivroAutor = fopen("LivroAutor.dat", "ab+");

    if (PtrArq == NULL || PtrLivroAutor == NULL || PtrAutores == NULL)
    {
    	
    	if(PtrLivroAutor == NULL)
    		
    
        gotoxy(35, 10);
        textcolor(4);
        printf("ERROR");
        textcolor(15);
    }
    else
    {
        rewind(PtrAutores);
        gotoxy(35, 10);
        textcolor(2);
        printf("CADASTRAR LIVROS");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID do Livro: ");
        scanf("%d", &R.idLivro);

        while (R.idLivro != 0)
        {
            if (BuscaIdLivro(PtrArq, R.idLivro) != -1)
            {
                LimparTela();
                gotoxy(35, 13);
                textcolor(4);
                printf("Id de livro ja cadastrado!");
                textcolor(15);
                getch();
                LimparTela();
            }
            else
            {
                gotoxy(35, 13);
                printf("Titulo do livro: ");
                fflush(stdin);
                gets(R.Titulo);
                gotoxy(35, 14);
                printf("Ano de Publicacaoo: ");
                scanf("%d", &R.AnoPublicacao);

                R.Status = 1;
                fwrite(&R, sizeof(TpLivro), 1, PtrArq);

                gotoxy(35, 16);
                textcolor(14);
                printf("Deseja associar autores ao livro? (S/N): ");
                controle = toupper(getche());
                while (controle == 'S')
                {
                    LimparTela();
                    gotoxy(35, 16);
                    textcolor(14);
                    printf("Digite o Id dos autores associados ao livro!");
                    gotoxy(35, 17);
                    printf("Id do Autor: ");
                    scanf("%d", &idAutor);

                    if (idAutor != 0)
                    {
                        if (BuscaIdAutor(PtrAutores, idAutor) == -1)
                        {
                            gotoxy(35, 18);
                            textcolor(4);
                            printf("Id Nao encontrado!");
                            textcolor(15);
                            getch();
                        }
                        else
                        {
                            if (BuscaLivroAutor(PtrLivroAutor, R.idLivro, idAutor))
                            {
                                gotoxy(35, 18);
                                textcolor(12);
                                printf("Relacionamento ja existe!");
                                textcolor(15);
                                getch();
                            }
                            else
                            {
                                Relac.idLivro = R.idLivro;
                                Relac.idAutor = idAutor;

                                fwrite(&Relac, sizeof(TpLivroAutor), 1, PtrLivroAutor);
                                gotoxy(35, 19);
                                textcolor(10);
                                printf("Relacionamento Livro-Autor Cadastrado!");
                                textcolor(15);
                                getch();
                            }
                        }
                    }

                    LimparTela();
                    gotoxy(35, 16);
                    textcolor(14);
                    printf("Deseja associar mais autores ao livro? (S/N): ");
                    controle = toupper(getche());
                }
                LimparTela();
                gotoxy(35, 13);
                textcolor(2);
                printf("Cadastro concluido com sucesso!");
                getch();
            }
            LimparTela();
            gotoxy(35, 10);
            textcolor(2);
            printf("CADASTRAR LIVROS");
            textcolor(8);
            gotoxy(35, 12);
            printf("Digite o ID do Livro (0 para sair): ");
            scanf("%d", &R.idLivro);
        }
    }

    fclose(PtrArq);
    fclose(PtrLivroAutor);
    fclose(PtrAutores);
}


void CadastrarAutor()
{
    LimparTela();
    TpAutor R;

    FILE *PtrArq = fopen("Autores.dat", "ab+");

    if (PtrArq == NULL)
    {
        gotoxy(35, 10);
        textcolor(4);
        printf("ERROR");
        textcolor(15);
    }
    else
    {
        // Exibe o cabeçalho inicial
        gotoxy(35, 10);
        textcolor(2);
        printf("CADASTRAR AUTORES");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID do Autor (0 para sair): ");
        textcolor(2);
        scanf("%d", &R.idAutor);

        while (R.idAutor != 0) // Critério de repetição
        {
            if (BuscaIdAutor(PtrArq, R.idAutor) != -1) // Verifica duplicidade
            {
                LimparTela();
                gotoxy(35, 13);
                textcolor(4);
                printf("ID de autor ja cadastrado!");
                textcolor(15);
                getch();

                LimparTela();
                gotoxy(35, 10);
                textcolor(2);
                printf("CADASTRAR AUTORES");
                textcolor(8);
                gotoxy(35, 12);
                printf("Digite o ID do Autor (0 para sair): ");
                scanf("%d", &R.idAutor);
            }
            else // Novo autor
            {
                gotoxy(35, 10);
                textcolor(2);
                printf("CADASTRAR AUTORES");

                gotoxy(35, 13);
                textcolor(8);
                printf("Nome do autor: ");
                fflush(stdin);
                gets(R.Nome);

                gotoxy(35, 14);
                printf("Nacionalidade do autor: ");
                fflush(stdin);
                gets(R.Nacionalidade);

                R.Status = 1; // Ativo
                fwrite(&R, sizeof(TpAutor), 1, PtrArq);

                gotoxy(35, 18);
                textcolor(10);
                printf("Cadastro concluido com sucesso!");
                textcolor(15);
                getch();
            }
            LimparTela();
            gotoxy(35, 10);
            textcolor(2);
            printf("CADASTRAR AUTORES");
            textcolor(8);
            gotoxy(35, 12);
            printf("Digite o ID do Autor (0 para sair): ");
            scanf("%d", &R.idAutor);
        }
    }
    LimparTela();
    fclose(PtrArq);
}



void CadastrarEmprestimo()
{
	LimparTela();
	TpEmprestimo R;
	
	FILE *PtrEmprestimo = fopen("Emprestimos.dat","ab+");
    FILE *PtrLivro = fopen("Livros.dat","rb");
    FILE *PtrPessoa = fopen("Pessoas.dat","rb");
	
	if(PtrEmprestimo == NULL|| PtrLivro == NULL || PtrPessoa == NULL)
	{
		gotoxy(35,10);	
		textcolor(4);
		printf("ERROR"); textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("CADASTRAR EMPRESTIMO");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do Emprestimo (0 para sair): ");
		scanf("%d", &R.idEmprestimo);
		while(R.idEmprestimo != 0)
		{
			if(BuscaIdEmprestimo(PtrEmprestimo,R.idEmprestimo)!= -1)	
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id de Emprestimo ja Cadastrado!");
				textcolor(15);
				getch();
				LimparTela();
			}
			else
			{
				gotoxy(35,13);
				printf("Digite o Id da Pessoa: ");
				scanf("%d",&R.idPessoa);
				if(BuscaIdPessoa(PtrPessoa, R.idPessoa) == -1)
				{
					LimparTela();
					gotoxy(35,13);
					textcolor(4);
					printf("Id de Pessoa nao Encontrado!");
					textcolor(15);
					getch();
					LimparTela();
				}
				else
				{
					gotoxy(35,14);
					printf("Digite o Id do Livro: ");
					scanf("%d",&R.idLivro);
					if(BuscaIdLivro(PtrLivro, R.idLivro) == -1)
					{
						LimparTela();
						gotoxy(35,13);
						textcolor(4);
						printf("Livro nao encontrado!");
						textcolor(15);
						getch();
						LimparTela();
					}
					else
					{
						gotoxy(35, 15);
                		printf("Digite a Data de Emprestimo (dd mm aaaa): ");
                		scanf("%d %d %d", &R.dataEmprestimo.d, &R.dataEmprestimo.m, &R.dataEmprestimo.a);
						
						gotoxy(35, 16);
                        printf("Data de Devolucao (dd mm aaaa): ");
                        scanf("%d %d %d", &R.dataDevolucao.d, &R.dataDevolucao.m, &R.dataDevolucao.a);
                        
                        R.Status = 1;
                        fwrite(&R, sizeof(TpEmprestimo), 1, PtrEmprestimo);
                        
                        gotoxy(35, 18);
                        textcolor(2);
                        printf("Cadastro Concluido!");
                        textcolor(15);
                        getch();
                        LimparTela();
					}
				}	
			}
			LimparTela();
			textcolor(8);
            gotoxy(35, 12);
            printf("Digite o ID do Emprestimo (0 para sair): ");
            scanf("%d", &R.idEmprestimo);
		}
	}
	fclose(PtrEmprestimo);
	fclose(PtrLivro);
	fclose(PtrPessoa);
}

void CadastrarPessoa()
{
	LimparTela();
	TpPessoa R;
	
	FILE *PtrArq = fopen("Pessoas.dat","ab+");
	
	gotoxy(35,10);
	textcolor(2);
	printf("CADASTRAR PESSOAS");
	textcolor(8);
	gotoxy(35,12);
	printf("Digite o ID da Pessoa (0 para sair): ");
	scanf("%d", &R.idPessoa);
	while(R.idPessoa != 0)
	{
		if(BuscaIdPessoa(PtrArq,R.idPessoa) != -1)
		{
			LimparTela();
			gotoxy(35,13);
			textcolor(4);
			printf("Id de pessoa ja cadastrado!");
			textcolor(15);
			getch();
			LimparTela();
			gotoxy(35,10);
			textcolor(2);
			printf("CADASTRAR PESSOAS");
			textcolor(8);
			gotoxy(35,12);
			printf("Digite o ID da Pessoa(0 para sair): ");
			scanf("%d", &R.idPessoa);
		}
		else
		{
			gotoxy(35,13);
			textcolor(8);
			printf("Nome da pessoa: "); fflush(stdin);
			gets(R.Nome);
			gotoxy(35,14);
			printf("Digite o telefone: "); fflush(stdin);
			scanf("%d", &R.Telefone);
			gotoxy(35,15);
			printf("Digite o endereco: "); fflush(stdin);
			gets(R.Endereco);
			R.Status = 1;
			
			fwrite(&R,sizeof(TpPessoa),1,PtrArq);
			gotoxy(35,18);
			textcolor(2);
			printf("Cadastro Concluido");
			getch();
			
		}
		LimparTela2();
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID da Pessoa (0 para sair): ");
		scanf("%d", &R.idPessoa); textcolor(15);
	}
	fclose(PtrArq);
}

// --------------> CONSULTAS <-------------- //

void ConsultarLivro()
{
	LimparTela();
	TpLivro R;
	TpLivroAutor Relac;
	TpAutor autor;
	
	int pos, y = 17, idAutor;
	
	FILE *PtrArq = fopen("Livros.dat","rb");
	FILE *PtrLivroAutor = fopen("LivroAutor.dat", "rb");
    FILE *PtrAutores = fopen("Autores.dat", "rb");
	
	if(PtrArq == NULL || PtrLivroAutor == NULL || PtrAutores == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("CONSULTAR LIVROS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do livro: ");
		scanf("%d", &R.idLivro);
		LimparTela();
		while(R.idLivro != 0)
		{
			pos = BuscaIdLivro(PtrArq,R.idLivro);
			
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id de Livro nao encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR LIVROS");
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do livro (0 para sair): ");
                scanf("%d", &R.idLivro);
				LimparTela();
			}
			else
			{
				LimparTela();
				fseek(PtrArq,pos,0);
				fread(&R,sizeof(TpLivro),1,PtrArq);
				
				if (R.Status == 0)
				{
					LimparTela();
                    gotoxy(35, 13);
                    textcolor(4);
                    printf("Livro excluido logicamente!");
                    textcolor(15);
                    getch();
				}
				else
				{
					gotoxy(35,12);
					textcolor(10);
					printf("--- DADOS ENCONTRADOS ---");
					textcolor(15);
					gotoxy(35,13);
					printf("Id do livro: %d", R.idLivro);
					gotoxy(35,14);
					printf("Titulo: %s", R.Titulo);
					gotoxy(35,15);
					printf("Ano de publicacao: %d",R.AnoPublicacao);
				
					fseek(PtrLivroAutor, 0, 0);
					gotoxy(35, 16);
                	textcolor(14);
               		printf("Autores do Livro:");
					while (fread(&Relac, sizeof(TpLivroAutor), 1, PtrLivroAutor) == 1)
					{
						if(Relac.idLivro == R.idLivro)
						{
							fseek(PtrAutores,0,0);
							while(fread(&autor, sizeof(TpAutor), 1, PtrAutores) == 1)
							{
								if(autor.idAutor == Relac.idAutor)
								{
									gotoxy(35,y);
									printf("- %s", autor.Nome);
									y++;
								}
							}
						}
					}	
				}
				textcolor(15);
                getch();
                LimparTela();
                gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR LIVROS");
                textcolor(8);
                gotoxy(35,12);
                printf("Digite o ID do livro: ");
				scanf("%d", &R.idLivro);
				textcolor(15);
				LimparTela();
			}
		}	
	}
	fclose(PtrArq);
    fclose(PtrLivroAutor);
    fclose(PtrAutores);
}

void ConsultarAutor()
{
	LimparTela();
	TpAutor R;
	int pos;
	
	FILE *PtrArq = fopen("Autores.dat","rb");
	
	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("CONSULTAR AUTORES");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do autor (0 para sair): ");
		scanf("%d", &R.idAutor);
		LimparTela();
		while(R.idAutor != 0)
		{
			pos = BuscaIdAutor(PtrArq,R.idAutor);
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id do Autor nao encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR AUTORES");
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do autor (0 para sair): ");
                scanf("%d", &R.idAutor);
				LimparTela();
			}
			else
			{
				LimparTela();
				fseek(PtrArq,pos,0);
				fread(&R,sizeof(TpAutor),1,PtrArq);
				
				if (R.Status == 0)
				{
					LimparTela();
                    gotoxy(35, 13);
                    textcolor(4);
                    printf("Autor excluido logicamente!");
                    textcolor(15);
                    getch();
				}
				else
				{
					gotoxy(35,12);
					textcolor(10);
					printf("--- DADOS ENCONTRADOS ---");
					textcolor(15);
					gotoxy(35,13);
					printf("Id do autor: %d", R.idAutor);
					gotoxy(35,14);
					printf("Nome: %s", R.Nome);
					gotoxy(35,15);
					printf("Nacionalidade: %s",R.Nacionalidade);
				}
				textcolor(15);
                getch();
                LimparTela();
                gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR AUTORES");
                textcolor(8);
                gotoxy(35,12);
                printf("Digite o ID do autor (0 para sair): ");
				scanf("%d", &R.idAutor);
				textcolor(15);
				LimparTela();
			}
		}
	}
	fclose(PtrArq);
}

void ConsultarEmprestimo()
{
	LimparTela();
	TpEmprestimo R;
	int pos;
	
	FILE *PtrArq = fopen("Emprestimos.dat","rb");
	
	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("CONSULTAR EMPRESTIMOS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do emprestimo (0 para sair): ");
		scanf("%d", &R.idEmprestimo);
		LimparTela();
		while(R.idEmprestimo != 0)
		{
			pos = BuscaIdEmprestimo(PtrArq, R.idEmprestimo);
			if(pos == -1)
			{
				LimparTela();	
				gotoxy(35,13);
				textcolor(12);
				printf("Id do Emprestimo nao encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR EMPRESTIMOS");
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do emprestimo (0 para sair): ");
                scanf("%d", &R.idEmprestimo);
				LimparTela();
			}
			else
			{
				LimparTela();
				fseek(PtrArq,pos,0);
				fread(&R,sizeof(TpEmprestimo),1,PtrArq);
				
				gotoxy(35,12);
				textcolor(10);
				printf("--- DADOS ENCONTRADOS ---");
				textcolor(15);
				gotoxy(35,13);
				printf("Id do Emprestimo: %d", R.idEmprestimo);
				gotoxy(35,14);
				printf("Id da Pessoa: %d", R.idPessoa);
				gotoxy(35,15);
				printf("Id do Livro: %d", R.idLivro);
				gotoxy(35,16);
				printf("Data de Emprestimo: %d %d %d", R.dataEmprestimo.d, R.dataEmprestimo.m, R.dataEmprestimo.a);
				gotoxy(35,17);
				printf("Data de Devolucao: %d %d %d", R.dataDevolucao.d, R.dataDevolucao.m, R.dataDevolucao.a);	
				textcolor(15);
                getch();
                
                LimparTela();
                gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR EMPRESTIMOS");
                textcolor(8);
                gotoxy(35,12);
                printf("Digite o ID do Emprestimo: ");
				scanf("%d", &R.idEmprestimo);
				textcolor(15);
				LimparTela();
			}
		}
	}
	fclose(PtrArq);
}

void ConsultarPessoa()
{
	LimparTela();
	TpPessoa R;
	int pos;
	
	FILE *PtrArq = fopen("Pessoas.dat","rb");
	
	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("CONSULTAR PESSOAS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID da pessoa (0 para sair): ");
		scanf("%d", &R.idPessoa);
		LimparTela();
		while(R.idPessoa != 0)
		{
			pos = BuscaIdPessoa(PtrArq,R.idPessoa);
			
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id da Pessoa nao encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR PESSOAS");
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID da pessoa (0 para sair): ");
                scanf("%d", &R.idPessoa);
				LimparTela();
			}
			else
			{
				LimparTela();
				fseek(PtrArq,pos,0);
				fread(&R,sizeof(TpPessoa),1,PtrArq);
				
				if (R.Status == 0)
				{
					LimparTela();
                    gotoxy(35, 13);
                    textcolor(4);
                    printf("Pessoa excluida logicamente!");
                    textcolor(15);
                    getch();
				}
				else
				{
					gotoxy(35,12);
					textcolor(10);
					printf("--- DADOS ENCONTRADOS ---");
					textcolor(15);
					gotoxy(35,13);
					printf("Id da pessoa: %d", R.idPessoa);
					gotoxy(35,14);
					printf("Nome: %s", R.Nome);
					gotoxy(35,15);
					printf("Telefone: %d",R.Telefone);
					gotoxy(35,16);
					printf("Endereco: %d",R.Endereco);
				}
			
				textcolor(15);
                getch();
                LimparTela();
                gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR PESSOAS");
                textcolor(8);
                gotoxy(35,12);
                printf("Digite o ID da Pessoa: ");
				scanf("%d", &R.idPessoa);
				textcolor(15);
				LimparTela();
			}
		}
	}
	fclose(PtrArq);
}

// --------------> ALTERAÇÕES <-------------- //

void AlterarLivro()
{
	LimparTela();
	TpLivro R;
	int pos;

	FILE *PtrArq = fopen("Livros.dat","rb+");

	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("ALTERAR LIVROS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do Livro (0 para sair): ");
		scanf("%d", &R.idLivro);
		while(R.idLivro != 0)
		{
			pos = BuscaIdLivro(PtrArq,R.idLivro);
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id do Livro nao Encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("ALTERAR LIVROS");
				LimparTela();
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do Livro (0 para sair): ");
                scanf("%d", &R.idLivro);
				LimparTela();	
			}
			else
			{
				LimparTela();
				fseek(PtrArq,pos,0);	
				fread(&R,sizeof(TpLivro),1,PtrArq);
				gotoxy(35,8);
				textcolor(10);
				printf("--- DADOS ENCONTRADOS ---");
				textcolor(2);
				gotoxy(35,9);
				printf("Id do Livro: %d", R.idLivro);
				gotoxy(35,12);
				printf("Titulo do Livro: %s", R.Titulo);
				gotoxy(35,15);
				printf("Ano de publicacao: %d",R.AnoPublicacao);
				textcolor(15);
				gotoxy(35,22);
				printf("Deseja Alterar (S/N)? ");
				if(toupper(getche())=='S')
				{
					textcolor(14);
					gotoxy(35,10);
					printf("Novo id do Livro: ");
					scanf("%d", &R.idLivro);
					gotoxy(35,13);
					printf("Novo Titulo do Livro: "); fflush(stdin);
					gets(R.Titulo);
					gotoxy(35,16);
					printf("Novo Ano de Publicacao: ");
					scanf("%d", &R.AnoPublicacao);
					
					fseek(PtrArq,pos,0);
					fwrite(&R,sizeof(TpLivro),1,PtrArq);
					gotoxy(35,19);
					textcolor(10);
					printf("Dados atualizados!");
						
					textcolor(15);
                	getch();
               		LimparTela();
               		gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR LIVROS");
              		textcolor(8);
              		gotoxy(35,12);
              	  	printf("Digite o ID do Livro (0 para sair): ");
					scanf("%d", &R.idLivro);
					textcolor(15);
					LimparTela();	
				}
				else
				{
					LimparTela();
					gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR LIVROS");
					LimparTela();
					gotoxy(35, 12);
                	textcolor(8);
                	printf("Digite o ID do Livro (0 para sair): ");
                	scanf("%d", &R.idLivro);
					LimparTela();		
				}
			}
		}
	}
	fclose(PtrArq);
}

void AlterarAutor()
{
	LimparTela();
	TpAutor R;
	int pos;
	
	FILE *PtrArq = fopen("Autores.dat","rb+");
	
	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("ALTERAR AUTORES");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do autor (0 para sair): ");
		scanf("%d", &R.idAutor);
		while(R.idAutor != 0)
		{
			pos = BuscaIdAutor(PtrArq,R.idAutor);	
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id do Autor nao encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("CONSULTAR AUTORES");
				LimparTela();
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do Autor (0 para sair): ");
                scanf("%d", &R.idAutor);
				LimparTela();	
			}
			else
			{
				LimparTela();
				fseek(PtrArq,pos,0);	
				fread(&R,sizeof(TpAutor),1,PtrArq);
				gotoxy(35,8);
				textcolor(10);
				printf("--- DADOS ENCONTRADOS ---");
				textcolor(2);
				gotoxy(35,9);
				printf("Id do Autor: %d", R.idAutor);
				gotoxy(35,12);
				printf("Nome: %s", R.Nome);
				gotoxy(35,15);
				printf("Nacionalidade: %s",R.Nacionalidade);
				textcolor(15);
				gotoxy(35,22);
				printf("Deseja Alterar (S/N)? ");
				if(toupper(getche())=='S')
				{
					textcolor(14);
					gotoxy(35,10);
					printf("Novo id do Autor: ");
					scanf("%d", &R.idAutor);
					gotoxy(35,13);
					printf("Novo Nome do Autor: "); fflush(stdin);
					gets(R.Nome);
					gotoxy(35,16);
					printf("Nova Nacionalidade do Autor: ");
					fflush(stdin);
					gets(R.Nacionalidade);
					
					fseek(PtrArq,pos,0);
					fwrite(&R,sizeof(TpAutor),1,PtrArq);
					gotoxy(35,19);
					textcolor(10);
					printf("Dados atualizados!");
						
					textcolor(15);
                	getch();
               		LimparTela();
               		gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR AUTORES");
              		textcolor(8);
              		gotoxy(35,12);
              	  	printf("Digite o ID do Autor (0 para sair): ");
					scanf("%d", &R.idAutor);
					textcolor(15);
					LimparTela();
				}
				else
				{
					LimparTela();
					gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR AUTORES");
					LimparTela();
					gotoxy(35, 12);
                	textcolor(8);
                	printf("Digite o ID do Autor (0 para sair): ");
                	scanf("%d", &R.idAutor);
					LimparTela();		
				}
			}
		}	
	}
	fclose(PtrArq);
}

void AlterarEmprestimo()
{
	LimparTela();
	TpEmprestimo R;
	int pos;
	
	FILE *PtrEmprestimo = fopen("Emprestimos.dat","rb+");
    FILE *PtrLivro = fopen("Livros.dat","rb+");
    FILE *PtrPessoa = fopen("Pessoas.dat","rb+");
	
	if(PtrEmprestimo == NULL|| PtrLivro == NULL || PtrPessoa == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("ALTERAR EMPRESTIMOS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do Emprestimo (0 para sair): ");
		scanf("%d", &R.idEmprestimo);
		while(R.idEmprestimo != 0)
		{
			pos = BuscaIdEmprestimo(PtrEmprestimo,R.idEmprestimo);
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id do Emprestimo nao Encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("ALTERAR EMPRESTIMOS");
				LimparTela();
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do Emprestimo (0 para sair): ");
                scanf("%d", &R.idEmprestimo);
				LimparTela();	
			}
			else
			{
				LimparTela();
				fseek(PtrEmprestimo,pos,0);	
				fread(&R,sizeof(TpEmprestimo),1,PtrEmprestimo);
				gotoxy(35,8);
				textcolor(10);
				printf("--- DADOS ENCONTRADOS ---");
				textcolor(2);
				gotoxy(35,9);
				printf("Id do Emprestimo: %d", R.idEmprestimo);
				gotoxy(35,12);
				printf("Id da Pessoa: %d", R.idPessoa);
				gotoxy(35,15);
				printf("Id do Livro: %d",R.idLivro);
				gotoxy(35,18);
				printf("Data de Emprestimo: %d %d %d", R.dataEmprestimo.d, R.dataEmprestimo.m, R.dataEmprestimo.a);
				gotoxy(35,21);
				printf("Data de Devolucao: %d %d %d", R.dataDevolucao.d, R.dataDevolucao.m, R.dataDevolucao.a);
				textcolor(15);
				gotoxy(35,24);
				printf("Deseja Alterar (S/N)? ");
				if(toupper(getche())=='S')
				{
					textcolor(14);
					gotoxy(35,10);
					printf("Novo id do Emprestimo: ");
					scanf("%d", &R.idEmprestimo);
					gotoxy(35,13);
					printf("Novo id da Pessoa: ");
					scanf("%d",&R.idPessoa);
					gotoxy(35,16);
					printf("Novo id do Livro: ");
					scanf("%d", &R.idLivro);
					gotoxy(35,19);
					printf("Nova Data de Emprestimo: "); 
					scanf("%d %d %d",&R.dataEmprestimo.d, R.dataEmprestimo.m, R.dataEmprestimo.a);
					
					fseek(PtrEmprestimo,pos,0);
					fwrite(&R,sizeof(TpEmprestimo),1,PtrEmprestimo);
					gotoxy(35,25);
					textcolor(10);
					printf("Dados atualizados!");
						
					textcolor(15);
                	getch();
               		LimparTela();
               		gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR EMPRESTIMOS");
					LimparTela();
					gotoxy(35, 12);
        	        textcolor(8);
        	        printf("Digite o ID do Emprestimo (0 para sair): ");
        	        scanf("%d", &R.idEmprestimo);
					LimparTela();	
				}
				else
				{
					gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR EMPRESTIMOS");
					LimparTela();
					gotoxy(35, 12);
               		textcolor(8);
            		printf("Digite o ID do Emprestimo (0 para sair): ");
               		scanf("%d", &R.idEmprestimo);
					LimparTela();	
				}
			}
		}
	}
	fclose(PtrEmprestimo);	
}

void AlterarPessoa()
{
	LimparTela();
	TpPessoa R;
	int pos;
	
	FILE *PtrArq = fopen("Pessoas.dat","rb+");
	
	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("ALTERAR PESSOAS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID da Pessoa (0 para sair): ");
		scanf("%d", &R.idPessoa);
		while(R.idPessoa != 0)
		{
			pos = BuscaIdPessoa(PtrArq,R.idPessoa);
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id da Pessoa nao Encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("ALTERAR PESSOAS");
				LimparTela();
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID da Pessoa(0 para sair): ");
                scanf("%d", &R.idPessoa);
				LimparTela();	
			}
			else
			{
				LimparTela();
				fseek(PtrArq,pos,0);	
				fread(&R,sizeof(TpLivro),1,PtrArq);
				gotoxy(35,8);
				textcolor(10);
				printf("--- DADOS ENCONTRADOS ---");
				textcolor(2);
				gotoxy(35,9);
				printf("Id da Pessoa: %d", R.idPessoa);
				gotoxy(35,12);
				printf("Nome: %s", R.Nome);
				gotoxy(35,15);
				printf("Telefone: %d",R.Telefone);
				gotoxy(35,18);
				printf("Endereco:",R.Endereco);
				textcolor(15);
				gotoxy(35,23);
				printf("Deseja Alterar (S/N)? ");
				if(toupper(getche())=='S')
				{
					textcolor(14);
					gotoxy(35,10);
					printf("Novo id da Pessoa: ");
					scanf("%d", &R.idPessoa);
					gotoxy(35,13);
					printf("Novo Nome: "); fflush(stdin);
					gets(R.Nome);
					gotoxy(35,16);
					printf("Novo Telefone: ");
					scanf("%d", &R.Telefone);
					gotoxy(35,19);
					printf("Novo Endereco:"); fflush(stdin);
					gets(R.Endereco);
					
					fseek(PtrArq,pos,0);
					fwrite(&R,sizeof(TpPessoa),1,PtrArq);
					gotoxy(35,21);
					textcolor(10);
					printf("Dados atualizados!");
						
					textcolor(15);
                	getch();
               		LimparTela();
               		gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR Pessoas");
              		textcolor(8);
              		gotoxy(35,12);
              	  	printf("Digite o ID da Pessoa (0 para sair): ");
					scanf("%d", &R.idPessoa);
					textcolor(15);
					LimparTela();	
				}
				else
				{
					LimparTela();
					gotoxy(35,10);
					textcolor(2);
					printf("ALTERAR Pessoas");
					LimparTela();
					gotoxy(35, 12);
                	textcolor(8);
                	printf("Digite o ID da Pessoa (0 para sair): ");
                	scanf("%d", &R.idPessoa);
					LimparTela();		
				}
			}
		}
	}
	fclose(PtrArq);
}
	
void ExclusaoLogicaLivro()
{
	FILE *PtrArq = fopen("Livros.dat","rb+");
	FILE *PtrLivroAutor = fopen("LivroAutor.dat", "rb");
    FILE *PtrAutores = fopen("Autores.dat", "rb");
	
	TpLivro R;
	TpLivroAutor Relac;
	TpAutor autor;
	int pos, y = 13, idAutor;
	
	if(PtrArq == NULL || PtrLivroAutor == NULL || PtrAutores == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("EXCLUSAO(LOGICA) DE LIVROS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do Livro (0 para sair): ");
		scanf("%d", &R.idLivro);
		while(R.idLivro != 0)
		{
			pos = BuscaIdLivro(PtrArq,R.idLivro);
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id do Livro nao Encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("EXCLUSAO(LOGICA) DE LIVROS");
				LimparTela();
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do Livro(0 para sair): ");
                scanf("%d", &R.idLivro);
				LimparTela();
			}
			else
			{
				if(R.Status == 0)
				{
					LimparTela();
                    gotoxy(35, 13);
                    textcolor(4);
                    printf("Livro excluido logicamente!");
                    textcolor(15);
                    getch();	
                    LimparTela();
                    gotoxy(35, 10);
					textcolor(2);
					printf("EXCLUSAO(LOGICA) DE LIVROS");
					textcolor(8);
					gotoxy(35, 12);
					printf("Digite o ID do Livro (0 para sair): ");
					scanf("%d", &R.idLivro);
				}
				else
				{
					LimparTela();
					fseek(PtrArq,pos,0);	
					fread(&R,sizeof(TpLivro),1,PtrArq);
					gotoxy(35,8);
					textcolor(10);
					printf("--- DADOS ENCONTRADOS ---");
					textcolor(2);
					gotoxy(35,9);
					printf("Id do Livro: %d", R.idLivro);
					gotoxy(35,10);
					printf("Titulo do Livro: %s", R.Titulo);
					gotoxy(35,11);
					printf("Ano de publicacao: %d",R.AnoPublicacao);
					
					fseek(PtrLivroAutor, 0, 0);
					gotoxy(35,12);
                	textcolor(14);
               		printf("Autores do Livro:");
					while (fread(&Relac, sizeof(TpLivroAutor), 1, PtrLivroAutor) == 1)
					{
						if(Relac.idLivro == R.idLivro)
						{
							fseek(PtrAutores,0,0);
							while(fread(&autor, sizeof(TpAutor), 1, PtrAutores) == 1)
							{
								if(autor.idAutor == Relac.idAutor)
								{
									gotoxy(35,y);
									printf("- %s", autor.Nome);
									y++;
								}
							}
						}
					}
					textcolor(15);
					gotoxy(35,17);
					printf("Confirma Exclusao (S/N)? ");
					if (toupper(getche())=='S')
					{
						R.Status = 0;
						fseek(PtrArq,pos,0);
						fwrite(&R,sizeof(TpLivro),1,PtrArq);
						gotoxy(35,18);
						textcolor(10);
						printf("Registro de Livro Excluido!");
					
						textcolor(15);
                		getch();
               			LimparTela();
               			gotoxy(35,10);
						textcolor(2);
						printf("EXCLUSAO(LOGICA) DE LIVROS");
              			textcolor(8);
              			gotoxy(35,12);
              	  		printf("Digite o ID do Livro (0 para sair): ");
						scanf("%d", &R.idLivro);
						textcolor(15);
						LimparTela();
					}
					else
					{
						LimparTela();
						gotoxy(35,10);
						textcolor(2);
						printf("EXCLUSAO(LOGICA) DE LIVROS");
						LimparTela();
						gotoxy(35, 12);
                		textcolor(8);
                		printf("Digite o ID do Livro (0 para sair): ");
                		scanf("%d", &R.idLivro);
						LimparTela();
					}	
				}
				
				
			}
		}	
	}
	fclose(PtrArq);
    fclose(PtrLivroAutor);
    fclose(PtrAutores);
}
	
void ExclusaoLogicaAutor()
{
	FILE *PtrArq = fopen("Autores.dat","rb+");
	TpAutor R;
	int pos;
	
	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("EXCLUSAO(LOGICA) DE AUTORES");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do Autor (0 para sair): ");
		scanf("%d", &R.idAutor);
		while(R.idAutor != 0)
		{
			pos = BuscaIdAutor(PtrArq,R.idAutor);
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id do Autor nao Encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("EXCLUSAO(LOGICA) DE AUTORES");
				LimparTela();
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do Autor(0 para sair): ");
                scanf("%d", &R.idAutor);
				LimparTela();
			}
			else
			{
				fseek(PtrArq,pos,0);
				fread(&R,sizeof(TpAutor),1,PtrArq);
				
				if (R.Status == 0)
				{
					LimparTela();
                    gotoxy(35, 13);
                    textcolor(4);
                    printf("Autor excluido logicamente!");
                    textcolor(15);
                    getch();
                    LimparTela();
                    gotoxy(35,10);
					textcolor(2);
					printf("EXCLUSAO(LOGICA) DE AUTORES");
					textcolor(8);
					gotoxy(35,12);
					printf("Digite o ID do Autor (0 para sair): ");
					scanf("%d", &R.idAutor);
				}
				else
				{
					LimparTela();
					gotoxy(35,12);
					textcolor(10);
					printf("--- DADOS ENCONTRADOS ---");
					textcolor(15);
					gotoxy(35,13);
					printf("Id do autor: %d", R.idAutor);
					gotoxy(35,14);
					printf("Nome: %s", R.Nome);
					gotoxy(35,15);
					printf("Nacionalidade: %s",R.Nacionalidade);
					textcolor(14);
					gotoxy(35,16);
					printf("Confirma Exclusao (S/N)? ");
					if (toupper(getche())=='S')
					{
						R.Status = 0;
						fseek(PtrArq,pos,0);
						fwrite(&R,sizeof(TpAutor),1,PtrArq);
						gotoxy(35,14);
						textcolor(10);
						printf("Registro de Autor Excluido!");
					
						textcolor(15);
                		getch();
               			LimparTela();
               			gotoxy(35,10);
						textcolor(2);
						printf("EXCLUSAO(LOGICA) DE AUTORES");
              			textcolor(8);
              			gotoxy(35,12);
              	  		printf("Digite o ID do Autor (0 para sair): ");
						scanf("%d", &R.idAutor);
						textcolor(15);
						LimparTela();
					}
					else
					{
						LimparTela();
						gotoxy(35,10);
						textcolor(2);
						printf("EXCLUSAO(LOGICA) DE AUTORES");
						LimparTela();
						gotoxy(35, 12);
                		textcolor(8);
                		printf("Digite o ID do Autor (0 para sair): ");
                		scanf("%d", &R.idAutor);
						LimparTela();
					}
				}
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("EXCLUSAO(LOGICA) DE AUTORES");
				LimparTela();
				gotoxy(35, 12);
               	textcolor(8);
               	printf("Digite o ID do Autor (0 para sair): ");
              	scanf("%d", &R.idAutor);
				LimparTela();
			}
		}	
	}
	fclose(PtrArq);
}

void ExclusaoLogicaEmprestimo()
{
	LimparTela();
	TpEmprestimo R;
	int pos;
	
	FILE *PtrArq = fopen("Emprestimos.dat","rb+");
	
	if(PtrArq == NULL)
	{
		gotoxy(35,10);
		textcolor(4);
		printf("Error");
		textcolor(15);
	}
	else
	{
		gotoxy(35,10);
		textcolor(2);
		printf("EXCLUSAO(LOGICA) DE EMPRESTIMOS");
		textcolor(8);
		gotoxy(35,12);
		printf("Digite o ID do Emprestimo (0 para sair): ");
		scanf("%d", &R.idEmprestimo);
		while(R.idEmprestimo != 0)
		{
			pos = BuscaIdEmprestimo(PtrArq,R.idEmprestimo);
			if(pos == -1)
			{
				LimparTela();
				gotoxy(35,13);
				textcolor(4);
				printf("Id do Emprestimo nao Encontrado!");
				textcolor(15);
				getch();
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("EXCLUSAO(LOGICA) DE EMPRESTIMOS");
				LimparTela();
				gotoxy(35, 12);
                textcolor(8);
                printf("Digite o ID do Emprestimo(0 para sair): ");
                scanf("%d", &R.idEmprestimo);
				LimparTela();
			}
			else
			{
				fseek(PtrArq,pos,0);
				fread(&R,sizeof(TpEmprestimo),1,PtrArq);		
				
				if (R.Status == 0)
				{
					LimparTela();
                    gotoxy(35, 13);
                    textcolor(4);
                    printf("Emprestimo excluido logicamente!");
                    textcolor(15);
                    getch();
                    LimparTela();
                    gotoxy(35,10);
					textcolor(2);
					printf("EXCLUSAO(LOGICA) DE EMPRESTIMOS");
					textcolor(8);
					gotoxy(35,12);
					printf("Digite o ID do Emprestimo (0 para sair): ");
					scanf("%d", &R.idEmprestimo);
				}
				else
				{
					LimparTela();
					fseek(PtrArq,pos,0);
					fread(&R,sizeof(TpEmprestimo),1,PtrArq);
					gotoxy(35,12);
					textcolor(10);
					printf("--- DADOS ENCONTRADOS ---");
					textcolor(15);
					gotoxy(35,13);
					printf("Id do Emprestimo: %d", R.idEmprestimo);
					gotoxy(35,14);
					printf("Id da Pessoa: %d", R.idPessoa);
					gotoxy(35,15);
					printf("Id do Livro: %d", R.idLivro);
					gotoxy(35,16);
					printf("Data de Emprestimo: %d %d %d", R.dataEmprestimo.d, R.dataEmprestimo.m, R.dataEmprestimo.a);
					gotoxy(35,17);
					printf("Data de Devolucao: %d %d %d", R.dataDevolucao.d, R.dataDevolucao.m, R.dataDevolucao.a);
					textcolor(15);
					gotoxy(35,18);
					textcolor(14);
					printf("Confirma Exclusao (S/N)? ");
					if(toupper(getche())=='S')
					{
						R.Status = 0;
						fseek(PtrArq,pos,0);
						fwrite(&R,sizeof(TpEmprestimo),1,PtrArq);
						gotoxy(35,19);
						textcolor(10);
						printf("Registro de Emprestimo Excluido!");
					
						textcolor(15);
                		getch();
               			LimparTela();
               			gotoxy(35,10);
						textcolor(2);
						printf("EXCLUSAO(LOGICA) DE EMPRESTIMOS");
              			textcolor(8);
              			gotoxy(35,12);
              	  		printf("Digite o ID do Emprestimo (0 para sair): ");
						scanf("%d", &R.idEmprestimo);
						textcolor(15);
						LimparTela();
					}
					else
					{
						LimparTela();
						gotoxy(35,10);
						textcolor(2);
						printf("EXCLUSAO(LOGICA) DE EMPRESTIMOS");
						LimparTela();
						gotoxy(35, 12);
                		textcolor(8);
                		printf("Digite o ID do Emprestimo (0 para sair): ");
                		scanf("%d", &R.idEmprestimo);
						LimparTela();
					}
				}
				LimparTela();
				gotoxy(35,10);
				textcolor(2);
				printf("EXCLUSAO(LOGICA) DE EMPRESTIMOS");
				LimparTela();
				gotoxy(35, 12);
               	textcolor(8);
               	printf("Digite o ID do Emprestimo (0 para sair): ");
              	scanf("%d", &R.idEmprestimo);
				LimparTela();
			}		
		}	
	}
	fclose(PtrArq);
}


void ExclusaoLogicaPessoa()
{
	LimparTela();
    TpPessoa R;
    int pos;
	
	FILE *PtrArq = fopen("Pessoas.dat", "rb+");
	
	if (PtrArq == NULL)
    {
        gotoxy(35,10);
        textcolor(4);
        printf("Error");
        textcolor(15);
    }
	else
	{
		gotoxy(35,10);
        textcolor(2);
        printf("EXCLUSAO(LOGICA) DE PESSOAS");
        textcolor(8);
        gotoxy(35,12);
        printf("Digite o ID da Pessoa (0 para sair): ");
        scanf("%d", &R.idPessoa);
		
		while (R.idPessoa != 0)
		{
            pos = BuscaIdPessoa(PtrArq, R.idPessoa);
            if (pos == -1)
            {
                LimparTela();
                gotoxy(35,13);
                textcolor(4);
                printf("Id da Pessoa nao encontrado!");
                textcolor(15);
                getch();
                LimparTela();
                gotoxy(35,10);
        		textcolor(2);
        		printf("EXCLUSAO(LOGICA) DE PESSOAS");
        		textcolor(8);
        		gotoxy(35,12);
        		printf("Digite o ID da Pessoa (0 para sair): ");
        		scanf("%d", &R.idPessoa);
            }
            else
            {
                fseek(PtrArq, pos, 0);
                fread(&R, sizeof(TpPessoa), 1, PtrArq);

                if (R.Status == 0)
                {
                    LimparTela();
                    gotoxy(35,13);
                    textcolor(4);
                    printf("Pessoa ja foi excluida logicamente!");
                    textcolor(15);
                    getch();
                    LimparTela();
                    gotoxy(35,10);
       				textcolor(2);
        			printf("EXCLUSAO(LOGICA) DE PESSOAS");
        			textcolor(8);
        			gotoxy(35,12);
        			printf("Digite o ID da Pessoa (0 para sair): ");
        			scanf("%d", &R.idPessoa);
                }
                else
                {
                    LimparTela();
                    gotoxy(35,12);
                    textcolor(10);
                    printf("--- DADOS ENCONTRADOS ---");
                    textcolor(15);
                    gotoxy(35,13);
                    printf("Id da Pessoa: %d", R.idPessoa);
                    gotoxy(35,14);
                    printf("Nome: %s", R.Nome);
                    gotoxy(35,15);
                    printf("Endereco: %s", R.Endereco);
                    gotoxy(35,16);
                    printf("Telefone: %d", R.Telefone);
                    textcolor(14);
                    gotoxy(35,17);
                    printf("Confirma Exclusao (S/N)? ");
                    if (toupper(getche()) == 'S')
                    {
                        R.Status = 0;
                        fseek(PtrArq,pos,0);
                        fwrite(&R, sizeof(TpPessoa),1,PtrArq);
                        gotoxy(35, 18);
                        textcolor(10);
                        printf("Registro de Pessoa Excluido!");
                        textcolor(15);
                        getch();
                    }
                }
                LimparTela();
                gotoxy(35,10);
            	textcolor(2);
            	printf("EXCLUSAO(LOGICA) DE PESSOAS");
            	textcolor(8);
            	gotoxy(35,12);
            	printf("Digite o ID da Pessoa (0 para sair): ");
            	scanf("%d",&R.idPessoa);
            }
        }
	}
	fclose(PtrArq);
}


void ExclusaoFisicaLivro()
{
    LimparTela();
    TpLivro R;
    FILE *PtrTemp, *PtrArq;
    int idLivro, pos;

	PtrArq = fopen("Livros.dat", "rb+");

    if (PtrArq == NULL)
    {
        gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir o arquivo!");
        textcolor(15);
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("EXCLUSAO(FISICA) DE LIVROS");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID do Livro (0 para sair): ");
        scanf("%d", &idLivro);
	
		while(idLivro != 0)
		{
			pos = BuscaIdLivro(PtrArq, idLivro);
			if (pos == -1) // Livro excluído fisicamente
            {
                LimparTela();
                gotoxy(35, 13);
                textcolor(4);
                printf("Livro ja foi excluido fisicamente!");
                textcolor(15);
                getch();
            }
			else
			{
				fseek(PtrArq, pos, 0);
                fread(&R, sizeof(TpLivro), 1, PtrArq);
				LimparTela();
				gotoxy(35,12);
				textcolor(10);
				printf("--- DADOS ENCONTRADOS ---");
                textcolor(2);
                gotoxy(35, 13);
                printf("Id do Livro: %d", R.idLivro);
                gotoxy(35, 14);
                printf("Titulo do Livro: %s", R.Titulo);
                gotoxy(35, 15);
                printf("Ano de publicacao: %d", R.AnoPublicacao);
                gotoxy(35, 17);
                textcolor(14);
                printf("Confirma Exclusao (S/N)? ");
				if (toupper(getche()) == 'S')
                {
                	PtrTemp = fopen("Temp.dat", "wb");
                	rewind(PtrArq);
                	fread(&R, sizeof(TpLivro),1, PtrArq);
                	while(!feof(PtrArq))
					{
						if (R.idLivro != idLivro)
							fwrite(&R, sizeof(TpLivro),1, PtrTemp);
						fread(&R, sizeof(TpLivro),1, PtrArq);
					}
					fclose(PtrTemp);
					fclose(PtrArq);
					remove("Livros.dat");
					rename("Temp.dat", "Livros.dat");
			
					LimparTela();
					gotoxy(35,20);
					textcolor(10);
					printf("Livro excluido fisicamente!");
					textcolor(15);
					getch();
					PtrArq = fopen("Livros.dat", "rb+");
				}
			}
        	LimparTela();
        	gotoxy(35, 10);
        	textcolor(2);
        	printf("EXCLUSAO(FISICA) DE LIVROS");
        	textcolor(8);
        	gotoxy(35, 12);
        	printf("Digite o ID do Livro (0 para sair): ");
       		scanf("%d", &idLivro); 
        }
        fclose(PtrArq);
    }
}


void ExclusaoFisicaAutor()
{
    LimparTela();
    TpAutor R;
    FILE *PtrTemp, *PtrArq;
    int idAutor, pos;

   	PtrArq = fopen("Autores.dat", "rb+");

    if (PtrArq == NULL)
    {
        gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir o arquivo!");
        textcolor(15);
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("EXCLUSAO(FISICA) DE AUTORES");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID do Autor (0 para sair): ");
        scanf("%d", &idAutor);
        while(idAutor != 0) 
        {
        	pos = BuscaIdAutor(PtrArq, idAutor);
            if (pos == -1)
			{
				LimparTela();
                gotoxy(35, 13);
                textcolor(4);
                printf("Autor ja foi excluido fisicamente!");
                textcolor(15);
                getch();
			} 
            else
            {
                fseek(PtrArq, pos, 0);
                fread(&R, sizeof(TpAutor), 1, PtrArq);

				LimparTela();
                gotoxy(35, 12);
                textcolor(10);
                printf("--- DADOS ENCONTRADOS ---");
                textcolor(2);
                gotoxy(35, 13);
                printf("Id do Autor: %d", R.idAutor);
                gotoxy(35, 14);
                printf("Nome do Autor: %s", R.Nome);
                gotoxy(35, 15);
                printf("Nacionalidade: %s", R.Nacionalidade);				
				gotoxy(35, 17);
                textcolor(14);
                printf("Confirma Exclusao (S/N)? ");
				if (toupper(getche()) == 'S')
                {
                    PtrTemp = fopen("Temp.dat", "wb");
                    rewind(PtrArq);
                    fread(&R, sizeof(TpAutor),1,PtrArq);
                    while(!feof(PtrArq))
                    {
                    	if (R.idAutor != idAutor)
                        	fwrite(&R, sizeof(TpAutor), 1, PtrTemp);
                        fread(&R, sizeof(TpAutor), 1, PtrArq);
					}
					fclose(PtrTemp);
                    fclose(PtrArq);
                    remove("Autores.dat");
                    rename("Temp.dat", "Autores.dat");
					
                    LimparTela();
                    gotoxy(35,18);
                    textcolor(10);
                    printf("Autor excluido fisicamente!");
                    textcolor(15);
                    getch();
                    PtrArq = fopen("Autores.dat", "rb+");
                }
            }
            LimparTela();
        	gotoxy(35, 10);
        	textcolor(2);
        	printf("EXCLUSAO(FISICA) DE AUTORES");
        	textcolor(8);
        	gotoxy(35, 12);
        	printf("Digite o ID do Autor (0 para sair): ");
        	scanf("%d", &idAutor);
        }
        fclose(PtrArq);
    }
}


void ExclusaoFisicaPessoa()
{
    LimparTela();
    TpPessoa R;
    FILE *PtrTemp, *PtrArq;
    int idPessoa, pos;

    PtrArq = fopen("Pessoas.dat", "rb+");

    if (PtrArq == NULL)
    {
        gotoxy(35,10);
        textcolor(4);
        printf("Erro ao abrir o arquivo!");
        textcolor(15);
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("EXCLUSAO(FISICA) DE PESSOAS");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID da Pessoa (0 para sair): ");
        scanf("%d", &idPessoa);
		while(idPessoa != 0)
		{
			pos = BuscaIdPessoa(PtrArq, idPessoa);

            if (pos == -1) // Excluido fisicamente
            {
                LimparTela();
                gotoxy(35,13);
                textcolor(4);
                printf("Pessoa ja foi excluida fisicamente!");
                textcolor(15);
                getch();
            }
            else
            {
            	fseek(PtrArq, pos, SEEK_SET);
                fread(&R, sizeof(TpPessoa), 1, PtrArq);
                
            	LimparTela();
                gotoxy(35,12);
                textcolor(10);
                printf("--- DADOS ENCONTRADOS ---");
                textcolor(2);
                gotoxy(35,13);
                printf("Id da Pessoa: %d", R.idPessoa);
                gotoxy(35,14);
                printf("Nome da Pessoa: %s", R.Nome);
                gotoxy(35,15);
                printf("Endereco: %s", R.Endereco);
                gotoxy(35,16);
                printf("Telefone: %d", R.Telefone);
            	gotoxy(35,18);
                textcolor(14);
                printf("Confirma Exclusao (S/N)? ");
            	if (toupper(getche()) == 'S')
            	{
                	FILE *PtrTemp = fopen("Temp.dat", "wb");
                    rewind(PtrArq);
                    fread(&R, sizeof(TpPessoa), 1, PtrArq);
                	while (!feof(PtrArq))
                    {
                        if (R.idPessoa != idPessoa)
                        	fwrite(&R, sizeof(TpPessoa), 1, PtrTemp);
                        fread(&R, sizeof(TpPessoa), 1, PtrArq);
                    }
                    fclose(PtrTemp);
                    fclose(PtrArq);
                    remove("Pessoas.dat");
                    rename("Temp.dat", "Pessoas.dat");    

                    LimparTela();
                    gotoxy(35,18);
                    textcolor(10);
                    printf("Pessoa excluida fisicamente!");
                    textcolor(15);
                    getch();  
					PtrArq = fopen("Emprestimos.dat","rb+");
                }	
			}
            LimparTela();
        	gotoxy(35, 10);
        	textcolor(2);
        	printf("EXCLUSAO(FISICA) DE PESSOAS");
        	textcolor(8);
        	gotoxy(35, 12);
        	printf("Digite o ID da Pessoa (0 para sair): ");
        	scanf("%d", &idPessoa);   
		} 
		fclose(PtrArq); 		
    }
}


void ExclusaoFisicaEmprestimo()
{
    LimparTela();
    TpEmprestimo R;
	FILE *PtrTemp, *PtrArq;
    int idEmprestimo, pos; 
	PtrArq = fopen("Emprestimos.dat", "rb+");

    
    if (PtrArq == NULL)
    {
        gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir o arquivo!");
        textcolor(15);
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("EXCLUSAO(FISICA) DE EMPRESTIMOS");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID do Emprestimo (0 para sair): ");
        scanf("%d", &idEmprestimo);
        while (idEmprestimo != 0) 
        {
            pos = BuscaIdEmprestimo(PtrArq, idEmprestimo);
            if (pos == -1) // Empréstimo já excluído fisicamente
            {
                LimparTela();
                gotoxy(35, 13);
                textcolor(4);
                printf("Emprestimo ja foi excluido fisicamente!");
                textcolor(15);
                getch();
            }
            else
            {
                fseek(PtrArq, pos, SEEK_SET);
                fread(&R, sizeof(TpEmprestimo), 1, PtrArq);
                LimparTela();
                gotoxy(35, 12);
                textcolor(10);
                printf("--- DADOS ENCONTRADOS ---");
                textcolor(2);
                gotoxy(35, 13);
                printf("Id do Emprestimo: %d", R.idEmprestimo);
                gotoxy(35, 14);
                printf("Id da Pessoa: %d", R.idPessoa);
                gotoxy(35, 15);
                printf("Id do Livro: %d", R.idLivro);
                gotoxy(35, 16);
                printf("Data de Emprestimo: %d %d %d", R.dataEmprestimo.d, R.dataEmprestimo.m, R.dataEmprestimo.a);
                gotoxy(35, 17);
                printf("Data de Devolucao: %d %d %d", R.dataDevolucao.d, R.dataDevolucao.m, R.dataDevolucao.a);	
                gotoxy(35, 19);
                textcolor(14);
                printf("Confirma Exclusao (S/N)? ");
                if (toupper(getche()) == 'S')
                {
                	PtrTemp = fopen("Temp.dat", "wb");
                    rewind(PtrArq);
                    fread(&R, sizeof(TpEmprestimo), 1, PtrArq);
                    while (!feof(PtrArq))
                    {
                        if (R.idEmprestimo != idEmprestimo)
                            fwrite(&R, sizeof(TpEmprestimo), 1, PtrTemp);
                        fread(&R, sizeof(TpEmprestimo), 1, PtrArq);
                    }
                    fclose(PtrTemp);
                    fclose(PtrArq);
                    remove("Emprestimos.dat");
                    rename("Temp.dat", "Emprestimos.dat");

                    LimparTela();
                    gotoxy(35, 20);
                    textcolor(10);
                    printf("Emprestimo excluido fisicamente!");
                    textcolor(15);
                    getch();
					PtrArq = fopen("Emprestimos.dat", "rb+");
                }
            }            
	        LimparTela();
	        gotoxy(35, 10);
	        textcolor(2);
	        printf("EXCLUSAO(FISICA) DE EMPRESTIMOS");
	        textcolor(8);
	        gotoxy(35, 12);
	        printf("Digite o ID do Emprestimo (0 para sair): ");
	        scanf("%d", &idEmprestimo);
        }
    	fclose(PtrArq); 
    }
}

// ---------------------- RELATORIOS --------------------//


void RelatorioAutoresPorLetra()
{
    LimparTela();
    FILE *PtrArq = fopen("Autores.dat", "rb");
    TpAutor AutorA, AutorB;
    int QtdeReg, a, b, linha = 12;
    char letra;

    if (PtrArq == NULL)
    {
        gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir o arquivo de autores!");
        textcolor(15);
        getch();
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("RELATORIO DE AUTORES POR LETRA");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite a letra inicial dos autores: ");
        letra = toupper(getche());

        // ordena nacionalidade
        fseek(PtrArq, 0, 2);
        QtdeReg = ftell(PtrArq) / sizeof(TpAutor);

        for (a = 0;a<QtdeReg - 1; a++)
        {
            for (b = a+1;b<QtdeReg;b++)
            {
                fseek(PtrArq, a*sizeof(TpAutor), 0);
                fread(&AutorA, sizeof(TpAutor), 1, PtrArq);

                fseek(PtrArq, b * sizeof(TpAutor), 0);
                fread(&AutorB, sizeof(TpAutor), 1, PtrArq);

                if (strcmp(AutorA.Nacionalidade, AutorB.Nacionalidade) > 0)
                {
                    fseek(PtrArq, a * sizeof(TpAutor), 0);
                    fwrite(&AutorB, sizeof(TpAutor), 1, PtrArq);

                    fseek(PtrArq, b * sizeof(TpAutor), 0);
                    fwrite(&AutorA, sizeof(TpAutor), 1, PtrArq);
                }
            }
        }
        rewind(PtrArq);
        fread(&AutorA, sizeof(TpAutor), 1, PtrArq);

        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("RELATORIO DE AUTORES QUE COMECAM COM A LETRA (%c)", letra);
        textcolor(15);

        while (!feof(PtrArq))
        {
            if (toupper(AutorA.Nome[0]) == letra)
            {
                gotoxy(35, linha++);
                printf("ID Autor: %d", AutorA.idAutor);
                gotoxy(35, linha++);
                printf("Nome: %s", AutorA.Nome);
                gotoxy(35, linha++);
                printf("Nacionalidade: %s", AutorA.Nacionalidade);
                gotoxy(35, linha++);
                printf("------------------------------");
                linha++;

                if (linha > 22)
                {
                    gotoxy(35, 26);
                    textcolor(14);
                    printf("pressione qualquer tecla para continuar...");
                    textcolor(15);
                    getch();
                    LimparTela();
                    gotoxy(35, 10);
                    textcolor(2);
                    printf("RELATORIO DE AUTORES QUE COMECAM COM A LETRA '%c'", letra);
                    linha = 12;
                }
            }
            fread(&AutorA, sizeof(TpAutor), 1, PtrArq);
        }
        if (linha == 12)
        {
            gotoxy(35, 12);
            textcolor(4);
            printf("Nenhum autor encontrado com a letra '%c'!", letra);
            textcolor(15);
        }
        fclose(PtrArq);
    }
    gotoxy(35, 25);
    textcolor(14);
    printf("pressione qualquer tecla para voltar ao menu...");
    textcolor(15);
    getch();
}




void RelatorioEmprestimoPorPessoa()
{
    LimparTela();
    FILE *PtrArq = fopen("Emprestimos.dat", "rb");
    TpEmprestimo R;
    int idPessoa, linha = 12;

    if (PtrArq == NULL)
    {
    	gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir o arquivo de emprestimos!");
        textcolor(15);
        getch();
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("RELATORIO DE EMPRESTIMOS POR PESSOA");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID da Pessoa (0 para sair): ");
        scanf("%d", &idPessoa);

        if (idPessoa != 0)
        {
            LimparTela();
            gotoxy(35, 10);
            textcolor(2);
            printf("RELATORIO DE EMPRESTIMOS - ID PESSOA: %d", idPessoa);
            textcolor(15);

            rewind(PtrArq);
            fread(&R, sizeof(TpEmprestimo), 1, PtrArq);

            while (!feof(PtrArq))
            {
                if (R.idPessoa == idPessoa && R.Status != 0)
                {
                    gotoxy(35, linha++);
                    printf("Id Emprestimo: %d", R.idEmprestimo);
                    gotoxy(35, linha++);
                    printf("Id Livro: %d", R.idLivro);
                    gotoxy(35, linha++);
                    printf("Data Emprestimo: %d %d %d", R.dataEmprestimo.d, R.dataEmprestimo.m, R.dataEmprestimo.a);
                    gotoxy(35, linha++);
                    printf("Data Devolucao: %d %d %d", R.dataDevolucao.d, R.dataDevolucao.m, R.dataDevolucao.a);
                    gotoxy(35, linha++);
                    printf("------------------------------");
                    linha++;
                }

                if (linha > 22)
                {
                    gotoxy(35, 25);
                    textcolor(14);
                    printf("pressione qualquer tecla para continuar...");
                    textcolor(15);
                    getch();
                    LimparTela();
                    gotoxy(35, 10);
                    textcolor(2);
                    printf("RELATORIO DE EMPRESTIMOS - ID PESSOA: %d", idPessoa);
                    linha = 12;
                }

                fread(&R, sizeof(TpEmprestimo), 1, PtrArq);
            }

            if (linha == 12) 
            {
                gotoxy(35, 12);
                textcolor(4);
                printf("Nenhum emprestimo encontrado para esta pessoa!");
                textcolor(15);
            }
        }
        fclose(PtrArq);
    }
    gotoxy(35, 25);
    textcolor(14);
    printf("pressione qualquer tecla para voltar ao menu...");
    textcolor(15);
    getch();
}


void RelatorioLivrosPorPalavra()
{
    LimparTela();
    FILE *PtrArq = fopen("Livros.dat", "rb");
    TpLivro LivroA, LivroB;
    char palavra[15];
    int QtdeReg, a, b, linha = 12;

    if (PtrArq == NULL)
    {
        gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir o arquivo de livros!");
        textcolor(15);
        getch();
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("RELATORIO DE LIVROS POR PALAVRA");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite uma palavra para buscar nos titulos: ");
        scanf(" %[^\n]", palavra); //string com espaco até o final do \n

        fseek(PtrArq, 0, 2);
        QtdeReg = ftell(PtrArq) / sizeof(TpLivro);

        // Ordenação pelo Ano de Publicação
        for (a = 0; a < QtdeReg - 1; a++)
        {
            for (b = a + 1; b < QtdeReg; b++)
            {
                fseek(PtrArq, a * sizeof(TpLivro), 0);
                fread(&LivroA, sizeof(TpLivro), 1, PtrArq);

                fseek(PtrArq, b * sizeof(TpLivro), 0);
                fread(&LivroB, sizeof(TpLivro), 1, PtrArq);

                if (LivroA.AnoPublicacao > LivroB.AnoPublicacao)
                {
                    fseek(PtrArq, a * sizeof(TpLivro), 0);
                    fwrite(&LivroB, sizeof(TpLivro), 1, PtrArq);

                    fseek(PtrArq, b * sizeof(TpLivro), 0);
                    fwrite(&LivroA, sizeof(TpLivro), 1, PtrArq);
                }
            }
        }

        rewind(PtrArq);
        fread(&LivroA, sizeof(TpLivro), 1, PtrArq);

        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("RELATORIO DE LIVROS POR PALAVRA: '%s'", palavra);
        textcolor(15);

        while (!feof(PtrArq))
        {
            if (strstr(LivroA.Titulo, palavra) != NULL) // compara string com substring(palavra) 
            {
                gotoxy(35, linha++);
                printf("ID Livro: %d", LivroA.idLivro);
                gotoxy(35, linha++);
                printf("Titulo: %s", LivroA.Titulo);
                gotoxy(35, linha++);
                printf("Ano de Publicacao: %d", LivroA.AnoPublicacao);
                gotoxy(35, linha++);
                printf("-----------------------------");
                linha++;

                if (linha > 22)
                {
                    gotoxy(35, 25);
                    textcolor(14);
                    printf("pressione qualquer tecla para continuar...");
                    textcolor(15);
                    getch();
                    LimparTela();
                    gotoxy(35, 10);
                    textcolor(2);
                    printf("RELATORIO DE LIVROS POR PALAVRA: '%s'", palavra);
                    linha = 12;
                }
            }

            fread(&LivroA, sizeof(TpLivro), 1, PtrArq);
        }

        if (linha == 12) // livro n encontrado
        {
            gotoxy(35, 12);
            textcolor(4);
            printf("Nenhum livro encontrado com a palavra '%s'!", palavra);
            textcolor(15);
        }

        fclose(PtrArq);
    }

    gotoxy(35, 25);
    textcolor(14);
    printf("pressione qualquer tecla para voltar ao menu...");
    textcolor(15);
    getch();
}



void RelatorioLivroAutor()
{
    LimparTela();
    FILE *PtrArqLivros = fopen("Livros.dat", "rb");
    FILE *PtrArqLivroAutor = fopen("LivroAutor.dat", "rb");
    TpLivro Livro;
    TpLivroAutor LivroAutor;
    int idAutor, linha = 12;

    
    if (PtrArqLivros == NULL || PtrArqLivroAutor == NULL)
    {
    	gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir os arquivos de livros ou autores!");
        textcolor(15);
        getch();
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("RELATORIO DE LIVROS POR AUTOR");
        textcolor(8);
        gotoxy(35, 12);
        printf("Digite o ID do Autor (0 para sair): ");
        scanf("%d", &idAutor);

        if (idAutor != 0)
        {
            LimparTela();
            gotoxy(35, 10);
            textcolor(2);
            printf("RELATORIO DE LIVROS - ID AUTOR: %d", idAutor);
            textcolor(15);

            rewind(PtrArqLivroAutor);
            fread(&LivroAutor, sizeof(TpLivroAutor), 1, PtrArqLivroAutor);

            while (!feof(PtrArqLivroAutor))
            {
                if (LivroAutor.idAutor == idAutor)
                {
                    rewind(PtrArqLivros);
                    fread(&Livro, sizeof(TpLivro), 1, PtrArqLivros);

                    while (!feof(PtrArqLivros))
                    {
                        if (Livro.idLivro == LivroAutor.idLivro && Livro.Status != 0)
                        {
                            gotoxy(35, linha++);
                            printf("Livro ID: %d", Livro.idLivro);
                            gotoxy(35, linha++);
                            printf("Titulo: %s", Livro.Titulo);
                            gotoxy(35, linha++);
                            printf("Ano de Publicacao: %d", Livro.AnoPublicacao);
                            gotoxy(35, linha++);
                            printf("------------------------------");
                            linha++;
                        }
                        fread(&Livro, sizeof(TpLivro), 1, PtrArqLivros);
                    }
                }
                if (linha > 22)
                {
                    gotoxy(35, 25);
                    textcolor(14);
                    printf("pressione qualquer tecla para continuar...");
                    textcolor(15);
                    getch();
                    LimparTela();
                    gotoxy(35, 10);
                    textcolor(2);
                    printf("RELATORIO DE LIVROS - ID AUTOR: %d", idAutor);
                    linha = 12;
                }
                fread(&LivroAutor, sizeof(TpLivroAutor), 1, PtrArqLivroAutor);
            }

            if (linha == 12) 
            {
                gotoxy(35, 12);
                textcolor(4);
                printf("Nenhum livro encontrado para este autor!");
                textcolor(15);
            }
        }
        fclose(PtrArqLivros);
        fclose(PtrArqLivroAutor);
    }
    gotoxy(35, 24);
    textcolor(14);
    printf("pressione qualquer tecla para voltar ao menu...");
    textcolor(15);
    getch();
}


void RelatorioEmprestimosSeparado(void)
{
    LimparTela();  
    TpEmprestimo Emp;
    TpPessoa Pessoa;
    TpLivro Livro;
    int y = 14; 

    FILE *PtrEmprestimos = fopen("Emprestimos.dat", "rb");
    FILE *PtrPessoas = fopen("Pessoas.dat", "rb");
    FILE *PtrLivros = fopen("Livros.dat", "rb");

    if (PtrEmprestimos == NULL || PtrPessoas == NULL || PtrLivros == NULL)
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(4);
        printf("Erro ao abrir arquivos!");
        textcolor(15);
        getch(); 
    }
    else
    {
        LimparTela();
        gotoxy(35, 10);
        textcolor(2);
        printf("RELATORIO DE EMPRESTIMOS POR PESSOA");
        textcolor(8);

        while (fread(&Pessoa, sizeof(TpPessoa), 1, PtrPessoas))
        {
            if (Pessoa.Status != 0) // verificar pessoa ativa
            {
                LimparTela(); 
                gotoxy(35, 10);
                textcolor(2);
                printf("RELATORIO DE EMPRESTIMOS POR PESSOA");
                textcolor(8);
                gotoxy(35, 12);
                printf("ID Pessoa: %d - Nome: %s", Pessoa.idPessoa, Pessoa.Nome);
                gotoxy(35, 14);
                printf("ID Livro   | Titulo     | Data Emprestimo");

                
                fseek(PtrEmprestimos, 0, SEEK_SET);  

                while (fread(&Emp, sizeof(TpEmprestimo), 1, PtrEmprestimos)) // verificar emprestimos no arqv emprest
                {
                    if (Emp.idPessoa == Pessoa.idPessoa && Emp.Status != 0) 
                    {
                        
                        fseek(PtrLivros, 0, SEEK_SET);

                        // Verifica todos os livros no arquivo Livros
                        while (fread(&Livro, sizeof(TpLivro), 1, PtrLivros)) // verificar livros no arqv livro
                        {
                            if (Livro.idLivro == Emp.idLivro)  
                            {
                            	y++;
                                gotoxy(35, y);
                                textcolor(15);
                                printf("%d", Livro.idLivro);   
                                gotoxy(48, y);
                                printf("%s", Livro.Titulo);  
                                gotoxy(62, y);
                                printf("%d/%d/%d", Emp.dataEmprestimo.d, Emp.dataEmprestimo.m, Emp.dataEmprestimo.a);  

								getch();
                                if (y > 22)
                                {
                                    gotoxy(35, 23);
                                    textcolor(14);
                                    printf("pressione qualquer tecla para continuar...");
                                    getch();  
                                    LimparTela();  
                                    y = 14;  
                                }
                            }
                        }
                    }
                }
            }
        }
        if (y == 14)
        {
            gotoxy(35, 14);
            textcolor(4);
            printf("Nenhum emprestimo encontrado.");
        }
        fclose(PtrEmprestimos);
        fclose(PtrPessoas);
        fclose(PtrLivros);
    }
}



void CriaArquivos(void)
{
	FILE *Ptr;
	
	Ptr = fopen("Livros.dat","ab");
	fclose(Ptr);
	Ptr = fopen("Autores.dat","ab");
	fclose(Ptr);
	Ptr = fopen("Emprestimos.dat","ab");
	fclose(Ptr);
	Ptr = fopen("LivroAutor.dat","ab");
	fclose(Ptr);
	Ptr = fopen("Pessoas.dat","ab");
	fclose(Ptr);
}

void InserirDados()
{
    TpLivro Livro;
    TpAutor Autor;
    TpEmprestimo Emprestimo;
    TpPessoa Pessoa;

    FILE *PtrLivro = fopen("Livros.dat", "ab+");
    FILE *PtrAutor = fopen("Autores.dat", "ab+");
    FILE *PtrEmprestimo = fopen("Emprestimos.dat", "ab+");
    FILE *PtrPessoa = fopen("Pessoas.dat", "ab+");

    if (PtrLivro == NULL || PtrAutor == NULL || PtrEmprestimo == NULL)
    {
        printf("Erro ao abrir arquivos para inserção automática!\n");
    }

    // Livros
    Livro.idLivro = 1;
    Livro.AnoPublicacao = 2021;
    Livro.Status = 1;
    strcpy(Livro.Titulo, "algoritmo 2");
    fwrite(&Livro, sizeof(TpLivro), 1, PtrLivro);

    Livro.idLivro = 2;
    Livro.AnoPublicacao = 2020;
    Livro.Status = 1;
    strcpy(Livro.Titulo, "algoritmo 1");
    fwrite(&Livro, sizeof(TpLivro), 1, PtrLivro);

    // Autores
    Autor.idAutor = 1;
    Autor.Status = 1;
    strcpy(Autor.Nome, "Joao Silva");
    strcpy(Autor.Nacionalidade, "Brasileiro");
    fwrite(&Autor, sizeof(TpAutor), 1, PtrAutor);

    Autor.idAutor = 2;
    Autor.Status = 1;
    strcpy(Autor.Nome, "Joao Oliveira");
    strcpy(Autor.Nacionalidade, "Italiano");
    fwrite(&Autor, sizeof(TpAutor), 1, PtrAutor);
    
    // Pessoas
    Pessoa.idPessoa = 1;
    Pessoa.Telefone = 189914653;
    Pessoa.Status = 1;
    strcpy(Pessoa.Nome, "Carlos Andrade");
    strcpy(Pessoa.Endereco, "Rua Ana Jacinta 54");
    fwrite(&Pessoa, sizeof(TpPessoa), 1, PtrPessoa);

    Pessoa.idPessoa = 2;
    Pessoa.Telefone = 189914965;
    Pessoa.Status = 1;
    strcpy(Pessoa.Nome, "Ana Vieira");
    strcpy(Pessoa.Endereco, "Avenida Beco 82");
    fwrite(&Pessoa, sizeof(TpPessoa), 1, PtrPessoa);

    // Empréstimos
    Emprestimo.idEmprestimo = 1;
    Emprestimo.idLivro = 1;
    Emprestimo.idPessoa = 1;
    Emprestimo.Status = 1;
    Emprestimo.dataEmprestimo.d = 15;
    Emprestimo.dataEmprestimo.m = 11;
    Emprestimo.dataEmprestimo.a = 2024;
    Emprestimo.dataDevolucao.d = 15;
    Emprestimo.dataDevolucao.m = 12;
    Emprestimo.dataDevolucao.a = 2024;
    fwrite(&Emprestimo, sizeof(TpEmprestimo), 1, PtrEmprestimo);

    Emprestimo.idEmprestimo = 2;
    Emprestimo.idLivro = 2;
    Emprestimo.idPessoa = 2;
    Emprestimo.Status = 1;
    Emprestimo.dataEmprestimo.d = 20;
    Emprestimo.dataEmprestimo.m = 11;
    Emprestimo.dataEmprestimo.a = 2024;
    Emprestimo.dataDevolucao.d = 20;
    Emprestimo.dataDevolucao.m = 12;
    Emprestimo.dataDevolucao.a = 2024;
    fwrite(&Emprestimo, sizeof(TpEmprestimo), 1, PtrEmprestimo);

    fclose(PtrLivro);
    fclose(PtrAutor);
    fclose(PtrEmprestimo);
    fclose(PtrPessoa);

	gotoxy(35,14);
	textcolor(GREEN);
    printf("Dados inseridos automaticamente com sucesso!");
    getch();
}




int main ()
{
	int TL=0;
	char op, opc, ope, letra, palavra;
	CriaArquivos();
	Moldura();
	do {
		LimparMenu();
		op = Menu();
		switch (op) {
			case 'A':	LimparMenu();
						opc = Menu2();
						switch (opc) {
							case 'A':	CadastrarLivro();	
										break;
							case 'B':	CadastrarAutor();
										break;
							case 'C':	CadastrarEmprestimo();
										break;
							case 'D':	CadastrarPessoa();
										break;
						}
						break;
			case 'B':	LimparMenu();
						opc = Menu2();
						switch (opc) {
							case 'A':	ConsultarLivro();	
										break;
							case 'B':	ConsultarAutor();
										break;
							case 'C':	ConsultarEmprestimo();
										break;
							case 'D':	ConsultarPessoa();
										break;	
						}	
						break;
			case 'C':	LimparMenu();
						opc = Menu2();
						switch (opc) {
							case 'A':	AlterarLivro();	
										break;
							case 'B':	AlterarAutor();
										break;
							case 'C':	AlterarEmprestimo();
										break;
							case 'D':	AlterarPessoa();
										break;
						}
						break;
			case 'D':	LimparMenu();
						opc = Menu2();
						switch (opc) {
							case 'A':	//Livros
										LimparMenu();	
										ope = MenuEx2();
										switch(ope) {
											case 'A':	ExclusaoLogicaLivro();
														break;
											case 'B':	ExclusaoFisicaLivro();
														break;
										}
										break;
							case 'B':	//Autores
										LimparMenu();	
										ope = MenuEx2();
										switch(ope) {
											case 'A':	ExclusaoLogicaAutor();
														break;
											case 'B':	ExclusaoFisicaAutor();
														break;
										}				
										break;
							case 'C':	//Emprestimos
										LimparMenu();	
										ope = MenuEx2();
										switch(ope) {
											case 'A':	ExclusaoLogicaEmprestimo();
														break;
											case 'B':	ExclusaoFisicaEmprestimo();
														break;
										}				
										break;
							case 'D':	//Pessoas
										LimparMenu();	
										ope = MenuEx2();
										switch(ope) {
											case 'A':	ExclusaoLogicaPessoa();
														break;
											case 'B':	ExclusaoFisicaPessoa();
														break;
										}				
										break;			
						}
						break;
			case 'E':	LimparMenu();
						opc = MenuRelat();
						switch (opc) {
							case 'A':	RelatorioAutoresPorLetra();	
										break;
							case 'B':	RelatorioLivrosPorPalavra();
										break;
							case 'C':	RelatorioEmprestimoPorPessoa();
										break;
							case 'D':	RelatorioLivroAutor();
										break;
							case 'E':	RelatorioEmprestimosSeparado();
										break;
						}
						break;
			case 'I':	LimparMenu();
						InserirDados();
						break;
		}
	} while (op != 27);
	
	clrscr();
	textcolor(10);
	printf("o--------------- + ---------------o\n");
	printf("         Fim do Programa\n");
	printf("   
	printf("       
	printf("o--------------- + ---------------o\n");
	textcolor(15);
	
	return 0;
}
