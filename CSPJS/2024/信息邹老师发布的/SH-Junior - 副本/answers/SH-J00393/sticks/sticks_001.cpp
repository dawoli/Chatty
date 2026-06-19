#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20]={6,2,5,5,4,5,6,3,7,6};
ll t,bi=0;
ll wei,shu,n=10;
ll b[100005]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,268,288,688,888};
ll cou[20]={0,1,2,6,8};
ll ko[10]={1,1,2,2,2,6,8};
ll lo[10]={2,2,5,5,5,6,7};
ll c[100];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
//	freopen("p.in","r",stdin);
//	freopen("p.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>c[i];
		bi=max(bi,c[i]);
	}
//	cout<<"--------------";
	for(int i=15;i<=bi;i++){
//		wei=i/7+1;
		shu=(i-1)%7;
		if(shu==0)n*=10;
		b[i]=ko[shu]*n+b[i-lo[shu]];
		if(shu==0||shu==3)b[i]-=6*(n/10);
	}
//	for(int i=1;i<=bi;i++){
//		cout<<i<<":"<<b[i]<<endl;
//	}
	for(int i=1;i<=t;i++){
		cout<<b[c[i]]<<endl;
	}
	return 0;
}
