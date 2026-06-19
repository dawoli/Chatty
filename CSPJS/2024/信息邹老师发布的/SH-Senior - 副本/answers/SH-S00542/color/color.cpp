#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[200010];
int r[200010],l[200010];
long long ans;

void dfs(int t,int lr,int ll){
	if(t==n){
		long long c=0;
		for(int i=1;i<lr;i++){
			if(r[i]==r[i+1]){
				c+=r[i+1];
			}
		}
		for(int i=1;i<ll;i++){
			if(l[i]==l[i+1]){
				c+=l[i+1];
			}
		}
		ans=max(ans,c);
		return;
	}
	r[lr+1]=a[t+1];
	dfs(t+1,lr+1,ll);
	l[ll+1]=a[t+1];
	dfs(t+1,lr,ll+1);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		dfs(0,0,0);
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
