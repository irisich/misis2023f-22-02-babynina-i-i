#include <iostream>
#include <vector>
#include <algorithm>
 
void solve() {
    int n = 0;
    std::cin >> n;
    int ans = 0;
    while (n > 0) {
        if (n & 1) {
            ++ans;
        }
        n >>= 1;
    }
    std::cout << ans;
}
 
int main()
{
    int t = 1;
    while (t--) {
        solve();
    }
}
