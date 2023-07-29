#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()
#define ll long long
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(all(A));
    sort(all(B), greater<>());
    ll sum = 0;
    for(int i = 0; i < A.size(); i++){
        sum += A[i] * B[i];
    }

    return sum;
}