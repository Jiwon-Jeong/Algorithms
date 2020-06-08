#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	int c = 0;
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			v.push_back(stoi(s.substr(c, i)));
			c = i + 1;
		}
	}
	v.push_back(stoi(s.substr(c, s.size())));
	sort(v.begin(), v.end());
	answer = to_string(v.front()) + " " + to_string(v.back());
	return answer;
}