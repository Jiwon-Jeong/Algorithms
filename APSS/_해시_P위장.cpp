#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	int tmp;
	map<string, int> m;
	for (vector<string> i : clothes)
		m[i[1]]++;
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		answer *= (iter->second + 1);
	}
	return answer - 1;
}