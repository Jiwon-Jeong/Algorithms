#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int n, m,  A[100], B[100];
int cache[101][101];
const long long NEGINF = numeric_limits<long long>::min();

int jlis(int indexA, int indexB) {

	int& ret = cache[indexA+1][indexB+1];
	if (ret != -1) return ret;

	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; ++nextA) 
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);

	for (int nextB = indexB + 1; nextB < n; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);


	return ret;
}

void main() {

	list<int> answers;
	int C;
	cin >> C;
	while (C-- > 0) {
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}

		for (int i = 0; i < m; ++i) {
			cin >> B[i];
		}
		answers.push_front(jlis(-1, -1) - 2);
	}

	for (int answer : answers) {
		cout << answer << endl;
	}
	
}