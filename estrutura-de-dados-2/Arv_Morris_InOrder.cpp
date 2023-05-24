#include <iostream>
using namespace std;

struct NoArvore {
    int valor;
    NoArvore* esquerda;
    NoArvore* direita;

    NoArvore(int x) : valor(x), esquerda(nullptr), direita(nullptr) {}
};

void MorrisInOrder(NoArvore* raiz) {
    NoArvore* atual = raiz;
    while (atual != nullptr) {
        if (atual->esquerda == nullptr) {
            cout << atual->valor << " ";
            atual = atual->direita;
        } else {
            NoArvore* predecessor = atual->esquerda;
            while (predecessor->direita != nullptr && predecessor->direita != atual) {
                predecessor = predecessor->direita;
            }

            if (predecessor->direita == nullptr) {
                predecessor->direita = atual;
                atual = atual->esquerda;
            } else {
                predecessor->direita = nullptr;
                cout << atual->valor << " ";
                atual = atual->direita;
            }
        }
    }
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

    return raiz;
}

int main() {
    NoArvore* raiz = nullptr;
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 24);

    cout << "Percurso In-Order: ";
    MorrisInOrder(raiz);
    cout << endl;

    return 0;
}
