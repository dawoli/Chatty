#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 100010
using namespace std;
typedef long long ll;
int T,n,a[maxn][5],ans,cnt[5],m[maxn];
void dfs(int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){
		if(cnt[i]>=n/2)continue;
		++cnt[i];
		dfs(k+1,sum+a[k][i]);
		--cnt[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
//		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				scanf("%d",&a[i][j]);
			}
		}
		bool f=true;
		for(int i=1;i<=n;++i)
			if(a[i][2]||a[i][3]){
				f=false;
				break;
			}
		if(!f){
			ans=-1;
			dfs(1,0);
		}else{
			for(int i=1;i<=n;++i)m[i]=a[i][1];
			sort(m+1,m+1+n);
			ans=0;
			for(int i=n;i>n/2;--i){
				ans+=m[i];
				//cout<<m[i];
			}
		}
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
1 0 0
1 0 0
2 0 0
2 0 0
2
10 9 0
4 0 0

18
4
13
*/
