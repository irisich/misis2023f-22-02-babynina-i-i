#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int len = 0;
  std::cin >> len;

  std::vector<unsigned long long int> first_line(len);
  std::vector<unsigned long long int> second_line(len);
  for (unsigned long long int& current_player : first_line){
    std::cin >> current_player;
  }
  for (unsigned long long int& current_player : second_line) {
    std::cin >> current_player;
  }

  std::vector<std::pair<unsigned long long int, unsigned long long int>> table_dp(len);
  table_dp[0].first = first_line[0];
  table_dp[0].second = second_line[0];
  for (int ind_col = 1; ind_col < len; ++ind_col){
    table_dp[ind_col].first = std::max(table_dp[ind_col - 1].first, table_dp[ind_col - 1].second + first_line[ind_col]);
    table_dp[ind_col].second = std::max(table_dp[ind_col - 1].second, table_dp[ind_col - 1].first + second_line[ind_col]);
  }

  std::cout << std::max(table_dp.back().first, table_dp.back().second);
}