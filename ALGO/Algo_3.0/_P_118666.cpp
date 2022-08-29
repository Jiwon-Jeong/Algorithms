#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    vector<char> mbti = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    unordered_map<char, int> m;
    for (auto s : mbti)
        m.insert(make_pair(s, 0));

    for (int i = 0; i < survey.size(); ++i){
        auto c = choices[i] - 4;
        auto s = (c < 0) ? survey[i][0] : survey[i][1];
        m[s] += abs(c);
    }

    for (int j = 0; j < mbti.size(); j+=2){
        auto first = mbti[j];
        auto second = mbti[j+1];
        answer += (m[first] >= m[second]) ? first : second;
    }

    return answer;
}
