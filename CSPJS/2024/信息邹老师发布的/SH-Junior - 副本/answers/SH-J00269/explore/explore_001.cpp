#include<bits/stdc++.h>
using namespace std;
int ss[1010][1010],pp,qq,dd,vv[1010][1010],r1[4],r2[4];
char ip[1010][1010];
int main(){
	int i,j,t,n,m,k,zz;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	int nu,b;
	r1[0]=0;r1[1]=1;r1[2]=0;r1[3]=-1;
	r2[0]=1;r2[1]=0;r2[2]=-1;r2[3]=0;
	for(zz=1;zz<=t;zz++)
	{
		nu=0;
		cin>>n>>m>>k;
		cin>>pp>>qq>>dd;
		for(i=0;i<1010;i++) 
		{
			for(j=0;j<1010;j++)
			{
				vv[i][j]=0;
				ss[i][j]=0;
			}
		}
		for(i=1;i<=n;i++) cin>>ip[i];
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(ip[i][j]=='x') ss[i][j+1]=1;
			}
		}
		for(i=1;i<=k;i++)
		{
			b=0;
			vv[pp][qq]=1;
			if(pp+r1[dd]>=1&&pp+r1[dd]<=n&&qq+r2[dd]>=1&&qq+r2[dd]<=m&&ss[pp+r1[dd]][qq+r2[dd]]==0)
			{
				pp=pp+r1[dd];
				qq=qq+r2[dd];
				vv[pp][qq]=1;
				b=1;
			}
			if(b==0)
			{
				dd=(dd+1)%4;
			}
		}
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(vv[i][j]) nu++;
		cout<<nu<<endl;
	}
	return 0;
}
