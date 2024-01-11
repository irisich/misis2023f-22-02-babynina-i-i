#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int len = 0;
  int left = 0;
  int right = 0;
  int different = 0;
  std::cin >> len >> left >> right >> different;

  std::vector<int> complexity_tasks(len);
  for (int& complexity_task : complexity_tasks)
    std::cin >> complexity_task;

  int cnt_variants = 0;
  for (int mask = 0; mask < (1 << len); ++mask) {
    int sum_hards = 0;
    int max_hards = 0;
    int min_hards = INT_MAX;
    for (int ind_task = 0; ind_task < len; ++ind_task) {
      if (mask & (1 << ind_task)) {
        sum_hards += complexity_tasks[ind_task];
        max_hards = std::max(max_hards, complexity_tasks[ind_task]);
        min_hards = std::min(min_hards, complexity_tasks[ind_task]);
      }
    }

    if (left <= sum_hards && sum_hards <= right && max_hards - min_hards >= different) {
      ++cnt_variants;
    }
  }
  std::cout << cnt_variants;
}