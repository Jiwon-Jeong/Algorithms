#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for (int n : nums)
        s.insert(n);
    // set<int> s(nums.begin(), nums.end()); --- 위 3줄 대체
    return min(nums.size() / 2, s.size()); 
}