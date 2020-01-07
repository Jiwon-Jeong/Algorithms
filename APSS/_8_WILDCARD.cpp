#include <iostream>
#include <string>
using namespace std;

/* match: w가 s에 대응 되는지 확인 */
bool match(const string& w, const string& s) {
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	// w 끝에 도달했으면 두개 길이 같을때만 true
	if (pos == w.size())
		return pos == s.size();

	// *인 경우가 문젠데, 
	if (w[pos] == '*') // 몇글자 대응해야 할지 재귀호출하면서 확인
		for (int skip = 0; pos + skip <= s.size(); ++skip)
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;

	// 그 외는 모두 false
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