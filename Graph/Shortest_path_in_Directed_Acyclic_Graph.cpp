//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  //https://www.youtube.com/watch?v=P_bfy0LOU5g&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=10&ab_channel=CodeHelp-byBabbar
  //Topologial sort nikalo
  //dist array with INT_MAX
  //traverse stack and save top
  //if top ka distance is not INT_MAX to traverse karo adj[top]
  //update the dist of it.first to min(it.first ka pahla dist , dist[top] + it.second)
  
  
  void dfs(int src , vector<bool> &visited , stack<int> &st, vector<pair<int,int>> adj[] )
  {
      visited[src]=true;
      for(auto i : adj[src])
      {
          if(!visited[i.first])
          dfs(i.first,visited,st,adj);
      }
      
      st.push(src);
  }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
         vector<pair<int,int>> adj[N];
         for(auto i : edges)
         {
             int u = i[0];
             int v = i[1];
             int w=i[2];
             adj[u].push_back({v,w});
         }
         
        
        //Topological Sort
       
      stack<int> st;
      vector<bool> visited(N,false);
      for(int i=0;i<N;i++)
      {
          if(!visited[i])
          dfs(i,visited,st,adj);
      }
      
      //Topo sort aagaya
      
      
      //create a distance array
      //initialize it with INT_MAX
      
      
    //   while(!st.empty())
    //   {
    //       cout<<st.top()<<" ";
    //       st.pop();
    //   }
    //   cout<<endl;
      
      
      vector<int> dist(N,INT_MAX);
      
      int src=0;
      dist[src]=0;
      
      while(!st.empty())
      {
          int top = st.top();
          st.pop(); 
          
          for(auto it : adj[top])
          {
              if(dist[top] != INT_MAX)
              {
                  int node = it.first;
                  int nDist = it.second;
                  dist[node]=min(dist[node],dist[top]+nDist);
              }
          }
      }
      
      
      for(int i=0;i<N;i++)
      {
          if(dist[i]==INT_MAX)
          dist[i]=-1;
      }
      
      
      
      return dist;
      
      
      
      
      
      
      
      
      
      
       
       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
