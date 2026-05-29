#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canPaint(vector<int> &boards,
                  int painters,
                  int maxTimeAllowed)
    {
        int n = boards.size();
        int painter = 1;
        int time = 0;
        for (int i = 0; i < n; i++)
        {
            if ((boards[i] + time) <= maxTimeAllowed)
            {
                time += boards[i];
            }
            else
            {
                painter++;
                time = boards[i];
            }
        }
        return painter <= painters;
    }

    int paintersPartition(vector<int> &boards,
                          int painters)
    {
        int n = boards.size();
        int low = *max_element(boards.begin(), boards.end());
        int high = 0;
        for (int i = 0; i < n; i++)
        {
            high += boards[i];
        }
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            bool isPossible = canPaint(boards, painters, mid);
            if (isPossible)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution obj;

    // Test Case 1
    {
        vector<int> boards = {40, 10, 30, 20};
        int painters = 2;

        cout << obj.paintersPartition(
                    boards,
                    painters)
             << endl;
    }

    // Test Case 2
    {
        vector<int> boards = {10, 20, 30, 40};
        int painters = 2;

        cout << obj.paintersPartition(
                    boards,
                    painters)
             << endl;
    }

    // Test Case 3
    {
        vector<int> boards = {5, 10, 15, 20};
        int painters = 3;

        cout << obj.paintersPartition(
                    boards,
                    painters)
             << endl;
    }

    // Test Case 4
    {
        vector<int> boards = {10, 10, 10, 10};
        int painters = 2;

        cout << obj.paintersPartition(
                    boards,
                    painters)
             << endl;
    }

    // Test Case 5
    {
        vector<int> boards = {7, 2, 5, 10, 8};
        int painters = 2;

        cout << obj.paintersPartition(
                    boards,
                    painters)
             << endl;
    }

    return 0;
}