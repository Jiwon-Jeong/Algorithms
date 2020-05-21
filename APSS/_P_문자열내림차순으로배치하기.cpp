#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<char> v1;
	vector<char> v2;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A') v2.push_back(s[i]);
		else v1.push_back(s[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = v1.size() - 1; i >= 0; i--) {
		answer += v1[i];
	}
	for (int i = v2.size() - 1; i >= 0; i--) {
		answer += v2[i];
	}
	return answer;
}