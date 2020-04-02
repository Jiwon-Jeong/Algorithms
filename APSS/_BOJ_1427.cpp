#include <iostream>
#include <string>
using namespace std;

inline void ShowArray(const string& s, int);

void InsertSort(string& s, int len)
{
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j > 0; j--) 
		{
			if (s.at(j - 1) < s.at(j)) break;
			swap(s.at(j), s.at(j - 1));
		}
	}
}

inline void ShowArray(const string& s)
{
	for (int i = s.size() - 1; i >= 0; i--)
		cout << s.at(i);
}
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	string str;
	cin >> str;
	InsertSort(str, str.size());
	ShowArray(str);
	return 0;
}

