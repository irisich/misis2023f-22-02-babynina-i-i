#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
 
int max(int l, int r) {
    return (l > r) ? l : r;
}
int min(int l, int r) {
    return (l < r) ? l : r;
}
 
 
int main() {
    int n = 0;
    int x = 0;
    std::cin >> n >> x;
    int c = 0;
    int cur = 0;
    for (int i = 1; i * i < x; ++i) {
        if (x % i == 0 && x / i <= n) {
            c += 2;
        }
        cur = i;
    }
    if ((cur + 1) * (cur + 1) == x && cur + 1 <= n) {
        ++c;
    }
    std::cout << c;
    return 0;
}
