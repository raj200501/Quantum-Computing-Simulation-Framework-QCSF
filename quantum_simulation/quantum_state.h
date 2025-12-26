#ifndef QUANTUM_STATE_H
#define QUANTUM_STATE_H

#include <vector>
#include <complex>
#include "quantum_gates.h"

class QuantumState {
public:
    QuantumState(int num_qubits);

    void apply_gate(const QuantumGate &gate, int qubit);
    void apply_gate(const QuantumGate &gate, int control_qubit, int target_qubit);
    void apply_controlled_gate(const QuantumGate &gate, int control_qubit, int target_qubit);

    void print_state() const;
    int get_num_qubits() const;
    const std::vector<std::complex<double>> &get_state_vector() const;
    std::vector<int> measure(int num_measurements) const;
    void swap_qubits(int qubit1, int qubit2);

private:
    int num_qubits;
    std::vector<std::complex<double>> state_vector;
};

#endif // QUANTUM_STATE_H
