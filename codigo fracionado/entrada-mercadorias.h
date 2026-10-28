// 5. Função para entrada de mercadorias
void registrarEntrada() {
    int codigo, qtdEntrada;

    if (totalCadastrados == 0) {
        printf("\n[Atencao] Nenhum produto cadastrado para receber entrada.\n");
        return;
    }

    consultarEstoque();
    printf("\nDigite o codigo do produto para dar entrada: ");
    scanf("%d", &codigo);

    if (codigo < 0 || codigo >= totalCadastrados) {
        printf("\n[Erro] Codigo invalido!\n");
        return;
    }

    printf("Digite a quantidade de unidades recebidas: ");
    scanf("%d", &qtdEntrada);

    // Validação para não aceitar valores negativos ou zero
    if (qtdEntrada <= 0) {
        printf("\n[Erro] Quantidade invalida! Informe um valor maior que zero.\n");
    } else {
        quantidades[codigo] = quantidades[codigo] + qtdEntrada;
        printf("\n[Sucesso] Entrada registrada! Nova quantidade do produto '%s': %d\n", nomes[codigo], quantidades[codigo]);
    }
}
