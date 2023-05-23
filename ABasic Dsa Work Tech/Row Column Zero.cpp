
// Given a matrix, if any of the cells in the matrix is 0, set all the elements in its row and column to 0.

#include <bits/stdc++.h>
using namespace std;

void setRowColumnZeroes(vector<vector<int>> &mat)
{

    int row = mat.size();
    int col = mat[0].size();
    vector<bool> v1(row, 1);
    vector<bool> v2(col, 1);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                v1[i] = 0;
                v2[j] = 0;
            }
        }
    }

    // 	for(int i=0;i<v1.size();i++)
    // 	{
    // 		cout<<v1[i]<< " ";
    // 	}

    // 	cout<<endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (v1[i] == 0 || v2[j] == 0)
            {
                mat[i][j] = 0;
            }
        }
    }

    // return mat;
}