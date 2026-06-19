#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,vm,d,v,a,p[100010],ar[1000010],k=1,sum=0,pp[100010],q[100010],kk;
double h[100010],t[100010],b[100010];
int msort(int hh,int tt)
{
	if(hh==tt)
	{
		return 0;
	}
	int mid=(hh+tt)/2;
	msort(hh,mid);msort(mid+1,tt);
	int i=hh;int j=mid+1;k=hh;
	while(i<=mid&&j<=tt)
	{
		if(h[i]<=h[j])
		{
			b[k]=h[i];q[k]=pp[i];i++;
		}
		else
		{
			b[k]=h[j];q[k]=pp[j];j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=h[i];q[k]=pp[i];k++;i++;
	}
	while(j<=tt)
	{
		b[k]=h[j];q[k]=pp[j];k++;j++;
	}
	for(i=hh;i<=tt;i++)
	{
		h[i]=b[i];
		pp[i]=q[i];
	}
}
double flor(double x,int y)
{
	if(x-floor(x)==0)
	{
		if(y==0)
		{
			x++;
		}
		else
		{
			x--;
		}
	}
	else
	{
		if(y==0)
		{
			x=floor(x);
			x++;
		}
		else
		{
			x=floor(x);
		}
	}
	return x;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		cin>>n>>m>>l>>vm;
		for(int i=1;i<=n;i++)
		{
			cin>>d>>v>>a;
			pp[i]=i;
			if(v>vm)
			{
				h[i]=d;
				if(a>=0)
				{
					t[i]=l;
				}
				else
				{
					t[i]=(vm*vm-v*v)*1.0/(2*a)+d;t[i]=flor(t[i],1);
					if(t[i]>l)
					{
						t[i]=l;
					}
				}
			}
			else if(a<=0)
			{
				h[i]=l+2;
				t[i]=l+1;
			}
			else
			{
				h[i]=(vm*vm-v*v)*1.0/(2*a)+d;
				h[i]=flor(h[i],0);
				t[i]=l;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		p[m+1]=l+10;
		k=1;
		for(int i=0;i<=l;i++)
		{
			ar[i]=k;
			if(i>=p[k])
			{
				k++;
			}
		}
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(t[i]==l+1)
			{
				h[i]=1;t[i]=m;
				continue;
			}
			h[i]=ar[int(h[i])];
			if(t[i]==p[ar[int(t[i])]])
			{
				t[i]=ar[int(t[i])];
			}
			else
			{
				t[i]=ar[int(t[i])]-1;
			}
			if(h[i]<=t[i])
			{
				sum++;
			}
			else
			{
				h[i]=1;t[i]=m;
			}
		}
		cout<<sum<<" ";
		msort(1,n);
		for(int i=n-1;i>=1;i--)
		{
			if(t[pp[i]]>t[pp[i+1]])
			{
				t[pp[i]]=t[pp[i+1]];
			}
		}
		k=1;sum=0;
		while(k<=n)
		{
			kk=k;
			while(h[kk]<=t[pp[k]])
			{
				kk++;
			}
			sum++;
			k=kk;
		}
		cout<<m-sum<<endl;
		for(int i=1;i<=n;i++)
		{
			h[i]=0;t[i]=0;pp[i]=0;q[i]=0;b[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			p[i]=0;
		}
		for(int i=1;i<=l;i++)
		{
			ar[i]=0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
