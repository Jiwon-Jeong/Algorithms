#include <limits>
class Solution {
public:
	int reverse(int x) {
		long long answer = 0;
		while (x != 0) {
			answer *= 10;
			answer += x % 10;
			x /= 10;
		}
		if (answer<INT_MIN || answer>INT_MAX) return 0;
		return answer;
	}
};