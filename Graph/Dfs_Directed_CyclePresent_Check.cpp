
// basic idea
// visited[node] =true and dfsVisited[true] = true
//  Then cycle is present in given undirected graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(int i, vector<int> &visited, vector<int> &dfsVisited, vector<int> adj[])
    {
        visited[i] = 1;
        dfsVisited[i] = 1;

        for (auto j : adj[i])
        {
            if (!visited[j])
            {
                bool check = helper(j, visited, dfsVisited, adj);
                if (check)
                    return true;
            }
            else if (dfsVisited[j])
            {
                return true;
            }
        }

        dfsVisited[i] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {

        // created visited and dfsVisited arrays
        vector<int> visited(V, 0);
        vector<int> dfsVisited(V, 0);

        // call dfs for all component
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool check = helper(i, visited, dfsVisited, adj);
                if (check)
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
