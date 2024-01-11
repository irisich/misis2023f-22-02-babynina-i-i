#include <iostream>
#include <vector>
#include <algorithm>

struct Laptop {
  int price = 0;
  int quality = 0;
};

int main()
{
  int n_laptops = 0;
  std::cin >> n_laptops;

  std::vector<Laptop> laptops;
  for (int i_laptop = 0; i_laptop < n_laptops; ++i_laptop){
    int price = 0;
    int quality = 0;
    std::cin >> price >> quality;

    laptops.push_back({price, quality});
  }
  
  std::sort(laptops.begin(), laptops.end(), 
    [](const Laptop& first, const Laptop& second) -> bool {
      return first.price < second.price; 
    });

  bool is_Alex_happy = false;
  for (int i_laptop = 1; i_laptop < n_laptops && !is_Alex_happy; ++i_laptop)
    is_Alex_happy = laptops[i_laptop - 1].quality > laptops[i_laptop].quality;

  std::cout << (is_Alex_happy ? "Happy Alex" : "Poor Alex");
}