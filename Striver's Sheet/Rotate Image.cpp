
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // #SS
    // Transpose of a given matrix
    // Transpose mai columns row banenge and vice versa
    //  1 2 3         1 4 7
    //  4 5 6  -->    2 5 8
    //  7 8 9         3 6 9
    // abhi bas reverse karo  all rows
    // Transpose and reverse bas 90 degree hogya

    void rotate(vector<vector<int>> &mat)
    {

        int row = mat.size();
        int col = mat[0].size();

        // transpose just swap (i,j) with (j,i)

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for (int i = 0; i < row; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};
