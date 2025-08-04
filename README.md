# Simple Sorting Algorithm Performance Comparison

A clean and simple C program that demonstrates the performance difference between Merge Sort (O(n log n)) and Bubble Sort (O(n²)) algorithms.

## Files

- `main.c` - Simple performance comparison program
- `sorting_comparison_extended.c` - Extended version (simplified)

## Features

- **Random Data Generation**: Creates 5,000 random integers
- **Time Measurement**: Uses `clock()` function for execution timing
- **Clean Output**: Simple, focused results
- **Memory Management**: Proper malloc/free usage

## Algorithm Implementations

### Bubble Sort
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- Simple nested loops with element swapping

### Merge Sort  
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)
- Divide and conquer approach

## Usage

```bash
# Compile
gcc main.c -o sorting_test

# Run
./sorting_test
```

## Expected Output

```
Sorting 5000 elements...
Merge Sort:  0.0024 seconds
Bubble Sort: 0.0584 seconds
Merge Sort is 24.4x faster
```

## Key Takeaway

This simple demonstration shows that Merge Sort is typically 20-30x faster than Bubble Sort for medium-sized datasets, illustrating why O(n log n) algorithms are preferred over O(n²) algorithms for sorting tasks.
