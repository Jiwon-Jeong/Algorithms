#include <string>
#include <iostream>
using namespace std;
string swap(string s, int i, int j) {
	char ch = s[j];
	s[j] = s[i];
	s[i] = ch;
	return s;
}

int main() {
	string s = "ABC";
	cout<<swap(s, 0, 2);	
}