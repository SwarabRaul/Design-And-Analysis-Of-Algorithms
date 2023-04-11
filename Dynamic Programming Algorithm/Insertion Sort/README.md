# Insertion Sort

Insertion Sort is a simple sorting algorithm that works by comparing each element with the elements before it and inserting it into its correct position in the sorted portion of the array.

## Algorithm

The algorithm starts with the second element of the array and iterates through each subsequent element, comparing it to the elements before it and shifting them to the right until it finds the correct position for the current element. It continues this process until it has sorted the entire array.

Here is the **pseudocode** for the algorithm:

```less
Algorithm InsertionSort(A: List of Sortable Elements)
    n = lenght(A)
    for i = 1 to n - 1
        j = i
        while j >= 0 & A[j - 1] > A[j]
            swap A[j] & A[j - 1]
            j = j - 1
    end for
end Algorithm
```

## Use Cases
Insertion Sort is useful when you need to sort a small number of elements or when the array is almost sorted. It has a simple implementation and requires minimal additional memory, making it useful in situations where memory is limited. However, it's worst-case time complexity is $\ O(n^2) $, which makes it less efficient than other sorting algorithms for larger arrays.

## Proof Of Correctness

The correctness of Insertion Sort can be proved using the following steps:

- **Initialization**
    - The first element of the array is considered as the sorted portion of the array.
- **Maintenance**
    - For each iteration, the next element of the unsorted portion is compared with the elements in the sorted portion of the array and inserted into its correct position, maintaining the sorted property of the array.
- **Termination**
    - Once all elements have been iterated through and inserted into their correct positions, the array is fully sorted, and the algorithm is terminated.
    
## Complexity

Insertion Sort has the following complexity characteristics:    

- **Time Complexity**
    - Best Case: $\ O(n) $, when the array is already sorted.
    - Average Case: $\ O(n^2) $, when the elements are randomly ordered.
    - Worst Case: $\ O(n^2) $, when the array is reverse sorted.

- **Space Complexity:** $\ O(1) $, as it only requires a constant amount of additional memory.

- **Stability:** Insertion Sort is a stable sorting algorithm, meaning that it maintains the relative order of equal elements in the sorted array.

## Conclusion

Insertion Sort is a simple, stable, and efficient algorithm for sorting small arrays or almost sorted arrays. However, for larger arrays, it is less efficient than other sorting algorithms with better time complexity, such as Quick Sort or Merge Sort.