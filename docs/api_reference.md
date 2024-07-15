# QCSF API Reference

## QuantumState

### Methods

- **QuantumState(int num_qubits)**: Initializes a quantum state with the specified number of qubits.
- **void apply_gate(const QuantumGate &gate, int qubit)**: Applies a single-qubit gate to the specified qubit.
- **void apply_gate(const QuantumGate &gate, int control_qubit, int target_qubit)**: Applies a two-qubit gate with the specified control and target qubits.
- **void print_state() const**: Prints the current quantum state.

## QuantumAlgorithm

### Methods

- **QuantumAlgorithm(QuantumState &qs)**: Initializes a quantum algorithm with the specified quantum state.
- **void execute_grover()**: Executes Grover's algorithm on the quantum state.

## QuantumGate

### Functions

- **QuantumGate HadamardGate()**: Returns a Hadamard gate.
- **QuantumGate CNOTGate()**: Returns a CNOT gate.
- **QuantumGate OracleGate()**: Returns an oracle gate.
- **QuantumGate DiffusionGate()**: Returns a diffusion gate.

## Visualization

### Functions

- **void plot_quantum_state(state_vector)**: Plots the probability distribution of the quantum state.
- **void plot_quantum_circuit(circuit)**: Plots the simulation of a quantum circuit.

## Scripts

### deploy.sh

- **Description**: Deploys the Docker containers for the quantum simulation framework.

### run_simulation.sh

- **Description**: Runs the quantum simulation.
