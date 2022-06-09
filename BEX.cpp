#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;
	stack<pair<int, pair<string,int>> > s;
	while(n--){
	    ll q;
	    cin>>q;
	    if(q==-1){
	       cout<<s.top().first<<" "<<s.top().second.first<<endl;
	       s.pop();
	    }
	    else{
	        string name;
	        cin>>name;
	        if(q==0){
	            continue;
	        }
	        else{
	            if(s.empty() || q<=s.top().second.second){
	               s.push({0,{name,q}});
	            }
	            else{
	                s.top().first++;
	            }
	        }
	    }
	}
	return 0;
}
