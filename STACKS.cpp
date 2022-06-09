#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using ll = long long int;
using namespace std;

vector <ll> v;


int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,a;
        cin>>n;
        vector <ll> v;
        
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }

        vector<ll> stack ;
        for(int i=0;i<v.size();i++){
            int pos = upper_bound(stack.begin(),stack.end(),v[i]) - stack.begin();
            if(pos == stack.size()){
                stack.push_back(v[i]);
            }
            else{
                stack[pos] = v[i];
            }
        }
        cout<<stack.size()<<" ";
        for(int i:stack){
            cout<<i<<" ";
        }
        cout<<"\n";
    }


    
}