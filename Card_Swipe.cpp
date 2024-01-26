#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n;
    cin>>n;

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    multiset<int> st;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(st.find(a[i])!=st.end())
        {
            st.erase(a[i]);
        }
        else
        {
            st.insert(a[i]);
        }
        int len=st.size();
        maxi=max(len,maxi);
    }    

    cout<<maxi<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}