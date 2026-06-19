#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[1000005];
struct node{
	int t,w,d;
}a[10005];
bool cmp(node a,node b){
	return a.t<b.t;
}
int main(){
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		if(sum+a[i].w<=m){
			sum+=a[i].w;
		}else{
			ans+=v[sum];
			sum=a[i].w;
		}
	}
	cout<<ans+v[sum];
	return 0;
}
