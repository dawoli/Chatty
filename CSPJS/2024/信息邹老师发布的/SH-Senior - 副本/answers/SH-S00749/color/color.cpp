#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],c1,c2,ans,i;
void dfs(int c,int cl1,int cl2,int score)
{
	if(c>n)
	{
		ans = max(ans,score);
		return;
	}
	dfs(c+1,c,cl2,score+(a[c]==a[cl1]?a[c]:0));
	dfs(c+1,cl1,c,score+(a[c]==a[cl2]?a[c]:0));
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		i = 2;
		scanf("%d",&n);
		for(int j = 1;j<=n;j++) scanf("%d",&a[j]);
		ans = 0;
		c1 = 1;
		for(;a[i]==a[1];i++)
		{
			++c1;
			ans += a[i];
		}
		c2 = i;
		i++;
		dfs(i,c1,c2,ans);
		cout<<ans<<endl;
	}
	return 0;
}
