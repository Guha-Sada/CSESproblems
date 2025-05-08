//DFS to count groups.

#include<bits/stdc++.h>

using namespace std;


vector<vector<int>> adj(10e5+1);

vector<bool> visited (10e5+1,false);

vector<int> new_roads;

int n,m;


void dfs(int v)
{
	visited[v]=true;
	//cout<<v<<" ";
	for(auto u:adj[v])
	{
		if(!visited[u]) dfs(u);
	}

}

int main()
{

	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int city1,city2;
		cin>>city1>>city2;
		adj[city1].push_back(city2);
		adj[city2].push_back(city1);
	}

	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			new_roads.push_back(i);
			dfs(i);
		}

	}
	
	cout<<new_roads.size()-1<<"\n";
	for(int i=0;i<int(new_roads.size())-1;i++)
	{
		cout<<new_roads[i]<<" "<<new_roads[i+1]<<"\n";
	}
	return 0;
}
