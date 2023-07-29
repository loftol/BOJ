#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

#define ll long long
#define INT int

#define X first
#define Y second
#define vi vector<INT>
#define pii pair<INT,INT>
#define vp vector<pii>
#define MOD 1000000000
#define D 1000000000
#define all(x) x.begin(), x.end()
using namespace std;

//=====================풀이========================//

vector<string> arr;

string solve(int x, int y, int size) {
    if (size == 1) {
        return string(1, arr[y][x]);
    }

    int midX = x + size / 2;
    int midY = y + size / 2;

    string ans = solve(x, y, size / 2)\
        + solve(midX, y, size / 2)\
        + solve(x, midY, size / 2)\
        + solve(midX, midY, size / 2);

    if (ans == "0000") ans = "0";
    else if (ans == "1111") ans = "1";
    else ans = "(" + ans + ")";
    return ans;
}

vector<int> solution(vector<vector<int>> _arr) {
    vector<int> answer = {0, 0};
    
    int n = _arr.size();
    
    arr = vector<string>(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            if(_arr[i][j] == 0) arr[i][j] = '0';
            else arr[i][j] = '1';
        }
    }

    string ans = solve(0, 0, n);
    
    for(char c : ans){
        if(c == '0') answer[0]++;
        else if(c == '1') answer[1]++;
    }
    
    return answer;
}