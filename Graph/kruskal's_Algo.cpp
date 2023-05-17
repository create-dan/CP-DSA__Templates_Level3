//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//#LOVE BABBAR
	//https://www.youtube.com/watch?v=rnYBi9N_vw4&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=12&t=1s&ab_channel=CodeHelp-byBabbar
	
	
	//Prim's Algo
	//3 Arrays - key , mst , parent
	//src node ko 0 man lenge baki sari infinity
	//starting mai koi bhi node mst ke andar nahi hai to mst = false for all
	//sabka parent -1
	//key[0]=0 and parent[0]-1
	//now key array mai javo and minimum value nikalo (0th) and mark mst[0]=true
	//ab 0 ke sare adjancet dekho
	//and agar waha badi value padi hai to update (key[i])
	//parent[i]=u
	//abhi mst false honi chahiye and key value < minimum
	
	
	
	//Kruskal's Algorithms
	//disjoint set
	//find parent and union set
	//union by rank and path compression
	
	
	
	int parent[1005];
	
	int find(int v)
	{
	    if(v==parent[v]) return v;
	    return parent[v] = find(parent[v]);
	}
	
	void Union(int a, int b)
	{
	  parent[b]=a;
	}
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<V;i++)
        {
            int u = i;
           parent[i]=i;
            for(auto j : adj[i]){
                
               int  w = j[0];
              int  weight =  j[1];
                v.push_back({weight,{u,w}});
                // cout<<weight<<" "<<u<<" "<<w<<endl;
            }
          
            
            
        }
        
        sort(v.begin(),v.end());
        
        int sum = 0;
        for(auto i : v)
        {
            int weight = i.first;
            int u = i.second.first;
            int w = i.second.second;
            // cout<<weight<<" "<<u<<" "<<w<<endl;
            
            u = find(u);
            w = find(w);
            if(u!=w)
            {
                sum+=weight;
                Union(u,w);
            }
        }
        
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
