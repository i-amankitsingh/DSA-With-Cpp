// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

bool exist(vector<vector<char>> &board, string word)
{
    int letter = 0;
    int cell = 0;
    int m = board.size();
    int n = board[0].size();
    int len = word.length();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[letter])
            {
                letter++;
                cell++;
            }
            cout << "Letter: " << letter << endl;
        }
    }
    cout << "final letter: " << letter << endl;
    if (letter >= len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    cout << exist(board, word);

    return 0;
}