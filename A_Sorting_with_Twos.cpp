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

 bool isPowerOf2(int number) {
    if (number <= 0) {
        return false;
    }
    return (number & (number - 1)) == 0;
}
 
void solve(){
    ll n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    bool ans=true;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            if(!isPowerOf2(i))
            {
                ans=false;
                break;
            }
        }
    }

    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}