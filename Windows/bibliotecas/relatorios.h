void Relatorios(cli *listacli, pro *listapro);
void Menu_Relatorios(int erro);

void Relatorios_Cliente(cli *listacli);
void Relatorios_Produto(pro *listapro);

void clrscr();

void Menu_Relatorios(int erro){
	
	printf("Menu dos Relatorios\n");
	if(erro == 1){
		
		printf("\n");
		printf("ERRO! A opcao tem de constar no menu \n");
		printf("\n");
		
	}
	printf("4.1 Cliente\n");
	printf("4.2 Produto\n");
	printf("Opcao desejada: ");
	
}

void Relatorios(cli *listacli, pro *listapro){
	
	int controle_laco, erro;
	char opcao[4];
	char opcao1[] = {'4','.','1','\0'};
	char opcao2[] = {'4','.','2','\0'};
	
	erro = 0;
	
	controle_laco = 1;
	
	clrscr();
	Menu_Relatorios(erro);
	
	while(controle_laco == 1){
				
		scanf("%s", opcao);
		clrscr();
	
		if(strcmp(opcao, opcao1) == 0){
			
			Relatorios_Cliente(listacli);
			controle_laco = 0;
			
		}else if(strcmp(opcao, opcao2) == 0){
			
			Relatorios_Produto(listapro);
			controle_laco = 0;
			
		}else{
		
			erro = 1;

		}
		
		if(controle_laco == 1){
			
			clrscr();
			Menu_Relatorios(erro);
			
		}		
		
	}
	
}

void Relatorios_Cliente(cli *listacli){
	
	cli *p;
	
	for(p = listacli->prox; p != NULL; p = p->prox){
		
		printf("%s", p->cpf);
		printf("\n");
		
		printf("%s", p->nome);
		printf("\n\n");
		
	}
	
	if(listacli->prox == NULL){
		
		printf("Nao existem elementos a ser mostrados!\n\n");
		
		
	}
	
	system("pause");
	printf("\n");
	
	clrscr();
	
}

void Relatorios_Produto(pro *listapro){
	
	pro *p;
	
	for(p = listapro->prox; p != NULL; p = p->prox){
		
		printf("Codigo do Produto: %s", p->codigo);
		printf("\n");
		
		printf("Nome do Produto: %s", p->nome);
		printf("\n");
		
		printf("Quantidade do Produto: %d", p->estoque);
		printf("\n");
		
		printf("Preco do Produto: %.2f", p->preco);
		printf("\n\n");
		
	}
	
	if(listapro->prox == NULL){
		
		printf("Nao existem elementos a ser mostrados!\n\n");
		
	}
	
	system("pause");
	printf("\n");
	
	clrscr();
	
}

