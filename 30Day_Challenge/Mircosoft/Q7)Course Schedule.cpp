// https: // leetcode.com/problems/course-schedule/description/

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

// Algo-
// - Basically check whether cycle exists or not using topological sorting
// - topological sorting using BFS and DFS
// - iski dfs approach bhi dekh lo

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int num, vector<vector<int>> &v)
    {

        vector<vector<int>> adj(num);
        vector<int> indegree(num, 0);
        for (int i = 0; i < v.size(); i++)
        {
            adj[v[i][1]].push_back(v[i][0]);
            indegree[v[i][0]]++;
        }

        queue<int> q;
        for (int i = 0; i < num; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // bfs
        vector<int> ans;
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            ans.push_back(node);
            for (auto i : adj[node])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        cout << cnt << " " << num << endl;

        return cnt == num;
    }
};

int32_t main()
{
}