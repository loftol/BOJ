#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'
#define forin(i, n) for(int i = 0; i < n; ++i)
#define mod 1e9+7

void solve()
{
    int bias = 500000;
    ll n, k; cin >> n >> k;
    vector<ll> board(k);
    for(ll &i : board)cin >> i;
    ll cnts[2 * bias];
    for(int i = 0; i < k; i++){
        cnts[board[i] - (i + 1) + bias]++;
    }

    ll centerSum = 0;
    int plusCnt = 0;
    int minusCnt = 0;
    for(int i = 2; i < n + 2; i++){
        centerSum += abs(board[i] - (i - 1));
        if(board[i] - (i + 1) >= -2) plusCnt++;
        else minusCnt++;
    }
    // minusCnt -> plusCnt 이동중
    ll minSum = 1e18;
    for(int i = 2; i + n + 1 < k; i++){
        ll sideSum = abs(board[i-2] - 1);
        sideSum += abs(board[i-1] - 1);
        sideSum += abs(board[i + n] - n);
        sideSum += abs(board[i + n + 1] - n);
        minSum = min(minSum, sideSum + centerSum);
        plusCnt--;
        centerSum += plusCnt - minusCnt;
        centerSum -= abs(board[i] - 1);
        centerSum += abs(board[i+n] - n);
        plusCnt += cnts[-(i + 1) + bias];
        minusCnt -= cnts[-(i + 1) + bias];
        minusCnt++;
    }
    
    cout << minSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}