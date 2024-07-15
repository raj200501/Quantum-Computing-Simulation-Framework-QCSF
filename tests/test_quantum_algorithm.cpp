#include "quantum_state.h"
#include "quantum_algorithm.h"
#include <cassert>

void test_quantum_algorithm() {
    QuantumState qs(3);
    QuantumAlgorithm qa(qs);
    qa.execute_grover();

    assert(qs.get_state_vector().size() == (1 << 3));
    qs.print_state();
}

int main() {
    test_quantum_algorithm();
    return 0;
}
