#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void solve(int n, int from, int to){
    if(n == 1) answer.push_back({from, to});
    else{
        int rest = from ^ to;
        solve(n - 1, from, rest);
        answer.push_back({from, to});
        solve(n - 1, rest, to);
    }
}

vector<vector<int>> solution(int n) {
    solve(n, 1, 3);
    return answer;
}