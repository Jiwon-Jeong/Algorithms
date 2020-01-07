#include <iostream>
#include <string>
using namespace std;

/* match: w�� s�� ���� �Ǵ��� Ȯ�� */
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

int main() {
	int c;
	cin >> c;
	while (c-- > 0) {
		string w,s;
		int n;
		cin >> w;
		cin >> n;
		while (n-- > 0) {
			cin >> s;
			if (match(w, s))
				cout << s<<endl;
		}
	}
}