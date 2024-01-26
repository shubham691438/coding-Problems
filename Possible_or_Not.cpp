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
    int n,target;
    cin>>n>>target;

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    int curr=-1;
    for(int i=0;i<n;i++)
    {
        if((a[i]&target)==target)
        {
            curr=curr & a[i];
        }
    }

    if(curr==target)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}