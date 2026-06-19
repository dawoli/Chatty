#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001][2],b[100001][2];
int find(int i)
{
	for(int j=1;j<=i;j++)		//寻找能吃的目标 
	{
		if(b[i-j][0]<b[i][0]&&(b[i-j][1]!=1)) 			//判断是否能吃 
		{
			b[i-j][1]=1;				//吃 
			return 1;
		}
	}
	return 0;
	
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i][0];			//输入
		b[i][0]=a[i][0];
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-1;j++)
		{
			if(b[j][0]>b[j+1][0]&&j<n-1)		//排序 
			{
				int temp=0;
				temp=b[j][0];
				b[j][0]=b[j+1][0];
				b[j+1][0]=temp;
			}
		}
	}
	for(int i=0;i<=n-1;i++)	//遍历b数组 
	{
		if(find(i))	//如果可以吃
			b[i+1][1]=2;	//吃  	//如果前者和后面一样，前面打后面 
		if(b[i][0]==b[i+1][0]) b[i][1]=2;
	}
	int res=0;
	for(int i=0;i<=n-1;i++)
	{
		if(b[i][1]==0||b[i][1]==2) res++;		//计算剩下的怪物 
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
	
