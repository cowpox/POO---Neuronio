#ifndef NEURONIO_HPP
#define NEURONIO_HPP

#include <vector>

using namespace std;

class Neuronio {
protected:
    vector<double> pesos;
    double bias;

public:
    // Construtor
    Neuronio(const vector<double>& pesos, double bias) 
        : pesos(pesos), bias(bias) {}

    // Método virtual puro (obrigatório na classe derivada)
    virtual double predict(const vector<double>& entradas) const = 0;

    // Método para acessar os pesos (encapsulamento)
    const vector<double>& getPesos() const {
        return pesos;
    }

    // Destrutor virtual
    virtual ~Neuronio() {}
};

#endif