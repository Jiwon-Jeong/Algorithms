#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

string str;
const int INF = 987654321;
int cache[10002];

int classify(int start, int end) {
	string tmp = str.substr(start, end - start + 1);

	if (tmp == string(tmp.size(), tmp[0])) return 1;

	bool progressive = true;
	for (int i = 0; i < tmp.size() - 1; ++i)
		if (tmp[i + 1] - tmp[i] != tmp[1] - tmp[0])
			progressive = false;

	if (progressive && abs(tmp[1] - tmp[0]) == 1)
		return 2;

	bool alternating = true;
	for (int i = 0; i < tmp.size(); ++i)
		if (tmp[i] != tmp[i % 2])
			alternating = false;
	if (alternating) return 4;
	if (progressive)return 5;
	return 10;
}

int pi(int start) {
	//B: 마지막 자리면
	if (start == str.size()) return 0;

	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = INF;
	for (int L = 3; L <= 5; L++) {
		if (start + L <= str.size())
			ret = min(ret, pi(start + L) + classify(start, start + L - 1));
		
	}
	return ret;
}


void main() {
	int c;
	list<int> answers;
	cin >> c;
	while (c-- > 0) {
		memset(cache, -1, sizeof(cache));
		cin >> str;

		answers.push_front(pi(0));
	}

	for (int answer : answers) {
		cout << answer << endl;
	
	}
	
}