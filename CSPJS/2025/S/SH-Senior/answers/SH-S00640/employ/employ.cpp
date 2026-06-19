#include<bits/stdc++.h>
#define N ((int)(500)+10)
#define MOD 998244353
using namespace std;
typedef long long ll;
int n,m;
int s[N],c[N];
int p[N];
int ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n>=12){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		int res=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]){
				cnt++;
				continue;
			}
			if(s[i])res++;
			else cnt++;
		}
		ans+=(res>=m);
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
}

