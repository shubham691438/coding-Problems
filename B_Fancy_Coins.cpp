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
    ll m,k,x,y;
    cin>>m>>k>>x>>y;

    //use the available
    if(m-y*k<=0)
    {
        int type2=m/k;
        m=m-type2*k;

        if(m-x<=0)
        {
            cout<<0<<endl;
            return;
        }
        else
        {
            cout<<m-x<<endl;
            return ;
        }
    }
    else
    {
        m=m-y*k;
    }

    if(m-x<=0)
    {
        cout<<0<<endl;
        return;
    }
    else
    {
        if((m-x)%k==0)
        {
            cout<<(m-x)/k<<endl;
        }
        else
        {
            int req=x-(k-(m-x)%k);
            if(req>=0)
            {
                cout<<((m-x)/k+1)<<endl;
            }
            else
            {
                m=m-x;
                int ans=0;
                ans+=m/k;
                m=m%k;
                ans+=m;

                cout<<ans<<endl;
            }
        }
    }


        
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}