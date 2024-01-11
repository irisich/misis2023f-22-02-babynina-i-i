#include <iostream>
#include <vector>
#include <set>

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main(){
  int n_points = 0;
  int gun_pos_x = 0;
  int gun_pos_y = 0;
  std::cin >> n_points >> gun_pos_x >> gun_pos_y;

  std::set<std::pair<int, int>> set_of_k;
  for (int ind_enemys = 0; ind_enemys < n_points; ++ind_enemys) {
    int enemys_pos_x = 0;
    int enemys_pos_y = 0;
    std::cin >> enemys_pos_x >> enemys_pos_y;
    enemys_pos_x -= gun_pos_x;
    enemys_pos_y -= gun_pos_y;

    if (enemys_pos_x == 0){
      set_of_k.insert({ 0, 0 });
    }
    else{
      int gcd_coordinats = gcd(enemys_pos_x, enemys_pos_y);
      set_of_k.insert({ enemys_pos_x / gcd_coordinats, enemys_pos_y / gcd_coordinats });
    }
  }

  std::cout << set_of_k.size();
}