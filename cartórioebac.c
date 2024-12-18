#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bliblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int inclusao() // Função responsável por cadastrar o usuário no sistema.
{	
	//início da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim da criação de variáveis
	
	printf ("Digite o CPF a ser cadastrado:");
	scanf ("%s", cpf); //%s refere-se ao armazenamento da string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file;
	file = fopen(arquivo, "w"); //criar arquivo, o "W" significa escrever (write)
	fprintf(file, cpf); //salva o valor da variável
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf ("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta() // Função para consultar um usuário no sistema.
{	

	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r (read) lê o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	 } 
	 
	 system("pause");
}

int deletar() // Função para deletar um usuário do sistema. 
{	

	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf ("Digite o CPF do usuário que você deseja deletar:");
	scanf("%s", cpf);
	
	remove(cpf);	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
	
}

int main()
	{
	int opcao=0; //definindo variável
	int x=1;
	
	for (x=1;x=1;)
	{
		
		system("cls"); //limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf ("### Cartório da EBAC ###\n\n"); //início do menu
		printf ("O que você deseja realizar? \n\n");
		printf ("\t1 - Incluir nomes \n");
		printf ("\t2 - Consultar nomes \n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("\t4 - Sair do sistema.\n\n");
		printf ("Digite a opção desejada:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			inclusao();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf ("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Você digitou uma opção inválida!\n");
			system("pause");
			break;
			
		}
		
		
	
	}
	
}
