#include<bits/stdc++.h>
using namespace std;
int n,i,j,r[200001]={0},ans=0,t,ma=0,tong[200001]={0},sm=0;
bool is[200001];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	ans=n;
	for(i=1;i<=n;i++)
	{
		cin>>r[i];
		tong[r[i]]++;
		ma=max(ma,r[i]);
	}
	for(i=1;i<=ma;i++)
	{
		if(tong[i]!=0)
		{
			if(sm<=tong[i])
				sm=tong[i];
		}
	}
	cout<<sm;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//每次让最小的，未攻击的去打最大的 
