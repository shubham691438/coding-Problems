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
    ll n,m,d;
    cin>>n>>m>>d;

    vector<int> a(m);
    for(auto &x:a) cin>>x;

    a.insert(a.begin(),1-d);
    a.push_back(n+1);


    //Total cookies eaten if no cookie seller is removed
    int original=0;
    for(int i=1;i<a.size();i++)
    {
        original+= (a[i] - a[i - 1] - 1) / d ;
    }
    //subtracting 1 for the last
    original=original+a.size()-2;
    
    int mini=1e9,cnt=0;
    for(int i=1;i<=m;i++)
    {
        int A = (a[i] - a[i - 1]-1)/d;
        int B = (a[i + 1] - a[i]-1)/d;
        int C = (a[i + 1] - a[i - 1] -1 )/d;

        int curr= original- A - B + C -1;
        

        if(curr<mini)
        {
            mini=curr;
            cnt=0;
        }
        if(curr==mini)
        {
            cnt++;    
        }
        
    }

    cout<<mini<<" "<<cnt<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}