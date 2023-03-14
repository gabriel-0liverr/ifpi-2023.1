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

int altura(No* no) {
    if (no == nullptr) {
        return 0;
    }
    
    return 1 + max(altura(no->left), altura(no->right));
}

bool cheia(No* root) {
    // Se a árvore está vazia, ela é uma árvore cheia
    if (root == nullptr) {
        return true;
    }
    
    // Se um nó não tem ambos os filhos, a árvore não é cheia
    if (root->left == nullptr && root->right != nullptr) {
        return false;
    }
    
    if (root->left != nullptr && root->right == nullptr) {
        return false;
    }
    
    // Verifique se todas as folhas da árvore estão no mesmo nível
    int leftHeight = altura(root->left);
    int rightHeight = altura(root->right);
    
    if (leftHeight != rightHeight) {
        return false;
    }
    
    // Verifique as subárvores esquerda e direita recursivamente
    return cheia(root->left) && cheia(root->right);
}
bool completa(No* root) {
    if (root == nullptr) {
        return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    else if (root->left != nullptr && root->right == nullptr) {
        return false;
    }
    else if (root->left == nullptr && root->right != nullptr) {
        return false;
    }
    return completa(root->left) && completa(root->right);
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

    cout << "\nArvore:\n";
    exibirNos(root);
    cout << "\n";

    cout << "\nArvore Completa?\n";
    if (completa(root) == true) {
        cout << "SIM";
    } else {
        cout << "NAO";
    }
    cout << "\n";

    return 0;
}