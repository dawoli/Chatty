#include<bits/stdc++.h>
using namespace std;
const int N=200010; 
int sto[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sto[i]);
	}
	sort(sto+1,sto+n+1);
	int ans=n;
	int l=0;
	int eq=0;
	for(int i=1;i<=n;i++)
	{
		if(sto[i]!=sto[i-1])
		{
			l+=eq;
			eq=0;
		}
		if(l!=0)
		{
			ans--;
			l--;
		}
		eq++;
	}
	printf("%d\n",ans);
	return 0;
}
