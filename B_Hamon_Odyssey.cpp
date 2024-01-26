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

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    int mini=-1;
    for(int i=0;i<n;i++)
    {
        mini=mini & a[i];
    }

    int cnt=0;
    int curr=-1;
    for(int i=0;i<n;i++)
    {
        curr=curr & a[i];
        if(curr==0)
        {
            cnt++;
            curr=-1;
        }
    }

    if(mini==0)
    {
        cout<<cnt<<endl;
    }
    else
    {
        cout<<cnt+1<<endl;
    }

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}