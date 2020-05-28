#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
	int node[2];
	int weight;
	Edge(int x, int y, int d) {
		this->node[0] = x;
		this->node[1] = y;
		this->weight = d;
	}

	bool operator <(Edge &edge) {
		return this->weight < edge.weight;
	}
};

/*
typedef struct Edge {
	int v1; 
	int v2; 
	int w;
};
*/

//오름차순 비교 위한 함수
/*
bool comp(Edge e1, Edge e2) {
	return e1.w < e2.w;
}
*/

int parents[1000];

int find(int i) {
	if (i == parents[i]) return i;
	return parents[i] = find(parents[i]);
}
bool flag;

void merge(int x, int y) {
	flag = false;
	x = find(x);
	y = find(y);
	if (x == y) return ; // 사이클이면 false 리턴
	//아니면 크기 더 작은 값을 부모노드로 해서 union
	if (x < y) {
		parents[y] = x;
	}
	else {
		parents[x] = y;
	}
	flag = true;
}

int main() {
	int n = 7; // 노드의 개수 
	int m = 11; // 간선의 개수 

	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}

	vector<Edge> v; 
	vector<Edge> F;

	v.push_back(Edge(1, 7, 12)); // 1
	v.push_back(Edge(4, 7, 13)); // 2 
	v.push_back(Edge(1, 4, 18)); // 3 
	v.push_back(Edge(1, 2, 67)); // 4 
	v.push_back(Edge(1, 5, 17)); // 5 
	v.push_back(Edge(2, 4, 24)); // 6 
	v.push_back(Edge(2, 5, 62)); // 7 
	v.push_back(Edge(3, 5, 20)); // 8 
	v.push_back(Edge(3, 6, 37)); // 9 
	v.push_back(Edge(5, 6, 45)); // 10 
	v.push_back(Edge(5, 7, 73)); // 11

	sort(v.begin(), v.end());

	int sum = 0;

	for(int i=0; i<v.size(); i++){

		if (F.size() == n - 1) break;

		int e = v[i].weight; // 가장 가중치 작은 간선
		int v1 = v[i].node[0];
		int v2 = v[i].node[1];

		int p = find(v1);
		int q = find(v2);
		if (p != q) { // 다르면 - 사이클 안생기면
			
			merge(p, q); // union하고
			if (flag) { //union 잘 되면 F에 간선 추가
				F.push_back(v[i]);
				sum += e;
			}
		}
	}
	cout << sum << endl;
	return 0;

}