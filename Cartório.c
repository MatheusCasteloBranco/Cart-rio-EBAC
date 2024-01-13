#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

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
	scanf("%s",cpf); //Armazenado a variavel cpf, utilado a função string "%s"
	printf("\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo CPF e R de read le(r)
	
	if(file == NULL)
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	printf("Essas são as informações do usuario: \n");
	
	while(fgets(conteudo, 200, file) != NULL) //while (enquanto) tiver informação, armazene a informação em conteudo, se for diferente de NULL(nulo)
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL) //se cpf informado for nulo apresenta a mensagem abaixo
	{
		printf( "\nO usuário não se encontra no sistema!.\n\n");
		system("pause"); //trava a tela na mensagem
	}
	
	else
	{
	if(remove(cpf) == 0) //se o cpf informado estiver na base, apresenta a mensagem abaixo
	{
		printf("\n usuário deletado com sucesso!\n\n");
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
	
		printf("### cartório da EBAC ###\n\n"); //INICIO DO MENU
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); //FIM DO MENU
		printf("Opção:");
	
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
			printf("essa opção não está disponível!\n");
			system("pause");
			break;
				
		}

	
	}
}
