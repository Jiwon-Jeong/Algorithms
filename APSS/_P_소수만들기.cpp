#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
bool prime[50000];
bool check(int d) {
	for (int i = 2; i <= sqrt(d); i++) {
		if (d%i == 0) {
			return false;
		}
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;
	int len = nums.size();

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			for (int k = j + 1; k < len; k++) {
				if (check(nums[i] + nums[j] + nums[k])) {
					answer++;
				}
			}
		}
	}

	return answer;
}