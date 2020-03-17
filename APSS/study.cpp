
#include <iostream>
#include <stack>
//#include <queue>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	string str;
	int tc;
	scanf("%d", &tc);
	//getchar();
	int cnt = 1;
	int flag = 0;
	while (tc--) {
		int a;
		stack<int>s;
		scanf("%d", &a);
		if (s.empty()) {
			printf("À¸¿¢");
			while (cnt <= a) {
				s.push(cnt);

				str += "+\n";
				cnt += 1;
			}
			str += "-\n";
			s.pop();
		}


		if ( s.top() < a) {
			
			printf("Á¨Àå");
			while (cnt <= a) {
				s.push(cnt);
				
				str += "+\n";
				cnt += 1;
			}
			str += "-\n";
			s.pop();
			
		}


		else {
			
			printf("%d\n", s.top());
			if (s.top() == a) {
				s.pop();
				str += "-\n";
			}
			else {
				cout << "NO" << '\n';
				return 0;
			}

		}
		

	}
	if (flag == 1) {
		printf("NO\n");
	}
	else {
		cout << str;
	}

}