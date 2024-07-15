#include <iostream>
#include "quantum_state.h"
#include "quantum_algorithm.h"

int main() {
    QuantumState qs(3); // Initialize a 3-qubit quantum state
    qs.apply_gate(HadamardGate(), 0); // Apply Hadamard gate to the first qubit
    qs.apply_gate(CNOTGate(), 1, 2); // Apply CNOT gate with control qubit 1 and target qubit 2

    QuantumAlgorithm qa(qs);
    qa.execute_grover();

    std::cout << "Quantum State after applying gates and executing Grover's algorithm:" << std::endl;
    qs.print_state();

    return 0;
}
