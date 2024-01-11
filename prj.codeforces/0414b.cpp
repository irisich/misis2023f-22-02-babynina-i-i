#include <iostream>
#include <vector>

int main() {
  const long long int mod = 1000000007;

  int n = 0;
  int k = 0;

  std::cin >> n >> k;

  std::vector<std::vector<int>> dividers(n + 1);
  for (int current_n = 1; current_n <= n; ++current_n) {
    for (int current_divider = 1; current_divider <= n; ++current_divider) {
      if (current_n % current_divider == 0) {
        dividers[current_n].push_back(current_divider);
      }
    }
  }

  std::vector<std::vector<long long>> dp_table(n + 1);
  for (auto& i : dp_table) {
    i.resize(k + 1, 1);
  }

  for (int current_k = 2; current_k <= k; ++current_k) {
    for (int current_n = 2; current_n <= n; ++current_n) {
      long long int sum = 0;
      for (int current_divider : dividers[current_n]) {
        sum = (sum + dp_table[current_divider][current_k - 1]) % mod;
      }
      dp_table[current_n][current_k] = sum;
    }
  }

  long long int answer = 0;
  for (int current_n = 1; current_n <= n; ++current_n) {
    answer = (answer + dp_table[current_n][k]) % mod;
  }

  std::cout << answer;
}