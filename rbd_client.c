/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rbd.h"
#include <stdio.h>


/** void
rbdprog_1(char *host)
{

	result_1 = inicializar_1((void*)&inicializar_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = insere_1(&insere_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = remove_1(&remove_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = busca_1(&busca_1_arg, clnt);
	if (result_4 == (Agenda *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = numero_agenda_1((void*)&numero_agenda_1_arg, clnt);
	if (result_5 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_6 = listar_1(&listar_1_arg, clnt);
	if (result_6 == (Agenda *) NULL) {
		clnt_perror (clnt, "call failed");
	}
} **/

void cli_error(CLIENT *cnlt);

int
main (int argc, char *argv[])
{
	CLIENT *clnt;
	int  *result_1;
	char *inicializar_1_arg;
	int  *result_2;
	struct Agenda  insere_1_arg;
	int  *result_3;
	char * remove_1_arg;
	Agenda  *result_4;
	char * busca_1_arg;
	int  *result_5;
	char *numero_agenda_1_arg;
	Agenda  *result_6;
	int  listar_1_arg;

	char *host;
	int opcao = 0;
	int sair = 0;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	clnt = clnt_create (host, RBDPROG, RDBVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	while (sair == 0) {
		Agenda *a = malloc(sizeof(Agenda));
		printf("\nMenu de opções:\n");
		printf("\n1- Inicializar\n 2- Inserir\n 3- Remover\n 4- Buscar\n 5-Listar\n 6-Sair\n\n");
		scanf("%d", &opcao);
		char* nome = malloc(sizeof(char*));
		char* email = malloc(sizeof(char*));
		char* endereco = malloc(sizeof(char*));
		char* telefone = malloc(sizeof(char*));
		char* palavra = malloc(sizeof(char*));
		char **arg; 
		int *idx;

		switch (opcao)
		{
			case 1:
				result_1 = inicializar_1(NULL, clnt);
				if(result_1 == (int *)NULL) {
					cli_error(clnt);
				}

				if(*result_1)
					printf("INICIALIZADO!\n\n");
				break;
			case 2:
				printf("Informe nome: ");
				scanf(" %[^\n]", nome);
				a->nome = nome;

				printf("Informe telefone: ");
				scanf(" %[^\n]", telefone);
				a->telefone = telefone;

				printf("Informe endereco: ");
				scanf(" %[^\n]", endereco);
				a->endereco = endereco;

				printf("Informe email: ");
				scanf(" %[^\n]", email);
				a->email = email;

				result_2 = insere_1(a, clnt); 
				
				if (result_2 == (int *)NULL) {
					cli_error(clnt);
				}
				if(*result_2) {
					printf("--------------\n");
					printf("INFORMAÇÃO INSERIDA!\n");
					printf("--------------\n");
				}
				else {
					printf("--------------\n");
					printf("INFORMAÇÕES NÃO INSERIDAS!\n");
					printf("--------------\n");
				}
				
				break;
			case 3:
				printf("Informe o nome: ");
				scanf(" %[^\n]", palavra);
				arg = &palavra;
				result_3 = remove_1(arg, clnt);

				if (result_3 == (int *)NULL) {
					cli_error(clnt);
				}

				if (*result_3) {
					printf("--------------\n");
					printf("NOME REMOVIDO!\n");
					printf("--------------\n");
				}
				else {
					printf("--------------\n");
					printf("NÃO FOI POSSÍVEL REMOVER!\n");
					printf("--------------\n");
				}

				break;
			case 4:
				printf("Informe o nome: ");
				scanf(" %[^\n]", palavra);
  				arg = &palavra;
				result_4 = busca_1(arg, clnt);
				if (strcmp("0", result_4->nome) == 0) {
					printf("--------------\n");
					printf("\nNOME NÃO ENCONTRADA!\n");	
					printf("--------------\n");
				} 
				else {
					printf("\nNOME ENCONTRADO!\n");
					printf("--------------\n");
					printf("Nome: %s\n", result_4->nome);
					printf("Telefone: %s\n", result_4->telefone);
					printf("Endereco: %s\n", result_4->endereco);
					printf("Email: %s\n", result_4->email);
					printf("--------------\n");	
				}

				break;
			case 5:
				result_5 = numero_agenda_1(NULL, clnt);
				//printf("tamamnho: %d\n", *result_5);
				if(*result_5 == 0) {
					printf("--------------\n");
					printf("Sem dados na agenda!\n");
					printf("--------------\n");
					break;
				}
				int i;
				//printf("ooo oo %d\n", *result_5);
				for (i = 0; i < *result_5; i++) {
					listar_1_arg = i;
					result_6 = listar_1(&listar_1_arg, clnt);
					printf("--------------\n");
					printf("Nome: %s\n", result_6->nome);
					printf("Telefone: %s\n", result_6->telefone);
					printf("Endereco: %s\n", result_6->endereco);
					printf("Email: %s\n", result_6->email);
					printf("--------------\n");
				}
				break;
			default:
				sair = 1;
				break;
		}
	}
	exit (0);
}

void cli_error(CLIENT *clnt)
{
   /* An error occurred while calling the server. */
   /* Print error message and die. */
   printf("RPC falhou\n");
   clnt_destroy( clnt );
   exit(1);
}
//gcc -o server rbd_svc.c rbd_server.c rbd_xdr.c -I/usr/include/tirpc -ltirpc - compilacao de servidor
//gcc -o cliente rbd_clnt.c rbd_client.c rbd_xdr.c -I/usr/include/tirpc -ltirpc  - compilacao de cliente