#include<bits/stdc++.h>
int main(){long long a,b;std::cin>>a>>b;auto c=[](long long a){long long x=1,ret=0;while(x<=a)x<<=1,ret+=a/x*x/2+std::max(a%x-x/2+1,0LL);return ret;};std::cout<<c(b)-c(a-1);}