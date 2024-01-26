#include <bits/stdc++.h>

using namespace std;

int main()
{    
    
    int n;
    cin>>n;

    vector<pair<string,pair<string,float>>> transaction(n);


    for(int i=0;i<n;i++)
    {
        cin>>transaction[i].first;
        cin>>transaction[i].second.first;
        cin>>transaction[i].second.second;
    }

    float initalBalance=100;

    map<string,float> balance;
    balance["A"]=initalBalance;
    for(int i=0;i<transaction.size();i++)
    {
        string src=transaction[i].first;
        string desc=transaction[i].second.first;
        float pert=transaction[i].second.second;

        if(balance[src]>=(pert/100) * balance[src]){
        //destination user balance
        balance[desc]= balance[desc]+(pert/100) * balance[src];

        //source user balance
        balance[src]=balance[src]-(pert/100) * balance[src];
        }
    }

    for(auto [user,bal]:balance)
    {
        cout<<user<<" -> "<<bal<<endl;
    }



    return 0;
}