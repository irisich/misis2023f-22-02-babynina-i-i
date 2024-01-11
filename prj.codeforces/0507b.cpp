#include <iostream>
#include <cmath>

class Coords {
public:
  unsigned long long int srt_len(const Coords& other) const {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
  }

  long long int x = 0;
  long long int y = 0;
};

int main() {
  long long int radius = 0;
  Coords start;
  Coords end;

  std::cin >> radius >> start.x >> start.y >> end.x >> end.y;

  long long int len = ceil(sqrt(start.srt_len(end)));
  std::cout << len / (2 * radius) + (len % (2 * radius) != 0);
}