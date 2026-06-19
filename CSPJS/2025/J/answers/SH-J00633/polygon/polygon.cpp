#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5010],b[5010];
bool vis[5010];
void dfs(int x,int t){
	if(x==t+1){
		for(int i=1;i<=t;i++){
			for(int j=i+1;j<=t;j++){
				if(b[i]>=b[j]) return;
			}
		}
		int sum=0,maxb=0;
		for(int i=1;i<=t;i++){
			sum+=a[b[i]];
			if(a[b[i]]>maxb) maxb=a[b[i]];
		}
		if(sum>maxb*2) ans++;
		return;
	}
	for(int i=x;i<=n;i++){
		b[x]=i;
		dfs(x+1,t);
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) dfs(1,i);
	cout<<ans%998224353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
