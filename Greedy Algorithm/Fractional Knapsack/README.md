# Fractional Knapsack

The fractional knapsack is a variant of the knapsack problem where items can be divided into fractions. Given a set of items, each with a weight and a value, and a knapsack with a maximum weight capacity, the goal is to fill the knapsack with items that maximize the total value.

In the fractional knapsack, we can take fractions of items, i.e., we can take a part of an item that can fit into the knapsack, and leave the remaining part. This is in contrast to the 0-1 knapsack problem, where we can either take an item or leave it entirely.

## Different Tpyes of Fractional Knapsack:

There are different variations of fractional knapsack, depending on the objective of the problem. Some of them are:

- **Maximize the value:** In this variation, the goal is to fill the knapsack with items that have the highest value, regardless of their weight.

- **Minimize the weight:** In this variation, the goal is to fill the knapsack with items that have the lowest weight, regardless of their value.

- **Maximize the ratio of value and weight:** In this variation, the goal is to fill the knapsack with items that have the highest ratio of value to weight.

## Algorithm

The algorithm starts by calculating the value-to-weight ratio for each item. It then sorts the items in decreasing order of their ratio, and iteratively adds items to the knapsack until it is full. At each iteration, the algorithm adds as much of the most valuable item as possible, and if it cannot add the entire item, it adds a fractional part of it. Once the knapsack is full or all items have been considered, the algorithm returns the contents of the knapsack and their total value.

Here is the **pseudocode** for the algorithm:

```less
Algorithm FractionalKnapsack(items, Capacity)
    for item in items:
        item.ratio = item.value/item.weight
    
    sorted_items = sort(items in descending order of thier ratio)

    Total_Value = 0
    Total_Weight = 0
    knapsack = []

    for item in sorted_items:
        if Total_Weight + item.weight <= Capacity:
            knapsack.append(item)
            Total_Value += item.value
            Total_Weight += item.weight

        else:
            Remaining_Weight = Capacity - Total_Weight

            Fraction = Remaining_Weight/item.weight
            item_Fraction = Item(item.value * Fraction, item.weight * Fraction)
            knapsack.append(item_Fraction)

            Total_Value += item.ratio * Remaining_Weight
            break
    
    return knapsack, Total_Value
```

An **alternative pseudocode** for the algorithm:

```less
1. Sort items by value-to-weight ratio in descending order.
2. Initialize Total_Value = 0.
3. For i = 1 to n
    - If weight of item i is greater than the remaining capacity of the knapsack, add a fraction of item i to the knapsack.
    - Else, add the entire item i to the knapsack.
    - Update the Total_Value & Remaining_Weight of the knapsack.
4. Return the Total_Value of the knapsack.
```

## Use Cases
Fractional knapsack has various use cases in different domains. Here are some examples:

- **Resource Allocation:** Suppose a company has a limited budget to invest in different projects, where each project has a cost and a return on investment. The company can use the fractional knapsack algorithm to determine the optimal combination of projects to invest in to maximize the overall return on investment while staying within the budget.

- **Cutting Stock Problem:** The cutting stock problem is a manufacturing optimization problem where a set of raw materials of different sizes are cut into smaller pieces to produce a specific number of products. The fractional knapsack algorithm can be used to determine the optimal way to cut the raw materials to minimize the waste and maximize the profit.

- **Packing Luggage:** When packing luggage for travel, we often have a limited weight capacity and a set of items to pack, where each item has a weight and a value. The fractional knapsack algorithm can be used to determine the optimal way to pack the items to maximize the value while staying within the weight limit.

## Proof Of Correctness

The correctness of Fractional Knapsack can be proved using the following steps:

- **Initialization**
    - S Sort the items by their value-to-weight ratio in decreasing order. Let V[i] and W[i] denote the value and weight of the ith item, respectively.
- **Maintenance**
    - Consider each item in order of the sorted list. If the weight of the item is less than or equal to the remaining capacity of the knapsack, add the entire item to the knapsack and subtract its weight from the remaining capacity. Otherwise, add a fraction of the item to the knapsack that fits within the remaining capacity, and update the remaining capacity to zero.
- **Termination**
    - When all items have been considered, return the total value of the items in the knapsack.
    
## Complexity

Fractional Knapsack has the following complexity characteristics:    

- **Time Complexity**
    - Best Case: $\ O(n) $, when the array is already sorted in descending order by the value-to-weight ratio.
    - Average Case: $\ O(nlog(n)) $, when the items are randomly ordered.
    - Worst Case: $\ O(nlog(n)) $,when the array is sorted in ascending order by the value-to-weight ratio.

- **Space Complexity:** $\ O(n) $, as it requires an array to store the items and their properties.

- **Stability:** Fractional Knapsack is an unstable algorithm, as the sorting of items can change the order of items with the same value-to-weight ratio. However, it does not affect the optimal solution as long as the items are chosen based on the ratio and not their original order.

## Conclusion

The fractional knapsack problem is a useful optimization problem with many practical use cases in different domains. The variations in objective allow us to tailor the problem to specific scenarios and find optimal solutions.