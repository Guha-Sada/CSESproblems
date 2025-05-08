#include<bits/stdc++.h>

using namespace std;


//I can use dfs to check if a route exists. However, this route may not be the ideal route.
//Maybe BFS? to find ideal route. so dfs to chekc if route exists, BFS to find route? sounds too expensive.
//proabably there is a method using dfs?

vector<vector<int>> adj(2*10e5+1);

vector<int> from(10e5+1);

vector<bool> visited(10e5+1);

stack<int> route;
int n,m;


int main()
{
	cin >> n >> m;
	
	for(int i=0;i<m;i++)
	{
		int c1,c2; cin>>c1>>c2;
		adj[c1].push_back(c2);
		adj[c2].push_back(c1);
	}
	
	

	queue<int> computers;
	computers.push(1);
	visited[1]=true;
	
	while(!computers.empty())
	{
		int cur=computers.front();
		computers.pop();
		visited[cur]=true;

		if(cur==n)break;
	
		for(int nxt:adj[cur])
		{
			if(!visited[nxt])
			{
				visited[nxt]=true;
				from[nxt]=cur;
				computers.push(nxt);
			}
		}

	}

	if(!visited[n]) cout<<"IMPOSSIBLE\n";
	else
	{
		route.push(n);
		int backtracker=n;
		while(backtracker!=1)
		{
			backtracker=from[backtracker];
			route.push(backtracker);
		}
		cout<<route.size()<<"\n";
		while(!route.empty())
		{
			cout<<route.top()<<" ";
			route.pop();
		}
	}
	
	return 0;
}
