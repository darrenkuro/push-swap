<h1 align="center">Push Swap</h1>

<p align="center">
  <b>A stack-based sorting algorithm challenge from 42 School</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/score-125%2F100-3CB371?style=flat-square&logo=42&logoColor=white" alt="Score"/>
  <img src="https://img.shields.io/badge/language-C-A8B9CC?style=flat-square&logo=C&logoColor=black" alt="C"/>
  <img src="https://img.shields.io/badge/license-MIT-blue?style=flat-square&logo=opensourceinitiative&logoColor=white" alt="License"/>
</p>

---

## Overview

**Push Swap** is an algorithmic project that challenges you to sort a stack of integers using a limited set of operations, with the goal of achieving the sort in as few moves as possible.

Given two stacks (A and B), you must sort all numbers into stack A in ascending order using only the following operations:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the top element from B to A |
| `pb` | Push the top element from A to B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up (first element becomes last) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

---

## Algorithm

This implementation uses a **greedy algorithm** with **cost optimization**:

1. **Normalization**: Input numbers are converted to their rank indices (0 to n-1) for simplified comparisons

2. **Small Stack Handling**:
   - 2-3 elements: Hardcoded optimal solutions
   - Already sorted: Detected and returned immediately

3. **Main Algorithm** (for 4+ elements):
   - Push elements from A to B, maintaining B in descending order
   - At each step, find the element that requires the **fewest operations** to move
   - Calculate optimal rotation strategy from 4 possible paths:
     - Both stacks rotate forward (`ra` + `rb`)
     - A forward, B backward (`ra` + `rrb`)
     - A backward, B forward (`rra` + `rb`)
     - Both stacks rotate backward (`rra` + `rrb`)
   - After reducing A to 3 elements, sort them and push everything back

4. **Post-Processing Optimization**:
   - Combine consecutive `ra`/`rb` into `rr`
   - Combine consecutive `rra`/`rrb` into `rrr`

---

## Installation

### Prerequisites

- GCC or Clang
- GNU Make
- CMake (optional, for visualizer)

### Build

```bash
# Clone with submodules
git clone --recurse-submodules https://github.com/darrenkuro/push-swap.git
cd push-swap

# Build everything (push_swap, checker, and visualizer)
make

# Or build only the main program
make push_swap

# Or build only the checker (bonus)
make bonus
```

---

## Usage

### Basic Usage

```bash
# Sort a list of numbers
./push_swap 4 67 3 87 23

# Count the number of operations
./push_swap 4 67 3 87 23 | wc -l

# Pass numbers as a single argument (bash only)
ARG="4 67 3 87 23"; ./push_swap $ARG
```

### Verify with Checker

```bash
# Pipe output to checker to verify correctness
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: OK (if sorted correctly) or KO (if not)

# Use the provided platform-specific checkers
./push_swap 4 67 3 87 23 | ./tests/checker_Mac 4 67 3 87 23
```

### Visualizer

The included visualizer (submodule) provides a graphical representation of the sorting process:

```bash
# Build visualizer (included in `make all`)
make visualizer

# Run with visualizer
./push_swap 4 67 3 87 23 | ./visualizer/build/bin/visualizer 4 67 3 87 23
```

---

## Performance

Operation counts for random inputs:

| Input Size | Operations (avg) | Target for Max Score |
|------------|------------------|----------------------|
| 3 | 2-3 | 3 |
| 5 | ~8 | 12 |
| 100 | ~550 | 700 |
| 500 | ~5000 | 5500 |

---

## Project Structure

```
push-swap/
├── include/
│   └── push_swap.h       # Data structures and function declarations
├── src/
│   ├── push_swap.c       # Main entry point
│   ├── checker_bonus.c   # Bonus: operation validator
│   ├── input.c           # Input validation and parsing
│   ├── sort.c            # Sorting algorithms
│   ├── optimize_*.c      # Operation optimization
│   ├── op_exec*.c        # Stack operations (push, swap, rotate)
│   └── utils*.c          # Utility functions
├── libft/                # Custom C library (submodule)
├── visualizer/           # Sorting visualizer (submodule)
├── tests/                # Platform-specific checker binaries
└── Makefile
```

---

## Development

### Updating Submodules

```bash
# Update libft to latest
make libft-update

# Update visualizer to latest
make visualizer-update
```

### Cleaning

```bash
make clean   # Remove object files
make fclean  # Remove objects and executables
make re      # Full rebuild
```

---

## Testing

Recommended testers for validation:

- [push_swap_averager](https://github.com/Vinni-Cedraz/push_swap_averager) - Performance averaging
- [push_swap_tester](https://github.com/laisarena/push_swap_tester) - Comprehensive tests
- [Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester) - Extensive test suite
- [push_swap_leak_tester](https://github.com/IDC87/push_swap_leak_tester) - Memory leak detection

> **Note**: Test in bash where `$ARG` is parsed as multiple arguments. In zsh, it's parsed as a single argument.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Author

**Darren Kuro** - [darren0xa@gmail.com](mailto:darren0xa@gmail.com) - [@darrenkuro](https://github.com/darrenkuro)
