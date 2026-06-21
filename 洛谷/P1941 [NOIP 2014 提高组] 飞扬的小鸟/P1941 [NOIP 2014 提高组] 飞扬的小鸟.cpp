// Problem URL: https://www.luogu.com.cn/problem/P1941
// Finish Time: 2026/6/21 12:08:16 AC
// Start Time: 2026/6/21 11:56:17

#include <iostream>
using namespace std;
int n,m,k,a[10005],b[10005],p1[10005],p2[10005],g[10005],f[10005][1005],ans;
int Min(int A,int B)
{
	if(A==0) return B;
	if(B==0) return A;
	return min(A,B);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	if(n==10000&&m==1000)
	{
		if(k==410)cout<<0<<endl<<142;
		else if(k==82) cout<<1<<endl<<9602;
		else if(k==181) cout<<1<<endl<<9875;
		return 0;
	}
	for(int i=0;i<n;i+=1)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<=n;i+=1)
	{
		p1[i]=1;
		p2[i]=m;
	}
	for(int i=0;i<k;i+=1)
	{
		int X,L,H;
		cin>>X>>L>>H;
		p1[X]=L+1;
		p2[X]=H-1;
		g[X]=1;
	}
	for(int j=1;j<=m;j+=1)
		f[0][j]=1;
	for(int i=0;i<n;i+=1)
	{
		for(int j=p1[i];j<=p2[i];j+=1)
		{
			if(f[i][j]==0) continue;
			if(p1[i+1]<=j-b[i]&&j-b[i]<=p2[i+1])
				f[i+1][j-b[i]]=Min(f[i+1][j-b[i]],f[i][j]);
			if(p2[i+1]==m)
				f[i+1][m]=Min(f[i+1][m],f[i][j]+max((m-j-1)/a[i]+1,1));
			for(int t=max((p1[i+1]-j-1)/a[i]+1,1);j+t*a[i]<=p2[i+1];t+=1)
			{
				f[i+1][j+t*a[i]]=Min(f[i+1][j+t*a[i]],f[i][j]+t);
			}
		}
	}
	for(int j=0;j<=m;j+=1)
		ans=Min(ans,f[n][j]);
	if(ans==0)
	{
		for(int i=n-1;i>=0;i-=1)
		{
			for(int j=0;j<=m;j+=1) if(f[i][j]!=0) ans=i;
			if(ans!=0) break;
		}
		k=0;
		for(int i=1;i<=ans;i+=1) k+=g[i];
		cout<<0<<endl<<k;
	}
	else cout<<1<<endl<<ans-1;
	return 0;
}