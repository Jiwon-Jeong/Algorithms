#include <string>
#include <vector>
using namespace std;

//2진법으로 바꿔서 1개수 몇갠지
int count(int n) {
	int answer = 1;
	while (n >= 1) {
		if (n % 2 == 1) answer++;
		n /= 2;
	}
	return answer;
}

int solution(int n) {
	int cnt = count(n);
	int answer = n + 1;
	while (true) {
		if (cnt == count(answer)) break;
		answer++;
	}
	return answer;
}