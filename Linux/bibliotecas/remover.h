void Remover(cli *listacli, pro *listapro);
void Menu_Remover(int erro);

void Remover_Cliente(cli *listacli);
void Remover_Produto(pro *listapro);

void Relatorios_Cliente(cli *listacli);
void Relatorios_Produto(pro *listapro);

void Tratamento_CPF(cli *listacli);
void Tratamento_Codigo(pro *listapro);

void Menu_Remover(int erro){
	
	printf("Menu da Remocao\n");
	if(erro == 1){
		
		printf("\n");
		printf("ERRO! A opcao tem de constar no menu \n");
		printf("\n");
		
	}
	printf("3.1 Cliente\n");
	printf("3.2 Produto\n");
	printf("Opcao desejada: ");
	
}

void Remover(cli *listacli, pro *listapro){
	
	int controle_laco, erro;
	char opcao[4];
	char opcao1[] = {'3','.','1','\0'};
	char opcao2[] = {'3','.','2','\0'};
	
	erro = 0;
	controle_laco = 1;
	
	Menu_Remover(erro);
	
	while(controle_laco == 1){
				
		scanf("%s", opcao);
	
		if(strcmp(opcao, opcao1) == 0){
			
			Remover_Cliente(listacli);
			controle_laco = 0;
			
		}else if(strcmp(opcao, opcao2) == 0){
			
			Remover_Produto(listapro);
			controle_laco = 0;
			
		}else{
		
			erro = 1;

		}
		
		if(controle_laco == 1){
			
			Menu_Remover(erro);
			
		}		
		
	}
	
}

void Remover_Cliente(cli *listacli){
	
	cli *p, *p2, *teste, *lixo;
	
	p = listacli;
	
	printf("Digite o CPF: ");
	
	scanf("%s", p->cpf);
	
	Tratamento_CPF(listacli);
	
	printf("\n");
	printf("Procurando...\n\n");
	
	teste = p->prox;
	p2 = p;
	
	while(teste != NULL && strcmp(p->cpf, teste->cpf) != 0){
		
		teste = teste->prox;
		p2 = p2->prox;
		
	}
		
	if(teste != NULL){
		
		lixo = p2->prox;
		p2->prox = lixo->prox;
		free(lixo);
		
		printf("Cliente removido!");
		printf("\n\n");	
		
	}else{
		
		printf("Cliente nao encontrado!");
		printf("\n\n");	
		
	}
	
	Relatorios_Cliente(listacli);
	
}

void Remover_Produto(pro *listapro){
	
	pro *p, *p2, *teste, *lixo;
	
	p = listapro;
	
	printf("Digite o codigo do produto de ate 12 digitos: ");
	
	scanf("%s", p->codigo);
	
	Tratamento_Codigo(listapro);
	
	printf("\n");
	printf("Procurando...\n\n");
	
	teste = p->prox;
	p2 = p;
	
	while(teste != NULL && strcmp(p->codigo, teste->codigo) != 0){
		
		teste = teste->prox;
		p2 = p2->prox;
		
	}
	
	if(teste != NULL){
		
		lixo = p2->prox;
		p2->prox = lixo->prox;
		free(lixo);
		
		printf("Produto removido!");
		printf("\n\n");	
		
	}else{
		
		printf("Produto nao encontrado!");
		printf("\n\n");	
		
	}
	
	Relatorios_Produto(listapro);
	
}