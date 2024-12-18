#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int inclusao() // Fun��o respons�vel por cadastrar o usu�rio no sistema.
{	
	//in�cio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim da cria��o de vari�veis
	
	printf ("Digite o CPF a ser cadastrado:");
	scanf ("%s", cpf); //%s refere-se ao armazenamento da string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file;
	file = fopen(arquivo, "w"); //criar arquivo, o "W" significa escrever (write)
	fprintf(file, cpf); //salva o valor da vari�vel
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

int consulta() // Fun��o para consultar um usu�rio no sistema.
{	

	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r (read) l� o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	 } 
	 
	 system("pause");
}

int deletar() // Fun��o para deletar um usu�rio do sistema. 
{	

	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf ("Digite o CPF do usu�rio que voc� deseja deletar:");
	scanf("%s", cpf);
	
	remove(cpf);	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
	
}

int main()
	{
	int opcao=0; //definindo vari�vel
	int x=1;
	
	for (x=1;x=1;)
	{
		
		system("cls"); //limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf ("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf ("O que voc� deseja realizar? \n\n");
		printf ("\t1 - Incluir nomes \n");
		printf ("\t2 - Consultar nomes \n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("\t4 - Sair do sistema.\n\n");
		printf ("Digite a op��o desejada:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
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
			printf("Voc� digitou uma op��o inv�lida!\n");
			system("pause");
			break;
			
		}
		
		
	
	}
	
}
