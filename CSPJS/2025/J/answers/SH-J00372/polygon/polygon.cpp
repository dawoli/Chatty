#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int step,int picked,int sum,int maxn){
	if(sum > (maxn*2) && (picked > 3)){
		ans ++;
		ans %= 998244353;
	}
	if(step > n) return ;
	if(step > n && picked < 3) return ;
	for(int i = picked; i <= n; i ++)
	{
		dfs(step+1,picked+1,sum+a[i],max(maxn,a[i]));
		dfs(step+1,picked,sum,maxn);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n == 3)
	{
		int maxn = -1,sum = 0;
		for(int i = 1; i <= 3; i ++)
		{
			scanf("%d",&a[i]);
			maxn = max(maxn,a[i]);
			sum += a[i];
		}
		if((maxn*2) < sum ) cout << 1;
		else cout << 0;
		exit(0);
	}
	for(int i = 1; i <= n; i ++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,0,-1);
	printf("%d",ans);
	return 0;
} 
