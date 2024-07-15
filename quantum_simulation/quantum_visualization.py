import matplotlib.pyplot as plt
import numpy as np

def plot_quantum_state(state_vector):
    fig, ax = plt.subplots()
    ax.bar(range(len(state_vector)), [abs(amplitude)**2 for amplitude in state_vector])
    ax.set_xlabel('State')
    ax.set_ylabel('Probability')
    ax.set_title('Quantum State Probability Distribution')
    plt.show()

def plot_quantum_circuit(circuit):
    fig, ax = plt.subplots()
    ax.plot(circuit['time'], circuit['state'], marker='o')
    ax.set_xlabel('Time')
    ax.set_ylabel('State')
    ax.set_title('Quantum Circuit Simulation')
    plt.show()

# Example usage
if __name__ == "__main__":
    state_vector = np.array([1/np.sqrt(2), 0, 0, 1/np.sqrt(2)], dtype=complex)
    plot_quantum_state(state_vector)

    circuit = {'time': [0, 1, 2, 3], 'state': [0, 1, 2, 3]}
    plot_quantum_circuit(circuit)
