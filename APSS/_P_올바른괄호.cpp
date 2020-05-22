#include<string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int l = 0, r = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			l++;
		else r++;

		if (r > l) return false;
	}
	if (r != l) return false;
	return answer;
}