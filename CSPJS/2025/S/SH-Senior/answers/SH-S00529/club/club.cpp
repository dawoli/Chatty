#include<bits/stdc++.h>
using namespace std;
int n,cnt[4];
struct node{
	int v[4];
}a[100009];
bool cmp(node x,node y){
	return max(max(x.v[1],x.v[2]),x.v[3])>max(max(y.v[1],y.v[2]),y.v[3]);
}
int dfs(int i,int cnt1,int cnt2,int cnt3,int sum){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return 0;
	if(i==n){
		return sum;
	}
	int x=0,y=0,z=0;
	x=dfs(i+1,cnt1+1,cnt2,cnt3,sum+a[i].v[1]);
	y=dfs(i+1,cnt1,cnt2+1,cnt3,sum+a[i].v[2]);
	z=dfs(i+1,cnt1,cnt2,cnt3+1,sum+a[i].v[3]);
	return max(max(x,y),z);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=1;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(y>0||z>0) flag=0;
			a[i].v[1]=x,a[i].v[2]=y,a[i].v[3]=z;
		}
		if(flag){
			int ans=0;
			sort(a,a+n,cmp);
			for(int i=0;i<n/2;i++){
				ans+=a[i].v[1];
			}
			cout<<ans<<endl;
		}
		else cout<<dfs(0,0,0,0,0)<<endl;
	} 
	return 0;
} 
