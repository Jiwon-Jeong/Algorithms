class Solution {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int answer = 0, min = 0;
		auto comp = [](vector<int>&a, vector<int>&b) {
			return (a[0] - a[1]) < (b[0] - b[1]);
		};

		sort(costs.begin(), costs.end(), comp);
		for (int i = 0; i < costs.size(); i++) {
			if (i < costs.size() / 2)
				answer += costs[i][0];
			else
				answer += costs[i][1];
		}
		return answer;
	}
};