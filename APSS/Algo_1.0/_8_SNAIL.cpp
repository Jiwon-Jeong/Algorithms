#include <iostream>
using namespace std;

int height, day;
const int max_size = 1000;
double cache[max_size][2*max_size];

double climb(int passed, int climbed)
{
	if (passed == day)
		return climbed >= height ? 1 : 0;

	double &result = cache[passed][climbed];
	if (result != -1.0)
		return result;
	return result = (0.25 * climb(passed + 1, climbed + 1)) + (0.75 * climb(passed + 1, climbed + 2));
}

int main(void) {

	cin >> height >> day;
	if (height < 1 || height>1000 || day < 1 || day>1000)
		exit(-1);

	//memset(cache, -1, sizeof(cache)); double은 memset이 적용 안됨
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 2000; j++) {
			cache[i][j] = -1.0;
		}
	}
	cout.precision(11); //10자리
	cout << climb(0, 0) << endl;

	return 0;
}

