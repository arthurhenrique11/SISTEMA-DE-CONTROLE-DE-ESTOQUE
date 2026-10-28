// Função principal com o Menu
int main() {
    int opcao;

    do {
        printf("\n========================================\n");
        printf("         CONTROLE DE ESTOQUE - LOJA     \n");
        printf("========================================\n");
        printf("1. Cadastrar produtos\n");
        printf("2. Consultar estoque\n");
        printf("3. Registrar venda\n");
        printf("4. Consultar produtos que precisam de reposicao\n");
        printf("5. Registrar entrada de mercadorias\n");
        printf("6. Encerrar o programa\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProdutos();
                break;
            case 2:
                consultarEstoque();
                break;
            case 3:
                registrarVenda();
                break;
            case 4:
                alertaReposicao();
                break;
            case 5:
                registrarEntrada();
                break;
            case 6:
                printf("\nEncerrando o programa. Ate logo!\n");
                break;
            default:
                printf("\n[Erro] Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}           