//lower_bound, upper_bound�� ����Ž������̶� ����

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		auto answer = lower_bound(nums.begin(), nums.end(), target);
		return answer - nums.begin();
	}
};