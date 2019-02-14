void Editar(cli *listacli, pro *listapro);
void Menu_Editar(int erro);

void Editar_Cliente(cli *listacli);
void Editar_Produto(pro *listapro);

void Relatorios_Cliente(cli *listacli);
void Relatorios_Produto(pro *listapro);

void Tratamento_CPF(cli *listacli);
void Tratamento_Codigo(pro *listapro);

void Menu_Editar(int erro){
	
	printf("Menu da Edicao\n");
	if(erro == 1){
		
		printf("\n");
		printf("ERRO! A opcao tem de constar no menu \n");
		printf("\n");
		
	}
	printf("2.1 Cliente\n");
	printf("2.2 Produto\n");
	printf("Opcao desejada: ");
	
}

void Editar(cli *listacli, pro *listapro){
	
	int controle_laco, erro;
	char opcao[4];
	char opcao1[] = {'2','.','1','\0'};
	char opcao2[] = {'2','.','2','\0'};
	
	erro = 0;
	controle_laco = 1;
	
	Menu_Editar(erro);
	
	while(controle_laco == 1){
				
		scanf("%s", opcao);
	
		if(strcmp(opcao, opcao1) == 0){
			
			Editar_Cliente(listacli);
			controle_laco = 0;
			
		}else if(strcmp(opcao, opcao2) == 0){
			
			Editar_Produto(listapro);
			controle_laco = 0;
			
		}else{
		
			erro = 1;

		}
		
		if(controle_laco == 1){
			
			Menu_Editar(erro);
			
		}		
		
	}
	
}

void Editar_Cliente(cli *listacli){
	
	cli *p, *teste;
	
	p = listacli;
	
	printf("Digite o CPF: ");
	
	scanf("%s", p->cpf);
	
	Tratamento_CPF(listacli);
	
	printf("\n");
	printf("Procurando...\n\n");
	
	teste = p->prox;
	
	while(teste != NULL && strcmp(p->cpf, teste->cpf) != 0)
		teste = teste->prox;
	
	if(teste != NULL){
		
		printf("Digite o novo nome completo: ");
	
		setbuf(stdin, NULL);
		scanf("%[^\n]s", teste->nome);
		
		printf("Nome alterado!");
		printf("\n\n");	
		
	}else{
		
		printf("CPF nao encontrado!");
		printf("\n\n");	
		
	}
	
	Relatorios_Cliente(listacli);
	
}

void Editar_Produto(pro *listapro){
	
	pro *p, *teste;
	
	p = listapro;
	
	printf("Digite o codigo do produto de ate 12 digitos: ");
	
	scanf("%s", p->codigo);
	
	Tratamento_Codigo(listapro);
	
	printf("\n");
	printf("Procurando...\n\n");
	
	teste = p->prox;
	
	while(teste != NULL && strcmp(p->codigo, teste->codigo) != 0)
		teste = teste->prox;
	
	if(teste != NULL){
		
		printf("Digite o novo nome do produto: ");
	
		setbuf(stdin, NULL);
		scanf("%[^\n]s", teste->nome);
		
		printf("\n");
		printf("Digite a nova quantidade em estoque: ");
		
		scanf("%d", &teste->estoque);
		
		printf("\n");
		printf("Digite o novo preco do produto: ");
		
		scanf("%lf", &teste->preco);
		
		printf("Nome, quantidade e estoque alterados!");
		printf("\n\n");	
		
	}else{
		
		printf("Codigo do produto nao encontrado!");
		printf("\n\n");
		
	}
	
	Relatorios_Produto(listapro);
	
}