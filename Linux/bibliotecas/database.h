typedef struct cliente{
	
	char cpf[12];
	char nome[101];
	
	struct cliente *prox;
	
}cli;

typedef struct produto{

	char codigo[14];
	char nome[101];
	
	int estoque;
	double preco;
	
	struct produto *prox;

}pro;

void Salvar_Dados(cli *listacli, pro *listapro);
void Recuperar_Dados(cli *listacli, pro *listapro);

void Salvar_Cliente(cli *listacli);
void Salvar_Produto(pro *listapro);

void Recuperar_Cliente(cli *listacli);
void Recuperar_Produto(pro *listapro);

void Salvar_Dados(cli *listacli, pro *listapro){
	
	Salvar_Cliente(listacli);	
	Salvar_Produto(listapro);
	
}

void Salvar_Cliente(cli *listacli){
	
	FILE *arqcli;	
	
	cli *pcli;
	
	pcli = listacli->prox;
	
	if(listacli->prox != NULL){
		
		arqcli = fopen("./data_cli.txt", "a");
		
		fclose(arqcli);
		
		arqcli = fopen("./data_cli.txt", "w");		
		
	}
	
	while(pcli != NULL){
		
		fprintf(arqcli, "CPF: %s // Nome: %s \n", pcli->cpf, pcli->nome);
		pcli = pcli->prox;

	}
	
	if(listacli->prox != NULL)
		fclose(arqcli);
	else
		remove("./data_cli.txt");
	
}

void Salvar_Produto(pro *listapro){
	
	FILE *arqpro;

	pro *ppro;
	
	ppro = listapro->prox;
	
	if(listapro->prox != NULL){
		
		arqpro = fopen("./data_pro.txt", "a");
		
		fclose(arqpro);	
		
		arqpro = fopen("./data_pro.txt", "w");
		
	}

	while(ppro != NULL){
		
		fprintf(arqpro, "Codigo: %s // Nome: %s // Estoque: %d // Preco %.2f \n", ppro->codigo, ppro->nome, ppro->estoque, ppro->preco);
		ppro = ppro->prox;

	}

	if(listapro->prox != NULL)
		fclose(arqpro);		
	else
		remove("./data_pro.txt");
}

void Recuperar_Dados(cli *listacli, pro *listapro){

	Recuperar_Cliente(listacli);	
	Recuperar_Produto(listapro);
	
}

void Recuperar_Cliente(cli *listacli){

	FILE *arq;
	cli *p, *novo, *temp;
	int i;

	p = temp = listacli;

	arq = fopen("./data_cli.txt", "r");

	if(arq == NULL){

		return;

	}

	while(feof(arq) == 0){

		fscanf(arq, "CPF: %s // Nome: %s \n", p->cpf, p->nome);
	
		novo = (cli *) malloc(sizeof(cli));
			
		for(i = 0; i < 12; i++)
			novo->cpf[i] = p->cpf[i];
				
		for(i = 0; i < 101; i++)
			novo->nome[i] = p->nome[i];
				
		novo->prox = temp->prox;
		temp->prox = novo;
		temp = temp->prox;

	}

	fclose(arq);
	
}

void Recuperar_Produto(pro *listapro){
	
	FILE *arq;
	pro *p, *novo, *temp;
	int i;
	
	p = temp = listapro;
	
	arq = fopen("./data_pro.txt", "r");
	
	if(arq == NULL){

		return;

	}
	
	while(feof(arq) == 0){

		fscanf(arq, "Codigo: %s // Nome: %s // Estoque: %d // Preco %lf \n", p->codigo, p->nome, &p->estoque, &p->preco);
	
		novo = (pro *) malloc(sizeof(pro));
			
		for(i = 0; i < 14; i++)
			novo->codigo[i] = p->codigo[i];

		for(i = 0; i < 101; i++)
			novo->nome[i] = p->nome[i];
		
		novo->estoque = p->estoque;
		novo->preco = p->preco;
				
		novo->prox = temp->prox;
		temp->prox = novo;
		temp = temp->prox;

	}

	fclose(arq);

}