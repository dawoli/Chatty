#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int pre[N],f[N];
int p[N*3];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
	fill(p+1,p+3*N,-1);
	for(int i=1;i<=n;i++){
		int t=pre[i]^k;
		f[i]=max(f[i],f[i-1]);
		if(p[t]!=-1) f[i]=max(f[i],f[p[t]]+1);
		p[pre[i]]=i;
	}
	cout<<f[n];
	return 0;
}
/*
4 0
2 1 0 3
*/
