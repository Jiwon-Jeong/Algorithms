#include <string>
#include <vector>

using namespace std;

void func(vector<vector<int>> &answer, int n, int from, int to){
    if (n == 1){
        answer.push_back({from, to});
        return;
    }
    
    func(answer, n-1, from, 6 - from - to);
    answer.push_back({from, to});
    func(answer, n-1, 6 - from - to, to);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    func(answer, n, 1, 3);
    return answer;
}
