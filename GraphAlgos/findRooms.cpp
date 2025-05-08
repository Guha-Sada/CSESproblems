#include<bits/stdc++.h>


using namespace std;

int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

int main()
{
	int n, m; cin >> n >> m;

	vector<string> grid(n);

	for(auto &x:grid) cin>>x;
	

	int count_rooms=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]=='#') continue;

			count_rooms++;

			queue<pair<int,int>> room_cells;
			room_cells.push({i,j});
			
			grid[i][j]='#';

			while(!room_cells.empty())
			{
				auto curr_cell=room_cells.front(); room_cells.pop();

				for(int k=0;k<4;k++)
				{

					auto next_cell=curr_cell;
					
					next_cell.first+=dx[k];
					next_cell.second+=dy[k];
					if(next_cell.first<0||next_cell.first>=n||next_cell.second<0||next_cell.second>=m) continue;

					if(grid[next_cell.first][next_cell.second]=='#') continue;

					room_cells.push(next_cell);
				
					grid[next_cell.first][next_cell.second]='#';
				}
			}
		}

	}
	cout<<count_rooms<<"\n";

	return 0;
}

