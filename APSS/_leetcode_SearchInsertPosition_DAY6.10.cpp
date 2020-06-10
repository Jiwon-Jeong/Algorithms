//lower_bound, upper_bound는 이진탐색기반이라 빠름

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto answer = lower_bound(nums.begin(), nums.end(), target);
		return answer - nums.begin();
	}
};