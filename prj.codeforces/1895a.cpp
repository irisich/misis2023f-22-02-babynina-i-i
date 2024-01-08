#include <iostream>
#include <algorithm>
#include <cmath>

void solve() {
    int c, k, t;
    std::cin >> c >> k >> t;
    if (c < k) {
        c += std::min(t, k - c);
        std::cout << 2 * k - c << std::endl;
    }
    else {
        std::cout << c << std::endl;
    }
}

int main()
{
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}
