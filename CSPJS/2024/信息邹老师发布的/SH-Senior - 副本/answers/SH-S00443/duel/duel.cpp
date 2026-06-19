#include<bits/stdc++.h>
using namespace std;
int n,arr[100005];
int vis[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;++i)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	int ans=0;
	for(i=1;i<=n;++i){
		int t=upper_bound(arr+i+1+1,arr+n+1,arr[i])-arr,v=*upper_bound(arr+i+1+1,arr+n+1,arr[i]);
		if(t>=n+1)
			break;
		while(vis[t]){
			t=lower_bound(arr+t+1,arr+n+1,v)-arr;
			v=*lower_bound(arr+t+1,arr+n+1,v);
		}
		if(t>=n+1)
			break;
		vis[t]=1;
		ans++;
	}
	printf("%d\n",n-ans);
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
