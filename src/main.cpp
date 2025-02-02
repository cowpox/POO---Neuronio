#include <iostream>
#include <vector>
#include "../include/neuronio_relu.hpp"

using namespace std;

int main() {
    // Criando um vetor de ponteiros para Neuronio (polimorfismo)
    vector<Neuronio*> neuronios;

    // Criando 10 neurônios com diferentes pesos e bias
    neuronios.push_back(new NeuronioReLU({0.2, 0.4}, -1.5)); // Exemplo do enunciado (Caso 1)
    neuronios.push_back(new NeuronioReLU({0.2, 0.4}, -0.5)); // Exemplo do enunciado (Caso 2)
    neuronios.push_back(new NeuronioReLU({-0.1, 0.5}, 0.2));
    neuronios.push_back(new NeuronioReLU({0.5, -0.3, 0.8}, -0.2));
    neuronios.push_back(new NeuronioReLU({-0.4, 0.7, 0.1}, 0.5));
    neuronios.push_back(new NeuronioReLU({0.3, -0.6, 0.9, -0.2}, -0.1));
    neuronios.push_back(new NeuronioReLU({0.1, 0.2, -0.5, 0.4}, 0.3));
    neuronios.push_back(new NeuronioReLU({-0.7, 0.9, 0.5, -0.3, 0.2}, -0.4));
    neuronios.push_back(new NeuronioReLU({0.8, -0.1, 0.3, 0.7, -0.2}, 0.6));
    neuronios.push_back(new NeuronioReLU({-0.2, 0.4, -0.3, 0.1, 0.5}, -0.3));

    // Criando 10 vetores de entrada com tamanhos variados (de 2 a 5 elementos)
    vector<vector<double>> entradas_testes = {
        {0.3, 2.0},               // Exemplo do enunciado (Caso 1 e 2)
        {1.0, -1.0},              // 2 entradas
        {-0.5, 0.8},              // 2 entradas
        {2.5, -1.5, 0.7},         // 3 entradas
        {0.1, 0.4, -0.3},         // 3 entradas
        {-0.2, 0.3, 0.6, -0.1},   // 4 entradas
        {0.8, -0.1, 0.3, 0.7},    // 4 entradas
        {0.5, -0.3, 0.8, 0.2, 0.4}, // 5 entradas
        {-0.7, 0.9, 0.5, -0.3, 0.2}, // 5 entradas
        {0.2, -0.4, 0.3, -0.1, 0.5}  // 5 entradas
    };

    // Executando os testes
    cout << "=== Testando 10 Neuronios ReLU ===" << endl;

    for (size_t i = 0; i < neuronios.size(); i++) {
        cout << "\nNeurônio " << i + 1 << " (Pesos e Bias personalizados)" << endl;
        
        for (size_t j = 0; j < entradas_testes.size(); j++) {
            // Agora usamos o método getPesos() para acessar os pesos
            if (entradas_testes[j].size() == neuronios[i]->getPesos().size()) {
                cout << "Entradas: [";
                for (size_t k = 0; k < entradas_testes[j].size(); k++) {
                    cout << entradas_testes[j][k];
                    if (k < entradas_testes[j].size() - 1) cout << ", ";
                }
                cout << "] -> Saída: " << neuronios[i]->predict(entradas_testes[j]) << endl;
            } else {
                cout << "ERRO: O número de entradas não corresponde ao número de pesos do neurônio " << i + 1 << endl;
            }
        }
        cout << "-----------------------------" << endl;
    }

    // Liberando memória (evita vazamento de memória)
    for (auto ptr : neuronios) {
        delete ptr;
    }

    return 0;
}
