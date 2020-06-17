class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int time = k % nums.size();
		int tmp = 0;
		while (time--) {
			tmp = nums.back();
			nums.pop_back();
			nums.insert(nums.begin(), tmp);
		}
	}
};