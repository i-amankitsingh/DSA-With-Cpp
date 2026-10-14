#include <iostream>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    int i = st;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + st] = temp[i];
    }
    cout << endl;
}
void devide(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        devide(arr, start, mid);
        devide(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
vector<int> sortArray(vector<int> &nums)
{
    devide(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> arr = {5, 2, 3, 1};
    sortArray(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}