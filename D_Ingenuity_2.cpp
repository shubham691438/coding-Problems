#include<bits/stdc++.h>
using namespace std;
 
// DEBUG CODE 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



#define      ll         long long
#define      MAX        1000000
#define      mod        LLONG_MAX
#define      endl       "\n"
#define      ff         first
#define      ss         second
#define      w(t)       ll t; cin >> t; while(t--)
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

 
 
void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    if(s.size()%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }

    map<char,ll> mp;
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }

    //north and south cancel;
    ll ns_cancel= min(mp['N'],mp['S']);
    mp['N']-=ns_cancel;
    mp['S']-=ns_cancel;

    //east west cancel
    ll ew_cancel= min(mp['E'],mp['W']);
    mp['E']-=ew_cancel;
    mp['W']-=ew_cancel;

     if(mp['N']%2==1 || mp['S']%2==1 || mp['E']%2==1 || mp['W']%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }

    vector<char> ans(n);
    
    ll nor=ns_cancel ,sou=ns_cancel,e=ew_cancel,w=ew_cancel;

    ll cntH=0,cntR=0;
    ll alternate=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='N' && nor)
        {
           
                cntH++;
                ans[i]='H';
           
            
            
            nor--;
        }
        if(s[i]=='S' && sou)
        {
            
                cntH++;
                ans[i]='H';
                
           
            
            sou--;
        }
        if(s[i]=='E' && e)
        {
            
                cntH++;
                ans[i]='H';
            
            e--;
        }
        if(s[i]=='W' && w)
        {
              cntH++;
                ans[i]='H';
              
            
            w--;
        }
    }

    // debug(ans);
    //find a pair of north-south where ans="H" currently ans replace it with R
    ll done=false;
    bool oneDone1 =false,oneDone2=false;
    for(int i=0;i<n;i++)
    {   
        if(ans[i]=='H' && s[i]=='N' && !oneDone1) 
        {
            ans[i]='R';
            if(oneDone2)
            {
                done=true;
                break;
            }
            oneDone1=true;
            
        }

        else if(ans[i]=='H' && s[i]=='S' && !oneDone2)
        {
            ans[i]='R';
            if(oneDone1)
            {
                done=true;
                break;
            }
            oneDone2=true;
        }
    }

    if(!done)
    {
        oneDone1 =false,oneDone2=false;
        for(int i=0;i<n;i++)
        {   
            if(ans[i]=='H' && s[i]=='E' && !oneDone1) 
            {
                ans[i]='R';
                if(oneDone2)
                {
                    done=true;
                    break;
                }
                oneDone1=true;
                
            }

           else  if(ans[i]=='H' && s[i]=='W' && !oneDone2)
            {
                ans[i]='R';
                if(oneDone1)
                {
                    done=true;
                    break;
                }
                oneDone2=true;
            }
        }

    }

    // debug(ans);
    if(done){
        cntR+=2;
        cntH-=2;
    }

    
   

    //equallly divide the rest
    ll nh=mp['N']/2,sh=mp['S']/2,eh=mp['E']/2,wh=mp['W']/2;

    if(nh+sh+eh+wh==0 && (cntH==0 || cntR==0))
    {
        cout<<"NO"<<endl;
        return;
    }

    // debug(nh,sh,eh,wh);
    // debug(ans);
    for(int i=0;i<n;i++)
    {
        if(ans[i]=='H')
        {
            continue;
        }

        if(s[i]=='N')
        {
            if(nh)
            {
                ans[i]='H';
                nh--;
            }
            else
            {
                ans[i]='R';
            }
        }
        
        else if(s[i]=='S')
        {
            if(sh)
            {
                ans[i]='H';
                sh--;
            }
            else
            {
                ans[i]='R';
            }
        }
        else if(s[i]=='E')
        {
            if(eh)
            {
                ans[i]='H';
                eh--;
            }
            else
            {
                ans[i]='R';
            }
        }
        else if(s[i]=='W')
        {
            if(wh)
            {
                ans[i]='H';
                wh--;
            }
            else
            {
                ans[i]='R';
            }
        }
        

        
    }

    for(int i=0;i<n;i++)
        cout<<ans[i];
    cout<<endl;    


    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}