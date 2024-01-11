#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<deque>

using namespace std;
const int N = 105;
int n, dp[N][N][2], a[N];
int solve(int i, int sum, bool parity) {
  if (i == n) return (sum >= 0 ? parity ? 1e9 : 0 : 1e9);
  if (dp[i][sum][parity] != -1) return dp[i][sum][parity];
  int ans = 1e9;
  for (int j = -1; j <= 1; j += 2)
    ans = min(ans, solve(i + 1, sum + j, parity ^ (j < 0)) + (a[i] != j));
  return dp[i][sum][parity] = ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) << '\n';
  }
  return 0;
}
