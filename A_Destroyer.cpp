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
    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &x:a) cin>>x;

    map<int,int> mp;
    for(int i=0;i<n;i++) mp[a[i]]++;

    int last_cnt=mp[0];
    int i=0,flag=1;
    for(auto ele:mp)
    {
        if(mp.find(i)==mp.end()){
            flag=0;
            break;
        }
        if(ele.second>last_cnt) flag=false;

        last_cnt=ele.second;
        i++;
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}