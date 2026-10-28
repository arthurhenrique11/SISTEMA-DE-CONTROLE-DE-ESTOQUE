#include <stdio.h>
#include <string.h>

// Definição de constantes e variáveis globais para facilitar o controle do iniciante
#define MAX_PRODUTOS 10

char nomes[MAX_PRODUTOS][50];
float precos[MAX_PRODUTOS];
int quantidades[MAX_PRODUTOS];
int totalCadastrados = 0; // Controla quantos produtos já foram cadastrados

// 1. Função para cadastrar produtos
void cadastrarProdutos() {
    if (totalCadastrados >= MAX_PRODUTOS) {
        printf("\n[Erro] O estoque esta cheio! Nao e possivel cadastrar mais produtos.\n");
        return;
    }

    printf("\n--- CADASTRO DE PRODUTO [%d/%d] ---\n", totalCadastrados + 1, MAX_PRODUTOS);
    
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", nomes[totalCadastrados]); // Leitura de string com espaços
    
    printf("Digite o preco unitario: R$ ");
    scanf("%f", &precos[totalCadastrados]);
    
        
    scanf("%d", &quantidades[totalCadastrados]);

    totalCadastrados++;
    printf("\n[Sucesso] Produto cadastrado com sucesso!\n");
}

// Função auxiliar para calcular o faturamento de uma venda
float calcularFaturamento(float precoUnitario, int qtdVendida) {
    float total = precoUnitario * qtdVendida;
    return total;
}

// Função auxiliar para calcular o valor total do estoque
float calcularValorTotalEstoque() {
    float valorTotal = 0;
    int i;
    for (i = 0; i < totalCadastrados; i++) {
        valorTotal = valorTotal + (precos[i] * quantidades[i]);
    }
    return valorTotal;
}

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