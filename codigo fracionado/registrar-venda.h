// 3. Função para registrar venda
void registrarVenda() {
    int codigo, qtdDesejada;
    
    if (totalCadastrados == 0) {
        printf("\n[Atencao] Cadastre produtos antes de registrar vendas.\n");
        return;
    }

    consultarEstoque();
    printf("\nDigite o codigo do produto que deseja comprar: ");
    scanf("%d", &codigo);

    // Validação simples se o código existe
    if (codigo < 0 || codigo >= totalCadastrados) {
        printf("\n[Erro] Codigo de produto invalido!\n");
        return;
    }

    printf("Digite a quantidade desejada: ");
    scanf("%d", &qtdDesejada);

    // Verifica se tem estoque suficiente
    if (quantidades[codigo] >= qtdDesejada) {
        quantidades[codigo] = quantidades[codigo] - qtdDesejada;
        
        // Calcula o faturamento usando a função solicitada
        float valorFinal = calcularFaturamento(precos[codigo], qtdDesejada);
        
        printf("\n[Sucesso] Venda realizada com sucesso!\n");
        printf("Valor total da venda: R$ %.2f\n", valorFinal);
    } else {
        printf("\n[Erro] Venda nao realizada. Quantidade em estoque insuficiente! (Disponivel: %d)\n", quantidades[codigo]);
    }
}