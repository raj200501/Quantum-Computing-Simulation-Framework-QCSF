#include "quantum_gates.h"
#include <cmath>
#include <complex>

std::complex<double> QuantumGate::apply(const std::complex<double> &amplitude, int qubit_state) const {
    return matrix[qubit_state][0] * amplitude + matrix[qubit_state][1] * amplitude;
}

#if 0
QuantumGate HadamardGate() {
    QuantumGate gate;
    gate.matrix = {{{1 / std::sqrt(2), 1 / std::sqrt(2)}, {1 / std::sqrt(2), -1 / std::sqrt(2)}}};
    return gate;
}

QuantumGate CNOTGate() {
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, 1}}, {{0, 1}, {1, 0}}};
    return gate;
}

QuantumGate OracleGate() {
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, -1}}, {{0, 1}, {1, 0}}};
    return gate;
}

QuantumGate DiffusionGate() {
    QuantumGate gate;
    gate.matrix = {{{2, 0}, {0, -1}}, {{0, 1}, {1, 0}}};
    return gate;
}

QuantumGate ModExpGate(int a, int N) {
    // Implement the modular exponentiation gate here
    // This is a placeholder example
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, 1}}, {{0, 1}, {1, 0}}};
    return gate;
}

QuantumGate RGate(double theta) {
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, std::exp(std::complex<double>(0, theta))}}};
    return gate;
}
#endif

QuantumGate HadamardGate() {
    QuantumGate gate;
    const double inv_sqrt2 = 1.0 / std::sqrt(2.0);
    gate.matrix = {{{inv_sqrt2, inv_sqrt2}, {inv_sqrt2, -inv_sqrt2}}};
    return gate;
}

QuantumGate CNOTGate() {
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, 1}}};
    return gate;
}

QuantumGate OracleGate() {
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, -1}}};
    return gate;
}

QuantumGate DiffusionGate() {
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, 1}}};
    return gate;
}

QuantumGate ModExpGate(int a, int N) {
    (void)a;
    (void)N;
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, 1}}};
    return gate;
}

QuantumGate RGate(double theta) {
    QuantumGate gate;
    gate.matrix = {{{1, 0}, {0, std::exp(std::complex<double>(0.0, theta))}}};
    return gate;
}
