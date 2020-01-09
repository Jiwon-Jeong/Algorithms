#include <iostream>
#include<vector>;
using namespace std;


int n, days, prison, town;
int A[51][51], deg[51];
double cache[51][101];


double calculate(int t, int day) { 

	if (day == 0) 
		return (t == prison ? 1.0 : 0.0);

	double & ret = cache[t][day];
	
	if (ret != -1.0) return ret;
	ret = 0.0;

	for (int there = 0; there < n; ++there) {
		if (A[t][there])
			ret += calculate(there, day - 1) / deg[there];
	}

	return ret;
}

int main(void) {

	int testCase;
	cin >> testCase;
	if (testCase < 1 || testCase>50)
		exit(-1);

	while (testCase-- > 0) {

		cin >> n >> days >> prison;

		for (int i = 0; i <50; ++i)
			for (int j = 0; j <100; ++j)
				cache[i][j] = -1.0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> A[i][j];
				deg[i]+=A[i][j];
			}

		cin >> town;

		vector<int> v;
		for (int i = 0; i < town; ++i) {
			int there;
			cin >> there;
			v.push_back(there);
		}

		for (int i = 0; i < town; ++i) {
			cout.precision(8);
			cout << calculate(v[i], days) << " ";
		}
		cout << endl << endl;
	}
	
	return 0;
}

