#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	int t,brr[10][30];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,l,v,d[100010],u[100010],a[100010],p[3010],num=0,num1[100010],num2=1,ew=0,f=1;
		cin>>n>>m>>l>>v;
		for(int j=1;j<=n;j++) cin>>d[j]>>u[j]>>a[j];
		for(int j=1;j<=m;j++) cin>>p[j];
		for(int j=1;j<=m;j++) num1[j]=0;
		for(int j=1;j<=n;j++)
		{
			if(d[j]>l) continue;
			if(a[j]==0)
			{
				if(u[j]>v&&d[j]<=p[m]) 
				{
					num++;
					ew=1;
					int o=0;
					for(int z=1;z<=m;z++)
					{
						if(p[z]>=d[j])
						{
							num1[z]++;
							if(num1[z]>=f) o=1;
						}
					}
					if(o==0) num2++;
					f++;
				}
				else
				continue;
			}
			else 
			{
				int h=0;
				int arr=(v*v-u[j]*u[j])/(a[j]*2);
				if(a[j]<0)
				{
					int fla=0;
					for(int z=1;z<=m;z++)
					{
						if(d[j]<=p[z]&&arr+d[j]>p[z])
						{
							num1[z]++;
							fla=1;
							if(num1[z]>=f) h=1;
						}
					}
					if(fla==1)
					{
						f++;
						num++;
						if(h==0) num2++;
					}
				}
				else
				{
					int fla=0;
					for(int z=1;z<=m;z++)
					{
						if(arr+d[j]<p[z])
						{
							num1[z]++;
							if(num1[z]>=f) h=1;
							fla=1;
						}
					}
					if(fla==1)
					{
						f++;
						num++;
						if(h==0) num2++;
					}
					
				}
				
			}
		}
		brr[1][i]=num;
		if(num2==m) brr[2][i]=ew;
		else brr[2][i]=m-num2;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<brr[1][i]<<" "<<brr[2][i]<<endl;;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}