#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5, MAXS=5e2+5;
int n, a[MAXN];
bool vis[MAXN];
int f[MAXS][MAXS];
int minn=numeric_limits<int>::max();
int dfs(int i, int pos) {
	if(i>n || pos>n || i==pos) return 0;
	if(vis[pos]) return 0;
	if(f[i][pos]!=0x3f3f3f3f) return f[i][pos];
	vis[i]=1;
	int rt=0;
	for(int j=pos; j<=n; j++) {
//		cout << a[i] << " " << a[j] << " " << sum << endl;
		if(a[i]<=a[j]) continue;
		vis[pos]=1;
		rt=max(rt, dfs(i, j)+1);
//		cout << rt << " ";
	}
//	cout<<endl;
	vis[i]=0;
	vis[pos]=0;
	f[i][pos]=rt;
	return f[i][pos];
}
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	memset(f, 0x3f, sizeof(f));
	for(int i=1; i<=n; i++) {
		memset(vis, 0,sizeof(vis));
		int val=dfs(i,1);
//		cout << "val:"<<val<<endl;
		if(val!=0)
			minn=min(minn,val);
	}
	if(minn==2147483647) minn=n;
	printf("%d\n", minn);
	return 0;
} 

