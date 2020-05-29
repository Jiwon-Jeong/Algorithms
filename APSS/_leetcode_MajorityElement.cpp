#include <map>
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int, greater<int>> m;

		for (int i = 0; i < nums.size(); i++) {
			if (m.count(nums[i]) == 0) {
				m.insert(make_pair(nums[i], 1));

			}
			else {
				m.find(nums[i])->second++;
			}
		}
		int max = 0, idx = 0;
		map<int, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++) {
			if (max < iter->second) {
				max = iter->second;
				idx = iter->first;
			}
		}
		return idx;
	}
};