#include<bits/stdc++.h>
using namespace std;
int t,d[100010],v[100010],a[100010],p[100010],n,m,l,u,vis[100010];
bool check(int a[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=0)  return false;
	}
	return true;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=1e5;i++)  vis[i]=0;
		cin>>n>>m>>l>>u;
		for(int i=1;i<=n;i++)  cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)  cin>>p[i];
		if(check(a)){
			int cnt=0,ans=0;
			for(int i=1;i<=n;i++){
				if(v[i]<=u)  continue;
				int flag=0;
				for(int j=1;j<=m;j++){
					if(p[j]>=d[i]){
						flag=1,vis[j]=1;
					}
				}
				if(flag==1)  cnt++;
			}
			for(int i=1;i<=m;i++){
				if(vis[i]==0)  ans++;
			}
			cout<<cnt<<" "<<ans<<endl;
		}
	}
	return 0;
}
