class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return {};
		//1. �������� ����
		sort(nums.begin(), nums.end());

		//2. ���� �� ���� ����ϱ� ���� ����. �ʱ�ȭ�� ���� ���� 1.
		// �� ���� ���ڿ� ����� ����
		vector<int> dp(n, 1);

		//3.���� �ε��� ����ϱ� ���� ����. -1�� inf ��Ÿ��
		vector<int> pi(n, -1);
		int idx = 0;

		//4. j<i<n����, A[i]%A[j] == 0�̸�, A[i]�� A[j]�� ������ ���ҷ� �����Ŵ�.
		// A[i]�� �߰��� �� A[j]�� ������ �κ� ������ ���̰� A[i]�� �̹� �Ϻ��� 
		// �κ� ������ ���̺��� ������� ��쿡�� A[i]�� A[j]�� �ϴ� �κ� ���տ� �߰��� �� �ִ�.
		// �κ������� �̷�� ��� ���Ҹ� �˾ƾ��ϹǷ� pi���Ϳ� ���� �ε����� �����Ѵ�.
		// ���� ū �κ������� �ε����� idx�� �����Ѵ�.
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					pi[i] = j;
				}
			}
			if (dp[i] > dp[idx]) { idx = i; }
		}


		//5. ��Ʈ��ŷ���� ����Ѵ�.

		vector<int> ans;
		int k = idx;
		while (k >= 0) {
			ans.push_back(nums[k]);
			k = pi[k];
		}

		return ans;
	}
};