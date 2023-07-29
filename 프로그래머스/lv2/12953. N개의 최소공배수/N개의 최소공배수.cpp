#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    for(int i : arr) answer = answer * i / gcd(answer,i);
    return answer;
}