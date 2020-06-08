#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, answer = 0, i = 1;
	vector<int> fib(2);
	fib[0] = 0; fib[1] = 1;
	cin >> n;
	while (fib.back() < n) {
		fib.push_back(fib[i - 1] + fib[i]);
		i++;
	}
	for (int i : fib) {
		if (i % 2 == 0)
			answer += i;
	}
	cout << answer << endl;
	return 0;
}