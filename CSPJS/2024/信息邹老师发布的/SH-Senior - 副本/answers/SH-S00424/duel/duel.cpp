#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100010],x[100010],k=1,c,ans;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	x[k]=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1])
			x[++k]++;
		else
			x[k]++;
	}
	for(int i=2;i<=k;i++){
		int z=x[i-1]-x[i];
		ans+=max(0LL,z);
		c+=max(0LL,z);
		ans-=min(c,max(0LL,-z));
		c-=min(c,max(0LL,-z));
	}
	cout<<ans+x[k];
	return 0;
} 
