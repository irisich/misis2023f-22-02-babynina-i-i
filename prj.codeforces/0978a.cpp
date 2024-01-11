#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int& i : a)
		std::cin >> i;

	std::vector<int> r_ans;
	for (int i = n - 1; i >= 0; --i)
	{
		bool is_in = false;
		for (int j : r_ans)
			if (j == a[i])
			{
				is_in = true;
				break;
			}
		if (!is_in)
			r_ans.push_back(a[i]);
	}
	std::cout << r_ans.size() << std::endl;
	for (int i = r_ans.size() - 1; i >= 0; --i)
		std::cout << r_ans[i] << " ";

}