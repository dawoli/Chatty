#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n,t;
int a[N][4];
int aa,bb,cc;
long long ans=0;

void dfs(long long t,int w){//t answer   w who
	if (w == n+1){
		ans = max(ans,t);
		return;
	}
	if(aa<n/2){
		aa+=1;
		dfs(t+a[w][1],w+1);
		aa-=1;
	}
	if(bb<n/2){
		bb+=1;
		dfs(t+a[w][2],w+1);
		bb-=1;
	} 
	if(cc<n/2) {
		cc+=1;
		dfs(t+a[w][3],w+1);
		cc-=1;
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	
	for(int i = 1;i<=t;i+=1){
		scanf("%lld",&n);
		for(int j = 1;j<=n;j+=1){
			scanf("%d %d %d",&a[j][1],&a[j][2],&a[j][3]);
			
		}
		dfs(0,1);
		printf("%lld\n",ans);
		ans = 0;
		aa = bb=cc=0;
	}

	return 0;
} 
