#include "quantum_state.h"
#include <cmath>
#include <iostream>
#include <random>
#include <utility>

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

void QuantumState::apply_controlled_gate(const QuantumGate &gate, int control_qubit, int target_qubit) {
    int dim = 1 << num_qubits;
    for (int i = 0; i < dim; ++i) {
        bool control_on = (i & (1 << control_qubit)) != 0;
        bool target_off = (i & (1 << target_qubit)) == 0;
        if (control_on && target_off) {
            int j = i | (1 << target_qubit);
            auto temp = state_vector[i];
            state_vector[i] = gate.apply(state_vector[i], 0);
            state_vector[j] = gate.apply(temp, 1);
        }
    }
}

int QuantumState::get_num_qubits() const {
    return num_qubits;
}

const std::vector<std::complex<double>> &QuantumState::get_state_vector() const {
    return state_vector;
}

std::vector<int> QuantumState::measure(int num_measurements) const {
    std::vector<double> probabilities;
    probabilities.reserve(state_vector.size());
    for (const auto &amplitude : state_vector) {
        probabilities.push_back(std::norm(amplitude));
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> dist(probabilities.begin(), probabilities.end());
    int outcome = dist(gen);

    std::vector<int> bits;
    bits.reserve(num_measurements);
    for (int i = num_measurements - 1; i >= 0; --i) {
        bits.push_back((outcome >> i) & 1);
    }
    return bits;
}

void QuantumState::swap_qubits(int qubit1, int qubit2) {
    if (qubit1 == qubit2) {
        return;
    }
    int dim = 1 << num_qubits;
    for (int i = 0; i < dim; ++i) {
        int bit1 = (i >> qubit1) & 1;
        int bit2 = (i >> qubit2) & 1;
        if (bit1 != bit2) {
            int j = i ^ ((1 << qubit1) | (1 << qubit2));
            if (i < j) {
                std::swap(state_vector[i], state_vector[j]);
            }
        }
    }
}
