#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using ll = long long int;
using namespace std;

vector <ll> gap;



int main()
{
    ios_base::sync_with_stdio(0);
    int sumn = 0;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        sumn += n;
        string a;
        cin >> a;
        assert(a.length() == n);
        int cost01 = 0;
        int cost10 = 0;
        for(int i=0;i<n;i++){
            if (i % 2 == 0) {
                if (a[i] == '0') cost10++;
                else cost01++;
            } else {
                if (a[i] == '0') cost01++;
                else cost10++;
            }
        }
        if (min(cost01, cost10) <= k) {
            cout << 1 << endl;
            continue;
        }

        vector <ll> runs;
        int run_len = 1;
        for(int i=1;i<=n-1;i++) {
            if (a[i] != a[i-1]) {
                runs.push_back(run_len);
                run_len = 1;
            } else {
                run_len++;
            }
        }
        runs.push_back(run_len);
        int lo = 2, hi = n;
        int res = n;
        while (lo <= hi) {
            int block_size = (lo+hi)/2;
            int cost = 0;
            for (int len : runs) {
                cost += len / (block_size+1);
            }
            if (cost <= k) {
                res = min(res, block_size);
                hi = block_size-1;
            } else {
                lo = block_size+1;
            }
        }
        cout << res << endl;
    }

    return 0;
}