#include<bits/stdc++.h>
using namespace std;
int n,a[5010],vis[5010],ans;
bool flaga=1;
int sys[10010];
void dfs(int dep){
	if(dep==n+1){
		int cnt=0,maxn=0,tot=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				tot+=a[i];
				maxn=max(maxn,a[i]);
				cnt++;
			}
		}
		if(cnt>=3&&tot>maxn*2)ans=(ans+1)%998244353;
		return;
	}
	vis[dep]=1;
	dfs(dep+1);
	vis[dep]=0;
	dfs(dep+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flaga=0;
	}
	if(flaga){
		for(int i=3;i<=n;i++){
			for(int j=i;j<=n;j++){
				int ys=2,jj=j;
				while(jj>1){
					if(jj%ys==0){
						jj%=ys;
						sys[ys]++;
					}else ys++;
				}
			}
			for(int j=2;j<=n-i;j++){
				int ys=2,jj=j;
				while(jj>1){
					if(jj%ys==0){
						jj%=ys;
						sys[ys]--;
					}else ys++;
				}
			}
		}
		unsigned long long llans=1;
		for(int i=1;i<=10000;i++){
			while(sys[i]>0){
				sys[i]--;
				llans=(llans*i)%998244353;
			}
		}
		cout<<llans%998244353;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
