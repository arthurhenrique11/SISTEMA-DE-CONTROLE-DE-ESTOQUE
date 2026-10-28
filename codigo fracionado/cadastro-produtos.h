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