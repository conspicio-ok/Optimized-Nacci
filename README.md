# Optimized Nacci

Computes any term of the Fibonacci, Tribonacci, or n-bonacci sequence in **O(log n)** using matrix exponentiation.

## Algorithm

A n-bonacci sequence is defined by its companion matrix of size n×n. Computing the k-th term reduces to raising that matrix to the power k, which is done via fast exponentiation (square-and-multiply): O(log k) matrix multiplications instead of O(k) additions.

This generalizes: degree 2 = Fibonacci, degree 3 = Tribonacci, degree n = n-bonacci.

## Usage

```
./nacci <index> <degree> <show_all>
```

| Argument | Description |
|---|---|
| `index` | Which term to compute (0-indexed) |
| `degree` | Degree of the sequence (2 = Fibonacci, 3 = Tribonacci, ...) |
| `show_all` | 1 = print all terms up to index, 0 = print only the term at index |

### Examples

```sh
./nacci 10 2 0     # 10th Fibonacci term → 55
./nacci 10 2 1     # Fibonacci sequence up to index 10 → [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 ]
./nacci 10 3 0     # 10th Tribonacci term
```

## Files

| File | Description |
|---|---|
| `main.c` | Argument parsing and output |
| `nacci.c` | Matrix initialization and nacci entry point |
| `matrix.c` | Matrix library (create, multiply, power, free) |
| `clib.h` | Shared types and function declarations |

## Build

```sh
gcc main.c nacci.c matrix.c -o nacci
```
