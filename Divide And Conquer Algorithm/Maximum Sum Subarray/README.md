# Maximum Sum Subarray

The maximum sum subarray problem is a classic algorithmic problem that involves finding a contiguous subarray within a one-dimensional array of numbers that has the largest possible sum. This problem is also known as the maximum subarray problem.

## Problem Statement

Given an array of integers, we want to find the subarray with the maximum sum. More formally, we want to find the indices start and end such that the sum of elements from start to end (inclusive) is maximized.

## Algorithm

The algorithm for finding the maximum sum subarray can be solved using Kadane's algorithm.

Here is the **pseudocode** for the algorithm:

```less
function maxCrossingSum(arr, low, mid, high):
    leftSum = -infinity
    sum = 0
    for i = mid downto low:
        sum = sum + arr[i]
        if sum > leftSum:
            leftSum = sum
    rightSum = -infinity
    sum = 0
    for i = mid + 1 to high:
        sum = sum + arr[i]
        if sum > rightSum:
            rightSum = sum
    return leftSum + rightSum

function maxSubarraySum(arr, low, high):
    if low = high:
        return arr[low]
    mid = (low + high) / 2
    leftSum = maxSubarraySum(arr, low, mid)
    rightSum = maxSubarraySum(arr, mid + 1, high)
    crossingSum = maxCrossingSum(arr, low, mid, high)
    return max(leftSum, rightSum, crossingSum)
```

## Use Cases

The maximum sum subarray problem has various use cases in different domains. Here are some examples:

- **Financial Analysis:** The maximum sum subarray algorithm can be used to analyze financial data, such as stock prices or sales figures, to identify periods of maximum growth or decline.

- **Data Mining:** In data mining applications, the maximum sum subarray algorithm can be used to find patterns or anomalies in large datasets, where the subarray with the maximum sum represents significant trends or outliers.

- **Image Processing:** The maximum sum subarray algorithm can be applied to image processing tasks, such as edge detection or feature extraction, where it helps identify regions of interest based on the maximum sum of pixel values.

## Proof Of Correctness

To prove the correctness of the maximum sum subarray algorithm, we can use the following steps:

- **Initialization**
    - At the start of each recursive call of maxSubarraySum, we have the base case when low is equal to high. In this case, there is only one element in the subarray, and the maximum sum subarray is simply that element. Therefore, the base case is correct.
    - For the recursive case, the initial values of leftSum and rightSum are set to negative infinity to allow any positive sum encountered in the loop to be greater than the initial values.

- **Maintenance**
    -  The algorithm finds the maximum sum subarray by recursively dividing the array into two halves, finding the maximum sum subarrays of the left and right halves, and then finding the maximum sum subarray that crosses the midpoint. The correct maximum sum subarray will be the maximum of these three values.
    - For the recursive case, the initial values of leftSum and rightSum are set to negative infinity to allow any positive sum encountered in the loop to be greater than the initial values.

- **Termination**
    - The algorithm terminates when the base case is reached, which occurs when low is equal to high. In this case, the algorithm returns the single element as the maximum sum subarray.
    - The recursive calls are made on smaller subarrays, ensuring that the problem size reduces with each recursion. Eventually, the problem size will reach the base case, and the recursion will terminate.

Therefore, the pseudocode correctly finds the maximum sum subarray using the divide and conquer approach.
    
## Complexity

Maximum Sum Subarray has the following complexity characteristics:    

- **Time Complexity**
    - Best Case: $\ O(nlogn) $, occurs when the maximum sum subarray is located in either the left or right half of the array, resulting in a balanced split at each recursion level.
    - Average Case: $\ O(nlogn) $, assumes a random distribution of the maximum sum subarray within the array.
    - Worst Case: $\ O(nlogn) $,occurs when the maximum sum subarray crosses the midpoint of the array at each recursion level, resulting in the need to calculate the crossing sum for every split.

The divide and conquer approach has a better time complexity than the brute-force approach, which has a time complexity of $\ O(n^2) $. The divide and conquer approach has a logarithmic factor due to the recursive splitting of the array, resulting in a more efficient algorithm.

- **Space Complexity:** $\ O(log(n)) $, During the recursive calls, additional space is required for the function call stack to store the intermediate values and return addresses. The maximum depth of the recursion is log n, as the array size is halved at each recursive step.

- **Stability:** The algorithm preserves the relative order of elements in the input array.

## Conclusion

The maximum sum subarray algorithm provides an efficient solution for finding the subarray with the maximum sum within an array. It has a linear time complexity in all cases, making it suitable for large arrays. The algorithm requires only a constant amount of additional space, making it space-efficient. Additionally, it preserves the relative order of elements in the input array, ensuring stability. The maximum sum subarray algorithm is a valuable tool for various applications, including financial analysis, data mining, and image processing, where identifying the subarray with the maximum sum is crucial.