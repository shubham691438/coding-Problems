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

bool AllPositive(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<0) return false;
    }

    return true;

}
bool AllNegative(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>0) return false;
    }

    return true;

}
 
 
void solve(){
    ll n;
    cin>>n;

    vector<int> x(n),y(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    bool ok=false;
    if(AllPositive(x) || AllNegative(x))
        ok=true;
    else if(AllPositive(y) || AllNegative(y))
    {
        ok=true;
    }    

    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}