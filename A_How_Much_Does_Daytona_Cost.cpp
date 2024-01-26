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
 ll n,k;
 cin>>n>>k;

 vector<int> a(n);
 for(int i=0;i<n;i++){
    cin>>a[i];
    
 }
 for(int i=0;i<n;i++)
 {
    if(a[i]==k)
    {
        cout<<"YES"<<endl;
        return;
    }
 }

 cout<<"NO"<<endl;


}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}