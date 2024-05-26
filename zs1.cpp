#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fast;
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        queue<int> q;
        q.push(n);
        set<int> st;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            st.insert(curr);
            if(curr-a>0){
                q.push(curr-a);
            }
            if(curr-b>0){
                q.push(curr-b);
            }
        }
        cout<<st.size();
    }
    return 0;
}