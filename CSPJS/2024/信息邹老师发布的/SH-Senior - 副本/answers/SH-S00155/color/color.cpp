#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0; cin>>n;
		int a[10000]={0};
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=0;i<=(1<<n)-1;i++){
			bool color[10000]={0},c[10000]={0};
			for(int j=1;j<=n;j++){
				int mask=1<<j-1;
				if(i&mask){
					color[j]=1;
				}
			}
			int rb[10000][2];
			for(int i=1;i<=n;i++){
				rb[i][1]=rb[i-1][1]+color[i];
				rb[i][0]=rb[i-1][0]+(!color[i]);
			}
			for(int i=1;i<=n;i++){
				if(rb[i][color[i]]==0) continue;
				int near;
				for(int j=i-1;j>=1;j--)
					if(color[i]==color[j]){
						near=j;
						break;
					}
				if(a[i]==a[near]) c[i]=a[i];
				else c[i]=0;
			}
			int res=0;
			for(int i=1;i<=n;i++) res+=c[i];
			ans=max(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1
8
3 5 2 5 1 2 1 4
*/
