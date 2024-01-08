#include <iostream>
#include <vector>
 
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> rem(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        int num(0);
        std::cin >> num;
        rem[num] = i;
    }
    for (int i = 1; i < n + 1; ++i) {
        std::cout << rem[i] << ' ';
    }
}
