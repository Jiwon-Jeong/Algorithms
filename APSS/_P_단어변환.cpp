#include <string>
#include <vector>

using namespace std;

bool check[50];
int answer = 100;

bool checkDiff(string a, string b)
{
	int diff = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			diff++;
		}
	}
	if (diff == 1)
	{
		return true;
	}
	else
	{
		return false;
	}


}

void DFS(string begin, string target, vector<string> words, bool * check, int time)
{
	for (int i = 0; i < words.size(); i++)
	{

		if (checkDiff(begin, words[i]))
		{
			if (target == words[i])
			{
				if (answer > time + 1)
				{
					answer = time + 1;
					return;
				}

			}
			if (!check[i])
			{
				check[i] = true;
				DFS(words[i], target, words, check, time + 1);
			}
		}
	}


}

int solution(string begin, string target, vector<string> words) {

	int tmp = 0;
	bool check[50] = { false };
	DFS(begin, target, words, check, 0);
	if (answer == 100)
		return 0;
	else
	{
		return answer;
	}

}
