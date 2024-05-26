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

 bool isBinaryDecimal(double n)
 {
    if(floor(n) !=ceil(n)) return false;

    ll num=(ll)n;
    while(num>0)
    {
        if( (num % 10) >=2) return false;

        num=num/10;
    }

    return true;
 }

ll getBinaryform(ll n)
{
    // debug(n);

     // array to store binary number
    int binaryNum[65];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    // for (int j = i - 1; j >= 0; j--)
    //     cout << binaryNum[j];


    ll num=0;
    for (int j = i - 1; j >= 0; j--)
        num=num*10+binaryNum[j];

    // debug(num);
    return num;
} 

ll divideBybinaryDec(ll n)
{   
    //upto 6 digit in binary
    for(int i=2;i<=64;i++)
    {
       
        ll num = getBinaryform(i);

        if(n%num==0) return n/num;
    }

    return 0;
}
void solve(){
    double n;
    cin>>n;


    // debug("NUM",n);
    bool ok=false;
    while(n>0)
    {
       if(isBinaryDecimal(n))
       {
            ok=true;
            break;
       }

       
       if(!divideBybinaryDec(n)) 
       {
        break;
       }

       n=divideBybinaryDec(n);
    }

    if(ok)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    

    

}
 
 
int main(){
    fastio;
    w(t){
        solve();
    }
}