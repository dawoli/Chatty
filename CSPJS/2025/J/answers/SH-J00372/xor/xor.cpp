#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt,ans;
struct node{
	int f,s;
} arr[500005];
int pre;
bool cmp(node x,node y)
{
	return x.s < y.s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%d",&a[1]);
	sum[1] = a[1];
	for(int i = 2; i <= n; i ++)
	{
		int x;
		scanf("%d",&x);
		a[i] = x;
		sum[i] =(sum[i-1]^x);
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i; j <= n; j ++)
		{
			if((i == 1) && (sum[j] == k))
			{
				cnt ++;
				//cout << i << " vis1 " << j << endl;
				arr[cnt].f = i, arr[cnt].s = j;
				break;
			}
			/*if((i == j) && (a[i] == k))
			{
				cnt ++;
				//cout << i << " vis2 " << j << endl;
				arr[cnt].f = i, arr[cnt].s = j;
				break;
			} */
			if(i == 1) continue;
			if(((sum[j]) ^ sum[i-1]) == k) {
				cnt ++;
				//cout << i << " vis3 " << j << endl;
				arr[cnt].f = i, arr[cnt].s = j;
				break;
			}
		}
	}
	sort(arr+1,arr+cnt+1,cmp);
	for(int i = 1; i <= cnt; i ++)
	{
		if(arr[i].f > pre){
			ans ++;
			pre = arr[i].s;
		}
	}
	printf("%d",ans);
	return 0;
}
