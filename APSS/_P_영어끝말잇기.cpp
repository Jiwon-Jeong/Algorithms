#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<string> all;
	vector<string> v[n];
	char last = '0';
	for (int i = 0; i < words.size(); i++) {
		//마지막 글자가 다르면 실패
		if (i != 0 && last != words[i][0]) {
			answer.push_back(i%n + 1);
			answer.push_back(i / n + 1);
			break;
		}
		//했던말 또하면 실패 
		vector<string>::iterator it;
		it = find(all.begin(), all.end(), words[i]);
		if (it != all.end()) {
			answer.push_back(i%n + 1);
			answer.push_back(i / n + 1);
			break;
		}

		v[i%n].push_back(words[i]);
		last = words[i][words[i].length() - 1];
		all.push_back(words[i]);
	}

	if (answer.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}