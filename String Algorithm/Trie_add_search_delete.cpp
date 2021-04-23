#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

set<pair<char,bool>> g[1007][28];

void build_trie(ll n){
    for(ll i=1;i<=n;i++){
        string s;
        cin>>s;
        char p=(char)(0);
        for(ll j=0;j<s.size();j++){
            set<pair<char,bool>>::iterator it=g[j][p].lower_bound(mp(s[j],0));
            if(it->first==s[j]){
                if(j+1==s.size()){
                    g[j][p].erase(it);
                    g[j][p].insert({s[j],1});
                }
            }
            else{
                if(j+1==s.size()) g[j][p].insert({s[j],1});
                else g[j][p].insert({s[j],0});
            }
            p=s[j];
        }
    }
}

void search_in_trie(){
    string s;
    cin>>s;

    char p=(char)(0);
    for(ll i=0;i<s.size();i++){
        set<pair<char,bool>>::iterator it=g[i][p].lower_bound(mp(s[i],0));
        if(it->first==s[i]) p=s[i];
        else{
            cout<<"String not found!"<<endl;
            return;
        }
        if(i+1==s.size()){
            if(it->second) cout<<"String found!"<<endl;
            else cout<<"String not found!"<<endl;
            return;
        }
    }
}

void delete_word_in_trie(){
	string s;
	cin>>s;

	for(ll i=s.size()-1;i>=0;i--){
		char p=(char)(0);
		if(i) p=s[i-1];
		set<pair<char,bool>>::iterator it=g[i][p].lower_bound(mp(s[i],0));
		if(i+1==s.size()){
			g[i][p].erase(it);
			if(g[i][s[i]].size()!=0) g[i][p].insert({s[i],0});
		}
		else{
			if(g[i][s[i]].size()==0 && (it->second)!=1)
				g[i][p].erase(it);
			else break;
		}
	}
}

int main()
{   

    ll n;
    cin>>n;

    build_trie(n);

    ll q;

    cin>>q;
    while(q--){
        ll c;
        cin>>c;
        if(c==1) search_in_trie();
        else delete_word_in_trie();
    }

    return 0;
}
