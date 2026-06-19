#include<bits/stdc++.h>
using namespace std;
int t,n,ans,c[100005];
struct Node{
	int x,y,z;
}a[100005];
void dfs(int dep,int ac,int bc,int cc,int sum){
	if(dep==n){
		ans=max(ans,sum);
		return;
	}
	if(ac<n/2) dfs(dep+1,ac+1,bc,cc,sum+a[dep].x);
	if(bc<n/2) dfs(dep+1,ac,bc+1,cc,sum+a[dep].y);
	if(cc<n/2) dfs(dep+1,ac,bc,cc+1,sum+a[dep].z);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int f1=1,f2=1;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			c[i]=a[i].x;
			if(a[i].y!=0) f1=0;
			if(a[i].z!=0) f2=0;
			int mx=max({a[i].x,a[i].y,a[i].z});
//			ans+=mx;
		}
		if(f1){
			int sum=0,ct=0;
			sort(c,c+n);
			for(int i=n-1;i>=0;i--){
				sum+=c[i];
				if(++ct>=n/2) break;
			}
			cout<<sum<<'\n';
		}else {
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
