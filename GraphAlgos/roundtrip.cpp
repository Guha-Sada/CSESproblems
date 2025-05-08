#include<bits/stdc++.h>

using namespace std;


vector<int> adj(2*10e5+1);

int dfs(int city)
{

}

int main()
{
    int n,m; cin>>n>>m;
    
    
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++)
    {
        int dfs_val=dfs(i);    
    }
       
    return 0;
}
