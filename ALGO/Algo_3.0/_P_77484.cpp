#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0; 
    int zeroCnt = count(lottos.begin(), lottos.end(), 0);
    for (int i = 0; i < lottos.size(); ++i){
        if (count(win_nums.begin(), win_nums.end(), lottos[i]))
            cnt++;  
    }
    answer.push_back(min(6, 7 - (zeroCnt + cnt)));
    answer.push_back(min(6, 7 - cnt));
    return answer;
}
