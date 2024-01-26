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
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n;
    cin>>n;
    vector<ll> ans;

    ans.push_back(2);
    ans.push_back(3);

    int curr=3;
    for(ll i=2;i<n;i++)
    {
        curr++;
        if((3*curr)%(ans[i-1]+ans[i-2])==0)
            curr++;

        ans.push_back(curr);
    } 

    for(ll i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }   

    cout<<endl;

    // bool f=true;
    // for(ll i=2;i<n;i++)
    // {
    //     if(((3*ans[i])%(ans[i-1]+ans[i-2]))==0)
    //     {
    //         f=false;
    //         break;
    //     }
    // }

    // if(f)
    // cout<<"CORRECT"<<endl;
    // else
    // cout<<"INCORRECT"<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}