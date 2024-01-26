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

 
bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first<b.first)
    {
        return true;
    }
    
    return false;
}

void solve(){
    ll n,p;
    cin>>n>>p;

    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];

    for(ll j=0;j<n;j++)
        cin>>b[j];
        

    vector<pair<int,int>> vpr;
    for(int i=0;i<n;i++)
        vpr.push_back({min(b[i],p),a[i]});

    sort(vpr.begin(),vpr.end(),compare);    

      


    ll currCnt=1;
    ll currCost=p;

    
    for(auto ele: vpr)
    {
        ll cost=ele.first;
        ll no=ele.second;

        // cout<<cost<<" "<<no<<endl;
        if(n-currCnt-no>=0)
        {   
            currCnt+=no;
            currCost+=no*cost;
        }
        else if(n-currCnt>0)
        {
            int num=n-currCnt;
            currCnt+=num;
            currCost+=(num)*cost;
            
        }
        
    }    


    cout<<currCost<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}