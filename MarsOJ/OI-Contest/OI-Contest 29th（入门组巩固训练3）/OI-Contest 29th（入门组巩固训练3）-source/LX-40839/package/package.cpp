#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,t;
}a[10005];
struct n2{
	int v,id;
}b[1000005];
int n,m,k;
bool cmp(node a,node b){
	return a.t<b.t;
}
bool cmp2(n2 a,n2 b){
	return a.v<b.v;
}
int main(){
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>b[i].v,b[i].id=i;
	for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].t;
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp2);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].w;
	}
	long long ans=sum/b[1].id*b[1].v;
	ans+=(b[sum%b[1].id].v);
	cout<<ans;
	return 0;
} 
