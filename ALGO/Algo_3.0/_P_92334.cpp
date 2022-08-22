#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> split(string input){
    vector<string> ret;
    int curr = input.find(' ');
    ret.push_back(input.substr(0, curr));
    ret.push_back(input.substr(curr + 1, input.length() - curr - 1));
    return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    vector<int> reported(id_list.size());
    map<string, set<string>> m;
    for (string s: report){
        vector<string> vs = split(s);
        m[vs[0]].insert(vs[1]);
    }
    
    for (auto n: m){
        string key = n.first;
        set<string> values = n.second;
        for (auto v: values){
            int i = find(id_list.begin(), id_list.end(), v) - id_list.begin();
            reported[i] += 1;
        }
    }
    
    for (auto id : id_list)
    {
        int idx = find(id_list.begin(), id_list.end(), id) - id_list.begin();
        auto reporter = m[id];
        for (auto r : reporter){
            int i = find(id_list.begin(), id_list.end(), r) - id_list.begin();
            if (reported[i] >= k)
                answer[idx] ++;
        }
    }
    
    return answer;
}
