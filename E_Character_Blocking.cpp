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
    string str1,str2;
    cin>>str1>>str2;

    int n=str1.size();
    int t,queries;
    cin>>t>>queries;    

    int unequal_cnt=0;
    for(int i=0;i<n;i++)
    {
        if(str1[i]!=str2[i])
            unequal_cnt++;
    }

    vector<bool> block(n,false);
    queue <int> q;

    for(int pos=0;pos<queries;pos++)
    {
        

        int qt;
        cin>>qt;

        //unblocking with each query
        if(!q.empty() && pos-t>=0)
        {
            int index=q.front();
            q.pop();
            if(index!=-1)
            {
                block[index]=false;
                if(str1[index]!=str2[index])
                {
                    unequal_cnt++;
                }
            }

        }

        if(qt==1)
        {
            int ind;
            cin>>ind;
            ind=ind-1;

            q.push(ind);
            block[ind]=true;

            if(str1[ind]!=str2[ind])
            {
                unequal_cnt--;
            }
        }

        else if(qt==2)
        {
            int s1,i,s2,j;
            cin>>s1>>i>>s2>>j;

            q.push(-1);
            i=i-1;
            j=j-1;

            if(s1!=s2)
            {
                if(s1==1 && s2==2)
                {
                    int curr_unequal=0;


                    if(str1[i]!=str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]!=str2[j])  curr_unequal++; else curr_unequal--;

                    std::swap(str1[i],str2[j]);

                    if(str1[i]==str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]==str2[j])  curr_unequal++; else curr_unequal--;
                    
                    unequal_cnt-=curr_unequal/2;

                }
                else
                {
                    int curr_unequal=0;


                    if(str1[i]!=str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]!=str2[j])  curr_unequal++; else curr_unequal--;

                    std::swap(str1[j],str2[i]);

                    if(str1[i]==str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]==str2[j])  curr_unequal++; else curr_unequal--;
                    
                    unequal_cnt-=curr_unequal/2;
                }
            }
            else if(s1==s2)
            {
                if(s1==1)
                {
                    int curr_unequal=0;


                    if(str1[i]!=str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]!=str2[j])  curr_unequal++; else curr_unequal--;

                    std::swap(str1[i],str1[j]);

                    if(str1[i]==str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]==str2[j])  curr_unequal++; else curr_unequal--;
                    
                    unequal_cnt-=curr_unequal/2;
                }
                else if(s1==2)
                {
                    int curr_unequal=0;


                    if(str1[i]!=str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]!=str2[j])  curr_unequal++; else curr_unequal--;

                    std::swap(str2[i],str2[j]);

                    if(str1[i]==str2[i])  curr_unequal++; else curr_unequal--;
                    if(str1[j]==str2[j])  curr_unequal++; else curr_unequal--;
                    
                    unequal_cnt-=curr_unequal/2;
                }
            }

        }
        else if(qt==3)
        {
            q.push(-1);
            if(unequal_cnt==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;    
        }
 }
}
 
 
int main(){
    fastio
    w(t){
        solve();
    }
}