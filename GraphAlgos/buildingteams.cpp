#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m; cin >>n >>m;
	
	vector<vector<int>> adj(n);

	for(int i=0;i<m;i++)
	{
		int a,b; cin>>a>>b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> teams(n,-1);

	for(int i=0;i<n;i++)
	{
		if(teams[i]!=-1) continue;

		queue<int> pupils;
		pupils.push(i);
		teams[i]=1;
		while(!pupils.empty())
		{
			int cur=pupils.front();
			pupils.pop();

			for(int nxt: adj[cur])
			{
				if(teams[nxt]!=-1)
				{
					if(teams[nxt]+teams[cur]!=3) 
					{
						cout<<"IMPOSSIBLE\n";
						return 0;
					}
				}
				else
				{
					teams[nxt]=3-teams[cur];
					pupils.push(nxt);
				}
			}
		}
	}
	for(auto& x:teams) cout<<x<<" ";	
	return 0;
}
