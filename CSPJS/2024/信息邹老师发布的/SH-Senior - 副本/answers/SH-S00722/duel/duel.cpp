#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,top,ans,a[N],b[N],c[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])top++,b[top]++;
		else b[top]++;
	}
	for(int i=1;i<=top;i++)c[i]=c[i-1]+b[i];
	for(int i=2;i<=top;i++)
	{
		//cout<<ans<<' '<<c[i-1]+ans<<' ';
		if(b[i]<=c[i-1]+ans)ans-=b[i];
		else if(c[i-1]+ans<b[i])ans-=(c[i-1]+ans);
	}
	cout<<n+ans;
	return 0;
} 
//preans=0,c[i-1]=3,b[i](1)<c[i-1]+preans(3),ans-=1
//1 1 2 3 3 3 3 3 3
//preans=-1,c[i-1]=4,b[i](6)>c[i-1]+preans(3),after, ans-=3(4)

