#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    for(int i : arr){
        int g = gcd(answer,i);
        answer = answer * i / g;
    }
    
    return answer;
}