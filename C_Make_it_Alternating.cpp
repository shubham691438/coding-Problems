#include<bits/stdc++.h>
using namespace std;
 
#define      ll         long long
#define      MAX        1000000
#define      mod        998244353
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/



void solve(ll fact[]){
    string str;
    cin>>str;

    ll n=str.size();

    vector<ll> a;
    ll cnt=1;
    for(ll i=1;i<n;i++) 
    {
        if(str[i]==str[i-1])
        {
            cnt++;
        }
        else 
        {
            
            a.push_back(cnt);
            cnt=1;
        }
    }

    
        a.push_back(cnt);
   

    ll steps=0;
    steps=n-a.size();

    ll no_operations=1;
    for(auto x:a) {
        no_operations=(no_operations*x)%mod;
    }
    no_operations=(no_operations*fact[steps])%mod;

    cout<<steps<<" "<<no_operations<<endl;


}
 
 
int main(){
    fastio
    ll n=2e5+7;
    ll fact[n + 1];
 
    // Base case
    fact[0] = 1;
 
    // Calculate value
    // factorials up to n
    for(ll i = 1; i <= n; i++)
    fact[i] = ((i%mod) * (fact[i - 1]%mod))%mod;

    w(t){
        solve(fact);
    }
}