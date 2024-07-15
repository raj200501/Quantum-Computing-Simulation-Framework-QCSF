#include "quantum_state.h"
#include "quantum_gates.h"
#include <cassert>

void test_quantum_state() {
    QuantumState qs(3);
    qs.apply_gate(HadamardGate(), 0);
    qs.apply_gate(CNOTGate(), 1, 2);

    assert(qs.get_state_vector().size() == (1 << 3));
    qs.print_state();
}

int main() {
    test_quantum_state();
    return 0;
}
