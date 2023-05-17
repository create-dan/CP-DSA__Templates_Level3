//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
   void dfs(int node , int parent , vector<int> &disc , vector<int> &low, vector<bool> &visited, vector<int> adj[], vector<int> &ans , int &timer)
   {
       visited[node]=true;
       disc[node]=low[node]=timer++;
       int child=0;
       
       for(auto nbr : adj[node])
       {
           if(nbr!=parent)
           {
                if(!visited[nbr])
                {
                    dfs(nbr,node,disc,low,visited,adj,ans,timer);
                    low[node] = min(low[node],low[nbr]);
                    
                    //check articulation point or not
                    if(low[nbr]>=disc[node] and parent!=-1) {
                        ans[node]=1;
                    }
                    child++;
                }
                else{
                    low[node]=min(low[node],disc[nbr]);
                }
           }
       }
       
       
       if(parent==-1 and child>1) ans[node]=1;
   }
  
  
  
    vector<int> articulationPoints(int v, vector<int>adj[]) {
       
       int timer=0;
       vector<int> disc(v,-1);
       vector<int> low(v,-1);
       
       vector<bool> visited(v,false);
       vector<int> ans(v,0);
       
       //dfs
       for(int i=0;i<v;i++)
       {
           if(!visited[i])
           dfs(i,-1,disc,low,visited,adj,ans,timer);
       }
       vector<int> mark;
    //   for(auto i : ans)
    //   {
    //       cout<<i<<" ";
    //   }
    //   cout<<endl;
       for(int i=0;i<v;i++)
       {
           if(ans[i]==1) mark.push_back(i);
       }
       if(mark.size()==0) mark.push_back(-1);
       return mark;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
