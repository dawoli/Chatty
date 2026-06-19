#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005],c[100005];
int d[100005];
inline int max(int &a,int &b){return a>b?a:b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int T;scanf("%d",&T);while(T--){
	scanf("%d",&n);
	int sm=0;
	for(int i=1;i<=n;sm+=max(a[i],max(b[i],c[i])),++i)
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	
	// a limited
	int D=0,m=0,md=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		if(a[i]>max(b[i],c[i])){
			d[++m]=a[i]-max(b[i],c[i]);
	}	}
	if(m>n/2){
		sort(d+1,d+m+1);
		for(int i=1;i<=m-n/2;++i)D+=d[i];
	md=min(D,md);}
	 D=0,m=0;
	// b limited
	for(int i=1;i<=n;++i){
		if(b[i]>max(a[i],c[i])){
			d[++m]=b[i]-max(a[i],c[i]);
	}	}
	if(m>n/2){
		sort(d+1,d+m+1);
		for(int i=1;i<=m-n/2;++i)D+=d[i];
	md=min(D,md);}D=0,m=0;
	// c limited
	for(int i=1;i<=n;++i){
		if(c[i]>max(a[i],b[i])){
			d[++m]=c[i]-max(a[i],b[i]);
	}	}
	if(m>n/2){
		sort(d+1,d+m+1);
		for(int i=1;i<=m-n/2;++i)D+=d[i];
	md=min(D,md);}
	if(md==0x3f3f3f3f)md=0;
	printf("%d\n",sm-md);
}
	return 0;
}
