class Solution {
public:
	int singleNumber(std::vector<int>& nums) {
		return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor{});
	}
};

// Second Approach
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		while (nums.size() > 1) {
			if (nums[0] == nums[1]) {
				nums.erase(nums.begin());
				nums.erase(nums.begin());
			}
			else return nums[0];
		}
		return nums.back();
	}
};