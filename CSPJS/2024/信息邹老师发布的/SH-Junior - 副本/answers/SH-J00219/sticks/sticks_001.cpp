#include<bits/stdc++.h>
using namespace std;
int n,ans[11] = {-1,-1,1,7,4,2,6,8},pre[11] = {8,10,18,22,20,28,68};
void solve(){
	if(n <= 7){ printf("%d\n",ans[n]); return; }
	printf("%d",pre[n % 7]);
	int k = n / 7;
	while(--k) printf("%d",8);
	printf("\n");
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		solve();
	}
	return 0;
}

