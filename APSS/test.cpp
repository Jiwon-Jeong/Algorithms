#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v = { 4,2,234,7,3,4,5,2,22,7,6,43 };
	sort(v.begin(), v.end());
	cout<< lower_bound(v.begin(),  v.end(), 30) -v.begin()+1<<endl;
}