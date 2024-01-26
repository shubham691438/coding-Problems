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

 int cntUnique(vector<int>ans)
 {
    set<int> st;
    for(auto ele:ans)
    {
        st.insert(ele);
    }
    return st.size();
 }   
 bool bothequal(string str)
 {
    int n=str.size();
    int o=0,c=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]==')')
        {
            c++;
        }
        else
        {
            o++;
        }
    }

    if(o==c)
    {
        return true;
    }
    else
    {
        return false;
    }

 }
 
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;

    if(n%2==1)
    {
        cout<<-1<<endl;
        return;
    }

    if(bothequal(str)==false)
    {
        cout<<-1<<endl;
        return;
    }

    int c=0;
    int cnt=1;
    vector<int> ans(n);
    ans[0]=0;
    char last=str[0];
    for(int i=1;i<n;i++)
    {
        if(str[i]==last)
        {
            ans[i]=c;
            cnt++;
        }
        else if(cnt)
        {
            ans[i]=c;
            cnt--;
        }
        else{
            cnt++;
            c=c^1;
            last=str[i];
            ans[i]=c;
        }
        // cout<<cnt<<endl;

    }    

    cout<<cntUnique(ans)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]+1<<" ";
    }

    cout<<endl;
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}