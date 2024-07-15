FROM gcc:latest

WORKDIR /app

COPY quantum_simulation /app/quantum_simulation
COPY config /app/config
COPY data /app/data

RUN apt-get update && apt-get install -y cmake

RUN cd /app/quantum_simulation && cmake . && make

CMD ["./main"]
