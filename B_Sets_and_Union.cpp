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

    vector<set<int>> sets(n);
    map<ll,ll> freq;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
           int val;
           cin>>val;
           sets[i].insert(val);
           freq[val]++;
        }
    }

    ll maxi=0;
    for(auto child:freq)
    {
        int i=child.first;
        set<ll> masterSet;
        for(int j=0;j<n;j++)
        {
            if(sets[j].find(i)==sets[j].end())
            {
                masterSet.insert(sets[j].begin(),sets[j].end());
            }
        }

        
        if((ll)masterSet.size() != freq.size())
         maxi=max(maxi,(ll)masterSet.size());
    }  



    cout<<maxi<<endl;
    
    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}