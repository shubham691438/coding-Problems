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
#define      fastio     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define      all(a)     (a).begin(), (a).end()
#define      pb         push_back
/*-----------------------------------------------------------------------------------*/

long long merge(vector<ll>& arr, ll low, ll mid, ll high) {
    ll leftSize = mid - low + 1;
    ll rightSize = high - mid;

    vector<ll> left(leftSize);
    vector<ll> right(rightSize);

    for (ll i = 0; i < leftSize; ++i)
        left[i] = arr[low + i];
    for (ll j = 0; j < rightSize; ++j)
        right[j] = arr[mid + 1 + j];

    long long inversions = 0;
    ll i = 0, j = 0, k = low;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += (leftSize - i); // Count inversions
        }
    }

    while (i < leftSize)
        arr[k++] = left[i++];
    while (j < rightSize)
        arr[k++] = right[j++];

    return inversions;
}

long long mergeSort(vector<ll>& arr, ll low, ll high) {
    long long inversions = 0;
    if (low < high) {
        ll mid = low + (high - low) / 2;
        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);
        inversions += merge(arr, low, mid, high);
    }
    return inversions;
}

long long countInversions(vector<ll>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}
 
 
void solve(){
    ll n;
    cin>>n;

    vector<ll> a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    
    vector<ll> ansA(n),ansB(n);
    ll mini;

    //sort a and count inversion in b
    map<ll,ll> mp1;
    for(ll i=0;i<n;i++)
    {
        mp1[a[i]]=b[i];
    }

    vector<ll> sortedA=a;
    sort(sortedA.begin(),sortedA.end());

    vector<ll> temp(n);
    ansA=sortedA;
    for(ll i=0;i<n;i++)
    {
        temp[i]=mp1[sortedA[i]];
        ansB[i]=mp1[sortedA[i]];

    }

    mini= countInversions(temp);

    //sort b and count inversion in a
    mp1.clear();
    for(ll i=0;i<n;i++)
    {
        mp1[b[i]]=a[i];
    }
    

    vector<ll> sortedB=b;
    sort(sortedB.begin(),sortedB.end());

    temp.clear();
    temp.resize(n);
    for(ll i=0;i<n;i++)
    {
        temp[i]=mp1[sortedB[i]];

    }

    
    ll cnt=countInversions(temp);
    
    if(cnt<mini)
    {
        ansB.clear();
        ansB.resize(n);
        ansB=b;
        for(int i=0;i<n;i++)
            ansA[i]=mp1[sortedB[i]];
    }

    for(int i=0;i<n;i++)
        cout<<ansA[i]<<" ";

    cout<<endl;    
    for(int i=0;i<n;i++)
        cout<<ansB[i]<<" ";
    cout<<endl;           

    
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}