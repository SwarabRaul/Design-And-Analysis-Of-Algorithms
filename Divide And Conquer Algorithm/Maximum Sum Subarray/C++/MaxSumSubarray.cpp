#include <iostream>
#include <climits>

using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid + 1, high);
    int crossingSum = maxCrossingSum(arr, low, mid, high);

    return max(max(leftSum, rightSum), crossingSum);
}

int main()
{
    int n;
    cout << "Enter the Size of Array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of Array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubarraySum(arr, 0, size - 1);

    cout << "Maximum sum of subarray: " << maxSum << endl;

    return 0;
}
