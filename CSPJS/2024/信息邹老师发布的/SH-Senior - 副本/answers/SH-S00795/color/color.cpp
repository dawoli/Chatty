#include <bits/stdc++.h>
using namespace std;
int n,tmp=0,ans=-1;
int a[200005],tp[200005];
void dfs(int x){
	if(x==n+1){
		tmp=0;
		int b=0,r=0;
		for(int i=1;i<=n;i++){
			if(tp[i]==0){
				if(a[i]==r) tmp+=a[i];
				r=a[i];
			}
			if(tp[i]==1){
				if(a[i]==b) tmp+=a[i];
				b=a[i];
			}
		}
		ans=max(ans,tmp);
		return ;
	}
	tp[x]=0;
	dfs(x+1);
	tp[x]=1;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=-1,tmp=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
