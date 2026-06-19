#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T, n, k, q, l[2001], s[1001][2001], r, c, f, tot;
struct node{
	int a, b;
}cnt[2000000];
void dfs(int d, int now, int lst){
	if(d==r){
		if(now==c)f=1;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f)return;
		if(i==lst)continue;
		for(int j=1;j<=l[i];j++){
			if(f)return;
			if(s[i][j]==now){
				for(int lng=1;lng<=k;lng++){
					if(j+lng<=l[i]){
						dfs(d+1, s[i][j+lng], i);
						if(f)return;
					}
					else break;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin>>T;
	while(T--){
		memset(cnt, 0, sizeof cnt);tot=0;
		cin>>n>>k>>q;
		k--;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>s[i][j];
				if(s[i][j]==1){
					tot++;
					cnt[tot].a=i;cnt[tot].b=j;
				}
			}
		}
		for(int i=1;i<=q;i++){
			f=0;
			cin>>r>>c;
			if(r>1){
				dfs(0, 1, -1);
				cout<<f<<endl;
			}
			else{
				for(int i=1;i<=tot;i++){
					int sa=cnt[i].a, sb=cnt[i].b;
					for(int j=1;j<=k;j++){
						if(k+sb>l[sa])break;
						if(s[sa][sb+j]==c){
							f=1;break;
						}
					}
					if(f)break;
				}
				cout<<f<<endl;
			}
		}
	}
	return 0;
}
