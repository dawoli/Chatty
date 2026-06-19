#include<bits\stdc++.h>
using namespace std;
int T,n,ans;
int f[105][105][105];
int a[100005][3],b[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=0;
		if(n<=200)
		{
			for(int i=0;i<=n/2;++i)
				for(int j=0;j<=n/2;++j)
					for(int k=0;k<=n/2;++k)
					{
						if(i+j+k>n) continue;
						f[i][j][k]=0;
						if(i>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i+j+k][1]);
						if(j>0) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[i+j+k][2]);
						if(k>0) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[i+j+k][3]);
						ans=max(ans,f[i][j][k]);
					}	
			cout<<ans<<endl;				
		}
		else
		{
			bool flag=1;
			for(int i=1;i<=n;++i)
			{
				if(a[i][2]!=0 || a[i][3]!=0)
					flag=0;
				b[i]=a[i][1];
			}
			if(flag)
			{
				sort(b+1,b+n+1);
				for(int i=n;i>(n+1)/2;--i) ans+=b[i];
			}
			else
				for(int i=1;i<=n;++i)
					ans+=max(a[i][1],max(a[i][2],a[i][3]));			
			cout<<ans<<endl;
		}
	}
	return 0;
	
}
