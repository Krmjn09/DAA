#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> left_arr(n1);
    std::vector<int> right_arr(n2);

    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    int size = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    merge_sort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
