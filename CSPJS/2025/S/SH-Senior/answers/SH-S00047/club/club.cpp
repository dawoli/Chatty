#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
struct node{
	int a,b,c;
	int num;
}a[100005],f[100005][5];
bool cmp(node x,node y){
	return x.a>y.a;
}
int num[100005];
ll ans=0;
bool isb=1;
void dfs(int t,int ca,int cb,int cc,ll sum){
	if(t>n){
		ans=max(ans,sum);
		return;
	}
	if(ca<n/2){
		num[t]=1;
		dfs(t+1,ca+1,cb,cc,sum+a[t].a);
	}
	if(cb<n/2){
		num[t]=2;
		dfs(t+1,ca,cb+1,cc,sum+a[t].b);
	}
	if(cc<n/2){
		num[t]=3;
		dfs(t+1,ca,cb,cc+1,sum+a[t].c);
	}
}
bool vis[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		bool isa=1;
		isb=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b!=0||a[i].c!=0) isa=0;
			if(a[i].c!=0) isb=0;
		}
		if(isa){
			sort(a+1,a+n+1,cmp);
			ll ans=0;
			for(int i=n;i>=n/2;i--)
				ans+=a[i].a;
			cout<<ans<<endl;
			continue;
		}
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
