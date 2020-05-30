#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1000000;

int main() {
	char W[MAX + 1], S[MAX + 1];
	int M, N;
	gets(S);
	gets(W);
	N = strlen(S);
	M = strlen(W);

	int fail[MAX] = { ... };

	// S, W�� ��ġ�ϴ� ������ result�� ����
	vector<int> result;
	for (int i = 0, j = 0; i < N; i++) {
		// ���� ���ڰ� ����ġ�ϸ� fail ���� ��� ����
		while (j > 0 && S[i] != W[j]) j = fail[j - 1];
		// ���� ���ڰ� ��ġ
		if (S[i] == W[j]) {
			// W�� S[i:i+M-1]���� ã��
			if (j == M - 1) {
				// i=0���� �����Ѵٸ� i-M+1. ���� ���ǿ� ���� 1�� ����
				result.push_back(i - M + 2);
				// ã�� ���� ��ó�� j�� �̵���Ű�� ��
				j = fail[j];
			}
			else j++;
		}
	}

	printf("%d\n", result.size());
	for (int i : result)
		printf("%d ", i);
}