
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int test = 1;
    cin >> test;
 
    while(test--){
        int N,M,K; cin >> N >> M >> K;
        if(K >= 4){cout << 0 << endl; continue;}
        if(K == 1){cout << 1 << endl; continue;}
        int ans1 = min(M,M/N+N-1);
        if(K == 2) cout << ans1 << endl;
        if(K == 3) cout << M-ans1 << endl;
    }
}
