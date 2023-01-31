//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    //#LOVE BABBAR
    //https://www.youtube.com/watch?v=CiDPT1xMKI0&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=14&ab_channel=CodeHelp-byBabbar
    //discovery array--> kis type pai pahuche
    //low --> earlisest possible time
    //dekho kya earliest time(low) update ho sakta hai kya
    //low[node ] = min(low[node],disc[neighbour])
    //if(neighbour==parent) ignore karo
    //if(low[neighbour]) bada hai disc[node] to bridge present hai
    //back edge


 
    void dfs(int node , vector<bool> & visited, int &timer , vector<int> &disc, vector<int> &low, vector<int> adj[], int c ,int d , bool &flag, int parent)
    {
        visited[node]=true;
        disc[node]=low[node]=timer++;
        
        for(auto nbr : adj[node])
        {
            if(nbr!=parent) 
            {
                if(!visited[nbr])
                {
                    dfs(nbr,visited,timer,disc,low,adj,c,d,flag,node);
                    low[node] = min(low[node],low[nbr]);
                    
                    //check edge is bridge
                    if(low[nbr] > disc[node])
                    {
                        if(c==nbr and d==node) {flag=true;break;}
                        if(d==nbr and c==node) {flag=true;break;}
                    }
                }
                else
                {
                    //visited bhi nahi hai and parent bhi nahi hai to back edge
                    low[node] = min(low[node],disc[nbr]);
                }
            }
            
        }
        
        
        
        
        
    }
    
    
    
    
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        int timer=0;
        vector<int> disc(v,-1);
        vector<int> low(v,-1);
        vector<bool> visited(v,false);
        
        //dfs
        bool flag = false;
        int parent=-1;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            dfs(i,visited,timer,disc,low,adj,c,d,flag,parent);
        }
        
        return flag;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends
