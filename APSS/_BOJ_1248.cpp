#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> a(n + 1);
int s[11][11];
bool check(vector<int> &a) {
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (s[i][j] == '-' && sum > 0)
				return false;
			if (s[i][j] == '+' && sum < 0)
				return false;
			if (s[i][j] == '0' && sum != 0)
				return false;
		}
	}
	return true;
};

void go(int index, vector<int> &a) {

	if (index == n) {
		if (check(a)) {
			for (int i : a)
				cout << a[i] << " ";
			cout << "\n";
			return;
		}
	}

	for (int i = 1; i <= 10; i++) {
		a[index] = i;
		go(index + 1, a);
	}

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
			cin >> s[i][j];
	}
	go(0, a);
	return 0;
}