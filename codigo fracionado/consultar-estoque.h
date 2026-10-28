// 2. Função para consultar estoque
void consultarEstoque() {
    int i;
    if (totalCadastrados == 0) {
        printf("\n[Atencao] Nenhum produto cadastrado no estoque.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           RELATORIO DE ESTOQUE         \n");
    printf("========================================\n");
    for (i = 0; i < totalCadastrados; i++) {
        printf("Codigo: %d\n", i);
        printf("Nome: %s\n", nomes[i]);
        printf("Preco Unitario: R$ %.2f\n", precos[i]);
        printf("Quantidade em Estoque: %d\n", quantidades[i]);
        printf("----------------------------------------\n");
    }

    // Apresenta o valor total financeiro do estoque
    float valorGeral = calcularValorTotalEstoque();
    printf("Valor Total Financeiro do Estoque: R$ %.2f\n", valorGeral);
    printf("========================================\n");
}