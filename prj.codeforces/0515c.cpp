#include <iostream>
#include <string>
#include <vector>

int GetPrimeFromInd(int index) {
  switch (index){
  case 0:
    return 2;
  case 1:
    return 3;
  case 2:
    return 5;
  case 3:
    return 7;
  }
}

void init_prime_factorization_cnts(std::vector<int>& prime_factorization_cnts, int n_didgits) {
  for (int i_didgit = 0; i_didgit < n_didgits; ++i_didgit) {
    char char_didgit = '\0';
    std::cin >> char_didgit;

    int didgit = char_didgit - '0';
    for (int current_multiplier = 2; current_multiplier <= didgit; ++current_multiplier) {
      int copy_current_multiplier = current_multiplier;
      for (int i_prime = 0; i_prime < prime_factorization_cnts.size(); ++i_prime)
        while (copy_current_multiplier % GetPrimeFromInd(i_prime) == 0) {
          ++prime_factorization_cnts[i_prime];
          copy_current_multiplier /= GetPrimeFromInd(i_prime);
        }
    }
  }
}

int main(){
  int n_didgits = 0;
  std::cin >> n_didgits;

  std::vector<int> prime_factorization_cnts(4);
  init_prime_factorization_cnts(prime_factorization_cnts, n_didgits);

  for (int i_prime = prime_factorization_cnts.size() - 1; i_prime >= 0; --i_prime) {
    std::cout << std::string(prime_factorization_cnts[i_prime], '0' + GetPrimeFromInd(i_prime));
    switch (i_prime){
    case 0:
      prime_factorization_cnts[0] -= 1 * prime_factorization_cnts[i_prime];
    break;
    case 1:
      prime_factorization_cnts[0] -= 1 * prime_factorization_cnts[i_prime];
      prime_factorization_cnts[1] -= 1 * prime_factorization_cnts[i_prime];
    break;
    case 2:
      prime_factorization_cnts[0] -= 3 * prime_factorization_cnts[i_prime];
      prime_factorization_cnts[1] -= 1 * prime_factorization_cnts[i_prime];
      prime_factorization_cnts[2] -= 1 * prime_factorization_cnts[i_prime];
    break;
    case 3:
      prime_factorization_cnts[0] -= 4 * prime_factorization_cnts[i_prime];
      prime_factorization_cnts[1] -= 2 * prime_factorization_cnts[i_prime];
      prime_factorization_cnts[2] -= 1 * prime_factorization_cnts[i_prime];
      prime_factorization_cnts[3] -= 1 * prime_factorization_cnts[i_prime];
    break;
    }
  }
}