# Algorithmic-Combinatorics-Permutation-Library
## Quick Start
```bash
git clone ...
cd ...
make test
make examples
```

## **Features**

### Module 1: Recursive Algorithms

* Classic backtracking permutation generation
* In-place recursive swap algorithm
* Lexicographic recursive permutations
* Permutations with constraints (constraint satisfaction)
* Multiset permutations (with repeated elements)
  _______

### **Module 2: Iterative Algorithms**

* Narayana next_permutation algorithm
* Reverse (prev_permutation) generation
* Factorial number system (permutation by index)
* Inversion table based generation
* Incremental (“plus-one”) permutation generation
   _______

### **Module 3: Optimized Algorithms**

* Johnson–Trotter algorithm (minimal changes)
* Heap’s algorithm (minimal swaps)
* Minimal-change (Gray code–like) permutations
* Cycle leader algorithm
* Bitmask-based generation (for small n)
   _______

### **Module 4: Infrastructure**

* Unified API for all algorithms
* Iterator-based interface
* Automatic algorithm selection
* Built-in benchmarks
* Unit tests and correctness verification
* Optional step-by-step visualization
   _______
## Build  
```bush
make test          
make examples      
make clean
```       

## If you need to run the tests for a single student separately  (for example, for the first student)
```bush
make TestProgram1
./TestProgram1
```
## If you need to run the examples for a single student separately (for example, for the first student)
```bush
make ExamplesProgram1
./ExamplesProgram1
```

## Requirements
* C11 compatible compiler GCC
* Make
* Linux with command line
