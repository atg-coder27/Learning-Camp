#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >>n >>m;

    vector<pair<int, int>> a(n);
    vector<pair<int, int>> b(m);

    for(int i = 0; i<n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    for(int i = 0; i<m; ++i){
        cin >> b[i].first;
        b[i].second = i;
    }

    sort( a.begin(), a.end());
    sort( b.begin(), b.end() );

    for( int i = 0; i<n; ++i ){
        cout << i <<" "<<b[0].second<<"\n";
    }

    for( int i=1; i<m; ++i ){
        cout << a[n-1].second << " "<< b[i].second<<"\n";
    }

    return 0;
}