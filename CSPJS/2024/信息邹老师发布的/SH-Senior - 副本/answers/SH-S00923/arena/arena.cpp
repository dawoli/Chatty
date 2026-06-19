#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T,n,m,K,a[MAXN],c[MAXN],val[MAXN],dx[6];
long long ans,ret;
char g[MAXN<<1];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=m;i++)	cin>>c[i];
	K=log2(n);
	if((1<<K)==n)	K--;
	for(int i=K,j=1;i>=0;i--)
		for(int k=1;k<=(1<<i);k++,j++)
			cin>>g[j];
	for(int e=1;e<=T;e++){
		cin>>dx[0]>>dx[1]>>dx[2]>>dx[3];	ret=1;
		for(int i=1;i<=n;i++)	val[i]=a[i]^dx[i%4];
		for(int i=2;i<=m;i++){
			int k=log2(i),pos=1;
			if((1<<k)==i)	k--;
			for(int j=K;j>k;j--)	pos+=(1<<j);
			
		}
	}
	return 0;
}
