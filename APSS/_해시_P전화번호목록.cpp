#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {

	sort(phone_book.begin(), phone_book.end());
	for (int i = 1; i < phone_book.size(); ++i) {
		if (phone_book[i - 1] == phone_book[i].substr(0, (phone_book[i - 1]).length())) {
			return false;
		}
	}

	return true;
}