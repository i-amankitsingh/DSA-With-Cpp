// Flood Fill Algorithm Problem (LeetCode 733)

#include <iostream>
#include <list>
using namespace std;

class Solution
{
public:
    void floodFillHelper(vector<vector<int>> &image, int sr, int sc, int color, vector<vector<bool>> &vis)
    {
        cout<<sr<<" "<<sc<<" "<<endl;
        if ( sr >= image.size() || sc >= image[0].size() || sr < 0 || sc < 0 || image[sr][sc] == 0 || vis[sr][sc])
        {
            return;
        }
        cout<<"Start... "<<endl;
        vis[sr][sc] = true;
        cout<<image[sr][sc]<<" "<<endl;
        if (image[sr][sc] == 1)
        {
            cout<<"Hello"<<endl;
            image[sr][sc] = 2;
        }
        floodFillHelper(image, sr, sc - 1, color, vis); // left
        floodFillHelper(image, sr - 1, sc, color, vis); // top
        floodFillHelper(image, sr, sc + 1, color, vis); // right
        floodFillHelper(image, sr + 1, sc, color, vis); // bottom
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        floodFillHelper(image, sr, sc, color, vis);
        return image;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    vector<vector<int>> ans = sol.floodFill(image, 1, 1, 1);

    for(int i=0; i<image.size(); i++){
        for(int j=0; j<image[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}