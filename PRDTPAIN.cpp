#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using ll = long long int;
using namespace std;

vector <ll> v;



int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n;
        vector <ll> a;
        for(int i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        vector <ll> sub;
        ll ans = 0;
        for(int i=0;i<n;i++){
            sub.clear();
            //[1] [1,2] [1,2,3] [1,2,3,4] i = 0
            // [2] [2,3] [2,3,4]
            
            for(int j=i;j<n;j++){
                sub.push_back(a[j]);
                int nn = sub.size();
                if(nn>=3){
                    ll val = (sub[0]+sub[nn-1])/2;
                    int pos1 = upper_bound(sub.begin(),sub.end(),val) - sub.begin();
                    int pos2 = lower_bound(sub.begin(),sub.end(),val) - sub.begin();
                    int pos3 = pos2-1;
                    ll ele = -1;
                    if(0<=pos1 && pos1<=nn-1){
                        ll cal = (sub[nn-1]-sub[pos1])*(sub[pos1]-sub[0]);
                        ele = max(ele, cal);
                    }
                    if(0<=pos2 && pos2<=nn-1){
                        ll cal = (sub[nn-1]-sub[pos2])*(sub[pos2]-sub[0]);
                        ele = max(ele, cal);
                    }
                    if(0<=pos3 && pos3<=nn-1){
                        ll cal = (sub[nn-1]-sub[pos3])*(sub[pos3]-sub[0]);
                        ele = max(ele, cal);
                    }
                    ans += ele;
                }
            }
            
        }
        cout<<ans<<"\n";

    }

    
}