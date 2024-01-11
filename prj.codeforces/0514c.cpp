#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

struct Node
{
	Node(char _ch)
	{
		ch = _ch;
		childrens['a'] = childrens['b'] = childrens['c'] = NULL;
	}

	char ch;
	std::map<char, Node*> childrens;
	std::set<unsigned long long> in_this_tree;
};

void insert(Node* node, unsigned long long hash, int pos, std::string& s, 
	std::vector<unsigned long long>& st, std::map<char, int>& ord)
{
	if (pos == s.size())
		return;

	node->in_this_tree.insert(hash);
	hash -= ord[s[pos]] * st[s.size() - pos - 1];

	if (pos == s.size() - 1)
		return;
	++pos;

	if (node->childrens[s[pos]] == NULL)
		node->childrens[s[pos]] = new Node(s[pos]);

	insert(node->childrens[s[pos]], hash, pos, s, st, ord);
}

bool check(Node* node, unsigned long long hash, int pos, std::string& s,
	std::vector<unsigned long long>& st, std::map<char, int>& ord)
{
	if (pos == s.size() - 1)
		return false;

	for (auto it : node->childrens) if (it.second != NULL && it.first != s[pos + 1])
	{
		if (pos < s.size() - 2)
		{
			Node* tmp = it.second->childrens[s[pos + 2]];
			unsigned long long new_hash = hash - ord[s[pos]] * st[s.size() - pos - 1] - ord[s[pos + 1]] * st[s.size() - (pos + 1) - 1];
			if (tmp != NULL && tmp->in_this_tree.find(new_hash) != tmp->in_this_tree.end())
				return true;
		}
		else
			return true;
	}

	Node* next = node->childrens[s[pos + 1]];
	if (next == NULL)
		return false;
	else
		return check(next, hash - ord[s[pos]] * st[s.size() - pos - 1], pos + 1, s, st, ord);
}

void clear(Node* node)
{
	if (node == NULL)
		return;

	clear(node->childrens['a']);
	clear(node->childrens['b']);
	clear(node->childrens['c']);

	delete node;
}

int main()
{
	std::map<char, int> ord;
	ord['#'] = 1;
	ord['a'] = 2;
	ord['b'] = 3;
	ord['c'] = 4;

	std::vector<unsigned long long> st(6e5);
	st[0] = 1;
	for (int i = 1; i < st.size(); ++i)
		st[i] = st[i - 1] * 5;

	Node* tree = new Node('#');

	int n, m;
	std::cin >> n >> m;
	while (n--)
	{
		std::string s;
		{
			std::string tmp;
			std::cin >> tmp;
			s = '#' + tmp;
		}

		unsigned long long hash = 0;
		for (int i = 0; i < s.size(); ++i)
			hash += ord[s[i]] * st[s.size() - i - 1];

		insert(tree, hash, 0, s, st, ord);
	}

	while (m--)
	{
		std::string s;
		{
			std::string tmp;
			std::cin >> tmp;
			s = '#' + tmp;
		}

		unsigned long long hash = 0;
		for (int i = 0; i < s.size(); ++i)
			hash += ord[s[i]] * st[s.size() - i - 1];

		if (check(tree, hash, 0, s, st, ord))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}

	clear(tree);
}