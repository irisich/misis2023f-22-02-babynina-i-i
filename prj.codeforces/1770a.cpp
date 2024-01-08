#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
 
void solve() {
 
    int n, m;
    long long s = 0;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        sort(a.begin(), a.end());
        cin >> a[0];
    }
    for (int i = 0; i < n; ++i) {
        s += a[i];
    }
    cout << s << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
