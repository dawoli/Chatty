#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int MAXN=2e5+5;
int f[2][MAXN];
int n,a[MAXN];

int chg(int a,int b)
{
	if(a==b) return b;
	return 0;
}

signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++)
	for(int i=1;i<k-1;i++)
	{
		f[0][k-1]=max(f[0][k-1],f[1][i]+chg(a[k],a[i]));
		f[1][k-1]=max(f[1][k-1],f[0][i]+chg(a[k],a[i]));
		f[0][i]=f[0][i]+chg(a[k],a[k-1]);
		f[1][i]=f[1][i]+chg(a[k],a[k-1]);
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		maxn=max(max(f[0][i],f[1][i]),maxn);
	}
	cout<<maxn<<endl;
}
} 
