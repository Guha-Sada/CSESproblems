#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> children(n);
    
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;

        adj[a].push_back(b);
    }

    

    return 0;
}
