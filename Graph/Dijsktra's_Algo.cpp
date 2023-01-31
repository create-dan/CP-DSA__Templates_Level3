//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    //#Lover babbar
    //https://www.youtube.com/watch?v=dVUR3Rm6biE&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA&index=11&ab_channel=CodeHelp-byBabbar
    //set lo pair ka
    //pair = {distance,node} distance pahle because uske basis pai sort hona chahiye
    
    
    
    
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
       vector<int> dist(V,INT_MAX);
       
       //distance , node
       set<pair<int,int>> st;
       
       dist[src]=0;
       st.insert({0,src});
       while(!st.empty())
       {
            auto top = *(st.begin());
            int distance = top.first;//0
            int node = top.second;//2
            st.erase(top);
            
            for(auto it : adj[node])
            {
                int itDist = it[1];//6
                int itNode = it[0];//0
                
                if(distance + itDist < dist[itNode])
                {
                    auto j = st.find({dist[itNode],itNode});
                    if(j!=st.end())
                    {
                        st.erase(j);
                    }
                    
                    dist[itNode] = distance+itDist;
                    st.insert({dist[itNode],itNode});
                }
            }
       }
       
       return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
