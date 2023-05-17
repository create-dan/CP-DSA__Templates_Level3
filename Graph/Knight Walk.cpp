//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    //bfs
    //knight ki position pakdo and sare adjancent(valid) check karo
    //1 based indexing so -1,-1 kar do 
    //pos ko queue mai push kar do
    //ab 8 positions dekho
    
    
    bool isValid(int x ,int y , int n)
    {
        return (x>=0 and x<n and y>=0 and y<n);
    }


	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    
	    
	    //target position yaha jana hai
	    int tx=TargetPos[0]-1,ty=TargetPos[1]-1;
	    
	    //knight ki position
	    int x1 = KnightPos[0]-1 , y1 = KnightPos[1]-1;
	    
	    if(tx==x1 and ty==y1) return 0;
	    
	    //jitni bar bfs return it
	    int ans =0;
	    
	    //take queue
	    queue<pair<int,int>> q;
	    q.push({x1,y1});
	    
	    
	    vector<vector<bool>> visited(n,vector<bool>(n,false));
	    
	    visited[x1][y1]= true;
	    
	    
	    
	    //do bfs
	    while(!q.empty())
	    {
	        ans++;
	        int sz = q.size();
	        while(sz--){
	        
	        
	        pair<int,int> p = q.front();
	        q.pop();
	        int xx1 = p.first; 
	        int yy1 = p.second;
	        
	        
	        
	        int ax[8] ={1,1,-1,-1,2,-2,2,-2};
	        int ay[8] ={2,-2,2,-2,1,1,-1,-1};
	        
	        for(int i=0;i<8;i++)
	        {
	            int nx = xx1+ax[i];
	            int ny = yy1+ay[i];
	           
	            
	            if(nx==tx and ny==ty) return ans;
	            
	            if(isValid(nx,ny,n) and !visited[nx][ny]){
	               
	                 visited[nx][ny]= true;
	                 q.push({nx,ny});
	            }
	        }
	       }
	    }
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
