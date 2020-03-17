#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

	int n, c;
	cin >> n >> c;
	cin.ignore();
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	string result = "<";

	while (q.size()>1) {

		for (int j = 0; j < c-1; j++) {
			q.push(q.front());
			q.pop();
		}
		result += to_string(q.front());
		result += ", ";
		q.pop();
	}

	result += to_string(q.front());
	result += ">";
	cout << result << '\n';
	return 0;
}