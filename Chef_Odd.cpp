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
    int n,k;
    cin>>n>>k;

    if(k>n/2)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(n%2==1)
    {
        if((n-2*k)==1)
        {
            cout<<"NO"<<endl;
            return ;
        }
        else
        {
            cout<<"YES"<<endl;
            return;
        }

    }

    cout<<"YES"<<endl;



}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}