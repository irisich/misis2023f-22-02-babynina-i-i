#include <bits/stdc++.h>
using i64 = long long;
void solve() {
  i64 n, m;
  std::cin >> n >> m;
  std::vector<std::vector<i64>> c(n, std::vector<i64>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> c[i][j];
    }
  }
  i64 ans = 0;
  for (int j = 0; j < m; j++) {
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = c[i][j];
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      ans += (2 * i - n + 1) * a[i];
    }
  }
  std::cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
