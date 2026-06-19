#include<bits/stdc++.h>
using namespace std;
struct car{
	int d;
	int v;
	int a;
}c[110000];
int p[110000];
void solve(){
	int n,m,l,v;
	scanf("%d%d%d%d",&n,&m,&l,&v);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
	}
	for(int i = 1;i <= m;i++){
		scanf("%d",&p[i]);
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int di = c[i].d;
		int vi = c[i].v;
		int ai = c[i].a;
		if(ai == 0){
			if(vi > v && p[m] >= di){
				ans++;
			}
		}
	}
	printf("%d %d\n",ans,ans ? m - 1 : m);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++){
		solve();
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
