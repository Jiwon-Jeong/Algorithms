#include<iostream>
#include <string>
#include <vector>
using namespace std;
bool c[10];
char boo[10];
int k;
vector<string> ans;
bool ok(string str) {
	for (int i = 0; i < k; i++) {
		if (boo[i] == '>' &&  str[i] < str[i + 1])
			return false;
		if (boo[i] == '<' &&  str[i] > str[i + 1])
			return false;
	}
	return true;
}

void find(int index,  string current) {
	// 정답인 경우
	if (index == k + 1) {
		//최대, 최소 업데이트
		if (ok(current)) {
			ans.push_back(current);
		}
		return;
	}
	
	for (int i = 0; i < 10; i++) {
		if (c[i]) continue;
		c[i] = true;
		find(index + 1, current + to_string(i));
		c[i] = false;
	}
}
int main() {
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> boo[i];
	}
	find(0, "");
	string max = "";
	string min = "9999999999";
	for (int i = 0; i <ans.size(); i++) {
		if (ans[i] > max) max = ans[i];
		if (ans[i] < min) min = ans[i];

	}
	cout << max << "\n";
	cout << min << "\n";
}