class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int len = 0, answer = 0;
		for (auto i : nums) {
			len = to_string(i).length();
			if (len % 2 == 0)
				answer++;
		}
		return answer;
	}
};