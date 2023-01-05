//stack use karna
//recursive call se wapas to stack mai dal do
//stack ko vector mai dalo and return


#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    // Function to return list containing vertices in Topological order.

    void topSortFunc(int src, stack<int> &st, vector<int> &visited, vector<int> adj[])
    {
        visited[src] = true;
        for (auto i : adj[src])
        {
            if (!visited[i])
            {
                topSortFunc(i, st, visited, adj);
            }
        }

        st.push(src);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> visited(V, false);
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                topSortFunc(i, st, visited, adj);
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};


int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
