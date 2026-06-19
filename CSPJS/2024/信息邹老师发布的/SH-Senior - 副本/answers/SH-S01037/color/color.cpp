#include<bits/stdc++.h>
#define maxn 200010
#define maxA 1000010
#define ll long long int
#define inf 0x7fffffffffffffff
using namespace std;
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,A[maxn];
ll ans[maxn];
int maxa;
ll delta[maxn],max0,max1;
ll sh0[maxA],sh1[maxA];
ll F[maxn][2];
void solve(int t){
	n=read();
	maxa=0;
	for(int i=1;i<=n;i++){
		A[i]=read(), maxa=max(maxa,A[i]);
	}
	for(int i=1;i<=maxa;i++){
		sh0[i]=sh1[i]=-inf;
	}
	for(int j=1;j<=n;j++){
		F[j][0]=F[j][1]=-inf;
	}
	F[1][0]=F[1][1]=0, delta[1]=0;
	max0=F[1][0], max1=F[1][1];
	sh0[A[1]]=max(sh0[A[1]],F[1][0]);
	sh1[A[1]]=max(sh1[A[1]],F[1][1]);
	for(int i=2;i<=n;i++){
		//j<i
		delta[i]=delta[i-1]+(A[i-1]==A[i])*A[i];
		//j=i
		F[i][0]=max(max1,sh1[A[i]]+A[i])+delta[i-1]-delta[i];
		F[i][1]=max(max0,sh0[A[i]]+A[i])+delta[i-1]-delta[i];
		//update
		max0=max(max0,F[i][0]), max1=max(max1,F[i][1]);
		sh0[A[i-1]]=max(sh0[A[i-1]],F[i][0]);
		sh1[A[i-1]]=max(sh1[A[i-1]],F[i][1]);
	}
	ans[t]=max(max0,max1)+delta[n];
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t=read();
	for(int i=1;i<=t;i++){
		solve(i);
	}
	for(int i=1;i<=t;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}

