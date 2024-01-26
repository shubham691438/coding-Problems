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
    ll ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;    

    int cntx=0,cnty=0;

    if((ax<bx && ax<cx) || (ax>bx && ax>cx))
    {
        cntx+=min(abs(ax-bx),abs(ax-cx));
    }

    if((ay<by && ay<cy) || (ay>by && ay>cy))
    {
        cnty+=min(abs(ay-by),abs(ay-cy));
    }

    // if(cntx==0 + cnty==0)
    // {
    //     cout<<1<<endl;
    // }
    // else
    {
        cout<<cntx+cnty+1<<endl;
    }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}