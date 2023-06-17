#include <iostream>
#include <algorithm>
using namespace std;

struct NoArvore {
    int valor;
    NoArvore* esquerda;
    NoArvore* direita;
    int altura;

    NoArvore(int x) : valor(x), esquerda(nullptr), direita(nullptr), altura(1) {}
};

int getAltura(NoArvore* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->altura;
}

int getBalanceamento(NoArvore* node) {
    if (node == nullptr) {
        return 0;
    }
    return getAltura(node->esquerda) - getAltura(node->direita);
}

NoArvore* rotacaoDireita(NoArvore* y) {
    NoArvore* x = y->esquerda;
    NoArvore* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(getAltura(y->esquerda), getAltura(y->direita)) + 1;
    x->altura = max(getAltura(x->esquerda), getAltura(x->direita)) + 1;

    return x;
}

NoArvore* rotacaoEsquerda(NoArvore* x) {
    NoArvore* y = x->direita;
    NoArvore* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(getAltura(x->esquerda), getAltura(x->direita)) + 1;
    y->altura = max(getAltura(y->esquerda), getAltura(y->direita)) + 1;

    return y;
}

NoArvore* inserir(NoArvore* raiz, int valor) {
    if (raiz == nullptr) {
        return new NoArvore(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    raiz->altura = max(getAltura(raiz->esquerda), getAltura(raiz->direita)) + 1;

    int balanceamento = getBalanceamento(raiz);

    // Verifica os casos de desbalanceamento e realiza as rotações necessárias
    if (balanceamento > 1 && valor < raiz->esquerda->valor) {
        return rotacaoDireita(raiz);
    }
    if (balanceamento < -1 && valor > raiz->direita->valor) {
        return rotacaoEsquerda(raiz);
    }
    if (balanceamento > 1 && valor > raiz->esquerda->valor) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }
    if (balanceamento < -1 && valor < raiz->direita->valor) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void inorder(NoArvore* raiz) {
    if (raiz != nullptr) {
        inorder(raiz->esquerda);
        cout << raiz->valor << " ";
        inorder(raiz->direita);
    }
}

int main() {
    NoArvore* raiz = nullptr;
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 22);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 63);

    cout << "Percurso In-Order: ";
    inorder(raiz);
    cout << endl;

    return 0;
}
