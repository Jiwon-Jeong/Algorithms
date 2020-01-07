#include <iostream>
#include <string>
using namespace std;

/* match: w�� s�� ���� �Ǵ��� Ȯ�� - �ܼ��� ��� */
/*
bool match(const string& w, const string& s) {
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	// w ���� ���������� �ΰ� ���� �������� true
	if (pos == w.size())
		return pos == s.size();

	// *�� ��찡 ������, 
	if (w[pos] == '*') // ����� �����ؾ� ���� ���ȣ���ϸ鼭 Ȯ��
		for (int skip = 0; pos + skip <= s.size(); ++skip)
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;

	// �� �ܴ� ��� false
	return false;

}
*/
 
/* ������ȹ�� - Memoization */
int cache[101][101];
string S, W;

int matchMemoization(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;

	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}

	if (w == W.size()) return ret = (s = S.size());
	if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); ++skip)
			if (matchMemoization(w + 1, s + skip))
				return ret = 1;

	return ret = 0;

}


int main() {
	memset(cache, -1, sizeof(cache));

	int c;
	cin >> c;
	while (c-- > 0) {
		int n;
		cin >> W;
		cin >> n;
		while (n-- > 0) {
			cin >> S;
			if (matchMemoization(0,0))
				cout << S <<endl;
		}
	}
}