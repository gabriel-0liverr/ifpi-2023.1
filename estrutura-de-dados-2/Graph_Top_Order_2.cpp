#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// Função recursiva para realizar a ordenação topológica
void topologicalSortDFS(int vertex, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& result) {
    visited[vertex] = true;

    // Percorre os vértices adjacentes
    for (int adj : graph[vertex]) {
        if (!visited[adj]) {
            topologicalSortDFS(adj, graph, visited, result);
        }
    }

    // Adiciona o vértice atual à pilha
    result.push(vertex);
}

// Função para realizar a ordenação topológica
vector<string> topologicalSort(vector<vector<int>>& graph, vector<string>& disciplinas) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    stack<int> result;

    // Realiza a ordenação topológica para todos os vértices não visitados
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, graph, visited, result);
        }
    }

    // Armazena o resultado da ordenação topológica em um vetor
    vector<string> sortedOrder;
    while (!result.empty()) {
        sortedOrder.push_back(disciplinas[result.top()]);
        result.pop();
    }

    return sortedOrder;
}

int main() {
    int numVertices = 10;
    vector<vector<int>> graph(numVertices);

    // Nomes das disciplinas
    vector<string> disciplinas = {
        "Arquitetura de Computadores",
        "Matematica Discreta",
        "Algoritmos",
        "Calculo 1",
        "Linguagem de Programacao",
        "Calculo 2",
        "Programacao Orientada a Objetos",
        "Estrutura de Dados",
        "Calculo Numerico Computacional",
        "Banco de Dados"
    };

    // Adiciona as arestas do grafo conforme as dependências descritas
    graph[2].push_back(0); // Arquitetura de Computadores -> Algoritmos
    graph[2].push_back(1); // Matematica Discreta -> Algoritmos
    graph[3].push_back(1); // Matematica Discreta -> Calculo 1
    graph[4].push_back(2); // Algoritmos -> Linguagem de Programacao
    graph[5].push_back(3); // Calculo 1 -> Calculo 2
    graph[6].push_back(4); // Linguagem de Programacao -> Programacao Orientada a Objetos
    graph[7].push_back(4); // Linguagem de Programacao -> Estrutura de Dados
    graph[8].push_back(5); // Calculo 2 -> Calculo Numerico Computacional
    graph[8].push_back(7); // Estrutura de Dados -> Calculo Numerico Computacional
    graph[9].push_back(7); // Estrutura de Dados -> Banco de Dados

    // Mapeamento das disciplinas para os módulos
    map<string, int> modulos = {
        {"Arquitetura de Computadores", 1},
        {"Matematica Discreta", 1},
        {"Algoritmos", 2},
        {"Calculo 1", 2},
        {"Linguagem de Programacao", 3},
        {"Calculo 2", 3},
        {"Programacao Orientada a Objetos", 4},
        {"Estrutura de Dados", 4},
        {"Calculo Numerico Computacional", 5},
        {"Banco de Dados", 5}
    };

    // Realiza a ordenação topológica
    vector<string> sortedOrder = topologicalSort(graph, disciplinas);

    // Imprime as disciplinas agrupadas por módulo
    cout << "Disciplinas agrupadas por modulo:" << endl;
    map<int, vector<string>> moduloDisciplinas;
    for (const string& disciplina : sortedOrder) {
        int modulo = modulos[disciplina];
        moduloDisciplinas[modulo].push_back(disciplina);
    }

    for (const auto& entry : moduloDisciplinas) {
        int modulo = entry.first;
        const vector<string>& disciplinas = entry.second;

        cout << endl << "Modulo " << modulo << ":" << endl;
        for (const string& disciplina : disciplinas) {
            cout << " " << disciplina << endl;
        }
        cout << endl;
    }

    return 0;
}
