class Solution {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int idx = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (i + 2 < nums.size() && nums[i] == nums[i + 2]) {
				i += 2;
			}
			else {
				idx = i; break;
			}
		}
		if (idx == -1) idx = nums.size() - 1;
		return nums[idx];
	}
};