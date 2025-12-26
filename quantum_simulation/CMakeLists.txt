add_library(qcsf_core
    quantum_state.cpp
    quantum_gates.cpp
    quantum_algorithm.cpp
)

target_include_directories(qcsf_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(qcsf_core PUBLIC cxx_std_17)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE qcsf_core)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/quantum_simulation
)
