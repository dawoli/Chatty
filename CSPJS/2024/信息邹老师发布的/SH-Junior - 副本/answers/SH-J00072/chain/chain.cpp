#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,tn[100005],x,r[100005],c[100005],maxr,vis[105][100005];
vector<int> s[100005];
int read(){
	int x = 0;
	char ch = getchar();
	while(ch>='0'&&ch<='9'){
		x = (x<<3)+(x<<1)+ch-'0';
		ch = getchar();
	}
	return x;
}
void dfs(int num,int per,int tur){
	vis[tur][num] = 1;
	if(tur==maxr) return;
	for(int i = 1;i<=n;i++){
		if(i==per) continue;
		int f = 0,z; 
		for(int j = 0;j<tn[i];j++){
			if(s[i][j]==num){
				z = 0;
				for(int l = max(f+1,j+1);l<=min(j+k-1,tn[i]-1);l++){
					if(s[i][l]==num&&z==0) z = l;
					dfs(s[i][l],i,tur+1);
				}
				f = min(j+k-1,tn[i]-1);
				if(z==0) z = f+1;
				j = z-1;
			}
			if(f==tn[i]-1) break;
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	t = read();
	while(t--){
		maxr = 0;
		n = read();
		k = read();
		q = read();
		for(int i = 1;i<=n;i++){
			tn[i] = read();
			s[i].clear();
			for(int j = 1;j<=tn[i];j++){
				x = read();
				s[i].push_back(x);
			}
		}
		for(int i = 1;i<=q;i++){
			r[i] = read();
			c[i] = read();
			maxr = max(maxr,r[i]);
		}
		dfs(1,0,0);
		for(int i = 1;i<=q;i++) printf("%d\n",vis[r[i]][c[i]]);
	}
	return 0;
}
