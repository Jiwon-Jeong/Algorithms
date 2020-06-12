class BrowserHistory {
public:
	vector<string> location;
	int idx;

	BrowserHistory(string homepage) {
		location.push_back(homepage);
		idx = 0;
	}

	void visit(string url) {
		if (idx == (location.size() - 1))
			location.push_back(url);
		else {
			int n = location.size() - idx - 1;
			while (n--) {
				location.pop_back();
			}
			location.push_back(url);
		}
		idx++;
	}

	string back(int steps) {
		if ((idx - steps) < 0) { idx = 0; return location.at(0); }
		idx = idx - steps;
		return location.at(idx);
	}

	string forward(int steps) {
		if ((idx + steps) > (location.size() - 1)) { idx = location.size() - 1; return location.back(); }
		idx = idx + steps;
		return location.at(idx);
	}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */