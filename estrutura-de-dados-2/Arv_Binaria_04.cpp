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

void exibirFilhos(No* root){
    if(root != nullptr){
        cout << " ( " << root->value;
        exibirFilhos(root->left);
        exibirFilhos(root->right);
        cout << " ) ";
    }
}

bool igual(No* root1, No* root2) {
    stack<No*> pilha1, pilha2;
    if (root1 != nullptr) {
        pilha1.push(root1);
    }
    if (root2 != nullptr) {
        pilha2.push(root2);
    }
    while (!pilha1.empty() && !pilha2.empty()) {
        No* atual1 = pilha1.top();
        pilha1.pop();
        No* atual2 = pilha2.top();
        pilha2.pop();
        if (atual1->value != atual2->value) {
            return false;
        }
        if (atual1->left != nullptr) {
            pilha1.push(atual1->left);
        }
        if (atual2->left != nullptr) {
            pilha2.push(atual2->left);
        }
        if (pilha1.size() != pilha2.size()) {
            return false;
        }
        if (atual1->right != nullptr) {
            pilha1.push(atual1->right);
        }
        if (atual2->right != nullptr) {
            pilha2.push(atual2->right);
        }
        if (pilha1.size() != pilha2.size()) {
            return false;
        }
    }
    return pilha1.empty() && pilha2.empty();
}

int main() {
    No* root1 = nullptr;
    inserir_no(&root1, 5);
    inserir_no(&root1, 2);
    inserir_no(&root1, 1);
    inserir_no(&root1, 3);
    inserir_no(&root1, 7);
    inserir_no(&root1, 6);
    inserir_no(&root1, 8);

    No* root2 = nullptr;
    inserir_no(&root2, 5);
    inserir_no(&root2, 2);
    inserir_no(&root2, 1);
    inserir_no(&root2, 3);
    inserir_no(&root2, 7);
    inserir_no(&root2, 6);
    inserir_no(&root2, 10);

    cout << "\nArvore 1:\n";
    exibirFilhos(root1);
    cout << "\n";

    cout << "\nArvore 2:\n";
    exibirFilhos(root2);
    cout << "\n";

    cout << "\nAs Arvores 1 e 2 sao iguais?\n";
    if (igual(root1, root2)) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
