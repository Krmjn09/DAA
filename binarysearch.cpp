#include <iostream>
using namespace std;
int binary_search(int arr[], int n, int low, int high)
{
    int mid = (low + high) / 2;
    if (arr[mid] == n)
    {
        return mid + 1;
    }
    if (n > arr[mid])
    {
        return binary_search(arr, n, mid + 1, high);
    }
    if (n < arr[mid])
    {

        return binary_search(arr, n, low, mid - 1);
    }
}
int main()
{
    int arr[10], k;
    cout << "enter aray elements";
    int i;
    for (i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = 9;
    cout << "enter the element you want to search";
    cin >> k;
    int r = binary_search(arr, k, low, high);
    cout << "element is found at " << r;
}
