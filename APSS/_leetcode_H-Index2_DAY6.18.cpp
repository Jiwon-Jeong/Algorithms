class Solution {
public:
	int hIndex(vector<int>& citations) {
		int answer = 0;
		for (int i = citations.size() - 1; i >= 0; i--) {
			if (citations[i] <= answer) break;
			answer++;
		}
		return answer;
	}
};