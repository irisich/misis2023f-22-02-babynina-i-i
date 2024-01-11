#include <iostream>
#include <string>
#include <vector>

int main() {
  int len_commands_str;
  std::cin >> len_commands_str;

  std::string commands_str;
  std::cin >> commands_str;

  std::vector<std::pair<int, int>> positions;
  positions.push_back({0, 0});
  for (char command : commands_str){
    int current_x = positions.back().first;
    int current_y = positions.back().second;
    if (command == 'U') {
      positions.push_back({ current_x, current_y + 1 });
    } else {
      positions.push_back({ current_x + 1, current_y });
    }
  }

  int answer = 0;
  int last_country = (positions[1].first > positions[1].second);
  for (int ind_position = 2; ind_position < positions.size(); ++ind_position){
    if (positions[ind_position].first != positions[ind_position].second) {
      int current_country = (positions[ind_position].first > positions[ind_position].second);

      if (last_country != current_country)
        ++answer;

      last_country = current_country;
    }
  }

  std::cout << answer;
}