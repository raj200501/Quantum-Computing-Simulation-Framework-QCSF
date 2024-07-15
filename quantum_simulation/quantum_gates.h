#ifndef QUANTUM_GATES_H
#define QUANTUM_GATES_H

#include <complex>
#include <array>

class QuantumGate {
public:
    std::complex<double> apply(const std::complex<double> &amplitude, int qubit_state) const;

    std::array<std::array<std::complex<double>, 2>, 2> matrix;
};

QuantumGate HadamardGate();
QuantumGate CNOTGate();
QuantumGate OracleGate();
QuantumGate DiffusionGate();
QuantumGate ModExpGate(int a, int N);
QuantumGate RGate(double theta);

#endif // QUANTUM_GATES_H
