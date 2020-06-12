class Solution {
public:
	vector<int> getStrongest(vector<int>& arr, int k) {
		sort(arr.begin(), arr.end());
		int s = arr.size();
		int med = arr[(s - 1) / 2];
		sort(arr.begin(), arr.end(), [&](int a, int b) {
			return (abs(med - a) > abs(med - b)) || (abs(med - a) == abs(med - b) && a > b);
			//원래 이 부분을 abs(med-a) >= abs(med-b)로 작성했더니 heap overflow 발생함
		});
		return vector<int>(arr.begin(), arr.begin() + k);
	}
};