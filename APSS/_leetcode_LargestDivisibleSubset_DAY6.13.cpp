class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return {};
		//1. 오름차순 정렬
		sort(nums.begin(), nums.end());

		//2. 가장 긴 길이 기록하기 위한 벡터. 초기화는 본인 길이 1.
		// 더 작은 숫자에 기록할 것임
		vector<int> dp(n, 1);

		//3.이전 인덱스 기억하기 위한 벡터. -1은 inf 나타냄
		vector<int> pi(n, -1);
		int idx = 0;

		//4. j<i<n에서, A[i]%A[j] == 0이면, A[i]를 A[j]의 마지막 원소로 넣을거다.
		// A[i]를 추가한 후 A[j]로 끝나는 부분 집합의 길이가 A[i]가 이미 일부인 
		// 부분 집합의 길이보다 길어지는 경우에만 A[i]를 A[j]로 하는 부분 집합에 추가할 수 있다.
		// 부분집합을 이루는 모든 원소를 알아야하므로 pi벡터에 이전 인덱스를 저장한다.
		// 가장 큰 부분집합의 인덱스를 idx에 저장한다.
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pi[i] = j;
				}
			}
			if (dp[i] > dp[idx]) { idx = i; }
		}


		//5. 백트래킹으로 출력한다.

		vector<int> ans;
		int k = idx;
		while (k >= 0) {
			ans.push_back(nums[k]);
			k = pi[k];
		}

		return ans;
	}
};