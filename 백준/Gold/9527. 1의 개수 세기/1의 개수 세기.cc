#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){ll a,b;cin>>a>>b;auto c=[](ll a) {ll x=1, ret=0;while(x<=a)x<<=1,ret+=a/x*x/2+max(a%x-x/2+1,0LL);return ret;};cout<<c(b)-c(a-1);}