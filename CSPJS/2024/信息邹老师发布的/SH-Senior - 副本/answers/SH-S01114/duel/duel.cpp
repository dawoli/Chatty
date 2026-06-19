#include<bits/stdc++.h>
using namespace std;
int lev[100005],r[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,i,cnt=0,diff=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&r[i]);
	sort(r+1,r+1+n,greater<int>());
	for(i=1;i<n;++i)
	{
		lev[diff]++;
		if(r[i]>r[i+1])
			diff++;
	}
	lev[diff]++;
	if(diff==n)//特殊性质A：互不相同//
	{
		printf("1");
		return 0;
	}
	for(i=diff-1;i>=1;--i)
	{
		if(lev[i+1]>=lev[i])
			lev[i+1]-=lev[i];
		else
			lev[i+1]=0;
	}
	for(i=1;i<=diff;++i)
		cnt+=lev[i];
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
