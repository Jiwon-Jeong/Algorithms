#include <string>
#include <vector>
#include<algorithm>
#include<functional> // �Լ� ������ ������ ���
using namespace std;

bool checkNum(int, string);

int solution(string numbers) {
	int answer = 0;
	vector<int> number;

	//numbers ���ڿ��� ������������ ����
	sort(numbers.begin(), numbers.end(), greater<int>());

	vector<bool> temp(stoi(numbers) + 1);

	//2���� �ش� ���ڱ��� �Ҽ� ���� ã���ž�
	for (int i = 2; i <= stoi(numbers); i++) {
		// ���� ã�� ���̰�, numbers�� ���ϴ� ���ڷ� �����Ǹ�
		if (temp[i] == false && checkNum(i, numbers)) {
			answer++;
		}
		// �� �Ҽ��� ������� ��� true�� - �Ҽ��ƴѰ� ���� �н� ����
		if (temp[i] == false) {
			for (int j = i; j <= stoi(numbers); j += i) {
				temp[j] = true;
			}
		}
	}
	return answer;
}

/* i�� numbers�� ���ϴ��� �Ǻ��ϴ� �Լ�*/
bool checkNum(int i, string numbers) {
	bool flag = false;
	// ���� �湮 �ߴ��� Ȯ�� ����
	vector<bool> visit(numbers.length());
	while (i != 0) {
		flag = false;
		int temp = i % 10; // ������ �ڸ� �� 
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


