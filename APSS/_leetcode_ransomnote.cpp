class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int num1[26] = { 0 };
		int num2[26] = { 0 };
		for (int i = 0; i < ransomNote.length(); i++) {
			num1[ransomNote[i] - 'a']++;
		}
		for (int i = 0; i < magazine.length(); i++) {
			num2[magazine[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (num1[i] > num2[i])
				return false;
		}
		return true;
	}
};