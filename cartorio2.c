#include <stdio.h> // library of comunication user
#include <stdlib.h> // memory allocation library 
#include <locale.h> // text localization library (language)
#include <string.h> // string library 

int registrar() // responsible function for register new user
{
	system("cls");
	
	setlocale(LC_ALL,"portuguese");
	
	// variables/string 
	char arquivo[200]; 
	char cpf[40];
	char nome[40];
	char nascimento[20];
	char cargo[40];
	char cep[40];
	char cidade[40];
	char bairro[40];
	char endereco[40];
	char complemento[40];
	
	printf("\n\tCADASTRO DE DADOS PESSOAIS\n");
	
	printf("\n\tCPF: ");
	scanf("%s",cpf);
	setbuf(stdin,NULL);
	
	strcpy(arquivo,cpf);
	
	FILE *file;
	
	file = fopen(arquivo,"w");
	fprintf(file,"\tCPF: ");
	fprintf(file,cpf);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\tNOME COMPLETO: ");
	scanf("%[^\n]",nome);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tNOME COMPLETO: ");
	fprintf(file,nome);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\tDATA DE NASCIMENTO: ");
	scanf("%s",nascimento);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tDATA DE NASCIMENTO: ");
	fprintf(file,nascimento);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\tCARGO: ");
	scanf("%[^\n]",cargo);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tCARGO: ");
	fprintf(file,cargo);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\n");
	printf("\tCADASTRO DE ENDEREÇO\n\n");
	
	printf("\tCEP: ");
	scanf("%s",cep);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tCEP: ");
	fprintf(file,cep);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\tCIDADE E ESTADO: ");
	scanf("%[^\n]",cidade);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tCIDADE E ESTADO: ");
	fprintf(file,cidade);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\tBAIRRO: ");
	scanf("%[^\n]",bairro);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tBAIRRO: ");
	fprintf(file,bairro);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\tENDEREÇO: ");
	scanf("%[^\n]",endereco);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tENDEREÇO: ");
	fprintf(file,endereco);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\tCOMPLEMENTO: ");
	scanf("%[^\n]",complemento);
	setbuf(stdin,NULL);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\tCOMPLEMENTO: ");
	fprintf(file,complemento);
	fprintf(file,"\n");
	fclose(file);
	
	printf("\n");
	
	printf("\tUSUARIO CADASTRADO COM SUCESSO!\n\n");
	
	system("pause");
	
	system("cls");
	
	int opcao=0;
	
	printf("\n\tPRESSIONE 1 PARA NOVO CADASTRO OU 2 PARA VOLTAR AO MENU\n\n");
	printf("\t");
	scanf("%d",&opcao);
	
	switch(opcao)
	{
		case 1:
			registrar();
		break;
		
		case 2:
			main();
		break;
	}
}

int consultar() // responsible function for search user
{
	setlocale(LC_ALL,"portuguese"); // defining language
	
	char cpf[40];
	
	char conteudo[200]; // defining max caracters present
	
	printf("\n\tCONSULTAR POR CPF: "); // comunication with user
	scanf("%s",cpf); // collecting user information and put in variable "cpf" 
	
	FILE *file; // open "file" mode and search 
	file = fopen(cpf,"r"); // defining file and action, in case; "read"
	
	if(file == NULL) // if archive does not exist, to present; NOT AVAIBLE
	{
		printf("\nNOT AVAIBLE\n");
	} 
	
	while(fgets(conteudo,200,file) != NULL) // defining number of search in the file
	{	
		printf("\n");
		printf("%s",conteudo);
	}
	
	printf("\n"); 
	system ("pause");
	fclose(file); // close the file	
}

int deletar() // responsible function for delete user
{
	setlocale(LC_ALL,"portuguese"); // defining language
	
	char cpf[40];
	
	printf("\n\tDIGITE O CPF DO USUÁRIO QUE DESEJA DELETAR: "); // communication with user
	scanf("%s",cpf); // collection user information, and put in variable "cpf"
	
	FILE *file; // open "file" mode and search 
	file = fopen(cpf,"r"); // open file and read
	
	if(file != NULL) // if is a valid archive, close, delet and communicate of user
	{
		fclose(file); 
		remove(cpf);
		printf("\n\tUSUÁRIO DELETADO\n");
	} 
	
	else // if is a not valid archive, communicate of user
	printf("\n\tUSUÁRIO NÃO LOCALIZADO\n");
	printf("\n");
	
	system("pause");	
}

int main ()
{
	int opcao=0; // defining variables
	int x=1;
	
	for (x=1;x=1;)
	{
		system ("cls"); // clean screen command
		
		setlocale(LC_ALL,"portuguese"); // defining language

		printf("Cartório da EBAC\n\n");
		printf("\t1 REGISTRAR USUÁRIO\n");
		printf("\t2 CONSULTAR USUÁRIO\n");
		printf("\t3 DELETAR USUÁRIO\n");
		printf("\t\nOPÇÃO: ");
	
		scanf("%d",&opcao); // getting user input whith %d, and putting in variable whith &opcao
	
		system("cls"); // clean screen when command is executed 
	
		switch(opcao)
		{
			case 1:
				registrar();
			break;
		
			case 2:
				consultar();
			break;
		
			case 3:
				deletar();
			break; 
			
			default:
				printf("\n\tNOT AVAIBLE\n");
				system("pause");
			break;
		}
	}
}
