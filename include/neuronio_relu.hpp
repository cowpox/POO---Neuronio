#ifndef NEURONIO_RELU_HPP
#define NEURONIO_RELU_HPP

#include "neuronio.hpp"
#include <vector>
#include <algorithm> // Para usar std::max

using namespace std;

class NeuronioReLU : public Neuronio {
public:
    // Construtor que chama o construtor da classe base
    NeuronioReLU(const vector<double>& pesos, double bias)
        : Neuronio(pesos, bias) {}

    // Implementação do método predict() usando a função ReLU
    double predict(const vector<double>& entradas) const override {
        double soma = bias;  // Começamos com o bias

        // Somatório ponderado das entradas e pesos
        // usado size_t como tipo seguro para índices de vetor
        // (evita problemas com números negativos)
        for (size_t i = 0; i < entradas.size(); i++) {
            soma += entradas[i] * pesos[i];
        }

        // Aplicação da função ReLU: max(0, soma)
        return max(0.0, soma);
    }
};

#endif