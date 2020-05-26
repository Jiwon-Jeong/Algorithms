#include <vector>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		vector<int> v;
		while (num != 0) {
			v.push_back(num % 2);
			num /= 2;
		}
		long long k = 1, result = 0;
		for (int i = 0; i < v.size(); i++) {
			result += v[i] == 0 ? k : 0;
			k = k * 2;
		}
		return result;
	}
};