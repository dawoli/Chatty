#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int m,index[100005],countt=0;
	bool fighted[100005];
	bool dead[100005];
	memset(fighted,0,sizeof(fighted));
	memset(dead,0,sizeof(dead));
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&index[i]);
	}
	sort(index,index+m);
	int ans=m;
	for(int i=0;i<m;i++)
	{
		for(int h=i+1;h<m;h++)
		{
			if(index[i]<index[h]&&dead[h]==0&&fighted[h]==0&&dead[i]==0) 
			{
				dead[i]=1;
				fighted[h]=1;
				ans--;
			}
		}
	} 
	cout<<ans;
	return 0; 
}
