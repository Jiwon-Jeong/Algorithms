#include <string>
#include <vector>
#include<algorithm>
#include<functional> // 함수 포인터 때문에 사용
using namespace std;

bool checkNum(int, string);

int solution(string numbers) {
	int answer = 0;
	vector<int> number;

	//numbers 문자열을 내림차순으로 정렬
	sort(numbers.begin(), numbers.end(), greater<int>());

	vector<bool> temp(stoi(numbers) + 1);

	//2부터 해당 숫자까지 소수 개수 찾을거야
	for (int i = 2; i <= stoi(numbers); i++) {
		// 새로 찾은 수이고, numbers에 속하는 숫자로 구성되면
		if (temp[i] == false && checkNum(i, numbers)) {
			answer++;
		}
		// 그 소수의 배수들을 모두 true로 - 소수아닌거 빨리 패스 위해
		if (temp[i] == false) {
			for (int j = i; j <= stoi(numbers); j += i) {
				temp[j] = true;
			}
		}
	}
	return answer;
}

/* i가 numbers에 속하는지 판별하는 함수*/
bool checkNum(int i, string numbers) {
	bool flag = false;
	// 숫자 방문 했는지 확인 위해
	vector<bool> visit(numbers.length());
	while (i != 0) {
		flag = false;
		int temp = i % 10; // 마지막 자리 수 
		for (int j = 0; j <= numbers.length(); j++) {
			if (temp == numbers[j] - '0' && visit[j] == 0) {
				flag = true;
				visit[j] = 1;
				break;
			}
		}
		if (flag == false) return false;
		i /= 10;
	}
	return true;
}


