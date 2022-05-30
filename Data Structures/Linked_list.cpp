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

class Node{
    public:
        int val;
        Node* prev=NULL;
        Node* next=NULL;
}; 
Node* head = new Node();

void addVal(int x){
    Node* node=head;
    while(node->next!=NULL) node=node->next;

    Node* newNode=new Node();
    newNode->val=x;
    newNode->prev=node;

    node->next=newNode;
}

void deleteVal(int x){
    Node* node=head;
    while(node->next!=NULL && node->val!=x) node=node->next;
    if(node->val!=x){
        cout<<x<<" is not found."<<endl;
        return;
    }

    node->prev->next=node->next;
    node->next->prev=node->prev;
}

void printList(){
    Node* node=head;
    while(node->next!=NULL){
        node=node->next;
        cout<<node->val<<" ";
    }cout<<endl;
}

int main()
{   
    

    int n;
    cin>>n;

    while(n--){
        int x,op;
        cin>>op>>x;

        if(op) addVal(x);
        else deleteVal(x);
        printList();
    }

    return 0;
}
