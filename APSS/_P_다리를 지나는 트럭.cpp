#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int now_weight = 0;
	int tmp = 0;
	queue<int> q;
	for (int i = 0; i < truck_weights.size(); i++) {
		tmp = truck_weights[i];
		while (1) {
			if (q.empty()) {
				q.push(tmp);
				now_weight += tmp;
				answer++;
				break;
			}
			else if (q.size() == bridge_length) {
				now_weight -= q.front();
				q.pop();
			}
			else {
				if (tmp + now_weight > weight) {
					q.push(0);
					answer++;
				}
				else {
					q.push(tmp);
					now_weight += tmp;
					answer++;
					break;
				}
			}

		}
	}

	return answer + bridge_length;
}