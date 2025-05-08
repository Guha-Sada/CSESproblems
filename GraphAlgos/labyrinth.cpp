#include<bits/stdc++.h>


using namespace std;

vector<vector<char>> grid(1001,vector<char>(1001)),path_taken(1001,vector<char>(1001));
bool used[1001][1001];
int n,m,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
string direction="RLDU";
stack<char> route;


void backtrack(int x,int y)
{

	if(path_taken[x][y]!='S')
	{
		char dir=path_taken[x][y];
		route.push(dir);
		if (dir == 'U') backtrack(x + 1, y);
        	else if (dir == 'D') backtrack(x - 1, y);
        	else if (dir == 'L') backtrack(x, y + 1);
        	else if (dir == 'R') backtrack(x, y - 1);
	}
}


bool bfs(pair<int,int> start)
{
	queue <pair<int,int>> path_cells;
	bool flag=false;

	path_taken[start.first][start.second]='S';
	used[start.first][start.second]=true;
	path_cells.push(start);
	
	while(!path_cells.empty())
	{
		auto curr=path_cells.front();
		path_cells.pop();
		if(grid[curr.first][curr.second]=='B')
		{
			flag=true;
			backtrack(curr.first,curr.second);
			break;
		}

		for(int d=0;d<4;d++)
		{
			auto nxt=curr;
			nxt.first+=dx[d];
			nxt.second+=dy[d];

			if(nxt.first<0||nxt.first>=n||nxt.second<0||nxt.second>=m) continue;
			if(grid[nxt.first][nxt.second]=='#') continue;
			if(used[nxt.first][nxt.second]) continue;
			
			
			used[nxt.first][nxt.second]=true;
			path_taken[nxt.first][nxt.second]=direction[d];
			path_cells.push(nxt);
			
			//cout<<nxt.first<<" "<<nxt.second<<" "<<direction[d]<<"\n";
		}

	}
	return (flag?true:false);
}

int main()
{

	pair<int,int> start;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='A')
				start={i,j};
		}


	if(bfs(start))
	{
		cout<<"YES\n"<<route.size()<<"\n";
		while(!route.empty()) 
		{
			cout<<route.top();
			route.pop();
		}

	}
	else cout<<"NO\n";

	return 0;
}
