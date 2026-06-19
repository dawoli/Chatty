#include<bits/stdc++.h>
using namespace std;
int ri[100000],ea[100000];
int n,pan,yishu,ershu,huan,shengyu;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	shengyu=n;
	for(int i=0;i<n;i++)
	{
		cin>>ri[i];
		if(pan!=1)
		{
			if(ri[i]!=1&&ri[i]!=2) pan=1;
		}
	}
	if(pan==0)
	{
		for(int i=0;i<n;i++)
		{
			if(ri[i]==1) yishu=yishu+1;
		}
		ershu=n-yishu;
		if(yishu>=ershu) cout<<yishu;
		else cout<<ershu;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(ri[i]>ri[j])
				{
					huan=ri[i];
					ri[i]=ri[j];
					ri[j]=huan;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				if(ea[j]!=1)
				{
					if(ri[i]<ri[j])
					{
						shengyu=shengyu-1;
						ea[j]=1;
						break;
					}
				}
			}
			if(ea[n-1]==1) break;
		}
		cout<<shengyu;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
