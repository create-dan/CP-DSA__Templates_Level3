
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isCycleBfs(int src, vector<int> &visited, vector<int> adj[])
    {
        unordered_map<int, int> parent;

        parent[src] = -1;
        visited[src] = -1;

        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto i : adj[front])
            {

                if (visited[i] == true and i != parent[front])
                {
                    return true;
                }
                else if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {

        // unordered_map<int,bool> visited;
        vector<int> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = isCycleBfs(i, visited, adj);
                if (ans)
                    return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends