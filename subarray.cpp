#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxcrossingSum(vector<int> &arr, int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
        }
    }
    int rightSum = INT_MIN;
    int sum = 0;
    for (int i = mid + 1; i <= high; i--)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}
int maxsubarray(vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftMax = maxsubarray(arr, low, mid);
    int rightMax = maxsubarray(arr, mid + 1, high);
    int crossMax = maxcrossingSum(arr, low, mid, high);

    return max(leftMax, rightMax, crossMax);
}
int main()
{
    vector<int> arr = {23, 56, 2, 78, 24, 12, 90};
    int n = arr.size();
    int r = maxsubarray(arr, 0, n - 1);
    cout << r;
    return 0;
}