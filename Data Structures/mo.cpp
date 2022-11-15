#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{   

    ll n,m;
    cin>>n>>m;

    //ll a[n+1];
    //for(ll i=1;i<=n;i++) cin>>a[i];

    ll ans[m+1];
    vector<pair<pair<ll,ll>,ll>> q;
    for(ll i=1;i<=m;i++){
        ll l,r;
        cin>>l>>r;
        q.pb({{l,r},i});
    }

    sort(all(q));
    ll d=sqrt(n)+1;

    priority_queue<pair<pair<ll,ll>,ll>> p;
    for(ll i=0,j=1;i<m;i++){
        if(q[i].first.first<=j*d){
            p.push({{q[i].first.second,q[i].first.first},q[i].second});
            continue;
        }
        ll c=0;
        while(!p.empty()){
            pair<pair<ll,ll>,ll> temp=p.top();
            p.pop();
            c++;
            q[i-c]={{temp.first.second,temp.first.first},temp.second};
        }
        p.push({{q[i].first.second,q[i].first.first},q[i].second});
        j++;
    }
    ll c=0;
    while(!p.empty()){
        pair<pair<ll,ll>,ll> temp=p.top();
        p.pop();
        c++;
        q[m-c]={{temp.first.second,temp.first.first},temp.second};
    }

    for(ll i=0;i<m;i++) cout<<q[i].first.first<<" "<<q[i].first.second<<" "<<q[i].second<<endl;

    return 0;
}