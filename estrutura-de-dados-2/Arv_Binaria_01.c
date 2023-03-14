//Atividade 1 - Criação da árvore, impressao dos nós
//(mostrando raiz e os filhos da raiz)
//e percurso em largura

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int value;
    struct no* left;
    struct no* right;
} No;

No* criar_no(int value) {
    No* no = (No*) malloc(sizeof(No));
    no->value = value;
    no->left = nullptr;
    no->right = nullptr;
    return no;
}

void inserir_no(No** root, int value) {
    if (*root == nullptr) {
        *root = criar_no(value);
    } else {
        if (value < (*root)->value) {
            inserir_no(&(*root)->left, value);
        } else {
            inserir_no(&(*root)->right, value);
        }
    }
}

void exibirEmOrdem(No* root){
    if(root != nullptr){
        exibirEmOrdem(root->left);
        printf(" (%d) ", root->value);
        exibirEmOrdem(root->right);
    }
}

void exibirPreOrdem(No* root){
    if(root != nullptr){
        printf(" (%d) ", root->value);
        exibirPreOrdem(root->left);
        exibirPreOrdem(root->right);
    }
}

void exibirPosOrdem(No* root){
    if(root != nullptr){
        exibirPosOrdem(root->left);
        exibirPosOrdem(root->right);
        printf(" (%d) ", root->value);
    }
}

void exibirFilhos(No* root){
    if(root != nullptr){
        printf(" ( %d ", root->value);
        exibirFilhos(root->left);
        exibirFilhos(root->right);
        printf(" ) ");
    }
}

int main() {
    No* root = nullptr;

    inserir_no(&root, 5);
    inserir_no(&root, 2);
    inserir_no(&root, 1);
    inserir_no(&root, 3);
    inserir_no(&root, 6);
    inserir_no(&root, 8);
    inserir_no(&root, 7);
    inserir_no(&root, 9);

    printf("\nEm Ordem:\n");
    exibirEmOrdem(root);
    printf("\n");

    printf("\nPre Ordem:\n");
    exibirPreOrdem(root);
    printf("\n");

    printf("\nPos Ordem:\n");
    exibirPosOrdem(root);
    printf("\n");

    printf("\nExibir Pais e Filhos:\n");
    exibirFilhos(root);
    printf("\n");

    return 0;
}
