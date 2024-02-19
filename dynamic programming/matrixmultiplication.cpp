#include <iostream>
#include <climits>
using namespace std;
int matrix_mul(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int mini = INT_MAX;
    int k, count;
    for (k = i; k < j; k++)
    {
        count = matrix_mul(p, i, k) + matrix_mul(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        mini = min(mini, count);
    }
    return mini;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int r = matrix_mul(arr, 1, size - 1);
    cout << r;
    return 0;
}