#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{   

    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];

    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll id=lower_bound(all(v),a[i])-v.begin();
        if(id<v.size()) v[id]=a[i];
        else v.pb(a[i]);
    }

    cout<<v.size()<<endl;

    return 0;
}
