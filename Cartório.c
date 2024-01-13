#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string


	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); // cria arquivo
	fprintf(file, "\nCPF: ");
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nNOME: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf); //Armazenado a variavel cpf, utilado a fun��o string "%s"
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo CPF e R de read le(r)
	
	if(file == NULL)
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	printf("Essas s�o as informa��es do usuario: \n");
	
	while(fgets(conteudo, 200, file) != NULL) //while (enquanto) tiver informa��o, armazene a informa��o em conteudo, se for diferente de NULL(nulo)
	{
	printf("%s", conteudo);
	}
	
	printf("\n\n");
	
	system("pause");
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //se cpf informado for nulo apresenta a mensagem abaixo
	{
		printf( "\nO usu�rio n�o se encontra no sistema!.\n\n");
		system("pause"); //trava a tela na mensagem
	}
	
	else
	{
	if(remove(cpf) == 0) //se o cpf informado estiver na base, apresenta a mensagem abaixo
	{
		printf("\n usu�rio deletado com sucesso!\n\n");
		system("pause");
	}
		
		
		
		
	}
	
}

int main()
{
	int opcao=0; //DEFININDO AS VARIAVEIS
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //DEFININDO A LINGUAGUEM
	
		printf("### cart�rio da EBAC ###\n\n"); //INICIO DO MENU
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //FIM DO MENU
		printf("Op��o:");
	
		scanf("%d", &opcao); //ARMAZENANDO A ESCOLHA DO USUARIO
	
		system("cls");
		
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
				
		}

	
	}
}
