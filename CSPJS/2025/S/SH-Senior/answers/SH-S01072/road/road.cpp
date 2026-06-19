#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],a[11][10005],ans=0;
int minn=1e9;
struct road{
	long long u,v,w;
}r[10005];
bool cmp(road a,road b){
	if(a.w<b.w)return 1;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)cin>>r[i].u>>r[i].v>>r[i].w;
	sort(r,r+m,cmp);
	if(k==0){
		long long ans=0;
		for(int i=0;i<m-1;i++)ans+=r[i].w;
		cout<<ans;
		return 0;
	} 
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<m;j++)cin>>a[i][j];
	}
	for(int i=0;i<m/2;i++)ans+=r[i].w;
	for(int i=0;i<k;i++){
		int tmp=c[i];
		sort(a[i],a[i]+m);
		for(int j=0;j<m/2;j++){
			tmp+=a[i][j];
		}
		minn=min(minn,tmp);
	}
	cout<<ans+minn;
	return 0;
} 
