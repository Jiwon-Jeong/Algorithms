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
		for (int i = 0; i < n; i++) { // �Է��� �޴� �κ�
			string __name__; string kind; // name�� ������ �ʽ��ϴ�.
			cin >> __name__ >> kind;
			if (data.find(kind) == data.end()) { // �����Ͱ� ���� ���
				data.insert({ kind,1 });
			}
			else { // �����Ͱ� �ִ� ���
				data[kind]++;
			}

		}
		int result = 1; // ������ ���� �ʱⰪ
		for (auto kind : data) {
			// second�� �ش� ������ ������ ���� ��
			result *= (kind.second + 1);
		}
		result -= 1; // ��ΰ� None�� ���̽� ����
		cout << result << endl;
	}
	return 0;
}