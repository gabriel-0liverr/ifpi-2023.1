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
    no->left = NULL;
    no->right = NULL;
    return no;
}

void inserir_no(No* &root, char value) {
    if (root == NULL) {
        root = criar_no(value);
    } else if (value < root->value) {
            inserir_no(root->left, value);
    } else if (value > root->value) {
            inserir_no(root->right, value);
    }
}

void exibirNos(No* root){
    if(root != NULL){
        cout << " ( " << root->value;
        exibirNos(root->left);
        exibirNos(root->right);
        cout << " ) ";
    }
}

int main() {
    No* root = NULL;
    inserir_no(root, 'D');
    inserir_no(root, 'B');
    inserir_no(root, 'A');
    inserir_no(root, 'C');
    inserir_no(root, 'F');
    inserir_no(root, 'E');
    inserir_no(root, 'G');

    cout << "\nArvore:\n";
    exibirNos(root);
    cout << "\n";

    return 0;
}
