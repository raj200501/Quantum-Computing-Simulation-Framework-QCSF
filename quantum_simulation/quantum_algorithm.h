#ifndef QUANTUM_ALGORITHM_H
#define QUANTUM_ALGORITHM_H

#include "quantum_state.h"

class QuantumAlgorithm {
public:
    QuantumAlgorithm(QuantumState &qs);

    void execute_grover();
    void execute_shor(int N);

private:
    QuantumState &qs;

    void apply_oracle();
    void apply_diffusion();
    int find_period(int a, int N);
    void apply_inverse_qft(QuantumState &qs);
};

#endif // QUANTUM_ALGORITHM_H
