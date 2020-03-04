/* TRIANGLEPATH 반대로 연산한 버전 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int n = triangle.size();
	vector<vector<int>> tmp(triangle.size(), vector<int>(triangle.size()));

	tmp[0][0] = triangle[0][0];

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0) {
				tmp[i][j] = tmp[i - 1][j] + triangle[i][j];
			}
			else if (i == j)
				tmp[i][j] = tmp[i - 1][j - 1] + triangle[i][j];
			else {
				tmp[i][j] = max(tmp[i - 1][j - 1], tmp[i - 1][j]) + triangle[i][j];
			}
			if (i == n - 1)
				answer = max(answer, tmp[i][j]);
		}
	}

	return answer;
}