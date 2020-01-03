// Programmers-완전탐색-카펫
#include <string>
#include <vector>

using namespace std;
/* comb: 가능한 조합 모두 구하기 */
vector<int> comb(int n) {
	vector<int> ret;
	int i;
	for (i = 1; i*i <= n; ++i) {
		if (n%i == 0) {
			ret.push_back(n / i);
			ret.push_back(i);
		}
	}
	return ret;
}

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int size = comb(red).size();
	int a = 0, b = 0;

	for (int i = 0; i < size - 1; i += 2) {
		a = comb(red)[i] + 2;
		b = comb(red)[i + 1] + 2;

		if (a*b == (brown + red)) {
			answer.push_back(a);
			answer.push_back(b);
			break;
		}
	}

	return answer;
}