#include <iostream>

using namespace std;

struct No {
    char value;
    No* left;
    No* right;
};

No* criar_no(char value) {
    No* no = new No;
    no->value = value;
    no->left = nullptr;
    no->right = nullptr;
    return no;
}

void inserir_no(No* &root, char value) {
    if (root == nullptr) {
        root = criar_no(value);
    } else if (value < root->value) {
            inserir_no(root->left, value);
    } else if (value > root->value) {
            inserir_no(root->right, value);
    }
}

void exibirNos(No* root){
    if(root != nullptr){
        cout << " ( " << root->value;
        exibirNos(root->left);
        exibirNos(root->right);
        cout << " ) ";
    }
}

void remover_no(No* &root, char value) {
    if (root == nullptr) {
        cout << "NAO ENCONTRADO";
        return;
    } else if (value < root->value) {
        remover_no(root->left, value);
    } else if (value > root->value) {
        remover_no(root->right, value);
    } else {
        delete root;
        root = nullptr;
        cout << "Removido com sucesso!";
        return;
    }
}

int main() {
    No* root = nullptr;
    inserir_no(root, 'D');
    inserir_no(root, 'B');
    inserir_no(root, 'A');
    inserir_no(root, 'C');
    inserir_no(root, 'F');
    inserir_no(root, 'E');
    inserir_no(root, 'G');

    cout << "\nArvore Antes:\n";
    exibirNos(root);
    cout << "\n";

    cout << "\nRemovendo F...\n";
    remover_no(root , 'F');
    cout << "\n";

    cout << "\nArvore Depois:\n";
    exibirNos(root);
    cout << "\n";

    return 0;
}