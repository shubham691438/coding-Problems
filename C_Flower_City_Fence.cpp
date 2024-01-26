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
    ll n;;
    cin>>n;

    stack<int> s;
    vector<int> a(n);
    for(auto &x:a) 
    {
        cin>>x;
        s.push(x);
    }

    if(a[0]!=a.size()){
        cout<<"NO"<<endl;
        return;
    }

    int d=1;
    for(int i=1;i<n;i++)
    {
        while(s.top()-d<=0)
        {
            s.pop();
        }
       

        if(a[i] != s.size())
        {
            cout<<"NO"<<endl;
            return;
        }
         d++;

    }

    cout<<"YES"<<endl;


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}