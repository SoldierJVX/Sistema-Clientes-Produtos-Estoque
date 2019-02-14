void Vendas(cli *listacli, pro *listapro);

void Tratamento_CPF(cli *listacli);
void Tratamento_Codigo(pro *listapro);

void clrscr();

void Vendas(cli *listacli, pro *listapro){
	
	pro *ppro;
	cli *pcli;
	
	int quant;
	double valorpago;
	
	if(listacli->prox == NULL){
		
		printf("Sem clientes cadastrados no sistema!\n\n");
		return;
		
	}
	
	if(listapro->prox == NULL){
		
		printf("Sem produtos cadastrados no sistema!\n\n");
		return;
		
	}
	
	
	printf("Digite o codigo do produto a ser vendido: ");
	scanf("%s", listapro->codigo);
	
	Tratamento_Codigo(listapro);
	
	ppro = listapro->prox;
	
	while(ppro != NULL && strcmp(listapro->codigo,ppro->codigo) > 0)
		ppro = ppro->prox;
	
	if(strcmp(listapro->codigo,ppro->codigo) != 0){
		
		printf("Codigo de Produto inexistente!\n\n");
		return;
		
	}
	
	printf("Digite o CPF do usuario: ");
	scanf("%s", listacli->cpf);
	
	Tratamento_CPF(listacli);
	
	pcli = listacli->prox;
	
	while(pcli != NULL && strcmp(listacli->cpf, pcli->cpf) > 0)
		pcli = pcli->prox;
	
	if(strcmp(listacli->cpf, pcli->cpf) != 0){
		
		printf("CPF inexistente!\n\n");
		return;
		
	}
	
	printf("Digite a quantidade a ser vendida: ");
	scanf("%d", &quant);
	
	if(quant > ppro->estoque){

		printf("Sem estoque suficiente\n\n");
		return;		
		
	}
	
	ppro->estoque = ppro->estoque - quant;
	valorpago = quant * ppro->preco;
	
	printf("Total da Compra: %.2f\n\n", valorpago);
	
}