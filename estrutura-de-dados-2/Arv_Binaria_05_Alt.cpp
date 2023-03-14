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
    if (value == "+" || value == "-" || value == "*" || value == "/") {
        no->value = value;
    } else {
        no->value = to_string(stoi(value));
    }
    no->left = nullptr;
    no->right = nullptr;
    return no;
}

void inserir_no(No** root, string value) {
    if (*root == nullptr) {
        *root = criar_no(value);
    } else if ((*root)->value == "+" || (*root)->value == "-" || (*root)->value == "*" || (*root)->value == "/") {
        if ((*root)->left == nullptr) {
            inserir_no(&((*root)->left), value);
        } else {
            inserir_no(&((*root)->right), value);
        }
    }
}

void exibirNos(No* root){
    if(root != nullptr){
        exibirNos(root->left);
        cout << " " << root->value << " ";
        exibirNos(root->right);
    }
}

int main() {
    No* root = nullptr;
    inserir_no(&root, "*");
    inserir_no(&root, "/");
    inserir_no(&root, "+");
    inserir_no(&root, "5");
    inserir_no(&root, "3");
    inserir_no(&root, "4");

    cout << "\nArvore:\n";
    exibirNos(root);
    cout << "\n";

    return 0;
}