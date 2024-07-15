#include "quantum_algorithm.h"
#include "quantum_gates.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>

// QuantumAlgorithm constructor
QuantumAlgorithm::QuantumAlgorithm(QuantumState &qs) : qs(qs) {}

// Grover's Algorithm implementation
void QuantumAlgorithm::execute_grover() {
    int n = qs.get_num_qubits();
    int iterations = std::floor(std::sqrt(1 << n));

    // Apply Hadamard to all qubits
    for (int i = 0; i < n; ++i) {
        qs.apply_gate(HadamardGate(), i);
    }

    for (int i = 0; i < iterations; ++i) {
        apply_oracle();
        apply_diffusion();
    }

    std::cout << "Executed Grover's Algorithm" << std::endl;
}

// Apply the Oracle gate for Grover's algorithm
void QuantumAlgorithm::apply_oracle() {
    // This is a simplified example of an oracle
    // A real implementation would depend on the specific problem
    QuantumGate oracle = OracleGate();
    for (int i = 0; i < qs.get_num_qubits(); ++i) {
        qs.apply_gate(oracle, i);
    }
}

// Apply the Diffusion gate for Grover's algorithm
void QuantumAlgorithm::apply_diffusion() {
    int n = qs.get_num_qubits();
    for (int i = 0; i < n; ++i) {
        qs.apply_gate(HadamardGate(), i);
    }

    QuantumGate diffusion = DiffusionGate();
    for (int i = 0; i < n; ++i) {
        qs.apply_gate(diffusion, i);
    }

    for (int i = 0; i < n; ++i) {
        qs.apply_gate(HadamardGate(), i);
    }
}

// Shor's Algorithm implementation
void QuantumAlgorithm::execute_shor(int N) {
    // Step 1: Choose a random number a such that 1 < a < N
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2, N - 1);
    int a = dis(gen);

    // Step 2: Compute gcd(a, N)
    int gcd = std::gcd(a, N);
    if (gcd != 1) {
        std::cout << "Found factors: " << gcd << " and " << N / gcd << std::endl;
        return;
    }

    // Step 3: Quantum period-finding
    int r = find_period(a, N);
    if (r % 2 != 0 || std::pow(a, r / 2) == -1) {
        std::cout << "Failed to find factors, please try again." << std::endl;
        return;
    }

    // Step 4: Compute factors
    int factor1 = std::gcd(static_cast<int>(std::pow(a, r / 2)) - 1, N);
    int factor2 = std::gcd(static_cast<int>(std::pow(a, r / 2)) + 1, N);
    std::cout << "Found factors: " << factor1 << " and " << factor2 << std::endl;
}

// Period-finding subroutine for Shor's algorithm using quantum phase estimation
int QuantumAlgorithm::find_period(int a, int N) {
    int n = qs.get_num_qubits();
    int m = 2 * n;

    QuantumState qs_phase(m);

    // Initialize the first m qubits to |+> state
    for (int i = 0; i < m; ++i) {
        qs_phase.apply_gate(HadamardGate(), i);
    }

    // Apply the controlled-U^2^j gates
    for (int j = 0; j < m; ++j) {
        int power = 1 << j;
        for (int k = 0; k < power; ++k) {
            qs_phase.apply_controlled_gate(ModExpGate(a, N), j, m + k);
        }
    }

    // Apply inverse quantum Fourier transform
    apply_inverse_qft(qs_phase);

    // Measure the first m qubits
    std::vector<int> measurements = qs_phase.measure(m);

    // Classical post-processing to find the period r
    double measured_value = 0;
    for (int i = 0; i < m; ++i) {
        measured_value += measurements[i] * std::pow(2, m - 1 - i);
    }

    double phase = measured_value / std::pow(2, m);
    int r = static_cast<int>(1 / phase);
    return r;
}

// Apply inverse quantum Fourier transform
void QuantumAlgorithm::apply_inverse_qft(QuantumState &qs) {
    int n = qs.get_num_qubits();
    for (int i = n - 1; i >= 0; --i) {
        qs.apply_gate(HadamardGate(), i);
        for (int j = i - 1; j >= 0; --j) {
            qs.apply_controlled_gate(RGate(M_PI / std::pow(2, i - j)), j, i);
        }
    }

    // Swap the qubits
    for (int i = 0; i < n / 2; ++i) {
        qs.swap_qubits(i, n - 1 - i);
    }
}
