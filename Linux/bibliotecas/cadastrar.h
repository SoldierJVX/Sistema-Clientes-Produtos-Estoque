void Menu_Cadastro(int erro);
void Cadastrar(cli *listacli, pro *listapro);

void Cadastrar_Cliente(cli *listacli);
void Cadastrar_Produto(pro *listapro);

void Cliente_Dinamico(cli *nova, cli *p, cli *temp);
void Produto_Dinamico(pro *nova, pro *p, pro *temp);

void Tratamento_CPF(cli *listacli);
void Tratamento_Codigo(pro *listapro);

void Relatorios_Cliente(cli *listacli);
void Relatorios_Produto(pro *listapro);

void Menu_Cadastro(int erro){
	
	printf("Menu do Cadastro\n");
	if(erro == 1){
		
		printf("\n");
		printf("ERRO! A opcao tem de constar no menu \n");
		printf("\n");
		
	}
	printf("1.1 Cliente\n");
	printf("1.2 Produto\n");
	printf("Opcao desejada: ");
	
}

void Cadastrar(cli *listacli, pro *listapro){
	
	int controle_laco, erro;
	char opcao[4];
	char opcao1[] = {'1','.','1','\0'};
	char opcao2[] = {'1','.','2','\0'};
	
	erro = 0;
	controle_laco = 1;
	
	Menu_Cadastro(erro);
	
	while(controle_laco == 1){
		
		scanf("%s", opcao);
	
		if(strcmp(opcao, opcao1) == 0){
			
			Cadastrar_Cliente(listacli);
			controle_laco = 0;
			
		}else if(strcmp(opcao, opcao2) == 0){
			
			Cadastrar_Produto(listapro);
			controle_laco = 0;
			
		}else{
		
			erro = 1;

		}
		
		if(controle_laco == 1){
			
			Menu_Cadastro(erro);
			
		}		
		
	}
	
}

void Cadastrar_Cliente(cli *listacli){
	
	cli *p, *nova, *temp;
	
	p = listacli;
	
	printf("Digite o CPF: ");
	
	scanf("%s", p->cpf);

	Tratamento_CPF(listacli);
	
	printf("\n");
	printf("Digite o nome completo: ");
	
	setbuf(stdin, NULL);
	scanf("%[^\n]s", p->nome);
	
	printf("\n");
	printf("Adicionando...\n\n");
	
	temp = p;
	
	while(temp->prox != NULL  && strcmp(p->cpf, temp->prox->cpf) > 0)
		temp = temp->prox;
		
	if(temp->prox == NULL){
		
		nova = (cli *) malloc(sizeof(cli));
		Cliente_Dinamico(nova, p, temp);
	
	}else if(strcmp(p->cpf, temp->prox->cpf) != 0){
		
		nova = (cli *) malloc(sizeof(cli));
		Cliente_Dinamico(nova, p, temp);
		
	}else{
		
		printf("CPF ja existente!");
		printf("\n\n");
		
	}

	Relatorios_Cliente(listacli);
	
}

void Cliente_Dinamico(cli *nova, cli *p, cli *temp){
	
	int i;
	
	if(nova == NULL){
		
		printf("Nao foi possivel alocar espaco!\n\n");
		
		return;
		
	}
			
	for(i = 0; i < 12; i++)
		nova->cpf[i] = p->cpf[i];
				
	for(i = 0; i < 101; i++)
		nova->nome[i] = p->nome[i];
				
	nova->prox = temp->prox;
	temp->prox = nova;
				
	printf("CPF Adicionado!");
	printf("\n\n");	
	
}

void Tratamento_CPF(cli *listacli){
	
	int quantcpf, i, count;
	char temp[12];

	quantcpf = strlen(listacli->cpf);
	count = 11 - quantcpf;

	for(i = 0; i < count; i++)
		temp[i] = '0';
	
	for(i = 0; i <= quantcpf;i++){
		
		temp[count] = listacli->cpf[i];
		count++;
		
	}
	
	for(i = 0; i < 12; i++)
		listacli->cpf[i] = temp[i];	
			
}

void Cadastrar_Produto(pro *listapro){
	
	pro *p, *temp, *nova;
	
	p = listapro;
	
	printf("Digite o codigo do produto: ");
	
	scanf("%s", p->codigo);
	
	Tratamento_Codigo(listapro);
	
	printf("\n");
	printf("Digite o nome do produto: ");
	
	setbuf(stdin, NULL);
	scanf("%[^\n]s", p->nome);
	
	printf("\n");
	printf("Digite a quantidade em estoque: ");
	
	scanf("%d", &p->estoque);
	
	printf("\n");
	printf("Digite o preco do produto: ");
	
	scanf("%lf", &p->preco);
	
	printf("\n");
	printf("Adicionando...\n\n");
	
	temp = p;
	
	while(temp->prox != NULL  && strcmp(p->codigo, temp->prox->codigo) > 0)
		temp = temp->prox;
	
	if(temp->prox == NULL){
		
		nova = (pro *) malloc(sizeof(pro));
		Produto_Dinamico(nova, p, temp);
		
	}else if(strcmp(p->codigo, temp->prox->codigo) != 0){
		
		nova = (pro *) malloc(sizeof(pro));
		Produto_Dinamico(nova, p, temp);
		
	}else{
		
		printf("Produto ja cadastrado!");
		printf("\n\n");
		
	}
	
	Relatorios_Produto(listapro);
	
	
}

void Produto_Dinamico(pro *nova, pro *p, pro *temp){
	
	int i;
	
	if(nova == NULL){
		
		printf("Nao foi possivel alocar espaco!\n\n");
		
		return;
		
	}
		
	for(i = 0; i < 14; i++)
		nova->codigo[i] = p->codigo[i];

	for(i = 0; i < 101; i++)
		nova->nome[i] = p->nome[i];
		
	nova->estoque = p->estoque;
	nova->preco = p->preco;
		
	nova->prox = temp->prox;
	temp->prox = nova;
		
	printf("Produto Adicionado!");
	printf("\n\n");
	
}

void Tratamento_Codigo(pro *listapro){
	
	int quantcod, i, count;
	char temp[14];

	quantcod = strlen(listapro->codigo);
	count = 13 - quantcod;

	for(i = 0; i < count; i++)
		temp[i] = '0';
	
	for(i = 0; i <= quantcod;i++){
		
		temp[count] = listapro->codigo[i];
		count++;
		
	}
	
	for(i = 0; i < 14; i++)
		listapro->codigo[i] = temp[i];	
			
}