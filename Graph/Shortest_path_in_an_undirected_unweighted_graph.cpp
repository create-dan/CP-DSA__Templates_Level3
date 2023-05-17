//n-vertices
//m-edges size
//bfs se parent array nikala
//while s!=t t=parent[t]
//reverse parent

#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<int> adj[n];
	for(int i=0;i<m;i++)
	{
		int u = edges[i].first-1;
		int v = edges[i].second-1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//bfs
        bool visited[n] = { false };
		s--;
		t--;
		int parent[n];
		queue<int> q;
		q.push(s);
		visited[s]=true;
		parent[s]=-1;
		while(!q.empty())
		{
			int front = q.front();
			q.pop();
			 for(auto i : adj[front])
			 {
				 if(!visited[i]){
					 visited[i]=true;
					 parent[i]=front;
					 q.push(i);
				 }
			 }

		}


		// for(int i=0;i<n;i++)
		// {
		// 	cout<<parent[i]<<" ";
		// }
		// cout<<endl;

		vector<int> ans;
		ans.push_back(t+1);
		while(s!=t)
		{
			t=parent[t];
			ans.push_back(t+1);
		}
		reverse(ans.begin(),ans.end());
                return ans;
}
