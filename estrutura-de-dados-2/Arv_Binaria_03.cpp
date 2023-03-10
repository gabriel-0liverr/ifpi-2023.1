#include <iostream>
#include <stack>
using namespace std;

typedef struct no {
    int value;
    struct no* left;
    struct no* right;
} No;

No* criar_no(int value) {
    No* no = (No*) malloc(sizeof(No));
    no->value = value;
    no->left = NULL;
    no->right = NULL;
    return no;
}

void inserir_no(No** root, int value) {
    if (*root == NULL) {
        *root = criar_no(value);
    } else {
        if (value < (*root)->value) {
            inserir_no(&(*root)->left, value);
        } else {
            inserir_no(&(*root)->right, value);
        }
    }
}

void exibirFilhos(No* root){
    if(root != NULL){
        cout << " ( " << root->value;
        exibirFilhos(root->left);
        exibirFilhos(root->right);
        cout << " ) ";
    }
}

void checaEB(No* root){
    stack<No*> pilha;
    No* p = root;
    bool ver = 1;
    do{
        while (p!=NULL){
            pilha.push(p);
            p = p->left;
        }
        if (!pilha.empty()){
            p = pilha.top();
            pilha.pop();
            if(!((p->right && p->left) || (!p->right && !p->left))) ver = 0;
            p = p->right;
        }
    }while (!pilha.empty() || p!=NULL);

    if(ver == 0){
        cout << "NAO";
    } else {
        cout << "SIM";
    }
}

int main() {
    No* root = NULL;

    inserir_no(&root, 5);
    inserir_no(&root, 2);
    inserir_no(&root, 1);
    inserir_no(&root, 3);
    inserir_no(&root, 7);
    inserir_no(&root, 6);
    inserir_no(&root, 8);
    inserir_no(&root, 9);

    cout << "\nExibir Pais e Filhos:\n";
    exibirFilhos(root);
    cout << "\n";

    cout << "\nArvore Estritamente Binaria?\n";
    checaEB(root);
    cout << "\n";

    return 0;
}
