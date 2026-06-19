#include<bits/stdc++.h>
using namespace std;

int n,k,a[10005],res;
int cg1(int x)
{
	int xn[10005],ansx,lenx=0;
	for(int i=1;x!=0;i++)
	{
		xn[i]=x%2;
		x=x/2;
		lenx++;
	}
	for(int i=lenx;i>=1;i--)
	{
		ansx=ansx*10+xn[i];
	}
	return ansx;
}
int sq2(int z)
{
	int ans=1;
	for(int i=1;i<=z;i++)
	{
		ans*=2;
	}
	return ans;
}
int cg2(int x)
{
	int ansx=0,z=0;
	while(x!=0)
	{
		ansx+=(x%10)*sq2(z);
		x=x/10;
		z++;
	}
	return ansx;
}


int sum(int x,int y)
{
	int xn,yn,qx,qy,ans=0,z=0;
	xn=cg1(x);
	yn=cg1(y);
	while(xn!=0||yn!=0)
	{
		qx=xn%10;
		qy=yn%10;
		if(qx==qy)
		{
			ans=ans*10;
			if(z==0)z=1;
		}
		else
		{
			if(z==1)
			{
				z=-1;
				ans=(ans+1)*10;
			}
			else ans=ans*10+1;
		}
		xn/=10;
		yn/=10;
	}
	return cg2(ans);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int l=1;l+i<=n;l++)
		{
			int r=l+i;
			int b=a[l];
			for(int z=l+1;z<=l+i;z++)
			{
				if(b==-1||a[z]==-1)break;
				b=sum(b,a[z]);
			}
			if(b==k)
			{
				for(int c=l;c<=r;c++)
				{
					a[c]=-1;
				}
				res++;
			}
		}
	}
	cout<<res;
}
