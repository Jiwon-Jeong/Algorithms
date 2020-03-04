#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0; //������ ���� ����
	bool flag = true;
	string tmp = "";
	string str = "";

	for (int i = 123; i <= 987; i++) { //����� �� �����ϴ��� �� �غ���
		tmp = to_string(i);

		//���� ���ڷ� �����ǰų� 0�� ���� �н�
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
			continue;
		else if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
			continue;

		flag = true;
		// �־��� ���� �����ϴ��� ���ڿ� ��
		for (int j = 0; j < baseball.size(); ++j) {
			int strCnt = 0, ballCnt = 0;
			str = to_string(baseball[j][0]);
			//strike ���� �´���
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					//strike ����
					if (x == y && tmp[x] == str[y])
						strCnt++;
					//ball ����
					if (x != y && tmp[x] == str[y])
						ballCnt++;
				}
			}
			// strike, ball ���� �ٸ��� �ٷ� ����
			if (strCnt != baseball[j][1] || ballCnt != baseball[j][2]) {
				flag = false;
				break;
			}
		}
		// �־��� ���ö� �� �� �ؼ� �����ϴ°� Ȯ���ϸ� answer++
		if (flag == true)
			answer++;
	}

	return answer;

}