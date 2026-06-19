#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;
long long n,m,k,c[12][10002],sum=0;
struct edge{
	long long u,v,w;
}a[10002];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		sum+=a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++) cin>>c[i][j];
	}
	if(m==n-1){
		if(k==0){
			cout<<sum<<endl;
			return 0;
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(c[i][j]==0){
					sum-=1;
				}
			}
		}
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}
