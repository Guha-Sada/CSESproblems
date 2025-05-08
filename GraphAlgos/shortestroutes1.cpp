#include<bits/stdc++.h>

using namespace std;

//Dijkstra,


typedef long long ll;

const ll inf=9e17;


int main()
{
    int n,m; cin>>n>>m;
    
    vector<vector<pair<ll,ll>>> adj(n);

    for(int i=0;i<m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        --a;
        --b;

        adj[a].push_back({b,c});
    }

    vector<ll> distances(n,inf);
    distances[0]=0;

    priority_queue<pair<ll,ll>> pq;
    pq.push({0,0});

    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        if(-1*cur.first>distances[cur.second]) continue;

        for(auto &nxt:adj[cur.second])
        { 
            if (distances[cur.second]+nxt.second<distances[nxt.first])
            {
                distances[nxt.first]=distances[cur.second]+nxt.second;
                pq.push({-distances[nxt.first],nxt.first});    
            }
            
        }
    }
    
    for(auto &x: distances) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
