#include "quantum_state.h"
#include <cmath>
#include <iostream>

QuantumState::QuantumState(int num_qubits) : num_qubits(num_qubits) {
    int dim = 1 << num_qubits;
    state_vector.resize(dim, {0, 0});
    state_vector[0] = {1, 0}; // Initialize the state to |0>
}

void QuantumState::apply_gate(const QuantumGate &gate, int qubit) {
    // Implementation of applying a single-qubit gate to the quantum state
    int dim = 1 << num_qubits;
    for (int i = 0; i < dim; ++i) {
        if ((i & (1 << qubit)) == 0) {
            int j = i | (1 << qubit);
            auto temp = state_vector[i];
            state_vector[i] = gate.apply(state_vector[i], 0);
            state_vector[j] = gate.apply(temp, 1);
        }
    }
}

void QuantumState::apply_gate(const QuantumGate &gate, int control_qubit, int target_qubit) {
    // Implementation of applying a two-qubit gate to the quantum state
    int dim = 1 << num_qubits;
    for (int i = 0; i < dim; ++i) {
        if ((i & (1 << control_qubit)) && !(i & (1 << target_qubit))) {
            int j = i | (1 << target_qubit);
            auto temp = state_vector[i];
            state_vector[i] = gate.apply(state_vector[i], 0);
            state_vector[j] = gate.apply(temp, 1);
        }
    }
}

void QuantumState::print_state() const {
    for (const auto &amplitude : state_vector) {
        std::cout << amplitude << " ";
    }
    std::cout << std::endl;
}
