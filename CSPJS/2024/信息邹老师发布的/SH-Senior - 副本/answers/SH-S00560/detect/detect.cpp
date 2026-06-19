#include <bits/stdc++.h>
using namespace std;

int T;
int n,m,L,V;
int a[100005][4];
int b[100005];
int ans1=0;
int cnt,cntm;

bool loc1(int d)
{
	for(int k=1;k<=n;k++)
	{
		if(b[k]>=d)return true;
	}
	return false;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int stop;
		cin>>n>>m>>L>>V;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
		{
			if(a[i][3]==0)
			{
				if(a[i][2]>V&&loc1(a[i][1]))
				{
					ans1++;
				}
			}
			if(a[i][3]>0)
			{
				int x=abs(V*V-a[i][2]*a[i][2])/(2*a[i][3])+a[i][1];
				for(cnt=1;cnt<=m;cnt++)
				{
					if(x<b[cnt])
					{
						ans1++;
						break;
					}
				
				}
				if(cnt>cntm)cntm=cnt;
				
			}	
				
		}
		cout<<ans1<<" ";
		int cnt2=0,cnt3=0;	
		for(int i=1;i<=n;i++)
		{
			if(a[i][3]==0)cnt2++;
			if(a[i][3]>0)cnt3++;
		}
		if(cnt2==n&&ans1==0)cout<<m<<endl;
		if(cnt2==n&&ans1!=0)cout<<0<<endl;
		if(cnt3==n&&ans1==0)cout<<m<<endl;
		if(cnt3==n&&ans1!=0)cout<<cntm-m<<endl;
		
	}
	
	
	return 0;
}
