#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./bibliotecas/database.h"

#include "./bibliotecas/cadastrar.h"
#include "./bibliotecas/editar.h"
#include "./bibliotecas/remover.h"
#include "./bibliotecas/relatorios.h"
#include "./bibliotecas/vendas.h"

void Menu_Principal(){
	
	printf("Gestao de clientes e produtos\n");
	
	printf("1. Cadastrar\n");
	printf("2. Editar\n");
	printf("3. Remover\n");
	printf("4. Relatorios\n");
	printf("5. Vendas\n");
	printf("6. Sair\n");
	
}

int main(void){
	
	int opcao;
	
	cli c, *listacli;
	pro p, *listapro;
	
	c.prox = NULL;
	p.prox = NULL;
	
	listacli = &c;
	listapro = &p;	
	
	Recuperar_Dados(listacli, listapro);
	
	Menu_Principal();
	
	while(1){
		
		printf("\nDigite a opcao: ");
		scanf("%d", &opcao);
		
		if(opcao == 1){
			
			Cadastrar(listacli, listapro);			
			
		}else if (opcao == 2){
			
			Editar(listacli, listapro);
			
		}else if(opcao == 3){
			
			Remover(listacli, listapro);
			
		}else if(opcao == 4){
			
			Relatorios(listacli, listapro);			
			
		}else if(opcao == 5){
			
			Vendas(listacli, listapro);
			
		}else if(opcao == 6){
			
			Salvar_Dados(listacli, listapro);
			return 0;	
			
		}else{
			
			printf("Erro! A opcao tem de constar no menu \n\n");
			
		}
		
		Menu_Principal();
		
	}
	
	return 0;
	
}
