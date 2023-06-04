
// Revised

#include <bits/stdc++.h>
using namespace std;

// The time complexity of this solution is exponential, O(2 ^ N), where N is the size of the chessboard.This is because it explores all possible combinations of queen placements on the board.

class Solution
{
public:
    bool isSafe1(int row, int col, vector<string> &board, int n)
    {
        int cRow = row;
        int cCol = col;

        // diagonal left
        while (row >= 0 and col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // piche
        row = cRow;
        col = cCol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // diagonal niche
        row = cRow;
        col = cCol;
        while (row < n and col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    void helper(int col, vector<vector<string>> &ans, int n, vector<string> &board)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe1(row, col, board, n))
            {
                board[row][col] = 'Q';
                helper(col + 1, ans, n, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {

            board[i] = s;
        }

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<board[i].size();j++)
        //     {
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        helper(0, ans, n, board);
        return ans;
    }
};

// Optimized using hashing
//  row , upparRow, lowerDiagonal
class Solution
{
public:
    // https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14&ab_channel=takeUforward
    void helper(int col, vector<vector<string>> &ans, vector<string> &board, int n, vector<int> &left, vector<int> &upparDiagonal, vector<int> &lowerDiagonal)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (left[row] == 0 and lowerDiagonal[row + col] == 0 and upparDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                left[row] = 1;
                lowerDiagonal[row + col] = 1;
                upparDiagonal[n - 1 + col - row] = 1;
                helper(col + 1, ans, board, n, left, upparDiagonal, lowerDiagonal);
                board[row][col] = '.';
                left[row] = 0;
                lowerDiagonal[row + col] = 0;
                upparDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {

        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<board[i].size();j++)
        //     {
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout << endl;
        vector<int> left(n, 0), upparDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1);
        helper(0, ans, board, n, left, upparDiagonal, lowerDiagonal);
        return ans;
    }
};

int32_t main()
{

    return 0;
}