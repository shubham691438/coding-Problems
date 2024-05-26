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
    string s;
    cin>>s;

    int n=s.size();

    //transition from letter to number
    ll transition=0;
    for(int i=0;i<n-1;i++)
    {
        if ((s[i]<='Z' && s[i]>= 'A') && (s[i+1]>='1' && s[i+1] <='9')){
            transition++;
        }
    }


    //if not excel format then convert to excel format
    if(transition==2)
    {
        string row="",col="";
        int i=1;
        while(s[i] != 'C')
        {
            row+=s[i];
            i++;
        }
        i++;
        while(i<n)
        {
            col+=s[i];
            i++;
        }

        ll colNo= stoi(col);
        col="";
        while(colNo){
            colNo--;
            col+= 'A'+(colNo%26) ;
            colNo=colNo/26;
        }
        reverse(col.begin(),col.end());
        cout<<col<<row<<endl;
    }
    else{
            string row="",col="";
            int i=0;
            while(s[i]>='A' && s[i] <= 'Z')
            {
                col+=s[i];
                i++;
            }
            
            // debug(col);
            while(i<n)
            {
                row+=s[i];
                i++;
            }

            ll colNo=0;
            for(int i=0;i<col.size();i++)
            {
                colNo=colNo*26+ (col[i]-'A'+1);
            }

            cout<<'R'<<row<<'C'<<colNo<<endl;
    }

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}