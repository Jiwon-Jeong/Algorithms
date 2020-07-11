class Solution {
public:
	//helper method
	void fillPowerSet(vector<int>& nums, int i, int n, vector<vector<int>>& ans) {
		if (i == n) return;
		int v = nums[i];
		vector<vector<int>>t = ans;
		for (auto x : t) {
			x.push_back(v);
			ans.push_back(x);
		}
		fillPowerSet(nums, i + 1, n, ans);
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		int i = 0, n = nums.size();
		if (n == 0) return {};
		vector<vector<int>>ans;
		ans.push_back({});
		fillPowerSet(nums, i, n, ans);
		return ans;
	}
};