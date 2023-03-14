//Atividade 2 - Questao 13.2 (pag 138 do livro)

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

int contarNos(No *root){
   if(root == nullptr)
        return 0;
   else
        return 1 + contarNos(root->left) + contarNos(root->right);
}

int contarFolhas(No *root){
   if(root == nullptr)
        return 0;
   if(root->left == nullptr && root->right == nullptr)
        return 1;
   return contarFolhas(root->left) + contarFolhas(root->right);
}

int altura(No *root){
    if(root == nullptr){
        return -1;
    }
    else{
        int l = altura(root->left);
        int r = altura(root->right);
        if(l > r){
            return l + 1;
        }
        else{
            return r + 1;
        }
    }
}

No* buscar(No *root, int num){
    if(root){
        if(num == root->value){
            return root;
        }
        else if(num < root->value){
            return buscar(root->left, num);
        }
        else{
            return buscar(root->right, num);
        }
    }
    return nullptr;
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

    printf("\nQuantidade de Nos: %d", contarNos(root));
    printf("\n");

    printf("\nNumero de Folhas: %d", contarFolhas(root));
    printf("\n");

    printf("\nAltura da Arvore: %d", altura(root));
    printf("\n");

    No* busca = buscar(root, 10);
    if(busca){
        printf("\n\tValor encontrado: %d\n", busca->value);
    }
    else{
        printf("\n\tValor nao encontrado!\n");
    }

    printf("\nExibir Pais e Filhos...\n");
    exibirFilhos(root);
    printf("\n");

    return 0;
}
