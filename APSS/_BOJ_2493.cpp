#include<cstdio>
#include<stack>
#include<utility>


using namespace std;


int main(void) {
	int n, h;
	stack<pair<int, int>> S;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h);
		while (!S.empty() && S.top().first < h)
			S.pop();
		if (S.empty())
			printf("0 ");
		else
			printf("%d ", S.top().second);
		S.push(make_pair(h, i));
	}

	return 0;
}