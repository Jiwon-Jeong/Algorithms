class RandomizedSet {
public:
	vector<int> set;
	/** Initialize your data structure here. */
	RandomizedSet() {
		set.clear();
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (find(set.begin(), set.end(), val) != set.end()) return false;
		set.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (find(set.begin(), set.end(), val) == set.end()) return false;
		set.erase(std::remove(set.begin(), set.end(), val), set.end());
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int size = set.size();
		int idx = rand() % size;
		return set.at(idx);
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */