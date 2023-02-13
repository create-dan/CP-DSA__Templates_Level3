//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    
    
    bool isValid(int i , int j , int row , int col)
    {
        return (i>=0 and i<row and j>=0 and j<col);
    }
    
    void dfs(int i , int j , vector<vector<char>> &grid , vector<vector<bool>> &visited)
    {
        int row = grid.size();
        int col = grid[0].size();
        if(i>=row and col>=j) return ;
        
        visited[i][j]=true;
        
        int ax[4]={1,0,-1,0};
        int ay[4]={0,1,0,-1};
        
        for(int k=0;k<4;k++)
        {
            int nx = i+ax[k];
            int ny = j+ay[k];
            if(isValid(nx,ny,row,col) and !visited[nx][ny] and grid[nx][ny]=='X'){
                dfs(nx,ny,grid,visited);
            }
        }
    }
    
    
    int xShape(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        int cnt =0;
        
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] =='X' and !visited[i][j]){
                    cnt++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        
        
        
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends
