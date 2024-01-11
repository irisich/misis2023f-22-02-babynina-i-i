#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string exponats_name;
  std::cin >> exponats_name;

  int answer = 0;
  char last_letter = 'a';
  for (char current_letter : exponats_name) {
    answer += std::min(std::abs(current_letter - last_letter), 
                       std::min(std::abs(current_letter + 26 - last_letter), std::abs(current_letter - 26 - last_letter)));
    last_letter = current_letter;
  }

  std::cout << answer;
}