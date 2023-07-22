#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <stack>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define X first
#define Y second

#define vp vector<pii> 
#define PI 3.14159265358979323846
#define O {0,0}
#define vi vector<int>

int taxiDist(pii a, pii b) {
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

//==================================================================//
//==================================================================//

int hori[9], ver[9], squ[3][3];

int board[9][9];
vp zeros;
bool ended = false;

void recul(int idx) {
    if (ended) return;
    if (idx == zeros.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        ended = true;
        return;
    } 
    int x = zeros[idx].X;
    int y = zeros[idx].Y;

    int pos = hori[y] | ver[x] | squ[y / 3][x / 3];

    int num = 1;
    int bit = 1;
    while ((1 << 9) > bit) {
        if (!(pos & bit)) {
            board[y][x] = num;
            hori[y] += bit;
            ver[x] += bit;
            squ[y / 3][x / 3] += bit;
            
            recul(idx + 1);
            
            if (ended) return;

            board[y][x] = 0;
            hori[y] -= bit;
            ver[x] -= bit;
            squ[y / 3][x / 3] -= bit;
        }
        num++;
        bit <<= 1;
    }

}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                zeros.push_back({ j, i });
            }
            else {
                int bit = (1 << (board[i][j] - 1));
                hori[i] += bit;
                ver[j] += bit;
                squ[i / 3][j / 3] += bit;
            }
        }
    }

    recul(0);

    return 0;
}