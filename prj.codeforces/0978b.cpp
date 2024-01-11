#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'x')
			++cnt;
		else
		{
			ans += std::max(0, cnt - 2);
			cnt = 0;
		}
	}
	ans += std::max(0, cnt - 2);
	std::cout << ans;
}