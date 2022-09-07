using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = money;
    while (count){
        answer -= count * price;
        count--;
    }
    return answer < 0 ? -answer : 0;
}
