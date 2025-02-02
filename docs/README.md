
# Implementação de um Sistema de Neurônios Simples

## Disciplina: Programação Orientada a Objetos

**Universidade Estadual de Londrina**

**Professor:** Bruno Squizato Faiçal

**Autor:** Adriano Lúcio Uchôa Brandão

---

## Descrição do Projeto

Este projeto consiste na **implementação de um sistema de neurônios simples** utilizando **Programação Orientada a Objetos (POO)** em  **C++** . O foco é criar uma hierarquia de classes que permita a manipulação de diferentes tipos de neurônios, especificamente o  **NeuronioReLU** .

### **Objetivos**

1. Implementar uma **classe abstrata** `Neuronio` para representar um neurônio genérico.
2. Criar a **classe derivada** `NeuronioReLU`, que implementa a função de ativação  **ReLU** .
3. Implementar o método `predict()`, que recebe entradas e calcula a saída baseada nos pesos e bias.
4. Criar uma `main()` para testar diferentes casos com **10 neurônios** e **10 vetores de entrada** variando de  **2 a 5 elementos** .
5. Utilizar **polimorfismo** para manipulação dos neurônios através de ponteiros para a classe base.

---

## Estrutura do Projeto

```
Trabalho_1/
│── 📁 .vscode/         # Configurações do VS Code
│   ├── launch.json    # Configuração para depuração
│   ├── tasks.json     # Configuração para compilação automática
│── 📁 build/          # Diretório para arquivos compilados
│   ├── main.exe       # Executável gerado pela compilação
│── 📁 docs/           # Documentação e referências
│   ├── Aula 19 - Projeto 1.pdf  
│   ├── notas de desenvolvimento.txt  
│   ├── README.md  
│── 📁 include/        # Arquivos de cabeçalho (.hpp)
│   ├── neuronio_relu.hpp  
│   ├── neuronio.hpp  
│── 📁 src/            # Código-fonte principal
│   ├── main.cpp  
│── .gitignore         # Arquivos a serem ignorados no Git
```

---

## Implementação

### **1. Classe Abstrata `Neuronio`**

A classe `Neuronio` serve como **base abstrata** para os diferentes tipos de neurônios. Contém:

* Um vetor de pesos.
* Um bias.
* Um método **virtual puro** `predict()`, que precisa ser implementado nas classes derivadas.
* Um método `getPesos()`, para acessar os pesos da classe (necessário para polimorfismo na `main()`).

### **2. Classe `NeuronioReLU`**

A classe `NeuronioReLU` herda de `Neuronio` e implementa o cálculo da saída aplicando a função  **ReLU** :

Saıˊda=max⁡(0,∑(entradai×pesoi)+bias)\text{Saída} = \max(0, \sum (\text{entrada}_i \times \text{peso}_i) + \text{bias})

* Foi utilizado **`size_t`** para manipulação segura dos vetores.
* O método `predict()` aplica a fórmula e retorna o resultado.

### **3. Implementação da `main.cpp`**

A função `main()`:

* Cria **10 neurônios** `NeuronioReLU` com diferentes pesos e bias.
* Define **10 conjuntos de entradas** variando de 2 a 5 elementos.
* Testa todos os neurônios com todas as entradas.
* Utiliza  **polimorfismo** , manipulando objetos das classes derivadas através de ponteiros para `Neuronio*`.
* Implementa **tratamento de erros** caso o número de entradas seja diferente do número de pesos.
* **Libera a memória alocada** corretamente ao final.

---

## **Notas de Desenvolvimento**

1. **Classe Abstrata:**
   * Definição de `Neuronio` como  **classe base** .
   * Uso de **método virtual puro** para garantir implementação nas classes derivadas.
   * Encapsulamento correto dos atributos.
2. **Melhoria na Passagem de Parâmetros:**
   * O vetor de entradas é passado **por referência constante** (`const vector<double>&`) para evitar cópias desnecessárias e melhorar a eficiência.
3. **Implementação da Função ReLU:**
   * Aplicada a função `max(0.0, soma)` para seguir corretamente a lógica da  **ReLU** .
4. **Uso Correto de Ponteiros e Polimorfismo:**
   * Objetos de `NeuronioReLU` são manipulados via **ponteiros da classe base** `Neuronio*`.
5. **Aprimoramento na `main()`:**
   * **Expansão** para **10 neurônios** e  **10 vetores de entrada** .
   * **Tratamento de erros** : verifica se o tamanho das entradas corresponde ao dos pesos.
   * **Liberação de memória** correta com `delete`.

---

## **Compilação e Execução**

Para compilar o código, utilize um compilador  **g++** :

```sh
 g++ main.cpp -o programa
```

Para executar:

```sh
 ./programa
```

---

## **Conclusão**

✅ **Todos os requisitos foram atendidos:**

* Uso de **classe abstrata** e  **método virtual puro** .
* Implementação de **NeuronioReLU** seguindo a fórmula da  **ReLU** .
* Manipulação de  **ponteiros para a classe base** .
* Uso de **vetores dinâmicos** para pesos e entradas.
* Implementação de **10 neurônios** e  **10 vetores de teste** .
* **Liberação correta de memória** para evitar vazamentos.

📌 **Este projeto demonstrou conceitos importantes de POO e Redes Neurais Simples.**
