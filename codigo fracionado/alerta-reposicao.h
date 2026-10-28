// 4. Função para alerta de reposição
void alertaReposicao() {
    int i;
    int encontrou = 0;

    printf("\n========================================\n");
    printf("       PRODUTOS COM BAIXO ESTOQUE       \n");
    printf("========================================\n");

    for (i = 0; i < totalCadastrados; i++) {
        if (quantidades[i] < 5) {
            printf("Codigo: %d | Nome: %s | Quantidade atual: %d\n", i, nomes[i], quantidades[i]);
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("Otimo! Nenhum produto precisa de reposicao no momento.\n");
    }
    printf("========================================\n");
}
