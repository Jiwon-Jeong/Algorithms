class Solution {
public:
	string reverseWords(string s) {
		stringstream in(s);
		string word;
		s = "";
		while (in >> word) {
			reverse(word.begin(), word.end());
			s += word + " ";
		}
		if (!s.empty()) {
			s.pop_back();
			reverse(s.begin(), s.end());
		}
		return s;
	}
};