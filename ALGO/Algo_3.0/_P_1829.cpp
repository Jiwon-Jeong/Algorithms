#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool checked[100][100];

int bfs(int i, int j, int m, int n, vector<vector<int>>& picture){
    queue<pair<int, int>> q;
    int maxSize = 1;
    q.push(make_pair(i, j));
    checked[i][j] = true;
    
    while(!q.empty()){
        auto e = q.front();
        q.pop();

        int level = picture[e.first][e.second];

        for (int k = 0; k < 4; ++k){
            int x = e.first + dx[k];
            int y = e.second + dy[k];
            
            if (x < 0 || y < 0 || x >= m || y >=n) continue; 
            if (checked[x][y] || picture[x][y] != level) continue;
            checked[x][y] = true;   
            q.push(make_pair(x, y));
            maxSize++;
         }
    }
    return maxSize;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i = 0 ; i < m; ++i)
        for (int j = 0; j< n; ++j)
            checked[i][j] = false;
        
    for (int i = 0; i < m; ++i){
        for (int j = 0; j< n; ++j){
            if (picture[i][j] != 0 && checked[i][j] == false){
                int size = bfs(i, j, m, n, picture);
                max_size_of_one_area = max(size, max_size_of_one_area);
                number_of_area ++;                
            }
        }
    }
    
    return {number_of_area, max_size_of_one_area};
}
