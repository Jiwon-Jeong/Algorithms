#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(string s) {
    string res = "";
    for (int i = 0; i<s.length(); ++i)
    {
        if (s[i] >= '0' && s[i] <='9')
        {
            res += s[i];
        }
        else if (s[i] == 'z')
        {
            res += '0';
            i+=3;
        }
        else if (s[i] == 'o')
        {
            res += '1';
            i += 2;
        }
        else if (s[i] == 't')
        {
            if (s[i+1] == 'w')
            {
                res += '2';
                i+=2;
            }
            else {
                res += '3';
                i += 4;
            }
        }
        else if (s[i] == 'f') 
        {
            if (s[i+1]== 'o')
            {
                res += '4';
                i += 3;
            }
            else{
                res += '5';
                i += 3;
            }
        }
        else if (s[i] == 's')
        {
            if (s[i+1] == 'i')
            {
                res += '6';
                i += 2;
            }
            else
            {
                res += '7';
                i += 4;
            }
        }
        else if (s[i] == 'e')
        {
            res += '8';
            i += 4;
        }
        else if (s[i] == 'n')
        {
            res += '9';
            i += 3;
        }
    }
    return stoi(res);
}

int solution2(string s) {
    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string res = "";
    for (int i = 0; i<s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <='9')
        {
            res += s[i];
        }
        else
        {
            for (int j = 0; j < v.size(); j++)
            {   
                if (s.substr(i, v[j].length()) == v[j])
                {
                    res += to_string(j);
                    i += v[j].length() - 1;
                    break;
                }
            }
        }
    }
    return stoi(res);
}

int main()
{
    cout << solution("one4seveneight") << endl;
    return 0;
}
