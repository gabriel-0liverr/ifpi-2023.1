#include <iostream>

using namespace std;

// Definição da estrutura de um nó da árvore binária
struct No {
    int valor;
    char operacao;
    No* esquerda;
    No* direita;
};

// Função auxiliar que verifica se um nó é uma folha (não tem subárvores)
bool ehFolha(No* no) {
    return no->esquerda == nullptr && no->direita == nullptr;
}

// Função recursiva que avalia a expressão a partir de um nó da árvore
int avaliarExpressao(No* no) {
    // Se o nó for uma folha, seu valor representa um número da expressão
    if (ehFolha(no)) {
        return no->valor;
    }
    // Senão, o nó representa uma operação e seus filhos representam os operandos
    int esquerda = avaliarExpressao(no->esquerda);
    int direita = avaliarExpressao(no->direita);
    // Realiza a operação a partir dos valores dos filhos
    switch (no->operacao) {
        case '+':
            return esquerda + direita;
        case '-':
            return esquerda - direita;
        case '*':
            return esquerda * direita;
        case '/':
            return esquerda / direita;
    }
}

// Função principal que cria a árvore e avalia a expressão
int valor(No* raiz) {
    return avaliarExpressao(raiz);
}

// Função principal que testa a função valor(A)
int main() {
    // Cria a árvore que representa a expressão ((5+3)/4)*(6-1)
    No* no1 = new No {5, '\0', nullptr, nullptr};
    No* no2 = new No {3, '\0', nullptr, nullptr};
    No* no3 = new No {'+', '+', no1, no2};
    No* no4 = new No {4, '\0', nullptr, nullptr};
    No* no5 = new No {'/', '/', no3, no4};
    No* no6 = new No {6, '\0', nullptr, nullptr};
    No* no7 = new No {1, '\0', nullptr, nullptr};
    No* no8 = new No {'-', '-', no6, no7};
    No* no9 = new No {'*', '*', no5, no8};
    // Avalia a expressão a partir da raiz da árvore
    int resultado = valor(no9);
    cout << "Resultado: " << resultado << endl; // Deve imprimir 8
    return 0;
}