#include<bits/stdc++.h>
using namespace std;
int n,q;
char cn[1010][2][600000],cq[2][500010];
bool can(int sn,int qn)
{
	int i=0;
	for(;i<qn;i++)
		if(cq[0][i]!=cq[1][i])
			return false;
	for(;cn[sn][0][i];i++)
		if(cn[sn][1][i-qn]!=cq[1][i]||cn[sn][0][i-qn]!=cq[0][i])
			return false;
	for(;cq[0][i];i++)
		if(cq[0][i]!=cq[1][i])
			return false;
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("\n%s %s",cn[n][0],cn[n][1]);
	for(int i=0;i<q;i++)
	{
		int sum=0;
		bool bs=true;
		scanf("\n%s %s",cq[0],cq[1]);
		for(int j=0;j<n&&bs;j++)
			for(int k=1;cq[0][k-1];k++)
			{
				if((cq[0][k]==0)!=(cq[1][k]==0))
				{
					sum=0;
					bs=false;
					break;
				}
				sum+=can(j,k-1);
				if(can(j,k-1))
				{
					printf("%d %d %d\n",i,j,k-1);
				}
			}
		printf("%d\n",sum);
	}
	return 0;
}
