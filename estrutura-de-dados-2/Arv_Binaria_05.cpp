#include <iostream>
#include <string>

using namespace std;

struct No {
    string value;
    No* left;
    No* right;
};

No* criar_no(string value) {
    No* no = new No;
    no->value = value;
    no->left = nullptr;
    no->right = nullptr;
    return no;
}

void inserir_no(No* &root, string value) {
    if (root == nullptr) {
        root = criar_no(value);
        return;
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

int valor(No* no) {
  if (no->value[0] >= '0' && no->value[0] <= '9') { // verifica se o nó é um número
    return stoi(no->value); // converte char para string e depois para int
  } else { // nó é um operador
    int esq = valor(no->left); // avalia a subárvore esquerda
    int dir = valor(no->right); // avalia a subárvore direita

    switch (no->value[0]) { // realiza a operação correspondente ao operador
      case '+':
        return esq + dir;
      case '-':
        return esq - dir;
      case '*':
        return esq * dir;
      case '/':
        return esq / dir;
      default:
        return 0;
    }
  }
}

int main() {
    No* root = nullptr;
    inserir_no(root, "*");
    inserir_no(root->left, "/");
    inserir_no(root->left->left, "+");
    inserir_no(root->left->left->left, "5");
    inserir_no(root->left->left->right, "3");
    inserir_no(root->left->right, "4");
    inserir_no(root->right, "-");
    inserir_no(root->right->left, "6");
    inserir_no(root->right->right, "1");

    cout << "\nArvore de Expressão Aritmética:\n";
    exibirNos(root);
    cout << "\n";

    cout << "\nResultado:\n";
    cout << valor(root);
    cout << "\n";
    return 0;
}
