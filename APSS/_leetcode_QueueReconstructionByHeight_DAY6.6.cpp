class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](vector<int>&a, vector<int> &b) {
			return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
		});
		vector<vector<int>> answer;
		for (int i = 0; i < people.size(); ++i) {
			int idx = people[i][1];
			answer.insert(answer.begin() + idx, 1, people[i]);
		}
		return answer;
	}
};