#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7,md=9982344353;
int n,m,p[N],cnt;
char x[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",x+1);
	n=strlen(x+1);
	for(int i=1;i<=n;i++)
		if(isdigit(x[i]))
			p[++cnt]=x[i]^48;
	sort(p+1,p+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
		printf("%lld",p[i]);
} 
