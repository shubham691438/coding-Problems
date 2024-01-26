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
    vector<int> a(n),b(n);
    int min1=1e9+7,min2=1e9+7;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        min1=min(min1,a[i]);
       
    }  

    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        min2=min(min2,b[i]);
    } 

    ll option1=0,option2=0;
    option1+=min1*n;
        for(int i=0;i<n;i++)
        {
            option1+=b[i];
        }
        
    
        option2+=min2*n;
        for(int i=0;i<n;i++)
        {
            option2+=a[i];
        }

    cout<<min(option1,option2)<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}