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
    ll x;
    cin>>x;

    if(x==1)
    {
        cout<<-1<<endl;
        return;
    }    

    ll root=(ll)sqrt(x);

    ll a,b,c;
    
    a=root;
    if(x%a==0)
    {
        if((a-1)!=0 && x/(a-1)!=0 && (x-(a-1)*(x/(a-1)))!=0)
        {
            if((a-1)<=1e6 && x/(a-1)<=1e6 && (x-(a-1)*(x/(a-1)))<=1e6)
            {
                cout<<a-1<<" "<<x/(a-1)<<" "<<(x-(a-1)*(x/(a-1)))<<endl;
                return;
            }
            
        }

        b=root;
        a=root;
        c=x-a*b;
       if(a!=0 && b!=0 && c!=0)
        {
            if(a<=1e6 && b<=1e6 && c<=1e6)
            {
                cout<<a<<" "<<b<<" "<<c<<endl;
                return;
            }
        }

        a=root-1,b=root-1;
        c=x-a*b;
        if(a!=0 && b!=0 && c!=0)
        {
            if(a<=1e6 && b<=1e6 && c<=1e6)
            {
                cout<<a<<" "<<b<<" "<<c<<endl;
                return;
            }
        }
        


    }
    else {
        cout<<root<<" "<<x/root<<" "<<x%root<<endl;
        return;
    }

   
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}