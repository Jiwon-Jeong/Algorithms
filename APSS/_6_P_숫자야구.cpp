#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0; //가능한 값의 갯수
	bool flag = true;
	string tmp = "";
	string str = "";

	for (int i = 123; i <= 987; i++) { //입출력 예 만족하는지 다 해보기
		tmp = to_string(i);

		//같은 숫자로 구성되거나 0이 들어가면 패스
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
			continue;
		else if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
			continue;

		flag = true;
		// 주어진 조건 만족하는지 문자열 비교
		for (int j = 0; j < baseball.size(); ++j) {
			int strCnt = 0, ballCnt = 0;
			str = to_string(baseball[j][0]);
			//strike 조건 맞는지
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					//strike 조건
					if (x == y && tmp[x] == str[y])
						strCnt++;
					//ball 조건
					if (x != y && tmp[x] == str[y])
						ballCnt++;
				}
			}
			// strike, ball 수와 다르면 바로 종료
			if (strCnt != baseball[j][1] || ballCnt != baseball[j][2]) {
				flag = false;
				break;
			}
		}
		// 주어진 예시랑 비교 다 해서 만족하는거 확인하면 answer++
		if (flag == true)
			answer++;
	}

	return answer;

}