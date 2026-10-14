#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve(int i, int j,
               vector<vector<int>> &maze,
               vector<vector<int>> &vis,
               string path,
               vector<string> &ans)
    {
        
    }

    vector<string> findPath(vector<vector<int>> &maze)
    {

        int n = maze.size();

        vector<string> ans;

        if (maze[0][0] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, maze, vis, "", ans);

        return ans;
    }
};

int main()
{

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    Solution obj;

    vector<string> ans = obj.findPath(maze);

    for (string path : ans)
        cout << path << "\n";

    return 0;
}