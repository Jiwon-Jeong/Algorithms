#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main(void) {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		unordered_map<string, int> data;
		int n; cin >> n;
		for (int i = 0; i < n; i++) { // 입력을 받는 부분
			string __name__; string kind; // name은 사용되지 않습니다.
			cin >> __name__ >> kind;
			if (data.find(kind) == data.end()) { // 데이터가 없는 경우
				data.insert({ kind,1 });
			}
			else { // 데이터가 있는 경우
				data[kind]++;
			}

		}
		int result = 1; // 곱셈을 위한 초기값
		for (auto kind : data) {
			// second는 해당 종류가 가지는 가짓 수
			result *= (kind.second + 1);
		}
		result -= 1; // 모두가 None인 케이스 제외
		cout << result << endl;
	}
	return 0;
}