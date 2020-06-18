class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int c = 0, i = digits.size() - 1;
		while (i >= 0) {
			digits[i]++;
			if (digits[i] < 10) break;
			else {
				digits[i] = 0;
				i--;
			}
		}
		if (digits.front() == 0)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};