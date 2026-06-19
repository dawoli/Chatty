#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100005],b[100005];
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
		for(int j=i;j<=n;j++)
		{
			if(a[j]==a[i]) b[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,b[i]);
	}
	cout<<ans<<endl;
	return 0;
}
