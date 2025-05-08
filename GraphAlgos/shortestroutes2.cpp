#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;
typedef vector<set<int>> vsi;

const ll inf=9e17;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m,q; cin>>n>>m>>q;
   
    vector<vll> distances(n,vll(n,inf));

    for(int i=0;i<n;i++) distances[i][i]=0;

    for(int i=0;i<m;i++)
    {
        ll a,b,c; cin>>a>>b>>c;
        --a;
        --b;
        
        distances[a][b]=min(distances[a][b],c);
        distances[b][a]=min(distances[b][a],c);
    }
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                distances[i][j]=min(distances[i][j],distances[i][k]+distances[k][j]);


    for(int i=0;i<q;i++)
    {
        int a,b; cin>>a>>b;
        --a;
        --b;
        cout<<(distances[a][b]==inf?-1:distances[a][b])<<"\n";
    }
    
    return 0;
}
