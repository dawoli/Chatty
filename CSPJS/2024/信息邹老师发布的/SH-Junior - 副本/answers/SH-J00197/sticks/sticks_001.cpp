#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
const ll N = 100005;
ll T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		if(n == 1)puts("-1");
		else if(n == 3)puts("7");
		else if(n == 4)puts("4");
		else{
			if(n % 7 == 1)n -= 8,printf("10");
			if(n % 7 == 2)n -= 2,printf("1");
			if(n % 7 == 3)n -= 10,printf("22");
			if(n % 7 == 4)n -= 11,printf("20");
			if(n % 7 == 5)n -= 5,printf("2");
			if(n % 7 == 6)n -= 6,printf("6");
			while(n)n -= 7,printf("8");
			puts("");
		}
	}
	return 0;
}
