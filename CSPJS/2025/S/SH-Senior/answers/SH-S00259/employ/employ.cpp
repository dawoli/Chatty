#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
#define MOD 998244353
int c[505],id[505],n,m;
char s[505];
void solve_BF(){
	int res=0;
	do{
	//	for(int i=1;i<=n;i++)printf("%d ",id[i]);
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(cnt>=c[id[i]]||s[i]=='0')++cnt;
		if(n-cnt>=m)++res;
	//	if(n-cnt>=m)puts("yes");
	//	else printf("no %d\n",cnt);
	}while(next_permutation(id+1,id+1+n));
	printf("%d",res);
}
int main(){
	file();
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),id[i]=i;
	if(n<=10)solve_BF();
	return 0;
}
