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
    ll n,k;
    cin>>n>>k;

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll last=n,second_last=i,third_last;
        bool valid_seq=true;
        for(int j=0;j<k-2;j++)
        {
           third_last=last-second_last;
           
           if(third_last<0 || third_last >second_last)
           {
             valid_seq=false;
             break;
           }

           last=second_last;
           second_last=third_last;
        }

        if(valid_seq) ans++;
    }  

    cout<<ans<<endl;  

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}