#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <deque>

#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

//=====================풀이========================//

deque<int> fr, bac;
vi vst;
priority_queue<int, vi, greater<>> mheap;
priority_queue<int> Mheap;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    vst = vi(n + 1);
    int state = 0;
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            int b;
            cin >> b;
            if (state == 0) {
                fr.push_back(b);
            }
            else {
                bac.push_back(b);
            }
        }
        else if (a == 1) {
            state = 0;
            while (fr.size()) {
                mheap.push(fr.back());
                Mheap.push(fr.back());
                fr.pop_back();
            }
            while (bac.size()) {
                mheap.push(bac.back());
                Mheap.push(bac.back());
                bac.pop_back();
            }
        }
        else if(a == 2){
            state = 1 - state;
        }
        else {
            while (true) {
                int u;
                if (state == 0) {
                    if (fr.size()) {
                        u = fr.back();
                        fr.pop_back();
                    }
                    else if(mheap.size()){
                        u = mheap.top();
                        mheap.pop();
                    }
                    else {
                        u = bac.front();
                        bac.pop_front();
                    }
                }
                else {
                    if (bac.size()) {
                        u = bac.back();
                        bac.pop_back();
                    }
                    else if(Mheap.size()) {
                        u = Mheap.top();
                        Mheap.pop();
                    }
                    else {
                        u = fr.front();
                        fr.pop_front();
                    }
                }
                if (vst[u]) continue;
                cout << u << '\n';
                vst[u] = 1;
                break;
            }
        }
    }

    return 0;
}