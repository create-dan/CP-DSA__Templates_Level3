#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void dfs(int source, bool *visited, vector<int> &ans, int V, vector<int> adj[])
    {
        visited[source] = true;

        ans.push_back(source);

        for (auto i : adj[source])
        {
            if (!visited[i])
                dfs(i, visited, ans, V, adj);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;

        bool visited[V] = {false};

        dfs(0, visited, ans, V, adj);

        return ans;
    }
};

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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
