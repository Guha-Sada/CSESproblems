#include<bits/stdc++.h>

using namespace std;

vector<int> a(2e5+1);
vector<long long>pref(2e5+1);

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int n,q; cin>>n>>q;
    
    for(int i=0;i<n;i++)
    { 
        cin>>a[i];
        pref[i+1]=pref[i]+a[i];
    }
    while(q--)
    {
        int l,r; cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<"\n";
    }
    return 0;
}
