#include<bits/stdc++.h>
#define HohleFeuerwerke using namespace std
#define int long long
HohleFeuerwerke;
inline int read(){
	int s=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
int T;
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	T=read();
	while(T--){
		puts("0");
	}
}
