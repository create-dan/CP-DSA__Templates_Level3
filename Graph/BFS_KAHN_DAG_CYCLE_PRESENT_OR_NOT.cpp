
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {

        vector<int> indegree(V);
        for (int i = 0; i < V; i++)
        {
            for (auto j : adj[i])
            {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // BFS
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cnt++;

            for (auto i : adj[node])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        if (cnt == V)
        {
            return false;
        }
        else
        {
            return true;
        }
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

