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

void exibir_asc(No* root){
    if(root != nullptr){
        exibir_asc(root->left);
        cout << " < " << root->value << " > ";
        exibir_asc(root->right);
    }
}

void exibir_dec(No* root){
    if(root != nullptr){
        exibir_dec(root->right);
        cout << " < " << root->value << " > ";
        exibir_dec(root->left);
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

    cout << "\nArvore Ascendente:\n";
    exibir_asc(root);
    cout << "\n";

    cout << "\nArvore Decrescente:\n";
    exibir_dec(root);
    cout << "\n";

    return 0;
}