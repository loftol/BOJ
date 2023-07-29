#include <string>
#include <vector>
#include <array>

#define pii array<int, 2>

using namespace std;

pii dir[3] = {{1, 0}, {0, 1}, {-1, -1}};

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> board;
    for(int i = 1; i <= n; i++){
        board.push_back(vector<int>(i));
    }
    
    int val = 1;
    
    int x = -1, y = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            x += dir[i % 3][0];
            y += dir[i % 3][1];
            board[x][y] = val++;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}