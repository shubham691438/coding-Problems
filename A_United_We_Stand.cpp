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

bool all_equal(vector<int> &a)
{
    for(int i=1;i<a.size();i++)
    {
        if(a[i]!=a[i-1])
        {
            return false;
        }
    }

    return true;
}
 
void solve(){
    ll n;
    cin>>n;

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    if(a.size()==1 || all_equal(a))
    {
        cout<<-1<<endl;
        return;
    }    

    sort(a.begin(),a.end());
    vector<int> b,c;
    b.push_back(a[0]);

    int i;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            b.push_back(a[i]);
        }
        else
        {
            break;
        }
    }

    for(;i<n;i++)
    {
        c.push_back(a[i]);
    }

    cout<<b.size()<<" "<<c.size()<<endl;
    for(auto &x:b) cout<<x<<" ";
    cout<<endl;
    for(auto &x:c)  cout<<x<<" ";
    cout<<endl;


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}