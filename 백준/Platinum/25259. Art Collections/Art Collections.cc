#include "art.h"
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

void solve(int n) {
    vector<int> arr(n);
    iota(all(arr), 1);
    int offset = publish(arr);

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            swap(arr[j], arr[j - 1]);
        }
        int pivot = publish(arr);
        int x = (pivot - offset + i) / 2;
        for (int j = 0; j < x; j++) {
            swap(arr[j], arr[j + 1]);
        }
        offset = pivot - x;
    }

    answer(arr);
}
