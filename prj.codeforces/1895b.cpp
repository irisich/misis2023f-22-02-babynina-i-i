#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());
    std::cout << vec[n - 1] - vec[0] + vec[2 * n - 1] - vec[n] << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << vec[i] << ' ' << vec[i + n] << std::endl;
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
